#ifndef C_TRIP_H
#define C_TRIP_H

#include <iostream>
#include <iomanip>
#include "c_car.h"
#include "c_car_driver.h"
#include "constans.h" // содержит константы
#include "myEmoji.h" // содержит эмодзи

// Предварительное объявление — чтобы хранить указатели
class CarDriver;
class Car;

// Перечисление констант, используемых в качетве статуса объекта поездка(битовые маски)
enum TripStat: status_8 {
    TripWork = 1u << 0, // в работе "1"
    TripDone = 1u << 1 // завершена "2"
};

// обьявляем класс поездка
class Trip {
private:
    static ushort s_id;
    mutable status_8 m_status; // статус поездки
    ushort m_id; // номер поездки
    wstr m_from; // от куда поездка
    wstr m_to; // куда поездка
    ushort m_cargoWeight; // вес груза в килограммах
    CarDriver* m_driver{nullptr}; // назначенный водитель
    Car* m_car{nullptr}; // назначенный автомобиль

    // метод класса преобразовывает код статуса поездки в строку
    const std::wstring StatusInLine() const {
        return (HasStatus(TripStat::TripDone)) ? L"Завершена!" : L"В работе!";
    }

    // метод класса преобразовывает код статуса поездки в эмодзи
    const wchar_t StatusInEmoji() const {
        return (HasStatus(TripStat::TripDone)) ? MyEmoji::ok : MyEmoji::process;
    }
public:

    Trip() = default;

    // конструктор с параметрами
    explicit Trip(const wstr &xfrom, const wstr xto, const ushort &xcargoWeight)
        : m_status{TripStat::TripWork}, // статус по умолчанию в работе
        m_id{++s_id}, // номер поездки
        m_from{xfrom}, // от куда поездка
        m_to{xto}, // куда поездка
        m_cargoWeight{xcargoWeight} // вес груза
    {}

    // конструктор копирования
    Trip(const Trip &xtrip)
        : m_status{xtrip.m_status},
        m_id{xtrip.m_id},
        m_from{xtrip.m_from},
        m_to{xtrip.m_to},
        m_cargoWeight{xtrip.m_cargoWeight}
    {}

    // оператор присваивания
    Trip& operator =(const Trip &xtrip) {
        if (this == &xtrip) return *this;
        m_status = xtrip.m_status;
        m_id = xtrip.m_id;
        m_from = xtrip.m_from;
        m_to = xtrip.m_to;
        m_cargoWeight = xtrip.m_cargoWeight;
        m_driver = xtrip.m_driver;
        m_car = xtrip.m_car;
        return *this;
    }

    // метод класса для установки статуса
    void SetStatus(const TripStat &xstatus) const {m_status |= xstatus;}

    // метод класса для сброса статуса
    void ClearStatus(const TripStat &xstatus) const {m_status &= ~xstatus;}

    // метод класса для проверки статуса
    bool HasStatus(const TripStat &xstatus) const { return (m_status & xstatus) != 0;}

    // Удобно: сбросить все статусы и поставить один (если статусы должны быть взаимоисключающими)
    void SetSingleStatus(const TripStat &xstatus) const {
        m_status = xstatus;
    }

    // метод класса читает значение поля класса "номер поездки"
    const ushort &GetId() const {return m_id;}

    // метод класса читает значение поля класса "от куда поездка"
    const wstr &GetFrom() const {return m_from;}

    // метод класса читает значение поля класса "куда поездка"
    const wstr &GetTo() const {return m_to;}

    // метод класса читает значение поля класса "вес груза"
    const ushort &GetCargoWeight() const {return m_cargoWeight;}

    CarDriver* GerDriver() const {return m_driver;}
    Car* GetCar() const {return m_car;}
    void SetDriver(CarDriver* xdriver) {m_driver = xdriver;}
    void SetCar(Car* xcar) {m_car = xcar;}

    void PrintTrip() const {
        std::wcout << std::setw(40) << L"Поездка № " << m_id << L'\n'
                   << L"Пункт отправления: " << m_from << L'\n'
                   << L"Пункт назначения: " << m_to << L'\n'
                   << L"Вес груза: " << m_cargoWeight << L" (кг)" << L'\n';

        if (m_car) {
            std::wcout << L"Автомобиль: " << m_car->GetName()
                    << L" (гос. номер: " << m_car->GetPlate() << L")" << L'\n';
        } else {
            std::wcout << L"Автомобиль: не назначен" << L'\n';
        }

        if (m_driver) {
            std::wcout << L"Водитель: " << m_driver->GetFio() << L'\n';
        } else {
            std::wcout << L"Водитель: не назначен" << L'\n';
        }

        std::wcout << L"Статус: " << StatusInLine() << '\n' << TaskStr::seporStr;
    }
};

#endif // C_TRIP_H
