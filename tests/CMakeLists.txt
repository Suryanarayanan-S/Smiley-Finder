# Here all test source files should be included.
set(UNITTEST_SOURCE_FILES)
include(${CMAKE_CURRENT_LIST_DIR}/core/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/format/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/output/CMakeLists.txt)

# Here all test header files should be included.
set(UNITTEST_HEADER_FILES
    ${CMAKE_CURRENT_LIST_DIR}/MockFormat.hpp
)

add_executable(${TARGET_NAME}_gtest
    ${UNITTEST_SOURCE_FILES}
    ${UNITTEST_HEADER_FILES}
    gtest_main.cpp
)

target_link_libraries(${TARGET_NAME}_gtest
    PUBLIC
    ${TARGET_NAME}_lib
    gtest
    gmock
)

target_include_directories(${TARGET_NAME}_gtest
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

install(TARGETS ${TARGET_NAME}_gtest
    DESTINATION bin
)
