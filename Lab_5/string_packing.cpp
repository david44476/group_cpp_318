#include<iostream>
#include<string>
#include<iomanip>
#include"constans.h"

auto Func (std::string& r_text) -> void;
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

    std::string str {"4ab5c4d"};
    std::cout << "Исходная строка " << str << '\n';
    Regist (str); // вызов функции для преобразования символов в верхний регистр
    Func (str); // вызов функции для распаковки строки
    return Ok;
}

// функция преобразования символов в верхний регистр
auto Regist (std::string& r_text) -> void {
    short diff_ul{32}; // разница между пропесными и строчными символами алфавита
    short down_a {90}; // десятичный код символа для проверки условия
    short up_a {122}; // десятичный код символа для проверки условия
    for (auto& i : r_text) {
        if (i <= up_a && i >= down_a) i -= diff_ul;
    }
}

// функция распаковки строки
auto Func (std::string& r_text) -> void {
    short summ {0};
    short down_a {48};
    short up_a {57};
    for (auto i : r_text) {
        if (i >= down_a && i <= up_a) {
            summ = i - '0';
        }
        for (short j{0}; j < summ; j++) {
            if (i <= 90 && i >= 65) {
                std::cout << i;
            }
        }
    }
    std::cout << '\n';
}
