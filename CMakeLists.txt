cmake_minimum_required(VERSION 3.8)

project(NLiteLib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(NLITELIB_PROJECT_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

option(BUILD_WITH_SIMD "enable simd math." ON)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX /utf-8")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4100")
elseif(GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
    if(BUILD_WITH_SIMD)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4")
    endif(BUILD_WITH_SIMD)
endif()
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS}")

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
