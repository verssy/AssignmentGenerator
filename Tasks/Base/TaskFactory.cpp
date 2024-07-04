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

void TaskFactory::Print(docx::Document &doc)
{
    for (int64_t variant = 0; variant < Settings::variants; variant++) {
        auto pVar = doc.AppendParagraph(Format("Вариант №{}", variant + 1), 14);
        pVar.SetFontStyle(docx::Run::Bold);

        for (int64_t i = 0; i < tasks.size(); i++) {
            tasks[i]->Randomize(Settings::seed++);
            tasks[i]->Solve();

            auto pTaskNum = doc.AppendParagraph(Format("Задание {}.", i + 1), 12);
            pTaskNum.SetFontStyle(docx::Run::Bold);
            pTaskNum.SetLineSpacingSingle();

            auto pTask = doc.AppendParagraph(tasks[i]->GetDescription(), 12);
            pTask.SetLineSpacingSingle();

            auto pAnswer = doc.AppendParagraph("Ответ: " + tasks[i]->GetAnswer(), 12);
            pAnswer.SetLineSpacingSingle();
        }
    }
}
