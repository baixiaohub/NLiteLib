#include <cstdio>
#include "platform_defines.h"

int main()
{
    std::printf("OS: %s\n", NL_OS);
    std::printf("COMPILER: %s\n", NL_COMPILER);
    std::printf("CPU: %s\n", NL_CPU);
#ifdef NL_BUILD_SIMD
    std::printf("Defined NL_BUILD_SIMD\n");
#else
    std::printf("Not defined NL_BUILD_SIMD\n");
#endif
}
