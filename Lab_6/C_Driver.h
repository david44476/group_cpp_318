#ifndef C_DRIVER_H
#define C_DRIVER_H

#include <iostream>
#include "constans.h"
#include "myEmoji.h"

// Перечисление констант, используемых в качетве статуса объекта водитель(битовые маски)
enum DriverStat: status_8 {
    DriFree = 1u << 0, // свободен "0"
    DriWork = 1u << 1, // в работе "1"
    DriSuspend = 1u << 2, // отстранён "3"
};

// обьявляем класс водитель
class Driver {
private:
    mutable status_8 m_status; // статус водителя
    const wstr m_fio; // ФИО водителя

    // метод класса преобразовывает код статуса водителя в строку
    const std::wstring StatusInLine() const  {
        if (HasStatus(DriverStat::DriSuspend)) return L"Отстранён!"; // отстранён
        if (HasStatus(DriverStat::DriWork)) return L"В работе!"; // в работе
        return L"Свободен!";
    }

    // метод класса преобразовывает код статуса водителя в эмодзи
    const wchar_t StatusInEmoji() const {
        if (HasStatus(DriverStat::DriSuspend)) return MyEmoji::disapFace; // отстранён
        if (HasStatus(DriverStat::DriWork)) return MyEmoji::process; // в работе
        return MyEmoji::ok; // свободен
    }
public:

    // конструктор с параметрами
    explicit Driver(const wstr &xfio)
        :m_status{DriverStat::DriFree}, // статус по умолчанию водителя "свободен"
        m_fio{xfio} // ФИО водителя
    {}

    // метод класса для установки статуса
    void SetStatus(DriverStat xstatus) {m_status |= xstatus;}

    // метод класса для сброса статуса
    void ClearStatus(DriverStat xstatus) {m_status &= ~xstatus;}

    // метод класса для проверки статуса
    bool HasStatus(DriverStat xstatus) const { return (m_status & xstatus) != 0;}

    // Удобно: сбросить все статусы и поставить один (если статусы должны быть взаимоисключающими)
    void setSingleStatus(DriverStat xstatus) {
        m_status = xstatus;
    }

    // метод класса читает значение поля класса "ФИО водителя"
    const wstr &GetFio() const {return m_fio;}

    // метод класса выводит информацию о водителе
    void PrintDriver() {
        const wstr status{StatusInLine()}; // возвращаем строку статуса
        wchar_t emoji{StatusInEmoji()}; // возвращаем статус в эмодзи
        std::wcout << MyEmoji::joystick << L" Водитель: " + m_fio + L'\n'
                    + emoji << L" Статус водителя: " + status + L'\n';
    }
};

#endif // C_DRIVER_H
