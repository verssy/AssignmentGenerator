#pragma once

#include <string>

#include "TaskFactory.hpp"

template<typename TaskClass>
class Registrator {
public:
    Registrator(const std::wstring &taskName)
    {
        TaskFactory::GetInstance().RegisterTask<TaskClass>(taskName);
    }
};