#include <fstream>
#include <iostream>

#include "Settings.hpp"
#include "TaskFactory.hpp"

TaskFactory &TaskFactory::GetInstance()
{
    static TaskFactory fac;
    return fac;
}

void TaskFactory::Print(std::ostream &out)
{
    for (auto &task : tasks) {
        task->Randomize(Settings::seed);
        out << task->GetDescription() << std::endl;
        task->Solve();
        out << "ОТВЕТ = " << task->GetAnswer() << std::endl;
    }
}
