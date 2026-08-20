#include"errmess.h"
#include"myEmoji.h"
#include<iostream>

// функции вывода ошибок
auto Errmess::Exeption(const wstr &xstr) -> void {
    std::wcout << MyEmoji::error << L' ' << xstr << L'\n';
}

auto Errmess::Warning(const wstr &xstr) -> void {
    std::wcout << MyEmoji::warning << L' ' << xstr << L'\n';
}

auto Errmess::Info(const wstr &xstr) -> void {
    std::wcout << MyEmoji::inform << L' ' << xstr << L'\n';
}

auto Errmess::Every(const wstr &xstr) -> void {
    std::wcout << MyEmoji::satFace << L' ' << xstr << L'\n';
}
