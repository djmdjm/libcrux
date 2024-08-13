/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: 53530427db2941ce784201e64086766504bc5642
 * Eurydice: 67f4341506300372fba9cb8de070234935839cb7
 * Karamel: f9cdef256a2b88282398a609847b34dd8c9cf3e3
 * F*: 58c915a86a2c07c8eca8d9deafd76cb7a91f0eb7
 * Libcrux: 8afc9098ccf0c74c13fe7d661a9a9efad5861427
 */

#ifndef __libcrux_mlkem512_H
#define __libcrux_mlkem512_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"
#include "libcrux_core.h"

#define LIBCRUX_ML_KEM_MLKEM512_VECTOR_U_COMPRESSION_FACTOR_512 ((size_t)10U)

#define LIBCRUX_ML_KEM_MLKEM512_C1_BLOCK_SIZE_512          \
  (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * \
   LIBCRUX_ML_KEM_MLKEM512_VECTOR_U_COMPRESSION_FACTOR_512 / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM512_RANK_512 ((size_t)2U)

#define LIBCRUX_ML_KEM_MLKEM512_C1_SIZE_512 \
  (LIBCRUX_ML_KEM_MLKEM512_C1_BLOCK_SIZE_512 * LIBCRUX_ML_KEM_MLKEM512_RANK_512)

#define LIBCRUX_ML_KEM_MLKEM512_VECTOR_V_COMPRESSION_FACTOR_512 ((size_t)4U)

#define LIBCRUX_ML_KEM_MLKEM512_C2_SIZE_512                \
  (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * \
   LIBCRUX_ML_KEM_MLKEM512_VECTOR_V_COMPRESSION_FACTOR_512 / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_CIPHERTEXT_SIZE_512 \
  (LIBCRUX_ML_KEM_MLKEM512_C1_SIZE_512 + LIBCRUX_ML_KEM_MLKEM512_C2_SIZE_512)

#define LIBCRUX_ML_KEM_MLKEM512_T_AS_NTT_ENCODED_SIZE_512  \
  (LIBCRUX_ML_KEM_MLKEM512_RANK_512 *                      \
   LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * \
   LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_COEFFICIENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_PUBLIC_KEY_SIZE_512 \
  (LIBCRUX_ML_KEM_MLKEM512_T_AS_NTT_ENCODED_SIZE_512 + (size_t)32U)

#define LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_SECRET_KEY_SIZE_512 \
  (LIBCRUX_ML_KEM_MLKEM512_RANK_512 *                       \
   LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *  \
   LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_COEFFICIENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM512_ETA1 ((size_t)3U)

#define LIBCRUX_ML_KEM_MLKEM512_ETA1_RANDOMNESS_SIZE \
  (LIBCRUX_ML_KEM_MLKEM512_ETA1 * (size_t)64U)

#define LIBCRUX_ML_KEM_MLKEM512_ETA2 ((size_t)2U)

#define LIBCRUX_ML_KEM_MLKEM512_ETA2_RANDOMNESS_SIZE \
  (LIBCRUX_ML_KEM_MLKEM512_ETA2 * (size_t)64U)

#define LIBCRUX_ML_KEM_MLKEM512_IMPLICIT_REJECTION_HASH_INPUT_SIZE \
  (LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE +                   \
   LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_CIPHERTEXT_SIZE_512)

typedef libcrux_ml_kem_types_MlKemCiphertext_e8
    libcrux_ml_kem_mlkem512_MlKem512Ciphertext;

typedef libcrux_ml_kem_types_MlKemKeyPair_cb
    libcrux_ml_kem_mlkem512_MlKem512KeyPair;

typedef libcrux_ml_kem_types_MlKemPrivateKey_5e
    libcrux_ml_kem_mlkem512_MlKem512PrivateKey;

typedef libcrux_ml_kem_types_MlKemPublicKey_be
    libcrux_ml_kem_mlkem512_MlKem512PublicKey;

#define LIBCRUX_ML_KEM_MLKEM512_RANKED_BYTES_PER_RING_ELEMENT_512 \
  (LIBCRUX_ML_KEM_MLKEM512_RANK_512 *                             \
   LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_RING_ELEMENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM512_SECRET_KEY_SIZE_512      \
  (LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_SECRET_KEY_SIZE_512 + \
   LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_PUBLIC_KEY_SIZE_512 + \
   LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE +              \
   LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE)

#if defined(__cplusplus)
}
#endif

#define __libcrux_mlkem512_H_DEFINED
#endif
