/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: 45b95e0f63cb830202c0b3ca00a341a3451a02ba
 * Eurydice: 0eb8a17354fd62586cb9f7515af23f4488c2267e
 * Karamel: d5759a8b96e9f104664a88a83043d5761fcc9732
 * F*: b2931dfbe46e839cd757220c63d48c71335bb1ae
 * Libcrux: 3c5d3c5f94d5a7630aa83a84d6f06452e6c18807
 */

#ifndef __libcrux_sha3_internal_H
#define __libcrux_sha3_internal_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"
#include "libcrux_core.h"

static const uint64_t libcrux_sha3_generic_keccak_ROUNDCONSTANTS[24U] = {
    1ULL,
    32898ULL,
    9223372036854808714ULL,
    9223372039002292224ULL,
    32907ULL,
    2147483649ULL,
    9223372039002292353ULL,
    9223372036854808585ULL,
    138ULL,
    136ULL,
    2147516425ULL,
    2147483658ULL,
    2147516555ULL,
    9223372036854775947ULL,
    9223372036854808713ULL,
    9223372036854808579ULL,
    9223372036854808578ULL,
    9223372036854775936ULL,
    32778ULL,
    9223372039002259466ULL,
    9223372039002292353ULL,
    9223372036854808704ULL,
    2147483649ULL,
    9223372039002292232ULL};

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero(
    void) {
  return 0ULL;
}

static KRML_MUSTINLINE uint64_t libcrux_sha3_portable_keccak__veor5q_u64(
    uint64_t a, uint64_t b, uint64_t c, uint64_t d, uint64_t e) {
  uint64_t ab = a ^ b;
  uint64_t cd = c ^ d;
  uint64_t abcd = ab ^ cd;
  return abcd ^ e;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor5(
    uint64_t a, uint64_t b, uint64_t c, uint64_t d, uint64_t e) {
  return libcrux_sha3_portable_keccak__veor5q_u64(a, b, c, d, e);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___1int32_t_63int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)1 | x >> (uint32_t)(int32_t)63;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vrax1q_u64(uint64_t a, uint64_t b) {
  uint64_t uu____0 = a;
  return uu____0 ^
         libcrux_sha3_portable_keccak_rotate_left___1int32_t_63int32_t(b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___rotate_left1_and_xor(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vrax1q_u64(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vbcaxq_u64(uint64_t a, uint64_t b, uint64_t c) {
  return a ^ (b & ~c);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___and_not_xor(
    uint64_t a, uint64_t b, uint64_t c) {
  return libcrux_sha3_portable_keccak__vbcaxq_u64(a, b, c);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__veorq_n_u64(uint64_t a, uint64_t c) {
  return a ^ c;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_constant(
    uint64_t a, uint64_t c) {
  return libcrux_sha3_portable_keccak__veorq_n_u64(a, c);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor(
    uint64_t a, uint64_t b) {
  return a ^ b;
}

static KRML_MUSTINLINE void libcrux_sha3_portable_keccak_slice_1(
    Eurydice_slice a[1U], size_t start, size_t len, Eurydice_slice ret[1U]) {
  ret[0U] = Eurydice_slice_subslice2(a[0U], start, start + len, uint8_t,
                                     Eurydice_slice);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
    Eurydice_slice a[1U], size_t start, size_t len, Eurydice_slice ret[1U]) {
  Eurydice_slice uu____0[1U];
  memcpy(uu____0, a, (size_t)1U * sizeof(Eurydice_slice));
  Eurydice_slice ret0[1U];
  libcrux_sha3_portable_keccak_slice_1(uu____0, start, len, ret0);
  memcpy(ret, ret0, (size_t)1U * sizeof(Eurydice_slice));
}

static KRML_MUSTINLINE
    K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_
    libcrux_sha3_portable_keccak_split_at_mut_1(Eurydice_slice out[1U],
                                                size_t mid) {
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____0 =
      core_slice___Slice_T___split_at_mut(
          out[0U], mid, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice out00 = uu____0.fst;
  Eurydice_slice out01 = uu____0.snd;
  K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ lit;
  lit.fst[0U] = out00;
  lit.snd[0U] = out01;
  return lit;
}

static KRML_MUSTINLINE
    K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_
    libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
        Eurydice_slice a[1U], size_t mid) {
  return libcrux_sha3_portable_keccak_split_at_mut_1(a, mid);
}

typedef struct libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t_s {
  uint64_t st[5U][5U];
} libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t;

static KRML_MUSTINLINE libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t
libcrux_sha3_generic_keccak__libcrux_sha3__generic_keccak__KeccakState_T__N__TraitClause_0__1__new__uint64_t_1size_t(
    void) {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t lit;
  lit.st[0U][0U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[0U][1U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[0U][2U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[0U][3U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[0U][4U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[1U][0U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[1U][1U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[1U][2U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[1U][3U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[1U][4U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[2U][0U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[2U][1U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[2U][2U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[2U][3U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[2U][4U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[3U][0U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[3U][1U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[3U][2U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[3U][3U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[3U][4U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[4U][0U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[4U][1U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[4U][2U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[4U][3U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  lit.st[4U][4U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___zero();
  return lit;
}

static KRML_MUSTINLINE void libcrux_sha3_portable_keccak_load_block___168size_t(
    uint64_t (*s)[5U], Eurydice_slice blocks[1U]) {
  for (size_t i = (size_t)0U; i < (size_t)168U / (size_t)8U; i++) {
    size_t i0 = i;
    uint8_t uu____0[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst;
    Eurydice_slice_to_array2(
        &dst,
        Eurydice_slice_subslice2(blocks[0U], (size_t)8U * i0,
                                 (size_t)8U * i0 + (size_t)8U, uint8_t,
                                 Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst, uu____0);
    size_t uu____1 = i0 / (size_t)5U;
    size_t uu____2 = i0 % (size_t)5U;
    s[uu____1][uu____2] =
        s[uu____1][uu____2] ^ core_num__u64_9__from_le_bytes(uu____0);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_load_block_full___168size_t(
    uint64_t (*s)[5U], uint8_t blocks[1U][200U]) {
  Eurydice_slice buf[1U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice)};
  libcrux_sha3_portable_keccak_load_block___168size_t(s, buf);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block_full___168size_t(
    uint64_t (*a)[5U], uint8_t b[1U][200U]) {
  uint64_t(*uu____0)[5U] = a;
  uint8_t uu____1[1U][200U];
  memcpy(uu____1, b, (size_t)1U * sizeof(uint8_t[200U]));
  libcrux_sha3_portable_keccak_load_block_full___168size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___36int32_t_28int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)36 | x >> (uint32_t)(int32_t)28;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___36int32_t_28int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___36int32_t_28int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___36int32_t_28int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___36int32_t_28int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___3int32_t_61int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)3 | x >> (uint32_t)(int32_t)61;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___3int32_t_61int32_t(uint64_t a,
                                                             uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___3int32_t_61int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___3int32_t_61int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___3int32_t_61int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___41int32_t_23int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)41 | x >> (uint32_t)(int32_t)23;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___41int32_t_23int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___41int32_t_23int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___41int32_t_23int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___41int32_t_23int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___18int32_t_46int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)18 | x >> (uint32_t)(int32_t)46;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___18int32_t_46int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___18int32_t_46int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___18int32_t_46int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___18int32_t_46int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___1int32_t_63int32_t(uint64_t a,
                                                             uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___1int32_t_63int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___1int32_t_63int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___1int32_t_63int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___44int32_t_20int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)44 | x >> (uint32_t)(int32_t)20;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___44int32_t_20int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___44int32_t_20int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___44int32_t_20int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___44int32_t_20int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___10int32_t_54int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)10 | x >> (uint32_t)(int32_t)54;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___10int32_t_54int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___10int32_t_54int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___10int32_t_54int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___10int32_t_54int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___45int32_t_19int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)45 | x >> (uint32_t)(int32_t)19;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___45int32_t_19int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___45int32_t_19int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___45int32_t_19int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___45int32_t_19int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___2int32_t_62int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)2 | x >> (uint32_t)(int32_t)62;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___2int32_t_62int32_t(uint64_t a,
                                                             uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___2int32_t_62int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___2int32_t_62int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___2int32_t_62int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___62int32_t_2int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)62 | x >> (uint32_t)(int32_t)2;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___62int32_t_2int32_t(uint64_t a,
                                                             uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___62int32_t_2int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___62int32_t_2int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___62int32_t_2int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___6int32_t_58int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)6 | x >> (uint32_t)(int32_t)58;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___6int32_t_58int32_t(uint64_t a,
                                                             uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___6int32_t_58int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___6int32_t_58int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___6int32_t_58int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___43int32_t_21int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)43 | x >> (uint32_t)(int32_t)21;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___43int32_t_21int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___43int32_t_21int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___43int32_t_21int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___43int32_t_21int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___15int32_t_49int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)15 | x >> (uint32_t)(int32_t)49;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___15int32_t_49int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___15int32_t_49int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___15int32_t_49int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___15int32_t_49int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___61int32_t_3int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)61 | x >> (uint32_t)(int32_t)3;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___61int32_t_3int32_t(uint64_t a,
                                                             uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___61int32_t_3int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___61int32_t_3int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___61int32_t_3int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___28int32_t_36int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)28 | x >> (uint32_t)(int32_t)36;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___28int32_t_36int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___28int32_t_36int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___28int32_t_36int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___28int32_t_36int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___55int32_t_9int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)55 | x >> (uint32_t)(int32_t)9;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___55int32_t_9int32_t(uint64_t a,
                                                             uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___55int32_t_9int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___55int32_t_9int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___55int32_t_9int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___25int32_t_39int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)25 | x >> (uint32_t)(int32_t)39;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___25int32_t_39int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___25int32_t_39int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___25int32_t_39int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___25int32_t_39int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___21int32_t_43int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)21 | x >> (uint32_t)(int32_t)43;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___21int32_t_43int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___21int32_t_43int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___21int32_t_43int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___21int32_t_43int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___56int32_t_8int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)56 | x >> (uint32_t)(int32_t)8;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___56int32_t_8int32_t(uint64_t a,
                                                             uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___56int32_t_8int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___56int32_t_8int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___56int32_t_8int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___27int32_t_37int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)27 | x >> (uint32_t)(int32_t)37;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___27int32_t_37int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___27int32_t_37int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___27int32_t_37int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___27int32_t_37int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___20int32_t_44int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)20 | x >> (uint32_t)(int32_t)44;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___20int32_t_44int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___20int32_t_44int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___20int32_t_44int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___20int32_t_44int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___39int32_t_25int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)39 | x >> (uint32_t)(int32_t)25;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___39int32_t_25int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___39int32_t_25int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___39int32_t_25int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___39int32_t_25int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___8int32_t_56int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)8 | x >> (uint32_t)(int32_t)56;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___8int32_t_56int32_t(uint64_t a,
                                                             uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___8int32_t_56int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___8int32_t_56int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___8int32_t_56int32_t(a, b);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak_rotate_left___14int32_t_50int32_t(uint64_t x) {
  return x << (uint32_t)(int32_t)14 | x >> (uint32_t)(int32_t)50;
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak__vxarq_u64___14int32_t_50int32_t(uint64_t a,
                                                              uint64_t b) {
  uint64_t ab = a ^ b;
  return libcrux_sha3_portable_keccak_rotate_left___14int32_t_50int32_t(ab);
}

static KRML_MUSTINLINE uint64_t
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___14int32_t_50int32_t(
    uint64_t a, uint64_t b) {
  return libcrux_sha3_portable_keccak__vxarq_u64___14int32_t_50int32_t(a, b);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_theta_rho__uint64_t_1size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s) {
  uint64_t c[5U] = {
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor5(
          s->st[0U][0U], s->st[1U][0U], s->st[2U][0U], s->st[3U][0U],
          s->st[4U][0U]),
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor5(
          s->st[0U][1U], s->st[1U][1U], s->st[2U][1U], s->st[3U][1U],
          s->st[4U][1U]),
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor5(
          s->st[0U][2U], s->st[1U][2U], s->st[2U][2U], s->st[3U][2U],
          s->st[4U][2U]),
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor5(
          s->st[0U][3U], s->st[1U][3U], s->st[2U][3U], s->st[3U][3U],
          s->st[4U][3U]),
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor5(
          s->st[0U][4U], s->st[1U][4U], s->st[2U][4U], s->st[3U][4U],
          s->st[4U][4U])};
  uint64_t uu____0 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___rotate_left1_and_xor(
          c[((size_t)0U + (size_t)4U) % (size_t)5U],
          c[((size_t)0U + (size_t)1U) % (size_t)5U]);
  uint64_t uu____1 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___rotate_left1_and_xor(
          c[((size_t)1U + (size_t)4U) % (size_t)5U],
          c[((size_t)1U + (size_t)1U) % (size_t)5U]);
  uint64_t uu____2 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___rotate_left1_and_xor(
          c[((size_t)2U + (size_t)4U) % (size_t)5U],
          c[((size_t)2U + (size_t)1U) % (size_t)5U]);
  uint64_t uu____3 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___rotate_left1_and_xor(
          c[((size_t)3U + (size_t)4U) % (size_t)5U],
          c[((size_t)3U + (size_t)1U) % (size_t)5U]);
  uint64_t t[5U] = {
      uu____0, uu____1, uu____2, uu____3,
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___rotate_left1_and_xor(
          c[((size_t)4U + (size_t)4U) % (size_t)5U],
          c[((size_t)4U + (size_t)1U) % (size_t)5U])};
  s->st[0U][0U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor(
          s->st[0U][0U], t[0U]);
  uint64_t uu____4 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___36int32_t_28int32_t(
          s->st[1U][0U], t[0U]);
  s->st[1U][0U] = uu____4;
  uint64_t uu____5 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___3int32_t_61int32_t(
          s->st[2U][0U], t[0U]);
  s->st[2U][0U] = uu____5;
  uint64_t uu____6 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___41int32_t_23int32_t(
          s->st[3U][0U], t[0U]);
  s->st[3U][0U] = uu____6;
  uint64_t uu____7 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___18int32_t_46int32_t(
          s->st[4U][0U], t[0U]);
  s->st[4U][0U] = uu____7;
  uint64_t uu____8 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___1int32_t_63int32_t(
          s->st[0U][1U], t[1U]);
  s->st[0U][1U] = uu____8;
  uint64_t uu____9 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___44int32_t_20int32_t(
          s->st[1U][1U], t[1U]);
  s->st[1U][1U] = uu____9;
  uint64_t uu____10 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___10int32_t_54int32_t(
          s->st[2U][1U], t[1U]);
  s->st[2U][1U] = uu____10;
  uint64_t uu____11 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___45int32_t_19int32_t(
          s->st[3U][1U], t[1U]);
  s->st[3U][1U] = uu____11;
  uint64_t uu____12 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___2int32_t_62int32_t(
          s->st[4U][1U], t[1U]);
  s->st[4U][1U] = uu____12;
  uint64_t uu____13 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___62int32_t_2int32_t(
          s->st[0U][2U], t[2U]);
  s->st[0U][2U] = uu____13;
  uint64_t uu____14 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___6int32_t_58int32_t(
          s->st[1U][2U], t[2U]);
  s->st[1U][2U] = uu____14;
  uint64_t uu____15 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___43int32_t_21int32_t(
          s->st[2U][2U], t[2U]);
  s->st[2U][2U] = uu____15;
  uint64_t uu____16 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___15int32_t_49int32_t(
          s->st[3U][2U], t[2U]);
  s->st[3U][2U] = uu____16;
  uint64_t uu____17 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___61int32_t_3int32_t(
          s->st[4U][2U], t[2U]);
  s->st[4U][2U] = uu____17;
  uint64_t uu____18 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___28int32_t_36int32_t(
          s->st[0U][3U], t[3U]);
  s->st[0U][3U] = uu____18;
  uint64_t uu____19 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___55int32_t_9int32_t(
          s->st[1U][3U], t[3U]);
  s->st[1U][3U] = uu____19;
  uint64_t uu____20 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___25int32_t_39int32_t(
          s->st[2U][3U], t[3U]);
  s->st[2U][3U] = uu____20;
  uint64_t uu____21 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___21int32_t_43int32_t(
          s->st[3U][3U], t[3U]);
  s->st[3U][3U] = uu____21;
  uint64_t uu____22 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___56int32_t_8int32_t(
          s->st[4U][3U], t[3U]);
  s->st[4U][3U] = uu____22;
  uint64_t uu____23 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___27int32_t_37int32_t(
          s->st[0U][4U], t[4U]);
  s->st[0U][4U] = uu____23;
  uint64_t uu____24 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___20int32_t_44int32_t(
          s->st[1U][4U], t[4U]);
  s->st[1U][4U] = uu____24;
  uint64_t uu____25 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___39int32_t_25int32_t(
          s->st[2U][4U], t[4U]);
  s->st[2U][4U] = uu____25;
  uint64_t uu____26 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___8int32_t_56int32_t(
          s->st[3U][4U], t[4U]);
  s->st[3U][4U] = uu____26;
  uint64_t uu____27 =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_and_rotate___14int32_t_50int32_t(
          s->st[4U][4U], t[4U]);
  s->st[4U][4U] = uu____27;
}

static KRML_MUSTINLINE void libcrux_sha3_generic_keccak_pi__uint64_t_1size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s) {
  uint64_t old[5U][5U];
  memcpy(old, s->st, (size_t)5U * sizeof(uint64_t[5U]));
  s->st[0U][1U] = old[1U][1U];
  s->st[0U][2U] = old[2U][2U];
  s->st[0U][3U] = old[3U][3U];
  s->st[0U][4U] = old[4U][4U];
  s->st[1U][0U] = old[0U][3U];
  s->st[1U][1U] = old[1U][4U];
  s->st[1U][2U] = old[2U][0U];
  s->st[1U][3U] = old[3U][1U];
  s->st[1U][4U] = old[4U][2U];
  s->st[2U][0U] = old[0U][1U];
  s->st[2U][1U] = old[1U][2U];
  s->st[2U][2U] = old[2U][3U];
  s->st[2U][3U] = old[3U][4U];
  s->st[2U][4U] = old[4U][0U];
  s->st[3U][0U] = old[0U][4U];
  s->st[3U][1U] = old[1U][0U];
  s->st[3U][2U] = old[2U][1U];
  s->st[3U][3U] = old[3U][2U];
  s->st[3U][4U] = old[4U][3U];
  s->st[4U][0U] = old[0U][2U];
  s->st[4U][1U] = old[1U][3U];
  s->st[4U][2U] = old[2U][4U];
  s->st[4U][3U] = old[3U][0U];
  s->st[4U][4U] = old[4U][1U];
}

static KRML_MUSTINLINE void libcrux_sha3_generic_keccak_chi__uint64_t_1size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s) {
  uint64_t old[5U][5U];
  memcpy(old, s->st, (size_t)5U * sizeof(uint64_t[5U]));
  KRML_MAYBE_FOR5(
      i0, (size_t)0U, (size_t)5U, (size_t)1U, size_t i1 = i0; KRML_MAYBE_FOR5(
          i, (size_t)0U, (size_t)5U, (size_t)1U, size_t j = i;
          s->st[i1][j] =
              libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___and_not_xor(
                  s->st[i1][j], old[i1][(j + (size_t)2U) % (size_t)5U],
                  old[i1][(j + (size_t)1U) % (size_t)5U]);););
}

static KRML_MUSTINLINE void libcrux_sha3_generic_keccak_iota__uint64_t_1size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s, size_t i) {
  s->st[0U][0U] =
      libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___xor_constant(
          s->st[0U][0U], libcrux_sha3_generic_keccak_ROUNDCONSTANTS[i]);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s) {
  for (size_t i = (size_t)0U; i < (size_t)24U; i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_theta_rho__uint64_t_1size_t(s);
    libcrux_sha3_generic_keccak_pi__uint64_t_1size_t(s);
    libcrux_sha3_generic_keccak_chi__uint64_t_1size_t(s);
    libcrux_sha3_generic_keccak_iota__uint64_t_1size_t(s, i0);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_168size_t_31uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice last[1U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[1U][200U] = {{0U}};
  {
    size_t i = (size_t)0U;
    if (last_len > (size_t)0U) {
      Eurydice_slice uu____0 = Eurydice_array_to_subslice(
          (size_t)200U, blocks[i],
          (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                                  .end = last_len}),
          uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
      core_slice___Slice_T___copy_from_slice(uu____0, last[i], uint8_t, void *);
    }
    blocks[i][last_len] = 31U;
    size_t uu____1 = i;
    size_t uu____2 = (size_t)168U - (size_t)1U;
    blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;
  }
  uint64_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[1U][200U];
  memcpy(uu____4, blocks, (size_t)1U * sizeof(uint8_t[200U]));
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block_full___168size_t(
      uu____3, uu____4);
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_store_block___168size_t(uint64_t (*s)[5U],
                                                     Eurydice_slice out[1U]) {
  for (size_t i = (size_t)0U; i < (size_t)168U / (size_t)8U; i++) {
    size_t i0 = i;
    Eurydice_slice uu____0 = Eurydice_slice_subslice2(
        out[0U], (size_t)8U * i0, (size_t)8U * i0 + (size_t)8U, uint8_t,
        Eurydice_slice);
    uint8_t ret[8U];
    core_num__u64_9__to_le_bytes(s[i0 / (size_t)5U][i0 % (size_t)5U], ret);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)8U, ret, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___168size_t(
    uint64_t (*a)[5U], Eurydice_slice b[1U]) {
  libcrux_sha3_portable_keccak_store_block___168size_t(a, b);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_168size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___168size_t(
      s->st, out);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_168size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___168size_t(
      s->st, out);
}

static KRML_MUSTINLINE void libcrux_sha3_portable_keccak_load_block___136size_t(
    uint64_t (*s)[5U], Eurydice_slice blocks[1U]) {
  for (size_t i = (size_t)0U; i < (size_t)136U / (size_t)8U; i++) {
    size_t i0 = i;
    uint8_t uu____0[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst;
    Eurydice_slice_to_array2(
        &dst,
        Eurydice_slice_subslice2(blocks[0U], (size_t)8U * i0,
                                 (size_t)8U * i0 + (size_t)8U, uint8_t,
                                 Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst, uu____0);
    size_t uu____1 = i0 / (size_t)5U;
    size_t uu____2 = i0 % (size_t)5U;
    s[uu____1][uu____2] =
        s[uu____1][uu____2] ^ core_num__u64_9__from_le_bytes(uu____0);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_load_block_full___136size_t(
    uint64_t (*s)[5U], uint8_t blocks[1U][200U]) {
  Eurydice_slice buf[1U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice)};
  libcrux_sha3_portable_keccak_load_block___136size_t(s, buf);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block_full___136size_t(
    uint64_t (*a)[5U], uint8_t b[1U][200U]) {
  uint64_t(*uu____0)[5U] = a;
  uint8_t uu____1[1U][200U];
  memcpy(uu____1, b, (size_t)1U * sizeof(uint8_t[200U]));
  libcrux_sha3_portable_keccak_load_block_full___136size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_136size_t_31uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice last[1U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[1U][200U] = {{0U}};
  {
    size_t i = (size_t)0U;
    if (last_len > (size_t)0U) {
      Eurydice_slice uu____0 = Eurydice_array_to_subslice(
          (size_t)200U, blocks[i],
          (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                                  .end = last_len}),
          uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
      core_slice___Slice_T___copy_from_slice(uu____0, last[i], uint8_t, void *);
    }
    blocks[i][last_len] = 31U;
    size_t uu____1 = i;
    size_t uu____2 = (size_t)136U - (size_t)1U;
    blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;
  }
  uint64_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[1U][200U];
  memcpy(uu____4, blocks, (size_t)1U * sizeof(uint8_t[200U]));
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block_full___136size_t(
      uu____3, uu____4);
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_store_block___136size_t(uint64_t (*s)[5U],
                                                     Eurydice_slice out[1U]) {
  for (size_t i = (size_t)0U; i < (size_t)136U / (size_t)8U; i++) {
    size_t i0 = i;
    Eurydice_slice uu____0 = Eurydice_slice_subslice2(
        out[0U], (size_t)8U * i0, (size_t)8U * i0 + (size_t)8U, uint8_t,
        Eurydice_slice);
    uint8_t ret[8U];
    core_num__u64_9__to_le_bytes(s[i0 / (size_t)5U][i0 % (size_t)5U], ret);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)8U, ret, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___136size_t(
    uint64_t (*a)[5U], Eurydice_slice b[1U]) {
  libcrux_sha3_portable_keccak_store_block___136size_t(a, b);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___136size_t(
      s->st, out);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___136size_t(
      s->st, out);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block___168size_t(
    uint64_t (*a)[5U], Eurydice_slice b[1U]) {
  uint64_t(*uu____0)[5U] = a;
  Eurydice_slice uu____1[1U];
  memcpy(uu____1, b, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_portable_keccak_load_block___168size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_168size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice blocks[1U]) {
  uint64_t(*uu____0)[5U] = s->st;
  Eurydice_slice uu____1[1U];
  memcpy(uu____1, blocks, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block___168size_t(
      uu____0, uu____1);
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_store_block_full___168size_t(
    uint64_t (*s)[5U], uint8_t ret[1U][200U]) {
  uint8_t out[200U] = {0U};
  Eurydice_slice buf[1U] = {
      Eurydice_array_to_slice((size_t)200U, out, uint8_t, Eurydice_slice)};
  libcrux_sha3_portable_keccak_store_block___168size_t(s, buf);
  uint8_t uu____0[200U];
  memcpy(uu____0, out, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[0U], uu____0, (size_t)200U * sizeof(uint8_t));
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___168size_t(
    uint64_t (*a)[5U], uint8_t ret[1U][200U]) {
  uint8_t ret0[1U][200U];
  libcrux_sha3_portable_keccak_store_block_full___168size_t(a, ret0);
  memcpy(ret, ret0, (size_t)1U * sizeof(uint8_t[200U]));
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_168size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  uint8_t b[1U][200U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___168size_t(
      s->st, b);
  {
    size_t i = (size_t)0U;
    Eurydice_slice uu____0 = out[i];
    uint8_t *uu____1 = b[i];
    core_ops_range_Range__size_t lit;
    lit.start = (size_t)0U;
    lit.end = core_slice___Slice_T___len(out[i], uint8_t, size_t);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                   core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_168size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(&s);
  uint8_t b[1U][200U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___168size_t(
      s.st, b);
  {
    size_t i = (size_t)0U;
    Eurydice_slice uu____0 = out[i];
    uint8_t *uu____1 = b[i];
    core_ops_range_Range__size_t lit;
    lit.start = (size_t)0U;
    lit.end = core_slice___Slice_T___len(out[i], uint8_t, size_t);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                   core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_168size_t_31uint8_t(
    Eurydice_slice data[1U], Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s =
      libcrux_sha3_generic_keccak__libcrux_sha3__generic_keccak__KeccakState_T__N__TraitClause_0__1__new__uint64_t_1size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)168U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____0 = &s;
    Eurydice_slice uu____1[1U];
    memcpy(uu____1, data, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice ret[1U];
    libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
        uu____1, i0 * (size_t)168U, (size_t)168U, ret);
    libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_168size_t(
        uu____0, ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)168U;
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____2 = &s;
  Eurydice_slice uu____3[1U];
  memcpy(uu____3, data, (size_t)1U * sizeof(Eurydice_slice));
  Eurydice_slice ret[1U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
      uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem, rem,
      ret);
  libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_168size_t_31uint8_t(
      uu____2, ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)168U;
  size_t last = outlen - outlen % (size_t)168U;
  if (blocks == (size_t)0U) {
    libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_168size_t(
        &s, out);
  } else {
    K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____4 =
        libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
            out, (size_t)168U);
    Eurydice_slice o0[1U];
    memcpy(o0, uu____4.fst, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice o1[1U];
    memcpy(o1, uu____4.snd, (size_t)1U * sizeof(Eurydice_slice));
    libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_168size_t(
        &s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____5 =
            libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
                o1, (size_t)168U);
        Eurydice_slice o[1U];
        memcpy(o, uu____5.fst, (size_t)1U * sizeof(Eurydice_slice));
        Eurydice_slice orest[1U];
        memcpy(orest, uu____5.snd, (size_t)1U * sizeof(Eurydice_slice));
        libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_168size_t(
            &s, o);
        memcpy(o1, orest, (size_t)1U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_168size_t(s,
                                                                           o1);
    }
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccakx1___168size_t_31uint8_t(Eurydice_slice data[1U],
                                                     Eurydice_slice out[1U]) {
  Eurydice_slice uu____0[1U];
  memcpy(uu____0, data, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_168size_t_31uint8_t(
      uu____0, out);
}

static KRML_MUSTINLINE void libcrux_sha3_portable_keccak_load_block___104size_t(
    uint64_t (*s)[5U], Eurydice_slice blocks[1U]) {
  for (size_t i = (size_t)0U; i < (size_t)104U / (size_t)8U; i++) {
    size_t i0 = i;
    uint8_t uu____0[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst;
    Eurydice_slice_to_array2(
        &dst,
        Eurydice_slice_subslice2(blocks[0U], (size_t)8U * i0,
                                 (size_t)8U * i0 + (size_t)8U, uint8_t,
                                 Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst, uu____0);
    size_t uu____1 = i0 / (size_t)5U;
    size_t uu____2 = i0 % (size_t)5U;
    s[uu____1][uu____2] =
        s[uu____1][uu____2] ^ core_num__u64_9__from_le_bytes(uu____0);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block___104size_t(
    uint64_t (*a)[5U], Eurydice_slice b[1U]) {
  uint64_t(*uu____0)[5U] = a;
  Eurydice_slice uu____1[1U];
  memcpy(uu____1, b, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_portable_keccak_load_block___104size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_104size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice blocks[1U]) {
  uint64_t(*uu____0)[5U] = s->st;
  Eurydice_slice uu____1[1U];
  memcpy(uu____1, blocks, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block___104size_t(
      uu____0, uu____1);
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_load_block_full___104size_t(
    uint64_t (*s)[5U], uint8_t blocks[1U][200U]) {
  Eurydice_slice buf[1U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice)};
  libcrux_sha3_portable_keccak_load_block___104size_t(s, buf);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block_full___104size_t(
    uint64_t (*a)[5U], uint8_t b[1U][200U]) {
  uint64_t(*uu____0)[5U] = a;
  uint8_t uu____1[1U][200U];
  memcpy(uu____1, b, (size_t)1U * sizeof(uint8_t[200U]));
  libcrux_sha3_portable_keccak_load_block_full___104size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_104size_t_6uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice last[1U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[1U][200U] = {{0U}};
  {
    size_t i = (size_t)0U;
    if (last_len > (size_t)0U) {
      Eurydice_slice uu____0 = Eurydice_array_to_subslice(
          (size_t)200U, blocks[i],
          (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                                  .end = last_len}),
          uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
      core_slice___Slice_T___copy_from_slice(uu____0, last[i], uint8_t, void *);
    }
    blocks[i][last_len] = 6U;
    size_t uu____1 = i;
    size_t uu____2 = (size_t)104U - (size_t)1U;
    blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;
  }
  uint64_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[1U][200U];
  memcpy(uu____4, blocks, (size_t)1U * sizeof(uint8_t[200U]));
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block_full___104size_t(
      uu____3, uu____4);
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_store_block___104size_t(uint64_t (*s)[5U],
                                                     Eurydice_slice out[1U]) {
  for (size_t i = (size_t)0U; i < (size_t)104U / (size_t)8U; i++) {
    size_t i0 = i;
    Eurydice_slice uu____0 = Eurydice_slice_subslice2(
        out[0U], (size_t)8U * i0, (size_t)8U * i0 + (size_t)8U, uint8_t,
        Eurydice_slice);
    uint8_t ret[8U];
    core_num__u64_9__to_le_bytes(s[i0 / (size_t)5U][i0 % (size_t)5U], ret);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)8U, ret, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_store_block_full___104size_t(
    uint64_t (*s)[5U], uint8_t ret[1U][200U]) {
  uint8_t out[200U] = {0U};
  Eurydice_slice buf[1U] = {
      Eurydice_array_to_slice((size_t)200U, out, uint8_t, Eurydice_slice)};
  libcrux_sha3_portable_keccak_store_block___104size_t(s, buf);
  uint8_t uu____0[200U];
  memcpy(uu____0, out, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[0U], uu____0, (size_t)200U * sizeof(uint8_t));
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___104size_t(
    uint64_t (*a)[5U], uint8_t ret[1U][200U]) {
  uint8_t ret0[1U][200U];
  libcrux_sha3_portable_keccak_store_block_full___104size_t(a, ret0);
  memcpy(ret, ret0, (size_t)1U * sizeof(uint8_t[200U]));
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_104size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  uint8_t b[1U][200U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___104size_t(
      s->st, b);
  {
    size_t i = (size_t)0U;
    Eurydice_slice uu____0 = out[i];
    uint8_t *uu____1 = b[i];
    core_ops_range_Range__size_t lit;
    lit.start = (size_t)0U;
    lit.end = core_slice___Slice_T___len(out[i], uint8_t, size_t);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                   core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___104size_t(
    uint64_t (*a)[5U], Eurydice_slice b[1U]) {
  libcrux_sha3_portable_keccak_store_block___104size_t(a, b);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_104size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___104size_t(
      s->st, out);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_104size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___104size_t(
      s->st, out);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_104size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(&s);
  uint8_t b[1U][200U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___104size_t(
      s.st, b);
  {
    size_t i = (size_t)0U;
    Eurydice_slice uu____0 = out[i];
    uint8_t *uu____1 = b[i];
    core_ops_range_Range__size_t lit;
    lit.start = (size_t)0U;
    lit.end = core_slice___Slice_T___len(out[i], uint8_t, size_t);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                   core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_104size_t_6uint8_t(
    Eurydice_slice data[1U], Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s =
      libcrux_sha3_generic_keccak__libcrux_sha3__generic_keccak__KeccakState_T__N__TraitClause_0__1__new__uint64_t_1size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)104U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____0 = &s;
    Eurydice_slice uu____1[1U];
    memcpy(uu____1, data, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice ret[1U];
    libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
        uu____1, i0 * (size_t)104U, (size_t)104U, ret);
    libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_104size_t(
        uu____0, ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)104U;
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____2 = &s;
  Eurydice_slice uu____3[1U];
  memcpy(uu____3, data, (size_t)1U * sizeof(Eurydice_slice));
  Eurydice_slice ret[1U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
      uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem, rem,
      ret);
  libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_104size_t_6uint8_t(
      uu____2, ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)104U;
  size_t last = outlen - outlen % (size_t)104U;
  if (blocks == (size_t)0U) {
    libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_104size_t(
        &s, out);
  } else {
    K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____4 =
        libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
            out, (size_t)104U);
    Eurydice_slice o0[1U];
    memcpy(o0, uu____4.fst, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice o1[1U];
    memcpy(o1, uu____4.snd, (size_t)1U * sizeof(Eurydice_slice));
    libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_104size_t(
        &s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____5 =
            libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
                o1, (size_t)104U);
        Eurydice_slice o[1U];
        memcpy(o, uu____5.fst, (size_t)1U * sizeof(Eurydice_slice));
        Eurydice_slice orest[1U];
        memcpy(orest, uu____5.snd, (size_t)1U * sizeof(Eurydice_slice));
        libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_104size_t(
            &s, o);
        memcpy(o1, orest, (size_t)1U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_104size_t(s,
                                                                           o1);
    }
  }
}

static KRML_MUSTINLINE void libcrux_sha3_portable_keccakx1___104size_t_6uint8_t(
    Eurydice_slice data[1U], Eurydice_slice out[1U]) {
  Eurydice_slice uu____0[1U];
  memcpy(uu____0, data, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_104size_t_6uint8_t(
      uu____0, out);
}

static KRML_MUSTINLINE void libcrux_sha3_portable_keccak_load_block___144size_t(
    uint64_t (*s)[5U], Eurydice_slice blocks[1U]) {
  for (size_t i = (size_t)0U; i < (size_t)144U / (size_t)8U; i++) {
    size_t i0 = i;
    uint8_t uu____0[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst;
    Eurydice_slice_to_array2(
        &dst,
        Eurydice_slice_subslice2(blocks[0U], (size_t)8U * i0,
                                 (size_t)8U * i0 + (size_t)8U, uint8_t,
                                 Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst, uu____0);
    size_t uu____1 = i0 / (size_t)5U;
    size_t uu____2 = i0 % (size_t)5U;
    s[uu____1][uu____2] =
        s[uu____1][uu____2] ^ core_num__u64_9__from_le_bytes(uu____0);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block___144size_t(
    uint64_t (*a)[5U], Eurydice_slice b[1U]) {
  uint64_t(*uu____0)[5U] = a;
  Eurydice_slice uu____1[1U];
  memcpy(uu____1, b, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_portable_keccak_load_block___144size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_144size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice blocks[1U]) {
  uint64_t(*uu____0)[5U] = s->st;
  Eurydice_slice uu____1[1U];
  memcpy(uu____1, blocks, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block___144size_t(
      uu____0, uu____1);
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_load_block_full___144size_t(
    uint64_t (*s)[5U], uint8_t blocks[1U][200U]) {
  Eurydice_slice buf[1U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice)};
  libcrux_sha3_portable_keccak_load_block___144size_t(s, buf);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block_full___144size_t(
    uint64_t (*a)[5U], uint8_t b[1U][200U]) {
  uint64_t(*uu____0)[5U] = a;
  uint8_t uu____1[1U][200U];
  memcpy(uu____1, b, (size_t)1U * sizeof(uint8_t[200U]));
  libcrux_sha3_portable_keccak_load_block_full___144size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_144size_t_6uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice last[1U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[1U][200U] = {{0U}};
  {
    size_t i = (size_t)0U;
    if (last_len > (size_t)0U) {
      Eurydice_slice uu____0 = Eurydice_array_to_subslice(
          (size_t)200U, blocks[i],
          (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                                  .end = last_len}),
          uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
      core_slice___Slice_T___copy_from_slice(uu____0, last[i], uint8_t, void *);
    }
    blocks[i][last_len] = 6U;
    size_t uu____1 = i;
    size_t uu____2 = (size_t)144U - (size_t)1U;
    blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;
  }
  uint64_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[1U][200U];
  memcpy(uu____4, blocks, (size_t)1U * sizeof(uint8_t[200U]));
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block_full___144size_t(
      uu____3, uu____4);
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_store_block___144size_t(uint64_t (*s)[5U],
                                                     Eurydice_slice out[1U]) {
  for (size_t i = (size_t)0U; i < (size_t)144U / (size_t)8U; i++) {
    size_t i0 = i;
    Eurydice_slice uu____0 = Eurydice_slice_subslice2(
        out[0U], (size_t)8U * i0, (size_t)8U * i0 + (size_t)8U, uint8_t,
        Eurydice_slice);
    uint8_t ret[8U];
    core_num__u64_9__to_le_bytes(s[i0 / (size_t)5U][i0 % (size_t)5U], ret);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)8U, ret, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_store_block_full___144size_t(
    uint64_t (*s)[5U], uint8_t ret[1U][200U]) {
  uint8_t out[200U] = {0U};
  Eurydice_slice buf[1U] = {
      Eurydice_array_to_slice((size_t)200U, out, uint8_t, Eurydice_slice)};
  libcrux_sha3_portable_keccak_store_block___144size_t(s, buf);
  uint8_t uu____0[200U];
  memcpy(uu____0, out, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[0U], uu____0, (size_t)200U * sizeof(uint8_t));
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___144size_t(
    uint64_t (*a)[5U], uint8_t ret[1U][200U]) {
  uint8_t ret0[1U][200U];
  libcrux_sha3_portable_keccak_store_block_full___144size_t(a, ret0);
  memcpy(ret, ret0, (size_t)1U * sizeof(uint8_t[200U]));
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_144size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  uint8_t b[1U][200U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___144size_t(
      s->st, b);
  {
    size_t i = (size_t)0U;
    Eurydice_slice uu____0 = out[i];
    uint8_t *uu____1 = b[i];
    core_ops_range_Range__size_t lit;
    lit.start = (size_t)0U;
    lit.end = core_slice___Slice_T___len(out[i], uint8_t, size_t);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                   core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___144size_t(
    uint64_t (*a)[5U], Eurydice_slice b[1U]) {
  libcrux_sha3_portable_keccak_store_block___144size_t(a, b);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_144size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___144size_t(
      s->st, out);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_144size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___144size_t(
      s->st, out);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_144size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(&s);
  uint8_t b[1U][200U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___144size_t(
      s.st, b);
  {
    size_t i = (size_t)0U;
    Eurydice_slice uu____0 = out[i];
    uint8_t *uu____1 = b[i];
    core_ops_range_Range__size_t lit;
    lit.start = (size_t)0U;
    lit.end = core_slice___Slice_T___len(out[i], uint8_t, size_t);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                   core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_144size_t_6uint8_t(
    Eurydice_slice data[1U], Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s =
      libcrux_sha3_generic_keccak__libcrux_sha3__generic_keccak__KeccakState_T__N__TraitClause_0__1__new__uint64_t_1size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)144U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____0 = &s;
    Eurydice_slice uu____1[1U];
    memcpy(uu____1, data, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice ret[1U];
    libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
        uu____1, i0 * (size_t)144U, (size_t)144U, ret);
    libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_144size_t(
        uu____0, ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)144U;
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____2 = &s;
  Eurydice_slice uu____3[1U];
  memcpy(uu____3, data, (size_t)1U * sizeof(Eurydice_slice));
  Eurydice_slice ret[1U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
      uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem, rem,
      ret);
  libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_144size_t_6uint8_t(
      uu____2, ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)144U;
  size_t last = outlen - outlen % (size_t)144U;
  if (blocks == (size_t)0U) {
    libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_144size_t(
        &s, out);
  } else {
    K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____4 =
        libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
            out, (size_t)144U);
    Eurydice_slice o0[1U];
    memcpy(o0, uu____4.fst, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice o1[1U];
    memcpy(o1, uu____4.snd, (size_t)1U * sizeof(Eurydice_slice));
    libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_144size_t(
        &s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____5 =
            libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
                o1, (size_t)144U);
        Eurydice_slice o[1U];
        memcpy(o, uu____5.fst, (size_t)1U * sizeof(Eurydice_slice));
        Eurydice_slice orest[1U];
        memcpy(orest, uu____5.snd, (size_t)1U * sizeof(Eurydice_slice));
        libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_144size_t(
            &s, o);
        memcpy(o1, orest, (size_t)1U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_144size_t(s,
                                                                           o1);
    }
  }
}

static KRML_MUSTINLINE void libcrux_sha3_portable_keccakx1___144size_t_6uint8_t(
    Eurydice_slice data[1U], Eurydice_slice out[1U]) {
  Eurydice_slice uu____0[1U];
  memcpy(uu____0, data, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_144size_t_6uint8_t(
      uu____0, out);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block___136size_t(
    uint64_t (*a)[5U], Eurydice_slice b[1U]) {
  uint64_t(*uu____0)[5U] = a;
  Eurydice_slice uu____1[1U];
  memcpy(uu____1, b, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_portable_keccak_load_block___136size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice blocks[1U]) {
  uint64_t(*uu____0)[5U] = s->st;
  Eurydice_slice uu____1[1U];
  memcpy(uu____1, blocks, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block___136size_t(
      uu____0, uu____1);
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_store_block_full___136size_t(
    uint64_t (*s)[5U], uint8_t ret[1U][200U]) {
  uint8_t out[200U] = {0U};
  Eurydice_slice buf[1U] = {
      Eurydice_array_to_slice((size_t)200U, out, uint8_t, Eurydice_slice)};
  libcrux_sha3_portable_keccak_store_block___136size_t(s, buf);
  uint8_t uu____0[200U];
  memcpy(uu____0, out, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[0U], uu____0, (size_t)200U * sizeof(uint8_t));
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___136size_t(
    uint64_t (*a)[5U], uint8_t ret[1U][200U]) {
  uint8_t ret0[1U][200U];
  libcrux_sha3_portable_keccak_store_block_full___136size_t(a, ret0);
  memcpy(ret, ret0, (size_t)1U * sizeof(uint8_t[200U]));
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  uint8_t b[1U][200U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___136size_t(
      s->st, b);
  {
    size_t i = (size_t)0U;
    Eurydice_slice uu____0 = out[i];
    uint8_t *uu____1 = b[i];
    core_ops_range_Range__size_t lit;
    lit.start = (size_t)0U;
    lit.end = core_slice___Slice_T___len(out[i], uint8_t, size_t);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                   core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(&s);
  uint8_t b[1U][200U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___136size_t(
      s.st, b);
  {
    size_t i = (size_t)0U;
    Eurydice_slice uu____0 = out[i];
    uint8_t *uu____1 = b[i];
    core_ops_range_Range__size_t lit;
    lit.start = (size_t)0U;
    lit.end = core_slice___Slice_T___len(out[i], uint8_t, size_t);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                   core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_136size_t_31uint8_t(
    Eurydice_slice data[1U], Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s =
      libcrux_sha3_generic_keccak__libcrux_sha3__generic_keccak__KeccakState_T__N__TraitClause_0__1__new__uint64_t_1size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)136U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____0 = &s;
    Eurydice_slice uu____1[1U];
    memcpy(uu____1, data, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice ret[1U];
    libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
        uu____1, i0 * (size_t)136U, (size_t)136U, ret);
    libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_136size_t(
        uu____0, ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)136U;
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____2 = &s;
  Eurydice_slice uu____3[1U];
  memcpy(uu____3, data, (size_t)1U * sizeof(Eurydice_slice));
  Eurydice_slice ret[1U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
      uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem, rem,
      ret);
  libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_136size_t_31uint8_t(
      uu____2, ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)136U;
  size_t last = outlen - outlen % (size_t)136U;
  if (blocks == (size_t)0U) {
    libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_136size_t(
        &s, out);
  } else {
    K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____4 =
        libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
            out, (size_t)136U);
    Eurydice_slice o0[1U];
    memcpy(o0, uu____4.fst, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice o1[1U];
    memcpy(o1, uu____4.snd, (size_t)1U * sizeof(Eurydice_slice));
    libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_136size_t(
        &s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____5 =
            libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
                o1, (size_t)136U);
        Eurydice_slice o[1U];
        memcpy(o, uu____5.fst, (size_t)1U * sizeof(Eurydice_slice));
        Eurydice_slice orest[1U];
        memcpy(orest, uu____5.snd, (size_t)1U * sizeof(Eurydice_slice));
        libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_136size_t(
            &s, o);
        memcpy(o1, orest, (size_t)1U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_136size_t(s,
                                                                           o1);
    }
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccakx1___136size_t_31uint8_t(Eurydice_slice data[1U],
                                                     Eurydice_slice out[1U]) {
  Eurydice_slice uu____0[1U];
  memcpy(uu____0, data, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_136size_t_31uint8_t(
      uu____0, out);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_136size_t_6uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice last[1U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[1U][200U] = {{0U}};
  {
    size_t i = (size_t)0U;
    if (last_len > (size_t)0U) {
      Eurydice_slice uu____0 = Eurydice_array_to_subslice(
          (size_t)200U, blocks[i],
          (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                                  .end = last_len}),
          uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
      core_slice___Slice_T___copy_from_slice(uu____0, last[i], uint8_t, void *);
    }
    blocks[i][last_len] = 6U;
    size_t uu____1 = i;
    size_t uu____2 = (size_t)136U - (size_t)1U;
    blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;
  }
  uint64_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[1U][200U];
  memcpy(uu____4, blocks, (size_t)1U * sizeof(uint8_t[200U]));
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block_full___136size_t(
      uu____3, uu____4);
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_136size_t_6uint8_t(
    Eurydice_slice data[1U], Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s =
      libcrux_sha3_generic_keccak__libcrux_sha3__generic_keccak__KeccakState_T__N__TraitClause_0__1__new__uint64_t_1size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)136U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____0 = &s;
    Eurydice_slice uu____1[1U];
    memcpy(uu____1, data, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice ret[1U];
    libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
        uu____1, i0 * (size_t)136U, (size_t)136U, ret);
    libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_136size_t(
        uu____0, ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)136U;
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____2 = &s;
  Eurydice_slice uu____3[1U];
  memcpy(uu____3, data, (size_t)1U * sizeof(Eurydice_slice));
  Eurydice_slice ret[1U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
      uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem, rem,
      ret);
  libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_136size_t_6uint8_t(
      uu____2, ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)136U;
  size_t last = outlen - outlen % (size_t)136U;
  if (blocks == (size_t)0U) {
    libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_136size_t(
        &s, out);
  } else {
    K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____4 =
        libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
            out, (size_t)136U);
    Eurydice_slice o0[1U];
    memcpy(o0, uu____4.fst, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice o1[1U];
    memcpy(o1, uu____4.snd, (size_t)1U * sizeof(Eurydice_slice));
    libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_136size_t(
        &s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____5 =
            libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
                o1, (size_t)136U);
        Eurydice_slice o[1U];
        memcpy(o, uu____5.fst, (size_t)1U * sizeof(Eurydice_slice));
        Eurydice_slice orest[1U];
        memcpy(orest, uu____5.snd, (size_t)1U * sizeof(Eurydice_slice));
        libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_136size_t(
            &s, o);
        memcpy(o1, orest, (size_t)1U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_136size_t(s,
                                                                           o1);
    }
  }
}

static KRML_MUSTINLINE void libcrux_sha3_portable_keccakx1___136size_t_6uint8_t(
    Eurydice_slice data[1U], Eurydice_slice out[1U]) {
  Eurydice_slice uu____0[1U];
  memcpy(uu____0, data, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_136size_t_6uint8_t(
      uu____0, out);
}

static KRML_MUSTINLINE void libcrux_sha3_portable_keccak_load_block___72size_t(
    uint64_t (*s)[5U], Eurydice_slice blocks[1U]) {
  for (size_t i = (size_t)0U; i < (size_t)72U / (size_t)8U; i++) {
    size_t i0 = i;
    uint8_t uu____0[8U];
    core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError dst;
    Eurydice_slice_to_array2(
        &dst,
        Eurydice_slice_subslice2(blocks[0U], (size_t)8U * i0,
                                 (size_t)8U * i0 + (size_t)8U, uint8_t,
                                 Eurydice_slice),
        Eurydice_slice, uint8_t[8U], void *);
    core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
        dst, uu____0);
    size_t uu____1 = i0 / (size_t)5U;
    size_t uu____2 = i0 % (size_t)5U;
    s[uu____1][uu____2] =
        s[uu____1][uu____2] ^ core_num__u64_9__from_le_bytes(uu____0);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block___72size_t(
    uint64_t (*a)[5U], Eurydice_slice b[1U]) {
  uint64_t(*uu____0)[5U] = a;
  Eurydice_slice uu____1[1U];
  memcpy(uu____1, b, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_portable_keccak_load_block___72size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_72size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice blocks[1U]) {
  uint64_t(*uu____0)[5U] = s->st;
  Eurydice_slice uu____1[1U];
  memcpy(uu____1, blocks, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block___72size_t(
      uu____0, uu____1);
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_load_block_full___72size_t(
    uint64_t (*s)[5U], uint8_t blocks[1U][200U]) {
  Eurydice_slice buf[1U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice)};
  libcrux_sha3_portable_keccak_load_block___72size_t(s, buf);
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block_full___72size_t(
    uint64_t (*a)[5U], uint8_t b[1U][200U]) {
  uint64_t(*uu____0)[5U] = a;
  uint8_t uu____1[1U][200U];
  memcpy(uu____1, b, (size_t)1U * sizeof(uint8_t[200U]));
  libcrux_sha3_portable_keccak_load_block_full___72size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_72size_t_6uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice last[1U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[1U][200U] = {{0U}};
  {
    size_t i = (size_t)0U;
    if (last_len > (size_t)0U) {
      Eurydice_slice uu____0 = Eurydice_array_to_subslice(
          (size_t)200U, blocks[i],
          (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                                  .end = last_len}),
          uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
      core_slice___Slice_T___copy_from_slice(uu____0, last[i], uint8_t, void *);
    }
    blocks[i][last_len] = 6U;
    size_t uu____1 = i;
    size_t uu____2 = (size_t)72U - (size_t)1U;
    blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;
  }
  uint64_t(*uu____3)[5U] = s->st;
  uint8_t uu____4[1U][200U];
  memcpy(uu____4, blocks, (size_t)1U * sizeof(uint8_t[200U]));
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___load_block_full___72size_t(
      uu____3, uu____4);
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
}

static KRML_MUSTINLINE void libcrux_sha3_portable_keccak_store_block___72size_t(
    uint64_t (*s)[5U], Eurydice_slice out[1U]) {
  for (size_t i = (size_t)0U; i < (size_t)72U / (size_t)8U; i++) {
    size_t i0 = i;
    Eurydice_slice uu____0 = Eurydice_slice_subslice2(
        out[0U], (size_t)8U * i0, (size_t)8U * i0 + (size_t)8U, uint8_t,
        Eurydice_slice);
    uint8_t ret[8U];
    core_num__u64_9__to_le_bytes(s[i0 / (size_t)5U][i0 % (size_t)5U], ret);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)8U, ret, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak_store_block_full___72size_t(
    uint64_t (*s)[5U], uint8_t ret[1U][200U]) {
  uint8_t out[200U] = {0U};
  Eurydice_slice buf[1U] = {
      Eurydice_array_to_slice((size_t)200U, out, uint8_t, Eurydice_slice)};
  libcrux_sha3_portable_keccak_store_block___72size_t(s, buf);
  uint8_t uu____0[200U];
  memcpy(uu____0, out, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[0U], uu____0, (size_t)200U * sizeof(uint8_t));
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___72size_t(
    uint64_t (*a)[5U], uint8_t ret[1U][200U]) {
  uint8_t ret0[1U][200U];
  libcrux_sha3_portable_keccak_store_block_full___72size_t(a, ret0);
  memcpy(ret, ret0, (size_t)1U * sizeof(uint8_t[200U]));
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_72size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  uint8_t b[1U][200U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___72size_t(
      s->st, b);
  {
    size_t i = (size_t)0U;
    Eurydice_slice uu____0 = out[i];
    uint8_t *uu____1 = b[i];
    core_ops_range_Range__size_t lit;
    lit.start = (size_t)0U;
    lit.end = core_slice___Slice_T___len(out[i], uint8_t, size_t);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                   core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___72size_t(
    uint64_t (*a)[5U], Eurydice_slice b[1U]) {
  libcrux_sha3_portable_keccak_store_block___72size_t(a, b);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_72size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___72size_t(
      s->st, out);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_72size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(s);
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block___72size_t(
      s->st, out);
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_72size_t(
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s,
    Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_keccakf1600__uint64_t_1size_t(&s);
  uint8_t b[1U][200U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___store_block_full___72size_t(
      s.st, b);
  {
    size_t i = (size_t)0U;
    Eurydice_slice uu____0 = out[i];
    uint8_t *uu____1 = b[i];
    core_ops_range_Range__size_t lit;
    lit.start = (size_t)0U;
    lit.end = core_slice___Slice_T___len(out[i], uint8_t, size_t);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                   core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_72size_t_6uint8_t(
    Eurydice_slice data[1U], Eurydice_slice out[1U]) {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t s =
      libcrux_sha3_generic_keccak__libcrux_sha3__generic_keccak__KeccakState_T__N__TraitClause_0__1__new__uint64_t_1size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)72U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____0 = &s;
    Eurydice_slice uu____1[1U];
    memcpy(uu____1, data, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice ret[1U];
    libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
        uu____1, i0 * (size_t)72U, (size_t)72U, ret);
    libcrux_sha3_generic_keccak_absorb_block__uint64_t_1size_t_72size_t(uu____0,
                                                                        ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)72U;
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t *uu____2 = &s;
  Eurydice_slice uu____3[1U];
  memcpy(uu____3, data, (size_t)1U * sizeof(Eurydice_slice));
  Eurydice_slice ret[1U];
  libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___slice_n(
      uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem, rem,
      ret);
  libcrux_sha3_generic_keccak_absorb_final__uint64_t_1size_t_72size_t_6uint8_t(
      uu____2, ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)72U;
  size_t last = outlen - outlen % (size_t)72U;
  if (blocks == (size_t)0U) {
    libcrux_sha3_generic_keccak_squeeze_first_and_last__uint64_t_1size_t_72size_t(
        &s, out);
  } else {
    K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____4 =
        libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
            out, (size_t)72U);
    Eurydice_slice o0[1U];
    memcpy(o0, uu____4.fst, (size_t)1U * sizeof(Eurydice_slice));
    Eurydice_slice o1[1U];
    memcpy(o1, uu____4.snd, (size_t)1U * sizeof(Eurydice_slice));
    libcrux_sha3_generic_keccak_squeeze_first_block__uint64_t_1size_t_72size_t(
        &s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_1size_t__Eurydice_slice_uint8_t_1size_t_ uu____5 =
            libcrux_sha3_portable_keccak___libcrux_sha3__traits__internal__KeccakItem_1__usize__for_u64___split_at_mut_n(
                o1, (size_t)72U);
        Eurydice_slice o[1U];
        memcpy(o, uu____5.fst, (size_t)1U * sizeof(Eurydice_slice));
        Eurydice_slice orest[1U];
        memcpy(orest, uu____5.snd, (size_t)1U * sizeof(Eurydice_slice));
        libcrux_sha3_generic_keccak_squeeze_next_block__uint64_t_1size_t_72size_t(
            &s, o);
        memcpy(o1, orest, (size_t)1U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      libcrux_sha3_generic_keccak_squeeze_last__uint64_t_1size_t_72size_t(s,
                                                                          o1);
    }
  }
}

static KRML_MUSTINLINE void libcrux_sha3_portable_keccakx1___72size_t_6uint8_t(
    Eurydice_slice data[1U], Eurydice_slice out[1U]) {
  Eurydice_slice uu____0[1U];
  memcpy(uu____0, data, (size_t)1U * sizeof(Eurydice_slice));
  libcrux_sha3_generic_keccak_keccak__uint64_t_1size_t_72size_t_6uint8_t(
      uu____0, out);
}

#if defined(__cplusplus)
}
#endif

#define __libcrux_sha3_internal_H_DEFINED
#endif
