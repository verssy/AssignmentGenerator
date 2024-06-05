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
        std::cout << task->GetDescription() << std::endl;
        task->Solve();
        std::cout << task->GetAnswer() << std::endl;
    }
}
