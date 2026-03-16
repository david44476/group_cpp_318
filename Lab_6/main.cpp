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
#include"C_labWork.h" // // обьявляем класс
#include"constans.h" // подключаем константы
#include"errmess.h" // функции для вывода ошибок
#include "lab_work.h"

RetConst (*Select(const unsigned short& f_choice))();

// указатель на функцию для останоки или продолжения выполнения программы по выбору пользователя
const bool (*pStop)(const wstr& str){Stop};




auto main() -> int {

    //bool stop{false}; // переменная для цикла do while
    do {
        // устанавливаем локаль
        setlocale(LC_ALL, "ru_RU.UTF-8");

        // запрашиваем у пользователя номер лабораторной работы
        std::wcout << L"Ведите номер лабораторной работы от " + std::to_wstring(lab_1)  + L" до "
                          + std::to_wstring(lab_12) + L": ";

        // проверяем на коректность ввода
        unsigned short numLab{TypeThecking(numLab, lab_1, lab_12)};
        RetConst(*action)()(Select(numLab)); // получаем указатель на функцию
        if (action){action();} // вызываем лабораторную работу по указателю

        // вызов функции для останоки или продолжения выполнения программы по выбору пользователя
    } while (!(pStop)(L"Хотите продолжить демонстрацию лабораторных работ? "
                      "введите \"Д\" если нет \"Н\": ")); // выход из праграммы по выбору пользователя
    return 0;
}


RetConst (*Select(const unsigned short& f_choice))() {
    switch (f_choice) {
    case lab_1:
        errmess::Info(L"Реализации лабораторной работы № 1 нет!!!\n");
        return nullptr;
    case lab_2:
        errmess::Info(L"Реализации лабораторной работы № 2 нет!!!\n");
        return nullptr;
    case lab_3:
        errmess::Info(L"Реализации лабораторной работы № 3 нет!!!\n");
        return nullptr;
    case lab_4:
        errmess::Info(L"Реализации лабораторной работы № 4 нет!!!\n");
        return nullptr;
    case lab_5:
        errmess::Info(L"Реализации лабораторной работы № 5 нет!!!\n");
        return nullptr;
    case lab_6:
        errmess::Info(L"Вы выбрали лабораторную работу № 6\n");
        return Lab_6;
    case lab_7:
        errmess::Info(L"Реализации лабораторной работы № 7 нет!!!\n");
        return nullptr;
    case lab_8:
        errmess::Info(L"Реализации лабораторной работы № 8 нет!!!\n");
        return nullptr;
    case lab_9:
        errmess::Info(L"Реализации лабораторной работы № 9 нет!!!\n");
        return nullptr;
    case lab_10:
        errmess::Info(L"Реализации лабораторной работы № 10 нет!!!\n");
        return nullptr;
    case lab_11:
        errmess::Info(L"Реализации лабораторной работы № 11 нет!!!\n");
        return nullptr;
    case lab_12:
        errmess::Info(L"Реализации лабораторной работы № 12 нет!!!\n");
        return nullptr;
    default:
        errmess::Info(L"Такой лабораторной пока нет!!!\n");
        return nullptr;
    }
}
