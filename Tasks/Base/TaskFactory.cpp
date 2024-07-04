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

void TaskFactory::Print(duckx::Document &doc)
{
    duckx::Paragraph par = doc.paragraphs();

    for (int64_t variant = 0; variant < Settings::variants; variant++) {

        for (int64_t i = 0; i < tasks.size(); i++) {
            tasks[i]->Randomize(Settings::seed++);
            tasks[i]->Solve();
            par.insert_paragraph_after("Ответ: " + tasks[i]->GetAnswer());
            par.insert_paragraph_after(tasks[i]->GetDescription());
            par.insert_paragraph_after(Format("Задание {}.", tasks.size() - i));
        }

        par.insert_paragraph_after(Format("Вариант №{}", Settings::variants - variant));
        par.insert_paragraph_after("");
    }
}
