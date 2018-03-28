#ifndef NLITELIB_PLATFORM_H_
#define NLITELIB_PLATFORM_H_

//https://sourceforge.net/p/predef/wiki/OperatingSystems/
//OS PLATFORM MACROS
#if defined(_WIN32) || defined(_WIN64)
   #define NL_PLATFORM_WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
    #include "TargetConditionals.h"
    #if defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_IPHONE)
        #define NL_PLATFORM_IOS
    #elif TARGET_OS_MAC
        #define NL_PLATFORM_MAC
    #else
        #error "Unknown Apple platform"
    #endif
#elif defined(ANDROID) || defined(__ANDROID__)
    #define NL_PLATFORM_ANDROID
#elif defined(__linux__) // android may defined this too, so check after android.
    // linux
    #define NL_PLATFORM_LINUX
#elif defined(__unix__) // all unices not caught above
    // Unix
    #define NL_PLATFORM_UNIX
#elif defined(_POSIX_VERSION)
    // POSIX
    #define NL_PLATFORM_POSIX
#else
    #error "Unknown platform"
#endif

//https://sourceforge.net/p/predef/wiki/Compilers/
//COMPILER MACROS
#if defined(_MSC_VER)
    #define NL_COMPILER_MSVC
#elif defined(__GNUC__)
    #define NL_COMPILER_GCC
#elif defined(__clang__)
    #define NL_COMPILER_CLANG
#elif defined(__MINGW32__) || defined(__MINGW64__)
    #define NL_COMPILER_MINGW
#elif defined(__INTEL_COMPILER)
    #define NL_COMPILER_ICC
#endif

//https://sourceforge.net/p/predef/wiki/Architectures/
//CPU MACROS
#if defined(__amd64__) || defined(__x86_64__) || defined(_M_AMD64)
    #define NL_CPU_AMD64
#elif defined(__ia64__) || defined(_M_IA64) || defined(__itanium__)
    #define NL_CPU_IA64
#elif defined(__arm__) || defined(_ARM) || defined(_M_ARM)
    #define NL_CPU_ARM
#endif


#endif//NLITELIB_PLATFORM_H_
