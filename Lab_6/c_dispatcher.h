#ifndef C_DISPATCHER_H
#define C_DISPATCHER_H

#include "constans.h"
#include "messout.h"
#include "c_car.h"
#include "c_car_driver.h"
#include "c_trip.h"

// настройки лимитов
static constexpr ushort maxCars{50}; // максимум автомобилей
static constexpr ushort maxDrivers{100}; // максимум водителей
static constexpr ushort maxTrips{200}; // максимум поездок

// обьявляем класс диспечер
class Dispatcher {
private:

    // статические массивы указателей на объекты
    Car* m_cars[maxCars]{}; // автомобили
    CarDriver* m_drivers[maxDrivers]{}; // водителя
    Trip m_trips[maxTrips]{}; // статический массив поездок

    // счётчики количества элементов
    ushort m_carCount{0}; // автомобилей
    ushort m_driverCount{0}; // водителей
    ushort m_tripCount{0}; // поездок
public:

    // добавление автомобиля
    Ret::RetFunc AddCar(Car* xcar) {
        if (!xcar) {
            MessOut::Exeption(L"Нельзя добавить nullptr автомобиль!");
            return Ret::NullPtr;
        }
        if (m_carCount >= maxCars) {
            MessOut::Exeption(L"Превышен лимит в " + std::to_wstring(maxCars) + L" автомобилей!!!");
            return Ret::Overflow;
        }

        // присваеваем адресу ячейки массива адрес объекта автомобиль
        m_cars[m_carCount] = xcar;
        ++m_carCount; // инкрементируем счётчик автомобилей
        MessOut::Info(L"Автомобиль добавлен: " + xcar->GetName() + L", гос.номер: " + xcar->GetPlate()
                      + L", грузоподъёмность: " + std::to_wstring(xcar->GetCapacity()) + L" (кг)!!!");
        return Ret::Ok;
    }

    // Добавление водителя
    Ret::RetFunc AddDriver(CarDriver* xdriver) {
        if (!xdriver) {
            MessOut::Exeption(L"Нельзя добавить nullptr водительль!");
            return Ret::NullPtr;
        }
        if (m_driverCount >= maxDrivers) {
            MessOut::Exeption(L"Превышен лимит в " + std::to_wstring(maxDrivers) + L" водителей!!!");
            return Ret::Overflow;
        }

        // присваеваем адресу ячейки массива адрес объекта водитель
        m_drivers[m_driverCount] = xdriver;
        ++m_driverCount; // инкрементируем счётчик водителей
        MessOut::Info(L"Водитель добавлен: " + xdriver->GetFio());
        return Ret::Ok;
    }

    // создание рейса и назначения водителя и автомобиля
    Ret::RetFunc CreatTrip(const wstr &xfrom, const wstr &xto, const ushort &xcargoWeight,
                           const wstr &xfio, const wstr &xplate) {
        // Назначение водителя
        CarDriver* driver{nullptr};
        for (auto i{0}; i < m_driverCount; ++i) {
            if (m_drivers[i]->GetFio() == xfio && m_drivers[i]->HasStatus(DriverStat::DriverFree)) {
                driver = m_drivers[i];
                m_drivers[i]->SetSingleStatus(DriverStat::DriverWork);
                break;
            }
        }

        if (!driver) {
            MessOut::Exeption(L"Не удалось назначить водителя: нет свободного!!!");
            return Ret::NotFound;
        }

        // Назначение автомобиля: ищем машину с нужным номером, статусом и грузоподъёмностью
        Car* car{nullptr};
        for (auto i{0}; i < m_carCount; ++i) {
            Car* cur = m_cars[i];

            // Проверяем номер, статус и грузоподъёмность
            if (cur->GetPlate() != xplate)
                continue;
            if (!cur->HasStatus(CarStat::CarFree))
                continue;
            if (cur->GetCapacity() < xcargoWeight)
                continue;

            car = cur;
            break; // нашли подходящую — выходим
        }

        if (!car) {
            // Откатываем статус водителя, так как машина не найдена
            driver->SetSingleStatus(DriverStat::DriverFree);

            MessOut::Exeption(L"Не удалось назначить автомобиль: нет свободной машины с номером "
                              + xplate + L" и достаточной грузоподъёмностью!!!");
            return Ret::NotFound;
        }

        // Устанавливаем статус автомобиля
        car->SetSingleStatus(CarStat::CarWork);

        // Проверка лимита рейсов
        if (m_tripCount >= maxTrips) {
            // Важно: откатить статус автомобиля, так как рейс не будет создан
            car->SetSingleStatus(CarStat::CarFree);
            driver->SetSingleStatus(DriverStat::DriverFree);

            MessOut::Exeption(L"Превышен лимит в " + std::to_wstring(maxTrips) + L" рейсов!!!");
            return Ret::Overflow;
        }

        // Создаём поездку и привязываем водителя и машину
        m_trips[m_tripCount] = Trip{xfrom, xto, xcargoWeight};
        m_trips[m_tripCount].SetDriver(driver);
        m_trips[m_tripCount].SetCar(car);
        driver->AssinedCar(car);

        ++m_tripCount;

        MessOut::Info(L"Рейс создан: " + xfrom + L" → " + xto + L"; вес груза: "
                      + std::to_wstring(xcargoWeight) + L" (кг)" + L"; водитель: "
                      + driver->GetFio() + L"; авто: " + car->GetName()
                      + L"; гос.номер " + car->GetPlate()
                      + L"; грузоподъёмность: " + std::to_wstring(car->GetCapacity()) + L" (кг)");

        return Ret::Ok;
    }

    // диспечер отстроняет водителя от работы
    Ret::RetFunc SuspendDriver(const wstr &xfio) {
        for (auto i{0}; i < m_driverCount; ++i) {
            if (m_drivers[i]->GetFio() == xfio) {
                m_drivers[i]->SetSingleStatus(DriverStat::DriverSuspend);

                // освобождаем автомобиль, если был назначен
                Car* car = m_drivers[i]->GetAssignedCar();
                if (car) {
                    car->SetSingleStatus(CarStat::CarFree);
                    m_drivers[i]->Unassigned();
                }
                MessOut::Info(L"Водитель " + xfio + L" отстранён от работы!");
                return Ret::Ok;
            }
        }
        MessOut::Exeption(L"Водитель не найден: " + xfio);
        return Ret::NotFound;
    }

    // водитель отмечает выполнение рейса и состояние автомобиля
    Ret::RetFunc CompleteTrip(ushort xtripId, bool needRepair = false) {
        for (auto i{0}; i < m_tripCount; ++i) {
            if (m_trips[i].GetId() == xtripId && m_trips[i].HasStatus(TripStat::TripWork)) {

                // завершаем поездку
                m_trips[i].SetSingleStatus(TripStat::TripDone);

                // освобождаем водителя
                CarDriver* driver = m_trips[i].GerDriver();
                driver->SetSingleStatus(DriverStat::DriverFree);
                driver->Unassigned();
            }

            // освобождаем автомобиль или отправляем на ремонт
            Car* car = m_trips[i].GetCar();
            if (car) {
                if (needRepair) {
                    car->SetSingleStatus(CarStat::CarUndRen);
                    MessOut::Info(L"Поездка № " + std::to_wstring(xtripId)
                                  + L" завершёна. Автомобиль отправлен в ремонт!\n" + TaskStr::seporStr);
                } else {
                    car->SetSingleStatus(CarStat::CarFree);
                    MessOut::Info(L"Поездка № " + std::to_wstring(xtripId)
                                  + L" завершена. Водитель и автомобиль свободны!!!\n" + TaskStr::seporStr);
                }
            }
            return Ret::Ok;
        }
        MessOut::Exeption(L"Рейс не найден или уже завершён № " + std::to_wstring(xtripId));
        return Ret::NotFound;
    }

    // водитель подаёт заявку на ремонт (через диспетчера)
    Ret::RetFunc DriverRequestRepair(const wstr &xfio) {
        for (auto i{0}; i < m_driverCount; ++i) {
            if (m_drivers[i]->GetFio() == xfio) {
                m_drivers[i]->RequestRepair();
                return Ret::Ok;
            }
        }
        MessOut::Exeption(L"Водитель не найден: " + xfio);
        return Ret::NotFound;
    }

    void PrintInfoTrip() {
        for (auto i{0}; i < m_driverCount; ++i) m_drivers[i]->PrintDriver();
        for (auto i{0}; i < m_carCount; ++i) m_cars[i]->PrintCar();
        for (auto i{0}; i < m_tripCount; ++i) m_trips[i].PrintTrip();
    }
};

#endif // C_DISPATCHER_H
