set(src test_platform_defines.cpp)

add_executable(test_platform_defines ${src})
target_include_directories(test_platform_defines PRIVATE ../ ${NLITELIB_PROJECT_SRC_DIR}/platform)

add_test(nlite_tests test_platform_defines)
