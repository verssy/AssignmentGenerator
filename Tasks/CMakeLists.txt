set(BASE_TASKS_SOURCES
    Base/TaskBase.cpp
    Base/TaskFactory.cpp
    Base/Settings.cpp
)

set(TASKS_SOURCES
    TaskBayes.cpp
    TaskMoney.cpp
)

add_library(TasksLib OBJECT ${BASE_TASKS_SOURCES} ${TASKS_SOURCES})
set_target_properties(TasksLib PROPERTIES CXX_STANDARD 20)
target_include_directories(TasksLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Base)
target_include_directories(TasksLib PUBLIC ${PROJECT_SOURCE_DIR}/external/DuckX-1.2.2/src)
target_link_libraries(TasksLib LINK_PUBLIC duckx)
