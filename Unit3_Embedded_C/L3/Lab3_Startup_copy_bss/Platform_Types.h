#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include <stdint.h>
#include <stdbool.h>

#ifndef _Bool
#define _Bool unsigned char
#endif

#define CPU_TYPE            CPU_TYPE_32 
#define CPU_BIT_ORDER       MSB_FIRST 
#define CPU_BYTE_ORDER      HIGH_BYTE_FIRST

#ifndef FALSE
#define FALSE							(boolean)false
#endif
#ifndef TRUE
#define TRUE							(boolean)true
#endif

typedef _Bool							boolean;
typedef unsigned char					uint8;
typedef unsigned short					uint16;
typedef unsigned int					uint32;
typedef unsigned long long				uint64;
typedef	signed char						sint8;
typedef short							sint16;
typedef int								sint32;
typedef long long						sint64;
typedef unsigned char					uint8_least;
typedef unsigned short					uint16_least;
typedef unsigned int					uint32_least;
typedef signed char						sint8least;
typedef short							sint16least;
typedef int								sint32least;
typedef float							float32;
typedef double							float64;

typedef volatile signed char			vint8_t;
typedef volatile unsigned char			vuint8_t;

typedef volatile short					vint16_t;
typedef volatile unsigned short			vuint16_t;

typedef volatile int					vint32_t;
typedef volatile unsigned int			vuint32_t;

typedef volatile long long				vint64_t;
typedef volatile unsigned long long		vuint64_t;

#endif // !PLATFORM_TYPES_H_
