#include <fstream>
#include <iostream>

#include "Format.hpp"
#include "Settings.hpp"
#include "TaskFactory.hpp"

TaskFactory &TaskFactory::GetInstance()
{
    static TaskFactory fac;
    return fac;
}

void TaskFactory::Print(std::ostream &out)
{
    for (int64_t variant = 0; variant < Settings::variants; variant++) {
        out << "\nВариант №" << variant + 1 << "\n\n";

        for (int64_t i = 0; i < tasks.size(); i++) {
            out << i + 1 << ".\n";
            tasks[i]->Randomize(Settings::seed++);
            out << tasks[i]->GetDescription() << "\n";
            tasks[i]->Solve();
            out << "ОТВЕТ = " << tasks[i]->GetAnswer() << std::endl;
        }
    }
}
