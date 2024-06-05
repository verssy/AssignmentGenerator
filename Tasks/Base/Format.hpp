#pragma once

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::string ToString(const char *arg)
{
    return std::string(arg);
}

template <size_t ArrSize>
std::string ToString(char (&arg)[ArrSize])
{
    return arg;
}

template <typename T>
std::string ToString(T &&arg)
{
    return std::to_string(arg);
}

template <>
std::string ToString<std::string>(std::string &&arg)
{
    return arg;
}

template <typename... Args>
std::string Format(const std::string &formatStr, Args &&...args)
{
    std::ostringstream stream;
    std::vector<std::string> arguments = { ToString(std::forward<Args>(args))... };
    size_t argIndex = 0;

    try {
        for (size_t i = 0; i < formatStr.length(); i++) {
            if (formatStr[i] == L'{' && formatStr[i + 1] == L'}') {
                stream << arguments[argIndex++];
                i++;
            } else {
                stream << formatStr[i];
            }
        }
    } catch (std::out_of_range &error) {
        std::cerr << "Bad format: Format() doesn't allow any chars but '}' after '{'" << std::endl;
        return std::string{};
    }

    return stream.str();
}
