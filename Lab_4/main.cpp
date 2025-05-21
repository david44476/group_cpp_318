/*
* Лабораторная работа № 4
*
* Тема: “Исследование массивов, указателей, ссылок.”
*
* Разработчик: Давыдов Денис Владимирович.
*
* OS: UNIX
*
* locale (кодировка): UTF-8
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
        const short Size {10};  // создаём переменную для длины массива
        short MyArray[Size];  // создаём массив

        std::cout << "Заполняем массив с помошью Вихря Мэрсена" << '\n';
        MersWhir (MyArray, Size);  // вызов функуии для заполнения массива Вихрем Мэрсена

        std::cout << '\n' << "Заполнение массива своим генератором случайных чисел" << '\n';
        MyGen (MyArray, Size);
    }

    // условие для выбора задания № 2
    if (progrEnum == ProgrEnum::Task_2)
    {
        std::cout << "Единичная матрица размером 5*5" << '\n';

    }
        return 0;
}
