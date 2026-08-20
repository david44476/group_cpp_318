#include<iostream>
#include<limits>
#include"constans.h"
#include"errmess.h"
#include"myEmoji.h"
#include"checkInput.h"

// функция обработки ввода для std::wstring
auto CheckInput(wstr &xvalue, const ushort &xmin, const ushort &xmax, const wstr &xstr) -> bool {
    while (true) {
        if (!(std::wcin >> xvalue)
            || xvalue.length() < xmin
            || xvalue.length() > xmax) {
            Errmess::Exeption(xstr);
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            return false;
        } else break;
    }
    return true;
} // CheckInput функция обработки ввода для std::wstring

// перегружкнная функция обработки ввода для unsigned short
auto CheckInput(ushort &xvalue, const ushort &xmin, const ushort &xmax, const wstr &xstr) -> bool {
    while (true) {
        std::wcout << MyEmoji::fingRight << L' ';

        // читаем знаковый тип чтобы поймать минус
        short tmp;
        if (!(std::wcin >> tmp)) {
            Errmess::Warning(L"Вы ввели не число!!! Ведите число от " + std::to_wstring(xmin) + L" до "
                             + std::to_wstring(xmax));
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            continue;
        }
        if (tmp < 0) {
            Errmess::Warning(L"Нельзя вводить отрицательные числа!!! Ведите число от "
                             + std::to_wstring(xmin) + L" до " + std::to_wstring(xmax));
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            continue;
        }
        xvalue = static_cast<ushort>(tmp);
        if (xvalue < xmin || xvalue > xmax) {
            Errmess::Warning(xstr);
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            continue;
        }
        return true;
    }
} // CheckInput перегружкнная шаблонная функция обработки ввода

// перегружкнная функция обработки ввода для wchar_t
auto CheckInput(wchar_t xchoice) -> bool {
    while (true) {
        std::wcout << MyEmoji::fingRight << L' ';
        if (!(std::wcin >> xchoice) || !(iswalpha(xchoice))) {
            Errmess::Warning(L"Вы ввели не символ!!! Ведите \"Д\" или \"Н\"");
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            continue;
        }

        // переводим символ в верхний регист
        xchoice = std::towupper(xchoice);
        if (xchoice != L'Н' && xchoice != L'Д') {
            Errmess::Exeption(L"Неверный ввод. Введите \"Д\" или \"Н\".");
        } else {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            break;
        }
    }
    return (xchoice == L'Н') ? false : true;
} // CheckInput перегружкнная функция обработки ввода для wchar_t
