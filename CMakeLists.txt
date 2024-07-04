cmake_minimum_required(VERSION 3.16)

project(AssGen VERSION 0.1 LANGUAGES CXX)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/minidocx-0.5.0)
add_subdirectory(Tasks)

add_executable(Main main.cpp)
set_target_properties(Main PROPERTIES CXX_STANDARD 20)
target_include_directories(Main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Tasks/Base)
target_include_directories(Main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/minidocx-0.5.0/src)
target_link_libraries(Main LINK_PUBLIC TasksLib)
target_link_libraries(Main LINK_PUBLIC minidocx)
