#ifndef CONSTANS_H
#define CONSTANS_H

#include<string>

// псевдонимы типов
using ushort = unsigned short; // на unsigned short
using wstr = std::wstring; // на std::wstring
using ullong = unsigned long long; // на unsigned long long

// Перечисление констант, используемых в качетве выбора заданий
enum class ProgrEnum: ushort {
    Task_1, // задание № 1
    Task_2, // задание № 2
    Task_3, // задание № 3
    Task_4, // задание № 4
    Task_5, // задание № 5
    Task_Max
};

// Перечисление констант, используемых в качетве возвращаемых значений из функций
namespace Ret {
enum RetFunc: short {
    Ok = 0, // выполнео
    ErrData = -1, // ошибка
    ErrMemory = -2, // ошибка выделения памяти
    EmptyLine = -3, // пустая строка
    Overflow = -4, // переполнено
    OutRange = -5, // вне диапазона
    NotFound = -6, // не найден
    NullPointer = -7, // нулевой указатель
    Exit = -8 // выход
};
}
#endif // CONSTANS_H
