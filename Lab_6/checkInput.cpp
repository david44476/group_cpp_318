#include<iostream>
#include<limits>
#include"constans.h"
#include"errmess.h"
#include"myEmoji.h"
#include"taskStr.h"
#include"checkInput.h"

// функция обработки ввода для std::wstring с диапазонами проверки
auto CheckInput(wstr &xvalue, const ushort &xmin, const ushort &xmax, const wstr &xstr) -> bool {
    while (true) {
        if (!std::getline(std::wcin, xvalue)) {
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Warning(L"Ошибка чтения ввода!");
            return Ret::ErrData;
        } else if (xvalue.empty()) { // проверяем не пустая ли строка пароля
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Warning(L"Парол не должен быть пустой!!!");
            return Ret::EmptyLine;
        }
        bool flag{false};
        for (auto ch: xvalue) { // прверяем не содержит ли строка пробелов, символов табуляции
            if (std::iswspace(ch)) {
                flag = true;
                break;
            }
        }
        if (flag) {
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Warning(L"Пароль не должен содержать пробелов, символов табуляции!!!");
            return Ret::OutRange;
        }
        if (xvalue.length() < xmin || xvalue.length() > xmax) {
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Exeption(xstr);
            return Ret::OutRange;
        }
        return Ret::Ok;
    } 
} // CheckInput функция обработки ввода для std::wstring с диапазонами проверки

// функция обработки ввода для std::wstring
auto CheckInput(wstr &xvalue) -> short {
    while (true) {
        if (!std::getline(std::wcin, xvalue)) {
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Warning(L"Ошибка чтения ввода!");
            return Ret::ErrData;
        } else if (xvalue.empty()) {
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Warning(L"Строка не должна быть пустой!!!");
            return Ret::EmptyLine;
        }
        bool flag{false};
        for (auto ch: xvalue) { // прверяем не содержит ли строка пробелов, символов табуляции
            if (std::iswspace(ch)) {
                flag = true;
                break;
            }
        }
        if (flag) {
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Warning(L"Строка символов не должна содержать пробелов, символов табуляции!!!");
            return Ret::OutRange;
        }
        return Ret::Ok;
    }
} // CheckInput функция обработки ввода для std::wstring

// функция преобразования строки в число
auto StrNum(const wstr &xstr) -> short {
    size_t i{0};
    bool flag{false};
    wchar_t nul{L'0'};
    if (xstr[0] == L'-') {
        flag = true;
        ++i;
    } else if (xstr[0] == L'+') ++i;

    short didStr{0};
    while (i < xstr.size() && std::iswdigit(xstr[i])) {
        didStr = didStr * 10 + (xstr[i] - nul);
        ++i;
    }
    if (flag) didStr = -didStr;
    return didStr;
} // StrNum функция преобразования строки в число

// функция обработки ввода для unsigned short
auto CheckInput(ushort &xvalue, const ushort &xmin, const ushort &xmax,
                const wstr &xstr, PtrStrNum fPtrStr) -> short {
    while (true) {
        wstr bufStr;
        if (!(std::getline(std::wcin, bufStr)) || bufStr.empty()) {
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Warning(L"Ошибка ввода!!!");
            return Ret::ErrData;
        }
        for (auto i: bufStr) {
            if (std::iswalpha(i) || std::iswspace(i)) {
                std::wcout << TaskStr::seporStr; // вывод разделителя =
                Errmess::Warning(L"Вы ввели не число!!!");
                return Ret::OutRange;
            }
        }
        short tmp = fPtrStr(bufStr); // знаковый тип чтобы поймать минус
        if (tmp  <= 0) {
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Warning(L"Нельзя вводить нулевые и отрицательные значения!!!");
            return Ret::OutRange;
        }
        xvalue = static_cast<ushort>(tmp);
        if (xvalue < xmin || xvalue > xmax) {
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Warning(xstr);
            return Ret::OutRange;
        }
        return Ret::Ok;
    }
} // CheckInput перегружкнная шаблонная функция обработки ввода

// функция обработки ввода для wchar_t
auto CheckInput() -> bool {
    wchar_t xchoice;
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
