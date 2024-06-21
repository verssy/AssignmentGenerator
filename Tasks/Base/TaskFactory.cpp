#include "TaskFactory.hpp"
#include "Settings.hpp"

TaskFactory &TaskFactory::GetInstance()
{
    static TaskFactory fac;
    return fac;
}

void TaskFactory::Print()
{
    for (auto &task : tasks) {
        task->Randomize(Settings::seed);
        std::cout << task->GetDescription() << std::endl;
        task->Solve();
        std::cout << "ОТВЕТ = " << task->GetAnswer() << std::endl;
    }
}
