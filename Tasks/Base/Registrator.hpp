#pragma once

#include <string>

#include "TaskFactory.hpp"

template <typename TaskClass>
class Registrator {
public:
    Registrator(const std::string &taskName)
    {
        TaskFactory::GetInstance().RegisterTask<TaskClass>(taskName);
    }
};
