set(src test_simd.cpp)

add_executable(test_simd ${src})
target_include_directories(test_simd PRIVATE ../ ${NLITELIB_PROJECT_SRC_DIR}/simd)
#target_link_libraries(test_simd simd_vec)

add_test(nlite_tests test_simd)
