/*
* Лабораторная работа № 6
*
* Тема: “Исследование С++ классов в IDE Qt Creator”
*
* Цели работы:
*    1. Закрепить на практике представление о классах.
*    2. Научиться инкапсулировать данные в классах языка С++.
*
* Разработчик: Давыдов Денис Владимирович.
*
* OS: UNIX
*
* locale (кодировка): UTF 8
*/

#include <iostream>
#include "constans.h" // содержит константы
#include "messout.h" // содержит функции вывода ошибок
#include "taskStr.h" // содержит строки с информацией по заданиям
#include "myEmoji.h" // содержит эмодзи
#include "checkInput.h" // содержит деклорации функций

int main() {

    // устанавливаем локаль
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    // вывод информации по лабораторной работе
    std::wcout << TaskStr::lab6;

    do {
        // выбор задания через указатель на функцию
        const ProgrEnum progrEnum{TaskSel()};

        switch (progrEnum) {
        // задание № 1
        case ProgrEnum::Task_1: {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            void BrutFor(); // деклорация функции задания № 1
            BrutFor(); // вызов фукции задания № 1
            break;
        }

        // задание № 2
        case ProgrEnum::Task_2: {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            void PalDrom(); // деклорация функции задания № 2
            PalDrom(); // вызов фукции задания № 2
            break;
        }

        // задание № 3
        case ProgrEnum::Task_3: {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            void CarBase();
            CarBase();
            break;
        }

        // задание № 4
        case ProgrEnum::Task_4: {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            MessOut::Info(L"На данный момент реализация задания № "
                          + std::to_wstring(static_cast<ushort>(ProgrEnum::Task_5)) + L" отсутствует!!!");
            break;
        }

        // задание № 5
        case ProgrEnum::Task_5: {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            MessOut::Info(L"На данный момент реализация задания № "
                          + std::to_wstring(static_cast<ushort>(ProgrEnum::Task_Max)) + L" отсутствует!!!");
            break;
        }
        default: MessOut::Warning(L"Задания закончились!!!\n");
        }
        std::wcout << TaskStr::seporStr;
        std::wcout << MyEmoji::queMark << L" Хотите продолжить демонстрацию лабораторной работы?" << '\n';
    } while (PtrExit());
    return 0;
}
