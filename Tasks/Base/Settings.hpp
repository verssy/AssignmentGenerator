#pragma once

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace Settings {
extern int64_t seed;
extern bool helpRequest;
extern std::string outFilename;
extern int64_t variants;

void ParseSettings(int, char *[]);
void Help();
}  // namespace Settings