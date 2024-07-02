#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "TaskBase.hpp"

class TaskFactory {
public:
    static TaskFactory &GetInstance();

    template <typename TaskClass>
    void RegisterTask(const std::string &taskName)
    {
        tasks.push_back(std::make_unique<TaskClass>(taskName));
    }

    void Print(std::ostream &out);
    void SetSeed(int64_t seed);

private:
    TaskFactory() = default;
    TaskFactory(const TaskFactory &);

    std::vector<std::unique_ptr<TaskBase>> tasks;
    int64_t seed;
};
