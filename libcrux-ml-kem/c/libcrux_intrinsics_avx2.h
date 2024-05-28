/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /nix/store/c9m211bm84ncjmaxx27ki9dymd4qkwm2-ocaml4.14.1-eurydice-dirty/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc
  F* version: <unknown>
  KaRaMeL version: <unknown>
 */

#ifndef __libcrux_intrinsics_avx2_H
#define __libcrux_intrinsics_avx2_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"

extern core_core_arch_x86___m256i libcrux_intrinsics_avx2_mm256_setzero_si256(void);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_loadu_si256_i16(Eurydice_slice x0);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_add_epi16(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_sub_epi16(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i libcrux_intrinsics_avx2_mm256_set1_epi16(int16_t x0);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_mullo_epi16(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_and_si256(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_srai_epi16(int32_t x0, core_core_arch_x86___m256i x1);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_mulhi_epi16(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_xor_si256(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_srli_epi16(int32_t x0, core_core_arch_x86___m256i x1);

extern core_core_arch_x86___m256i libcrux_intrinsics_avx2_mm256_set1_epi32(int32_t x0);

extern core_core_arch_x86___m128i
libcrux_intrinsics_avx2_mm256_castsi256_si128(core_core_arch_x86___m256i x0);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_cvtepi16_epi32(core_core_arch_x86___m128i x0);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_slli_epi32(int32_t x0, core_core_arch_x86___m256i x1);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_add_epi32(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_mul_epu32(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_shuffle_epi32(int32_t x0, core_core_arch_x86___m256i x1);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_unpacklo_epi32(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_unpackhi_epi32(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_unpackhi_epi64(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_srli_epi32(int32_t x0, core_core_arch_x86___m256i x1);

extern core_core_arch_x86___m128i
libcrux_intrinsics_avx2_mm256_extracti128_si256(int32_t x0, core_core_arch_x86___m256i x1);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_packs_epi32(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_permute4x64_epi64(int32_t x0, core_core_arch_x86___m256i x1);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_mullo_epi32(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_set_epi16(
  int16_t x0,
  int16_t x1,
  int16_t x2,
  int16_t x3,
  int16_t x4,
  int16_t x5,
  int16_t x6,
  int16_t x7,
  int16_t x8,
  int16_t x9,
  int16_t x10,
  int16_t x11,
  int16_t x12,
  int16_t x13,
  int16_t x14,
  int16_t x15
);

extern core_core_arch_x86___m128i libcrux_intrinsics_avx2_mm_set1_epi16(int16_t x0);

extern core_core_arch_x86___m128i
libcrux_intrinsics_avx2_mm_mullo_epi16(
  core_core_arch_x86___m128i x0,
  core_core_arch_x86___m128i x1
);

extern core_core_arch_x86___m128i
libcrux_intrinsics_avx2_mm_mulhi_epi16(
  core_core_arch_x86___m128i x0,
  core_core_arch_x86___m128i x1
);

extern core_core_arch_x86___m128i
libcrux_intrinsics_avx2_mm_sub_epi16(
  core_core_arch_x86___m128i x0,
  core_core_arch_x86___m128i x1
);

extern core_core_arch_x86___m128i
libcrux_intrinsics_avx2_mm_add_epi16(
  core_core_arch_x86___m128i x0,
  core_core_arch_x86___m128i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_castsi128_si256(core_core_arch_x86___m128i x0);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_inserti128_si256(
  int32_t x0,
  core_core_arch_x86___m256i x1,
  core_core_arch_x86___m128i x2
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_blend_epi16(
  int32_t x0,
  core_core_arch_x86___m256i x1,
  core_core_arch_x86___m256i x2
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_set_epi8(
  int8_t x0,
  int8_t x1,
  int8_t x2,
  int8_t x3,
  int8_t x4,
  int8_t x5,
  int8_t x6,
  int8_t x7,
  int8_t x8,
  int8_t x9,
  int8_t x10,
  int8_t x11,
  int8_t x12,
  int8_t x13,
  int8_t x14,
  int8_t x15,
  int8_t x16,
  int8_t x17,
  int8_t x18,
  int8_t x19,
  int8_t x20,
  int8_t x21,
  int8_t x22,
  int8_t x23,
  int8_t x24,
  int8_t x25,
  int8_t x26,
  int8_t x27,
  int8_t x28,
  int8_t x29,
  int8_t x30,
  int8_t x31
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_shuffle_epi8(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_srai_epi32(int32_t x0, core_core_arch_x86___m256i x1);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_set_epi32(
  int32_t x0,
  int32_t x1,
  int32_t x2,
  int32_t x3,
  int32_t x4,
  int32_t x5,
  int32_t x6,
  int32_t x7
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_madd_epi16(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_slli_epi16(int32_t x0, core_core_arch_x86___m256i x1);

extern core_core_arch_x86___m128i
libcrux_intrinsics_avx2_mm_packs_epi16(
  core_core_arch_x86___m128i x0,
  core_core_arch_x86___m128i x1
);

extern int32_t libcrux_intrinsics_avx2_mm_movemask_epi8(core_core_arch_x86___m128i x0);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_permutevar8x32_epi32(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern void
libcrux_intrinsics_avx2_mm_storeu_bytes_si128(Eurydice_slice x0, core_core_arch_x86___m128i x1);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_sllv_epi32(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_srli_epi64(int32_t x0, core_core_arch_x86___m256i x1);

extern core_core_arch_x86___m128i
libcrux_intrinsics_avx2_mm_set_epi8(
  uint8_t x0,
  uint8_t x1,
  uint8_t x2,
  uint8_t x3,
  uint8_t x4,
  uint8_t x5,
  uint8_t x6,
  uint8_t x7,
  uint8_t x8,
  uint8_t x9,
  uint8_t x10,
  uint8_t x11,
  uint8_t x12,
  uint8_t x13,
  uint8_t x14,
  uint8_t x15
);

extern core_core_arch_x86___m128i libcrux_intrinsics_avx2_mm_loadu_si128(Eurydice_slice x0);

extern core_core_arch_x86___m128i
libcrux_intrinsics_avx2_mm_shuffle_epi8(
  core_core_arch_x86___m128i x0,
  core_core_arch_x86___m128i x1
);

extern void
libcrux_intrinsics_avx2_mm256_storeu_si256_i16(
  Eurydice_slice x0,
  core_core_arch_x86___m256i x1
);

extern core_core_arch_x86___m256i
libcrux_intrinsics_avx2_mm256_cmpgt_epi16(
  core_core_arch_x86___m256i x0,
  core_core_arch_x86___m256i x1
);

extern void
libcrux_intrinsics_avx2_mm_storeu_si128(Eurydice_slice x0, core_core_arch_x86___m128i x1);

#if defined(__cplusplus)
}
#endif

#define __libcrux_intrinsics_avx2_H_DEFINED
#endif
