#include<iostream>
#include<iomanip>
#include"constans.h"
#include"errmess.h"
#include"myEmoji.h"
#include"taskStr.h"
#include"checkInput.h"

// функция выбора задания
auto TaskSel() -> const ProgrEnum {
    std::wcout << std::setw(9) << MyEmoji::brain << L" ЗАДАНИЕ К ЛАБОРАТОРНОЙ РАБОТЕ № 6 "
               << MyEmoji::brain << '\n';
    std::wcout << TaskStr::strTask1; // вывод задания № 1
    std::wcout << TaskStr::strTask2; // вывод задания № 2
    std::wcout << TaskStr::strTask3; // вывод задания № 3
    std::wcout << TaskStr::strTask4; // вывод задания № 4
    std::wcout << TaskStr::strTask5; // вывод задания № 5
    std::wcout << std::setw(9) << MyEmoji::fingRight << L" ВЫБЕРИТЕ ЗАДАНИЕ ДЛЯ ДЕМОНСТРАЦИИ "
               << MyEmoji::fingLeft << '\n';

    ushort choice; // переменная выбора задания
    while (true){
        Errmess::Info(TaskStr::msg); // выводим условия ввода
        if (PtrUshor(choice, static_cast<ushort>(ProgrEnum::Task_2), // проверяем ввод
                       static_cast<ushort>(ProgrEnum::Task_Max), L"Данного задания не предусмотренно!!!")) {
            break;
        }
    }
    switch (choice) {
    case 1: {
        return ProgrEnum::Task_1;
        break;
    }
    case 2: {
        return ProgrEnum::Task_2;
        break;
    }
    case 3: {
        return ProgrEnum::Task_3;
        break;
    }
    case 4: {
        return ProgrEnum::Task_4;
        break;
    }
    case 5: {
        return ProgrEnum::Task_5;
        break;
    }
    }
    return ProgrEnum::Task_Max;
} // TaskSel функция выбора задания
