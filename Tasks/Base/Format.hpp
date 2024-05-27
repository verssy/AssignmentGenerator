#pragma once

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::wstring ToWstring(const wchar_t *arg)
{
    return std::wstring(arg);
}

template <size_t WcharArrSize>
std::wstring ToWstring(wchar_t (&arg)[WcharArrSize])
{
    return arg;
}

template <typename T>
std::wstring ToWstring(T &&arg)
{
    return std::to_wstring(arg);
}

template <>
std::wstring ToWstring<std::wstring>(std::wstring &&arg)
{
    return arg;
}

template <typename... Args>
std::wstring Format(const std::wstring &format_str, Args &&... args)
{
    std::wostringstream stream;
    std::vector<std::wstring> arguments = { ToWstring(std::forward<Args>(args))... };
    size_t arg_index = 0;
    size_t pos = 0;
    size_t prev_pos = 0;

    while ((pos = format_str.find(L"{}", prev_pos)) != std::wstring::npos) {
        stream << format_str.substr(prev_pos, pos - prev_pos);

        if (arg_index < arguments.size()) {
            stream << arguments[arg_index++];
        } else {
            throw std::runtime_error("Not enough arguments provided for the format string");
        }

        prev_pos = pos + 2;
    }

    stream << format_str.substr(prev_pos);

    return stream.str();
}
