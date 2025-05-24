#include<iostream>
#include <random>

auto MersWhir (short MyArray[ ], const short size) -> void
{
    short min = 0;  // переменная для минимального значения
    short max = 0;  // переменная для максимального значения

    // генерируем случайные числа
    std::random_device rd;
    std::mt19937 mers(rd());

    // цикл для заполнения массива случайными числами
    for (int i = 0; i < size; ++i)
    {
        MyArray[i] = static_cast<short>(mers());

        std::cout << MyArray[i] << '\t';  // вывод элементов массива

        if (MyArray[i] < min) {min = MyArray[i];}  // находим минимальное значение
        if (MyArray[i] > max) {max = MyArray[i];}  // находим максимальное значение
    }
    std::cout << '\n' << "минимальное значение = " << min << '\n';
    std::cout << "максимальное значение = " << max << std::endl;
}

auto MyGen (short MyArray[ ], const short size) -> void
{
    short min = 0;  // переменная для минимального значения
    short max = 0;  // переменная для максимального значения
    short Gmin = -20;  // переменная для минимального диапазона
    short Gmax = 20;  // переменная для максимального диапазона
    double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // вспомогательная переменная ждя генератора случайных чисел

    // цикл для заполнения массива случайными числами
    for (int i= 0; i < size; ++i)
    {
        MyArray [i] = static_cast<short>(rand() * fraction * (Gmax - Gmin + 1) + Gmin);

        std::cout << MyArray[i] << '\t';  // вывод элементов массива

        if ( MyArray[i] < min) {min = MyArray[i];}  // находим минимальное значение
        if ( MyArray[i] > max) {max = MyArray[i];}  // находим максимальное значение
    }
    std::cout << '\n' << "минимальное значение = " << min << '\n';
    std::cout << "максимальное значение = " << max << std::endl;
}
