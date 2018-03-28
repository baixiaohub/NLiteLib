#ifndef NL_VECTOR4F_HPP_
#define NL_VECTOR4F_HPP_

#ifdef NL_BUILD_SIMD
#include "../simd/simd_vec.h"
#endif

namespace nlite
{
namespace math
{

struct vector4f
{
float x, y, z, w;
};

//TODO:impl operators.
#ifdef NL_BUILD_SIMD
#else
#endif//NL_BUILD_SIMD

}
}

#endif//NL_VECTOR4F_HPP_