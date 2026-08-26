#include<iostream>
#include"messout.h"
#include"myEmoji.h"

// пространство имён функций вывода ошибок
namespace MessOut {
auto Exeption(const wstr &xstr) -> void {
    std::wcout << MyEmoji::error << L' ' << xstr << L'\n';
}

auto Warning(const wstr &xstr) -> void {
    std::wcout << MyEmoji::warning << L' ' << xstr << L'\n';
}

auto Info(const wstr &xstr) -> void {
    std::wcout << MyEmoji::inform << L' ' << xstr << L'\n';
}

auto Every(const wstr &xstr) -> void {
    std::wcout << MyEmoji::ok << L' ' << xstr << L'\n';
}

auto Input(const wstr &xstr) -> void {
    std::wcout << MyEmoji::listTasks << L' ' << xstr << L'\n';
}

auto Create(const wstr &xstr) -> void {
    std::wcout << MyEmoji::realiz << L' ' << xstr << L'\n';
}
}
