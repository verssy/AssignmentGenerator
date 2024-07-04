#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

#include "duckx.hpp"

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

    duckx::Document doc(Settings::outFilename);
    doc.open();
    TaskFactory::GetInstance().Print(doc);
    doc.save();
}
