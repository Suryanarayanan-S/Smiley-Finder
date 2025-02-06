# Place here all component header amd source files that should be included in library
set(SOURCE_FILES)
set(HEADER_FILES)
include(${CMAKE_CURRENT_LIST_DIR}/core/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/format/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/output/CMakeLists.txt)

# create library
add_library(${TARGET_NAME}_lib
    STATIC
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

set_target_properties(${TARGET_NAME}_lib
    PROPERTIES
    CXX_EXTENSIONS OFF
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(${TARGET_NAME}_lib
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/core
    ${CMAKE_CURRENT_LIST_DIR}/format
    ${CMAKE_CURRENT_LIST_DIR}/output
)

# Main executable
add_executable(${TARGET_NAME} main.cpp)

target_link_libraries(${TARGET_NAME}
    ${TARGET_NAME}_lib
)

install(TARGETS ${TARGET_NAME}
    DESTINATION bin
)