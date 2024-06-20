#include <iostream>
#include <locale>
#include <string>
#include <vector>

#include "TaskFactory.hpp"

using namespace std;

namespace Settings {
int64_t seed = 0;
int64_t isHelpRequested = false;

void ParseSettings(int argc, char *argv[])
{
    std::vector<std::string_view> args(argv + 1, argv + argc);
    try {
        for (int64_t i = 0; i < args.size(); i++) {
            if (args[i] == "-h" || args[i] == "--help") {
                isHelpRequested = true;
            } else if (args[i] == "--seed" || args[i] == "-s") {
                seed = std::stoi(args.at(i + 1).data());
                i++;
            } else {
                throw std::runtime_error("Unknown argument");
            }
        }
    } catch (std::exception &ex) {
        std::cerr << "ERROR [PARSING]: " << ex.what() << std::endl;
        isHelpRequested = true;
    }
}

void Help()
{
    std::cout << "usage: ./Main [-h | --help] [-s | --seed <number>]\n"
                 "\n"
                 "\thelp\tshow this message\n"
                 "\tseed\tset seed for random\n";
}
}  // namespace Settings

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "");
    Settings::ParseSettings(argc, argv);
    if (Settings::isHelpRequested) {
        Settings::Help();
        return 1;
    }

    TaskFactory::GetInstance().SetSeed(Settings::seed);
    TaskFactory::GetInstance().Print();
}
