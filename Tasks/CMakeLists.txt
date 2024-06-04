set(BASE_TASKS_SOURCES
    Base/TaskBase.cpp
    Base/TaskFactory.cpp
)

set(TASKS_SOURCES
    TaskBayes.cpp
)

add_compile_options(-g)

add_library(TasksLib OBJECT ${BASE_TASKS_SOURCES} ${TASKS_SOURCES})
target_include_directories(TasksLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Base)
set_target_properties(TasksLib PROPERTIES CXX_STANDARD 20)
