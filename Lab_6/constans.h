#ifndef CONSTANS_H
#define CONSTANS_H

#include<string>

// псевдонимы типов
using ushort = unsigned short; // на unsigned short
using wstr = std::wstring; // на std::wstring

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
enum RetFunc: ushort {
    Ok, // выполнео
    ErrData, // ошибка
    ErrMemory, // ошибка выделения памяти
    EmptyLine, // пустая строка
    Overflow, // переполнено
    OutRange, // вне диапазона
    ExitProg // выход из программы
};
#endif // CONSTANS_H
