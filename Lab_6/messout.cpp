#include <iostream>
#include "messout.h"
#include "myEmoji.h"

// пространство имён функций вывода сообщений
namespace MessOut {

// ошибка
auto Exeption(const std::wstring &xstr) -> void {
    std::wcout << MyEmoji::error << L' ' << xstr << L'\n';
}

// внимание
auto Warning(const std::wstring &xstr) -> void {
    std::wcout << MyEmoji::warning << L' ' << xstr << L'\n';
}

// информация
auto Info(const std::wstring &xstr) -> void {
    std::wcout << MyEmoji::inform << L' ' << xstr << L'\n';
}

// всё хорошо
auto Every(const std::wstring &xstr) -> void {
    std::wcout << MyEmoji::ok << L' ' << xstr << L'\n';
}

// ввод
auto Input(const std::wstring &xstr) -> void {
    std::wcout << MyEmoji::listTasks << L' ' << xstr << L'\n';
}

// создаём
auto Create(const std::wstring &xstr) -> void {
    std::wcout << MyEmoji::realiz << L' ' << xstr << L'\n';
}
}; // MessOut пространство имён функций вывода сообщений
