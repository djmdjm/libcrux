/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: 53530427db2941ce784201e64086766504bc5642
 * Eurydice: 7b1f8fd8d41a07543f4812a53624b6cb77e3df21
 * Karamel: 9fb21c700160be489cafc690c3c0af2681ece49b
 * F*: 58c915a86a2c07c8eca8d9deafd76cb7a91f0eb7
 * Libcrux: 0b811dab12d3bb3f004bb2ac853ff4a822780566
 */

#ifndef __libcrux_mlkem768_portable_H
#define __libcrux_mlkem768_portable_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"
#include "libcrux_core.h"
#include "libcrux_mlkem_portable.h"

/**
 Decapsulate ML-KEM 768

 Generates an [`MlKemSharedSecret`].
 The input is a reference to an [`MlKem768PrivateKey`] and an
 [`MlKem768Ciphertext`].
*/
void libcrux_ml_kem_mlkem768_portable_decapsulate(
    libcrux_ml_kem_types_MlKemPrivateKey_55 *private_key,
    libcrux_ml_kem_mlkem768_MlKem768Ciphertext *ciphertext, uint8_t ret[32U]);

/**
 Decapsulate ML-KEM 768 (unpacked)

 Generates an [`MlKemSharedSecret`].
 The input is a reference to an unpacked key pair of type
 [`MlKem768KeyPairUnpacked`] and an [`MlKem768Ciphertext`].
*/
void libcrux_ml_kem_mlkem768_portable_decapsulate_unpacked(
    libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked_f8 *private_key,
    libcrux_ml_kem_mlkem768_MlKem768Ciphertext *ciphertext, uint8_t ret[32U]);

/**
 Encapsulate ML-KEM 768

 Generates an ([`MlKem768Ciphertext`], [`MlKemSharedSecret`]) tuple.
 The input is a reference to an [`MlKem768PublicKey`] and [`SHARED_SECRET_SIZE`]
 bytes of `randomness`.
*/
tuple_3c libcrux_ml_kem_mlkem768_portable_encapsulate(
    libcrux_ml_kem_types_MlKemPublicKey_15 *public_key,
    uint8_t randomness[32U]);

/**
 Encapsulate ML-KEM 768 (unpacked)

 Generates an ([`MlKem768Ciphertext`], [`MlKemSharedSecret`]) tuple.
 The input is a reference to an unpacked public key of type
 [`MlKem768PublicKeyUnpacked`], the SHA3-256 hash of this public key, and
 [`SHARED_SECRET_SIZE`] bytes of `randomness`.
*/
tuple_3c libcrux_ml_kem_mlkem768_portable_encapsulate_unpacked(
    libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked_f8 *public_key,
    uint8_t randomness[32U]);

/**
 Generate ML-KEM 768 Key Pair
*/
libcrux_ml_kem_mlkem768_MlKem768KeyPair
libcrux_ml_kem_mlkem768_portable_generate_key_pair(uint8_t randomness[64U]);

/**
 Generate ML-KEM 768 Key Pair in "unpacked" form
*/
libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked_f8
libcrux_ml_kem_mlkem768_portable_generate_key_pair_unpacked(
    uint8_t randomness[64U]);

/**
 Validate a public key.

 Returns `Some(public_key)` if valid, and `None` otherwise.
*/
core_option_Option_92 libcrux_ml_kem_mlkem768_portable_validate_public_key(
    libcrux_ml_kem_types_MlKemPublicKey_15 public_key);

#if defined(__cplusplus)
}
#endif

#define __libcrux_mlkem768_portable_H_DEFINED
#endif
