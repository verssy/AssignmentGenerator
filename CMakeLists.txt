cmake_minimum_required(VERSION 3.16)

project(AssGen VERSION 0.1 LANGUAGES CXX)

add_subdirectory(Tasks)

add_executable(Main main.cpp)
set_target_properties(Main PROPERTIES CXX_STANDARD 20)
target_link_libraries(Main LINK_PUBLIC TasksLib)