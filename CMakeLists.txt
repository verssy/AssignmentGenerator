cmake_minimum_required(VERSION 3.16)

project(AssGen VERSION 0.1 LANGUAGES CXX)

add_compile_options(-g)

add_subdirectory(Tasks)

add_executable(Main main.cpp)
target_include_directories(Main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Tasks/Base)
set_target_properties(Main PROPERTIES CXX_STANDARD 20)
target_link_libraries(Main LINK_PUBLIC TasksLib)
