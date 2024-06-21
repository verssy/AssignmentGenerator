#pragma once

#include <cstdint>

namespace Settings {
extern int64_t seed;
extern bool helpRequest;

void ParseSettings(int, char *[]);
void Help();
}  // namespace Settings