#include <iostream>
#include"errmess.h"

// функции вывода ошибок
auto errmess::Exeption(const std::wstring &str)-> void {
    std::wcerr << L"Ошибка: " << str;
}

auto errmess::Warning(const std::wstring &str)-> void {
    std::wcout << L"Предупреждение: " << str;
}

auto errmess::Info(const std::wstring &str)-> void {
    std::wcout << L"Информация: " << str;
}
