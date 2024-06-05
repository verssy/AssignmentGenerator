#include "Registrator.hpp"
#include "TaskBase.hpp"
#include "TaskFactory.hpp"

class TaskMoney : public TaskBase {
public:
    TaskMoney(const std::string &taskName) : TaskBase(taskName)
    { }

    void Randomize() override
    { }

    std::string GetDescription() override
    {
        return "Штирлиц подбросил монету 2 раза\n"
               "Он не любит, когда выпадает менее двух орлов\n"
               "Найдите вероятность того, что Штирлиц веселый";
    }

    void Solve() override
    {
        probability = 0.5 * 0.5;
    }

    std::string GetAnswer() override
    {
        return std::to_string(probability);
    }

private:
    double probability;
};

Registrator<TaskMoney> registrator("Задача о подбрасывании монетки");