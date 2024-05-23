set(BASE_TASKS_SOURCES
    TaskBase.cpp
    TaskFactory.cpp
)

set(TASKS_SOURCES
    TaskMoney.cpp
)

add_library(TasksLib OBJECT ${BASE_TASKS_SOURCES} ${TASKS_SOURCES})