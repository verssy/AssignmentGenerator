#include <random>

#include "Format.hpp"
#include "Registrator.hpp"
#include "Settings.hpp"
#include "TaskBase.hpp"
#include "TaskFactory.hpp"

class TaskBayes : public TaskBase {
public:
    TaskBayes(const std::string &taskName)
        : TaskBase(taskName), distrMachines(1, 3), distrProbs(10, 90)
    { }

    void Randomize(const int64_t seed) override
    {
        gen.seed(seed);

        for (int64_t i = 0; i < 3; i++) {
            probs[i] = distrProbs(gen) / 100.0;
        }

        machinesCount = distrMachines(gen);
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

    std::string GetDescription() override
    {
        return Format(descriptions[machinesCount - 1], probs[0], probs[1], probs[2]);
    }

    std::string GetAnswer() override
    {
        return ToString(answer);
    }

private:
    std::uniform_int_distribution<int> distrMachines;
    std::uniform_int_distribution<int> distrProbs;
    std::mt19937 gen;

    int machinesCount;
    double probs[3];
    double answer;

    const std::string descriptions[3] = {
        "Решите с использованием формул полной вероятности и Байеса (3 балла)\n"
        "Рабочий обслуживает 3 станка.\n"
        "Вероятность того, что в течение часа не потребует внимания рабочего:\n"
        "первый станок равна {}, второй – {}, третий – {}.\n"
        "Найти вероятность того, что в течение часа потребует внимания 1 станок.",  // 1
        "Решите с использованием формул полной вероятности и Байеса (3 балла)\n"
        "Рабочий обслуживает 3 станка.\n"
        "Вероятность того, что в течение часа не потребует внимания рабочего:\n"
        "первый станок равна {}, второй – {}, третий – {}.\n"
        "Найти вероятность того, что в течение часа потребуют внимания 2 станка.",  // 2
        "Решите с использованием формул полной вероятности и Байеса (3 балла)\n"
        "Рабочий обслуживает 3 станка.\n"
        "Вероятность того, что в течение часа не потребует внимания рабочего:\n"
        "первый станок равна {}, второй – {}, третий – {}.\n"
        "Найти вероятность того, что в течение часа потребуют внимания 3 станка."  // 3
    };
};

Registrator<TaskBayes> registrator("Задание на использование формулы Байеса");
