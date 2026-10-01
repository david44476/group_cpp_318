#include "checkInput.h"
#include "constans.h"
#include "c_car_driver.h"
#include "c_car.h"
#include "c_trip.h"
#include "c_dispatcher.h"
#include "taskStr.h"
ushort Trip::s_id{0}; // определение статического счётчика поездок
auto CarBase() -> void {
    do {
        Dispatcher dispatcher;

        // ── 1. Добавляем автомобили ──
        Car car1{L"А123АА", L"Газель", 1500, 12};
        Car car2{L"В456ВВ", L"КамАЗ", 10000, 35};
        Car car3{L"С789СС", L"УАЗ", 800, 15};
        dispatcher.AddCar(&car1);
        dispatcher.AddCar(&car2);
        dispatcher.AddCar(&car3);
        std::wcout << TaskStr::seporStr;

        // ── 2. Добавляем водителей ──
        CarDriver drv1{L"Иванов Иван Иванович"};
        CarDriver drv2{L"Петров Пётр Петрович"};
        CarDriver drv3{L"Сидоров Сидор Сидорович"};
        dispatcher.AddDriver(&drv1);
        dispatcher.AddDriver(&drv2);
        dispatcher.AddDriver(&drv3);
        std::wcout << TaskStr::seporStr;

        // ── 3. Создаём поездку: Иванов на Газели везёт 800 кг ──
        std::wcout << std::setw(40) << L"=== Создание поездки № 1 ===" << L'\n';
        dispatcher.CreatTrip(L"Краснокаменск", L"Чита", 800,
                             L"Иванов Иван Иванович", L"А123АА");
        std::wcout << TaskStr::seporStr;

        // ── 4. Создаём вторую поездку: Петров на КамАЗе везёт 5000 кг ──
        std::wcout << std::setw(40) << L"=== Создание поездки № 2 ===" << L'\n';
        dispatcher.CreatTrip(L"Краснокаменск", L"Хабаровск", 5000,
                             L"Петров Пётр Петрович", L"В456ВВ");
        std::wcout << TaskStr::seporStr;

        // ── 5. Пытаемся создать поездку с превышением грузоподъёмности ──
        std::wcout << std::setw(58) << L"=== Поездка с превышением грузоподъёмности ===" << L'\n';
        dispatcher.CreatTrip(L"Краснокаменск", L"Чита", 2000,
                             L"Сидоров Сидор Сидорович", L"А123АА");
        std::wcout << TaskStr::seporStr;

        // ── 6. Выводим информацию о текущем состоянии автобазы ──
        std::wcout << std::setw(40) << L"=== Состояние автобазы ===" << L'\n';
        dispatcher.PrintInfoTrip();

        // ── 7. Водитель Иванов подаёт заявку на ремонт ──
        std::wcout << std::setw(40) << L"=== Заявка на ремонт ===" << L'\n';
        dispatcher.DriverRequestRepair(L"Иванов Иван Иванович");

        // ── 8. Диспетчер отстраняет Петрова от работы ──
        std::wcout << std::setw(44) << L"=== Отстранение водителя ===" << L'\n';
        dispatcher.SuspendDriver(L"Петров Пётр Петрович");
        std::wcout << TaskStr::seporStr;

        // ── 9. Выводим состояние автобазы после отстранения и ремонта ──
        std::wcout << std::setw(58) << L"=== Состояние после отстранения и ремонта ===" << L'\n';
        dispatcher.PrintInfoTrip();

        // Узнаём ID рейсов из вывода выше, но для демо возьмём ID = 1 (Иванов)
        std::wcout << std::setw(58) << L"=== Завершение поездки № 1 (без ремонта) ===" << L'\n';
        dispatcher.CompleteTrip(1, false);

        // Завершаем поездку № 2 (Петров) с ремонтом
        std::wcout << std::setw(58) << L"===Завершение поездки № 2 (с ремонтом авто) ===" << L'\n';
        dispatcher.CompleteTrip(2, true);

        // ── 11. Финальное состояние ──
        std::wcout << std::setw(47) << L"=== Финальное состояние автобазы ===" << L'\n';
        dispatcher.PrintInfoTrip();

    } while (PtrExit());
}
