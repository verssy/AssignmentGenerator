#include "TaskFactory.hpp"
#include "TaskBase.hpp"
#include "Registrator.hpp"

class TaskMoney : public TaskBase {
public:
    TaskMoney(const std::wstring &taskName) : TaskBase(taskName)
    { }

    void Randomize() override
    { }

    std::wstring GetDescription() override
    {
        return
            L"Штирлиц подбросил монету 2 раза\n"
            "Он не любит, когда выпадает менее двух орлов\n"
            "Найдите вероятность того, что Штирлиц веселый";
    }

    void Solve() override
    {
        probability = 0.5 * 0.5;
    }

    std::wstring GetAnswer() override
    {
        return std::to_wstring(probability);
    }

private:
    double probability;
};

Registrator<TaskMoney> registrator(L"Задача о подбрасывании монетки");