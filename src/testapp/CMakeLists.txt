cmake_minimum_required(VERSION 3.8)

set(target_srcs
  ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} PREFIX "/" FILES ${target_srcs})

get_filename_component(target ${CMAKE_CURRENT_LIST_DIR} NAME)
add_executable(${target})
target_sources(${target} PRIVATE ${target_srcs})
target_include_directories(${target} PRIVATE ${CONAN_INCLUDE_DIRS})
target_link_libraries(${target} PRIVATE ${CONAN_LIBS})
set_target_properties(${target} PROPERTIES FOLDER "CMakeTargets")
