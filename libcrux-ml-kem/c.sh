#!/usr/bin/env bash

set -e
set -o pipefail

if [[ -z "$CHARON_HOME" ]]; then
    echo "Please set CHARON_HOME to the Charon directory" 1>&2
    exit 1
fi
if [[ -z "$EURYDICE_HOME" ]]; then
    echo "Please set EURYDICE_HOME to the Eurydice directory" 1>&2
    exit 1
fi

portable_only=0
no_hacl=0
no_charon=0

# Parse command line arguments.
all_args=("$@")
while [ $# -gt 0 ]; do
    case "$1" in
    -p | --portable) portable_only=1 ;;
    --no-hacl) no_hacl=1 ;;
    --no-charon) no_charon=1 ;;
    esac
    shift
done

if [[ "$portable_only" = 1 ]]; then
    export LIBCRUX_DISABLE_SIMD256=1
    export LIBCRUX_DISABLE_SIMD128=1
fi

if [[ "$no_charon" = 0 ]]; then
    rm -rf ../libcrux_ml_kem.llbc ../libcrux_sha3.llbc
    echo "Running charon (sha3) ..."
    (cd ../libcrux-sha3 && RUSTFLAGS="--cfg eurydice" $CHARON_HOME/bin/charon --errors-as-warnings)
    if ! [[ -f ../libcrux_sha3.llbc ]]; then
      echo "😱😱😱 You are the victim of this bug: https://hacspec.zulipchat.com/#narrow/stream/433829-Circus/topic/charon.20declines.20to.20generate.20an.20llbc.20file"
      echo "Suggestion: rm -rf ../target"
      exit 1
    fi
    echo "Running charon (ml-kem) ..."
    RUSTFLAGS="--cfg eurydice" $CHARON_HOME/bin/charon --errors-as-warnings
else
    echo "Skipping charon"
fi

mkdir -p c
cd c

echo "Running eurydice ..."
$EURYDICE_HOME/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc
cp $EURYDICE_HOME/include/eurydice_glue.h .

# if [[ -n "$HACL_PACKAGES_HOME" && "$no_hacl" = 0 ]]; then
#     # clang-format --style=Mozilla -i libcrux_kyber.c libcrux_kyber.h
#     cp internal/*.h $HACL_PACKAGES_HOME/libcrux/include/internal/
#     cp *.h $HACL_PACKAGES_HOME/libcrux/include
#     cp *.c $HACL_PACKAGES_HOME/libcrux/src
# elif [[ "$no_hacl" = 0 ]]; then
#     echo "Please set HACL_PACKAGES_HOME to the hacl-packages directory to copy the code over" 1>&2
# else
#     echo "Copy to hacl-packages was disabled with --no-hacl" 1>&2
# fi
