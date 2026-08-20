#include<iostream>

// функция очистки окна терминала
auto ClearConsole() -> void {
    // \x1B[2J — очистить экран, \x1B[H — вернуть курсор в начало
    std::wcout << L"\x1B[2J\x1B[H";
    std::wcout.flush();
} // ClearConsole функция очистки окна терминала
