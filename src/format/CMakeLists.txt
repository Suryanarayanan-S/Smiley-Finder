list(APPEND HEADER_FILES
    ${CMAKE_CURRENT_LIST_DIR}/IFormat.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ConsoleFormat.hpp
    ${CMAKE_CURRENT_LIST_DIR}/TextFormat.hpp
    ${CMAKE_CURRENT_LIST_DIR}/XmlFormat.hpp
)

list(APPEND SOURCE_FILES
    ${CMAKE_CURRENT_LIST_DIR}/ConsoleFormat.cpp
    ${CMAKE_CURRENT_LIST_DIR}/TextFormat.cpp
    ${CMAKE_CURRENT_LIST_DIR}/XmlFormat.cpp
)
