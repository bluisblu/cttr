#ifndef CTTR_TYPES_H
#define CTTR_TYPES_H

// #include "macros.h"

// Note: only include this header inside CTTR-related headers/source code files.
// Don't include this in any libraries, like sdk, pure3d, lua, etc. files

#ifdef NULL
#undef NULL
#endif
#define NULL 0

#ifdef TRUE
#undef TRUE
#endif
#define TRUE 1

#ifdef FALSE
#undef FALSE
#endif
#define FALSE 0

#ifdef __MWERKS__
#define __declspec(x)
// #define asm
#endif

#define WEAK __declspec(weak)

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long size_t;
typedef unsigned long long u64;

typedef unsigned short ushort;
typedef unsigned int uint;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float f32;
typedef double f64;
typedef volatile f32 vf32;
typedef volatile f64 vf64;

typedef int BOOL;

typedef int unknown;

#ifndef __cplusplus
typedef unsigned short wchar_t;
typedef wchar_t wint_t;
#endif

// Basic defines to allow newer-like C++ code to be written

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define null 0

#ifndef NULL
#define NULL 0
#endif

#define UINT32_MAX 0xffffffff

#endif // !TYPES_H
