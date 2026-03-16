#include<iostream>

// пространство имён для функций вывода ошибок
namespace errmess {
auto Exeption(const std::wstring& f_str) -> void {
    std::wcout << L"Ошибка: " << f_str;
}

auto Warning(const std::wstring& f_str) -> void {
    std::wcout << L"Предупреждение: " << f_str;
}

auto Info(const std::wstring& f_str) -> void {
    std::wcout << L"Информация: " << f_str;
}
}// errmess
