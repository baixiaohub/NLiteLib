#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "simd_vec.h"

using namespace nlite;

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("simd vec are comuted", "[simd vec]")
{
    REQUIRE(simd::set(1.0f) == simd::set(1.0f, 1.0f, 1.0f, 1.0f));

    simd::float_simd128_t v1 = simd::set(1.0f);
    simd::float_simd128_t v2 = simd::set(2.0f);
    simd::float_simd128_t v3 = simd::set(3.0f);
    REQUIRE(simd::add(v1, v2) == v3);
    REQUIRE(simd::sub(v3, v2) == v1);
    REQUIRE(simd::mul(v1, v2) == v2);
}
