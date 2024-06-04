#include "Registrator.hpp"
#include "TaskBase.hpp"
#include "TaskFactory.hpp"

#include "Format.hpp"

class TaskBayes : public TaskBase {
public:
    TaskBayes(const std::wstring &taskName) : TaskBase(taskName)
    { }

    void Randomize() override
    {
        for (int64_t i = 0; i < 3; i++) {
            // [0.1; 0.9], step == 0.1
            probs[i] = (rand() % 9 + 1) / 10.0;
        }

        machinesCount = rand() % 3 + 1;
    }

    void Solve() override
    {
        switch (machinesCount) {
            default:
            case 1:
                answer = probs[0] * probs[1] * (1 - probs[2]) +
                         probs[0] * (1 - probs[1]) * probs[2] +
                         (1 - probs[0]) * probs[1] * probs[2];
                return;
            case 2:
                answer = probs[0] * (1 - probs[1]) * (1 - probs[2]) +
                         (1 - probs[0]) * probs[1] * (1 - probs[2]) +
                         (1 - probs[0]) * (1 - probs[1]) * probs[2];
                return;
            case 3:
                answer = (1 - probs[0]) * (1 - probs[1]) * (1 - probs[2]);
                return;
        }
    }

    std::wstring GetDescription() override
    {
        switch (machinesCount) {
            default:
            case 1:
                return Format(descriptionOneMachine, probs[0], probs[1], probs[2]);
            case 2:
                return Format(descriptionTwoMachines, probs[0], probs[1], probs[2]);
            case 3:
                return Format(descriptionThreeMachines, probs[0], probs[1], probs[2]);
        }
    }

    std::wstring GetAnswer() override
    {
        return ToWstring(answer);
    }

private:
    int machinesCount;
    double probs[3];
    double answer;

    const std::wstring descriptionOneMachine =
        L"Решите с использованием формул полной вероятности и Байеса (3 балла)\n"
        "Рабочий обслуживает 3 станка.\n"
        "Вероятность того, что в течение часа не потребует внимания рабочего:\n"
        "первый станок равна {}, второй – {}, третий – {}.\n"
        "Найти вероятность того, что в течение часа потребует внимания 1 станок.";

    const std::wstring descriptionTwoMachines =
        L"Решите с использованием формул полной вероятности и Байеса (3 балла)\n"
        "Рабочий обслуживает 3 станка.\n"
        "Вероятность того, что в течение часа не потребует внимания рабочего:\n"
        "первый станок равна {}, второй – {}, третий – {}.\n"
        "Найти вероятность того, что в течение часа потребуют внимания 2 станка.";

    const std::wstring descriptionThreeMachines =
        L"Решите с использованием формул полной вероятности и Байеса (3 балла)\n"
        "Рабочий обслуживает 3 станка.\n"
        "Вероятность того, что в течение часа не потребует внимания рабочего:\n"
        "первый станок равна {}, второй – {}, третий – {}.\n"
        "Найти вероятность того, что в течение часа потребуют внимания 3 станка.";
};

Registrator<TaskBayes> registrator(L"Задача о подбрасывании монетки");
