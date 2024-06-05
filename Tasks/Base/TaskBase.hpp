#pragma once

#include <string>

class TaskBase {
public:
    TaskBase(const std::string &taskName);

    virtual void Randomize() = 0;
    virtual std::string GetDescription() = 0;
    virtual void Solve() = 0;
    virtual std::string GetAnswer() = 0;

protected:
    std::string taskName;
};
