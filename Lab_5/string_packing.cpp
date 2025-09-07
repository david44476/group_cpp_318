#include<iostream>
#include<string>
#include<iomanip>
#include"constans.h"

auto Func (std::string& r_text) -> short;
auto Regist (std::string& r_text) -> void;

// функция по заданию №4
auto StringPacking () -> RetConst {

    std::string s = "Задание 4)";
    std::cout << std::setw(30) << std::right << s << '\n';
    std::cout << "Будем рассматривать символы состоящие из заглавных английских букв.\n"
                 "Например,рассмотрим строку AAAABCCCCCDDDD. Длина этой строки равна 14.\n"
                 "Поскольку строка состоит только из английских букв, повторяющиеся символы \n"
                 "могут быть удалены и заменены числами, определяющими количество повторений.\n"
                 "Таким образом, данная строка может быть представлена как 4AB5C4D.\n"
                 "Описанный метод мы назовем упаковкой строки.\n"
                 "Разработайте программу, которая берет упакованную строчку с буквами в нижнем \n"
                 "регистре и восстанавливает по ней исходную строку с буквами в верхнем регистре.\n"
              << std::endl;

    std::string str{"4ab5c4d"};
    //Func (str);
    for (auto i : Func(str)) {
        std::cout << i;
    }
    Regist (str);
    return Ok;
}


auto Func (std::string& r_text) -> short {
    short size{};
    for (auto i : r_text) {
        if (std::isdigit(i)) ++size;
    }
    short *number = new (std::nothrow) short[size];
    for (auto i : r_text) {
        if (std::isdigit(i)) number[i] = (short)i - (short)'0';
    }
    return *number;
}


// функция преобразования символов в верхний регистр
auto Regist (std::string& r_text) -> void {
    short diff_ul{32}; // разница между пропесными и строчными символами алфавита
    short up_a {90}; // десятичный код символа для проверки условия
    for (auto& i : r_text) {
        if (i >= up_a) i -= diff_ul;
    }
    std::cout << r_text << '\n';
}
