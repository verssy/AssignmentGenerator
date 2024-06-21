#include <iostream>
#include <string>
#include <vector>

#include "Settings.hpp"

namespace Settings {
int64_t seed = 0;
bool helpRequest = false;

void ParseSettings(int argc, char *argv[])
{
    std::vector<std::string_view> args(argv + 1, argv + argc);
    try {
        for (int64_t i = 0; i < args.size(); i++) {
            if (args[i] == "-h" || args[i] == "--help") {
                helpRequest = true;
            } else if (args[i] == "--seed" || args[i] == "-s") {
                seed = std::stoi(args.at(i + 1).data());
                i++;
            } else {
                throw std::runtime_error("Unknown argument");
            }
        }
    } catch (std::exception &ex) {
        std::cerr << "ERROR [PARSING]: " << ex.what() << std::endl;
        helpRequest = true;
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