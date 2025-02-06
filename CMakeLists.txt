cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME smileyfinder)
project(${TARGET_NAME} LANGUAGES CXX)

OPTION(ENABLE_UT_BUILD "set to ON to enable the build of Unit Tests." OFF)
OPTION(ENABLE_COVERAGE_BUILD "set to ON to enable the coverage." OFF)

if(ENABLE_COVERAGE_BUILD)
    add_compile_options(-O0 -g3 -fprofile-arcs -ftest-coverage)
    link_libraries(gcov)
endif(ENABLE_COVERAGE_BUILD)

add_subdirectory(src)

if(ENABLE_UT_BUILD)
    add_subdirectory(tools/googletest)
    add_subdirectory(tests)
endif(ENABLE_UT_BUILD)

MESSAGE("-- ENABLE_UT_BUILD          = ${ENABLE_UT_BUILD}")
MESSAGE("-- ENABLE_COVERAGE_BUILD    = ${ENABLE_COVERAGE_BUILD}")
