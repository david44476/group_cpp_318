#include<iostream>
#include<string>
#include<iomanip>
#include"constans.h"

auto unpackString (std::string& r_text) -> std::string;
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

    std::string str {"10a5b11c6d"};
    std::cout << "Начальная строка: " << str << '\n';
    Regist (str);
    std::cout << "Распакованная строка: " << unpackString (str) << '\n';
    return Ok;
}

// функция преобразования символов в верхний регистр
auto Regist (std::string& r_text) -> void {
    short diff_ul{32}; // разница между пропесными и строчными символами алфавита
    short down_a {97}; // десятичный код символа 'a' для проверки условия
    short up_a {122}; // десятичный код символа 'z' для проверки условия
    for (auto& i : r_text) {
        if (i <= up_a && i >= down_a) i -= diff_ul;
    }
}

// функция распаковки строки
auto unpackString (std::string& r_text) -> std::string {
    short summ {0}; // накопленное число повторений
    short down_a {48}; // десятичный код символа '0' для проверки условия
    short up_a {57}; // десятичный код символа '9' для проверки условия
    std::string result;  // итоговая распакованная строка
    for (char i : r_text) {
        if (i >= down_a && i <= up_a) {
            // накапливаем число (учитываем многозначные числа)
            summ = summ * 10 + (i - down_a);
        }
        else if (i >= 65 && i <= 90) {
            // буква: преобразуем в верхний регистр и повторяем summ раз
            // если summ == 0, то считаем, что повтор 1 раз
            int repeat = (summ > 0) ? summ : 1;
            char upperChar = i;
            result.append(repeat, upperChar);
            // сбрасываем счётчик после использования
            summ = 0;
        }
    }
    return result;
}
