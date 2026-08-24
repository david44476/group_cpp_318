#include<iostream>
#include<limits>
#include<cwctype>
#include"checkInput.h"
#include"errmess.h"
#include"myEmoji.h"
#include"taskStr.h"

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

        //choice = std::towupper(cha);
        if (cha != L'Н' && cha != L'Д') {
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Exeption(L"Неверный ввод. Введите \"Д\" или \"Н\".");
        } else {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            //std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            break;
        }
    }
    return (cha == L'Н') ? false : true;
} // Exit функция выхода
