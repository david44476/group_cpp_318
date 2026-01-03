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

        wstr str{L"123.78"};
        StrToNum (str);

    return Ok;
}

// функция преобразования строки в число
auto StrToNum (wstr& fp_str) -> void {

    short num{0};
    for(unsigned i{0}; i < fp_str.length(); i++) {

        // проверяем, является ли символ цифрой
        if(std::isdigit(fp_str[i])) {

            // добавляем в массив цифру
            num = num * 10 + (fp_str[i] - '0');
        }
    }
    std::wcout << num << L" Тип даных: " << typeid(num).name() << std::endl;
}
