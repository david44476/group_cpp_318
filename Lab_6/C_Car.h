#ifndef C_CAR_H
#define C_CAR_H

#include <iostream>
#include "constans.h"
#include "myEmoji.h"

// Перечисление констант, используемых в качетве статуса объекта автомобиля(битовые маски)
enum CarStat: status_8 {
    CarFree = 1u << 0, // свободен "0"
    CarWork = 1u << 1, // в работе "1"
    CarUndRen = 1u << 2, // на ремонте "2"
};

// обьявляем класс автомобиль
class Car {
private:
    mutable status_8 m_status; // статус
    const wstr m_plate; // гос.номер
    const wstr m_name; // название авто
    const ushort m_capacity; // грузоподъёмность в килограммах
    const ushort m_fuelCons; // расход топлива на 100 км

    // метод класса преобразовывает код статуса авто в строку
    const std::wstring StatusInLine() const {
        if (HasStatus(CarStat::CarUndRen)) return L"На ремонте!"; // на ремонте
        if (HasStatus(CarStat::CarWork)) return L"В работе!"; // в работе
        return L"Свободен!";
    }

    // метод класса преобразовывает код статуса авто в эмодзи
    const wchar_t StatusInEmoji() const {
        if (HasStatus(CarStat::CarUndRen)) return MyEmoji::realiz; // на ремонте
        if (HasStatus(CarStat::CarWork)) return MyEmoji::process; // в работе
        return MyEmoji::ok; // свободна
    }
public:

    // конструктор с параметрами
    explicit Car(const wstr &xplate, const wstr &xname, const ushort &xcapaciti, const ushort &xfuelCons)
        :m_status{CarStat::CarFree}, // статус по умолчанию авто "свободно"
        m_plate{xplate}, // гос.номер
        m_name{xname}, // название авто
        m_capacity{xcapaciti}, // грузоподъёмность в килограммах
        m_fuelCons{xfuelCons} // расход топлива "литров на 100 км"
    {}

    // метод класса для установки статуса
    void SetStatus(CarStat xstatus) {m_status |= xstatus;}

    // метод класса для сброса статуса
    void ClearStatus(CarStat xstatus) {m_status &= ~xstatus;}

    // метод класса для проверки статуса
    bool HasStatus(CarStat xstatus) const { return (m_status & xstatus) != 0;}

    // Удобно: сбросить все статусы и поставить один (если статусы должны быть взаимоисключающими)
    void setSingleStatus(CarStat xstatus) {
        m_status = xstatus;
    }

    // метод класса читает значение поля класса "гос.номер"
    const wstr &GetPlate() const {return m_plate;}

    // метод класса читает значение поля класса "название авто"
    const wstr &GetName() const {return m_name;}

    // метод класса читает значение поля класса "грузоподъёмность"
    const ushort &GetCapacity() const {return m_capacity;}

    // метод класса читает значение поля класса "расход топлива"
    const ushort &GetFuelCons() const {return m_fuelCons;}

    // метод класса выводит информацию об автомобиле
    void PrintCar() const {
        const wstr status{StatusInLine()}; // возвращаем строку статуса
        wchar_t emoji{StatusInEmoji()}; // возвращаем статус в эмодзи
        std::wcout << MyEmoji::truck << L" Автомобиль: " + m_name + L'\n'
                    + MyEmoji::listTasks << L" Гос.номер: " + m_plate + L'\n'
                    + MyEmoji::box << L" Грузоподъёмность (кг): " + std::to_wstring(m_capacity) + L'\n'
                    + MyEmoji::fuel << L" Расход топлива (литров на 100 км): "
                    + std::to_wstring(m_fuelCons) + L'\n'
                    + emoji << L" Статус автомобиля: " + status << std::endl;
    }
};

#endif // C_CAR_H
