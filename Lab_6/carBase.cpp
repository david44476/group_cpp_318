#include <iostream>
#include "checkInput.h"
#include "taskStr.h"
#include "C_Driver.h"


auto CarBase() -> void {
    do {
        Driver dri{L"Давыдов Денис Владимирович"};
        dri.PrintDriver();
        dri.setSingleStatus(DriverStat::DriSuspend);
        dri.PrintDriver();
        std::wcout << TaskStr::seporStr; // вывод разделителя =
        std::wcout << MyEmoji::queMark << L" Хотите продолжить демонстрацию задания № "
                   << static_cast<ushort>(ProgrEnum::Task_4) << '\n';
    } while (PtrExit());
}
