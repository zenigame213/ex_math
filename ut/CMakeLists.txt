cmake_minimum_required (VERSION 3.16)

set(UNIT_TEST_NAME "libmath_unit_test")

add_executable(${UNIT_TEST_NAME}
    src/main.cpp
    src/ex_math_test.cpp
)

target_link_libraries(${UNIT_TEST_NAME}
    ${PROJECT_NAME}
    ${GTEST_BOTH_LIBRARIES}
    GTest::gmock
    pthread
)

target_include_directories(${UNIT_TEST_NAME}
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

gtest_add_tests(TARGET ${UNIT_TEST_NAME})