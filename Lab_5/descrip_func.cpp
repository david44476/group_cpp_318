#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include "constans.h"

// псевдоним типа
using wstr = std::wstring;

// деклорация функции преобразования строки в число
auto StrToNum (wstr& fp_str) -> int;

// деклорация функции преобразования числа в строку
auto intToString(int num) -> wstr;

// функция по заданию №7
auto DescripFunc () -> RetConst {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    wstr s = L"Задание 7)";
    std::wcout << std::setw(30) << std::right << s << '\n';
    std::wcout << L"Реализовать самописные функции преобразования числа в строку "
                  "и строки в число." <<'\n';

    wstr str{L"-70000"};
    int num;
    num = StrToNum (str);
    std::wcout << num << L" Тип даных: " << typeid(num).name() << std::endl;
    wstr stroca = intToString(num);
    std::wcout << stroca << L" Тип даных: " << typeid(stroca).name() << std::endl;
    return Ok;
}

// функция преобразования строки в число
auto StrToNum (wstr& fp_str) -> int {

    int num{0}; // число
    int i{0};
    int sign = 0; // знак числа 0- положительное, 1 — отрицательное

    if (fp_str[i] == '-') {
        sign = 1;
        ++i;
    }
    // проверяем, является ли символ цифрой
    while(std::isdigit (fp_str[i])) {

        // добавляем в массив цифру
        num = num * 10 + (fp_str[i] - '0');
        ++i;
    }
    if (sign == 1)
        num = -num;
    return num;
}

// функция преобразования числа в строку
auto intToString(int num) -> wstr {
    wchar_t buffer[32]; // хватит для любого int
    int pos = 0;

    if (num == 0) {
        buffer[pos++] = '0';
    } else {
        bool isNegative = (num < 0);
        unsigned int absNum = (isNegative) ? -num : num;

        // Заполняем буфер с конца
        while (absNum > 0) {
            buffer[pos++] = '0' + (absNum % 10);
            absNum /= 10;
        }

        if (isNegative) buffer[pos++] = '-';
    }

    // Переворачиваем буфер (цифры записаны в обратном порядке)
    std::reverse(buffer, buffer + pos);

    return wstr(buffer, pos);
}
