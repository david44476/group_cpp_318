#include<iostream>
#include<limits>
#include<cwctype>
#include"checkInput.h"
#include"errmess.h"
#include"myEmoji.h"

// функция выхода
auto Exit() -> bool {
    wchar_t choice;
    Errmess::Info(L"введите \"Д\", если хотите закончить введите \"Н\"");
    while (true) {
        std::wcout << MyEmoji::fingRight << L' ';
        if (!(std::wcin >> choice) || !(std::iswalpha(choice))) {
            Errmess::Warning(L"Вы ввели не символ!!! Ведите \"Д\" или \"Н\"");
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            continue;
        }

        // переводим символ в верхний регист
        choice = std::towupper(choice);
        if (choice != L'Н' && choice != L'Д') {
            Errmess::Exeption(L"Неверный ввод. Введите \"Д\" или \"Н\".");
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
        } else {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            break;
        }
    }
    return (choice == L'Н') ? false : true;
} // Exit функция выхода
