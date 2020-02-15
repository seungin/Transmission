cmake_minimum_required(VERSION 3.8)

file(GLOB items LIST_DIRECTORIES TRUE "*")

foreach(item ${items})
  if(IS_DIRECTORY ${item})
    add_subdirectory(${item})
  endif()
endforeach()
