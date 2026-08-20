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

#include<iostream>
#include"checkInput.h"
#include"constans.h" // содержит константы
#include"errmess.h" // содержит функции вывода ошибок
#include"taskStr.h" // содержит строки с информацией по заданиям
#include"myEmoji.h" // содержит эмодзи

// деклорация функции выбора задания
ProgrEnum TaskSel();
ProgrEnum (*const PtrTaskSel)() = TaskSel; // указатель на функцию TaskSel

// деклорация функции очистки окна терминала
void ClearConsole();
void (*const PtrClearConsole)() = ClearConsole; // указатель на функцию ClearConsole


int main() {

    // устанавливаем локаль
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    // вывод информации по лабораторной работе
    std::wcout << TaskStr::lab6;

    do {
        // выбор задания через указатель на функцию
        const ProgrEnum progrEnum{PtrTaskSel()};

        // задание № 1
        if (progrEnum == ProgrEnum::Task_1) {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            void BrutFor(); // деклорация функции задания № 1
            BrutFor(); // вызов фукции задания № 1
        }

        // задание № 2
        else if (progrEnum == ProgrEnum::Task_2) {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            Errmess::Info(L"На данный момент реализация задания № "
                          + std::to_wstring(static_cast<ushort>(ProgrEnum::Task_3)) + L" отсутствует!!!");
        }

        // задание № 3
        else if (progrEnum == ProgrEnum::Task_3) {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            Errmess::Info(L"На данный момент реализация задания № "
                          + std::to_wstring(static_cast<ushort>(ProgrEnum::Task_4)) + L" отсутствует!!!");
        }

        // задание № 4
        else if (progrEnum == ProgrEnum::Task_4) {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            Errmess::Info(L"На данный момент реализация задания № "
                          + std::to_wstring(static_cast<ushort>(ProgrEnum::Task_5)) + L" отсутствует!!!");
        }

        // задание № 5
        else if (progrEnum == ProgrEnum::Task_5) {
            PtrClearConsole(); // вызов функции для очистки окна терминала через указатель
            Errmess::Info(L"На данный момент реализация задания № "
                          + std::to_wstring(static_cast<ushort>(ProgrEnum::Task_Max)) + L" отсутствует!!!");
        }
        else Errmess::Warning(L"Задания закончились!!!\n");
        std::wcout << TaskStr::seporStr + L'\n';
        std::wcout << MyEmoji::queMark << L" Хотите продолжить демонстрацию лабораторной работы?" << '\n';
    } while (PtrExit());
    return 0;
}
