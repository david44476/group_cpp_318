/*
* Лабораторная работа № 4
*
* Тема: Исследование массивов, указателей, ссылок.
*
* Разработчик: Давыдов Денис Владимирович.
*
* OS: UNIX
*
* locale (кодировка): UTF 8
*/

#include<iostream>
#include"type_thecking.h"

// создаём перечесление заданий
enum class ProgrEnum {Task_1, Task_2, Task_3, Task_4, Task_5, Task_6, Task_7, Task_8, Task_9};

// выбор задания
const ProgrEnum progrEnum = ProgrEnum::Task_4;


int main() {
    // условие для выбора задания № 1
    if (progrEnum == ProgrEnum::Task_1)
    {
#include "task_1.h"

        constexpr short Size {10};  // создаём переменную для длины массива
        short MyArray [Size];  // создаём массив

        std::cout << "Заполняем массив с помошью Вихря Мэрсена" << '\n';

        // вызов функуии для заполнения массива Вихрем Мэрсена
        void (*PtrMersWhir )(short MyArray[ ], const short size) = MersWhir;  // указатель на функцию
        PtrMersWhir (MyArray, Size);  // вызов функции через указатель

        std::cout << '\n' << "Заполнение массива своим генератором случайных чисел" << '\n';

        // вызов функции для заполнения массива своим генератором случайных чисел
        void (*PtrMyGen)(short MyArray[ ], const short size) = MyGen;  // указатель на функцию
        PtrMyGen (MyArray, Size);  // вызов функции через указатель
    }


    // условие для выбора задания № 2
    else if (progrEnum == ProgrEnum::Task_2)
    {
#include"task_2.h"

        std::cout << "\t Задание 2.a)" << '\n' << "Вывод единичной матрици" << '\n';

        // вызов функции для вывода единичной матрици
        void (*PtrTask_2a)() = Task_2a;  // указатель на функцию
        PtrTask_2a ();  // вызов функции через указатель

        std::cout << "\t Задание 2.b)" << '\n' << "Находим сумму элементов матрицы, "
                           "лежащих выше главной диагонали:\n\t квадратная матрица 8*8\n";

        // вызов функции для вывода суммы элементов матрицы лежащих выше главной диагонали
        void (*PtrTask_2b)() = Task_2b;  // указатель на функцию
        PtrTask_2b ();  // вызов функции через указатель
    }


    // условие для выбора задания № 3
    else if (progrEnum == ProgrEnum::Task_3)
    {
#include"task_3.h"

        std::cout << "\t Задание 3" << '\n' << "Алфавит английского языка" << '\t' << "Десятичный код символа" << '\n';

        // вызов функции для вывода английского алфавита от A до Z
        void (*PtrFromAtoZ)() = FromAtoZ;  // указатель на функцию
        PtrFromAtoZ ();  // вызов функции через указатель
    }

    // условие для выбора задания № 4
    else if (progrEnum == ProgrEnum::Task_4)
    {
#include"task_4.h"

        std::cout << "\t Задание 4.a" << '\n' << "Нахождение Факториала с помощью итерации и рекурсии" << '\n';
        std::cout << "Введите целое число ";
        short b{}; // пременная для ввода пользователем
        short (*PtrType_Thecking)(short b) = Type_Thecking;  // указатель на функцию
        b = PtrType_Thecking (b);  //проверка на коректность ввода через указатель

        // вызов функции для нахождения Факториала с помощью итерации
        unsigned long long (* PtrFacItr)(short a) = FacItr;  // указатель на функцию
        std::cout << "Факториал найденный с помощью итерации = " << PtrFacItr (b) << '\n';

        // вызов функции для нахождения Факториала с помощью рекурсии
        unsigned long long (* PtrFacRec)(short a) =FacRec;  // указатель на функцию
        std::cout << "Факториал найденный с помощью рекурсии = " << PtrFacRec (b) << '\n';



        std::cout << "\t Задание 4.б)" << '\n' << "Находим Число Фибоначчи, соответствующее заданному числу пользователя" << '\n';

        // выызов функции для нахождения число Фибоначчи с помощью итерации
        void (* PtrFibonacci)() = Fibonacci;
        PtrFibonacci();
    }

    // условие для выбора задания № 5
    else if (progrEnum == ProgrEnum::Task_5)
    {
#include"task_5.h"
        void (*PtrMyArray)() = MyArray;  // указатель на функцию
        PtrMyArray();  // вызов функции
    }
}
