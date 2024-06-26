#include <iostream>
#include <locale>
#include <string>
#include <vector>

#include "Settings.hpp"
#include "TaskFactory.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "");
    Settings::ParseSettings(argc, argv);
    if (Settings::helpRequest) {
        Settings::Help();
        return 1;
    }

    TaskFactory::GetInstance().Print();
}
