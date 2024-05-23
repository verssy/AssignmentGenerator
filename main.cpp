#include <iostream>
#include <locale>

#include "Tasks/TaskFactory.hpp"

using namespace std;

int main()
{
    std::setlocale(LC_ALL, "");
    TaskFactory::GetInstance().Print();
}