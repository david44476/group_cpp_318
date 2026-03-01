#ifndef CONSTANS_H
#define CONSTANS_H

// перечисление заданий
enum class ProgrEnum: short {Task_0, Task_1, Task_2, Task_3, Task_4, Task_5};

/* Перечисление констант, используемых в качетве
   возвращаемых значений из функций */
using typyRetConst = int; //псевдоним для типа констант enum
enum RetConst: typyRetConst
{
    Ok = 0, // Выполнео
    ErrData = -1, // Ошибка
    ErrMemory = -5, // Ошибка выделения памяти
    Overflow = -6, // Переполнено
    OutRange = -7, // Вне диапазона
    EndHi = -64, // Начиная с этого кода можно раширять коды возврата
    End = EndHi
};
#endif // CONSTANS_H
