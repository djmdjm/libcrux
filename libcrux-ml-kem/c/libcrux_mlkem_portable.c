/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: 45b95e0f63cb830202c0b3ca00a341a3451a02ba
 * Eurydice: 013beb9e4046a151131c6a56dfe25e606b49c4a1
 * Karamel: 4626e5fcb3787a47c806d160539342ade4b0809c
 * F*: b2931dfbe46e839cd757220c63d48c71335bb1ae
 * Libcrux: 8a3c1c4c84f258580d53bfef5ad2b1b7d5ef5fca
 */

#include "internal/libcrux_mlkem_portable.h"

#include "internal/libcrux_core.h"
#include "internal/libcrux_sha3_internal.h"

KRML_MUSTINLINE void libcrux_ml_kem_hash_functions_portable_G(
    Eurydice_slice input, uint8_t ret[64U]) {
  uint8_t digest[64U] = {0U};
  libcrux_sha3_portable_sha512(
      Eurydice_array_to_slice((size_t)64U, digest, uint8_t, Eurydice_slice),
      input);
  memcpy(ret, digest, (size_t)64U * sizeof(uint8_t));
}

KRML_MUSTINLINE void libcrux_ml_kem_hash_functions_portable_H(
    Eurydice_slice input, uint8_t ret[32U]) {
  uint8_t digest[32U] = {0U};
  libcrux_sha3_portable_sha256(
      Eurydice_array_to_slice((size_t)32U, digest, uint8_t, Eurydice_slice),
      input);
  memcpy(ret, digest, (size_t)32U * sizeof(uint8_t));
}

const int16_t libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[128U] = {
    (int16_t)-1044, (int16_t)-758,  (int16_t)-359,  (int16_t)-1517,
    (int16_t)1493,  (int16_t)1422,  (int16_t)287,   (int16_t)202,
    (int16_t)-171,  (int16_t)622,   (int16_t)1577,  (int16_t)182,
    (int16_t)962,   (int16_t)-1202, (int16_t)-1474, (int16_t)1468,
    (int16_t)573,   (int16_t)-1325, (int16_t)264,   (int16_t)383,
    (int16_t)-829,  (int16_t)1458,  (int16_t)-1602, (int16_t)-130,
    (int16_t)-681,  (int16_t)1017,  (int16_t)732,   (int16_t)608,
    (int16_t)-1542, (int16_t)411,   (int16_t)-205,  (int16_t)-1571,
    (int16_t)1223,  (int16_t)652,   (int16_t)-552,  (int16_t)1015,
    (int16_t)-1293, (int16_t)1491,  (int16_t)-282,  (int16_t)-1544,
    (int16_t)516,   (int16_t)-8,    (int16_t)-320,  (int16_t)-666,
    (int16_t)-1618, (int16_t)-1162, (int16_t)126,   (int16_t)1469,
    (int16_t)-853,  (int16_t)-90,   (int16_t)-271,  (int16_t)830,
    (int16_t)107,   (int16_t)-1421, (int16_t)-247,  (int16_t)-951,
    (int16_t)-398,  (int16_t)961,   (int16_t)-1508, (int16_t)-725,
    (int16_t)448,   (int16_t)-1065, (int16_t)677,   (int16_t)-1275,
    (int16_t)-1103, (int16_t)430,   (int16_t)555,   (int16_t)843,
    (int16_t)-1251, (int16_t)871,   (int16_t)1550,  (int16_t)105,
    (int16_t)422,   (int16_t)587,   (int16_t)177,   (int16_t)-235,
    (int16_t)-291,  (int16_t)-460,  (int16_t)1574,  (int16_t)1653,
    (int16_t)-246,  (int16_t)778,   (int16_t)1159,  (int16_t)-147,
    (int16_t)-777,  (int16_t)1483,  (int16_t)-602,  (int16_t)1119,
    (int16_t)-1590, (int16_t)644,   (int16_t)-872,  (int16_t)349,
    (int16_t)418,   (int16_t)329,   (int16_t)-156,  (int16_t)-75,
    (int16_t)817,   (int16_t)1097,  (int16_t)603,   (int16_t)610,
    (int16_t)1322,  (int16_t)-1285, (int16_t)-1465, (int16_t)384,
    (int16_t)-1215, (int16_t)-136,  (int16_t)1218,  (int16_t)-1335,
    (int16_t)-874,  (int16_t)220,   (int16_t)-1187, (int16_t)-1659,
    (int16_t)-1185, (int16_t)-1530, (int16_t)-1278, (int16_t)794,
    (int16_t)-1510, (int16_t)-854,  (int16_t)-870,  (int16_t)478,
    (int16_t)-108,  (int16_t)-308,  (int16_t)996,   (int16_t)991,
    (int16_t)958,   (int16_t)-1460, (int16_t)1522,  (int16_t)1628};

KRML_MUSTINLINE
    K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t
    libcrux_ml_kem_vector_portable_serialize_deserialize_4_int(
        Eurydice_slice bytes) {
  int16_t v0 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)0U, uint8_t, uint8_t *, uint8_t) &
                         15U);
  int16_t v1 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)0U, uint8_t, uint8_t *, uint8_t) >>
                             4U &
                         15U);
  int16_t v2 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)1U, uint8_t, uint8_t *, uint8_t) &
                         15U);
  int16_t v3 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)1U, uint8_t, uint8_t *, uint8_t) >>
                             4U &
                         15U);
  int16_t v4 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)2U, uint8_t, uint8_t *, uint8_t) &
                         15U);
  int16_t v5 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)2U, uint8_t, uint8_t *, uint8_t) >>
                             4U &
                         15U);
  int16_t v6 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)3U, uint8_t, uint8_t *, uint8_t) &
                         15U);
  int16_t v7 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)3U, uint8_t, uint8_t *, uint8_t) >>
                             4U &
                         15U);
  return (CLITERAL(
      K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t){
      .fst = v0,
      .snd = v1,
      .thd = v2,
      .f3 = v3,
      .f4 = v4,
      .f5 = v5,
      .f6 = v6,
      .f7 = v7});
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_vector_type_zero(void) {
  libcrux_ml_kem_vector_portable_vector_type_PortableVector lit;
  lit.elements[0U] = (int16_t)0;
  lit.elements[1U] = (int16_t)0;
  lit.elements[2U] = (int16_t)0;
  lit.elements[3U] = (int16_t)0;
  lit.elements[4U] = (int16_t)0;
  lit.elements[5U] = (int16_t)0;
  lit.elements[6U] = (int16_t)0;
  lit.elements[7U] = (int16_t)0;
  lit.elements[8U] = (int16_t)0;
  lit.elements[9U] = (int16_t)0;
  lit.elements[10U] = (int16_t)0;
  lit.elements[11U] = (int16_t)0;
  lit.elements[12U] = (int16_t)0;
  lit.elements[13U] = (int16_t)0;
  lit.elements[14U] = (int16_t)0;
  lit.elements[15U] = (int16_t)0;
  return lit;
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_serialize_deserialize_4(Eurydice_slice bytes) {
  K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t v0_7 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_4_int(
          Eurydice_slice_subslice2(bytes, (size_t)0U, (size_t)4U, uint8_t,
                                   Eurydice_slice));
  K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t v8_15 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_4_int(
          Eurydice_slice_subslice2(bytes, (size_t)4U, (size_t)8U, uint8_t,
                                   Eurydice_slice));
  libcrux_ml_kem_vector_portable_vector_type_PortableVector v =
      libcrux_ml_kem_vector_portable_vector_type_zero();
  v.elements[0U] = v0_7.fst;
  v.elements[1U] = v0_7.snd;
  v.elements[2U] = v0_7.thd;
  v.elements[3U] = v0_7.f3;
  v.elements[4U] = v0_7.f4;
  v.elements[5U] = v0_7.f5;
  v.elements[6U] = v0_7.f6;
  v.elements[7U] = v0_7.f7;
  v.elements[8U] = v8_15.fst;
  v.elements[9U] = v8_15.snd;
  v.elements[10U] = v8_15.thd;
  v.elements[11U] = v8_15.f3;
  v.elements[12U] = v8_15.f4;
  v.elements[13U] = v8_15.f5;
  v.elements[14U] = v8_15.f6;
  v.elements[15U] = v8_15.f7;
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_4(
    Eurydice_slice a) {
  return libcrux_ml_kem_vector_portable_serialize_deserialize_4(a);
}

KRML_MUSTINLINE void libcrux_ml_kem_vector_portable_vector_type_to_i16_array(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector x,
    int16_t ret[16U]) {
  memcpy(ret, x.elements, (size_t)16U * sizeof(int16_t));
}

void libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___to_i16_array(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector x,
    int16_t ret[16U]) {
  libcrux_ml_kem_vector_portable_vector_type_to_i16_array(x, ret);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_vector_type_from_i16_array(
    Eurydice_slice array) {
  libcrux_ml_kem_vector_portable_vector_type_PortableVector lit;
  int16_t ret[16U];
  core_result_Result__int16_t_16size_t__core_array_TryFromSliceError dst;
  Eurydice_slice_to_array2(
      &dst,
      Eurydice_slice_subslice2(array, (size_t)0U, (size_t)16U, int16_t,
                               Eurydice_slice),
      Eurydice_slice, int16_t[16U], void *);
  core_result__core__result__Result_T__E___unwrap_0a(dst, ret);
  memcpy(lit.elements, ret, (size_t)16U * sizeof(int16_t));
  return lit;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___from_i16_array(
    Eurydice_slice array) {
  return libcrux_ml_kem_vector_portable_vector_type_from_i16_array(array);
}

KRML_MUSTINLINE K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t
libcrux_ml_kem_vector_portable_serialize_serialize_5_int(Eurydice_slice v) {
  uint8_t r0 =
      (uint8_t)(Eurydice_slice_index(v, (size_t)0U, int16_t, int16_t *,
                                     int16_t) |
                Eurydice_slice_index(v, (size_t)1U, int16_t, int16_t *, int16_t)
                    << 5U);
  uint8_t r1 =
      (uint8_t)((Eurydice_slice_index(v, (size_t)1U, int16_t, int16_t *,
                                      int16_t) >>
                     3U |
                 Eurydice_slice_index(v, (size_t)2U, int16_t, int16_t *,
                                      int16_t)
                     << 2U) |
                Eurydice_slice_index(v, (size_t)3U, int16_t, int16_t *, int16_t)
                    << 7U);
  uint8_t r2 =
      (uint8_t)(Eurydice_slice_index(v, (size_t)3U, int16_t, int16_t *,
                                     int16_t) >>
                    1U |
                Eurydice_slice_index(v, (size_t)4U, int16_t, int16_t *, int16_t)
                    << 4U);
  uint8_t r3 =
      (uint8_t)((Eurydice_slice_index(v, (size_t)4U, int16_t, int16_t *,
                                      int16_t) >>
                     4U |
                 Eurydice_slice_index(v, (size_t)5U, int16_t, int16_t *,
                                      int16_t)
                     << 1U) |
                Eurydice_slice_index(v, (size_t)6U, int16_t, int16_t *, int16_t)
                    << 6U);
  uint8_t r4 =
      (uint8_t)(Eurydice_slice_index(v, (size_t)6U, int16_t, int16_t *,
                                     int16_t) >>
                    2U |
                Eurydice_slice_index(v, (size_t)7U, int16_t, int16_t *, int16_t)
                    << 3U);
  return (CLITERAL(K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t){
      .fst = r0, .snd = r1, .thd = r2, .f3 = r3, .f4 = r4});
}

KRML_MUSTINLINE void libcrux_ml_kem_vector_portable_serialize_serialize_5(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v,
    uint8_t ret[10U]) {
  K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t r0_4 =
      libcrux_ml_kem_vector_portable_serialize_serialize_5_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)0U, (size_t)8U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t r5_9 =
      libcrux_ml_kem_vector_portable_serialize_serialize_5_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)8U, (size_t)16U,
                                      int16_t, Eurydice_slice));
  uint8_t result[10U] = {0U};
  result[0U] = r0_4.fst;
  result[1U] = r0_4.snd;
  result[2U] = r0_4.thd;
  result[3U] = r0_4.f3;
  result[4U] = r0_4.f4;
  result[5U] = r5_9.fst;
  result[6U] = r5_9.snd;
  result[7U] = r5_9.thd;
  result[8U] = r5_9.f3;
  result[9U] = r5_9.f4;
  memcpy(ret, result, (size_t)10U * sizeof(uint8_t));
}

void libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_5(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a,
    uint8_t ret[10U]) {
  libcrux_ml_kem_vector_portable_serialize_serialize_5(a, ret);
}

KRML_MUSTINLINE
    K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t
    libcrux_ml_kem_vector_portable_serialize_deserialize_5_int(
        Eurydice_slice bytes) {
  int16_t v0 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)0U, uint8_t, uint8_t *, uint8_t) &
                         31U);
  int16_t v1 = (int16_t)(((uint32_t)Eurydice_slice_index(
                              bytes, (size_t)1U, uint8_t, uint8_t *, uint8_t) &
                          3U) << 3U |
                         (uint32_t)Eurydice_slice_index(
                             bytes, (size_t)0U, uint8_t, uint8_t *, uint8_t) >>
                             5U);
  int16_t v2 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)1U, uint8_t, uint8_t *, uint8_t) >>
                             2U &
                         31U);
  int16_t v3 = (int16_t)(((uint32_t)Eurydice_slice_index(
                              bytes, (size_t)2U, uint8_t, uint8_t *, uint8_t) &
                          15U)
                             << 1U |
                         (uint32_t)Eurydice_slice_index(
                             bytes, (size_t)1U, uint8_t, uint8_t *, uint8_t) >>
                             7U);
  int16_t v4 = (int16_t)(((uint32_t)Eurydice_slice_index(
                              bytes, (size_t)3U, uint8_t, uint8_t *, uint8_t) &
                          1U) << 4U |
                         (uint32_t)Eurydice_slice_index(
                             bytes, (size_t)2U, uint8_t, uint8_t *, uint8_t) >>
                             4U);
  int16_t v5 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)3U, uint8_t, uint8_t *, uint8_t) >>
                             1U &
                         31U);
  int16_t v6 = (int16_t)(((uint32_t)Eurydice_slice_index(
                              bytes, (size_t)4U, uint8_t, uint8_t *, uint8_t) &
                          7U) << 2U |
                         (uint32_t)Eurydice_slice_index(
                             bytes, (size_t)3U, uint8_t, uint8_t *, uint8_t) >>
                             6U);
  int16_t v7 = (int16_t)((uint32_t)Eurydice_slice_index(
                             bytes, (size_t)4U, uint8_t, uint8_t *, uint8_t) >>
                         3U);
  return (CLITERAL(
      K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t){
      .fst = v0,
      .snd = v1,
      .thd = v2,
      .f3 = v3,
      .f4 = v4,
      .f5 = v5,
      .f6 = v6,
      .f7 = v7});
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_serialize_deserialize_5(Eurydice_slice bytes) {
  K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t v0_7 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_5_int(
          Eurydice_slice_subslice2(bytes, (size_t)0U, (size_t)5U, uint8_t,
                                   Eurydice_slice));
  K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t v8_15 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_5_int(
          Eurydice_slice_subslice2(bytes, (size_t)5U, (size_t)10U, uint8_t,
                                   Eurydice_slice));
  libcrux_ml_kem_vector_portable_vector_type_PortableVector v =
      libcrux_ml_kem_vector_portable_vector_type_zero();
  v.elements[0U] = v0_7.fst;
  v.elements[1U] = v0_7.snd;
  v.elements[2U] = v0_7.thd;
  v.elements[3U] = v0_7.f3;
  v.elements[4U] = v0_7.f4;
  v.elements[5U] = v0_7.f5;
  v.elements[6U] = v0_7.f6;
  v.elements[7U] = v0_7.f7;
  v.elements[8U] = v8_15.fst;
  v.elements[9U] = v8_15.snd;
  v.elements[10U] = v8_15.thd;
  v.elements[11U] = v8_15.f3;
  v.elements[12U] = v8_15.f4;
  v.elements[13U] = v8_15.f5;
  v.elements[14U] = v8_15.f6;
  v.elements[15U] = v8_15.f7;
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_5(
    Eurydice_slice a) {
  return libcrux_ml_kem_vector_portable_serialize_deserialize_5(a);
}

KRML_MUSTINLINE
    K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t
    libcrux_ml_kem_vector_portable_serialize_deserialize_10_int(
        Eurydice_slice bytes) {
  int16_t r0 = ((int16_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)3)
                   << 8U |
               ((int16_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)255);
  int16_t r1 = ((int16_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)15)
                   << 6U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   2U;
  int16_t r2 = ((int16_t)Eurydice_slice_index(bytes, (size_t)3U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)63)
                   << 4U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   4U;
  int16_t r3 = (int16_t)Eurydice_slice_index(bytes, (size_t)4U, uint8_t,
                                             uint8_t *, uint8_t)
                   << 2U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)3U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   6U;
  int16_t r4 = ((int16_t)Eurydice_slice_index(bytes, (size_t)6U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)3)
                   << 8U |
               ((int16_t)Eurydice_slice_index(bytes, (size_t)5U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)255);
  int16_t r5 = ((int16_t)Eurydice_slice_index(bytes, (size_t)7U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)15)
                   << 6U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)6U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   2U;
  int16_t r6 = ((int16_t)Eurydice_slice_index(bytes, (size_t)8U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)63)
                   << 4U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)7U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   4U;
  int16_t r7 = (int16_t)Eurydice_slice_index(bytes, (size_t)9U, uint8_t,
                                             uint8_t *, uint8_t)
                   << 2U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)8U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   6U;
  return (CLITERAL(
      K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t){
      .fst = r0,
      .snd = r1,
      .thd = r2,
      .f3 = r3,
      .f4 = r4,
      .f5 = r5,
      .f6 = r6,
      .f7 = r7});
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_serialize_deserialize_10(Eurydice_slice bytes) {
  K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t v0_7 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_10_int(
          Eurydice_slice_subslice2(bytes, (size_t)0U, (size_t)10U, uint8_t,
                                   Eurydice_slice));
  K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t v8_15 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_10_int(
          Eurydice_slice_subslice2(bytes, (size_t)10U, (size_t)20U, uint8_t,
                                   Eurydice_slice));
  libcrux_ml_kem_vector_portable_vector_type_PortableVector v =
      libcrux_ml_kem_vector_portable_vector_type_zero();
  v.elements[0U] = v0_7.fst;
  v.elements[1U] = v0_7.snd;
  v.elements[2U] = v0_7.thd;
  v.elements[3U] = v0_7.f3;
  v.elements[4U] = v0_7.f4;
  v.elements[5U] = v0_7.f5;
  v.elements[6U] = v0_7.f6;
  v.elements[7U] = v0_7.f7;
  v.elements[8U] = v8_15.fst;
  v.elements[9U] = v8_15.snd;
  v.elements[10U] = v8_15.thd;
  v.elements[11U] = v8_15.f3;
  v.elements[12U] = v8_15.f4;
  v.elements[13U] = v8_15.f5;
  v.elements[14U] = v8_15.f6;
  v.elements[15U] = v8_15.f7;
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_10(
    Eurydice_slice a) {
  return libcrux_ml_kem_vector_portable_serialize_deserialize_10(a);
}

KRML_MUSTINLINE
    K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t
    libcrux_ml_kem_vector_portable_serialize_serialize_11_int(
        Eurydice_slice v) {
  uint8_t r0 =
      (uint8_t)Eurydice_slice_index(v, (size_t)0U, int16_t, int16_t *, int16_t);
  uint8_t r1 = (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)1U, int16_t,
                                                        int16_t *, int16_t) &
                                   (int16_t)31)
                   << 3U |
               (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)0U, int16_t,
                                                        int16_t *, int16_t) >>
                                   8U);
  uint8_t r2 = (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)2U, int16_t,
                                                        int16_t *, int16_t) &
                                   (int16_t)3)
                   << 6U |
               (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)1U, int16_t,
                                                        int16_t *, int16_t) >>
                                   5U);
  uint8_t r3 = (uint8_t)(Eurydice_slice_index(v, (size_t)2U, int16_t, int16_t *,
                                              int16_t) >>
                             2U &
                         (int16_t)255);
  uint8_t r4 = (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)3U, int16_t,
                                                        int16_t *, int16_t) &
                                   (int16_t)127)
                   << 1U |
               (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)2U, int16_t,
                                                        int16_t *, int16_t) >>
                                   10U);
  uint8_t r5 = (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)4U, int16_t,
                                                        int16_t *, int16_t) &
                                   (int16_t)15)
                   << 4U |
               (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)3U, int16_t,
                                                        int16_t *, int16_t) >>
                                   7U);
  uint8_t r6 = (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)5U, int16_t,
                                                        int16_t *, int16_t) &
                                   (int16_t)1)
                   << 7U |
               (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)4U, int16_t,
                                                        int16_t *, int16_t) >>
                                   4U);
  uint8_t r7 = (uint8_t)(Eurydice_slice_index(v, (size_t)5U, int16_t, int16_t *,
                                              int16_t) >>
                             1U &
                         (int16_t)255);
  uint8_t r8 = (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)6U, int16_t,
                                                        int16_t *, int16_t) &
                                   (int16_t)63)
                   << 2U |
               (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)5U, int16_t,
                                                        int16_t *, int16_t) >>
                                   9U);
  uint8_t r9 = (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)7U, int16_t,
                                                        int16_t *, int16_t) &
                                   (int16_t)7)
                   << 5U |
               (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)6U, int16_t,
                                                        int16_t *, int16_t) >>
                                   6U);
  uint8_t r10 = (uint8_t)(Eurydice_slice_index(v, (size_t)7U, int16_t,
                                               int16_t *, int16_t) >>
                          3U);
  return (CLITERAL(
      K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t){
      .fst = r0,
      .snd = r1,
      .thd = r2,
      .f3 = r3,
      .f4 = r4,
      .f5 = r5,
      .f6 = r6,
      .f7 = r7,
      .f8 = r8,
      .f9 = r9,
      .f10 = r10});
}

KRML_MUSTINLINE void libcrux_ml_kem_vector_portable_serialize_serialize_11(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v,
    uint8_t ret[22U]) {
  K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t
      r0_10 = libcrux_ml_kem_vector_portable_serialize_serialize_11_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)0U, (size_t)8U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t_uint8_t
      r11_21 = libcrux_ml_kem_vector_portable_serialize_serialize_11_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)8U, (size_t)16U,
                                      int16_t, Eurydice_slice));
  uint8_t result[22U] = {0U};
  result[0U] = r0_10.fst;
  result[1U] = r0_10.snd;
  result[2U] = r0_10.thd;
  result[3U] = r0_10.f3;
  result[4U] = r0_10.f4;
  result[5U] = r0_10.f5;
  result[6U] = r0_10.f6;
  result[7U] = r0_10.f7;
  result[8U] = r0_10.f8;
  result[9U] = r0_10.f9;
  result[10U] = r0_10.f10;
  result[11U] = r11_21.fst;
  result[12U] = r11_21.snd;
  result[13U] = r11_21.thd;
  result[14U] = r11_21.f3;
  result[15U] = r11_21.f4;
  result[16U] = r11_21.f5;
  result[17U] = r11_21.f6;
  result[18U] = r11_21.f7;
  result[19U] = r11_21.f8;
  result[20U] = r11_21.f9;
  result[21U] = r11_21.f10;
  memcpy(ret, result, (size_t)22U * sizeof(uint8_t));
}

void libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_11(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a,
    uint8_t ret[22U]) {
  libcrux_ml_kem_vector_portable_serialize_serialize_11(a, ret);
}

KRML_MUSTINLINE
    K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t
    libcrux_ml_kem_vector_portable_serialize_deserialize_11_int(
        Eurydice_slice bytes) {
  int16_t r0 = ((int16_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)7)
                   << 8U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t,
                                             uint8_t *, uint8_t);
  int16_t r1 = ((int16_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)63)
                   << 5U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   3U;
  int16_t r2 = (((int16_t)Eurydice_slice_index(bytes, (size_t)4U, uint8_t,
                                               uint8_t *, uint8_t) &
                 (int16_t)1)
                    << 10U |
                (int16_t)Eurydice_slice_index(bytes, (size_t)3U, uint8_t,
                                              uint8_t *, uint8_t)
                    << 2U) |
               (int16_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   6U;
  int16_t r3 = ((int16_t)Eurydice_slice_index(bytes, (size_t)5U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)15)
                   << 7U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)4U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   1U;
  int16_t r4 = ((int16_t)Eurydice_slice_index(bytes, (size_t)6U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)127)
                   << 4U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)5U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   4U;
  int16_t r5 = (((int16_t)Eurydice_slice_index(bytes, (size_t)8U, uint8_t,
                                               uint8_t *, uint8_t) &
                 (int16_t)3)
                    << 9U |
                (int16_t)Eurydice_slice_index(bytes, (size_t)7U, uint8_t,
                                              uint8_t *, uint8_t)
                    << 1U) |
               (int16_t)Eurydice_slice_index(bytes, (size_t)6U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   7U;
  int16_t r6 = ((int16_t)Eurydice_slice_index(bytes, (size_t)9U, uint8_t,
                                              uint8_t *, uint8_t) &
                (int16_t)31)
                   << 6U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)8U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   2U;
  int16_t r7 = (int16_t)Eurydice_slice_index(bytes, (size_t)10U, uint8_t,
                                             uint8_t *, uint8_t)
                   << 3U |
               (int16_t)Eurydice_slice_index(bytes, (size_t)9U, uint8_t,
                                             uint8_t *, uint8_t) >>
                   5U;
  return (CLITERAL(
      K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t){
      .fst = r0,
      .snd = r1,
      .thd = r2,
      .f3 = r3,
      .f4 = r4,
      .f5 = r5,
      .f6 = r6,
      .f7 = r7});
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_serialize_deserialize_11(Eurydice_slice bytes) {
  K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t v0_7 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_11_int(
          Eurydice_slice_subslice2(bytes, (size_t)0U, (size_t)11U, uint8_t,
                                   Eurydice_slice));
  K___int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t_int16_t v8_15 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_11_int(
          Eurydice_slice_subslice2(bytes, (size_t)11U, (size_t)22U, uint8_t,
                                   Eurydice_slice));
  libcrux_ml_kem_vector_portable_vector_type_PortableVector v =
      libcrux_ml_kem_vector_portable_vector_type_zero();
  v.elements[0U] = v0_7.fst;
  v.elements[1U] = v0_7.snd;
  v.elements[2U] = v0_7.thd;
  v.elements[3U] = v0_7.f3;
  v.elements[4U] = v0_7.f4;
  v.elements[5U] = v0_7.f5;
  v.elements[6U] = v0_7.f6;
  v.elements[7U] = v0_7.f7;
  v.elements[8U] = v8_15.fst;
  v.elements[9U] = v8_15.snd;
  v.elements[10U] = v8_15.thd;
  v.elements[11U] = v8_15.f3;
  v.elements[12U] = v8_15.f4;
  v.elements[13U] = v8_15.f5;
  v.elements[14U] = v8_15.f6;
  v.elements[15U] = v8_15.f7;
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_11(
    Eurydice_slice a) {
  return libcrux_ml_kem_vector_portable_serialize_deserialize_11(a);
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO(
    void) {
  return libcrux_ml_kem_vector_portable_vector_type_zero();
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_arithmetic_add(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector lhs,
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *rhs) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    size_t uu____0 = i0;
    lhs.elements[uu____0] = lhs.elements[uu____0] + rhs->elements[i0];
  }
  return lhs;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector lhs,
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *rhs) {
  return libcrux_ml_kem_vector_portable_arithmetic_add(lhs, rhs);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_arithmetic_sub(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector lhs,
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *rhs) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    size_t uu____0 = i0;
    lhs.elements[uu____0] = lhs.elements[uu____0] - rhs->elements[i0];
  }
  return lhs;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___sub(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector lhs,
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *rhs) {
  return libcrux_ml_kem_vector_portable_arithmetic_sub(lhs, rhs);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_arithmetic_multiply_by_constant(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t c) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    size_t uu____0 = i0;
    v.elements[uu____0] = v.elements[uu____0] * c;
  }
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___multiply_by_constant(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t c) {
  return libcrux_ml_kem_vector_portable_arithmetic_multiply_by_constant(v, c);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_arithmetic_bitwise_and_with_constant(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t c) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    size_t uu____0 = i0;
    v.elements[uu____0] = v.elements[uu____0] & c;
  }
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___bitwise_and_with_constant(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t c) {
  return libcrux_ml_kem_vector_portable_arithmetic_bitwise_and_with_constant(v,
                                                                             c);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_arithmetic_cond_subtract_3329(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  core_ops_range_Range__size_t iter =
      core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
          (CLITERAL(core_ops_range_Range__size_t){
              .start = (size_t)0U,
              .end = LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR}),
          core_ops_range_Range__size_t, core_ops_range_Range__size_t);
  while (true) {
    core_option_Option__size_t uu____0 =
        core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
            &iter, size_t, core_option_Option__size_t);
    if (!(uu____0.tag == core_option_None)) {
      size_t i = uu____0.f0;
      if (v.elements[i] >= (int16_t)3329) {
        size_t uu____1 = i;
        v.elements[uu____1] = v.elements[uu____1] - (int16_t)3329;
      }
      continue;
    }
    return v;
  }
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___cond_subtract_3329(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return libcrux_ml_kem_vector_portable_arithmetic_cond_subtract_3329(v);
}

int16_t libcrux_ml_kem_vector_portable_arithmetic_barrett_reduce_element(
    int16_t value) {
  int32_t t = (int32_t)value *
                  LIBCRUX_ML_KEM_VECTOR_PORTABLE_ARITHMETIC_BARRETT_MULTIPLIER +
              (LIBCRUX_ML_KEM_VECTOR_PORTABLE_ARITHMETIC_BARRETT_R >> 1U);
  int16_t quotient =
      (int16_t)(t >>
                (uint32_t)
                    LIBCRUX_ML_KEM_VECTOR_PORTABLE_ARITHMETIC_BARRETT_SHIFT);
  return value - quotient * LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_MODULUS;
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_arithmetic_barrett_reduce(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    v.elements[i0] =
        libcrux_ml_kem_vector_portable_arithmetic_barrett_reduce_element(
            v.elements[i0]);
  }
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___barrett_reduce(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return libcrux_ml_kem_vector_portable_arithmetic_barrett_reduce(v);
}

int16_t libcrux_ml_kem_vector_portable_arithmetic_montgomery_reduce_element(
    int32_t value) {
  int32_t k =
      (int32_t)(int16_t)value *
      (int32_t)LIBCRUX_ML_KEM_VECTOR_TRAITS_INVERSE_OF_MODULUS_MOD_MONTGOMERY_R;
  int32_t k_times_modulus =
      (int32_t)(int16_t)k * (int32_t)LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_MODULUS;
  int16_t c =
      (int16_t)(k_times_modulus >>
                (uint32_t)
                    LIBCRUX_ML_KEM_VECTOR_PORTABLE_ARITHMETIC_MONTGOMERY_SHIFT);
  int16_t value_high =
      (int16_t)(value >>
                (uint32_t)
                    LIBCRUX_ML_KEM_VECTOR_PORTABLE_ARITHMETIC_MONTGOMERY_SHIFT);
  return value_high - c;
}

KRML_MUSTINLINE int16_t
libcrux_ml_kem_vector_portable_arithmetic_montgomery_multiply_fe_by_fer(
    int16_t fe, int16_t fer) {
  return libcrux_ml_kem_vector_portable_arithmetic_montgomery_reduce_element(
      (int32_t)fe * (int32_t)fer);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_arithmetic_montgomery_multiply_by_constant(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t c) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    v.elements[i0] =
        libcrux_ml_kem_vector_portable_arithmetic_montgomery_multiply_fe_by_fer(
            v.elements[i0], c);
  }
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___montgomery_multiply_by_constant(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t r) {
  return libcrux_ml_kem_vector_portable_arithmetic_montgomery_multiply_by_constant(
      v, r);
}

uint8_t libcrux_ml_kem_vector_portable_compress_compress_message_coefficient(
    uint16_t fe) {
  int16_t shifted = (int16_t)1664 - (int16_t)fe;
  int16_t mask = shifted >> 15U;
  int16_t shifted_to_positive = mask ^ shifted;
  int16_t shifted_positive_in_range = shifted_to_positive - (int16_t)832;
  return (uint8_t)(shifted_positive_in_range >> 15U & (int16_t)1);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_compress_compress_1(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    v.elements[i0] = (int16_t)
        libcrux_ml_kem_vector_portable_compress_compress_message_coefficient(
            (uint16_t)v.elements[i0]);
  }
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___compress_1(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return libcrux_ml_kem_vector_portable_compress_compress_1(v);
}

KRML_MUSTINLINE uint32_t
libcrux_ml_kem_vector_portable_arithmetic_get_n_least_significant_bits(
    uint8_t n, uint32_t value) {
  return value & ((1U << (uint32_t)n) - 1U);
}

int16_t libcrux_ml_kem_vector_portable_compress_compress_ciphertext_coefficient(
    uint8_t coefficient_bits, uint16_t fe) {
  uint64_t compressed = (uint64_t)fe << (uint32_t)coefficient_bits;
  compressed = compressed + 1664ULL;
  compressed = compressed * 10321340ULL;
  compressed = compressed >> 35U;
  return (int16_t)
      libcrux_ml_kem_vector_portable_arithmetic_get_n_least_significant_bits(
          coefficient_bits, (uint32_t)compressed);
}

KRML_MUSTINLINE void libcrux_ml_kem_vector_portable_ntt_ntt_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *v, int16_t zeta,
    size_t i, size_t j) {
  int16_t t =
      libcrux_ml_kem_vector_portable_arithmetic_montgomery_multiply_fe_by_fer(
          v->elements[j], zeta);
  v->elements[j] = v->elements[i] - t;
  v->elements[i] = v->elements[i] + t;
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_ntt_ntt_layer_1_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t zeta0,
    int16_t zeta1, int16_t zeta2, int16_t zeta3) {
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta0, (size_t)0U,
                                              (size_t)2U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta0, (size_t)1U,
                                              (size_t)3U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta1, (size_t)4U,
                                              (size_t)6U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta1, (size_t)5U,
                                              (size_t)7U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta2, (size_t)8U,
                                              (size_t)10U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta2, (size_t)9U,
                                              (size_t)11U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta3, (size_t)12U,
                                              (size_t)14U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta3, (size_t)13U,
                                              (size_t)15U);
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ntt_layer_1_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a, int16_t zeta0,
    int16_t zeta1, int16_t zeta2, int16_t zeta3) {
  return libcrux_ml_kem_vector_portable_ntt_ntt_layer_1_step(a, zeta0, zeta1,
                                                             zeta2, zeta3);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_ntt_ntt_layer_2_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t zeta0,
    int16_t zeta1) {
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta0, (size_t)0U,
                                              (size_t)4U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta0, (size_t)1U,
                                              (size_t)5U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta0, (size_t)2U,
                                              (size_t)6U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta0, (size_t)3U,
                                              (size_t)7U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta1, (size_t)8U,
                                              (size_t)12U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta1, (size_t)9U,
                                              (size_t)13U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta1, (size_t)10U,
                                              (size_t)14U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta1, (size_t)11U,
                                              (size_t)15U);
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ntt_layer_2_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a, int16_t zeta0,
    int16_t zeta1) {
  return libcrux_ml_kem_vector_portable_ntt_ntt_layer_2_step(a, zeta0, zeta1);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_ntt_ntt_layer_3_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t zeta) {
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta, (size_t)0U, (size_t)8U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta, (size_t)1U, (size_t)9U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta, (size_t)2U,
                                              (size_t)10U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta, (size_t)3U,
                                              (size_t)11U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta, (size_t)4U,
                                              (size_t)12U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta, (size_t)5U,
                                              (size_t)13U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta, (size_t)6U,
                                              (size_t)14U);
  libcrux_ml_kem_vector_portable_ntt_ntt_step(&v, zeta, (size_t)7U,
                                              (size_t)15U);
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ntt_layer_3_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a, int16_t zeta) {
  return libcrux_ml_kem_vector_portable_ntt_ntt_layer_3_step(a, zeta);
}

KRML_MUSTINLINE void libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *v, int16_t zeta,
    size_t i, size_t j) {
  int16_t a_minus_b = v->elements[j] - v->elements[i];
  v->elements[i] =
      libcrux_ml_kem_vector_portable_arithmetic_barrett_reduce_element(
          v->elements[i] + v->elements[j]);
  v->elements[j] =
      libcrux_ml_kem_vector_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b, zeta);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_ntt_inv_ntt_layer_1_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t zeta0,
    int16_t zeta1, int16_t zeta2, int16_t zeta3) {
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta0, (size_t)0U,
                                                  (size_t)2U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta0, (size_t)1U,
                                                  (size_t)3U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta1, (size_t)4U,
                                                  (size_t)6U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta1, (size_t)5U,
                                                  (size_t)7U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta2, (size_t)8U,
                                                  (size_t)10U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta2, (size_t)9U,
                                                  (size_t)11U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta3, (size_t)12U,
                                                  (size_t)14U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta3, (size_t)13U,
                                                  (size_t)15U);
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___inv_ntt_layer_1_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a, int16_t zeta0,
    int16_t zeta1, int16_t zeta2, int16_t zeta3) {
  return libcrux_ml_kem_vector_portable_ntt_inv_ntt_layer_1_step(
      a, zeta0, zeta1, zeta2, zeta3);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_ntt_inv_ntt_layer_2_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t zeta0,
    int16_t zeta1) {
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta0, (size_t)0U,
                                                  (size_t)4U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta0, (size_t)1U,
                                                  (size_t)5U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta0, (size_t)2U,
                                                  (size_t)6U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta0, (size_t)3U,
                                                  (size_t)7U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta1, (size_t)8U,
                                                  (size_t)12U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta1, (size_t)9U,
                                                  (size_t)13U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta1, (size_t)10U,
                                                  (size_t)14U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta1, (size_t)11U,
                                                  (size_t)15U);
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___inv_ntt_layer_2_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a, int16_t zeta0,
    int16_t zeta1) {
  return libcrux_ml_kem_vector_portable_ntt_inv_ntt_layer_2_step(a, zeta0,
                                                                 zeta1);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_ntt_inv_ntt_layer_3_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t zeta) {
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta, (size_t)0U,
                                                  (size_t)8U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta, (size_t)1U,
                                                  (size_t)9U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta, (size_t)2U,
                                                  (size_t)10U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta, (size_t)3U,
                                                  (size_t)11U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta, (size_t)4U,
                                                  (size_t)12U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta, (size_t)5U,
                                                  (size_t)13U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta, (size_t)6U,
                                                  (size_t)14U);
  libcrux_ml_kem_vector_portable_ntt_inv_ntt_step(&v, zeta, (size_t)7U,
                                                  (size_t)15U);
  return v;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___inv_ntt_layer_3_step(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a, int16_t zeta) {
  return libcrux_ml_kem_vector_portable_ntt_inv_ntt_layer_3_step(a, zeta);
}

KRML_MUSTINLINE void libcrux_ml_kem_vector_portable_ntt_ntt_multiply_binomials(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *a,
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *b, int16_t zeta,
    size_t i, size_t j,
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *out) {
  int16_t o0 = libcrux_ml_kem_vector_portable_arithmetic_montgomery_reduce_element(
      (int32_t)a->elements[i] * (int32_t)b->elements[i] +
      (int32_t)
              libcrux_ml_kem_vector_portable_arithmetic_montgomery_reduce_element(
                  (int32_t)a->elements[j] * (int32_t)b->elements[j]) *
          (int32_t)zeta);
  int16_t o1 =
      libcrux_ml_kem_vector_portable_arithmetic_montgomery_reduce_element(
          (int32_t)a->elements[i] * (int32_t)b->elements[j] +
          (int32_t)a->elements[j] * (int32_t)b->elements[i]);
  out->elements[i] = o0;
  out->elements[j] = o1;
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_ntt_ntt_multiply(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *lhs,
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *rhs,
    int16_t zeta0, int16_t zeta1, int16_t zeta2, int16_t zeta3) {
  libcrux_ml_kem_vector_portable_vector_type_PortableVector out =
      libcrux_ml_kem_vector_portable_vector_type_zero();
  libcrux_ml_kem_vector_portable_ntt_ntt_multiply_binomials(
      lhs, rhs, zeta0, (size_t)0U, (size_t)1U, &out);
  libcrux_ml_kem_vector_portable_ntt_ntt_multiply_binomials(
      lhs, rhs, -zeta0, (size_t)2U, (size_t)3U, &out);
  libcrux_ml_kem_vector_portable_ntt_ntt_multiply_binomials(
      lhs, rhs, zeta1, (size_t)4U, (size_t)5U, &out);
  libcrux_ml_kem_vector_portable_ntt_ntt_multiply_binomials(
      lhs, rhs, -zeta1, (size_t)6U, (size_t)7U, &out);
  libcrux_ml_kem_vector_portable_ntt_ntt_multiply_binomials(
      lhs, rhs, zeta2, (size_t)8U, (size_t)9U, &out);
  libcrux_ml_kem_vector_portable_ntt_ntt_multiply_binomials(
      lhs, rhs, -zeta2, (size_t)10U, (size_t)11U, &out);
  libcrux_ml_kem_vector_portable_ntt_ntt_multiply_binomials(
      lhs, rhs, zeta3, (size_t)12U, (size_t)13U, &out);
  libcrux_ml_kem_vector_portable_ntt_ntt_multiply_binomials(
      lhs, rhs, -zeta3, (size_t)14U, (size_t)15U, &out);
  return out;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ntt_multiply(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *lhs,
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *rhs,
    int16_t zeta0, int16_t zeta1, int16_t zeta2, int16_t zeta3) {
  return libcrux_ml_kem_vector_portable_ntt_ntt_multiply(lhs, rhs, zeta0, zeta1,
                                                         zeta2, zeta3);
}

KRML_MUSTINLINE void libcrux_ml_kem_vector_portable_serialize_serialize_1(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v,
    uint8_t ret[2U]) {
  uint8_t result[2U] = {0U};
  KRML_MAYBE_FOR8(
      i, (size_t)0U, (size_t)8U, (size_t)1U, size_t i0 = i;
      size_t uu____0 = (size_t)0U;
      result[uu____0] = (uint32_t)result[uu____0] |
                        (uint32_t)(uint8_t)v.elements[i0] << (uint32_t)i0;);
  KRML_MAYBE_FOR8(i, (size_t)8U, (size_t)16U, (size_t)1U, size_t i0 = i;
                  size_t uu____1 = (size_t)1U;
                  result[uu____1] = (uint32_t)result[uu____1] |
                                    (uint32_t)(uint8_t)v.elements[i0]
                                        << (uint32_t)(i0 - (size_t)8U););
  memcpy(ret, result, (size_t)2U * sizeof(uint8_t));
}

void libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_1(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a,
    uint8_t ret[2U]) {
  libcrux_ml_kem_vector_portable_serialize_serialize_1(a, ret);
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_serialize_deserialize_1(Eurydice_slice v) {
  libcrux_ml_kem_vector_portable_vector_type_PortableVector result =
      libcrux_ml_kem_vector_portable_vector_type_zero();
  KRML_MAYBE_FOR8(
      i, (size_t)0U, (size_t)8U, (size_t)1U, size_t i0 = i;
      result.elements[i0] =
          (int16_t)((uint32_t)Eurydice_slice_index(v, (size_t)0U, uint8_t,
                                                   uint8_t *, uint8_t) >>
                        (uint32_t)i0 &
                    1U););
  for (size_t i = (size_t)8U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    result.elements[i0] =
        (int16_t)((uint32_t)Eurydice_slice_index(v, (size_t)1U, uint8_t,
                                                 uint8_t *, uint8_t) >>
                      (uint32_t)(i0 - (size_t)8U) &
                  1U);
  }
  return result;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_1(
    Eurydice_slice a) {
  return libcrux_ml_kem_vector_portable_serialize_deserialize_1(a);
}

KRML_MUSTINLINE K___uint8_t_uint8_t_uint8_t_uint8_t
libcrux_ml_kem_vector_portable_serialize_serialize_4_int(Eurydice_slice v) {
  uint8_t result0 = (uint32_t)(uint8_t)Eurydice_slice_index(
                        v, (size_t)1U, int16_t, int16_t *, int16_t)
                        << 4U |
                    (uint32_t)(uint8_t)Eurydice_slice_index(
                        v, (size_t)0U, int16_t, int16_t *, int16_t);
  uint8_t result1 = (uint32_t)(uint8_t)Eurydice_slice_index(
                        v, (size_t)3U, int16_t, int16_t *, int16_t)
                        << 4U |
                    (uint32_t)(uint8_t)Eurydice_slice_index(
                        v, (size_t)2U, int16_t, int16_t *, int16_t);
  uint8_t result2 = (uint32_t)(uint8_t)Eurydice_slice_index(
                        v, (size_t)5U, int16_t, int16_t *, int16_t)
                        << 4U |
                    (uint32_t)(uint8_t)Eurydice_slice_index(
                        v, (size_t)4U, int16_t, int16_t *, int16_t);
  uint8_t result3 = (uint32_t)(uint8_t)Eurydice_slice_index(
                        v, (size_t)7U, int16_t, int16_t *, int16_t)
                        << 4U |
                    (uint32_t)(uint8_t)Eurydice_slice_index(
                        v, (size_t)6U, int16_t, int16_t *, int16_t);
  return (CLITERAL(K___uint8_t_uint8_t_uint8_t_uint8_t){
      .fst = result0, .snd = result1, .thd = result2, .f3 = result3});
}

KRML_MUSTINLINE void libcrux_ml_kem_vector_portable_serialize_serialize_4(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v,
    uint8_t ret[8U]) {
  K___uint8_t_uint8_t_uint8_t_uint8_t result0_3 =
      libcrux_ml_kem_vector_portable_serialize_serialize_4_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)0U, (size_t)8U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t_uint8_t result4_7 =
      libcrux_ml_kem_vector_portable_serialize_serialize_4_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)8U, (size_t)16U,
                                      int16_t, Eurydice_slice));
  uint8_t result[8U] = {0U};
  result[0U] = result0_3.fst;
  result[1U] = result0_3.snd;
  result[2U] = result0_3.thd;
  result[3U] = result0_3.f3;
  result[4U] = result4_7.fst;
  result[5U] = result4_7.snd;
  result[6U] = result4_7.thd;
  result[7U] = result4_7.f3;
  memcpy(ret, result, (size_t)8U * sizeof(uint8_t));
}

void libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_4(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a,
    uint8_t ret[8U]) {
  libcrux_ml_kem_vector_portable_serialize_serialize_4(a, ret);
}

KRML_MUSTINLINE K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t
libcrux_ml_kem_vector_portable_serialize_serialize_10_int(Eurydice_slice v) {
  uint8_t r0 = (uint8_t)(Eurydice_slice_index(v, (size_t)0U, int16_t, int16_t *,
                                              int16_t) &
                         (int16_t)255);
  uint8_t r1 = (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)1U, int16_t,
                                                        int16_t *, int16_t) &
                                   (int16_t)63)
                   << 2U |
               (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)0U, int16_t,
                                                        int16_t *, int16_t) >>
                                       8U &
                                   (int16_t)3);
  uint8_t r2 = (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)2U, int16_t,
                                                        int16_t *, int16_t) &
                                   (int16_t)15)
                   << 4U |
               (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)1U, int16_t,
                                                        int16_t *, int16_t) >>
                                       6U &
                                   (int16_t)15);
  uint8_t r3 = (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)3U, int16_t,
                                                        int16_t *, int16_t) &
                                   (int16_t)3)
                   << 6U |
               (uint32_t)(uint8_t)(Eurydice_slice_index(v, (size_t)2U, int16_t,
                                                        int16_t *, int16_t) >>
                                       4U &
                                   (int16_t)63);
  uint8_t r4 = (uint8_t)(Eurydice_slice_index(v, (size_t)3U, int16_t, int16_t *,
                                              int16_t) >>
                             2U &
                         (int16_t)255);
  return (CLITERAL(K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t){
      .fst = r0, .snd = r1, .thd = r2, .f3 = r3, .f4 = r4});
}

KRML_MUSTINLINE void libcrux_ml_kem_vector_portable_serialize_serialize_10(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v,
    uint8_t ret[20U]) {
  K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t r0_4 =
      libcrux_ml_kem_vector_portable_serialize_serialize_10_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)0U, (size_t)4U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t r5_9 =
      libcrux_ml_kem_vector_portable_serialize_serialize_10_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)4U, (size_t)8U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t r10_14 =
      libcrux_ml_kem_vector_portable_serialize_serialize_10_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)8U, (size_t)12U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t_uint8_t_uint8_t r15_19 =
      libcrux_ml_kem_vector_portable_serialize_serialize_10_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)12U, (size_t)16U,
                                      int16_t, Eurydice_slice));
  uint8_t result[20U] = {0U};
  result[0U] = r0_4.fst;
  result[1U] = r0_4.snd;
  result[2U] = r0_4.thd;
  result[3U] = r0_4.f3;
  result[4U] = r0_4.f4;
  result[5U] = r5_9.fst;
  result[6U] = r5_9.snd;
  result[7U] = r5_9.thd;
  result[8U] = r5_9.f3;
  result[9U] = r5_9.f4;
  result[10U] = r10_14.fst;
  result[11U] = r10_14.snd;
  result[12U] = r10_14.thd;
  result[13U] = r10_14.f3;
  result[14U] = r10_14.f4;
  result[15U] = r15_19.fst;
  result[16U] = r15_19.snd;
  result[17U] = r15_19.thd;
  result[18U] = r15_19.f3;
  result[19U] = r15_19.f4;
  memcpy(ret, result, (size_t)20U * sizeof(uint8_t));
}

void libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_10(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a,
    uint8_t ret[20U]) {
  libcrux_ml_kem_vector_portable_serialize_serialize_10(a, ret);
}

KRML_MUSTINLINE K___uint8_t_uint8_t_uint8_t
libcrux_ml_kem_vector_portable_serialize_serialize_12_int(Eurydice_slice v) {
  uint8_t r0 = (uint8_t)(Eurydice_slice_index(v, (size_t)0U, int16_t, int16_t *,
                                              int16_t) &
                         (int16_t)255);
  uint8_t r1 = (uint8_t)(Eurydice_slice_index(v, (size_t)0U, int16_t, int16_t *,
                                              int16_t) >>
                             8U |
                         (Eurydice_slice_index(v, (size_t)1U, int16_t,
                                               int16_t *, int16_t) &
                          (int16_t)15)
                             << 4U);
  uint8_t r2 = (uint8_t)(Eurydice_slice_index(v, (size_t)1U, int16_t, int16_t *,
                                              int16_t) >>
                             4U &
                         (int16_t)255);
  return (
      CLITERAL(K___uint8_t_uint8_t_uint8_t){.fst = r0, .snd = r1, .thd = r2});
}

KRML_MUSTINLINE void libcrux_ml_kem_vector_portable_serialize_serialize_12(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v,
    uint8_t ret[24U]) {
  K___uint8_t_uint8_t_uint8_t r0_2 =
      libcrux_ml_kem_vector_portable_serialize_serialize_12_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)0U, (size_t)2U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t r3_5 =
      libcrux_ml_kem_vector_portable_serialize_serialize_12_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)2U, (size_t)4U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t r6_8 =
      libcrux_ml_kem_vector_portable_serialize_serialize_12_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)4U, (size_t)6U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t r9_11 =
      libcrux_ml_kem_vector_portable_serialize_serialize_12_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)6U, (size_t)8U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t r12_14 =
      libcrux_ml_kem_vector_portable_serialize_serialize_12_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)8U, (size_t)10U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t r15_17 =
      libcrux_ml_kem_vector_portable_serialize_serialize_12_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)10U, (size_t)12U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t r18_20 =
      libcrux_ml_kem_vector_portable_serialize_serialize_12_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)12U, (size_t)14U,
                                      int16_t, Eurydice_slice));
  K___uint8_t_uint8_t_uint8_t r21_23 =
      libcrux_ml_kem_vector_portable_serialize_serialize_12_int(
          Eurydice_array_to_subslice2(v.elements, (size_t)14U, (size_t)16U,
                                      int16_t, Eurydice_slice));
  uint8_t result[24U] = {0U};
  result[0U] = r0_2.fst;
  result[1U] = r0_2.snd;
  result[2U] = r0_2.thd;
  result[3U] = r3_5.fst;
  result[4U] = r3_5.snd;
  result[5U] = r3_5.thd;
  result[6U] = r6_8.fst;
  result[7U] = r6_8.snd;
  result[8U] = r6_8.thd;
  result[9U] = r9_11.fst;
  result[10U] = r9_11.snd;
  result[11U] = r9_11.thd;
  result[12U] = r12_14.fst;
  result[13U] = r12_14.snd;
  result[14U] = r12_14.thd;
  result[15U] = r15_17.fst;
  result[16U] = r15_17.snd;
  result[17U] = r15_17.thd;
  result[18U] = r18_20.fst;
  result[19U] = r18_20.snd;
  result[20U] = r18_20.thd;
  result[21U] = r21_23.fst;
  result[22U] = r21_23.snd;
  result[23U] = r21_23.thd;
  memcpy(ret, result, (size_t)24U * sizeof(uint8_t));
}

void libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_12(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a,
    uint8_t ret[24U]) {
  libcrux_ml_kem_vector_portable_serialize_serialize_12(a, ret);
}

KRML_MUSTINLINE K___int16_t_int16_t
libcrux_ml_kem_vector_portable_serialize_deserialize_12_int(
    Eurydice_slice bytes) {
  int16_t byte0 = (int16_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t,
                                                uint8_t *, uint8_t);
  int16_t byte1 = (int16_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t,
                                                uint8_t *, uint8_t);
  int16_t byte2 = (int16_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t,
                                                uint8_t *, uint8_t);
  int16_t r0 = (byte1 & (int16_t)15) << 8U | (byte0 & (int16_t)255);
  int16_t r1 = byte2 << 4U | (byte1 >> 4U & (int16_t)15);
  return (CLITERAL(K___int16_t_int16_t){.fst = r0, .snd = r1});
}

KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_serialize_deserialize_12(Eurydice_slice bytes) {
  K___int16_t_int16_t v0_1 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_12_int(
          Eurydice_slice_subslice2(bytes, (size_t)0U, (size_t)3U, uint8_t,
                                   Eurydice_slice));
  K___int16_t_int16_t v2_3 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_12_int(
          Eurydice_slice_subslice2(bytes, (size_t)3U, (size_t)6U, uint8_t,
                                   Eurydice_slice));
  K___int16_t_int16_t v4_5 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_12_int(
          Eurydice_slice_subslice2(bytes, (size_t)6U, (size_t)9U, uint8_t,
                                   Eurydice_slice));
  K___int16_t_int16_t v6_7 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_12_int(
          Eurydice_slice_subslice2(bytes, (size_t)9U, (size_t)12U, uint8_t,
                                   Eurydice_slice));
  K___int16_t_int16_t v8_9 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_12_int(
          Eurydice_slice_subslice2(bytes, (size_t)12U, (size_t)15U, uint8_t,
                                   Eurydice_slice));
  K___int16_t_int16_t v10_11 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_12_int(
          Eurydice_slice_subslice2(bytes, (size_t)15U, (size_t)18U, uint8_t,
                                   Eurydice_slice));
  K___int16_t_int16_t v12_13 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_12_int(
          Eurydice_slice_subslice2(bytes, (size_t)18U, (size_t)21U, uint8_t,
                                   Eurydice_slice));
  K___int16_t_int16_t v14_15 =
      libcrux_ml_kem_vector_portable_serialize_deserialize_12_int(
          Eurydice_slice_subslice2(bytes, (size_t)21U, (size_t)24U, uint8_t,
                                   Eurydice_slice));
  libcrux_ml_kem_vector_portable_vector_type_PortableVector re =
      libcrux_ml_kem_vector_portable_vector_type_zero();
  re.elements[0U] = v0_1.fst;
  re.elements[1U] = v0_1.snd;
  re.elements[2U] = v2_3.fst;
  re.elements[3U] = v2_3.snd;
  re.elements[4U] = v4_5.fst;
  re.elements[5U] = v4_5.snd;
  re.elements[6U] = v6_7.fst;
  re.elements[7U] = v6_7.snd;
  re.elements[8U] = v8_9.fst;
  re.elements[9U] = v8_9.snd;
  re.elements[10U] = v10_11.fst;
  re.elements[11U] = v10_11.snd;
  re.elements[12U] = v12_13.fst;
  re.elements[13U] = v12_13.snd;
  re.elements[14U] = v14_15.fst;
  re.elements[15U] = v14_15.snd;
  return re;
}

libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_12(
    Eurydice_slice a) {
  return libcrux_ml_kem_vector_portable_serialize_deserialize_12(a);
}

KRML_MUSTINLINE size_t libcrux_ml_kem_vector_portable_sampling_rej_sample(
    Eurydice_slice a, Eurydice_slice result) {
  size_t sampled = (size_t)0U;
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(a, uint8_t, size_t) / (size_t)3U; i++) {
    size_t i0 = i;
    int16_t b1 = (int16_t)Eurydice_slice_index(a, i0 * (size_t)3U + (size_t)0U,
                                               uint8_t, uint8_t *, uint8_t);
    int16_t b2 = (int16_t)Eurydice_slice_index(a, i0 * (size_t)3U + (size_t)1U,
                                               uint8_t, uint8_t *, uint8_t);
    int16_t b3 = (int16_t)Eurydice_slice_index(a, i0 * (size_t)3U + (size_t)2U,
                                               uint8_t, uint8_t *, uint8_t);
    int16_t d1 = (b2 & (int16_t)15) << 8U | b1;
    int16_t d2 = b3 << 4U | b2 >> 4U;
    bool uu____0;
    int16_t uu____1;
    bool uu____2;
    size_t uu____3;
    int16_t uu____4;
    size_t uu____5;
    int16_t uu____6;
    if (d1 < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_MODULUS) {
      if (sampled < (size_t)16U) {
        Eurydice_slice_index(result, sampled, int16_t, int16_t *, int16_t) = d1;
        sampled++;
        uu____1 = d2;
        uu____6 = LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_MODULUS;
        uu____0 = uu____1 < uu____6;
        if (uu____0) {
          uu____3 = sampled;
          uu____2 = uu____3 < (size_t)16U;
          if (uu____2) {
            uu____4 = d2;
            uu____5 = sampled;
            Eurydice_slice_index(result, uu____5, int16_t, int16_t *, int16_t) =
                uu____4;
            sampled++;
            continue;
          }
        }
        continue;
      }
    }
    uu____1 = d2;
    uu____6 = LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_MODULUS;
    uu____0 = uu____1 < uu____6;
    if (uu____0) {
      uu____3 = sampled;
      uu____2 = uu____3 < (size_t)16U;
      if (uu____2) {
        uu____4 = d2;
        uu____5 = sampled;
        Eurydice_slice_index(result, uu____5, int16_t, int16_t *, int16_t) =
            uu____4;
        sampled++;
        continue;
      }
    }
  }
  return sampled;
}

size_t
libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___rej_sample(
    Eurydice_slice a, Eurydice_slice out) {
  return libcrux_ml_kem_vector_portable_sampling_rej_sample(a, out);
}

inline libcrux_ml_kem_vector_portable_vector_type_PortableVector
libcrux_ml_kem_vector_portable_vector_type___core__clone__Clone_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___clone(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector *self) {
  return self[0U];
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@0]}.ZERO
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
ZERO_24(void) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      lit;
  lit.coefficients[0U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[1U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[2U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[3U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[4U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[5U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[6U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[7U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[8U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[9U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[10U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[11U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[12U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[13U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[14U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  lit.coefficients[15U] =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_to_reduced_ring_element with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    deserialize_to_reduced_ring_element_24(Eurydice_slice serialized) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      re = ZERO_24();
  for (size_t i = (size_t)0U;
       i <
       core_slice___Slice_T___len(serialized, uint8_t, size_t) / (size_t)24U;
       i++) {
    size_t i0 = i;
    Eurydice_slice bytes = Eurydice_slice_subslice2(
        serialized, i0 * (size_t)24U, i0 * (size_t)24U + (size_t)24U, uint8_t,
        Eurydice_slice);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector coefficient =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_12(
            bytes);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___cond_subtract_3329(
            coefficient);
    re.coefficients[i0] = uu____0;
  }
  return re;
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_ring_elements_reduced with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- PUBLIC_KEY_SIZE = 1568
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_ring_elements_reduced_c5(
    Eurydice_slice public_key,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[4U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      deserialized_pk[4U];
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U,
                  deserialized_pk[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(public_key, uint8_t, size_t) /
               LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT;
       i++) {
    size_t i0 = i;
    Eurydice_slice ring_element = Eurydice_slice_subslice2(
        public_key, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT +
            LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_to_reduced_ring_element_24(ring_element);
    deserialized_pk[i0] = uu____0;
  }
  memcpy(
      ret, deserialized_pk,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.vector.portable.arithmetic.shift_right
with const generics:
- SHIFT_BY = 15
*/
static KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
shift_right_d2(libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    v.elements[i0] = v.elements[i0] >> (uint32_t)(int32_t)15;
  }
  return v;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.{(libcrux_ml_kem::vector::traits::Operations␣for␣libcrux_ml_kem::vector::portable::vector_type::PortableVector)}.shift_right
with const generics:
- SHIFT_BY = 15
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector
shift_right_d20(libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return shift_right_d2(v);
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.traits.to_unsigned_representative with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector
to_unsigned_representative_24(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector a) {
  libcrux_ml_kem_vector_portable_vector_type_PortableVector t =
      shift_right_d20(a);
  libcrux_ml_kem_vector_portable_vector_type_PortableVector fm =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___bitwise_and_with_constant(
          t, LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_MODULUS);
  return libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
      a, &fm);
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.serialize_uncompressed_ring_element with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void serialize_uncompressed_ring_element_24(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re,
    uint8_t ret[384U]) {
  uint8_t serialized[384U] = {0U};
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector coefficient =
        to_unsigned_representative_24(re->coefficients[i0]);
    uint8_t bytes[24U];
    libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_12(
        coefficient, bytes);
    Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
        serialized, (size_t)24U * i0, (size_t)24U * i0 + (size_t)24U, uint8_t,
        Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)24U, bytes, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
  memcpy(ret, serialized, (size_t)384U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.serialize_secret_key with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
- OUT_LEN = 1536
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void serialize_secret_key_4b(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *key,
    uint8_t ret[1536U]) {
  uint8_t out[1536U] = {0U};
  for (
      size_t i = (size_t)0U;
      i <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)4U, key,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
          size_t);
      i++) {
    size_t i0 = i;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        re = key[i0];
    Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
        out, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        (i0 + (size_t)1U) * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    uint8_t ret0[384U];
    serialize_uncompressed_ring_element_24(&re, ret0);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)384U, ret0, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
  memcpy(ret, out, (size_t)1536U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.serialize_public_key with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
- RANKED_BYTES_PER_RING_ELEMENT = 1536
- PUBLIC_KEY_SIZE = 1568
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void serialize_public_key_38(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *t_as_ntt,
    Eurydice_slice seed_for_a, uint8_t ret[1568U]) {
  uint8_t public_key_serialized[1568U] = {0U};
  Eurydice_slice uu____0 =
      Eurydice_array_to_subslice2(public_key_serialized, (size_t)0U,
                                  (size_t)1536U, uint8_t, Eurydice_slice);
  uint8_t ret0[1536U];
  serialize_secret_key_4b(t_as_ntt, ret0);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)1536U, ret0, uint8_t, Eurydice_slice),
      uint8_t, void *);
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice_from((size_t)1568U, public_key_serialized,
                                      (size_t)1536U, uint8_t, size_t,
                                      Eurydice_slice),
      seed_for_a, uint8_t, void *);
  memcpy(ret, public_key_serialized, (size_t)1568U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.validate_public_key with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
- RANKED_BYTES_PER_RING_ELEMENT = 1536
- PUBLIC_KEY_SIZE = 1568
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
bool libcrux_ml_kem_ind_cca_validate_public_key_38(uint8_t *public_key) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      deserialized_pk[4U];
  deserialize_ring_elements_reduced_c5(
      Eurydice_array_to_subslice_to((size_t)1568U, public_key, (size_t)1536U,
                                    uint8_t, size_t, Eurydice_slice),
      deserialized_pk);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      *uu____0 = deserialized_pk;
  uint8_t public_key_serialized[1568U];
  serialize_public_key_38(
      uu____0,
      Eurydice_array_to_subslice_from((size_t)1568U, public_key, (size_t)1536U,
                                      uint8_t, size_t, Eurydice_slice),
      public_key_serialized);
  return core_array_equality___core__cmp__PartialEq__Array_U__N___for__Array_T__N____eq(
      (size_t)1568U, public_key, public_key_serialized, uint8_t, uint8_t, bool);
}

typedef struct
    __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t___s {
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      fst;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      snd;
} __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t__;

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.G
with const generics:
- K = 4
*/
static KRML_MUSTINLINE void G_c3(Eurydice_slice input, uint8_t ret[64U]) {
  libcrux_ml_kem_hash_functions_portable_G(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.sample_matrix_A.closure with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void closure_9f0(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[4U]) {
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U, ret[i] = ZERO_24(););
}

typedef struct PortableHash____4size_t_s {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t shake128_state[4U];
} PortableHash____4size_t;

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.shake128_init_absorb with const generics:
- K = 4
*/
static KRML_MUSTINLINE PortableHash____4size_t
shake128_init_absorb_c3(uint8_t input[4U][34U]) {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t shake128_state[4U];
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U,
      shake128_state[i] = libcrux_sha3_portable_incremental_shake128_init(););
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
                  libcrux_sha3_portable_incremental_shake128_absorb_final(
                      &shake128_state[i0],
                      Eurydice_array_to_slice((size_t)34U, input[i0], uint8_t,
                                              Eurydice_slice)););
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t uu____0[4U];
  memcpy(
      uu____0, shake128_state,
      (size_t)4U *
          sizeof(libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t));
  PortableHash____4size_t lit;
  memcpy(
      lit.shake128_state, uu____0,
      (size_t)4U *
          sizeof(libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t));
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.shake128_init_absorb
with const generics:
- K = 4
*/
static KRML_MUSTINLINE PortableHash____4size_t
shake128_init_absorb_c30(uint8_t input[4U][34U]) {
  uint8_t uu____0[4U][34U];
  memcpy(uu____0, input, (size_t)4U * sizeof(uint8_t[34U]));
  return shake128_init_absorb_c3(uu____0);
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.shake128_squeeze_three_blocks with const
generics:
- K = 4
*/
static KRML_MUSTINLINE void shake128_squeeze_three_blocks_c3(
    PortableHash____4size_t *st, uint8_t ret[4U][504U]) {
  uint8_t out[4U][504U] = {{0U}};
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
      libcrux_sha3_portable_incremental_shake128_squeeze_first_three_blocks(
          &st->shake128_state[i0],
          Eurydice_array_to_slice((size_t)504U, out[i0], uint8_t,
                                  Eurydice_slice)););
  memcpy(ret, out, (size_t)4U * sizeof(uint8_t[504U]));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.shake128_squeeze_three_blocks
with const generics:
- K = 4
*/
static KRML_MUSTINLINE void shake128_squeeze_three_blocks_c30(
    PortableHash____4size_t *self, uint8_t ret[4U][504U]) {
  shake128_squeeze_three_blocks_c3(self, ret);
}

/**
A monomorphic instance of
libcrux_ml_kem.sampling.sample_from_uniform_distribution_next with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
- N = 504
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE bool sample_from_uniform_distribution_next_e2(
    uint8_t randomness[4U][504U], size_t *sampled_coefficients,
    int16_t (*out)[272U]) {
  KRML_MAYBE_FOR4(
      i0, (size_t)0U, (size_t)4U, (size_t)1U, size_t i1 = i0;
      for (size_t i = (size_t)0U; i < (size_t)504U / (size_t)24U; i++) {
        size_t r = i;
        if (sampled_coefficients[i1] <
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
          Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
              randomness[i1], r * (size_t)24U, r * (size_t)24U + (size_t)24U,
              uint8_t, Eurydice_slice);
          size_t sampled =
              libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___rej_sample(
                  uu____0, Eurydice_array_to_subslice2(
                               out[i1], sampled_coefficients[i1],
                               sampled_coefficients[i1] + (size_t)16U, int16_t,
                               Eurydice_slice));
          size_t uu____1 = i1;
          sampled_coefficients[uu____1] =
              sampled_coefficients[uu____1] + sampled;
        }
      });
  bool done = true;
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
      if (sampled_coefficients[i0] >=
          LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
        sampled_coefficients[i0] =
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT;
      } else { done = false; });
  return done;
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.shake128_squeeze_block with const
generics:
- K = 4
*/
static KRML_MUSTINLINE void shake128_squeeze_block_c3(
    PortableHash____4size_t *st, uint8_t ret[4U][168U]) {
  uint8_t out[4U][168U] = {{0U}};
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
                  libcrux_sha3_portable_incremental_shake128_squeeze_next_block(
                      &st->shake128_state[i0],
                      Eurydice_array_to_slice((size_t)168U, out[i0], uint8_t,
                                              Eurydice_slice)););
  memcpy(ret, out, (size_t)4U * sizeof(uint8_t[168U]));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.shake128_squeeze_block
with const generics:
- K = 4
*/
static KRML_MUSTINLINE void shake128_squeeze_block_c30(
    PortableHash____4size_t *self, uint8_t ret[4U][168U]) {
  shake128_squeeze_block_c3(self, ret);
}

/**
A monomorphic instance of
libcrux_ml_kem.sampling.sample_from_uniform_distribution_next with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
- N = 168
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE bool sample_from_uniform_distribution_next_16(
    uint8_t randomness[4U][168U], size_t *sampled_coefficients,
    int16_t (*out)[272U]) {
  KRML_MAYBE_FOR4(
      i0, (size_t)0U, (size_t)4U, (size_t)1U, size_t i1 = i0;
      for (size_t i = (size_t)0U; i < (size_t)168U / (size_t)24U; i++) {
        size_t r = i;
        if (sampled_coefficients[i1] <
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
          Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
              randomness[i1], r * (size_t)24U, r * (size_t)24U + (size_t)24U,
              uint8_t, Eurydice_slice);
          size_t sampled =
              libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___rej_sample(
                  uu____0, Eurydice_array_to_subslice2(
                               out[i1], sampled_coefficients[i1],
                               sampled_coefficients[i1] + (size_t)16U, int16_t,
                               Eurydice_slice));
          size_t uu____1 = i1;
          sampled_coefficients[uu____1] =
              sampled_coefficients[uu____1] + sampled;
        }
      });
  bool done = true;
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
      if (sampled_coefficients[i0] >=
          LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
        sampled_coefficients[i0] =
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT;
      } else { done = false; });
  return done;
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@0]}.from_i16_array
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    from_i16_array_24(Eurydice_slice a) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result = ZERO_24();
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___from_i16_array(
            Eurydice_slice_subslice2(a, i0 * (size_t)16U,
                                     (i0 + (size_t)1U) * (size_t)16U, int16_t,
                                     Eurydice_slice));
    result.coefficients[i0] = uu____0;
  }
  return result;
}

/**
A monomorphic instance of libcrux_ml_kem.sampling.sample_from_xof.closure with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
closure_9f00(int16_t s[272U]) {
  return from_i16_array_24(Eurydice_array_to_subslice2(
      s, (size_t)0U, (size_t)256U, int16_t, Eurydice_slice));
}

/**
A monomorphic instance of libcrux_ml_kem.sampling.sample_from_xof with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void sample_from_xof_9f0(
    uint8_t seeds[4U][34U],
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[4U]) {
  size_t sampled_coefficients[4U] = {0U};
  int16_t out[4U][272U] = {{0U}};
  uint8_t uu____0[4U][34U];
  memcpy(uu____0, seeds, (size_t)4U * sizeof(uint8_t[34U]));
  PortableHash____4size_t xof_state = shake128_init_absorb_c30(uu____0);
  uint8_t randomness0[4U][504U];
  shake128_squeeze_three_blocks_c30(&xof_state, randomness0);
  uint8_t uu____1[4U][504U];
  memcpy(uu____1, randomness0, (size_t)4U * sizeof(uint8_t[504U]));
  bool done = sample_from_uniform_distribution_next_e2(
      uu____1, sampled_coefficients, out);
  while (true) {
    if (done) {
      break;
    } else {
      uint8_t randomness[4U][168U];
      shake128_squeeze_block_c30(&xof_state, randomness);
      uint8_t uu____2[4U][168U];
      memcpy(uu____2, randomness, (size_t)4U * sizeof(uint8_t[168U]));
      done = sample_from_uniform_distribution_next_16(
          uu____2, sampled_coefficients, out);
    }
  }
  int16_t uu____3[4U][272U];
  memcpy(uu____3, out, (size_t)4U * sizeof(int16_t[272U]));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      ret0[4U];
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U,
                  ret0[i] = closure_9f00(uu____3[i]););
  memcpy(
      ret, ret0,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.sample_matrix_A with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void sample_matrix_A_9f0(
    uint8_t seed[34U], bool transpose,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[4U][4U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A_transpose[4U][4U];
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U,
                  closure_9f0(A_transpose[i]););
  KRML_MAYBE_FOR4(
      i0, (size_t)0U, (size_t)4U, (size_t)1U, size_t i1 = i0;
      uint8_t uu____0[34U];
      memcpy(uu____0, seed, (size_t)34U * sizeof(uint8_t));
      uint8_t seeds[4U][34U]; KRML_MAYBE_FOR4(
          i, (size_t)0U, (size_t)4U, (size_t)1U,
          memcpy(seeds[i], uu____0, (size_t)34U * sizeof(uint8_t)););
      KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U, size_t j = i;
                      seeds[j][32U] = (uint8_t)i1; seeds[j][33U] = (uint8_t)j;);
      uint8_t uu____1[4U][34U];
      memcpy(uu____1, seeds, (size_t)4U * sizeof(uint8_t[34U]));
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          sampled[4U];
      sample_from_xof_9f0(uu____1, sampled); for (
          size_t i = (size_t)0U;
          i <
          core_slice___Slice_T___len(
              Eurydice_array_to_slice(
                  (size_t)4U, sampled,
                  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                  Eurydice_slice),
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
              size_t);
          i++) {
        size_t j = i;
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            sample = sampled[j];
        if (transpose) {
          A_transpose[j][i1] = sample;
        } else {
          A_transpose[i1][j] = sample;
        }
      });
  memcpy(
      ret, A_transpose,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [4U]));
}

typedef struct
    __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_4size_t__uint8_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      fst[4U];
  uint8_t snd;
} __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_4size_t__uint8_t;

/**
A monomorphic instance of libcrux_ml_kem.hash_functions.portable.PRFxN with
const generics:
- K = 4
- LEN = 128
*/
static KRML_MUSTINLINE void PRFxN_38(uint8_t (*input)[33U],
                                     uint8_t ret[4U][128U]) {
  uint8_t out[4U][128U] = {{0U}};
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
                  libcrux_sha3_portable_shake256(
                      Eurydice_array_to_slice((size_t)128U, out[i0], uint8_t,
                                              Eurydice_slice),
                      Eurydice_array_to_slice((size_t)33U, input[i0], uint8_t,
                                              Eurydice_slice)););
  memcpy(ret, out, (size_t)4U * sizeof(uint8_t[128U]));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.PRFxN
with const generics:
- K = 4
- LEN = 128
*/
static KRML_MUSTINLINE void PRFxN_380(uint8_t (*input)[33U],
                                      uint8_t ret[4U][128U]) {
  PRFxN_38(input, ret);
}

/**
A monomorphic instance of
libcrux_ml_kem.sampling.sample_from_binomial_distribution_2 with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    sample_from_binomial_distribution_2_24(Eurydice_slice randomness) {
  int16_t sampled_i16s[256U] = {0U};
  for (size_t i0 = (size_t)0U;
       i0 <
       core_slice___Slice_T___len(randomness, uint8_t, size_t) / (size_t)4U;
       i0++) {
    size_t chunk_number = i0;
    Eurydice_slice byte_chunk = Eurydice_slice_subslice2(
        randomness, chunk_number * (size_t)4U,
        chunk_number * (size_t)4U + (size_t)4U, uint8_t, Eurydice_slice);
    uint32_t random_bits_as_u32 =
        (((uint32_t)Eurydice_slice_index(byte_chunk, (size_t)0U, uint8_t,
                                         uint8_t *, uint8_t) |
          (uint32_t)Eurydice_slice_index(byte_chunk, (size_t)1U, uint8_t,
                                         uint8_t *, uint8_t)
              << 8U) |
         (uint32_t)Eurydice_slice_index(byte_chunk, (size_t)2U, uint8_t,
                                        uint8_t *, uint8_t)
             << 16U) |
        (uint32_t)Eurydice_slice_index(byte_chunk, (size_t)3U, uint8_t,
                                       uint8_t *, uint8_t)
            << 24U;
    uint32_t even_bits = random_bits_as_u32 & 1431655765U;
    uint32_t odd_bits = random_bits_as_u32 >> 1U & 1431655765U;
    uint32_t coin_toss_outcomes = even_bits + odd_bits;
    for (uint32_t i = 0U; i < CORE_NUM__U32_8__BITS / 4U; i++) {
      uint32_t outcome_set = i;
      uint32_t outcome_set0 = outcome_set * 4U;
      int16_t outcome_1 =
          (int16_t)(coin_toss_outcomes >> (uint32_t)outcome_set0 & 3U);
      int16_t outcome_2 =
          (int16_t)(coin_toss_outcomes >> (uint32_t)(outcome_set0 + 2U) & 3U);
      size_t offset = (size_t)(outcome_set0 >> 2U);
      sampled_i16s[(size_t)8U * chunk_number + offset] = outcome_1 - outcome_2;
    }
  }
  return from_i16_array_24(Eurydice_array_to_slice((size_t)256U, sampled_i16s,
                                                   int16_t, Eurydice_slice));
}

/**
A monomorphic instance of
libcrux_ml_kem.sampling.sample_from_binomial_distribution_3 with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    sample_from_binomial_distribution_3_24(Eurydice_slice randomness) {
  int16_t sampled_i16s[256U] = {0U};
  for (size_t i0 = (size_t)0U;
       i0 <
       core_slice___Slice_T___len(randomness, uint8_t, size_t) / (size_t)3U;
       i0++) {
    size_t chunk_number = i0;
    Eurydice_slice byte_chunk = Eurydice_slice_subslice2(
        randomness, chunk_number * (size_t)3U,
        chunk_number * (size_t)3U + (size_t)3U, uint8_t, Eurydice_slice);
    uint32_t random_bits_as_u24 =
        ((uint32_t)Eurydice_slice_index(byte_chunk, (size_t)0U, uint8_t,
                                        uint8_t *, uint8_t) |
         (uint32_t)Eurydice_slice_index(byte_chunk, (size_t)1U, uint8_t,
                                        uint8_t *, uint8_t)
             << 8U) |
        (uint32_t)Eurydice_slice_index(byte_chunk, (size_t)2U, uint8_t,
                                       uint8_t *, uint8_t)
            << 16U;
    uint32_t first_bits = random_bits_as_u24 & 2396745U;
    uint32_t second_bits = random_bits_as_u24 >> 1U & 2396745U;
    uint32_t third_bits = random_bits_as_u24 >> 2U & 2396745U;
    uint32_t coin_toss_outcomes = first_bits + second_bits + third_bits;
    for (int32_t i = (int32_t)0; i < (int32_t)24 / (int32_t)6; i++) {
      int32_t outcome_set = i;
      int32_t outcome_set0 = outcome_set * (int32_t)6;
      int16_t outcome_1 =
          (int16_t)(coin_toss_outcomes >> (uint32_t)outcome_set0 & 7U);
      int16_t outcome_2 = (int16_t)(coin_toss_outcomes >>
                                        (uint32_t)(outcome_set0 + (int32_t)3) &
                                    7U);
      size_t offset = (size_t)(outcome_set0 / (int32_t)6);
      sampled_i16s[(size_t)4U * chunk_number + offset] = outcome_1 - outcome_2;
    }
  }
  return from_i16_array_24(Eurydice_array_to_slice((size_t)256U, sampled_i16s,
                                                   int16_t, Eurydice_slice));
}

/**
A monomorphic instance of
libcrux_ml_kem.sampling.sample_from_binomial_distribution with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- ETA = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    sample_from_binomial_distribution_c0(Eurydice_slice randomness) {
  return sample_from_binomial_distribution_2_24(randomness);
}

/**
A monomorphic instance of libcrux_ml_kem.ntt.ntt_at_layer_7 with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void ntt_at_layer_7_24(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  size_t step = LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT / (size_t)2U;
  for (size_t i = (size_t)0U; i < step; i++) {
    size_t j = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector t =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___multiply_by_constant(
            re->coefficients[j + step], (int16_t)-1600);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___sub(
            re->coefficients[j], &t);
    re->coefficients[j + step] = uu____0;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____1 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
            re->coefficients[j], &t);
    re->coefficients[j] = uu____1;
  }
}

typedef struct
    __libcrux_ml_kem_vector_portable_vector_type_PortableVector_libcrux_ml_kem_vector_portable_vector_type_PortableVector_s {
  libcrux_ml_kem_vector_portable_vector_type_PortableVector fst;
  libcrux_ml_kem_vector_portable_vector_type_PortableVector snd;
} __libcrux_ml_kem_vector_portable_vector_type_PortableVector_libcrux_ml_kem_vector_portable_vector_type_PortableVector;

/**
A monomorphic instance of libcrux_ml_kem.vector.traits.montgomery_multiply_fe
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector
montgomery_multiply_fe_24(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v, int16_t fer) {
  return libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___montgomery_multiply_by_constant(
      v, fer);
}

/**
A monomorphic instance of libcrux_ml_kem.ntt.ntt_layer_int_vec_step with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    __libcrux_ml_kem_vector_portable_vector_type_PortableVector_libcrux_ml_kem_vector_portable_vector_type_PortableVector
    ntt_layer_int_vec_step_24(
        libcrux_ml_kem_vector_portable_vector_type_PortableVector a,
        libcrux_ml_kem_vector_portable_vector_type_PortableVector b,
        int16_t zeta_r) {
  libcrux_ml_kem_vector_portable_vector_type_PortableVector t =
      montgomery_multiply_fe_24(b, zeta_r);
  b = libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___sub(
      a, &t);
  a = libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
      a, &t);
  return (CLITERAL(
      __libcrux_ml_kem_vector_portable_vector_type_PortableVector_libcrux_ml_kem_vector_portable_vector_type_PortableVector){
      .fst = a, .snd = b});
}

/**
A monomorphic instance of libcrux_ml_kem.ntt.ntt_at_layer_4_plus with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void ntt_at_layer_4_plus_24(
    size_t *zeta_i,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re,
    size_t layer) {
  size_t step = (size_t)1U << (uint32_t)layer;
  for (size_t i0 = (size_t)0U; i0 < (size_t)128U >> (uint32_t)layer; i0++) {
    size_t round = i0;
    zeta_i[0U] = zeta_i[0U] + (size_t)1U;
    size_t offset = round * step * (size_t)2U;
    size_t offset_vec = offset / (size_t)16U;
    size_t step_vec = step / (size_t)16U;
    for (size_t i = offset_vec; i < offset_vec + step_vec; i++) {
      size_t j = i;
      __libcrux_ml_kem_vector_portable_vector_type_PortableVector_libcrux_ml_kem_vector_portable_vector_type_PortableVector
          uu____0 = ntt_layer_int_vec_step_24(
              re->coefficients[j], re->coefficients[j + step_vec],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U]]);
      libcrux_ml_kem_vector_portable_vector_type_PortableVector x = uu____0.fst;
      libcrux_ml_kem_vector_portable_vector_type_PortableVector y = uu____0.snd;
      re->coefficients[j] = x;
      re->coefficients[j + step_vec] = y;
    }
  }
}

/**
A monomorphic instance of libcrux_ml_kem.ntt.ntt_at_layer_3 with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void ntt_at_layer_3_24(
    size_t *zeta_i,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  KRML_MAYBE_FOR16(
      i, (size_t)0U, (size_t)16U, (size_t)1U, size_t round = i;
      zeta_i[0U] = zeta_i[0U] + (size_t)1U;
      libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
          libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ntt_layer_3_step(
              re->coefficients[round],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U]]);
      re->coefficients[round] = uu____0;);
}

/**
A monomorphic instance of libcrux_ml_kem.ntt.ntt_at_layer_2 with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void ntt_at_layer_2_24(
    size_t *zeta_i,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  KRML_MAYBE_FOR16(
      i, (size_t)0U, (size_t)16U, (size_t)1U, size_t round = i;
      zeta_i[0U] = zeta_i[0U] + (size_t)1U;
      libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
          libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ntt_layer_2_step(
              re->coefficients[round],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U]],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U] +
                                                                 (size_t)1U]);
      re->coefficients[round] = uu____0; zeta_i[0U] = zeta_i[0U] + (size_t)1U;);
}

/**
A monomorphic instance of libcrux_ml_kem.ntt.ntt_at_layer_1 with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void ntt_at_layer_1_24(
    size_t *zeta_i,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  KRML_MAYBE_FOR16(
      i, (size_t)0U, (size_t)16U, (size_t)1U, size_t round = i;
      zeta_i[0U] = zeta_i[0U] + (size_t)1U;
      libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
          libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ntt_layer_1_step(
              re->coefficients[round],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U]],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U] +
                                                                 (size_t)1U],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U] +
                                                                 (size_t)2U],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U] +
                                                                 (size_t)3U]);
      re->coefficients[round] = uu____0; zeta_i[0U] = zeta_i[0U] + (size_t)3U;);
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@0]}.poly_barrett_reduce
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void poly_barrett_reduce_24(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *self) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___barrett_reduce(
            self->coefficients[i0]);
    self->coefficients[i0] = uu____0;
  }
}

/**
A monomorphic instance of libcrux_ml_kem.ntt.ntt_binomially_sampled_ring_element
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void ntt_binomially_sampled_ring_element_24(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  ntt_at_layer_7_24(re);
  size_t zeta_i = (size_t)1U;
  ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)6U);
  ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)5U);
  ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)4U);
  ntt_at_layer_3_24(&zeta_i, re);
  ntt_at_layer_2_24(&zeta_i, re);
  ntt_at_layer_1_24(&zeta_i, re);
  poly_barrett_reduce_24(re);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.sample_vector_cbd_then_ntt with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
- ETA = 2
- ETA_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_4size_t__uint8_t
    sample_vector_cbd_then_ntt_23(uint8_t prf_input[33U],
                                  uint8_t domain_separator) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      re_as_ntt[4U];
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U,
                  re_as_ntt[i] = ZERO_24(););
  uint8_t uu____0[33U];
  memcpy(uu____0, prf_input, (size_t)33U * sizeof(uint8_t));
  uint8_t prf_inputs[4U][33U];
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U,
      memcpy(prf_inputs[i], uu____0, (size_t)33U * sizeof(uint8_t)););
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
                  prf_inputs[i0][32U] = domain_separator;
                  domain_separator = (uint32_t)domain_separator + 1U;);
  uint8_t prf_outputs[4U][128U];
  PRFxN_380(prf_inputs, prf_outputs);
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          uu____1 =
              sample_from_binomial_distribution_c0(Eurydice_array_to_slice(
                  (size_t)128U, prf_outputs[i0], uint8_t, Eurydice_slice));
      re_as_ntt[i0] = uu____1;
      ntt_binomially_sampled_ring_element_24(&re_as_ntt[i0]););
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____2[4U];
  memcpy(
      uu____2, re_as_ntt,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_4size_t__uint8_t
      lit;
  memcpy(
      lit.fst, uu____2,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  lit.snd = domain_separator;
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@0]}.ntt_multiply
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    ntt_multiply_24(
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *self,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *rhs) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      out = ZERO_24();
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ntt_multiply(
            &self->coefficients[i0], &rhs->coefficients[i0],
            libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[(size_t)64U +
                                                               (size_t)4U * i0],
            libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[(size_t)64U +
                                                               (size_t)4U * i0 +
                                                               (size_t)1U],
            libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[(size_t)64U +
                                                               (size_t)4U * i0 +
                                                               (size_t)2U],
            libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[(size_t)64U +
                                                               (size_t)4U * i0 +
                                                               (size_t)3U]);
    out.coefficients[i0] = uu____0;
  }
  return out;
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@0]}.add_to_ring_element
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with
const generics:
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void add_to_ring_element_eb(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *rhs) {
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(
               Eurydice_array_to_slice(
                   (size_t)16U, self->coefficients,
                   libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                   Eurydice_slice),
               libcrux_ml_kem_vector_portable_vector_type_PortableVector,
               size_t);
       i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
            self->coefficients[i0], &rhs->coefficients[i0]);
    self->coefficients[i0] = uu____0;
  }
}

/**
A monomorphic instance of libcrux_ml_kem.vector.traits.to_standard_domain with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore,
this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector
to_standard_domain_24(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___montgomery_multiply_by_constant(
      v, LIBCRUX_ML_KEM_VECTOR_TRAITS_MONTGOMERY_R_SQUARED_MOD_FIELD_MODULUS);
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@0]}.add_standard_error_reduce
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void add_standard_error_reduce_24(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *error) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t j = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector
        coefficient_normal_form = to_standard_domain_24(self->coefficients[j]);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___barrett_reduce(
            libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
                coefficient_normal_form, &error->coefficients[j]));
    self->coefficients[j] = uu____0;
  }
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_As_plus_e with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compute_As_plus_e_eb(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector (
        *matrix_A)[4U],
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *s_as_ntt,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *error_as_ntt,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[4U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result[4U];
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U,
                  result[i] = ZERO_24(););
  for (
      size_t i0 = (size_t)0U;
      i0 <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)4U, matrix_A,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [4U],
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
              [4U],
          size_t);
      i0++) {
    size_t i1 = i0;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *row = matrix_A[i1];
    for (
        size_t i = (size_t)0U;
        i <
        core_slice___Slice_T___len(
            Eurydice_array_to_slice(
                (size_t)4U, row,
                libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                Eurydice_slice),
            libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
            size_t);
        i++) {
      size_t j = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          *matrix_element = &row[j];
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(matrix_element, &s_as_ntt[j]);
      add_to_ring_element_eb(&result[i1], &product);
    }
    add_standard_error_reduce_24(&result[i1], &error_as_ntt[i1]);
  }
  memcpy(
      ret, result,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.generate_keypair_unpacked with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t__
generate_keypair_unpacked_23(Eurydice_slice key_generation_seed) {
  uint8_t hashed[64U];
  G_c3(key_generation_seed, hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____0 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          (size_t)32U, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice seed_for_A0 = uu____0.fst;
  Eurydice_slice seed_for_secret_and_error = uu____0.snd;
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A_transpose[4U][4U];
  uint8_t ret[34U];
  libcrux_ml_kem_utils_into_padded_array_fe(seed_for_A0, ret);
  sample_matrix_A_9f0(ret, true, A_transpose);
  uint8_t prf_input[33U];
  libcrux_ml_kem_utils_into_padded_array_cb(seed_for_secret_and_error,
                                            prf_input);
  uint8_t uu____1[33U];
  memcpy(uu____1, prf_input, (size_t)33U * sizeof(uint8_t));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_4size_t__uint8_t
      uu____2 = sample_vector_cbd_then_ntt_23(uu____1, 0U);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      secret_as_ntt[4U];
  memcpy(
      secret_as_ntt, uu____2.fst,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t domain_separator = uu____2.snd;
  uint8_t uu____3[33U];
  memcpy(uu____3, prf_input, (size_t)33U * sizeof(uint8_t));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_as_ntt[4U];
  memcpy(
      error_as_ntt,
      sample_vector_cbd_then_ntt_23(uu____3, domain_separator).fst,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      t_as_ntt[4U];
  compute_As_plus_e_eb(A_transpose, secret_as_ntt, error_as_ntt, t_as_ntt);
  uint8_t seed_for_A[32U];
  core_result_Result__uint8_t_32size_t__core_array_TryFromSliceError dst;
  Eurydice_slice_to_array2(&dst, seed_for_A0, Eurydice_slice, uint8_t[32U],
                           void *);
  core_result__core__result__Result_T__E___unwrap_fb(dst, seed_for_A);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____4[4U];
  memcpy(
      uu____4, t_as_ntt,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____5[4U][4U];
  memcpy(
      uu____5, A_transpose,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [4U]));
  uint8_t uu____6[32U];
  memcpy(uu____6, seed_for_A, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      pk;
  memcpy(
      pk.t_as_ntt, uu____4,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  memcpy(pk.seed_for_A, uu____6, (size_t)32U * sizeof(uint8_t));
  memcpy(
      pk.A, uu____5,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [4U]));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____7[4U];
  memcpy(
      uu____7, secret_as_ntt,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      sk;
  memcpy(
      sk.secret_as_ntt, uu____7,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  return (CLITERAL(
      __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t__){
      .fst = sk, .snd = pk});
}

/**
A monomorphic instance of
libcrux_ml_kem.ind_cca.generate_keypair_unpacked.closure with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
- CPA_PRIVATE_KEY_SIZE = 1536
- PRIVATE_KEY_SIZE = 3168
- PUBLIC_KEY_SIZE = 1568
- BYTES_PER_RING_ELEMENT = 1536
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void closure_23(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[4U]) {
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U, ret[i] = ZERO_24(););
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{(core::clone::Clone␣for␣libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@1])#1}.clone
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static inline libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
clone_24(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *self) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      lit;
  libcrux_ml_kem_vector_portable_vector_type_PortableVector ret[16U];
  core_array___core__clone__Clone_for__Array_T__N___20__clone(
      (size_t)16U, self->coefficients, ret,
      libcrux_ml_kem_vector_portable_vector_type_PortableVector, void *);
  memcpy(lit.coefficients, ret,
         (size_t)16U *
             sizeof(libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.H
with const generics:
- K = 4
*/
static KRML_MUSTINLINE void H_c3(Eurydice_slice input, uint8_t ret[32U]) {
  libcrux_ml_kem_hash_functions_portable_H(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.generate_keypair_unpacked with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
- CPA_PRIVATE_KEY_SIZE = 1536
- PRIVATE_KEY_SIZE = 3168
- PUBLIC_KEY_SIZE = 1568
- BYTES_PER_RING_ELEMENT = 1536
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
libcrux_ml_kem_ind_cca_generate_keypair_unpacked_23(uint8_t randomness[64U]) {
  Eurydice_slice ind_cpa_keypair_randomness = Eurydice_array_to_subslice2(
      randomness, (size_t)0U,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      Eurydice_slice);
  Eurydice_slice implicit_rejection_value0 = Eurydice_array_to_subslice_from(
      (size_t)64U, randomness,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      size_t, Eurydice_slice);
  __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t__
      uu____0 = generate_keypair_unpacked_23(ind_cpa_keypair_randomness);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      ind_cpa_private_key = uu____0.fst;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      ind_cpa_public_key = uu____0.snd;
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A[4U][4U];
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U, closure_23(A[i]););
  KRML_MAYBE_FOR4(
      i0, (size_t)0U, (size_t)4U, (size_t)1U, size_t i1 = i0; KRML_MAYBE_FOR4(
          i, (size_t)0U, (size_t)4U, (size_t)1U, size_t j = i;
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
              uu____1 = clone_24(&ind_cpa_public_key.A[j][i1]);
          A[i1][j] = uu____1;););
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____2[4U][4U];
  memcpy(
      uu____2, A,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [4U]));
  memcpy(
      ind_cpa_public_key.A, uu____2,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [4U]));
  uint8_t pk_serialized[1568U];
  serialize_public_key_38(
      ind_cpa_public_key.t_as_ntt,
      Eurydice_array_to_slice((size_t)32U, ind_cpa_public_key.seed_for_A,
                              uint8_t, Eurydice_slice),
      pk_serialized);
  uint8_t public_key_hash[32U];
  H_c3(Eurydice_array_to_slice((size_t)1568U, pk_serialized, uint8_t,
                               Eurydice_slice),
       public_key_hash);
  uint8_t implicit_rejection_value[32U];
  core_result_Result__uint8_t_32size_t__core_array_TryFromSliceError dst;
  Eurydice_slice_to_array2(&dst, implicit_rejection_value0, Eurydice_slice,
                           uint8_t[32U], void *);
  core_result__core__result__Result_T__E___unwrap_fb(dst,
                                                     implicit_rejection_value);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      uu____3 = ind_cpa_private_key;
  uint8_t uu____4[32U];
  memcpy(uu____4, implicit_rejection_value, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      uu____5;
  uu____5.ind_cpa_private_key = uu____3;
  memcpy(uu____5.implicit_rejection_value, uu____4,
         (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      uu____6 = ind_cpa_public_key;
  uint8_t uu____7[32U];
  memcpy(uu____7, public_key_hash, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      lit;
  lit.private_key = uu____5;
  lit.public_key.ind_cpa_public_key = uu____6;
  memcpy(lit.public_key.public_key_hash, uu____7,
         (size_t)32U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.generate_keypair with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
- PRIVATE_KEY_SIZE = 1536
- PUBLIC_KEY_SIZE = 1568
- RANKED_BYTES_PER_RING_ELEMENT = 1536
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static libcrux_ml_kem_utils_extraction_helper_Keypair1024 generate_keypair_23(
    Eurydice_slice key_generation_seed) {
  __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___4size_t__
      uu____0 = generate_keypair_unpacked_23(key_generation_seed);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      sk = uu____0.fst;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      pk = uu____0.snd;
  uint8_t public_key_serialized[1568U];
  serialize_public_key_38(pk.t_as_ntt,
                          Eurydice_array_to_slice((size_t)32U, pk.seed_for_A,
                                                  uint8_t, Eurydice_slice),
                          public_key_serialized);
  uint8_t secret_key_serialized[1536U];
  serialize_secret_key_4b(sk.secret_as_ntt, secret_key_serialized);
  uint8_t uu____1[1536U];
  memcpy(uu____1, secret_key_serialized, (size_t)1536U * sizeof(uint8_t));
  uint8_t uu____2[1568U];
  memcpy(uu____2, public_key_serialized, (size_t)1568U * sizeof(uint8_t));
  libcrux_ml_kem_utils_extraction_helper_Keypair1024 lit;
  memcpy(lit.fst, uu____1, (size_t)1536U * sizeof(uint8_t));
  memcpy(lit.snd, uu____2, (size_t)1568U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.serialize_kem_secret_key with
types libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with
const generics:
- K = 4
- SERIALIZED_KEY_LEN = 3168
*/
static KRML_MUSTINLINE void serialize_kem_secret_key_43(
    Eurydice_slice private_key, Eurydice_slice public_key,
    Eurydice_slice implicit_rejection_value, uint8_t ret[3168U]) {
  uint8_t out[3168U] = {0U};
  size_t pointer = (size_t)0U;
  uint8_t *uu____0 = out;
  size_t uu____1 = pointer;
  size_t uu____2 = pointer;
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice2(
          uu____0, uu____1,
          uu____2 + core_slice___Slice_T___len(private_key, uint8_t, size_t),
          uint8_t, Eurydice_slice),
      private_key, uint8_t, void *);
  pointer = pointer + core_slice___Slice_T___len(private_key, uint8_t, size_t);
  uint8_t *uu____3 = out;
  size_t uu____4 = pointer;
  size_t uu____5 = pointer;
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice2(
          uu____3, uu____4,
          uu____5 + core_slice___Slice_T___len(public_key, uint8_t, size_t),
          uint8_t, Eurydice_slice),
      public_key, uint8_t, void *);
  pointer = pointer + core_slice___Slice_T___len(public_key, uint8_t, size_t);
  Eurydice_slice uu____6 = Eurydice_array_to_subslice2(
      out, pointer, pointer + LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
      Eurydice_slice);
  uint8_t ret0[32U];
  H_c3(public_key, ret0);
  core_slice___Slice_T___copy_from_slice(
      uu____6,
      Eurydice_array_to_slice((size_t)32U, ret0, uint8_t, Eurydice_slice),
      uint8_t, void *);
  pointer = pointer + LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE;
  uint8_t *uu____7 = out;
  size_t uu____8 = pointer;
  size_t uu____9 = pointer;
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice2(
          uu____7, uu____8,
          uu____9 + core_slice___Slice_T___len(implicit_rejection_value,
                                               uint8_t, size_t),
          uint8_t, Eurydice_slice),
      implicit_rejection_value, uint8_t, void *);
  memcpy(ret, out, (size_t)3168U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.generate_keypair with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
- CPA_PRIVATE_KEY_SIZE = 1536
- PRIVATE_KEY_SIZE = 3168
- PUBLIC_KEY_SIZE = 1568
- BYTES_PER_RING_ELEMENT = 1536
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
libcrux_ml_kem_mlkem1024_MlKem1024KeyPair
libcrux_ml_kem_ind_cca_generate_keypair_23(uint8_t randomness[64U]) {
  Eurydice_slice ind_cpa_keypair_randomness = Eurydice_array_to_subslice2(
      randomness, (size_t)0U,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      Eurydice_slice);
  Eurydice_slice implicit_rejection_value = Eurydice_array_to_subslice_from(
      (size_t)64U, randomness,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      size_t, Eurydice_slice);
  libcrux_ml_kem_utils_extraction_helper_Keypair1024 uu____0 =
      generate_keypair_23(ind_cpa_keypair_randomness);
  uint8_t ind_cpa_private_key[1536U];
  memcpy(ind_cpa_private_key, uu____0.fst, (size_t)1536U * sizeof(uint8_t));
  uint8_t public_key[1568U];
  memcpy(public_key, uu____0.snd, (size_t)1568U * sizeof(uint8_t));
  uint8_t secret_key_serialized[3168U];
  serialize_kem_secret_key_43(
      Eurydice_array_to_slice((size_t)1536U, ind_cpa_private_key, uint8_t,
                              Eurydice_slice),
      Eurydice_array_to_slice((size_t)1568U, public_key, uint8_t,
                              Eurydice_slice),
      implicit_rejection_value, secret_key_serialized);
  uint8_t uu____1[3168U];
  memcpy(uu____1, secret_key_serialized, (size_t)3168U * sizeof(uint8_t));
  libcrux_ml_kem_types_MlKemPrivateKey____3168size_t private_key =
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPrivateKey_SIZE___8__from_df(
          uu____1);
  libcrux_ml_kem_types_MlKemPrivateKey____3168size_t uu____2 = private_key;
  uint8_t uu____3[1568U];
  memcpy(uu____3, public_key, (size_t)1568U * sizeof(uint8_t));
  return libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemKeyPair_PRIVATE_KEY_SIZE__PUBLIC_KEY_SIZE___from_8e(
      uu____2,
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPublicKey_SIZE___14__from_a7(
          uu____3));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.sample_ring_element_cbd with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
- ETA2_RANDOMNESS_SIZE = 128
- ETA2 = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_4size_t__uint8_t
    sample_ring_element_cbd_23(uint8_t prf_input[33U],
                               uint8_t domain_separator) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_1[4U];
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U,
                  error_1[i] = ZERO_24(););
  uint8_t uu____0[33U];
  memcpy(uu____0, prf_input, (size_t)33U * sizeof(uint8_t));
  uint8_t prf_inputs[4U][33U];
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U,
      memcpy(prf_inputs[i], uu____0, (size_t)33U * sizeof(uint8_t)););
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
                  prf_inputs[i0][32U] = domain_separator;
                  domain_separator = (uint32_t)domain_separator + 1U;);
  uint8_t prf_outputs[4U][128U];
  PRFxN_380(prf_inputs, prf_outputs);
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          uu____1 =
              sample_from_binomial_distribution_c0(Eurydice_array_to_slice(
                  (size_t)128U, prf_outputs[i0], uint8_t, Eurydice_slice));
      error_1[i0] = uu____1;);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____2[4U];
  memcpy(
      uu____2, error_1,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_4size_t__uint8_t
      lit;
  memcpy(
      lit.fst, uu____2,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  lit.snd = domain_separator;
  return lit;
}

/**
A monomorphic instance of libcrux_ml_kem.hash_functions.portable.PRF with const
generics:
- LEN = 128
*/
static KRML_MUSTINLINE void PRF_9b(Eurydice_slice input, uint8_t ret[128U]) {
  uint8_t digest[128U] = {0U};
  libcrux_sha3_portable_shake256(
      Eurydice_array_to_slice((size_t)128U, digest, uint8_t, Eurydice_slice),
      input);
  memcpy(ret, digest, (size_t)128U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.PRF
with const generics:
- K = 4
- LEN = 128
*/
static KRML_MUSTINLINE void PRF_38(Eurydice_slice input, uint8_t ret[128U]) {
  PRF_9b(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.invert_ntt.invert_ntt_at_layer_1 with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore,
this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void invert_ntt_at_layer_1_24(
    size_t *zeta_i,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  KRML_MAYBE_FOR16(
      i, (size_t)0U, (size_t)16U, (size_t)1U, size_t round = i;
      zeta_i[0U] = zeta_i[0U] - (size_t)1U;
      libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
          libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___inv_ntt_layer_1_step(
              re->coefficients[round],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U]],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U] -
                                                                 (size_t)1U],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U] -
                                                                 (size_t)2U],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U] -
                                                                 (size_t)3U]);
      re->coefficients[round] = uu____0; zeta_i[0U] = zeta_i[0U] - (size_t)3U;);
}

/**
A monomorphic instance of libcrux_ml_kem.invert_ntt.invert_ntt_at_layer_2 with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore,
this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void invert_ntt_at_layer_2_24(
    size_t *zeta_i,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  KRML_MAYBE_FOR16(
      i, (size_t)0U, (size_t)16U, (size_t)1U, size_t round = i;
      zeta_i[0U] = zeta_i[0U] - (size_t)1U;
      libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
          libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___inv_ntt_layer_2_step(
              re->coefficients[round],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U]],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U] -
                                                                 (size_t)1U]);
      re->coefficients[round] = uu____0; zeta_i[0U] = zeta_i[0U] - (size_t)1U;);
}

/**
A monomorphic instance of libcrux_ml_kem.invert_ntt.invert_ntt_at_layer_3 with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore,
this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void invert_ntt_at_layer_3_24(
    size_t *zeta_i,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  KRML_MAYBE_FOR16(
      i, (size_t)0U, (size_t)16U, (size_t)1U, size_t round = i;
      zeta_i[0U] = zeta_i[0U] - (size_t)1U;
      libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
          libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___inv_ntt_layer_3_step(
              re->coefficients[round],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U]]);
      re->coefficients[round] = uu____0;);
}

/**
A monomorphic instance of
libcrux_ml_kem.invert_ntt.inv_ntt_layer_int_vec_step_reduce with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    __libcrux_ml_kem_vector_portable_vector_type_PortableVector_libcrux_ml_kem_vector_portable_vector_type_PortableVector
    inv_ntt_layer_int_vec_step_reduce_24(
        libcrux_ml_kem_vector_portable_vector_type_PortableVector a,
        libcrux_ml_kem_vector_portable_vector_type_PortableVector b,
        int16_t zeta_r) {
  libcrux_ml_kem_vector_portable_vector_type_PortableVector a_minus_b =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___sub(
          b, &a);
  a = libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___barrett_reduce(
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
          a, &b));
  b = montgomery_multiply_fe_24(a_minus_b, zeta_r);
  return (CLITERAL(
      __libcrux_ml_kem_vector_portable_vector_type_PortableVector_libcrux_ml_kem_vector_portable_vector_type_PortableVector){
      .fst = a, .snd = b});
}

/**
A monomorphic instance of libcrux_ml_kem.invert_ntt.invert_ntt_at_layer_4_plus
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void invert_ntt_at_layer_4_plus_24(
    size_t *zeta_i,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re,
    size_t layer) {
  size_t step = (size_t)1U << (uint32_t)layer;
  for (size_t i0 = (size_t)0U; i0 < (size_t)128U >> (uint32_t)layer; i0++) {
    size_t round = i0;
    zeta_i[0U] = zeta_i[0U] - (size_t)1U;
    size_t offset = round * step * (size_t)2U;
    size_t offset_vec =
        offset / LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR;
    size_t step_vec =
        step / LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR;
    for (size_t i = offset_vec; i < offset_vec + step_vec; i++) {
      size_t j = i;
      __libcrux_ml_kem_vector_portable_vector_type_PortableVector_libcrux_ml_kem_vector_portable_vector_type_PortableVector
          uu____0 = inv_ntt_layer_int_vec_step_reduce_24(
              re->coefficients[j], re->coefficients[j + step_vec],
              libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[zeta_i[0U]]);
      libcrux_ml_kem_vector_portable_vector_type_PortableVector x = uu____0.fst;
      libcrux_ml_kem_vector_portable_vector_type_PortableVector y = uu____0.snd;
      re->coefficients[j] = x;
      re->coefficients[j + step_vec] = y;
    }
  }
}

/**
A monomorphic instance of libcrux_ml_kem.invert_ntt.invert_ntt_montgomery with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void invert_ntt_montgomery_eb(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  size_t zeta_i =
      LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT / (size_t)2U;
  invert_ntt_at_layer_1_24(&zeta_i, re);
  invert_ntt_at_layer_2_24(&zeta_i, re);
  invert_ntt_at_layer_3_24(&zeta_i, re);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)4U);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)5U);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)6U);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)7U);
  poly_barrett_reduce_24(re);
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@0]}.add_error_reduce
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void add_error_reduce_24(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *error) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t j = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector
        coefficient_normal_form =
            libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___montgomery_multiply_by_constant(
                self->coefficients[j], (int16_t)1441);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___barrett_reduce(
            libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
                coefficient_normal_form, &error->coefficients[j]));
    self->coefficients[j] = uu____0;
  }
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_vector_u with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compute_vector_u_eb(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector (
        *a_as_ntt)[4U],
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *r_as_ntt,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *error_1,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[4U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result[4U];
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U,
                  result[i] = ZERO_24(););
  for (
      size_t i0 = (size_t)0U;
      i0 <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)4U, a_as_ntt,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [4U],
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
              [4U],
          size_t);
      i0++) {
    size_t i1 = i0;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *row = a_as_ntt[i1];
    for (
        size_t i = (size_t)0U;
        i <
        core_slice___Slice_T___len(
            Eurydice_array_to_slice(
                (size_t)4U, row,
                libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                Eurydice_slice),
            libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
            size_t);
        i++) {
      size_t j = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          *a_element = &row[j];
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(a_element, &r_as_ntt[j]);
      add_to_ring_element_eb(&result[i1], &product);
    }
    invert_ntt_montgomery_eb(&result[i1]);
    add_error_reduce_24(&result[i1], &error_1[i1]);
  }
  memcpy(
      ret, result,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.vector.traits.decompress_1 with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector
decompress_1_24(libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___ZERO();
  return libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___bitwise_and_with_constant(
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___sub(
          uu____0, &v),
      (int16_t)1665);
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_then_decompress_message with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    deserialize_then_decompress_message_24(uint8_t serialized[32U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      re = ZERO_24();
  KRML_MAYBE_FOR16(
      i, (size_t)0U, (size_t)16U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_vector_portable_vector_type_PortableVector
          coefficient_compressed =
              libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_1(
                  Eurydice_array_to_subslice2(serialized, (size_t)2U * i0,
                                              (size_t)2U * i0 + (size_t)2U,
                                              uint8_t, Eurydice_slice));
      libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
          decompress_1_24(coefficient_compressed);
      re.coefficients[i0] = uu____0;);
  return re;
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@0]}.add_message_error_reduce
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    add_message_error_reduce_24(
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *self,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *message,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            result) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector
        coefficient_normal_form =
            libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___montgomery_multiply_by_constant(
                result.coefficients[i0], (int16_t)1441);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector tmp =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
            self->coefficients[i0], &message->coefficients[i0]);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector tmp0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
            coefficient_normal_form, &tmp);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___barrett_reduce(
            tmp0);
    result.coefficients[i0] = uu____0;
  }
  return result;
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_ring_element_v with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    compute_ring_element_v_eb(
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *t_as_ntt,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *r_as_ntt,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *error_2,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *message) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result = ZERO_24();
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(&t_as_ntt[i0], &r_as_ntt[i0]);
      add_to_ring_element_eb(&result, &product););
  invert_ntt_montgomery_eb(&result);
  result = add_message_error_reduce_24(error_2, message, result);
  return result;
}

/**
A monomorphic instance of libcrux_ml_kem.vector.portable.compress.compress with
const generics:
- COEFFICIENT_BITS = 10
*/
static KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
compress_a5(libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    int16_t uu____0 =
        libcrux_ml_kem_vector_portable_compress_compress_ciphertext_coefficient(
            (uint8_t)(int32_t)10, (uint16_t)v.elements[i0]);
    v.elements[i0] = uu____0;
  }
  return v;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.{(libcrux_ml_kem::vector::traits::Operations␣for␣libcrux_ml_kem::vector::portable::vector_type::PortableVector)}.compress
with const generics:
- COEFFICIENT_BITS = 10
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector compress_a50(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return compress_a5(v);
}

/**
A monomorphic instance of libcrux_ml_kem.vector.portable.compress.compress with
const generics:
- COEFFICIENT_BITS = 11
*/
static KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
compress_93(libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    int16_t uu____0 =
        libcrux_ml_kem_vector_portable_compress_compress_ciphertext_coefficient(
            (uint8_t)(int32_t)11, (uint16_t)v.elements[i0]);
    v.elements[i0] = uu____0;
  }
  return v;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.{(libcrux_ml_kem::vector::traits::Operations␣for␣libcrux_ml_kem::vector::portable::vector_type::PortableVector)}.compress
with const generics:
- COEFFICIENT_BITS = 11
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector compress_930(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return compress_93(v);
}

/**
A monomorphic instance of libcrux_ml_kem.serialize.compress_then_serialize_11
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with
const generics:
- OUT_LEN = 352
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compress_then_serialize_11_c5(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re,
    uint8_t ret[352U]) {
  uint8_t serialized[352U] = {0U};
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector coefficient =
        compress_930(to_unsigned_representative_24(re->coefficients[i0]));
    uint8_t bytes[22U];
    libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_11(
        coefficient, bytes);
    Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
        serialized, (size_t)22U * i0, (size_t)22U * i0 + (size_t)22U, uint8_t,
        Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)22U, bytes, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
  memcpy(ret, serialized, (size_t)352U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.compress_then_serialize_ring_element_u with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- COMPRESSION_FACTOR = 11
- OUT_LEN = 352
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compress_then_serialize_ring_element_u_bd(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re,
    uint8_t ret[352U]) {
  uint8_t uu____0[352U];
  compress_then_serialize_11_c5(re, uu____0);
  memcpy(ret, uu____0, (size_t)352U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.compress_then_serialize_u with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
- OUT_LEN = 1408
- COMPRESSION_FACTOR = 11
- BLOCK_LEN = 352
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void compress_then_serialize_u_67(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        input[4U],
    Eurydice_slice out) {
  for (
      size_t i = (size_t)0U;
      i <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)4U, input,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
          size_t);
      i++) {
    size_t i0 = i;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        re = input[i0];
    Eurydice_slice uu____0 = Eurydice_slice_subslice2(
        out, i0 * ((size_t)1408U / (size_t)4U),
        (i0 + (size_t)1U) * ((size_t)1408U / (size_t)4U), uint8_t,
        Eurydice_slice);
    uint8_t ret[352U];
    compress_then_serialize_ring_element_u_bd(&re, ret);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)352U, ret, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
}

/**
A monomorphic instance of libcrux_ml_kem.vector.portable.compress.compress with
const generics:
- COEFFICIENT_BITS = 4
*/
static KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
compress_3d(libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    int16_t uu____0 =
        libcrux_ml_kem_vector_portable_compress_compress_ciphertext_coefficient(
            (uint8_t)(int32_t)4, (uint16_t)v.elements[i0]);
    v.elements[i0] = uu____0;
  }
  return v;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.{(libcrux_ml_kem::vector::traits::Operations␣for␣libcrux_ml_kem::vector::portable::vector_type::PortableVector)}.compress
with const generics:
- COEFFICIENT_BITS = 4
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector compress_3d0(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return compress_3d(v);
}

/**
A monomorphic instance of libcrux_ml_kem.serialize.compress_then_serialize_4
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compress_then_serialize_4_24(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        re,
    Eurydice_slice serialized) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector coefficient =
        compress_3d0(to_unsigned_representative_24(re.coefficients[i0]));
    uint8_t bytes[8U];
    libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_4(
        coefficient, bytes);
    core_slice___Slice_T___copy_from_slice(
        Eurydice_slice_subslice2(serialized, (size_t)8U * i0,
                                 (size_t)8U * i0 + (size_t)8U, uint8_t,
                                 Eurydice_slice),
        Eurydice_array_to_slice((size_t)8U, bytes, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
}

/**
A monomorphic instance of libcrux_ml_kem.vector.portable.compress.compress with
const generics:
- COEFFICIENT_BITS = 5
*/
static KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
compress_c8(libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    int16_t uu____0 =
        libcrux_ml_kem_vector_portable_compress_compress_ciphertext_coefficient(
            (uint8_t)(int32_t)5, (uint16_t)v.elements[i0]);
    v.elements[i0] = uu____0;
  }
  return v;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.{(libcrux_ml_kem::vector::traits::Operations␣for␣libcrux_ml_kem::vector::portable::vector_type::PortableVector)}.compress
with const generics:
- COEFFICIENT_BITS = 5
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector compress_c80(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return compress_c8(v);
}

/**
A monomorphic instance of libcrux_ml_kem.serialize.compress_then_serialize_5
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compress_then_serialize_5_24(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        re,
    Eurydice_slice serialized) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector coefficients =
        compress_c80(to_unsigned_representative_24(re.coefficients[i0]));
    uint8_t bytes[10U];
    libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_5(
        coefficients, bytes);
    core_slice___Slice_T___copy_from_slice(
        Eurydice_slice_subslice2(serialized, (size_t)10U * i0,
                                 (size_t)10U * i0 + (size_t)10U, uint8_t,
                                 Eurydice_slice),
        Eurydice_array_to_slice((size_t)10U, bytes, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.compress_then_serialize_ring_element_v with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- COMPRESSION_FACTOR = 5
- OUT_LEN = 160
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compress_then_serialize_ring_element_v_00(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        re,
    Eurydice_slice out) {
  compress_then_serialize_5_24(re, out);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.encrypt_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
- CIPHERTEXT_SIZE = 1568
- T_AS_NTT_ENCODED_SIZE = 1536
- C1_LEN = 1408
- C2_LEN = 160
- U_COMPRESSION_FACTOR = 11
- V_COMPRESSION_FACTOR = 5
- BLOCK_LEN = 352
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void encrypt_unpacked_23(
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
        *public_key,
    uint8_t message[32U], Eurydice_slice randomness, uint8_t ret[1568U]) {
  uint8_t prf_input[33U];
  libcrux_ml_kem_utils_into_padded_array_cb(randomness, prf_input);
  uint8_t uu____0[33U];
  memcpy(uu____0, prf_input, (size_t)33U * sizeof(uint8_t));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_4size_t__uint8_t
      uu____1 = sample_vector_cbd_then_ntt_23(uu____0, 0U);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      r_as_ntt[4U];
  memcpy(
      r_as_ntt, uu____1.fst,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t domain_separator0 = uu____1.snd;
  uint8_t uu____2[33U];
  memcpy(uu____2, prf_input, (size_t)33U * sizeof(uint8_t));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_4size_t__uint8_t
      uu____3 = sample_ring_element_cbd_23(uu____2, domain_separator0);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_1[4U];
  memcpy(
      error_1, uu____3.fst,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t domain_separator = uu____3.snd;
  prf_input[32U] = domain_separator;
  uint8_t prf_output[128U];
  PRF_38(
      Eurydice_array_to_slice((size_t)33U, prf_input, uint8_t, Eurydice_slice),
      prf_output);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_2 = sample_from_binomial_distribution_c0(Eurydice_array_to_slice(
          (size_t)128U, prf_output, uint8_t, Eurydice_slice));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      u[4U];
  compute_vector_u_eb(public_key->A, r_as_ntt, error_1, u);
  uint8_t uu____4[32U];
  memcpy(uu____4, message, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      message_as_ring_element = deserialize_then_decompress_message_24(uu____4);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      v = compute_ring_element_v_eb(public_key->t_as_ntt, r_as_ntt, &error_2,
                                    &message_as_ring_element);
  uint8_t ciphertext[1568U] = {0U};
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____5[4U];
  memcpy(
      uu____5, u,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  compress_then_serialize_u_67(
      uu____5,
      Eurydice_array_to_subslice2(ciphertext, (size_t)0U, (size_t)1408U,
                                  uint8_t, Eurydice_slice));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____6 = v;
  compress_then_serialize_ring_element_v_00(
      uu____6,
      Eurydice_array_to_subslice_from((size_t)1568U, ciphertext, (size_t)1408U,
                                      uint8_t, size_t, Eurydice_slice));
  memcpy(ret, ciphertext, (size_t)1568U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.encapsulate_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
- CIPHERTEXT_SIZE = 1568
- PUBLIC_KEY_SIZE = 1568
- T_AS_NTT_ENCODED_SIZE = 1536
- C1_SIZE = 1408
- C2_SIZE = 160
- VECTOR_U_COMPRESSION_FACTOR = 11
- VECTOR_V_COMPRESSION_FACTOR = 5
- VECTOR_U_BLOCK_LEN = 352
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
K___libcrux_ml_kem_types_MlKemCiphertext___1568size_t___uint8_t_32size_t_
libcrux_ml_kem_ind_cca_encapsulate_unpacked_23(
    libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
        *public_key,
    uint8_t randomness[32U]) {
  uint8_t to_hash[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, randomness, uint8_t, Eurydice_slice),
      to_hash);
  Eurydice_slice uu____0 = Eurydice_array_to_subslice_from(
      (size_t)64U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
      size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)32U, public_key->public_key_hash, uint8_t,
                              Eurydice_slice),
      uint8_t, void *);
  uint8_t hashed[64U];
  G_c3(Eurydice_array_to_slice((size_t)64U, to_hash, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret = uu____1.fst;
  Eurydice_slice pseudorandomness = uu____1.snd;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      *uu____2 = &public_key->ind_cpa_public_key;
  uint8_t uu____3[32U];
  memcpy(uu____3, randomness, (size_t)32U * sizeof(uint8_t));
  uint8_t ciphertext[1568U];
  encrypt_unpacked_23(uu____2, uu____3, pseudorandomness, ciphertext);
  uint8_t shared_secret_array[32U] = {0U};
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_slice((size_t)32U, shared_secret_array, uint8_t,
                              Eurydice_slice),
      shared_secret, uint8_t, void *);
  uint8_t uu____4[1568U];
  memcpy(uu____4, ciphertext, (size_t)1568U * sizeof(uint8_t));
  libcrux_ml_kem_mlkem1024_MlKem1024Ciphertext uu____5 =
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___2__from_a7(
          uu____4);
  uint8_t uu____6[32U];
  memcpy(uu____6, shared_secret_array, (size_t)32U * sizeof(uint8_t));
  K___libcrux_ml_kem_types_MlKemCiphertext___1568size_t___uint8_t_32size_t_ lit;
  lit.fst = uu____5;
  memcpy(lit.snd, uu____6, (size_t)32U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.ind_cca.{(libcrux_ml_kem::ind_cca::Variant␣for␣libcrux_ml_kem::ind_cca::MlKem)}.entropy_preprocess
with types libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and
with const generics:
- K = 4
*/
static KRML_MUSTINLINE void entropy_preprocess_a6(Eurydice_slice randomness,
                                                  uint8_t ret[32U]) {
  uint8_t out[32U] = {0U};
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_slice((size_t)32U, out, uint8_t, Eurydice_slice),
      randomness, uint8_t, void *);
  memcpy(ret, out, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_ring_elements_reduced with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- PUBLIC_KEY_SIZE = 1536
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_ring_elements_reduced_47(
    Eurydice_slice public_key,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[4U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      deserialized_pk[4U];
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U,
                  deserialized_pk[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(public_key, uint8_t, size_t) /
               LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT;
       i++) {
    size_t i0 = i;
    Eurydice_slice ring_element = Eurydice_slice_subslice2(
        public_key, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT +
            LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_to_reduced_ring_element_24(ring_element);
    deserialized_pk[i0] = uu____0;
  }
  memcpy(
      ret, deserialized_pk,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.encrypt with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
- CIPHERTEXT_SIZE = 1568
- T_AS_NTT_ENCODED_SIZE = 1536
- C1_LEN = 1408
- C2_LEN = 160
- U_COMPRESSION_FACTOR = 11
- V_COMPRESSION_FACTOR = 5
- BLOCK_LEN = 352
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void encrypt_23(Eurydice_slice public_key, uint8_t message[32U],
                       Eurydice_slice randomness, uint8_t ret[1568U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      t_as_ntt[4U];
  deserialize_ring_elements_reduced_47(
      Eurydice_slice_subslice_to(public_key, (size_t)1536U, uint8_t, size_t,
                                 Eurydice_slice),
      t_as_ntt);
  Eurydice_slice seed = Eurydice_slice_subslice_from(
      public_key, (size_t)1536U, uint8_t, size_t, Eurydice_slice);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A[4U][4U];
  uint8_t ret0[34U];
  libcrux_ml_kem_utils_into_padded_array_fe(seed, ret0);
  sample_matrix_A_9f0(ret0, false, A);
  uint8_t seed_for_A[32U];
  core_result_Result__uint8_t_32size_t__core_array_TryFromSliceError dst;
  Eurydice_slice_to_array2(&dst, seed, Eurydice_slice, uint8_t[32U], void *);
  core_result__core__result__Result_T__E___unwrap_fb(dst, seed_for_A);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____0[4U];
  memcpy(
      uu____0, t_as_ntt,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____1[4U][4U];
  memcpy(
      uu____1, A,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [4U]));
  uint8_t uu____2[32U];
  memcpy(uu____2, seed_for_A, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      public_key_unpacked;
  memcpy(
      public_key_unpacked.t_as_ntt, uu____0,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  memcpy(public_key_unpacked.seed_for_A, uu____2,
         (size_t)32U * sizeof(uint8_t));
  memcpy(
      public_key_unpacked.A, uu____1,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [4U]));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      *uu____3 = &public_key_unpacked;
  uint8_t uu____4[32U];
  memcpy(uu____4, message, (size_t)32U * sizeof(uint8_t));
  uint8_t ret1[1568U];
  encrypt_unpacked_23(uu____3, uu____4, randomness, ret1);
  memcpy(ret, ret1, (size_t)1568U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.ind_cca.{(libcrux_ml_kem::ind_cca::Variant␣for␣libcrux_ml_kem::ind_cca::MlKem)}.kdf
with types libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and
with const generics:
- K = 4
- CIPHERTEXT_SIZE = 1568
*/
static KRML_MUSTINLINE void kdf_43(Eurydice_slice shared_secret,
                                   uint8_t ret[32U]) {
  uint8_t out[32U] = {0U};
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_slice((size_t)32U, out, uint8_t, Eurydice_slice),
      shared_secret, uint8_t, void *);
  memcpy(ret, out, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.encapsulate with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]],
libcrux_ml_kem_ind_cca_MlKem and with const generics:
- K = 4
- CIPHERTEXT_SIZE = 1568
- PUBLIC_KEY_SIZE = 1568
- T_AS_NTT_ENCODED_SIZE = 1536
- C1_SIZE = 1408
- C2_SIZE = 160
- VECTOR_U_COMPRESSION_FACTOR = 11
- VECTOR_V_COMPRESSION_FACTOR = 5
- VECTOR_U_BLOCK_LEN = 352
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::ind_cca::Variant for libcrux_ml_kem::ind_cca::MlKem)}
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
K___libcrux_ml_kem_types_MlKemCiphertext___1568size_t___uint8_t_32size_t_
libcrux_ml_kem_ind_cca_encapsulate_12(
    libcrux_ml_kem_types_MlKemPublicKey____1568size_t *public_key,
    uint8_t randomness[32U]) {
  uint8_t randomness0[32U];
  entropy_preprocess_a6(
      Eurydice_array_to_slice((size_t)32U, randomness, uint8_t, Eurydice_slice),
      randomness0);
  uint8_t to_hash[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, randomness0, uint8_t,
                              Eurydice_slice),
      to_hash);
  Eurydice_slice uu____0 = Eurydice_array_to_subslice_from(
      (size_t)64U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
      size_t, Eurydice_slice);
  uint8_t ret[32U];
  H_c3(
      Eurydice_array_to_slice(
          (size_t)1568U,
          libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemPublicKey_SIZE__18__as_slice_a7(
              public_key),
          uint8_t, Eurydice_slice),
      ret);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)32U, ret, uint8_t, Eurydice_slice),
      uint8_t, void *);
  uint8_t hashed[64U];
  G_c3(Eurydice_array_to_slice((size_t)64U, to_hash, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret = uu____1.fst;
  Eurydice_slice pseudorandomness = uu____1.snd;
  Eurydice_slice uu____2 = Eurydice_array_to_slice(
      (size_t)1568U,
      libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemPublicKey_SIZE__18__as_slice_a7(
          public_key),
      uint8_t, Eurydice_slice);
  uint8_t uu____3[32U];
  memcpy(uu____3, randomness0, (size_t)32U * sizeof(uint8_t));
  uint8_t ciphertext[1568U];
  encrypt_23(uu____2, uu____3, pseudorandomness, ciphertext);
  uint8_t uu____4[1568U];
  memcpy(uu____4, ciphertext, (size_t)1568U * sizeof(uint8_t));
  libcrux_ml_kem_mlkem1024_MlKem1024Ciphertext ciphertext0 =
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___2__from_a7(
          uu____4);
  uint8_t shared_secret_array[32U];
  kdf_43(shared_secret, shared_secret_array);
  libcrux_ml_kem_mlkem1024_MlKem1024Ciphertext uu____5 = ciphertext0;
  uint8_t uu____6[32U];
  memcpy(uu____6, shared_secret_array, (size_t)32U * sizeof(uint8_t));
  K___libcrux_ml_kem_types_MlKemCiphertext___1568size_t___uint8_t_32size_t_ lit;
  lit.fst = uu____5;
  memcpy(lit.snd, uu____6, (size_t)32U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.compress.decompress_ciphertext_coefficient with
const generics:
- COEFFICIENT_BITS = 10
*/
static KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
decompress_ciphertext_coefficient_a5(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    int32_t decompressed = (int32_t)v.elements[i0] *
                           (int32_t)LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_MODULUS;
    decompressed = (decompressed << 1U) + ((int32_t)1 << (uint32_t)(int32_t)10);
    decompressed = decompressed >> (uint32_t)((int32_t)10 + (int32_t)1);
    v.elements[i0] = (int16_t)decompressed;
  }
  return v;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.{(libcrux_ml_kem::vector::traits::Operations␣for␣libcrux_ml_kem::vector::portable::vector_type::PortableVector)}.decompress_ciphertext_coefficient
with const generics:
- COEFFICIENT_BITS = 10
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector
decompress_ciphertext_coefficient_a50(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return decompress_ciphertext_coefficient_a5(v);
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_then_decompress_10 with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    deserialize_then_decompress_10_24(Eurydice_slice serialized) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      re = ZERO_24();
  for (size_t i = (size_t)0U;
       i <
       core_slice___Slice_T___len(serialized, uint8_t, size_t) / (size_t)20U;
       i++) {
    size_t i0 = i;
    Eurydice_slice bytes = Eurydice_slice_subslice2(
        serialized, i0 * (size_t)20U, i0 * (size_t)20U + (size_t)20U, uint8_t,
        Eurydice_slice);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector coefficient =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_10(
            bytes);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        decompress_ciphertext_coefficient_a50(coefficient);
    re.coefficients[i0] = uu____0;
  }
  return re;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.compress.decompress_ciphertext_coefficient with
const generics:
- COEFFICIENT_BITS = 11
*/
static KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
decompress_ciphertext_coefficient_93(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    int32_t decompressed = (int32_t)v.elements[i0] *
                           (int32_t)LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_MODULUS;
    decompressed = (decompressed << 1U) + ((int32_t)1 << (uint32_t)(int32_t)11);
    decompressed = decompressed >> (uint32_t)((int32_t)11 + (int32_t)1);
    v.elements[i0] = (int16_t)decompressed;
  }
  return v;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.{(libcrux_ml_kem::vector::traits::Operations␣for␣libcrux_ml_kem::vector::portable::vector_type::PortableVector)}.decompress_ciphertext_coefficient
with const generics:
- COEFFICIENT_BITS = 11
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector
decompress_ciphertext_coefficient_930(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return decompress_ciphertext_coefficient_93(v);
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_then_decompress_11 with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    deserialize_then_decompress_11_24(Eurydice_slice serialized) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      re = ZERO_24();
  for (size_t i = (size_t)0U;
       i <
       core_slice___Slice_T___len(serialized, uint8_t, size_t) / (size_t)22U;
       i++) {
    size_t i0 = i;
    Eurydice_slice bytes = Eurydice_slice_subslice2(
        serialized, i0 * (size_t)22U, i0 * (size_t)22U + (size_t)22U, uint8_t,
        Eurydice_slice);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector coefficient =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_11(
            bytes);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        decompress_ciphertext_coefficient_930(coefficient);
    re.coefficients[i0] = uu____0;
  }
  return re;
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_then_decompress_ring_element_u with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- COMPRESSION_FACTOR = 11
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    deserialize_then_decompress_ring_element_u_5c(Eurydice_slice serialized) {
  return deserialize_then_decompress_11_24(serialized);
}

/**
A monomorphic instance of libcrux_ml_kem.ntt.ntt_vector_u with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- VECTOR_U_COMPRESSION_FACTOR = 11
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void ntt_vector_u_5c(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  size_t zeta_i = (size_t)0U;
  ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)7U);
  ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)6U);
  ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)5U);
  ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)4U);
  ntt_at_layer_3_24(&zeta_i, re);
  ntt_at_layer_2_24(&zeta_i, re);
  ntt_at_layer_1_24(&zeta_i, re);
  poly_barrett_reduce_24(re);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.deserialize_then_decompress_u
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with
const generics:
- K = 4
- CIPHERTEXT_SIZE = 1568
- U_COMPRESSION_FACTOR = 11
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_then_decompress_u_ec(
    uint8_t *ciphertext,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[4U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      u_as_ntt[4U];
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U,
                  u_as_ntt[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(
               Eurydice_array_to_slice((size_t)1568U, ciphertext, uint8_t,
                                       Eurydice_slice),
               uint8_t, size_t) /
               (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
                (size_t)11U / (size_t)8U);
       i++) {
    size_t i0 = i;
    Eurydice_slice u_bytes = Eurydice_array_to_subslice2(
        ciphertext,
        i0 * (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
              (size_t)11U / (size_t)8U),
        i0 * (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
              (size_t)11U / (size_t)8U) +
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
                (size_t)11U / (size_t)8U,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_then_decompress_ring_element_u_5c(u_bytes);
    u_as_ntt[i0] = uu____0;
    ntt_vector_u_5c(&u_as_ntt[i0]);
  }
  memcpy(
      ret, u_as_ntt,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.compress.decompress_ciphertext_coefficient with
const generics:
- COEFFICIENT_BITS = 4
*/
static KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
decompress_ciphertext_coefficient_3d(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    int32_t decompressed = (int32_t)v.elements[i0] *
                           (int32_t)LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_MODULUS;
    decompressed = (decompressed << 1U) + ((int32_t)1 << (uint32_t)(int32_t)4);
    decompressed = decompressed >> (uint32_t)((int32_t)4 + (int32_t)1);
    v.elements[i0] = (int16_t)decompressed;
  }
  return v;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.{(libcrux_ml_kem::vector::traits::Operations␣for␣libcrux_ml_kem::vector::portable::vector_type::PortableVector)}.decompress_ciphertext_coefficient
with const generics:
- COEFFICIENT_BITS = 4
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector
decompress_ciphertext_coefficient_3d0(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return decompress_ciphertext_coefficient_3d(v);
}

/**
A monomorphic instance of libcrux_ml_kem.serialize.deserialize_then_decompress_4
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    deserialize_then_decompress_4_24(Eurydice_slice serialized) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      re = ZERO_24();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(serialized, uint8_t, size_t) / (size_t)8U;
       i++) {
    size_t i0 = i;
    Eurydice_slice bytes = Eurydice_slice_subslice2(
        serialized, i0 * (size_t)8U, i0 * (size_t)8U + (size_t)8U, uint8_t,
        Eurydice_slice);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector coefficient =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_4(
            bytes);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        decompress_ciphertext_coefficient_3d0(coefficient);
    re.coefficients[i0] = uu____0;
  }
  return re;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.compress.decompress_ciphertext_coefficient with
const generics:
- COEFFICIENT_BITS = 5
*/
static KRML_MUSTINLINE libcrux_ml_kem_vector_portable_vector_type_PortableVector
decompress_ciphertext_coefficient_c8(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR; i++) {
    size_t i0 = i;
    int32_t decompressed = (int32_t)v.elements[i0] *
                           (int32_t)LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_MODULUS;
    decompressed = (decompressed << 1U) + ((int32_t)1 << (uint32_t)(int32_t)5);
    decompressed = decompressed >> (uint32_t)((int32_t)5 + (int32_t)1);
    v.elements[i0] = (int16_t)decompressed;
  }
  return v;
}

/**
A monomorphic instance of
libcrux_ml_kem.vector.portable.{(libcrux_ml_kem::vector::traits::Operations␣for␣libcrux_ml_kem::vector::portable::vector_type::PortableVector)}.decompress_ciphertext_coefficient
with const generics:
- COEFFICIENT_BITS = 5
*/
static libcrux_ml_kem_vector_portable_vector_type_PortableVector
decompress_ciphertext_coefficient_c80(
    libcrux_ml_kem_vector_portable_vector_type_PortableVector v) {
  return decompress_ciphertext_coefficient_c8(v);
}

/**
A monomorphic instance of libcrux_ml_kem.serialize.deserialize_then_decompress_5
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    deserialize_then_decompress_5_24(Eurydice_slice serialized) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      re = ZERO_24();
  for (size_t i = (size_t)0U;
       i <
       core_slice___Slice_T___len(serialized, uint8_t, size_t) / (size_t)10U;
       i++) {
    size_t i0 = i;
    Eurydice_slice bytes = Eurydice_slice_subslice2(
        serialized, i0 * (size_t)10U, i0 * (size_t)10U + (size_t)10U, uint8_t,
        Eurydice_slice);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_5(
            bytes);
    re.coefficients[i0] = uu____0;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____1 =
        decompress_ciphertext_coefficient_c80(re.coefficients[i0]);
    re.coefficients[i0] = uu____1;
  }
  return re;
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_then_decompress_ring_element_v with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- COMPRESSION_FACTOR = 5
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    deserialize_then_decompress_ring_element_v_e2(Eurydice_slice serialized) {
  return deserialize_then_decompress_5_24(serialized);
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@0]}.subtract_reduce
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    subtract_reduce_24(
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *self,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            b) {
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector
        coefficient_normal_form =
            libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___montgomery_multiply_by_constant(
                b.coefficients[i0], (int16_t)1441);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___barrett_reduce(
            libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___sub(
                self->coefficients[i0], &coefficient_normal_form));
    b.coefficients[i0] = uu____0;
  }
  return b;
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_message with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    compute_message_eb(
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *v,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *secret_as_ntt,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *u_as_ntt) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result = ZERO_24();
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(&secret_as_ntt[i0], &u_as_ntt[i0]);
      add_to_ring_element_eb(&result, &product););
  invert_ntt_montgomery_eb(&result);
  result = subtract_reduce_24(v, result);
  return result;
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.compress_then_serialize_message with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compress_then_serialize_message_24(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        re,
    uint8_t ret[32U]) {
  uint8_t serialized[32U] = {0U};
  KRML_MAYBE_FOR16(
      i, (size_t)0U, (size_t)16U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_vector_portable_vector_type_PortableVector coefficient =
          to_unsigned_representative_24(re.coefficients[i0]);
      libcrux_ml_kem_vector_portable_vector_type_PortableVector
          coefficient_compressed =
              libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___compress_1(
                  coefficient);
      uint8_t bytes[2U];
      libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_1(
          coefficient_compressed, bytes);
      Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
          serialized, (size_t)2U * i0, (size_t)2U * i0 + (size_t)2U, uint8_t,
          Eurydice_slice);
      core_slice___Slice_T___copy_from_slice(
          uu____0,
          Eurydice_array_to_slice((size_t)2U, bytes, uint8_t, Eurydice_slice),
          uint8_t, void *););
  memcpy(ret, serialized, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.decrypt_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
- CIPHERTEXT_SIZE = 1568
- VECTOR_U_ENCODED_SIZE = 1408
- U_COMPRESSION_FACTOR = 11
- V_COMPRESSION_FACTOR = 5
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void decrypt_unpacked_ec(
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
        *secret_key,
    uint8_t *ciphertext, uint8_t ret[32U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      u_as_ntt[4U];
  deserialize_then_decompress_u_ec(ciphertext, u_as_ntt);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      v = deserialize_then_decompress_ring_element_v_e2(
          Eurydice_array_to_subslice_from((size_t)1568U, ciphertext,
                                          (size_t)1408U, uint8_t, size_t,
                                          Eurydice_slice));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      message = compute_message_eb(&v, secret_key->secret_as_ntt, u_as_ntt);
  uint8_t ret0[32U];
  compress_then_serialize_message_24(message, ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.hash_functions.portable.PRF with const
generics:
- LEN = 32
*/
static KRML_MUSTINLINE void PRF_5b(Eurydice_slice input, uint8_t ret[32U]) {
  uint8_t digest[32U] = {0U};
  libcrux_sha3_portable_shake256(
      Eurydice_array_to_slice((size_t)32U, digest, uint8_t, Eurydice_slice),
      input);
  memcpy(ret, digest, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.PRF
with const generics:
- K = 4
- LEN = 32
*/
static KRML_MUSTINLINE void PRF_f8(Eurydice_slice input, uint8_t ret[32U]) {
  PRF_5b(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.decapsulate_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]] and with const
generics:
- K = 4
- SECRET_KEY_SIZE = 3168
- CPA_SECRET_KEY_SIZE = 1536
- PUBLIC_KEY_SIZE = 1568
- CIPHERTEXT_SIZE = 1568
- T_AS_NTT_ENCODED_SIZE = 1536
- C1_SIZE = 1408
- C2_SIZE = 160
- VECTOR_U_COMPRESSION_FACTOR = 11
- VECTOR_V_COMPRESSION_FACTOR = 5
- C1_BLOCK_SIZE = 352
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
- IMPLICIT_REJECTION_HASH_INPUT_SIZE = 1600
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
void libcrux_ml_kem_ind_cca_decapsulate_unpacked_23(
    libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
        *key_pair,
    libcrux_ml_kem_mlkem1024_MlKem1024Ciphertext *ciphertext,
    uint8_t ret[32U]) {
  uint8_t decrypted[32U];
  decrypt_unpacked_ec(&key_pair->private_key.ind_cpa_private_key,
                      ciphertext->value, decrypted);
  uint8_t to_hash0[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, decrypted, uint8_t, Eurydice_slice),
      to_hash0);
  Eurydice_slice uu____0 = Eurydice_array_to_subslice_from(
      (size_t)64U, to_hash0, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
      uint8_t, size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)32U, key_pair->public_key.public_key_hash,
                              uint8_t, Eurydice_slice),
      uint8_t, void *);
  uint8_t hashed[64U];
  G_c3(Eurydice_array_to_slice((size_t)64U, to_hash0, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret = uu____1.fst;
  Eurydice_slice pseudorandomness = uu____1.snd;
  uint8_t to_hash[1600U];
  libcrux_ml_kem_utils_into_padded_array_cd(
      Eurydice_array_to_slice((size_t)32U,
                              key_pair->private_key.implicit_rejection_value,
                              uint8_t, Eurydice_slice),
      to_hash);
  Eurydice_slice uu____2 = Eurydice_array_to_subslice_from(
      (size_t)1600U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
      uint8_t, size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____2,
      libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_a7(
          ciphertext),
      uint8_t, void *);
  uint8_t implicit_rejection_shared_secret[32U];
  PRF_f8(
      Eurydice_array_to_slice((size_t)1600U, to_hash, uint8_t, Eurydice_slice),
      implicit_rejection_shared_secret);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      *uu____3 = &key_pair->public_key.ind_cpa_public_key;
  uint8_t uu____4[32U];
  memcpy(uu____4, decrypted, (size_t)32U * sizeof(uint8_t));
  uint8_t expected_ciphertext[1568U];
  encrypt_unpacked_23(uu____3, uu____4, pseudorandomness, expected_ciphertext);
  uint8_t selector =
      libcrux_ml_kem_constant_time_ops_compare_ciphertexts_in_constant_time(
          libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_a7(
              ciphertext),
          Eurydice_array_to_slice((size_t)1568U, expected_ciphertext, uint8_t,
                                  Eurydice_slice));
  uint8_t ret0[32U];
  libcrux_ml_kem_constant_time_ops_select_shared_secret_in_constant_time(
      shared_secret,
      Eurydice_array_to_slice((size_t)32U, implicit_rejection_shared_secret,
                              uint8_t, Eurydice_slice),
      selector, ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_to_uncompressed_ring_element with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector Furthermore, this
instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    deserialize_to_uncompressed_ring_element_24(Eurydice_slice serialized) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      re = ZERO_24();
  for (size_t i = (size_t)0U;
       i <
       core_slice___Slice_T___len(serialized, uint8_t, size_t) / (size_t)24U;
       i++) {
    size_t i0 = i;
    Eurydice_slice bytes = Eurydice_slice_subslice2(
        serialized, i0 * (size_t)24U, i0 * (size_t)24U + (size_t)24U, uint8_t,
        Eurydice_slice);
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___deserialize_12(
            bytes);
    re.coefficients[i0] = uu____0;
  }
  return re;
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.deserialize_secret_key with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_secret_key_eb(
    Eurydice_slice secret_key,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[4U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      secret_as_ntt[4U];
  KRML_MAYBE_FOR4(i, (size_t)0U, (size_t)4U, (size_t)1U,
                  secret_as_ntt[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(secret_key, uint8_t, size_t) /
               LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT;
       i++) {
    size_t i0 = i;
    Eurydice_slice secret_bytes = Eurydice_slice_subslice2(
        secret_key, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT +
            LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_to_uncompressed_ring_element_24(secret_bytes);
    secret_as_ntt[i0] = uu____0;
  }
  memcpy(
      ret, secret_as_ntt,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.decrypt with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 4
- CIPHERTEXT_SIZE = 1568
- VECTOR_U_ENCODED_SIZE = 1408
- U_COMPRESSION_FACTOR = 11
- V_COMPRESSION_FACTOR = 5
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void decrypt_ec(Eurydice_slice secret_key, uint8_t *ciphertext,
                       uint8_t ret[32U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      secret_as_ntt[4U];
  deserialize_secret_key_eb(secret_key, secret_as_ntt);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____0[4U];
  memcpy(
      uu____0, secret_as_ntt,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__4size_t
      secret_key_unpacked;
  memcpy(
      secret_key_unpacked.secret_as_ntt, uu____0,
      (size_t)4U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t ret0[32U];
  decrypt_unpacked_ec(&secret_key_unpacked, ciphertext, ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.decapsulate with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$4size_t]],
libcrux_ml_kem_ind_cca_MlKem and with const generics:
- K = 4
- SECRET_KEY_SIZE = 3168
- CPA_SECRET_KEY_SIZE = 1536
- PUBLIC_KEY_SIZE = 1568
- CIPHERTEXT_SIZE = 1568
- T_AS_NTT_ENCODED_SIZE = 1536
- C1_SIZE = 1408
- C2_SIZE = 160
- VECTOR_U_COMPRESSION_FACTOR = 11
- VECTOR_V_COMPRESSION_FACTOR = 5
- C1_BLOCK_SIZE = 352
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
- IMPLICIT_REJECTION_HASH_INPUT_SIZE = 1600
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::ind_cca::Variant for libcrux_ml_kem::ind_cca::MlKem)}
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
void libcrux_ml_kem_ind_cca_decapsulate_12(
    libcrux_ml_kem_types_MlKemPrivateKey____3168size_t *private_key,
    libcrux_ml_kem_mlkem1024_MlKem1024Ciphertext *ciphertext,
    uint8_t ret[32U]) {
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____0 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)3168U, private_key->value, uint8_t,
                                  Eurydice_slice),
          (size_t)1536U, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice ind_cpa_secret_key = uu____0.fst;
  Eurydice_slice secret_key0 = uu____0.snd;
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          secret_key0, (size_t)1568U, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice ind_cpa_public_key = uu____1.fst;
  Eurydice_slice secret_key = uu____1.snd;
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____2 =
      core_slice___Slice_T___split_at(
          secret_key, LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice ind_cpa_public_key_hash = uu____2.fst;
  Eurydice_slice implicit_rejection_value = uu____2.snd;
  uint8_t decrypted[32U];
  decrypt_ec(ind_cpa_secret_key, ciphertext->value, decrypted);
  uint8_t to_hash0[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, decrypted, uint8_t, Eurydice_slice),
      to_hash0);
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice_from(
          (size_t)64U, to_hash0, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
          uint8_t, size_t, Eurydice_slice),
      ind_cpa_public_key_hash, uint8_t, void *);
  uint8_t hashed[64U];
  G_c3(Eurydice_array_to_slice((size_t)64U, to_hash0, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____3 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret0 = uu____3.fst;
  Eurydice_slice pseudorandomness = uu____3.snd;
  uint8_t to_hash[1600U];
  libcrux_ml_kem_utils_into_padded_array_cd(implicit_rejection_value, to_hash);
  Eurydice_slice uu____4 = Eurydice_array_to_subslice_from(
      (size_t)1600U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
      uint8_t, size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____4,
      libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_a7(
          ciphertext),
      uint8_t, void *);
  uint8_t implicit_rejection_shared_secret0[32U];
  PRF_f8(
      Eurydice_array_to_slice((size_t)1600U, to_hash, uint8_t, Eurydice_slice),
      implicit_rejection_shared_secret0);
  Eurydice_slice uu____5 = ind_cpa_public_key;
  uint8_t uu____6[32U];
  memcpy(uu____6, decrypted, (size_t)32U * sizeof(uint8_t));
  uint8_t expected_ciphertext[1568U];
  encrypt_23(uu____5, uu____6, pseudorandomness, expected_ciphertext);
  uint8_t implicit_rejection_shared_secret[32U];
  kdf_43(Eurydice_array_to_slice((size_t)32U, implicit_rejection_shared_secret0,
                                 uint8_t, Eurydice_slice),
         implicit_rejection_shared_secret);
  uint8_t shared_secret[32U];
  kdf_43(shared_secret0, shared_secret);
  uint8_t ret0[32U];
  libcrux_ml_kem_constant_time_ops_compare_ciphertexts_select_shared_secret_in_constant_time(
      libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_a7(
          ciphertext),
      Eurydice_array_to_slice((size_t)1568U, expected_ciphertext, uint8_t,
                              Eurydice_slice),
      Eurydice_array_to_slice((size_t)32U, shared_secret, uint8_t,
                              Eurydice_slice),
      Eurydice_array_to_slice((size_t)32U, implicit_rejection_shared_secret,
                              uint8_t, Eurydice_slice),
      ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_ring_elements_reduced with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- PUBLIC_KEY_SIZE = 800
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_ring_elements_reduced_b2(
    Eurydice_slice public_key,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[2U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      deserialized_pk[2U];
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U,
                  deserialized_pk[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(public_key, uint8_t, size_t) /
               LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT;
       i++) {
    size_t i0 = i;
    Eurydice_slice ring_element = Eurydice_slice_subslice2(
        public_key, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT +
            LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_to_reduced_ring_element_24(ring_element);
    deserialized_pk[i0] = uu____0;
  }
  memcpy(
      ret, deserialized_pk,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.serialize_secret_key with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
- OUT_LEN = 768
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void serialize_secret_key_33(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *key,
    uint8_t ret[768U]) {
  uint8_t out[768U] = {0U};
  for (
      size_t i = (size_t)0U;
      i <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)2U, key,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
          size_t);
      i++) {
    size_t i0 = i;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        re = key[i0];
    Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
        out, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        (i0 + (size_t)1U) * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    uint8_t ret0[384U];
    serialize_uncompressed_ring_element_24(&re, ret0);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)384U, ret0, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
  memcpy(ret, out, (size_t)768U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.serialize_public_key with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
- RANKED_BYTES_PER_RING_ELEMENT = 768
- PUBLIC_KEY_SIZE = 800
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void serialize_public_key_6b(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *t_as_ntt,
    Eurydice_slice seed_for_a, uint8_t ret[800U]) {
  uint8_t public_key_serialized[800U] = {0U};
  Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
      public_key_serialized, (size_t)0U, (size_t)768U, uint8_t, Eurydice_slice);
  uint8_t ret0[768U];
  serialize_secret_key_33(t_as_ntt, ret0);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)768U, ret0, uint8_t, Eurydice_slice),
      uint8_t, void *);
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice_from((size_t)800U, public_key_serialized,
                                      (size_t)768U, uint8_t, size_t,
                                      Eurydice_slice),
      seed_for_a, uint8_t, void *);
  memcpy(ret, public_key_serialized, (size_t)800U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.validate_public_key with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
- RANKED_BYTES_PER_RING_ELEMENT = 768
- PUBLIC_KEY_SIZE = 800
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
bool libcrux_ml_kem_ind_cca_validate_public_key_6b(uint8_t *public_key) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      deserialized_pk[2U];
  deserialize_ring_elements_reduced_b2(
      Eurydice_array_to_subslice_to((size_t)800U, public_key, (size_t)768U,
                                    uint8_t, size_t, Eurydice_slice),
      deserialized_pk);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      *uu____0 = deserialized_pk;
  uint8_t public_key_serialized[800U];
  serialize_public_key_6b(
      uu____0,
      Eurydice_array_to_subslice_from((size_t)800U, public_key, (size_t)768U,
                                      uint8_t, size_t, Eurydice_slice),
      public_key_serialized);
  return core_array_equality___core__cmp__PartialEq__Array_U__N___for__Array_T__N____eq(
      (size_t)800U, public_key, public_key_serialized, uint8_t, uint8_t, bool);
}

typedef struct
    __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t___s {
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      fst;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      snd;
} __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t__;

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.G
with const generics:
- K = 2
*/
static KRML_MUSTINLINE void G_e3(Eurydice_slice input, uint8_t ret[64U]) {
  libcrux_ml_kem_hash_functions_portable_G(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.sample_matrix_A.closure with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void closure_9f(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[2U]) {
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U, ret[i] = ZERO_24(););
}

typedef struct PortableHash____2size_t_s {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t shake128_state[2U];
} PortableHash____2size_t;

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.shake128_init_absorb with const generics:
- K = 2
*/
static KRML_MUSTINLINE PortableHash____2size_t
shake128_init_absorb_e3(uint8_t input[2U][34U]) {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t shake128_state[2U];
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U,
      shake128_state[i] = libcrux_sha3_portable_incremental_shake128_init(););
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
                  libcrux_sha3_portable_incremental_shake128_absorb_final(
                      &shake128_state[i0],
                      Eurydice_array_to_slice((size_t)34U, input[i0], uint8_t,
                                              Eurydice_slice)););
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t uu____0[2U];
  memcpy(
      uu____0, shake128_state,
      (size_t)2U *
          sizeof(libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t));
  PortableHash____2size_t lit;
  memcpy(
      lit.shake128_state, uu____0,
      (size_t)2U *
          sizeof(libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t));
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.shake128_init_absorb
with const generics:
- K = 2
*/
static KRML_MUSTINLINE PortableHash____2size_t
shake128_init_absorb_e30(uint8_t input[2U][34U]) {
  uint8_t uu____0[2U][34U];
  memcpy(uu____0, input, (size_t)2U * sizeof(uint8_t[34U]));
  return shake128_init_absorb_e3(uu____0);
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.shake128_squeeze_three_blocks with const
generics:
- K = 2
*/
static KRML_MUSTINLINE void shake128_squeeze_three_blocks_e3(
    PortableHash____2size_t *st, uint8_t ret[2U][504U]) {
  uint8_t out[2U][504U] = {{0U}};
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      libcrux_sha3_portable_incremental_shake128_squeeze_first_three_blocks(
          &st->shake128_state[i0],
          Eurydice_array_to_slice((size_t)504U, out[i0], uint8_t,
                                  Eurydice_slice)););
  memcpy(ret, out, (size_t)2U * sizeof(uint8_t[504U]));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.shake128_squeeze_three_blocks
with const generics:
- K = 2
*/
static KRML_MUSTINLINE void shake128_squeeze_three_blocks_e30(
    PortableHash____2size_t *self, uint8_t ret[2U][504U]) {
  shake128_squeeze_three_blocks_e3(self, ret);
}

/**
A monomorphic instance of
libcrux_ml_kem.sampling.sample_from_uniform_distribution_next with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
- N = 504
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE bool sample_from_uniform_distribution_next_4b(
    uint8_t randomness[2U][504U], size_t *sampled_coefficients,
    int16_t (*out)[272U]) {
  KRML_MAYBE_FOR2(
      i0, (size_t)0U, (size_t)2U, (size_t)1U, size_t i1 = i0;
      for (size_t i = (size_t)0U; i < (size_t)504U / (size_t)24U; i++) {
        size_t r = i;
        if (sampled_coefficients[i1] <
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
          Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
              randomness[i1], r * (size_t)24U, r * (size_t)24U + (size_t)24U,
              uint8_t, Eurydice_slice);
          size_t sampled =
              libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___rej_sample(
                  uu____0, Eurydice_array_to_subslice2(
                               out[i1], sampled_coefficients[i1],
                               sampled_coefficients[i1] + (size_t)16U, int16_t,
                               Eurydice_slice));
          size_t uu____1 = i1;
          sampled_coefficients[uu____1] =
              sampled_coefficients[uu____1] + sampled;
        }
      });
  bool done = true;
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      if (sampled_coefficients[i0] >=
          LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
        sampled_coefficients[i0] =
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT;
      } else { done = false; });
  return done;
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.shake128_squeeze_block with const
generics:
- K = 2
*/
static KRML_MUSTINLINE void shake128_squeeze_block_e3(
    PortableHash____2size_t *st, uint8_t ret[2U][168U]) {
  uint8_t out[2U][168U] = {{0U}};
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
                  libcrux_sha3_portable_incremental_shake128_squeeze_next_block(
                      &st->shake128_state[i0],
                      Eurydice_array_to_slice((size_t)168U, out[i0], uint8_t,
                                              Eurydice_slice)););
  memcpy(ret, out, (size_t)2U * sizeof(uint8_t[168U]));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.shake128_squeeze_block
with const generics:
- K = 2
*/
static KRML_MUSTINLINE void shake128_squeeze_block_e30(
    PortableHash____2size_t *self, uint8_t ret[2U][168U]) {
  shake128_squeeze_block_e3(self, ret);
}

/**
A monomorphic instance of
libcrux_ml_kem.sampling.sample_from_uniform_distribution_next with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
- N = 168
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE bool sample_from_uniform_distribution_next_fc(
    uint8_t randomness[2U][168U], size_t *sampled_coefficients,
    int16_t (*out)[272U]) {
  KRML_MAYBE_FOR2(
      i0, (size_t)0U, (size_t)2U, (size_t)1U, size_t i1 = i0;
      for (size_t i = (size_t)0U; i < (size_t)168U / (size_t)24U; i++) {
        size_t r = i;
        if (sampled_coefficients[i1] <
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
          Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
              randomness[i1], r * (size_t)24U, r * (size_t)24U + (size_t)24U,
              uint8_t, Eurydice_slice);
          size_t sampled =
              libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___rej_sample(
                  uu____0, Eurydice_array_to_subslice2(
                               out[i1], sampled_coefficients[i1],
                               sampled_coefficients[i1] + (size_t)16U, int16_t,
                               Eurydice_slice));
          size_t uu____1 = i1;
          sampled_coefficients[uu____1] =
              sampled_coefficients[uu____1] + sampled;
        }
      });
  bool done = true;
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      if (sampled_coefficients[i0] >=
          LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
        sampled_coefficients[i0] =
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT;
      } else { done = false; });
  return done;
}

/**
A monomorphic instance of libcrux_ml_kem.sampling.sample_from_xof.closure with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
closure_9f1(int16_t s[272U]) {
  return from_i16_array_24(Eurydice_array_to_subslice2(
      s, (size_t)0U, (size_t)256U, int16_t, Eurydice_slice));
}

/**
A monomorphic instance of libcrux_ml_kem.sampling.sample_from_xof with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void sample_from_xof_9f(
    uint8_t seeds[2U][34U],
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[2U]) {
  size_t sampled_coefficients[2U] = {0U};
  int16_t out[2U][272U] = {{0U}};
  uint8_t uu____0[2U][34U];
  memcpy(uu____0, seeds, (size_t)2U * sizeof(uint8_t[34U]));
  PortableHash____2size_t xof_state = shake128_init_absorb_e30(uu____0);
  uint8_t randomness0[2U][504U];
  shake128_squeeze_three_blocks_e30(&xof_state, randomness0);
  uint8_t uu____1[2U][504U];
  memcpy(uu____1, randomness0, (size_t)2U * sizeof(uint8_t[504U]));
  bool done = sample_from_uniform_distribution_next_4b(
      uu____1, sampled_coefficients, out);
  while (true) {
    if (done) {
      break;
    } else {
      uint8_t randomness[2U][168U];
      shake128_squeeze_block_e30(&xof_state, randomness);
      uint8_t uu____2[2U][168U];
      memcpy(uu____2, randomness, (size_t)2U * sizeof(uint8_t[168U]));
      done = sample_from_uniform_distribution_next_fc(
          uu____2, sampled_coefficients, out);
    }
  }
  int16_t uu____3[2U][272U];
  memcpy(uu____3, out, (size_t)2U * sizeof(int16_t[272U]));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      ret0[2U];
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U,
                  ret0[i] = closure_9f1(uu____3[i]););
  memcpy(
      ret, ret0,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.sample_matrix_A with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void sample_matrix_A_9f(
    uint8_t seed[34U], bool transpose,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[2U][2U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A_transpose[2U][2U];
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U,
                  closure_9f(A_transpose[i]););
  KRML_MAYBE_FOR2(
      i0, (size_t)0U, (size_t)2U, (size_t)1U, size_t i1 = i0;
      uint8_t uu____0[34U];
      memcpy(uu____0, seed, (size_t)34U * sizeof(uint8_t));
      uint8_t seeds[2U][34U]; KRML_MAYBE_FOR2(
          i, (size_t)0U, (size_t)2U, (size_t)1U,
          memcpy(seeds[i], uu____0, (size_t)34U * sizeof(uint8_t)););
      KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U, size_t j = i;
                      seeds[j][32U] = (uint8_t)i1; seeds[j][33U] = (uint8_t)j;);
      uint8_t uu____1[2U][34U];
      memcpy(uu____1, seeds, (size_t)2U * sizeof(uint8_t[34U]));
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          sampled[2U];
      sample_from_xof_9f(uu____1, sampled); for (
          size_t i = (size_t)0U;
          i <
          core_slice___Slice_T___len(
              Eurydice_array_to_slice(
                  (size_t)2U, sampled,
                  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                  Eurydice_slice),
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
              size_t);
          i++) {
        size_t j = i;
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            sample = sampled[j];
        if (transpose) {
          A_transpose[j][i1] = sample;
        } else {
          A_transpose[i1][j] = sample;
        }
      });
  memcpy(
      ret, A_transpose,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [2U]));
}

typedef struct
    __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_2size_t__uint8_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      fst[2U];
  uint8_t snd;
} __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_2size_t__uint8_t;

/**
A monomorphic instance of libcrux_ml_kem.hash_functions.portable.PRFxN with
const generics:
- K = 2
- LEN = 192
*/
static KRML_MUSTINLINE void PRFxN_52(uint8_t (*input)[33U],
                                     uint8_t ret[2U][192U]) {
  uint8_t out[2U][192U] = {{0U}};
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
                  libcrux_sha3_portable_shake256(
                      Eurydice_array_to_slice((size_t)192U, out[i0], uint8_t,
                                              Eurydice_slice),
                      Eurydice_array_to_slice((size_t)33U, input[i0], uint8_t,
                                              Eurydice_slice)););
  memcpy(ret, out, (size_t)2U * sizeof(uint8_t[192U]));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.PRFxN
with const generics:
- K = 2
- LEN = 192
*/
static KRML_MUSTINLINE void PRFxN_520(uint8_t (*input)[33U],
                                      uint8_t ret[2U][192U]) {
  PRFxN_52(input, ret);
}

/**
A monomorphic instance of
libcrux_ml_kem.sampling.sample_from_binomial_distribution with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- ETA = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    sample_from_binomial_distribution_0e(Eurydice_slice randomness) {
  return sample_from_binomial_distribution_3_24(randomness);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.sample_vector_cbd_then_ntt with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
- ETA = 3
- ETA_RANDOMNESS_SIZE = 192
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_2size_t__uint8_t
    sample_vector_cbd_then_ntt_60(uint8_t prf_input[33U],
                                  uint8_t domain_separator) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      re_as_ntt[2U];
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U,
                  re_as_ntt[i] = ZERO_24(););
  uint8_t uu____0[33U];
  memcpy(uu____0, prf_input, (size_t)33U * sizeof(uint8_t));
  uint8_t prf_inputs[2U][33U];
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U,
      memcpy(prf_inputs[i], uu____0, (size_t)33U * sizeof(uint8_t)););
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
                  prf_inputs[i0][32U] = domain_separator;
                  domain_separator = (uint32_t)domain_separator + 1U;);
  uint8_t prf_outputs[2U][192U];
  PRFxN_520(prf_inputs, prf_outputs);
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          uu____1 =
              sample_from_binomial_distribution_0e(Eurydice_array_to_slice(
                  (size_t)192U, prf_outputs[i0], uint8_t, Eurydice_slice));
      re_as_ntt[i0] = uu____1;
      ntt_binomially_sampled_ring_element_24(&re_as_ntt[i0]););
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____2[2U];
  memcpy(
      uu____2, re_as_ntt,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_2size_t__uint8_t
      lit;
  memcpy(
      lit.fst, uu____2,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  lit.snd = domain_separator;
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@0]}.add_to_ring_element
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with
const generics:
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void add_to_ring_element_c0(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *rhs) {
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(
               Eurydice_array_to_slice(
                   (size_t)16U, self->coefficients,
                   libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                   Eurydice_slice),
               libcrux_ml_kem_vector_portable_vector_type_PortableVector,
               size_t);
       i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
            self->coefficients[i0], &rhs->coefficients[i0]);
    self->coefficients[i0] = uu____0;
  }
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_As_plus_e with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compute_As_plus_e_c0(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector (
        *matrix_A)[2U],
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *s_as_ntt,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *error_as_ntt,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[2U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result[2U];
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U,
                  result[i] = ZERO_24(););
  for (
      size_t i0 = (size_t)0U;
      i0 <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)2U, matrix_A,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [2U],
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
              [2U],
          size_t);
      i0++) {
    size_t i1 = i0;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *row = matrix_A[i1];
    for (
        size_t i = (size_t)0U;
        i <
        core_slice___Slice_T___len(
            Eurydice_array_to_slice(
                (size_t)2U, row,
                libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                Eurydice_slice),
            libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
            size_t);
        i++) {
      size_t j = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          *matrix_element = &row[j];
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(matrix_element, &s_as_ntt[j]);
      add_to_ring_element_c0(&result[i1], &product);
    }
    add_standard_error_reduce_24(&result[i1], &error_as_ntt[i1]);
  }
  memcpy(
      ret, result,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.generate_keypair_unpacked with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
- ETA1 = 3
- ETA1_RANDOMNESS_SIZE = 192
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t__
generate_keypair_unpacked_60(Eurydice_slice key_generation_seed) {
  uint8_t hashed[64U];
  G_e3(key_generation_seed, hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____0 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          (size_t)32U, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice seed_for_A0 = uu____0.fst;
  Eurydice_slice seed_for_secret_and_error = uu____0.snd;
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A_transpose[2U][2U];
  uint8_t ret[34U];
  libcrux_ml_kem_utils_into_padded_array_fe(seed_for_A0, ret);
  sample_matrix_A_9f(ret, true, A_transpose);
  uint8_t prf_input[33U];
  libcrux_ml_kem_utils_into_padded_array_cb(seed_for_secret_and_error,
                                            prf_input);
  uint8_t uu____1[33U];
  memcpy(uu____1, prf_input, (size_t)33U * sizeof(uint8_t));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_2size_t__uint8_t
      uu____2 = sample_vector_cbd_then_ntt_60(uu____1, 0U);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      secret_as_ntt[2U];
  memcpy(
      secret_as_ntt, uu____2.fst,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t domain_separator = uu____2.snd;
  uint8_t uu____3[33U];
  memcpy(uu____3, prf_input, (size_t)33U * sizeof(uint8_t));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_as_ntt[2U];
  memcpy(
      error_as_ntt,
      sample_vector_cbd_then_ntt_60(uu____3, domain_separator).fst,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      t_as_ntt[2U];
  compute_As_plus_e_c0(A_transpose, secret_as_ntt, error_as_ntt, t_as_ntt);
  uint8_t seed_for_A[32U];
  core_result_Result__uint8_t_32size_t__core_array_TryFromSliceError dst;
  Eurydice_slice_to_array2(&dst, seed_for_A0, Eurydice_slice, uint8_t[32U],
                           void *);
  core_result__core__result__Result_T__E___unwrap_fb(dst, seed_for_A);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____4[2U];
  memcpy(
      uu____4, t_as_ntt,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____5[2U][2U];
  memcpy(
      uu____5, A_transpose,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [2U]));
  uint8_t uu____6[32U];
  memcpy(uu____6, seed_for_A, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      pk;
  memcpy(
      pk.t_as_ntt, uu____4,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  memcpy(pk.seed_for_A, uu____6, (size_t)32U * sizeof(uint8_t));
  memcpy(
      pk.A, uu____5,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [2U]));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____7[2U];
  memcpy(
      uu____7, secret_as_ntt,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      sk;
  memcpy(
      sk.secret_as_ntt, uu____7,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  return (CLITERAL(
      __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t__){
      .fst = sk, .snd = pk});
}

/**
A monomorphic instance of
libcrux_ml_kem.ind_cca.generate_keypair_unpacked.closure with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
- CPA_PRIVATE_KEY_SIZE = 768
- PRIVATE_KEY_SIZE = 1632
- PUBLIC_KEY_SIZE = 800
- BYTES_PER_RING_ELEMENT = 768
- ETA1 = 3
- ETA1_RANDOMNESS_SIZE = 192
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void closure_60(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[2U]) {
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U, ret[i] = ZERO_24(););
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.H
with const generics:
- K = 2
*/
static KRML_MUSTINLINE void H_e3(Eurydice_slice input, uint8_t ret[32U]) {
  libcrux_ml_kem_hash_functions_portable_H(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.generate_keypair_unpacked with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
- CPA_PRIVATE_KEY_SIZE = 768
- PRIVATE_KEY_SIZE = 1632
- PUBLIC_KEY_SIZE = 800
- BYTES_PER_RING_ELEMENT = 768
- ETA1 = 3
- ETA1_RANDOMNESS_SIZE = 192
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
libcrux_ml_kem_ind_cca_generate_keypair_unpacked_60(uint8_t randomness[64U]) {
  Eurydice_slice ind_cpa_keypair_randomness = Eurydice_array_to_subslice2(
      randomness, (size_t)0U,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      Eurydice_slice);
  Eurydice_slice implicit_rejection_value0 = Eurydice_array_to_subslice_from(
      (size_t)64U, randomness,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      size_t, Eurydice_slice);
  __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t__
      uu____0 = generate_keypair_unpacked_60(ind_cpa_keypair_randomness);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      ind_cpa_private_key = uu____0.fst;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      ind_cpa_public_key = uu____0.snd;
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A[2U][2U];
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U, closure_60(A[i]););
  KRML_MAYBE_FOR2(
      i0, (size_t)0U, (size_t)2U, (size_t)1U, size_t i1 = i0; KRML_MAYBE_FOR2(
          i, (size_t)0U, (size_t)2U, (size_t)1U, size_t j = i;
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
              uu____1 = clone_24(&ind_cpa_public_key.A[j][i1]);
          A[i1][j] = uu____1;););
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____2[2U][2U];
  memcpy(
      uu____2, A,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [2U]));
  memcpy(
      ind_cpa_public_key.A, uu____2,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [2U]));
  uint8_t pk_serialized[800U];
  serialize_public_key_6b(
      ind_cpa_public_key.t_as_ntt,
      Eurydice_array_to_slice((size_t)32U, ind_cpa_public_key.seed_for_A,
                              uint8_t, Eurydice_slice),
      pk_serialized);
  uint8_t public_key_hash[32U];
  H_e3(Eurydice_array_to_slice((size_t)800U, pk_serialized, uint8_t,
                               Eurydice_slice),
       public_key_hash);
  uint8_t implicit_rejection_value[32U];
  core_result_Result__uint8_t_32size_t__core_array_TryFromSliceError dst;
  Eurydice_slice_to_array2(&dst, implicit_rejection_value0, Eurydice_slice,
                           uint8_t[32U], void *);
  core_result__core__result__Result_T__E___unwrap_fb(dst,
                                                     implicit_rejection_value);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      uu____3 = ind_cpa_private_key;
  uint8_t uu____4[32U];
  memcpy(uu____4, implicit_rejection_value, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      uu____5;
  uu____5.ind_cpa_private_key = uu____3;
  memcpy(uu____5.implicit_rejection_value, uu____4,
         (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      uu____6 = ind_cpa_public_key;
  uint8_t uu____7[32U];
  memcpy(uu____7, public_key_hash, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      lit;
  lit.private_key = uu____5;
  lit.public_key.ind_cpa_public_key = uu____6;
  memcpy(lit.public_key.public_key_hash, uu____7,
         (size_t)32U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.generate_keypair with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
- PRIVATE_KEY_SIZE = 768
- PUBLIC_KEY_SIZE = 800
- RANKED_BYTES_PER_RING_ELEMENT = 768
- ETA1 = 3
- ETA1_RANDOMNESS_SIZE = 192
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static libcrux_ml_kem_utils_extraction_helper_Keypair512 generate_keypair_60(
    Eurydice_slice key_generation_seed) {
  __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___2size_t__
      uu____0 = generate_keypair_unpacked_60(key_generation_seed);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      sk = uu____0.fst;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      pk = uu____0.snd;
  uint8_t public_key_serialized[800U];
  serialize_public_key_6b(pk.t_as_ntt,
                          Eurydice_array_to_slice((size_t)32U, pk.seed_for_A,
                                                  uint8_t, Eurydice_slice),
                          public_key_serialized);
  uint8_t secret_key_serialized[768U];
  serialize_secret_key_33(sk.secret_as_ntt, secret_key_serialized);
  uint8_t uu____1[768U];
  memcpy(uu____1, secret_key_serialized, (size_t)768U * sizeof(uint8_t));
  uint8_t uu____2[800U];
  memcpy(uu____2, public_key_serialized, (size_t)800U * sizeof(uint8_t));
  libcrux_ml_kem_utils_extraction_helper_Keypair512 lit;
  memcpy(lit.fst, uu____1, (size_t)768U * sizeof(uint8_t));
  memcpy(lit.snd, uu____2, (size_t)800U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.serialize_kem_secret_key with
types libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with
const generics:
- K = 2
- SERIALIZED_KEY_LEN = 1632
*/
static KRML_MUSTINLINE void serialize_kem_secret_key_6d(
    Eurydice_slice private_key, Eurydice_slice public_key,
    Eurydice_slice implicit_rejection_value, uint8_t ret[1632U]) {
  uint8_t out[1632U] = {0U};
  size_t pointer = (size_t)0U;
  uint8_t *uu____0 = out;
  size_t uu____1 = pointer;
  size_t uu____2 = pointer;
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice2(
          uu____0, uu____1,
          uu____2 + core_slice___Slice_T___len(private_key, uint8_t, size_t),
          uint8_t, Eurydice_slice),
      private_key, uint8_t, void *);
  pointer = pointer + core_slice___Slice_T___len(private_key, uint8_t, size_t);
  uint8_t *uu____3 = out;
  size_t uu____4 = pointer;
  size_t uu____5 = pointer;
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice2(
          uu____3, uu____4,
          uu____5 + core_slice___Slice_T___len(public_key, uint8_t, size_t),
          uint8_t, Eurydice_slice),
      public_key, uint8_t, void *);
  pointer = pointer + core_slice___Slice_T___len(public_key, uint8_t, size_t);
  Eurydice_slice uu____6 = Eurydice_array_to_subslice2(
      out, pointer, pointer + LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
      Eurydice_slice);
  uint8_t ret0[32U];
  H_e3(public_key, ret0);
  core_slice___Slice_T___copy_from_slice(
      uu____6,
      Eurydice_array_to_slice((size_t)32U, ret0, uint8_t, Eurydice_slice),
      uint8_t, void *);
  pointer = pointer + LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE;
  uint8_t *uu____7 = out;
  size_t uu____8 = pointer;
  size_t uu____9 = pointer;
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice2(
          uu____7, uu____8,
          uu____9 + core_slice___Slice_T___len(implicit_rejection_value,
                                               uint8_t, size_t),
          uint8_t, Eurydice_slice),
      implicit_rejection_value, uint8_t, void *);
  memcpy(ret, out, (size_t)1632U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.generate_keypair with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
- CPA_PRIVATE_KEY_SIZE = 768
- PRIVATE_KEY_SIZE = 1632
- PUBLIC_KEY_SIZE = 800
- BYTES_PER_RING_ELEMENT = 768
- ETA1 = 3
- ETA1_RANDOMNESS_SIZE = 192
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
libcrux_ml_kem_types_MlKemKeyPair____1632size_t__800size_t
libcrux_ml_kem_ind_cca_generate_keypair_60(uint8_t randomness[64U]) {
  Eurydice_slice ind_cpa_keypair_randomness = Eurydice_array_to_subslice2(
      randomness, (size_t)0U,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      Eurydice_slice);
  Eurydice_slice implicit_rejection_value = Eurydice_array_to_subslice_from(
      (size_t)64U, randomness,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      size_t, Eurydice_slice);
  libcrux_ml_kem_utils_extraction_helper_Keypair512 uu____0 =
      generate_keypair_60(ind_cpa_keypair_randomness);
  uint8_t ind_cpa_private_key[768U];
  memcpy(ind_cpa_private_key, uu____0.fst, (size_t)768U * sizeof(uint8_t));
  uint8_t public_key[800U];
  memcpy(public_key, uu____0.snd, (size_t)800U * sizeof(uint8_t));
  uint8_t secret_key_serialized[1632U];
  serialize_kem_secret_key_6d(
      Eurydice_array_to_slice((size_t)768U, ind_cpa_private_key, uint8_t,
                              Eurydice_slice),
      Eurydice_array_to_slice((size_t)800U, public_key, uint8_t,
                              Eurydice_slice),
      implicit_rejection_value, secret_key_serialized);
  uint8_t uu____1[1632U];
  memcpy(uu____1, secret_key_serialized, (size_t)1632U * sizeof(uint8_t));
  libcrux_ml_kem_types_MlKemPrivateKey____1632size_t private_key =
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPrivateKey_SIZE___8__from_e0(
          uu____1);
  libcrux_ml_kem_types_MlKemPrivateKey____1632size_t uu____2 = private_key;
  uint8_t uu____3[800U];
  memcpy(uu____3, public_key, (size_t)800U * sizeof(uint8_t));
  return libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemKeyPair_PRIVATE_KEY_SIZE__PUBLIC_KEY_SIZE___from_8e0(
      uu____2,
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPublicKey_SIZE___14__from_72(
          uu____3));
}

/**
A monomorphic instance of libcrux_ml_kem.hash_functions.portable.PRFxN with
const generics:
- K = 2
- LEN = 128
*/
static KRML_MUSTINLINE void PRFxN_10(uint8_t (*input)[33U],
                                     uint8_t ret[2U][128U]) {
  uint8_t out[2U][128U] = {{0U}};
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
                  libcrux_sha3_portable_shake256(
                      Eurydice_array_to_slice((size_t)128U, out[i0], uint8_t,
                                              Eurydice_slice),
                      Eurydice_array_to_slice((size_t)33U, input[i0], uint8_t,
                                              Eurydice_slice)););
  memcpy(ret, out, (size_t)2U * sizeof(uint8_t[128U]));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.PRFxN
with const generics:
- K = 2
- LEN = 128
*/
static KRML_MUSTINLINE void PRFxN_100(uint8_t (*input)[33U],
                                      uint8_t ret[2U][128U]) {
  PRFxN_10(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.sample_ring_element_cbd with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
- ETA2_RANDOMNESS_SIZE = 128
- ETA2 = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_2size_t__uint8_t
    sample_ring_element_cbd_60(uint8_t prf_input[33U],
                               uint8_t domain_separator) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_1[2U];
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U,
                  error_1[i] = ZERO_24(););
  uint8_t uu____0[33U];
  memcpy(uu____0, prf_input, (size_t)33U * sizeof(uint8_t));
  uint8_t prf_inputs[2U][33U];
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U,
      memcpy(prf_inputs[i], uu____0, (size_t)33U * sizeof(uint8_t)););
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
                  prf_inputs[i0][32U] = domain_separator;
                  domain_separator = (uint32_t)domain_separator + 1U;);
  uint8_t prf_outputs[2U][128U];
  PRFxN_100(prf_inputs, prf_outputs);
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          uu____1 =
              sample_from_binomial_distribution_c0(Eurydice_array_to_slice(
                  (size_t)128U, prf_outputs[i0], uint8_t, Eurydice_slice));
      error_1[i0] = uu____1;);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____2[2U];
  memcpy(
      uu____2, error_1,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_2size_t__uint8_t
      lit;
  memcpy(
      lit.fst, uu____2,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  lit.snd = domain_separator;
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.PRF
with const generics:
- K = 2
- LEN = 128
*/
static KRML_MUSTINLINE void PRF_10(Eurydice_slice input, uint8_t ret[128U]) {
  PRF_9b(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.invert_ntt.invert_ntt_montgomery with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void invert_ntt_montgomery_c0(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  size_t zeta_i =
      LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT / (size_t)2U;
  invert_ntt_at_layer_1_24(&zeta_i, re);
  invert_ntt_at_layer_2_24(&zeta_i, re);
  invert_ntt_at_layer_3_24(&zeta_i, re);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)4U);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)5U);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)6U);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)7U);
  poly_barrett_reduce_24(re);
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_vector_u with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compute_vector_u_c0(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector (
        *a_as_ntt)[2U],
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *r_as_ntt,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *error_1,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[2U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result[2U];
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U,
                  result[i] = ZERO_24(););
  for (
      size_t i0 = (size_t)0U;
      i0 <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)2U, a_as_ntt,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [2U],
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
              [2U],
          size_t);
      i0++) {
    size_t i1 = i0;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *row = a_as_ntt[i1];
    for (
        size_t i = (size_t)0U;
        i <
        core_slice___Slice_T___len(
            Eurydice_array_to_slice(
                (size_t)2U, row,
                libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                Eurydice_slice),
            libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
            size_t);
        i++) {
      size_t j = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          *a_element = &row[j];
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(a_element, &r_as_ntt[j]);
      add_to_ring_element_c0(&result[i1], &product);
    }
    invert_ntt_montgomery_c0(&result[i1]);
    add_error_reduce_24(&result[i1], &error_1[i1]);
  }
  memcpy(
      ret, result,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_ring_element_v with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    compute_ring_element_v_c0(
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *t_as_ntt,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *r_as_ntt,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *error_2,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *message) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result = ZERO_24();
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(&t_as_ntt[i0], &r_as_ntt[i0]);
      add_to_ring_element_c0(&result, &product););
  invert_ntt_montgomery_c0(&result);
  result = add_message_error_reduce_24(error_2, message, result);
  return result;
}

/**
A monomorphic instance of libcrux_ml_kem.serialize.compress_then_serialize_10
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with
const generics:
- OUT_LEN = 320
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compress_then_serialize_10_b5(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re,
    uint8_t ret[320U]) {
  uint8_t serialized[320U] = {0U};
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector coefficient =
        compress_a50(to_unsigned_representative_24(re->coefficients[i0]));
    uint8_t bytes[20U];
    libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___serialize_10(
        coefficient, bytes);
    Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
        serialized, (size_t)20U * i0, (size_t)20U * i0 + (size_t)20U, uint8_t,
        Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)20U, bytes, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
  memcpy(ret, serialized, (size_t)320U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.compress_then_serialize_ring_element_u with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- COMPRESSION_FACTOR = 10
- OUT_LEN = 320
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compress_then_serialize_ring_element_u_63(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re,
    uint8_t ret[320U]) {
  uint8_t uu____0[320U];
  compress_then_serialize_10_b5(re, uu____0);
  memcpy(ret, uu____0, (size_t)320U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.compress_then_serialize_u with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
- OUT_LEN = 640
- COMPRESSION_FACTOR = 10
- BLOCK_LEN = 320
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void compress_then_serialize_u_0f(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        input[2U],
    Eurydice_slice out) {
  for (
      size_t i = (size_t)0U;
      i <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)2U, input,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
          size_t);
      i++) {
    size_t i0 = i;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        re = input[i0];
    Eurydice_slice uu____0 = Eurydice_slice_subslice2(
        out, i0 * ((size_t)640U / (size_t)2U),
        (i0 + (size_t)1U) * ((size_t)640U / (size_t)2U), uint8_t,
        Eurydice_slice);
    uint8_t ret[320U];
    compress_then_serialize_ring_element_u_63(&re, ret);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)320U, ret, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.compress_then_serialize_ring_element_v with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- COMPRESSION_FACTOR = 4
- OUT_LEN = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compress_then_serialize_ring_element_v_6c(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        re,
    Eurydice_slice out) {
  compress_then_serialize_4_24(re, out);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.encrypt_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
- CIPHERTEXT_SIZE = 768
- T_AS_NTT_ENCODED_SIZE = 768
- C1_LEN = 640
- C2_LEN = 128
- U_COMPRESSION_FACTOR = 10
- V_COMPRESSION_FACTOR = 4
- BLOCK_LEN = 320
- ETA1 = 3
- ETA1_RANDOMNESS_SIZE = 192
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void encrypt_unpacked_60(
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
        *public_key,
    uint8_t message[32U], Eurydice_slice randomness, uint8_t ret[768U]) {
  uint8_t prf_input[33U];
  libcrux_ml_kem_utils_into_padded_array_cb(randomness, prf_input);
  uint8_t uu____0[33U];
  memcpy(uu____0, prf_input, (size_t)33U * sizeof(uint8_t));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_2size_t__uint8_t
      uu____1 = sample_vector_cbd_then_ntt_60(uu____0, 0U);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      r_as_ntt[2U];
  memcpy(
      r_as_ntt, uu____1.fst,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t domain_separator0 = uu____1.snd;
  uint8_t uu____2[33U];
  memcpy(uu____2, prf_input, (size_t)33U * sizeof(uint8_t));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_2size_t__uint8_t
      uu____3 = sample_ring_element_cbd_60(uu____2, domain_separator0);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_1[2U];
  memcpy(
      error_1, uu____3.fst,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t domain_separator = uu____3.snd;
  prf_input[32U] = domain_separator;
  uint8_t prf_output[128U];
  PRF_10(
      Eurydice_array_to_slice((size_t)33U, prf_input, uint8_t, Eurydice_slice),
      prf_output);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_2 = sample_from_binomial_distribution_c0(Eurydice_array_to_slice(
          (size_t)128U, prf_output, uint8_t, Eurydice_slice));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      u[2U];
  compute_vector_u_c0(public_key->A, r_as_ntt, error_1, u);
  uint8_t uu____4[32U];
  memcpy(uu____4, message, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      message_as_ring_element = deserialize_then_decompress_message_24(uu____4);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      v = compute_ring_element_v_c0(public_key->t_as_ntt, r_as_ntt, &error_2,
                                    &message_as_ring_element);
  uint8_t ciphertext[768U] = {0U};
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____5[2U];
  memcpy(
      uu____5, u,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  compress_then_serialize_u_0f(
      uu____5, Eurydice_array_to_subslice2(ciphertext, (size_t)0U, (size_t)640U,
                                           uint8_t, Eurydice_slice));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____6 = v;
  compress_then_serialize_ring_element_v_6c(
      uu____6,
      Eurydice_array_to_subslice_from((size_t)768U, ciphertext, (size_t)640U,
                                      uint8_t, size_t, Eurydice_slice));
  memcpy(ret, ciphertext, (size_t)768U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.encapsulate_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
- CIPHERTEXT_SIZE = 768
- PUBLIC_KEY_SIZE = 800
- T_AS_NTT_ENCODED_SIZE = 768
- C1_SIZE = 640
- C2_SIZE = 128
- VECTOR_U_COMPRESSION_FACTOR = 10
- VECTOR_V_COMPRESSION_FACTOR = 4
- VECTOR_U_BLOCK_LEN = 320
- ETA1 = 3
- ETA1_RANDOMNESS_SIZE = 192
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
K___libcrux_ml_kem_types_MlKemCiphertext___768size_t___uint8_t_32size_t_
libcrux_ml_kem_ind_cca_encapsulate_unpacked_60(
    libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
        *public_key,
    uint8_t randomness[32U]) {
  uint8_t to_hash[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, randomness, uint8_t, Eurydice_slice),
      to_hash);
  Eurydice_slice uu____0 = Eurydice_array_to_subslice_from(
      (size_t)64U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
      size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)32U, public_key->public_key_hash, uint8_t,
                              Eurydice_slice),
      uint8_t, void *);
  uint8_t hashed[64U];
  G_e3(Eurydice_array_to_slice((size_t)64U, to_hash, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret = uu____1.fst;
  Eurydice_slice pseudorandomness = uu____1.snd;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      *uu____2 = &public_key->ind_cpa_public_key;
  uint8_t uu____3[32U];
  memcpy(uu____3, randomness, (size_t)32U * sizeof(uint8_t));
  uint8_t ciphertext[768U];
  encrypt_unpacked_60(uu____2, uu____3, pseudorandomness, ciphertext);
  uint8_t shared_secret_array[32U] = {0U};
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_slice((size_t)32U, shared_secret_array, uint8_t,
                              Eurydice_slice),
      shared_secret, uint8_t, void *);
  uint8_t uu____4[768U];
  memcpy(uu____4, ciphertext, (size_t)768U * sizeof(uint8_t));
  libcrux_ml_kem_types_MlKemCiphertext____768size_t uu____5 =
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___2__from_e3(
          uu____4);
  uint8_t uu____6[32U];
  memcpy(uu____6, shared_secret_array, (size_t)32U * sizeof(uint8_t));
  K___libcrux_ml_kem_types_MlKemCiphertext___768size_t___uint8_t_32size_t_ lit;
  lit.fst = uu____5;
  memcpy(lit.snd, uu____6, (size_t)32U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.ind_cca.{(libcrux_ml_kem::ind_cca::Variant␣for␣libcrux_ml_kem::ind_cca::MlKem)}.entropy_preprocess
with types libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and
with const generics:
- K = 2
*/
static KRML_MUSTINLINE void entropy_preprocess_a3(Eurydice_slice randomness,
                                                  uint8_t ret[32U]) {
  uint8_t out[32U] = {0U};
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_slice((size_t)32U, out, uint8_t, Eurydice_slice),
      randomness, uint8_t, void *);
  memcpy(ret, out, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_ring_elements_reduced with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- PUBLIC_KEY_SIZE = 768
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_ring_elements_reduced_98(
    Eurydice_slice public_key,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[2U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      deserialized_pk[2U];
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U,
                  deserialized_pk[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(public_key, uint8_t, size_t) /
               LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT;
       i++) {
    size_t i0 = i;
    Eurydice_slice ring_element = Eurydice_slice_subslice2(
        public_key, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT +
            LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_to_reduced_ring_element_24(ring_element);
    deserialized_pk[i0] = uu____0;
  }
  memcpy(
      ret, deserialized_pk,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.encrypt with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
- CIPHERTEXT_SIZE = 768
- T_AS_NTT_ENCODED_SIZE = 768
- C1_LEN = 640
- C2_LEN = 128
- U_COMPRESSION_FACTOR = 10
- V_COMPRESSION_FACTOR = 4
- BLOCK_LEN = 320
- ETA1 = 3
- ETA1_RANDOMNESS_SIZE = 192
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void encrypt_60(Eurydice_slice public_key, uint8_t message[32U],
                       Eurydice_slice randomness, uint8_t ret[768U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      t_as_ntt[2U];
  deserialize_ring_elements_reduced_98(
      Eurydice_slice_subslice_to(public_key, (size_t)768U, uint8_t, size_t,
                                 Eurydice_slice),
      t_as_ntt);
  Eurydice_slice seed = Eurydice_slice_subslice_from(
      public_key, (size_t)768U, uint8_t, size_t, Eurydice_slice);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A[2U][2U];
  uint8_t ret0[34U];
  libcrux_ml_kem_utils_into_padded_array_fe(seed, ret0);
  sample_matrix_A_9f(ret0, false, A);
  uint8_t seed_for_A[32U];
  core_result_Result__uint8_t_32size_t__core_array_TryFromSliceError dst;
  Eurydice_slice_to_array2(&dst, seed, Eurydice_slice, uint8_t[32U], void *);
  core_result__core__result__Result_T__E___unwrap_fb(dst, seed_for_A);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____0[2U];
  memcpy(
      uu____0, t_as_ntt,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____1[2U][2U];
  memcpy(
      uu____1, A,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [2U]));
  uint8_t uu____2[32U];
  memcpy(uu____2, seed_for_A, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      public_key_unpacked;
  memcpy(
      public_key_unpacked.t_as_ntt, uu____0,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  memcpy(public_key_unpacked.seed_for_A, uu____2,
         (size_t)32U * sizeof(uint8_t));
  memcpy(
      public_key_unpacked.A, uu____1,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [2U]));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      *uu____3 = &public_key_unpacked;
  uint8_t uu____4[32U];
  memcpy(uu____4, message, (size_t)32U * sizeof(uint8_t));
  uint8_t ret1[768U];
  encrypt_unpacked_60(uu____3, uu____4, randomness, ret1);
  memcpy(ret, ret1, (size_t)768U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.ind_cca.{(libcrux_ml_kem::ind_cca::Variant␣for␣libcrux_ml_kem::ind_cca::MlKem)}.kdf
with types libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and
with const generics:
- K = 2
- CIPHERTEXT_SIZE = 768
*/
static KRML_MUSTINLINE void kdf_6d(Eurydice_slice shared_secret,
                                   uint8_t ret[32U]) {
  uint8_t out[32U] = {0U};
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_slice((size_t)32U, out, uint8_t, Eurydice_slice),
      shared_secret, uint8_t, void *);
  memcpy(ret, out, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.encapsulate with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]],
libcrux_ml_kem_ind_cca_MlKem and with const generics:
- K = 2
- CIPHERTEXT_SIZE = 768
- PUBLIC_KEY_SIZE = 800
- T_AS_NTT_ENCODED_SIZE = 768
- C1_SIZE = 640
- C2_SIZE = 128
- VECTOR_U_COMPRESSION_FACTOR = 10
- VECTOR_V_COMPRESSION_FACTOR = 4
- VECTOR_U_BLOCK_LEN = 320
- ETA1 = 3
- ETA1_RANDOMNESS_SIZE = 192
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::ind_cca::Variant for libcrux_ml_kem::ind_cca::MlKem)}
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
K___libcrux_ml_kem_types_MlKemCiphertext___768size_t___uint8_t_32size_t_
libcrux_ml_kem_ind_cca_encapsulate_8f(
    libcrux_ml_kem_types_MlKemPublicKey____800size_t *public_key,
    uint8_t randomness[32U]) {
  uint8_t randomness0[32U];
  entropy_preprocess_a3(
      Eurydice_array_to_slice((size_t)32U, randomness, uint8_t, Eurydice_slice),
      randomness0);
  uint8_t to_hash[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, randomness0, uint8_t,
                              Eurydice_slice),
      to_hash);
  Eurydice_slice uu____0 = Eurydice_array_to_subslice_from(
      (size_t)64U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
      size_t, Eurydice_slice);
  uint8_t ret[32U];
  H_e3(
      Eurydice_array_to_slice(
          (size_t)800U,
          libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemPublicKey_SIZE__18__as_slice_72(
              public_key),
          uint8_t, Eurydice_slice),
      ret);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)32U, ret, uint8_t, Eurydice_slice),
      uint8_t, void *);
  uint8_t hashed[64U];
  G_e3(Eurydice_array_to_slice((size_t)64U, to_hash, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret = uu____1.fst;
  Eurydice_slice pseudorandomness = uu____1.snd;
  Eurydice_slice uu____2 = Eurydice_array_to_slice(
      (size_t)800U,
      libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemPublicKey_SIZE__18__as_slice_72(
          public_key),
      uint8_t, Eurydice_slice);
  uint8_t uu____3[32U];
  memcpy(uu____3, randomness0, (size_t)32U * sizeof(uint8_t));
  uint8_t ciphertext[768U];
  encrypt_60(uu____2, uu____3, pseudorandomness, ciphertext);
  uint8_t uu____4[768U];
  memcpy(uu____4, ciphertext, (size_t)768U * sizeof(uint8_t));
  libcrux_ml_kem_types_MlKemCiphertext____768size_t ciphertext0 =
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___2__from_e3(
          uu____4);
  uint8_t shared_secret_array[32U];
  kdf_6d(shared_secret, shared_secret_array);
  libcrux_ml_kem_types_MlKemCiphertext____768size_t uu____5 = ciphertext0;
  uint8_t uu____6[32U];
  memcpy(uu____6, shared_secret_array, (size_t)32U * sizeof(uint8_t));
  K___libcrux_ml_kem_types_MlKemCiphertext___768size_t___uint8_t_32size_t_ lit;
  lit.fst = uu____5;
  memcpy(lit.snd, uu____6, (size_t)32U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_then_decompress_ring_element_u with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- COMPRESSION_FACTOR = 10
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    deserialize_then_decompress_ring_element_u_96(Eurydice_slice serialized) {
  return deserialize_then_decompress_10_24(serialized);
}

/**
A monomorphic instance of libcrux_ml_kem.ntt.ntt_vector_u with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- VECTOR_U_COMPRESSION_FACTOR = 10
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void ntt_vector_u_96(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  size_t zeta_i = (size_t)0U;
  ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)7U);
  ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)6U);
  ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)5U);
  ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)4U);
  ntt_at_layer_3_24(&zeta_i, re);
  ntt_at_layer_2_24(&zeta_i, re);
  ntt_at_layer_1_24(&zeta_i, re);
  poly_barrett_reduce_24(re);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.deserialize_then_decompress_u
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with
const generics:
- K = 2
- CIPHERTEXT_SIZE = 768
- U_COMPRESSION_FACTOR = 10
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_then_decompress_u_6b(
    uint8_t *ciphertext,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[2U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      u_as_ntt[2U];
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U,
                  u_as_ntt[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(
               Eurydice_array_to_slice((size_t)768U, ciphertext, uint8_t,
                                       Eurydice_slice),
               uint8_t, size_t) /
               (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
                (size_t)10U / (size_t)8U);
       i++) {
    size_t i0 = i;
    Eurydice_slice u_bytes = Eurydice_array_to_subslice2(
        ciphertext,
        i0 * (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
              (size_t)10U / (size_t)8U),
        i0 * (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
              (size_t)10U / (size_t)8U) +
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
                (size_t)10U / (size_t)8U,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_then_decompress_ring_element_u_96(u_bytes);
    u_as_ntt[i0] = uu____0;
    ntt_vector_u_96(&u_as_ntt[i0]);
  }
  memcpy(
      ret, u_as_ntt,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_then_decompress_ring_element_v with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- COMPRESSION_FACTOR = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    deserialize_then_decompress_ring_element_v_eb(Eurydice_slice serialized) {
  return deserialize_then_decompress_4_24(serialized);
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_message with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    compute_message_c0(
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *v,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *secret_as_ntt,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *u_as_ntt) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result = ZERO_24();
  KRML_MAYBE_FOR2(
      i, (size_t)0U, (size_t)2U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(&secret_as_ntt[i0], &u_as_ntt[i0]);
      add_to_ring_element_c0(&result, &product););
  invert_ntt_montgomery_c0(&result);
  result = subtract_reduce_24(v, result);
  return result;
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.decrypt_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
- CIPHERTEXT_SIZE = 768
- VECTOR_U_ENCODED_SIZE = 640
- U_COMPRESSION_FACTOR = 10
- V_COMPRESSION_FACTOR = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void decrypt_unpacked_6b(
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
        *secret_key,
    uint8_t *ciphertext, uint8_t ret[32U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      u_as_ntt[2U];
  deserialize_then_decompress_u_6b(ciphertext, u_as_ntt);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      v = deserialize_then_decompress_ring_element_v_eb(
          Eurydice_array_to_subslice_from((size_t)768U, ciphertext,
                                          (size_t)640U, uint8_t, size_t,
                                          Eurydice_slice));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      message = compute_message_c0(&v, secret_key->secret_as_ntt, u_as_ntt);
  uint8_t ret0[32U];
  compress_then_serialize_message_24(message, ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.PRF
with const generics:
- K = 2
- LEN = 32
*/
static KRML_MUSTINLINE void PRF_c4(Eurydice_slice input, uint8_t ret[32U]) {
  PRF_5b(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.decapsulate_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]] and with const
generics:
- K = 2
- SECRET_KEY_SIZE = 1632
- CPA_SECRET_KEY_SIZE = 768
- PUBLIC_KEY_SIZE = 800
- CIPHERTEXT_SIZE = 768
- T_AS_NTT_ENCODED_SIZE = 768
- C1_SIZE = 640
- C2_SIZE = 128
- VECTOR_U_COMPRESSION_FACTOR = 10
- VECTOR_V_COMPRESSION_FACTOR = 4
- C1_BLOCK_SIZE = 320
- ETA1 = 3
- ETA1_RANDOMNESS_SIZE = 192
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
- IMPLICIT_REJECTION_HASH_INPUT_SIZE = 800
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
void libcrux_ml_kem_ind_cca_decapsulate_unpacked_60(
    libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
        *key_pair,
    libcrux_ml_kem_types_MlKemCiphertext____768size_t *ciphertext,
    uint8_t ret[32U]) {
  uint8_t decrypted[32U];
  decrypt_unpacked_6b(&key_pair->private_key.ind_cpa_private_key,
                      ciphertext->value, decrypted);
  uint8_t to_hash0[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, decrypted, uint8_t, Eurydice_slice),
      to_hash0);
  Eurydice_slice uu____0 = Eurydice_array_to_subslice_from(
      (size_t)64U, to_hash0, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
      uint8_t, size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)32U, key_pair->public_key.public_key_hash,
                              uint8_t, Eurydice_slice),
      uint8_t, void *);
  uint8_t hashed[64U];
  G_e3(Eurydice_array_to_slice((size_t)64U, to_hash0, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret = uu____1.fst;
  Eurydice_slice pseudorandomness = uu____1.snd;
  uint8_t to_hash[800U];
  libcrux_ml_kem_utils_into_padded_array_72(
      Eurydice_array_to_slice((size_t)32U,
                              key_pair->private_key.implicit_rejection_value,
                              uint8_t, Eurydice_slice),
      to_hash);
  Eurydice_slice uu____2 = Eurydice_array_to_subslice_from(
      (size_t)800U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
      uint8_t, size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____2,
      libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_e3(
          ciphertext),
      uint8_t, void *);
  uint8_t implicit_rejection_shared_secret[32U];
  PRF_c4(
      Eurydice_array_to_slice((size_t)800U, to_hash, uint8_t, Eurydice_slice),
      implicit_rejection_shared_secret);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      *uu____3 = &key_pair->public_key.ind_cpa_public_key;
  uint8_t uu____4[32U];
  memcpy(uu____4, decrypted, (size_t)32U * sizeof(uint8_t));
  uint8_t expected_ciphertext[768U];
  encrypt_unpacked_60(uu____3, uu____4, pseudorandomness, expected_ciphertext);
  uint8_t selector =
      libcrux_ml_kem_constant_time_ops_compare_ciphertexts_in_constant_time(
          libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_e3(
              ciphertext),
          Eurydice_array_to_slice((size_t)768U, expected_ciphertext, uint8_t,
                                  Eurydice_slice));
  uint8_t ret0[32U];
  libcrux_ml_kem_constant_time_ops_select_shared_secret_in_constant_time(
      shared_secret,
      Eurydice_array_to_slice((size_t)32U, implicit_rejection_shared_secret,
                              uint8_t, Eurydice_slice),
      selector, ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.deserialize_secret_key with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_secret_key_c0(
    Eurydice_slice secret_key,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[2U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      secret_as_ntt[2U];
  KRML_MAYBE_FOR2(i, (size_t)0U, (size_t)2U, (size_t)1U,
                  secret_as_ntt[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(secret_key, uint8_t, size_t) /
               LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT;
       i++) {
    size_t i0 = i;
    Eurydice_slice secret_bytes = Eurydice_slice_subslice2(
        secret_key, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT +
            LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_to_uncompressed_ring_element_24(secret_bytes);
    secret_as_ntt[i0] = uu____0;
  }
  memcpy(
      ret, secret_as_ntt,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.decrypt with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 2
- CIPHERTEXT_SIZE = 768
- VECTOR_U_ENCODED_SIZE = 640
- U_COMPRESSION_FACTOR = 10
- V_COMPRESSION_FACTOR = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void decrypt_6b(Eurydice_slice secret_key, uint8_t *ciphertext,
                       uint8_t ret[32U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      secret_as_ntt[2U];
  deserialize_secret_key_c0(secret_key, secret_as_ntt);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____0[2U];
  memcpy(
      uu____0, secret_as_ntt,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__2size_t
      secret_key_unpacked;
  memcpy(
      secret_key_unpacked.secret_as_ntt, uu____0,
      (size_t)2U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t ret0[32U];
  decrypt_unpacked_6b(&secret_key_unpacked, ciphertext, ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.decapsulate with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$2size_t]],
libcrux_ml_kem_ind_cca_MlKem and with const generics:
- K = 2
- SECRET_KEY_SIZE = 1632
- CPA_SECRET_KEY_SIZE = 768
- PUBLIC_KEY_SIZE = 800
- CIPHERTEXT_SIZE = 768
- T_AS_NTT_ENCODED_SIZE = 768
- C1_SIZE = 640
- C2_SIZE = 128
- VECTOR_U_COMPRESSION_FACTOR = 10
- VECTOR_V_COMPRESSION_FACTOR = 4
- C1_BLOCK_SIZE = 320
- ETA1 = 3
- ETA1_RANDOMNESS_SIZE = 192
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
- IMPLICIT_REJECTION_HASH_INPUT_SIZE = 800
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::ind_cca::Variant for libcrux_ml_kem::ind_cca::MlKem)}
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
void libcrux_ml_kem_ind_cca_decapsulate_8f(
    libcrux_ml_kem_types_MlKemPrivateKey____1632size_t *private_key,
    libcrux_ml_kem_types_MlKemCiphertext____768size_t *ciphertext,
    uint8_t ret[32U]) {
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____0 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)1632U, private_key->value, uint8_t,
                                  Eurydice_slice),
          (size_t)768U, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice ind_cpa_secret_key = uu____0.fst;
  Eurydice_slice secret_key0 = uu____0.snd;
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          secret_key0, (size_t)800U, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice ind_cpa_public_key = uu____1.fst;
  Eurydice_slice secret_key = uu____1.snd;
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____2 =
      core_slice___Slice_T___split_at(
          secret_key, LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice ind_cpa_public_key_hash = uu____2.fst;
  Eurydice_slice implicit_rejection_value = uu____2.snd;
  uint8_t decrypted[32U];
  decrypt_6b(ind_cpa_secret_key, ciphertext->value, decrypted);
  uint8_t to_hash0[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, decrypted, uint8_t, Eurydice_slice),
      to_hash0);
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice_from(
          (size_t)64U, to_hash0, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
          uint8_t, size_t, Eurydice_slice),
      ind_cpa_public_key_hash, uint8_t, void *);
  uint8_t hashed[64U];
  G_e3(Eurydice_array_to_slice((size_t)64U, to_hash0, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____3 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret0 = uu____3.fst;
  Eurydice_slice pseudorandomness = uu____3.snd;
  uint8_t to_hash[800U];
  libcrux_ml_kem_utils_into_padded_array_72(implicit_rejection_value, to_hash);
  Eurydice_slice uu____4 = Eurydice_array_to_subslice_from(
      (size_t)800U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
      uint8_t, size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____4,
      libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_e3(
          ciphertext),
      uint8_t, void *);
  uint8_t implicit_rejection_shared_secret0[32U];
  PRF_c4(
      Eurydice_array_to_slice((size_t)800U, to_hash, uint8_t, Eurydice_slice),
      implicit_rejection_shared_secret0);
  Eurydice_slice uu____5 = ind_cpa_public_key;
  uint8_t uu____6[32U];
  memcpy(uu____6, decrypted, (size_t)32U * sizeof(uint8_t));
  uint8_t expected_ciphertext[768U];
  encrypt_60(uu____5, uu____6, pseudorandomness, expected_ciphertext);
  uint8_t implicit_rejection_shared_secret[32U];
  kdf_6d(Eurydice_array_to_slice((size_t)32U, implicit_rejection_shared_secret0,
                                 uint8_t, Eurydice_slice),
         implicit_rejection_shared_secret);
  uint8_t shared_secret[32U];
  kdf_6d(shared_secret0, shared_secret);
  uint8_t ret0[32U];
  libcrux_ml_kem_constant_time_ops_compare_ciphertexts_select_shared_secret_in_constant_time(
      libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_e3(
          ciphertext),
      Eurydice_array_to_slice((size_t)768U, expected_ciphertext, uint8_t,
                              Eurydice_slice),
      Eurydice_array_to_slice((size_t)32U, shared_secret, uint8_t,
                              Eurydice_slice),
      Eurydice_array_to_slice((size_t)32U, implicit_rejection_shared_secret,
                              uint8_t, Eurydice_slice),
      ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_ring_elements_reduced with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- PUBLIC_KEY_SIZE = 1184
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_ring_elements_reduced_77(
    Eurydice_slice public_key,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[3U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      deserialized_pk[3U];
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U,
                  deserialized_pk[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(public_key, uint8_t, size_t) /
               LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT;
       i++) {
    size_t i0 = i;
    Eurydice_slice ring_element = Eurydice_slice_subslice2(
        public_key, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT +
            LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_to_reduced_ring_element_24(ring_element);
    deserialized_pk[i0] = uu____0;
  }
  memcpy(
      ret, deserialized_pk,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.serialize_secret_key with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
- OUT_LEN = 1152
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void serialize_secret_key_5e(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *key,
    uint8_t ret[1152U]) {
  uint8_t out[1152U] = {0U};
  for (
      size_t i = (size_t)0U;
      i <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)3U, key,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
          size_t);
      i++) {
    size_t i0 = i;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        re = key[i0];
    Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
        out, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        (i0 + (size_t)1U) * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    uint8_t ret0[384U];
    serialize_uncompressed_ring_element_24(&re, ret0);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)384U, ret0, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
  memcpy(ret, out, (size_t)1152U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.serialize_public_key with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
- RANKED_BYTES_PER_RING_ELEMENT = 1152
- PUBLIC_KEY_SIZE = 1184
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void serialize_public_key_1e(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *t_as_ntt,
    Eurydice_slice seed_for_a, uint8_t ret[1184U]) {
  uint8_t public_key_serialized[1184U] = {0U};
  Eurydice_slice uu____0 =
      Eurydice_array_to_subslice2(public_key_serialized, (size_t)0U,
                                  (size_t)1152U, uint8_t, Eurydice_slice);
  uint8_t ret0[1152U];
  serialize_secret_key_5e(t_as_ntt, ret0);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)1152U, ret0, uint8_t, Eurydice_slice),
      uint8_t, void *);
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice_from((size_t)1184U, public_key_serialized,
                                      (size_t)1152U, uint8_t, size_t,
                                      Eurydice_slice),
      seed_for_a, uint8_t, void *);
  memcpy(ret, public_key_serialized, (size_t)1184U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.validate_public_key with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
- RANKED_BYTES_PER_RING_ELEMENT = 1152
- PUBLIC_KEY_SIZE = 1184
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
bool libcrux_ml_kem_ind_cca_validate_public_key_1e(uint8_t *public_key) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      deserialized_pk[3U];
  deserialize_ring_elements_reduced_77(
      Eurydice_array_to_subslice_to((size_t)1184U, public_key, (size_t)1152U,
                                    uint8_t, size_t, Eurydice_slice),
      deserialized_pk);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      *uu____0 = deserialized_pk;
  uint8_t public_key_serialized[1184U];
  serialize_public_key_1e(
      uu____0,
      Eurydice_array_to_subslice_from((size_t)1184U, public_key, (size_t)1152U,
                                      uint8_t, size_t, Eurydice_slice),
      public_key_serialized);
  return core_array_equality___core__cmp__PartialEq__Array_U__N___for__Array_T__N____eq(
      (size_t)1184U, public_key, public_key_serialized, uint8_t, uint8_t, bool);
}

typedef struct
    __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t___s {
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      fst;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      snd;
} __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t__;

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.G
with const generics:
- K = 3
*/
static KRML_MUSTINLINE void G_c4(Eurydice_slice input, uint8_t ret[64U]) {
  libcrux_ml_kem_hash_functions_portable_G(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.sample_matrix_A.closure with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void closure_54(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[3U]) {
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U, ret[i] = ZERO_24(););
}

typedef struct PortableHash____3size_t_s {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t shake128_state[3U];
} PortableHash____3size_t;

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.shake128_init_absorb with const generics:
- K = 3
*/
static KRML_MUSTINLINE PortableHash____3size_t
shake128_init_absorb_c4(uint8_t input[3U][34U]) {
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t shake128_state[3U];
  KRML_MAYBE_FOR3(
      i, (size_t)0U, (size_t)3U, (size_t)1U,
      shake128_state[i] = libcrux_sha3_portable_incremental_shake128_init(););
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
                  libcrux_sha3_portable_incremental_shake128_absorb_final(
                      &shake128_state[i0],
                      Eurydice_array_to_slice((size_t)34U, input[i0], uint8_t,
                                              Eurydice_slice)););
  libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t uu____0[3U];
  memcpy(
      uu____0, shake128_state,
      (size_t)3U *
          sizeof(libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t));
  PortableHash____3size_t lit;
  memcpy(
      lit.shake128_state, uu____0,
      (size_t)3U *
          sizeof(libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t));
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.shake128_init_absorb
with const generics:
- K = 3
*/
static KRML_MUSTINLINE PortableHash____3size_t
shake128_init_absorb_c40(uint8_t input[3U][34U]) {
  uint8_t uu____0[3U][34U];
  memcpy(uu____0, input, (size_t)3U * sizeof(uint8_t[34U]));
  return shake128_init_absorb_c4(uu____0);
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.shake128_squeeze_three_blocks with const
generics:
- K = 3
*/
static KRML_MUSTINLINE void shake128_squeeze_three_blocks_c4(
    PortableHash____3size_t *st, uint8_t ret[3U][504U]) {
  uint8_t out[3U][504U] = {{0U}};
  KRML_MAYBE_FOR3(
      i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
      libcrux_sha3_portable_incremental_shake128_squeeze_first_three_blocks(
          &st->shake128_state[i0],
          Eurydice_array_to_slice((size_t)504U, out[i0], uint8_t,
                                  Eurydice_slice)););
  memcpy(ret, out, (size_t)3U * sizeof(uint8_t[504U]));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.shake128_squeeze_three_blocks
with const generics:
- K = 3
*/
static KRML_MUSTINLINE void shake128_squeeze_three_blocks_c40(
    PortableHash____3size_t *self, uint8_t ret[3U][504U]) {
  shake128_squeeze_three_blocks_c4(self, ret);
}

/**
A monomorphic instance of
libcrux_ml_kem.sampling.sample_from_uniform_distribution_next with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
- N = 504
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE bool sample_from_uniform_distribution_next_79(
    uint8_t randomness[3U][504U], size_t *sampled_coefficients,
    int16_t (*out)[272U]) {
  KRML_MAYBE_FOR3(
      i0, (size_t)0U, (size_t)3U, (size_t)1U, size_t i1 = i0;
      for (size_t i = (size_t)0U; i < (size_t)504U / (size_t)24U; i++) {
        size_t r = i;
        if (sampled_coefficients[i1] <
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
          Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
              randomness[i1], r * (size_t)24U, r * (size_t)24U + (size_t)24U,
              uint8_t, Eurydice_slice);
          size_t sampled =
              libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___rej_sample(
                  uu____0, Eurydice_array_to_subslice2(
                               out[i1], sampled_coefficients[i1],
                               sampled_coefficients[i1] + (size_t)16U, int16_t,
                               Eurydice_slice));
          size_t uu____1 = i1;
          sampled_coefficients[uu____1] =
              sampled_coefficients[uu____1] + sampled;
        }
      });
  bool done = true;
  KRML_MAYBE_FOR3(
      i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
      if (sampled_coefficients[i0] >=
          LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
        sampled_coefficients[i0] =
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT;
      } else { done = false; });
  return done;
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.shake128_squeeze_block with const
generics:
- K = 3
*/
static KRML_MUSTINLINE void shake128_squeeze_block_c4(
    PortableHash____3size_t *st, uint8_t ret[3U][168U]) {
  uint8_t out[3U][168U] = {{0U}};
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
                  libcrux_sha3_portable_incremental_shake128_squeeze_next_block(
                      &st->shake128_state[i0],
                      Eurydice_array_to_slice((size_t)168U, out[i0], uint8_t,
                                              Eurydice_slice)););
  memcpy(ret, out, (size_t)3U * sizeof(uint8_t[168U]));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.shake128_squeeze_block
with const generics:
- K = 3
*/
static KRML_MUSTINLINE void shake128_squeeze_block_c40(
    PortableHash____3size_t *self, uint8_t ret[3U][168U]) {
  shake128_squeeze_block_c4(self, ret);
}

/**
A monomorphic instance of
libcrux_ml_kem.sampling.sample_from_uniform_distribution_next with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
- N = 168
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE bool sample_from_uniform_distribution_next_3f(
    uint8_t randomness[3U][168U], size_t *sampled_coefficients,
    int16_t (*out)[272U]) {
  KRML_MAYBE_FOR3(
      i0, (size_t)0U, (size_t)3U, (size_t)1U, size_t i1 = i0;
      for (size_t i = (size_t)0U; i < (size_t)168U / (size_t)24U; i++) {
        size_t r = i;
        if (sampled_coefficients[i1] <
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
          Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
              randomness[i1], r * (size_t)24U, r * (size_t)24U + (size_t)24U,
              uint8_t, Eurydice_slice);
          size_t sampled =
              libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___rej_sample(
                  uu____0, Eurydice_array_to_subslice2(
                               out[i1], sampled_coefficients[i1],
                               sampled_coefficients[i1] + (size_t)16U, int16_t,
                               Eurydice_slice));
          size_t uu____1 = i1;
          sampled_coefficients[uu____1] =
              sampled_coefficients[uu____1] + sampled;
        }
      });
  bool done = true;
  KRML_MAYBE_FOR3(
      i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
      if (sampled_coefficients[i0] >=
          LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
        sampled_coefficients[i0] =
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT;
      } else { done = false; });
  return done;
}

/**
A monomorphic instance of libcrux_ml_kem.sampling.sample_from_xof.closure with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
closure_540(int16_t s[272U]) {
  return from_i16_array_24(Eurydice_array_to_subslice2(
      s, (size_t)0U, (size_t)256U, int16_t, Eurydice_slice));
}

/**
A monomorphic instance of libcrux_ml_kem.sampling.sample_from_xof with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void sample_from_xof_54(
    uint8_t seeds[3U][34U],
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[3U]) {
  size_t sampled_coefficients[3U] = {0U};
  int16_t out[3U][272U] = {{0U}};
  uint8_t uu____0[3U][34U];
  memcpy(uu____0, seeds, (size_t)3U * sizeof(uint8_t[34U]));
  PortableHash____3size_t xof_state = shake128_init_absorb_c40(uu____0);
  uint8_t randomness0[3U][504U];
  shake128_squeeze_three_blocks_c40(&xof_state, randomness0);
  uint8_t uu____1[3U][504U];
  memcpy(uu____1, randomness0, (size_t)3U * sizeof(uint8_t[504U]));
  bool done = sample_from_uniform_distribution_next_79(
      uu____1, sampled_coefficients, out);
  while (true) {
    if (done) {
      break;
    } else {
      uint8_t randomness[3U][168U];
      shake128_squeeze_block_c40(&xof_state, randomness);
      uint8_t uu____2[3U][168U];
      memcpy(uu____2, randomness, (size_t)3U * sizeof(uint8_t[168U]));
      done = sample_from_uniform_distribution_next_3f(
          uu____2, sampled_coefficients, out);
    }
  }
  int16_t uu____3[3U][272U];
  memcpy(uu____3, out, (size_t)3U * sizeof(int16_t[272U]));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      ret0[3U];
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U,
                  ret0[i] = closure_540(uu____3[i]););
  memcpy(
      ret, ret0,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.sample_matrix_A with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void sample_matrix_A_54(
    uint8_t seed[34U], bool transpose,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[3U][3U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A_transpose[3U][3U];
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U,
                  closure_54(A_transpose[i]););
  KRML_MAYBE_FOR3(
      i0, (size_t)0U, (size_t)3U, (size_t)1U, size_t i1 = i0;
      uint8_t uu____0[34U];
      memcpy(uu____0, seed, (size_t)34U * sizeof(uint8_t));
      uint8_t seeds[3U][34U]; KRML_MAYBE_FOR3(
          i, (size_t)0U, (size_t)3U, (size_t)1U,
          memcpy(seeds[i], uu____0, (size_t)34U * sizeof(uint8_t)););
      KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U, size_t j = i;
                      seeds[j][32U] = (uint8_t)i1; seeds[j][33U] = (uint8_t)j;);
      uint8_t uu____1[3U][34U];
      memcpy(uu____1, seeds, (size_t)3U * sizeof(uint8_t[34U]));
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          sampled[3U];
      sample_from_xof_54(uu____1, sampled); for (
          size_t i = (size_t)0U;
          i <
          core_slice___Slice_T___len(
              Eurydice_array_to_slice(
                  (size_t)3U, sampled,
                  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                  Eurydice_slice),
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
              size_t);
          i++) {
        size_t j = i;
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            sample = sampled[j];
        if (transpose) {
          A_transpose[j][i1] = sample;
        } else {
          A_transpose[i1][j] = sample;
        }
      });
  memcpy(
      ret, A_transpose,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [3U]));
}

typedef struct
    __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_3size_t__uint8_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      fst[3U];
  uint8_t snd;
} __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_3size_t__uint8_t;

/**
A monomorphic instance of libcrux_ml_kem.hash_functions.portable.PRFxN with
const generics:
- K = 3
- LEN = 128
*/
static KRML_MUSTINLINE void PRFxN_17(uint8_t (*input)[33U],
                                     uint8_t ret[3U][128U]) {
  uint8_t out[3U][128U] = {{0U}};
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
                  libcrux_sha3_portable_shake256(
                      Eurydice_array_to_slice((size_t)128U, out[i0], uint8_t,
                                              Eurydice_slice),
                      Eurydice_array_to_slice((size_t)33U, input[i0], uint8_t,
                                              Eurydice_slice)););
  memcpy(ret, out, (size_t)3U * sizeof(uint8_t[128U]));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.PRFxN
with const generics:
- K = 3
- LEN = 128
*/
static KRML_MUSTINLINE void PRFxN_170(uint8_t (*input)[33U],
                                      uint8_t ret[3U][128U]) {
  PRFxN_17(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.sample_vector_cbd_then_ntt with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
- ETA = 2
- ETA_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_3size_t__uint8_t
    sample_vector_cbd_then_ntt_80(uint8_t prf_input[33U],
                                  uint8_t domain_separator) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      re_as_ntt[3U];
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U,
                  re_as_ntt[i] = ZERO_24(););
  uint8_t uu____0[33U];
  memcpy(uu____0, prf_input, (size_t)33U * sizeof(uint8_t));
  uint8_t prf_inputs[3U][33U];
  KRML_MAYBE_FOR3(
      i, (size_t)0U, (size_t)3U, (size_t)1U,
      memcpy(prf_inputs[i], uu____0, (size_t)33U * sizeof(uint8_t)););
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
                  prf_inputs[i0][32U] = domain_separator;
                  domain_separator = (uint32_t)domain_separator + 1U;);
  uint8_t prf_outputs[3U][128U];
  PRFxN_170(prf_inputs, prf_outputs);
  KRML_MAYBE_FOR3(
      i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          uu____1 =
              sample_from_binomial_distribution_c0(Eurydice_array_to_slice(
                  (size_t)128U, prf_outputs[i0], uint8_t, Eurydice_slice));
      re_as_ntt[i0] = uu____1;
      ntt_binomially_sampled_ring_element_24(&re_as_ntt[i0]););
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____2[3U];
  memcpy(
      uu____2, re_as_ntt,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_3size_t__uint8_t
      lit;
  memcpy(
      lit.fst, uu____2,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  lit.snd = domain_separator;
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.polynomial.{libcrux_ml_kem::polynomial::PolynomialRingElement<Vector>[TraitClause@0]}.add_to_ring_element
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with
const generics:
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void add_to_ring_element_0e(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *rhs) {
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(
               Eurydice_array_to_slice(
                   (size_t)16U, self->coefficients,
                   libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                   Eurydice_slice),
               libcrux_ml_kem_vector_portable_vector_type_PortableVector,
               size_t);
       i++) {
    size_t i0 = i;
    libcrux_ml_kem_vector_portable_vector_type_PortableVector uu____0 =
        libcrux_ml_kem_vector_portable___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__portable__vector_type__PortableVector___add(
            self->coefficients[i0], &rhs->coefficients[i0]);
    self->coefficients[i0] = uu____0;
  }
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_As_plus_e with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compute_As_plus_e_0e(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector (
        *matrix_A)[3U],
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *s_as_ntt,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *error_as_ntt,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[3U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result[3U];
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U,
                  result[i] = ZERO_24(););
  for (
      size_t i0 = (size_t)0U;
      i0 <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)3U, matrix_A,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [3U],
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
              [3U],
          size_t);
      i0++) {
    size_t i1 = i0;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *row = matrix_A[i1];
    for (
        size_t i = (size_t)0U;
        i <
        core_slice___Slice_T___len(
            Eurydice_array_to_slice(
                (size_t)3U, row,
                libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                Eurydice_slice),
            libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
            size_t);
        i++) {
      size_t j = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          *matrix_element = &row[j];
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(matrix_element, &s_as_ntt[j]);
      add_to_ring_element_0e(&result[i1], &product);
    }
    add_standard_error_reduce_24(&result[i1], &error_as_ntt[i1]);
  }
  memcpy(
      ret, result,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.generate_keypair_unpacked with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t__
generate_keypair_unpacked_80(Eurydice_slice key_generation_seed) {
  uint8_t hashed[64U];
  G_c4(key_generation_seed, hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____0 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          (size_t)32U, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice seed_for_A0 = uu____0.fst;
  Eurydice_slice seed_for_secret_and_error = uu____0.snd;
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A_transpose[3U][3U];
  uint8_t ret[34U];
  libcrux_ml_kem_utils_into_padded_array_fe(seed_for_A0, ret);
  sample_matrix_A_54(ret, true, A_transpose);
  uint8_t prf_input[33U];
  libcrux_ml_kem_utils_into_padded_array_cb(seed_for_secret_and_error,
                                            prf_input);
  uint8_t uu____1[33U];
  memcpy(uu____1, prf_input, (size_t)33U * sizeof(uint8_t));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_3size_t__uint8_t
      uu____2 = sample_vector_cbd_then_ntt_80(uu____1, 0U);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      secret_as_ntt[3U];
  memcpy(
      secret_as_ntt, uu____2.fst,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t domain_separator = uu____2.snd;
  uint8_t uu____3[33U];
  memcpy(uu____3, prf_input, (size_t)33U * sizeof(uint8_t));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_as_ntt[3U];
  memcpy(
      error_as_ntt,
      sample_vector_cbd_then_ntt_80(uu____3, domain_separator).fst,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      t_as_ntt[3U];
  compute_As_plus_e_0e(A_transpose, secret_as_ntt, error_as_ntt, t_as_ntt);
  uint8_t seed_for_A[32U];
  core_result_Result__uint8_t_32size_t__core_array_TryFromSliceError dst;
  Eurydice_slice_to_array2(&dst, seed_for_A0, Eurydice_slice, uint8_t[32U],
                           void *);
  core_result__core__result__Result_T__E___unwrap_fb(dst, seed_for_A);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____4[3U];
  memcpy(
      uu____4, t_as_ntt,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____5[3U][3U];
  memcpy(
      uu____5, A_transpose,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [3U]));
  uint8_t uu____6[32U];
  memcpy(uu____6, seed_for_A, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      pk;
  memcpy(
      pk.t_as_ntt, uu____4,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  memcpy(pk.seed_for_A, uu____6, (size_t)32U * sizeof(uint8_t));
  memcpy(
      pk.A, uu____5,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [3U]));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____7[3U];
  memcpy(
      uu____7, secret_as_ntt,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      sk;
  memcpy(
      sk.secret_as_ntt, uu____7,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  return (CLITERAL(
      __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t__){
      .fst = sk, .snd = pk});
}

/**
A monomorphic instance of
libcrux_ml_kem.ind_cca.generate_keypair_unpacked.closure with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
- CPA_PRIVATE_KEY_SIZE = 1152
- PRIVATE_KEY_SIZE = 2400
- PUBLIC_KEY_SIZE = 1184
- BYTES_PER_RING_ELEMENT = 1152
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void closure_80(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[3U]) {
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U, ret[i] = ZERO_24(););
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.H
with const generics:
- K = 3
*/
static KRML_MUSTINLINE void H_c4(Eurydice_slice input, uint8_t ret[32U]) {
  libcrux_ml_kem_hash_functions_portable_H(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.generate_keypair_unpacked with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
- CPA_PRIVATE_KEY_SIZE = 1152
- PRIVATE_KEY_SIZE = 2400
- PUBLIC_KEY_SIZE = 1184
- BYTES_PER_RING_ELEMENT = 1152
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
libcrux_ml_kem_ind_cca_generate_keypair_unpacked_80(uint8_t randomness[64U]) {
  Eurydice_slice ind_cpa_keypair_randomness = Eurydice_array_to_subslice2(
      randomness, (size_t)0U,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      Eurydice_slice);
  Eurydice_slice implicit_rejection_value0 = Eurydice_array_to_subslice_from(
      (size_t)64U, randomness,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      size_t, Eurydice_slice);
  __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t__
      uu____0 = generate_keypair_unpacked_80(ind_cpa_keypair_randomness);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      ind_cpa_private_key = uu____0.fst;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      ind_cpa_public_key = uu____0.snd;
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A[3U][3U];
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U, closure_80(A[i]););
  KRML_MAYBE_FOR3(
      i0, (size_t)0U, (size_t)3U, (size_t)1U, size_t i1 = i0; KRML_MAYBE_FOR3(
          i, (size_t)0U, (size_t)3U, (size_t)1U, size_t j = i;
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
              uu____1 = clone_24(&ind_cpa_public_key.A[j][i1]);
          A[i1][j] = uu____1;););
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____2[3U][3U];
  memcpy(
      uu____2, A,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [3U]));
  memcpy(
      ind_cpa_public_key.A, uu____2,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [3U]));
  uint8_t pk_serialized[1184U];
  serialize_public_key_1e(
      ind_cpa_public_key.t_as_ntt,
      Eurydice_array_to_slice((size_t)32U, ind_cpa_public_key.seed_for_A,
                              uint8_t, Eurydice_slice),
      pk_serialized);
  uint8_t public_key_hash[32U];
  H_c4(Eurydice_array_to_slice((size_t)1184U, pk_serialized, uint8_t,
                               Eurydice_slice),
       public_key_hash);
  uint8_t implicit_rejection_value[32U];
  core_result_Result__uint8_t_32size_t__core_array_TryFromSliceError dst;
  Eurydice_slice_to_array2(&dst, implicit_rejection_value0, Eurydice_slice,
                           uint8_t[32U], void *);
  core_result__core__result__Result_T__E___unwrap_fb(dst,
                                                     implicit_rejection_value);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      uu____3 = ind_cpa_private_key;
  uint8_t uu____4[32U];
  memcpy(uu____4, implicit_rejection_value, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      uu____5;
  uu____5.ind_cpa_private_key = uu____3;
  memcpy(uu____5.implicit_rejection_value, uu____4,
         (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      uu____6 = ind_cpa_public_key;
  uint8_t uu____7[32U];
  memcpy(uu____7, public_key_hash, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      lit;
  lit.private_key = uu____5;
  lit.public_key.ind_cpa_public_key = uu____6;
  memcpy(lit.public_key.public_key_hash, uu____7,
         (size_t)32U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.generate_keypair with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
- PRIVATE_KEY_SIZE = 1152
- PUBLIC_KEY_SIZE = 1184
- RANKED_BYTES_PER_RING_ELEMENT = 1152
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static libcrux_ml_kem_utils_extraction_helper_Keypair768 generate_keypair_80(
    Eurydice_slice key_generation_seed) {
  __libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t___libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked_libcrux_ml_kem_vector_portable_vector_type_PortableVector___3size_t__
      uu____0 = generate_keypair_unpacked_80(key_generation_seed);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      sk = uu____0.fst;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      pk = uu____0.snd;
  uint8_t public_key_serialized[1184U];
  serialize_public_key_1e(pk.t_as_ntt,
                          Eurydice_array_to_slice((size_t)32U, pk.seed_for_A,
                                                  uint8_t, Eurydice_slice),
                          public_key_serialized);
  uint8_t secret_key_serialized[1152U];
  serialize_secret_key_5e(sk.secret_as_ntt, secret_key_serialized);
  uint8_t uu____1[1152U];
  memcpy(uu____1, secret_key_serialized, (size_t)1152U * sizeof(uint8_t));
  uint8_t uu____2[1184U];
  memcpy(uu____2, public_key_serialized, (size_t)1184U * sizeof(uint8_t));
  libcrux_ml_kem_utils_extraction_helper_Keypair768 lit;
  memcpy(lit.fst, uu____1, (size_t)1152U * sizeof(uint8_t));
  memcpy(lit.snd, uu____2, (size_t)1184U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.serialize_kem_secret_key with
types libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with
const generics:
- K = 3
- SERIALIZED_KEY_LEN = 2400
*/
static KRML_MUSTINLINE void serialize_kem_secret_key_14(
    Eurydice_slice private_key, Eurydice_slice public_key,
    Eurydice_slice implicit_rejection_value, uint8_t ret[2400U]) {
  uint8_t out[2400U] = {0U};
  size_t pointer = (size_t)0U;
  uint8_t *uu____0 = out;
  size_t uu____1 = pointer;
  size_t uu____2 = pointer;
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice2(
          uu____0, uu____1,
          uu____2 + core_slice___Slice_T___len(private_key, uint8_t, size_t),
          uint8_t, Eurydice_slice),
      private_key, uint8_t, void *);
  pointer = pointer + core_slice___Slice_T___len(private_key, uint8_t, size_t);
  uint8_t *uu____3 = out;
  size_t uu____4 = pointer;
  size_t uu____5 = pointer;
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice2(
          uu____3, uu____4,
          uu____5 + core_slice___Slice_T___len(public_key, uint8_t, size_t),
          uint8_t, Eurydice_slice),
      public_key, uint8_t, void *);
  pointer = pointer + core_slice___Slice_T___len(public_key, uint8_t, size_t);
  Eurydice_slice uu____6 = Eurydice_array_to_subslice2(
      out, pointer, pointer + LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
      Eurydice_slice);
  uint8_t ret0[32U];
  H_c4(public_key, ret0);
  core_slice___Slice_T___copy_from_slice(
      uu____6,
      Eurydice_array_to_slice((size_t)32U, ret0, uint8_t, Eurydice_slice),
      uint8_t, void *);
  pointer = pointer + LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE;
  uint8_t *uu____7 = out;
  size_t uu____8 = pointer;
  size_t uu____9 = pointer;
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice2(
          uu____7, uu____8,
          uu____9 + core_slice___Slice_T___len(implicit_rejection_value,
                                               uint8_t, size_t),
          uint8_t, Eurydice_slice),
      implicit_rejection_value, uint8_t, void *);
  memcpy(ret, out, (size_t)2400U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.generate_keypair with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
- CPA_PRIVATE_KEY_SIZE = 1152
- PRIVATE_KEY_SIZE = 2400
- PUBLIC_KEY_SIZE = 1184
- BYTES_PER_RING_ELEMENT = 1152
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
libcrux_ml_kem_mlkem768_MlKem768KeyPair
libcrux_ml_kem_ind_cca_generate_keypair_80(uint8_t randomness[64U]) {
  Eurydice_slice ind_cpa_keypair_randomness = Eurydice_array_to_subslice2(
      randomness, (size_t)0U,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      Eurydice_slice);
  Eurydice_slice implicit_rejection_value = Eurydice_array_to_subslice_from(
      (size_t)64U, randomness,
      LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE, uint8_t,
      size_t, Eurydice_slice);
  libcrux_ml_kem_utils_extraction_helper_Keypair768 uu____0 =
      generate_keypair_80(ind_cpa_keypair_randomness);
  uint8_t ind_cpa_private_key[1152U];
  memcpy(ind_cpa_private_key, uu____0.fst, (size_t)1152U * sizeof(uint8_t));
  uint8_t public_key[1184U];
  memcpy(public_key, uu____0.snd, (size_t)1184U * sizeof(uint8_t));
  uint8_t secret_key_serialized[2400U];
  serialize_kem_secret_key_14(
      Eurydice_array_to_slice((size_t)1152U, ind_cpa_private_key, uint8_t,
                              Eurydice_slice),
      Eurydice_array_to_slice((size_t)1184U, public_key, uint8_t,
                              Eurydice_slice),
      implicit_rejection_value, secret_key_serialized);
  uint8_t uu____1[2400U];
  memcpy(uu____1, secret_key_serialized, (size_t)2400U * sizeof(uint8_t));
  libcrux_ml_kem_types_MlKemPrivateKey____2400size_t private_key =
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPrivateKey_SIZE___8__from_99(
          uu____1);
  libcrux_ml_kem_types_MlKemPrivateKey____2400size_t uu____2 = private_key;
  uint8_t uu____3[1184U];
  memcpy(uu____3, public_key, (size_t)1184U * sizeof(uint8_t));
  return libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemKeyPair_PRIVATE_KEY_SIZE__PUBLIC_KEY_SIZE___from_b5(
      uu____2,
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemPublicKey_SIZE___14__from_fb(
          uu____3));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.sample_ring_element_cbd with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
- ETA2_RANDOMNESS_SIZE = 128
- ETA2 = 2
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_3size_t__uint8_t
    sample_ring_element_cbd_80(uint8_t prf_input[33U],
                               uint8_t domain_separator) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_1[3U];
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U,
                  error_1[i] = ZERO_24(););
  uint8_t uu____0[33U];
  memcpy(uu____0, prf_input, (size_t)33U * sizeof(uint8_t));
  uint8_t prf_inputs[3U][33U];
  KRML_MAYBE_FOR3(
      i, (size_t)0U, (size_t)3U, (size_t)1U,
      memcpy(prf_inputs[i], uu____0, (size_t)33U * sizeof(uint8_t)););
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
                  prf_inputs[i0][32U] = domain_separator;
                  domain_separator = (uint32_t)domain_separator + 1U;);
  uint8_t prf_outputs[3U][128U];
  PRFxN_170(prf_inputs, prf_outputs);
  KRML_MAYBE_FOR3(
      i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          uu____1 =
              sample_from_binomial_distribution_c0(Eurydice_array_to_slice(
                  (size_t)128U, prf_outputs[i0], uint8_t, Eurydice_slice));
      error_1[i0] = uu____1;);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____2[3U];
  memcpy(
      uu____2, error_1,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_3size_t__uint8_t
      lit;
  memcpy(
      lit.fst, uu____2,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  lit.snd = domain_separator;
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.PRF
with const generics:
- K = 3
- LEN = 128
*/
static KRML_MUSTINLINE void PRF_17(Eurydice_slice input, uint8_t ret[128U]) {
  PRF_9b(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.invert_ntt.invert_ntt_montgomery with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void invert_ntt_montgomery_0e(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *re) {
  size_t zeta_i =
      LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT / (size_t)2U;
  invert_ntt_at_layer_1_24(&zeta_i, re);
  invert_ntt_at_layer_2_24(&zeta_i, re);
  invert_ntt_at_layer_3_24(&zeta_i, re);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)4U);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)5U);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)6U);
  invert_ntt_at_layer_4_plus_24(&zeta_i, re, (size_t)7U);
  poly_barrett_reduce_24(re);
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_vector_u with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void compute_vector_u_0e(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector (
        *a_as_ntt)[3U],
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *r_as_ntt,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *error_1,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[3U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result[3U];
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U,
                  result[i] = ZERO_24(););
  for (
      size_t i0 = (size_t)0U;
      i0 <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)3U, a_as_ntt,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [3U],
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
              [3U],
          size_t);
      i0++) {
    size_t i1 = i0;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        *row = a_as_ntt[i1];
    for (
        size_t i = (size_t)0U;
        i <
        core_slice___Slice_T___len(
            Eurydice_array_to_slice(
                (size_t)3U, row,
                libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
                Eurydice_slice),
            libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
            size_t);
        i++) {
      size_t j = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          *a_element = &row[j];
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(a_element, &r_as_ntt[j]);
      add_to_ring_element_0e(&result[i1], &product);
    }
    invert_ntt_montgomery_0e(&result[i1]);
    add_error_reduce_24(&result[i1], &error_1[i1]);
  }
  memcpy(
      ret, result,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_ring_element_v with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    compute_ring_element_v_0e(
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *t_as_ntt,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *r_as_ntt,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *error_2,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *message) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result = ZERO_24();
  KRML_MAYBE_FOR3(
      i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(&t_as_ntt[i0], &r_as_ntt[i0]);
      add_to_ring_element_0e(&result, &product););
  invert_ntt_montgomery_0e(&result);
  result = add_message_error_reduce_24(error_2, message, result);
  return result;
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.compress_then_serialize_u with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
- OUT_LEN = 960
- COMPRESSION_FACTOR = 10
- BLOCK_LEN = 320
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void compress_then_serialize_u_8b(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        input[3U],
    Eurydice_slice out) {
  for (
      size_t i = (size_t)0U;
      i <
      core_slice___Slice_T___len(
          Eurydice_array_to_slice(
              (size_t)3U, input,
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
              Eurydice_slice),
          libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector,
          size_t);
      i++) {
    size_t i0 = i;
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        re = input[i0];
    Eurydice_slice uu____0 = Eurydice_slice_subslice2(
        out, i0 * ((size_t)960U / (size_t)3U),
        (i0 + (size_t)1U) * ((size_t)960U / (size_t)3U), uint8_t,
        Eurydice_slice);
    uint8_t ret[320U];
    compress_then_serialize_ring_element_u_63(&re, ret);
    core_slice___Slice_T___copy_from_slice(
        uu____0,
        Eurydice_array_to_slice((size_t)320U, ret, uint8_t, Eurydice_slice),
        uint8_t, void *);
  }
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.encrypt_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
- CIPHERTEXT_SIZE = 1088
- T_AS_NTT_ENCODED_SIZE = 1152
- C1_LEN = 960
- C2_LEN = 128
- U_COMPRESSION_FACTOR = 10
- V_COMPRESSION_FACTOR = 4
- BLOCK_LEN = 320
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void encrypt_unpacked_80(
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
        *public_key,
    uint8_t message[32U], Eurydice_slice randomness, uint8_t ret[1088U]) {
  uint8_t prf_input[33U];
  libcrux_ml_kem_utils_into_padded_array_cb(randomness, prf_input);
  uint8_t uu____0[33U];
  memcpy(uu____0, prf_input, (size_t)33U * sizeof(uint8_t));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_3size_t__uint8_t
      uu____1 = sample_vector_cbd_then_ntt_80(uu____0, 0U);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      r_as_ntt[3U];
  memcpy(
      r_as_ntt, uu____1.fst,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t domain_separator0 = uu____1.snd;
  uint8_t uu____2[33U];
  memcpy(uu____2, prf_input, (size_t)33U * sizeof(uint8_t));
  __libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector_3size_t__uint8_t
      uu____3 = sample_ring_element_cbd_80(uu____2, domain_separator0);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_1[3U];
  memcpy(
      error_1, uu____3.fst,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t domain_separator = uu____3.snd;
  prf_input[32U] = domain_separator;
  uint8_t prf_output[128U];
  PRF_17(
      Eurydice_array_to_slice((size_t)33U, prf_input, uint8_t, Eurydice_slice),
      prf_output);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      error_2 = sample_from_binomial_distribution_c0(Eurydice_array_to_slice(
          (size_t)128U, prf_output, uint8_t, Eurydice_slice));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      u[3U];
  compute_vector_u_0e(public_key->A, r_as_ntt, error_1, u);
  uint8_t uu____4[32U];
  memcpy(uu____4, message, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      message_as_ring_element = deserialize_then_decompress_message_24(uu____4);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      v = compute_ring_element_v_0e(public_key->t_as_ntt, r_as_ntt, &error_2,
                                    &message_as_ring_element);
  uint8_t ciphertext[1088U] = {0U};
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____5[3U];
  memcpy(
      uu____5, u,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  compress_then_serialize_u_8b(
      uu____5, Eurydice_array_to_subslice2(ciphertext, (size_t)0U, (size_t)960U,
                                           uint8_t, Eurydice_slice));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____6 = v;
  compress_then_serialize_ring_element_v_6c(
      uu____6,
      Eurydice_array_to_subslice_from((size_t)1088U, ciphertext, (size_t)960U,
                                      uint8_t, size_t, Eurydice_slice));
  memcpy(ret, ciphertext, (size_t)1088U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.encapsulate_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
- CIPHERTEXT_SIZE = 1088
- PUBLIC_KEY_SIZE = 1184
- T_AS_NTT_ENCODED_SIZE = 1152
- C1_SIZE = 960
- C2_SIZE = 128
- VECTOR_U_COMPRESSION_FACTOR = 10
- VECTOR_V_COMPRESSION_FACTOR = 4
- VECTOR_U_BLOCK_LEN = 320
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
K___libcrux_ml_kem_types_MlKemCiphertext___1088size_t___uint8_t_32size_t_
libcrux_ml_kem_ind_cca_encapsulate_unpacked_80(
    libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
        *public_key,
    uint8_t randomness[32U]) {
  uint8_t to_hash[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, randomness, uint8_t, Eurydice_slice),
      to_hash);
  Eurydice_slice uu____0 = Eurydice_array_to_subslice_from(
      (size_t)64U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
      size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)32U, public_key->public_key_hash, uint8_t,
                              Eurydice_slice),
      uint8_t, void *);
  uint8_t hashed[64U];
  G_c4(Eurydice_array_to_slice((size_t)64U, to_hash, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret = uu____1.fst;
  Eurydice_slice pseudorandomness = uu____1.snd;
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      *uu____2 = &public_key->ind_cpa_public_key;
  uint8_t uu____3[32U];
  memcpy(uu____3, randomness, (size_t)32U * sizeof(uint8_t));
  uint8_t ciphertext[1088U];
  encrypt_unpacked_80(uu____2, uu____3, pseudorandomness, ciphertext);
  uint8_t shared_secret_array[32U] = {0U};
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_slice((size_t)32U, shared_secret_array, uint8_t,
                              Eurydice_slice),
      shared_secret, uint8_t, void *);
  uint8_t uu____4[1088U];
  memcpy(uu____4, ciphertext, (size_t)1088U * sizeof(uint8_t));
  libcrux_ml_kem_mlkem768_MlKem768Ciphertext uu____5 =
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___2__from_e6(
          uu____4);
  uint8_t uu____6[32U];
  memcpy(uu____6, shared_secret_array, (size_t)32U * sizeof(uint8_t));
  K___libcrux_ml_kem_types_MlKemCiphertext___1088size_t___uint8_t_32size_t_ lit;
  lit.fst = uu____5;
  memcpy(lit.snd, uu____6, (size_t)32U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of
libcrux_ml_kem.ind_cca.{(libcrux_ml_kem::ind_cca::Variant␣for␣libcrux_ml_kem::ind_cca::MlKem)}.entropy_preprocess
with types libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and
with const generics:
- K = 3
*/
static KRML_MUSTINLINE void entropy_preprocess_9a(Eurydice_slice randomness,
                                                  uint8_t ret[32U]) {
  uint8_t out[32U] = {0U};
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_slice((size_t)32U, out, uint8_t, Eurydice_slice),
      randomness, uint8_t, void *);
  memcpy(ret, out, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.serialize.deserialize_ring_elements_reduced with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- PUBLIC_KEY_SIZE = 1152
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_ring_elements_reduced_46(
    Eurydice_slice public_key,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[3U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      deserialized_pk[3U];
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U,
                  deserialized_pk[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(public_key, uint8_t, size_t) /
               LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT;
       i++) {
    size_t i0 = i;
    Eurydice_slice ring_element = Eurydice_slice_subslice2(
        public_key, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT +
            LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_to_reduced_ring_element_24(ring_element);
    deserialized_pk[i0] = uu____0;
  }
  memcpy(
      ret, deserialized_pk,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.encrypt with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
- CIPHERTEXT_SIZE = 1088
- T_AS_NTT_ENCODED_SIZE = 1152
- C1_LEN = 960
- C2_LEN = 128
- U_COMPRESSION_FACTOR = 10
- V_COMPRESSION_FACTOR = 4
- BLOCK_LEN = 320
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void encrypt_80(Eurydice_slice public_key, uint8_t message[32U],
                       Eurydice_slice randomness, uint8_t ret[1088U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      t_as_ntt[3U];
  deserialize_ring_elements_reduced_46(
      Eurydice_slice_subslice_to(public_key, (size_t)1152U, uint8_t, size_t,
                                 Eurydice_slice),
      t_as_ntt);
  Eurydice_slice seed = Eurydice_slice_subslice_from(
      public_key, (size_t)1152U, uint8_t, size_t, Eurydice_slice);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      A[3U][3U];
  uint8_t ret0[34U];
  libcrux_ml_kem_utils_into_padded_array_fe(seed, ret0);
  sample_matrix_A_54(ret0, false, A);
  uint8_t seed_for_A[32U];
  core_result_Result__uint8_t_32size_t__core_array_TryFromSliceError dst;
  Eurydice_slice_to_array2(&dst, seed, Eurydice_slice, uint8_t[32U], void *);
  core_result__core__result__Result_T__E___unwrap_fb(dst, seed_for_A);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____0[3U];
  memcpy(
      uu____0, t_as_ntt,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____1[3U][3U];
  memcpy(
      uu____1, A,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [3U]));
  uint8_t uu____2[32U];
  memcpy(uu____2, seed_for_A, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      public_key_unpacked;
  memcpy(
      public_key_unpacked.t_as_ntt, uu____0,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  memcpy(public_key_unpacked.seed_for_A, uu____2,
         (size_t)32U * sizeof(uint8_t));
  memcpy(
      public_key_unpacked.A, uu____1,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
                  [3U]));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      *uu____3 = &public_key_unpacked;
  uint8_t uu____4[32U];
  memcpy(uu____4, message, (size_t)32U * sizeof(uint8_t));
  uint8_t ret1[1088U];
  encrypt_unpacked_80(uu____3, uu____4, randomness, ret1);
  memcpy(ret, ret1, (size_t)1088U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.ind_cca.{(libcrux_ml_kem::ind_cca::Variant␣for␣libcrux_ml_kem::ind_cca::MlKem)}.kdf
with types libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and
with const generics:
- K = 3
- CIPHERTEXT_SIZE = 1088
*/
static KRML_MUSTINLINE void kdf_14(Eurydice_slice shared_secret,
                                   uint8_t ret[32U]) {
  uint8_t out[32U] = {0U};
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_slice((size_t)32U, out, uint8_t, Eurydice_slice),
      shared_secret, uint8_t, void *);
  memcpy(ret, out, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.encapsulate with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]],
libcrux_ml_kem_ind_cca_MlKem and with const generics:
- K = 3
- CIPHERTEXT_SIZE = 1088
- PUBLIC_KEY_SIZE = 1184
- T_AS_NTT_ENCODED_SIZE = 1152
- C1_SIZE = 960
- C2_SIZE = 128
- VECTOR_U_COMPRESSION_FACTOR = 10
- VECTOR_V_COMPRESSION_FACTOR = 4
- VECTOR_U_BLOCK_LEN = 320
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::ind_cca::Variant for libcrux_ml_kem::ind_cca::MlKem)}
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
K___libcrux_ml_kem_types_MlKemCiphertext___1088size_t___uint8_t_32size_t_
libcrux_ml_kem_ind_cca_encapsulate_c3(
    libcrux_ml_kem_types_MlKemPublicKey____1184size_t *public_key,
    uint8_t randomness[32U]) {
  uint8_t randomness0[32U];
  entropy_preprocess_9a(
      Eurydice_array_to_slice((size_t)32U, randomness, uint8_t, Eurydice_slice),
      randomness0);
  uint8_t to_hash[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, randomness0, uint8_t,
                              Eurydice_slice),
      to_hash);
  Eurydice_slice uu____0 = Eurydice_array_to_subslice_from(
      (size_t)64U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
      size_t, Eurydice_slice);
  uint8_t ret[32U];
  H_c4(
      Eurydice_array_to_slice(
          (size_t)1184U,
          libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemPublicKey_SIZE__18__as_slice_fb(
              public_key),
          uint8_t, Eurydice_slice),
      ret);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)32U, ret, uint8_t, Eurydice_slice),
      uint8_t, void *);
  uint8_t hashed[64U];
  G_c4(Eurydice_array_to_slice((size_t)64U, to_hash, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret = uu____1.fst;
  Eurydice_slice pseudorandomness = uu____1.snd;
  Eurydice_slice uu____2 = Eurydice_array_to_slice(
      (size_t)1184U,
      libcrux_ml_kem_types__libcrux_ml_kem__types__MlKemPublicKey_SIZE__18__as_slice_fb(
          public_key),
      uint8_t, Eurydice_slice);
  uint8_t uu____3[32U];
  memcpy(uu____3, randomness0, (size_t)32U * sizeof(uint8_t));
  uint8_t ciphertext[1088U];
  encrypt_80(uu____2, uu____3, pseudorandomness, ciphertext);
  uint8_t uu____4[1088U];
  memcpy(uu____4, ciphertext, (size_t)1088U * sizeof(uint8_t));
  libcrux_ml_kem_mlkem768_MlKem768Ciphertext ciphertext0 =
      libcrux_ml_kem_types___core__convert__From__Array_u8__SIZE___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___2__from_e6(
          uu____4);
  uint8_t shared_secret_array[32U];
  kdf_14(shared_secret, shared_secret_array);
  libcrux_ml_kem_mlkem768_MlKem768Ciphertext uu____5 = ciphertext0;
  uint8_t uu____6[32U];
  memcpy(uu____6, shared_secret_array, (size_t)32U * sizeof(uint8_t));
  K___libcrux_ml_kem_types_MlKemCiphertext___1088size_t___uint8_t_32size_t_ lit;
  lit.fst = uu____5;
  memcpy(lit.snd, uu____6, (size_t)32U * sizeof(uint8_t));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.deserialize_then_decompress_u
with types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with
const generics:
- K = 3
- CIPHERTEXT_SIZE = 1088
- U_COMPRESSION_FACTOR = 10
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_then_decompress_u_ee(
    uint8_t *ciphertext,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[3U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      u_as_ntt[3U];
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U,
                  u_as_ntt[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(
               Eurydice_array_to_slice((size_t)1088U, ciphertext, uint8_t,
                                       Eurydice_slice),
               uint8_t, size_t) /
               (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
                (size_t)10U / (size_t)8U);
       i++) {
    size_t i0 = i;
    Eurydice_slice u_bytes = Eurydice_array_to_subslice2(
        ciphertext,
        i0 * (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
              (size_t)10U / (size_t)8U),
        i0 * (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
              (size_t)10U / (size_t)8U) +
            LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *
                (size_t)10U / (size_t)8U,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_then_decompress_ring_element_u_96(u_bytes);
    u_as_ntt[i0] = uu____0;
    ntt_vector_u_96(&u_as_ntt[i0]);
  }
  memcpy(
      ret, u_as_ntt,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.matrix.compute_message with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
    compute_message_0e(
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *v,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *secret_as_ntt,
        libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
            *u_as_ntt) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      result = ZERO_24();
  KRML_MAYBE_FOR3(
      i, (size_t)0U, (size_t)3U, (size_t)1U, size_t i0 = i;
      libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
          product = ntt_multiply_24(&secret_as_ntt[i0], &u_as_ntt[i0]);
      add_to_ring_element_0e(&result, &product););
  invert_ntt_montgomery_0e(&result);
  result = subtract_reduce_24(v, result);
  return result;
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.decrypt_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
- CIPHERTEXT_SIZE = 1088
- VECTOR_U_ENCODED_SIZE = 960
- U_COMPRESSION_FACTOR = 10
- V_COMPRESSION_FACTOR = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void decrypt_unpacked_ee(
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
        *secret_key,
    uint8_t *ciphertext, uint8_t ret[32U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      u_as_ntt[3U];
  deserialize_then_decompress_u_ee(ciphertext, u_as_ntt);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      v = deserialize_then_decompress_ring_element_v_eb(
          Eurydice_array_to_subslice_from((size_t)1088U, ciphertext,
                                          (size_t)960U, uint8_t, size_t,
                                          Eurydice_slice));
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      message = compute_message_0e(&v, secret_key->secret_as_ntt, u_as_ntt);
  uint8_t ret0[32U];
  compress_then_serialize_message_24(message, ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_kem.hash_functions.portable.{(libcrux_ml_kem::hash_functions::Hash<K>␣for␣libcrux_ml_kem::hash_functions::portable::PortableHash<K>)}.PRF
with const generics:
- K = 3
- LEN = 32
*/
static KRML_MUSTINLINE void PRF_f6(Eurydice_slice input, uint8_t ret[32U]) {
  PRF_5b(input, ret);
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.decapsulate_unpacked with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]] and with const
generics:
- K = 3
- SECRET_KEY_SIZE = 2400
- CPA_SECRET_KEY_SIZE = 1152
- PUBLIC_KEY_SIZE = 1184
- CIPHERTEXT_SIZE = 1088
- T_AS_NTT_ENCODED_SIZE = 1152
- C1_SIZE = 960
- C2_SIZE = 128
- VECTOR_U_COMPRESSION_FACTOR = 10
- VECTOR_V_COMPRESSION_FACTOR = 4
- C1_BLOCK_SIZE = 320
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
- IMPLICIT_REJECTION_HASH_INPUT_SIZE = 1120
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
void libcrux_ml_kem_ind_cca_decapsulate_unpacked_80(
    libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
        *key_pair,
    libcrux_ml_kem_mlkem768_MlKem768Ciphertext *ciphertext, uint8_t ret[32U]) {
  uint8_t decrypted[32U];
  decrypt_unpacked_ee(&key_pair->private_key.ind_cpa_private_key,
                      ciphertext->value, decrypted);
  uint8_t to_hash0[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, decrypted, uint8_t, Eurydice_slice),
      to_hash0);
  Eurydice_slice uu____0 = Eurydice_array_to_subslice_from(
      (size_t)64U, to_hash0, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
      uint8_t, size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_slice((size_t)32U, key_pair->public_key.public_key_hash,
                              uint8_t, Eurydice_slice),
      uint8_t, void *);
  uint8_t hashed[64U];
  G_c4(Eurydice_array_to_slice((size_t)64U, to_hash0, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret = uu____1.fst;
  Eurydice_slice pseudorandomness = uu____1.snd;
  uint8_t to_hash[1120U];
  libcrux_ml_kem_utils_into_padded_array_a0(
      Eurydice_array_to_slice((size_t)32U,
                              key_pair->private_key.implicit_rejection_value,
                              uint8_t, Eurydice_slice),
      to_hash);
  Eurydice_slice uu____2 = Eurydice_array_to_subslice_from(
      (size_t)1120U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
      uint8_t, size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____2,
      libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_e6(
          ciphertext),
      uint8_t, void *);
  uint8_t implicit_rejection_shared_secret[32U];
  PRF_f6(
      Eurydice_array_to_slice((size_t)1120U, to_hash, uint8_t, Eurydice_slice),
      implicit_rejection_shared_secret);
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      *uu____3 = &key_pair->public_key.ind_cpa_public_key;
  uint8_t uu____4[32U];
  memcpy(uu____4, decrypted, (size_t)32U * sizeof(uint8_t));
  uint8_t expected_ciphertext[1088U];
  encrypt_unpacked_80(uu____3, uu____4, pseudorandomness, expected_ciphertext);
  uint8_t selector =
      libcrux_ml_kem_constant_time_ops_compare_ciphertexts_in_constant_time(
          libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_e6(
              ciphertext),
          Eurydice_array_to_slice((size_t)1088U, expected_ciphertext, uint8_t,
                                  Eurydice_slice));
  uint8_t ret0[32U];
  libcrux_ml_kem_constant_time_ops_select_shared_secret_in_constant_time(
      shared_secret,
      Eurydice_array_to_slice((size_t)32U, implicit_rejection_shared_secret,
                              uint8_t, Eurydice_slice),
      selector, ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.deserialize_secret_key with
types libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static KRML_MUSTINLINE void deserialize_secret_key_0e(
    Eurydice_slice secret_key,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        ret[3U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      secret_as_ntt[3U];
  KRML_MAYBE_FOR3(i, (size_t)0U, (size_t)3U, (size_t)1U,
                  secret_as_ntt[i] = ZERO_24(););
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(secret_key, uint8_t, size_t) /
               LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT;
       i++) {
    size_t i0 = i;
    Eurydice_slice secret_bytes = Eurydice_slice_subslice2(
        secret_key, i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        i0 * LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT +
            LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT,
        uint8_t, Eurydice_slice);
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
        uu____0 = deserialize_to_uncompressed_ring_element_24(secret_bytes);
    secret_as_ntt[i0] = uu____0;
  }
  memcpy(
      ret, secret_as_ntt,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cpa.decrypt with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector and with const
generics:
- K = 3
- CIPHERTEXT_SIZE = 1088
- VECTOR_U_ENCODED_SIZE = 960
- U_COMPRESSION_FACTOR = 10
- V_COMPRESSION_FACTOR = 4
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
static void decrypt_ee(Eurydice_slice secret_key, uint8_t *ciphertext,
                       uint8_t ret[32U]) {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      secret_as_ntt[3U];
  deserialize_secret_key_0e(secret_key, secret_as_ntt);
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector
      uu____0[3U];
  memcpy(
      uu____0, secret_as_ntt,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_portable_vector_type_PortableVector__3size_t
      secret_key_unpacked;
  memcpy(
      secret_key_unpacked.secret_as_ntt, uu____0,
      (size_t)3U *
          sizeof(
              libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_portable_vector_type_PortableVector));
  uint8_t ret0[32U];
  decrypt_unpacked_ee(&secret_key_unpacked, ciphertext, ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_kem.ind_cca.decapsulate with types
libcrux_ml_kem_vector_portable_vector_type_PortableVector,
libcrux_ml_kem_hash_functions_portable_PortableHash[[$3size_t]],
libcrux_ml_kem_ind_cca_MlKem and with const generics:
- K = 3
- SECRET_KEY_SIZE = 2400
- CPA_SECRET_KEY_SIZE = 1152
- PUBLIC_KEY_SIZE = 1184
- CIPHERTEXT_SIZE = 1088
- T_AS_NTT_ENCODED_SIZE = 1152
- C1_SIZE = 960
- C2_SIZE = 128
- VECTOR_U_COMPRESSION_FACTOR = 10
- VECTOR_V_COMPRESSION_FACTOR = 4
- C1_BLOCK_SIZE = 320
- ETA1 = 2
- ETA1_RANDOMNESS_SIZE = 128
- ETA2 = 2
- ETA2_RANDOMNESS_SIZE = 128
- IMPLICIT_REJECTION_HASH_INPUT_SIZE = 1120
Furthermore, this instances features the following traits:
- {(libcrux_ml_kem::ind_cca::Variant for libcrux_ml_kem::ind_cca::MlKem)}
- {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::portable::vector_type::PortableVector)}
*/
void libcrux_ml_kem_ind_cca_decapsulate_c3(
    libcrux_ml_kem_types_MlKemPrivateKey____2400size_t *private_key,
    libcrux_ml_kem_mlkem768_MlKem768Ciphertext *ciphertext, uint8_t ret[32U]) {
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____0 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)2400U, private_key->value, uint8_t,
                                  Eurydice_slice),
          (size_t)1152U, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice ind_cpa_secret_key = uu____0.fst;
  Eurydice_slice secret_key0 = uu____0.snd;
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at(
          secret_key0, (size_t)1184U, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice ind_cpa_public_key = uu____1.fst;
  Eurydice_slice secret_key = uu____1.snd;
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____2 =
      core_slice___Slice_T___split_at(
          secret_key, LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice ind_cpa_public_key_hash = uu____2.fst;
  Eurydice_slice implicit_rejection_value = uu____2.snd;
  uint8_t decrypted[32U];
  decrypt_ee(ind_cpa_secret_key, ciphertext->value, decrypted);
  uint8_t to_hash0[64U];
  libcrux_ml_kem_utils_into_padded_array_51(
      Eurydice_array_to_slice((size_t)32U, decrypted, uint8_t, Eurydice_slice),
      to_hash0);
  core_slice___Slice_T___copy_from_slice(
      Eurydice_array_to_subslice_from(
          (size_t)64U, to_hash0, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
          uint8_t, size_t, Eurydice_slice),
      ind_cpa_public_key_hash, uint8_t, void *);
  uint8_t hashed[64U];
  G_c4(Eurydice_array_to_slice((size_t)64U, to_hash0, uint8_t, Eurydice_slice),
       hashed);
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____3 =
      core_slice___Slice_T___split_at(
          Eurydice_array_to_slice((size_t)64U, hashed, uint8_t, Eurydice_slice),
          LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice shared_secret0 = uu____3.fst;
  Eurydice_slice pseudorandomness = uu____3.snd;
  uint8_t to_hash[1120U];
  libcrux_ml_kem_utils_into_padded_array_a0(implicit_rejection_value, to_hash);
  Eurydice_slice uu____4 = Eurydice_array_to_subslice_from(
      (size_t)1120U, to_hash, LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE,
      uint8_t, size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____4,
      libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_e6(
          ciphertext),
      uint8_t, void *);
  uint8_t implicit_rejection_shared_secret0[32U];
  PRF_f6(
      Eurydice_array_to_slice((size_t)1120U, to_hash, uint8_t, Eurydice_slice),
      implicit_rejection_shared_secret0);
  Eurydice_slice uu____5 = ind_cpa_public_key;
  uint8_t uu____6[32U];
  memcpy(uu____6, decrypted, (size_t)32U * sizeof(uint8_t));
  uint8_t expected_ciphertext[1088U];
  encrypt_80(uu____5, uu____6, pseudorandomness, expected_ciphertext);
  uint8_t implicit_rejection_shared_secret[32U];
  kdf_14(Eurydice_array_to_slice((size_t)32U, implicit_rejection_shared_secret0,
                                 uint8_t, Eurydice_slice),
         implicit_rejection_shared_secret);
  uint8_t shared_secret[32U];
  kdf_14(shared_secret0, shared_secret);
  uint8_t ret0[32U];
  libcrux_ml_kem_constant_time_ops_compare_ciphertexts_select_shared_secret_in_constant_time(
      libcrux_ml_kem_types___core__convert__AsRef__Slice_u8___for_libcrux_ml_kem__types__MlKemCiphertext_SIZE___1__as_ref_e6(
          ciphertext),
      Eurydice_array_to_slice((size_t)1088U, expected_ciphertext, uint8_t,
                              Eurydice_slice),
      Eurydice_array_to_slice((size_t)32U, shared_secret, uint8_t,
                              Eurydice_slice),
      Eurydice_array_to_slice((size_t)32U, implicit_rejection_shared_secret,
                              uint8_t, Eurydice_slice),
      ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}
