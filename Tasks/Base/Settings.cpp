#include "Settings.hpp"

namespace Settings {
int64_t seed = 0;
bool helpRequest = false;
std::string outFilename = "";

void ParseSettings(int argc, char *argv[])
{
    std::vector<std::string_view> args(argv + 1, argv + argc);

    for (int64_t i = 0; i < args.size(); i++) {
        if (args[i] == "--seed" || args[i] == "-s" && i < args.size() - 1) {
            seed = std::stoi(args[i + 1].data());
            i++;
        } else if (args[i] == "--out" || args[i] == "-o" && i < args.size() - 1) {
            outFilename = args[i + 1];
            i++;
        } else {
            helpRequest = true;
            break;
        }
    }
}

void Help()
{
    std::cout << "usage: ./Main [-h | --help] [-s | --seed <number>] [-o | --out <file>]\n"
                 "\n"
                 "\thelp\tshow this message\n"
                 "\tseed\tset seed for random\n";
}
}  // namespace Settings