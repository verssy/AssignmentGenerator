#pragma once

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

inline std::string ToString(const char *arg)
{
    return std::string(arg);
}

template <size_t ArrSize>
inline std::string ToString(char (&arg)[ArrSize])
{
    return arg;
}

template <typename T>
inline std::string ToString(T &&arg)
{
    return std::to_string(arg);
}

template <>
inline std::string ToString<std::string>(std::string &&arg)
{
    return arg;
}

template <typename... Args>
inline std::string Format(const std::string &formatStr, Args &&...args)
{
    std::ostringstream stream;
    std::vector<std::string> arguments = { ToString(std::forward<Args>(args))... };
    size_t argIndex = 0;
    int lastPos = 0;
    int pos = 0;

    while ((pos = formatStr.find("{}", lastPos)) != std::string::npos) {
        stream << formatStr.substr(lastPos, std::max(0, pos - lastPos));
        stream << arguments[argIndex++];
        lastPos = pos + 2;
    }

    stream << formatStr.substr(lastPos);

    return stream.str();
}
