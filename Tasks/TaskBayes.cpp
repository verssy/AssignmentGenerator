#include "Registrator.hpp"
#include "TaskBase.hpp"
#include "TaskFactory.hpp"

#include <format>

class TaskBayes : public TaskBase {
public:
    TaskBayes(const std::wstring &taskName) : TaskBase(taskName)
    { }

    void Randomize() override
    {
        for (int64_t i = 0; i < 3; i++) {
            // [0.01; 0.99]
            probs[i] = (rand() % 9 + 1) / 10.0;
        }
    }

    std::wstring GetDescription() override
    {
        return std::format(
            L"Решите с использованием формул полной вероятности и Байеса (3 балла)\n"
            "Рабочий обслуживает 3 станка.\n"
            "Вероятность того, что в течение часа не потребует внимания рабочего:\n"
            "первый станок равна {}, второй – {}, третий – {}.\n"
            "Найти вероятность того, что в течение часа потребуют внимания 2 станка.",
            probs[0], probs[1], probs[2]);
    }

    void Solve() override
    {
        answer = probs[0] * (1 - probs[1]) * (1 - probs[2]) +
                 (1 - probs[0]) * probs[1] * (1 - probs[2]) +
                 (1 - probs[0]) * (1 - probs[1]) * probs[2];
    }

    std::wstring GetAnswer() override
    {
        return std::to_wstring(answer);
    }

private:
    double probs[3];
    double answer;
};

Registrator<TaskBayes> registrator(L"Задача о подбрасывании монетки");
