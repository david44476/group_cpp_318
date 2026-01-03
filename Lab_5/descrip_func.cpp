#include <iostream>
#include <string>
#include <iomanip>
#include "constans.h"

// псевдоним типа
using wstr = std::wstring;
auto StrToNum (wstr& fp_str) -> void;

// функция по заданию №7
auto DescripFunc () -> RetConst {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    wstr s = L"Задание 7)";
    std::wcout << std::setw(30) << std::right << s << '\n';
    std::wcout << L"Реализовать самописные функции преобразования числа в строку "
                  "и строки в число." <<'\n';

    wstr str{L"-70000"};
    StrToNum (str);

    return Ok;
}

// функция преобразования строки в число
auto StrToNum (wstr& fp_str) -> void {

    int num{0}; // число
    int i{0};
    int sign = 0; // знак числа 0- положительное, 1 — отрицательное

    if (fp_str[i] == '-') {
        sign = 1;
        ++i;
    }
    // проверяем, является ли символ цифрой
    while(std::isdigit(fp_str[i])) {

        // добавляем в массив цифру
        num = num * 10 + (fp_str[i] - '0');
        ++i;
    }
    if (sign == 1)
        num = -num;
    std::wcout << num << L" Тип даных: " << typeid(num).name() << std::endl;
}
