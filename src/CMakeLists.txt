cmake_minimum_required(VERSION 3.1)

project(Transmission)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(target "testapp")
add_executable(${target})
target_sources(${target} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/main.cpp)
target_include_directories(${target} PRIVATE ${CONAN_INCLUDE_DIRS})
target_link_libraries(${target} PRIVATE ${CONAN_LIBS})
