/*
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /home/franziskus/eurydice//eurydice --config ../c.yaml
  ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc F* version: <unknown>
  KaRaMeL version: 40e3a603
 */

#include "libcrux_mlkem768.h"

#include "internal/libcrux_core.h"

static void
decapsulate___3size_t_2400size_t_1152size_t_1184size_t_1088size_t_1152size_t_960size_t_128size_t_10size_t_4size_t_320size_t_2size_t_128size_t_2size_t_128size_t_1120size_t(
    libcrux_ml_kem_types_MlKemPrivateKey____2400size_t *private_key,
    libcrux_ml_kem_types_MlKemCiphertext____1088size_t *ciphertext,
    uint8_t ret[32U]) {
  uint8_t uu____0[32U];
  if (libcrux_platform_platform_simd256_support()) {
    libcrux_ml_kem_ind_cca_instantiations_avx2_decapsulate___3size_t_2400size_t_1152size_t_1184size_t_1088size_t_1152size_t_960size_t_128size_t_10size_t_4size_t_320size_t_2size_t_128size_t_2size_t_128size_t_1120size_t(
        private_key, ciphertext, uu____0);
    memcpy(ret, uu____0, (size_t)32U * sizeof(uint8_t));
    return;
  }
  libcrux_ml_kem_ind_cca_instantiations_portable_decapsulate___3size_t_2400size_t_1152size_t_1184size_t_1088size_t_1152size_t_960size_t_128size_t_10size_t_4size_t_320size_t_2size_t_128size_t_2size_t_128size_t_1120size_t(
      private_key, ciphertext, uu____0);
  memcpy(ret, uu____0, (size_t)32U * sizeof(uint8_t));
}

void libcrux_ml_kem_mlkem768_decapsulate(
    libcrux_ml_kem_types_MlKemPrivateKey____2400size_t *private_key,
    libcrux_ml_kem_types_MlKemCiphertext____1088size_t *ciphertext,
    uint8_t ret[32U]) {
  uint8_t ret0[32U];
  decapsulate___3size_t_2400size_t_1152size_t_1184size_t_1088size_t_1152size_t_960size_t_128size_t_10size_t_4size_t_320size_t_2size_t_128size_t_2size_t_128size_t_1120size_t(
      private_key, ciphertext, ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

static K___libcrux_ml_kem_types_MlKemCiphertext___1088size_t___uint8_t_32size_t_
encapsulate___3size_t_1088size_t_1184size_t_1152size_t_960size_t_128size_t_10size_t_4size_t_320size_t_2size_t_128size_t_2size_t_128size_t(
    libcrux_ml_kem_types_MlKemPublicKey____1184size_t *public_key,
    uint8_t randomness[32U]) {
  K___libcrux_ml_kem_types_MlKemCiphertext___1088size_t___uint8_t_32size_t_
      uu____0;
  if (libcrux_platform_platform_simd256_support()) {
    libcrux_ml_kem_types_MlKemPublicKey____1184size_t *uu____1 = public_key;
    uint8_t uu____2[32U];
    memcpy(uu____2, randomness, (size_t)32U * sizeof(uint8_t));
    uu____0 =
        libcrux_ml_kem_ind_cca_instantiations_avx2_encapsulate___3size_t_1088size_t_1184size_t_1152size_t_960size_t_128size_t_10size_t_4size_t_320size_t_2size_t_128size_t_2size_t_128size_t(
            uu____1, uu____2);
    return uu____0;
  }
  libcrux_ml_kem_types_MlKemPublicKey____1184size_t *uu____3 = public_key;
  uint8_t uu____4[32U];
  memcpy(uu____4, randomness, (size_t)32U * sizeof(uint8_t));
  uu____0 =
      libcrux_ml_kem_ind_cca_instantiations_portable_encapsulate___3size_t_1088size_t_1184size_t_1152size_t_960size_t_128size_t_10size_t_4size_t_320size_t_2size_t_128size_t_2size_t_128size_t(
          uu____3, uu____4);
  return uu____0;
}

K___libcrux_ml_kem_types_MlKemCiphertext___1088size_t___uint8_t_32size_t_
libcrux_ml_kem_mlkem768_encapsulate(
    libcrux_ml_kem_types_MlKemPublicKey____1184size_t *public_key,
    uint8_t randomness[32U]) {
  libcrux_ml_kem_types_MlKemPublicKey____1184size_t *uu____0 = public_key;
  uint8_t uu____1[32U];
  memcpy(uu____1, randomness, (size_t)32U * sizeof(uint8_t));
  return encapsulate___3size_t_1088size_t_1184size_t_1152size_t_960size_t_128size_t_10size_t_4size_t_320size_t_2size_t_128size_t_2size_t_128size_t(
      uu____0, uu____1);
}

static libcrux_ml_kem_types_MlKemKeyPair____2400size_t__1184size_t
generate_keypair___3size_t_1152size_t_2400size_t_1184size_t_1152size_t_2size_t_128size_t(
    uint8_t randomness[64U]) {
  libcrux_ml_kem_types_MlKemKeyPair____2400size_t__1184size_t uu____0;
  if (libcrux_platform_platform_simd256_support()) {
    uint8_t uu____1[64U];
    memcpy(uu____1, randomness, (size_t)64U * sizeof(uint8_t));
    uu____0 =
        libcrux_ml_kem_ind_cca_instantiations_avx2_generate_keypair___3size_t_1152size_t_2400size_t_1184size_t_1152size_t_2size_t_128size_t(
            uu____1);
    return uu____0;
  }
  uint8_t uu____2[64U];
  memcpy(uu____2, randomness, (size_t)64U * sizeof(uint8_t));
  uu____0 =
      libcrux_ml_kem_ind_cca_instantiations_portable_generate_keypair___3size_t_1152size_t_2400size_t_1184size_t_1152size_t_2size_t_128size_t(
          uu____2);
  return uu____0;
}

libcrux_ml_kem_types_MlKemKeyPair____2400size_t__1184size_t
libcrux_ml_kem_mlkem768_generate_key_pair(uint8_t randomness[64U]) {
  uint8_t uu____0[64U];
  memcpy(uu____0, randomness, (size_t)64U * sizeof(uint8_t));
  return generate_keypair___3size_t_1152size_t_2400size_t_1184size_t_1152size_t_2size_t_128size_t(
      uu____0);
}

static bool validate_public_key___3size_t_1152size_t_1184size_t(
    uint8_t *public_key) {
  bool uu____0;
  if (libcrux_platform_platform_simd256_support()) {
    uu____0 =
        libcrux_ml_kem_ind_cca_instantiations_avx2_validate_public_key___3size_t_1152size_t_1184size_t(
            public_key);
    return uu____0;
  }
  uu____0 =
      libcrux_ml_kem_ind_cca_instantiations_portable_validate_public_key___3size_t_1152size_t_1184size_t(
          public_key);
  return uu____0;
}

core_option_Option__libcrux_ml_kem_types_MlKemPublicKey___1184size_t__
libcrux_ml_kem_mlkem768_validate_public_key(
    libcrux_ml_kem_types_MlKemPublicKey____1184size_t public_key) {
  core_option_Option__libcrux_ml_kem_types_MlKemPublicKey___1184size_t__
      uu____0;
  if (validate_public_key___3size_t_1152size_t_1184size_t(public_key.value)) {
    uu____0 = ((
        core_option_Option__libcrux_ml_kem_types_MlKemPublicKey___1184size_t__){
        .tag = core_option_Some, .f0 = public_key});
  } else {
    uu____0 = ((
        core_option_Option__libcrux_ml_kem_types_MlKemPublicKey___1184size_t__){
        .tag = core_option_None});
  }
  return uu____0;
}
