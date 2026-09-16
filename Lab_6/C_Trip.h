#ifndef C_TRIP_H
#define C_TRIP_H

#include "constans.h" // содержит константы
#include "myEmoji.h" // содержит эмодзи

// Перечисление констант, используемых в качетве статуса объекта поездка(битовые маски)
enum TripStat: status_8 {
    TriWork = 1u << 0, // в работе "1"
    TriDone = 1u << 1 // завершена "2"
};

// обьявляем класс поездка
class Trip {
private:
    static ushort s_id;
    mutable status_8 m_status; // статус поездки
    const ushort m_id; // номер поездки
    const wstr m_from; // от куда поездка
    const wstr m_to; // куда поездка
    const ushort m_cargoWeight; // вес груза в килограммах

    // метод класса преобразовывает код статуса поездки в строку
    const std::wstring StatusInLine() const {
        return (HasStatus(TripStat::TriDone)) ? L"Завершена!" : L"В работе!";
    }

    // метод класса преобразовывает код статуса поездки в эмодзи
    const wchar_t StatusInEmoji() const {
        return (HasStatus(TripStat::TriDone)) ? MyEmoji::ok : MyEmoji::process;
    }
public:

    // конструктор с параметрами
    explicit Trip(const wstr &xfrom, const wstr xto, const ushort &xcargoWeight)
        : m_status{TripStat::TriDone}, // статус по умолчанию завешена
        m_id{++s_id}, // номер поездки
        m_from{xfrom}, // от куда поездка
        m_to{xto}, // куда поездка
        m_cargoWeight{xcargoWeight} // вес груза
    {}

    // метод класса для установки статуса
    void SetStatus(TripStat xstatus) {m_status |= xstatus;}

    // метод класса для сброса статуса
    void ClearStatus(TripStat xstatus) {m_status &= ~xstatus;}

    // метод класса для проверки статуса
    bool HasStatus(TripStat xstatus) const { return (m_status & xstatus) != 0;}

    // Удобно: сбросить все статусы и поставить один (если статусы должны быть взаимоисключающими)
    void setSingleStatus(TripStat xstatus) {
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
};

#endif // C_TRIP_H
