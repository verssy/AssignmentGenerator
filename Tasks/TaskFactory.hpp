#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "TaskBase.hpp"

class TaskFactory {
public:
    static TaskFactory& GetInstance();

    template<typename TaskClass>
    void RegisterTask(const std::wstring &taskName)
    {
        tasks.push_back(std::make_unique<TaskClass>(taskName));
    }

    void Print();

private:
    TaskFactory() = default;
    TaskFactory(const TaskFactory&);

    std::vector<std::unique_ptr<TaskBase>> tasks;
};