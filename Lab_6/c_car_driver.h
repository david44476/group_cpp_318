#ifndef C_CAR_DRIVER_H
#define C_CAR_DRIVER_H

#include <iostream>
#include "c_car.h"
#include "constans.h"
#include "messout.h"
#include "myEmoji.h"
#include "taskStr.h"

class Car; // предворительное обьявление класса автомобиль

// Перечисление констант, используемых в качетве статуса объекта водитель(битовые маски)
enum DriverStat: status_8 {
    DriverFree = 1u << 0, // свободен "0"
    DriverWork = 1u << 1, // в работе "1"
    DriverSuspend = 1u << 2, // отстранён "3"
};

// обьявляем класс водитель
class CarDriver {
private:
    mutable status_8 m_status; // статус водителя
    const wstr m_fio; // ФИО водителя
    Car* m_assignedCar{nullptr}; // назначенный автомобиль

    // метод класса преобразовывает код статуса водителя в строку
    const std::wstring StatusInLine() const  {
        if (HasStatus(DriverStat::DriverSuspend)) return L"Отстранён!"; // отстранён
        if (HasStatus(DriverStat::DriverWork)) return L"В работе!"; // в работе
        return L"Свободен!";
    }

    // метод класса преобразовывает код статуса водителя в эмодзи
    const wchar_t StatusInEmoji() const {
        if (HasStatus(DriverStat::DriverSuspend)) return MyEmoji::disapFace; // отстранён
        if (HasStatus(DriverStat::DriverWork)) return MyEmoji::process; // в работе
        return MyEmoji::ok; // свободен
    }
public:

    // конструктор с параметрами
    explicit CarDriver(const wstr &xfio)
        :m_status{DriverStat::DriverFree}, // статус по умолчанию водителя "свободен"
        m_fio{xfio} // ФИО водителя
    {}

    // метод класса для установки статуса
    void SetStatus(const DriverStat &xstatus) const {m_status |= xstatus;}

    // метод класса для сброса статуса
    void ClearStatus(const DriverStat &xstatus) const {m_status &= ~xstatus;}

    // метод класса для проверки статуса
    bool HasStatus(const DriverStat &xstatus) const { return (m_status & xstatus) != 0;}

    // Удобно: сбросить все статусы и поставить один (если статусы должны быть взаимоисключающими)
    void SetSingleStatus(const DriverStat &xstatus) const {
        m_status = xstatus;
    }

    // метод класса читает значение поля класса "ФИО водителя"
    const wstr &GetFio() const {return m_fio;}

    // управление назначенным автомобилем
    Car* GetAssignedCar() const {return m_assignedCar;}
    void AssinedCar(Car* xcar) {m_assignedCar = xcar;}
    void Unassigned() {m_assignedCar = nullptr;}

    // водитель подаёт заявку на ремонт
    void RequestRepair() {
            if (!m_assignedCar) {
                MessOut::Exeption(L"Водителю " + m_fio + L" не назначен автомобиль!");
                return;
            }
            m_assignedCar->SetSingleStatus(CarStat::CarUndRen);
            MessOut::Info(L"Водитель " + m_fio + L" подал заявку на ремонт автомобиля: "
                          + m_assignedCar->GetPlate());
        }

    // метод класса выводит информацию о водителе
    void PrintDriver() {
        const wstr status{StatusInLine()}; // возвращаем строку статуса
        wchar_t emoji{StatusInEmoji()}; // возвращаем статус в эмодзи
        std::wcout << MyEmoji::joystick << L" Водитель: " + m_fio + L'\n'
                    + emoji << L" Статус водителя: " + status + L'\n'
                    + TaskStr::seporStr;
    }
};

#endif // C_CAR_DRIVER_H
