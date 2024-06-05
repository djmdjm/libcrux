/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc
  F* version: b5cb71b8
  KaRaMeL version: 40e3a603
 */

#ifndef __internal_libcrux_core_H
#define __internal_libcrux_core_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "../libcrux_core.h"
#include "eurydice_glue.h"

extern void core_fmt_rt__core__fmt__rt__Argument__a__1__none(core_fmt_rt_Argument x0[0U]);

extern core_fmt_Arguments
core_fmt__core__fmt__Arguments__a__2__new_v1(Eurydice_slice x0, Eurydice_slice x1);

#define CORE_NUM__U32_8__BITS (32U)

static inline uint32_t core_num__u32_8__from_le_bytes(uint8_t x0[4U]);

#define LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE ((size_t)32U)

void
libcrux_ml_kem_constant_time_ops_select_shared_secret_in_constant_time(
  Eurydice_slice lhs,
  Eurydice_slice rhs,
  uint8_t selector,
  uint8_t ret[32U]
);

#define LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_COEFFICIENT ((size_t)12U)

#define LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT ((size_t)256U)

#define LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_RING_ELEMENT (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * (size_t)12U)

#define LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT (LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_RING_ELEMENT / (size_t)8U)

#define LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE ((size_t)32U)

#define LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE ((size_t)32U)

libcrux_ml_kem_types_MlKemPublicKey____1568size_t
libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPublicKey_SIZE___14__from___1568size_t(
  uint8_t value[1568U]
);

libcrux_ml_kem_types_MlKemKeyPair____3168size_t__1568size_t
libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemKeyPair_PRIVATE_KEY_SIZE__PUBLIC_KEY_SIZE___from___3168size_t_1568size_t(
  libcrux_ml_kem_types_MlKemPrivateKey____3168size_t sk,
  libcrux_ml_kem_types_MlKemPublicKey____1568size_t pk
);

libcrux_ml_kem_types_MlKemPrivateKey____3168size_t
libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPrivateKey_SIZE___8__from___3168size_t(
  uint8_t value[3168U]
);

typedef struct K___uint8_t_1536size_t__uint8_t_1568size_t__s
{
  uint8_t fst[1536U];
  uint8_t snd[1568U];
}
K___uint8_t_1536size_t__uint8_t_1568size_t_;

libcrux_ml_kem_types_MlKemCiphertext____1568size_t
libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___2__from___1568size_t(
  uint8_t value[1568U]
);

uint8_t
*libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemPublicKey_SIZE__18__as_slice___1568size_t(
  libcrux_ml_kem_types_MlKemPublicKey____1568size_t *self
);

uint8_t
libcrux_ml_kem_constant_time_ops_compare_ciphertexts_in_constant_time___1568size_t(
  Eurydice_slice lhs,
  Eurydice_slice rhs
);

Eurydice_slice
libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref___1568size_t(
  libcrux_ml_kem_types_MlKemCiphertext____1568size_t *self
);

void
libcrux_ml_kem_ind_cpa_into_padded_array___1600size_t(Eurydice_slice slice, uint8_t ret[1600U]);

libcrux_ml_kem_types_MlKemPublicKey____1184size_t
libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPublicKey_SIZE___14__from___1184size_t(
  uint8_t value[1184U]
);

libcrux_ml_kem_types_MlKemKeyPair____2400size_t__1184size_t
libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemKeyPair_PRIVATE_KEY_SIZE__PUBLIC_KEY_SIZE___from___2400size_t_1184size_t(
  libcrux_ml_kem_types_MlKemPrivateKey____2400size_t sk,
  libcrux_ml_kem_types_MlKemPublicKey____1184size_t pk
);

libcrux_ml_kem_types_MlKemPrivateKey____2400size_t
libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPrivateKey_SIZE___8__from___2400size_t(
  uint8_t value[2400U]
);

typedef struct K___uint8_t_1152size_t__uint8_t_1184size_t__s
{
  uint8_t fst[1152U];
  uint8_t snd[1184U];
}
K___uint8_t_1152size_t__uint8_t_1184size_t_;

libcrux_ml_kem_types_MlKemCiphertext____1088size_t
libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___2__from___1088size_t(
  uint8_t value[1088U]
);

uint8_t
*libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemPublicKey_SIZE__18__as_slice___1184size_t(
  libcrux_ml_kem_types_MlKemPublicKey____1184size_t *self
);

uint8_t
libcrux_ml_kem_constant_time_ops_compare_ciphertexts_in_constant_time___1088size_t(
  Eurydice_slice lhs,
  Eurydice_slice rhs
);

Eurydice_slice
libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref___1088size_t(
  libcrux_ml_kem_types_MlKemCiphertext____1088size_t *self
);

void
libcrux_ml_kem_ind_cpa_into_padded_array___1120size_t(Eurydice_slice slice, uint8_t ret[1120U]);

typedef struct K___Eurydice_slice_uint8_t_128size_t__Eurydice_slice_uint8_t_128size_t__s
{
  Eurydice_slice fst;
  Eurydice_slice snd;
}
K___Eurydice_slice_uint8_t_128size_t__Eurydice_slice_uint8_t_128size_t_;

typedef struct K___Eurydice_slice_uint8_t_192size_t__Eurydice_slice_uint8_t_192size_t__s
{
  Eurydice_slice fst;
  Eurydice_slice snd;
}
K___Eurydice_slice_uint8_t_192size_t__Eurydice_slice_uint8_t_192size_t_;

typedef struct K___Eurydice_slice_uint8_t_504size_t__Eurydice_slice_uint8_t_504size_t__s
{
  Eurydice_slice fst;
  Eurydice_slice snd;
}
K___Eurydice_slice_uint8_t_504size_t__Eurydice_slice_uint8_t_504size_t_;

libcrux_ml_kem_types_MlKemPublicKey____800size_t
libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPublicKey_SIZE___14__from___800size_t(
  uint8_t value[800U]
);

libcrux_ml_kem_types_MlKemKeyPair____1632size_t__800size_t
libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemKeyPair_PRIVATE_KEY_SIZE__PUBLIC_KEY_SIZE___from___1632size_t_800size_t(
  libcrux_ml_kem_types_MlKemPrivateKey____1632size_t sk,
  libcrux_ml_kem_types_MlKemPublicKey____800size_t pk
);

libcrux_ml_kem_types_MlKemPrivateKey____1632size_t
libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPrivateKey_SIZE___8__from___1632size_t(
  uint8_t value[1632U]
);

typedef struct K___uint8_t_768size_t__uint8_t_800size_t__s
{
  uint8_t fst[768U];
  uint8_t snd[800U];
}
K___uint8_t_768size_t__uint8_t_800size_t_;

libcrux_ml_kem_types_MlKemCiphertext____768size_t
libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___2__from___768size_t(
  uint8_t value[768U]
);

uint8_t
*libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemPublicKey_SIZE__18__as_slice___800size_t(
  libcrux_ml_kem_types_MlKemPublicKey____800size_t *self
);

uint8_t
libcrux_ml_kem_constant_time_ops_compare_ciphertexts_in_constant_time___768size_t(
  Eurydice_slice lhs,
  Eurydice_slice rhs
);

void
libcrux_ml_kem_ind_cpa_into_padded_array___33size_t(Eurydice_slice slice, uint8_t ret[33U]);

void
libcrux_ml_kem_ind_cpa_into_padded_array___34size_t(Eurydice_slice slice, uint8_t ret[34U]);

Eurydice_slice
libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref___768size_t(
  libcrux_ml_kem_types_MlKemCiphertext____768size_t *self
);

void
libcrux_ml_kem_ind_cpa_into_padded_array___800size_t(Eurydice_slice slice, uint8_t ret[800U]);

void
libcrux_ml_kem_ind_cpa_into_padded_array___64size_t(Eurydice_slice slice, uint8_t ret[64U]);

typedef struct core_option_Option__Eurydice_slice_uint8_t_s
{
  core_option_Option__size_t_tags tag;
  Eurydice_slice f0;
}
core_option_Option__Eurydice_slice_uint8_t;

typedef struct core_result_Result__int16_t_16size_t__core_array_TryFromSliceError_s
{
  core_result_Result__int16_t_16size_t__core_array_TryFromSliceError_tags tag;
  union {
    int16_t case_Ok[16U];
    core_array_TryFromSliceError case_Err;
  }
  val;
}
core_result_Result__int16_t_16size_t__core_array_TryFromSliceError;

void
core_result__core__result__Result_T__E___unwrap__int16_t_16size_t__core_array_TryFromSliceError(
  core_result_Result__int16_t_16size_t__core_array_TryFromSliceError self,
  int16_t ret[16U]
);

typedef struct K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t__s
{
  Eurydice_slice fst[2U];
  Eurydice_slice snd[2U];
}
K___Eurydice_slice_uint8_t_2size_t__Eurydice_slice_uint8_t_2size_t_;

#if defined(__cplusplus)
}
#endif

#define __internal_libcrux_core_H_DEFINED
#endif
