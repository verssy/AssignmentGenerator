#include "TaskFactory.hpp"

TaskFactory &TaskFactory::GetInstance()
{
    static TaskFactory fac;
    return fac;
}

void TaskFactory::Print()
{
    for (auto &task : tasks) {
        task->Randomize();
        std::wcout << task->GetDescription() << std::endl;
        task->Solve();
        std::wcout << task->GetAnswer() << std::endl;
    }
}
