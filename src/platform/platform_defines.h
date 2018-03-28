#ifndef NLITELIB_PLATFORM_H_
#define NLITELIB_PLATFORM_H_

//https://sourceforge.net/p/predef/wiki/OperatingSystems/
//OS MACROS
#if defined(_WIN32) || defined(_WIN64)
   #define NL_OS_WINDOWS "WINDOWS"
   #define NL_OS NL_OS_WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
    #include "TargetConditionals.h"
    #if defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_IPHONE)
        #define NL_OS_IOS "IOS"
        #define NL_OS NL_OS_IOS
    #elif TARGET_OS_MAC
        #define NL_OS_MAC "MAC"
        #define NL_OS NL_OS_MAC
    #else
        #error "Unknown Apple OS"
    #endif
#elif defined(ANDROID) || defined(__ANDROID__)
    #define NL_OS_ANDROID "ANDROID"
    #define NL_OS NL_OS_ANDROID
#elif defined(__linux__) // android may defined this too, so check after android.
    #define NL_OS_LINUX "LINUX"
    #define NL_OS NL_OS_LINUX
#elif defined(__unix__) // all unices not caught above
    #define NL_OS_UNIX "UNIX"
    #define NL_OS NL_OS_UNIX
#elif defined(_POSIX_VERSION)
    #define NL_OS_POSIX "POSIX"
    #define NL_OS NL_OS_POSIX
#else
    #error "Unknown OS"
#endif

//https://sourceforge.net/p/predef/wiki/Compilers/
//COMPILER MACROS
#if defined(_MSC_VER)
    #define NL_COMPILER_MSVC "MSVC"
    #define NL_COMPILER NL_COMPILER_MSVC
#elif defined(__GNUC__)
    #define NL_COMPILER_GCC "GCC"
    #define NL_COMPILER NL_COMPILER_GCC
#elif defined(__clang__)
    #define NL_COMPILER_CLANG "CLANG"
    #define NL_COMPILER NL_COMPILER_CLANG
#elif defined(__MINGW32__) || defined(__MINGW64__)
    #define NL_COMPILER_MINGW "MINGW"
    #define NL_COMPILER NL_COMPILER_MINGW
#elif defined(__INTEL_COMPILER)
    #define NL_COMPILER_ICC "ICC"
    #define NL_COMPILER NL_COMPILER_ICC
#else
    #error "Unknown compiler"
#endif

//https://sourceforge.net/p/predef/wiki/Architectures/
//CPU MACROS
#if defined(__ia64__) || defined(_M_IA64) || defined(__itanium__)
    #define NL_CPU_IA64 "IA64"
    #define NL_CPU NL_CPU_IA64
#elif defined(__amd64__) || defined(__x86_64__) || defined(_M_AMD64)
    #define NL_CPU_AMD64 "AMD64"
    #define NL_CPU NL_CPU_AMD64
#elif defined(__arm__) || defined(_ARM) || defined(_M_ARM)
    #define NL_CPU_ARM "ARM"
    #define NL_CPU NL_CPU_ARM
#else
    #error "Unknown cpu"
#endif


#endif//NLITELIB_PLATFORM_H_
