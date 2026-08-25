#include<iostream>
#include<iomanip>
#include"constans.h" // содержит константы
#include"messout.h" // содержит сообщения о действиях
#include"myEmoji.h" // содержит эмодзи
#include"taskStr.h" // содержит строки вывода информации по заданиям
#include"checkInput.h" // содержит деклорации функций и указатели на них

// функция выбора задания
auto TaskSel(PtrChec xPtrChec) -> ProgrEnum {
    std::wcout << std::setw(9) << MyEmoji::brain << L" ЗАДАНИЯ К ЛАБОРАТОРНОЙ РАБОТЕ № 6 "
               << MyEmoji::brain << '\n';
    std::wcout << TaskStr::strTask1; // вывод задания № 1
    std::wcout << TaskStr::strTask2; // вывод задания № 2
    std::wcout << TaskStr::strTask3; // вывод задания № 3
    std::wcout << TaskStr::strTask4; // вывод задания № 4
    std::wcout << TaskStr::strTask5; // вывод задания № 5
    std::wcout << std::setw(9) << MyEmoji::fingRight << L" ВЫБЕРИТЕ ЗАДАНИЕ ДЛЯ ДЕМОНСТРАЦИИ "
               << MyEmoji::fingLeft << '\n';

    ushort choice{0}; // переменная выбора задания

    // цикл проверки ввода
    do {
        MessOut::Info(TaskStr::msg); // выводим условия ввода
        std::wcout << MyEmoji::fingRight << L' '; // приглашение к вводу
    } while (xPtrChec(choice, static_cast<ushort>(ProgrEnum::Task_2),
                      static_cast<ushort>(ProgrEnum::Task_Max),
                      L"Данного задания не предусмотренно!!!", PtrNumStr) != Ret::Ok);
    switch (choice) {
    case 1: {
        return ProgrEnum::Task_1;
    }
    case 2: {
        return ProgrEnum::Task_2;
    }
    case 3: {
        return ProgrEnum::Task_3;
    }
    case 4: {
        return ProgrEnum::Task_4;
    }
    case 5: {
        return ProgrEnum::Task_5;
    }
    default: return ProgrEnum::Task_Max;
    }
} // TaskSel функция выбора задания
