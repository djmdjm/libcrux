/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc
  F* version: b5cb71b8
  KaRaMeL version: 40e3a603
 */

#ifndef __libcrux_platform_H
#define __libcrux_platform_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"

extern bool libcrux_platform_platform_simd256_support(void);

extern bool libcrux_platform_platform_simd128_support(void);

#if defined(__cplusplus)
}
#endif

#define __libcrux_platform_H_DEFINED
#endif
