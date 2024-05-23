#pragma once

#include <string>

class TaskBase {
public:
    TaskBase(const std::wstring &taskName);

    virtual void Randomize() = 0;
    virtual std::wstring GetDescription() = 0;
    virtual void Solve() = 0;
    virtual std::wstring GetAnswer() = 0;

protected:
    std::wstring taskName;
};
