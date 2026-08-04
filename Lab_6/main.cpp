/*
* Лабораторная работа № 6
*
* Тема: “Исследование С++ классов в IDE Qt Creator”
*
* Цель работы:
*    1. Закрепить на практике представление о классах.
*    2. Научиться инкапсулировать данные в классах языка С++.
*
* Разработчик: Давыдов Денис Владимирович.
*
* OS: UNIX
*
* locale (кодировка): UTF 8
*/
#include<iostream>
#include<string>

enum class ProgrEnum{Task_1, Task_2, Task_3, Task_4, Task_5};
const ProgrEnum progrEnum = ProgrEnum::Task_1;

int main() {

    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    std::locale loc("ru_RU.UTF-8");
    std::cout.imbue(loc);

    std::wstring text{LR"(              Лабораторная работа № 6

Тема: “Исследование С++ классов в IDE Qt Creator”

Цель работы:
    1. Закрепить на практике представление о классах.
    2. Научиться инкапсулировать данные в классах языка С++.

Разработчик: Давыдов Денис Владимирович.

OS: UNIX

locale (кодировка): UTF 8)"};
    std::wcout << text << '\n' << std::wstring(90, '-') << std::endl;

    if (progrEnum == ProgrEnum::Task_1) {
        void Brutfor();
        Brutfor();
    }
    else if (progrEnum == ProgrEnum::Task_2) {
        void PaliDron();
        PaliDron();
    }
    else if (progrEnum == ProgrEnum::Task_3) {

    }
    else if (progrEnum == ProgrEnum::Task_4) {

    }
    else if (progrEnum == ProgrEnum::Task_5) {

    } else std::cout << "Задания закончились!!!";
    return 0;
}
