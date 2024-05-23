#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "TaskBase.hpp"

class TaskFactory {
public:
    static TaskFactory &GetInstance();

    template <typename TaskClass>
    void RegisterTask(const std::wstring &taskName)
    {
        tasks.push_back(std::make_unique<TaskClass>(taskName));
    }

    void Print();

private:
    TaskFactory() = default;
    TaskFactory(const TaskFactory &);

    std::vector<std::unique_ptr<TaskBase>> tasks;
};