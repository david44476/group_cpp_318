#ifndef ERRMESS_H
#define ERRMESS_H
#include<string>

// пространство имён для функций вывода ошибок
namespace errmess {
auto Exeption(const std::wstring &str) -> void;

auto Warning(const std::wstring &str) -> void;

auto Info(const std::wstring &str) -> void;
}// errmess
#endif // ERRMESS_H
