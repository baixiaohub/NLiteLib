#ifndef NLITE_SIMD_VEC_HPP_
#define NLITE_SIMD_VEC_HPP_

#include "../platform/platform_defines.h"

namespace nlite
{
namespace simd
{

//windows intrinsics headers.
//intrin.h	    All Architectures
//mmintrin.h	MMX intrinsics
//xmmintrin.h	Streaming SIMD Extensions intrinsics
//emmintrin.h	Willamette New Instruction intrinsics (SSE2)
//pmmintrin.h	SSE3 intrinsics
//tmmintrin.h	SSSE3 intrinsics
//smmintrin.h	SSE4.1 intrinsics
//nmmintrin.h	SSE4.2 intrinsics
//wmmintrin.h	AES and PCLMULQDQ intrinsics
//immintrin.h	Intel-specific intrinsics(AVX)
//ammintrin.h	AMD-specific intrinsics (FMA4, LWP, XOP)
//mm3dnow.h     AMD 3DNow! intrinsics

//reference
//https://software.intel.com/sites/landingpage/IntrinsicsGuide/
//https://developer.arm.com/technologies/neon/intrinsics

//TODO:impl simd functions and typedefs.
#ifdef NL_OS_WINDOWS
    #include <intrin.h>
    typedef __m128 float_simd128_t;
    // pass by value on x86
    typedef float_simd128_t float_simd128_arg_t;
#elif NL_OS_LINUX
#elif NL_OS_MAC
#elif NL_IO_IOS
#elif NL_OS_ANDROID
    typedef float32x4_t float_simd128_t;
    // pass by value on neon
    typedef float_simd128_t float_simd128_arg_t;
#endif

float_simd128_t set(float s);
float_simd128_t set(float x, float y, float z, float w);
float_simd128_t add(float_simd128_arg_t a, float_simd128_arg_t b);
float_simd128_t sub(float_simd128_arg_t a, float_simd128_arg_t b);
float_simd128_t mul(float_simd128_arg_t a, float_simd128_arg_t b);

template <unsigned int T0, unsigned int T1, unsigned int T2, unsigned int T3>
float_simd128_t Shuffle(float_simd128_arg_t a);

}
}

#endif//NLITE_SIMD_VEC_HPP_