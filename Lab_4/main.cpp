/*
* Лабораторная работа № 4
*
* Тема: ?Исследование массивов, указателей, ссылок.?
*
* Разработчик: Давыдов Денис Владимирович.
*
* OS: WINDOWS
*
* locale (кодировка): IBM 866
*/

#include<iostream>
#include"functions.h"

// создаём перечесление заданий
enum class ProgrEnum {Task_1, Task_2, Task_3, Tak_4, Task_5, Task_6, Task_7, Task_8, Task_9};

// выбор зания
const ProgrEnum progrEnum = ProgrEnum::Task_1;


int main() {
    // условие для выбора задания № 1
    if (progrEnum == ProgrEnum::Task_1)
    {
        constexpr short Size {10};  // создаём переменную для длины массива
        short MyArray [Size];  // создаём массив

        std::cout << "Заполняем массив с помошью Вихря Мэрсена" << '\n';
        MersWhir (MyArray, Size);  // вызов функуии для заполнения массива Вихрем Мэрсена

        std::cout << '\n' << "Заполнение массива своим генератором случайных чисел" << '\n';
        MyGen (MyArray, Size);
    }

    // условие для выбора задания № 2
    if (progrEnum == ProgrEnum::Task_2)
    {
        std::cout << "\t Задание 2.a)" << '\n' << "Вывод единичной матрици" << '\n';
        Task_2a ();

        std::cout << "\t Задание 2.b)" << '\n' << "Находим сумму элементов матрицы, "
                                                  "лежащих выше главной диагонали:\n\t квадратная матрица 8*8\n";
        Task_2b ();
    }
}
