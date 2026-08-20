#include "checkInput.h"
#include "errmess.h"
#include "myEmoji.h"
#include <iostream>
auto Exit() -> bool {
    wchar_t choice;
    while (true) {
        Errmess::Info(L"Введите 'Д', если хотите закончить введите 'Н'");
        std::wcout << MyEmoji::fingRight << L' ';

        // ошибка ввода (EOF, сбой потока)
        if (!CheckInput(choice)) {
            continue;
        }

        // переводим символ в верхний регист
        choice = std::towupper(choice);
        if (choice != L'Н' && choice != L'Д') {
            Errmess::Exeption(L"Неверный ввод. Введите 'Д' или 'Н'.");
        } else break;
    }
    return (choice == L'Н') ? false : true;
}
