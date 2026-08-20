#include<iostream>
#include<iomanip>
#include"constans.h"
#include"errmess.h"
#include"myEmoji.h"
#include"taskStr.h"
#include"checkInput.h"

// функция выбора задания
auto TaskSel() -> const ProgrEnum {
    std::wcout << std::setw(9) << MyEmoji::fingRight << L" ВЫБЕРИТЕ ЗАДАНИЕ ДЛЯ ДЕМОНСТРАЦИИ: "
               << MyEmoji::fingLeft << '\n';
    std::wcout << TaskStr::strTask1;
    std::wcout << TaskStr::strTask2;
    std::wcout << TaskStr::strTask3;
    std::wcout << TaskStr::strTask4;
    std::wcout << TaskStr::strTask5;

    // Собираем сообщение в отдельную строку — так проще и безопаснее
    std::wstring msg = L"Введите число от ";
    msg += std::to_wstring(static_cast<ushort>(ProgrEnum::Task_2));
    msg += L" до ";
    msg += std::to_wstring(static_cast<ushort>(ProgrEnum::Task_Max));
    msg += L": ";
    ushort choice;
    while (true){
        Errmess::Info(msg);
        std::wcout << MyEmoji::fingRight << L' ';
        if (CheckInput(choice, static_cast<ushort>(ProgrEnum::Task_2),
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
}
