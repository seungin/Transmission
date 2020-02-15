cmake_minimum_required(VERSION 3.8)

project(Transmission)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src)
