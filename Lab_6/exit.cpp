#include<iostream>
#include<cwctype>
#include"checkInput.h" // содержит деклорации функций и указатели на них
#include"errmess.h" // содержит сообщения о действиях
#include"myEmoji.h" // содержит эмодзи
#include"taskStr.h" // содержит строки вывода информации по заданиям

// функция выхода
auto Exit() -> bool {
    wstr choice; // переменная для ввода строки
    wchar_t cha; // вспомогательная переменная
    while (true) {
        do {
            Errmess::Info(L"Продолжить введите \"Д\", закончить введите \"Н\"");
            std::wcout << MyEmoji::fingRight << L' ';
        } while (PtrInStr(choice) != Ret::Ok); // проверяем строку на ввод
        if (choice.length() > 1) {
            Errmess::Warning(L"Вы ввели не один символ!!!");
            continue;
        }

        // переводим символ в верхний регист
        for (auto &i: choice) {
            cha = std::towupper(i);
        }
        if (cha != L'Н' && cha != L'Д') {
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Exeption(L"Неверный ввод. Введите \"Д\" или \"Н\".");
        } else {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            break;
        }
    }
    return (cha == L'Н') ? false : true;
} // Exit функция выхода
