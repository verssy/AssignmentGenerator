#include "Settings.hpp"

namespace Settings {
int64_t seed = 0;
bool helpRequest = false;
std::string outFilename = "";
int64_t variants = 1;

std::pair<bool, int64_t> ParseInt(std::string_view str)
{
    try {
        return { true, std::stoi(str.data()) };
    } catch (const std::invalid_argument &) {
        return { false, 0 };
    }
}

void ParseSettings(int argc, char *argv[])
{
    std::vector<std::string_view> args(argv + 1, argv + argc);

    for (int64_t i = 0; i < args.size(); i++) {
        if (args[i] == "--seed" || args[i] == "-s" && i < args.size() - 1) {
            const auto [parsed, value] = ParseInt(args[i + 1]);
            seed = value;
            helpRequest |= !parsed;
            i++;
        } else if (args[i] == "--out" || args[i] == "-o" && i < args.size() - 1) {
            outFilename = args[i + 1];
            outFilename.append(".docx");
            i++;
        } else if (args[i] == "--variants" || args[i] == "-v" && i < args.size() - 1) {
            const auto [parsed, value] = ParseInt(args[i + 1]);
            variants = value;
            helpRequest |= !parsed;
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
                 "\t[-v | --variants <number>]\n"
                 "\n"
                 "\thelp\tshow this message\n"
                 "\tseed\tset seed for random\n";
}
}  // namespace Settings