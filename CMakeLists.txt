project(libsoup_parse)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_definitions(-DLIBSOUP_DISABLE_DEPRECATED )
find_package(Glib REQUIRED)
find_package(LibSoup REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/)

include_directories(${GLIB_INCLUDE_DIRS})
include_directories(${LIBSOUP_INCLUDE_DIRS})

set(TARGET libsoup_parser)

add_executable(${TARGET} parser.c)

target_link_libraries(${TARGET} ${GLIB_LIBRARIES} ${LIBSOUP_LIBRARIES})

