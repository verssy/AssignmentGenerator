#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

#include "Settings.hpp"
#include "TaskFactory.hpp"

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "");
    Settings::ParseSettings(argc, argv);
    if (Settings::helpRequest) {
        Settings::Help();
        return 1;
    }

    std::ofstream outFile(Settings::outFilename);
    auto &out = (outFile.is_open() ? outFile : std::cout);
    TaskFactory::GetInstance().Print(out);
}
