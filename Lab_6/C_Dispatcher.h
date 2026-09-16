#ifndef C_DISPATCHER_H
#define C_DISPATCHER_H

#include "constans.h"
#include "messout.h"
#include "C_Car.h"
#include "C_Driver.h"
#include "C_Trip.h"

// настройки лимитов
constexpr ushort maxCars{50}; // максимум автомобилей
constexpr ushort maxDrivers{100}; // максимум водителей
constexpr ushort maxTrips{200}; // максимум поездок

// обьявляем класс диспечер
class Dispatcher {
private:

    // статические массивы объектов
    Car* m_cars[maxCars]; // автомобили
    Driver* m_drivers[maxDrivers]; // водителя
    Trip* m_trips[maxTrips]; // поездки

    // счётчики количества элементов
    ushort m_carsCount{0};
    ushort m_driCount{0};
    ushort m_triCount{0};
public:

    // добавление автомобиля
    Ret::RetFunc AddCar(Car* xcar) {
        if (m_carsCount >= maxCars) {
            MessOut::Exeption(L"Превышен лимит в " + std::to_wstring(maxCars) + L" автомобилей!!!");
            return Ret::Overflow;
        }

        // присваеваем адресу ячейки массива адрес объекта автомобиль
        m_cars[m_carsCount] = xcar;
        ++m_carsCount;
        MessOut::Info(L"Автомобиль добавлен: " + xcar->GetName() + L", гос.номер: " + xcar->GetPlate());
        return Ret::Ok;
    }

    // Добавление водителя
    Ret::RetFunc AddDriver(Driver* xdriver) {
        if ( m_driCount >= maxDrivers) {
            MessOut::Exeption(L"Превышен лимит в " + std::to_wstring(maxDrivers) + L" водителей!!!");
            return Ret::Overflow;
        }

        // присваеваем адресу ячейки массива адрес объекта водитель
        m_drivers[m_driCount] = xdriver;
        ++m_driCount;
        MessOut::Info(L"Водитель добавлен: " + xdriver->GetFio());
        return Ret::Ok;
    }

    // создание рейса и назначения водителя и автомобиля
    Ret::RetFunc CreatTrip(const wstr &xfrom, const wstr &xto, const ushort &xcargoWeight,
                   const wstr &xfio, const wstr &xplate) {
        Driver* driver{nullptr};
        for (auto i{0}; i < m_driCount; ++i) {
            if (m_drivers[i]->GetFio() == xfio && m_drivers[i]->HasStatus(DriverStat::DriFree)) {
                driver = m_drivers[i]; // берём адрес элемента массива
                break;
            }
        }
        if (!driver) {
            MessOut::Exeption(L"Не удалось назначить водителя: нет свободного!!!");
            return Ret::NotFound;
        }

        Car* car{nullptr};
        for (auto &cr: m_cars) {
            if (cr->GetPlate() == xplate && cr->HasStatus(CarStat::CarFree)) {
                continue;
            }
            if (cr->GetCapacity() < xcargoWeight) {
                MessOut::Warning(L"Вес груза не соответствует грузоподъёмности автомобиля!!!");
                return Ret::OutRange;
            } else {
                car = cr;
                break;
            }
        }
        if (!car) {
            MessOut::Exeption(L"Не удалось назначить автомобиль: нет свободного!!!");
            return Ret::NotFound;
        }

        // Добавляем поездку
        if (m_triCount >= maxTrips) {
            MessOut::Exeption(L"Превышен лимит в " + std::to_wstring(maxTrips) + L" рейсов!!!");
            return Ret::Overflow;
        }
        m_trips[m_triCount] = Trip(xfrom, xto, xcargoWeight);
    }
};

#endif // C_DISPATCHER_H
