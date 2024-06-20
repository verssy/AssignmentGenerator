#include "TaskFactory.hpp"

TaskFactory &TaskFactory::GetInstance()
{
    static TaskFactory fac;
    return fac;
}

void TaskFactory::Print()
{
    for (auto &task : tasks) {
        task->SetSeed(this->seed);
        task->Randomize();
        std::cout << task->GetDescription() << std::endl;
        task->Solve();
        std::cout << "ОТВЕТ = " << task->GetAnswer() << std::endl;
    }
}

void TaskFactory::SetSeed(int64_t seed)
{
    this->seed = seed;
}
