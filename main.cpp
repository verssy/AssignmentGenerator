#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

#include "minidocx.hpp"

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

    docx::Document doc(Settings::outFilename);
    TaskFactory::GetInstance().Print(doc);
    doc.Save();
}
