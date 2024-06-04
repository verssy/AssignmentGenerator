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
std::wstring Format(const std::wstring &formatStr, Args &&...args)
{
    std::wostringstream stream;
    std::vector<std::wstring> arguments = { ToWstring(std::forward<Args>(args))... };
    size_t argIndex = 0;

    try {
        for (int64_t i = 0; i < formatStr.length(); i++) {
            if (formatStr[i] == L'{' && formatStr[i + 1] == L'}') {
                stream << arguments[argIndex++];
                i++;
            } else {
                stream << formatStr[i];
            }
        }
    } catch (std::out_of_range &error) {
        std::cerr << "Bad format: Format() doesn't allow any chars but '}' after '{'" << std::endl;
        return std::wstring{};
    }

    return stream.str();
}
