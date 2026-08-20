#ifndef CHECKINPUT_H
#define CHECKINPUT_H

#include"errmess.h"
#include<iostream>
#include<limits>

// функция выхода
bool Exit();
bool (*const PtrExit)() = Exit; // указатель на функцию Exit

template<typename T>
bool CheckInput(T &xvalue) {
    while (true) {

        // ошибка ввода (EOF, сбой потока)
        if (!(std::wcin >> xvalue)) {
            Errmess::Exeption(L"Ошибка ввода. Попробуйте снова.");
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            return false;
        } else break;
    }
    return true;
}

template<typename T>
bool CheckInput(T &xvalue, const ushort &xmin, const ushort &xmax, const wstr &xstr) {
    while (true) {
        if (!(std::wcin >> xvalue)
            || xvalue < xmin
            || xvalue > xmax) {
            Errmess::Exeption(xstr);
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            return false;
        } else break;
    }
    return true;
}

bool CheckInput(wstr &xvalue, const ushort &xmin, const ushort &xmax, const wstr &xstr);
#endif // CHECKINPUT_H
