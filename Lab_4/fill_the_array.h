#ifndef FILL_THE_ARRAY_H
#define FILL_THE_ARRAY_H
#include<iostream>
#include <cstdlib>
#include<ctime>
#include"type_thecking.h"

// фунуция для создания массива по выбору пользователя
template<typename T>
auto FillTheArray(T) -> void
{
    int Gmin = -20;  // переменная для минимального диапазона
    int Gmax = 20;  // переменная для максимального диапазона
    double fraction = 2.0 / (static_cast<double>(RAND_MAX) + 2.0); // вспомогательная переменная для генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    short num; //размер массива
    std::cout << "Введите число для размера массива :";

    num = Type_Thecking(num);  // проверка на коректность ввода

    // создание массива по выбору пользователя
    T *array = new T[num];

    std::cout << "Вывод не отсортированного массива" << '\n';

    for (int i = 0; i < num; ++i)
    {
        array[i] = static_cast<T>(rand())* fraction * (Gmax - Gmin + 1) + Gmin;
        std::cout << "элемент " <<  i << " значение элемента " << array[i] << '\n';
    }
    std::cout << "Вывод отсортированного массива" << '\n';

    for (int startIndex = 0; startIndex < num - 1; ++startIndex)
    {
        // В переменной smallestIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации.
        // Начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
        int smallestIndex = startIndex;
        // Затем ищем элемент поменьше в остальной части массива
        for (int currentIndex = startIndex + 1; currentIndex < num; ++currentIndex)
        {
            // Если мы нашли элемент, который меньше нашего наименьшего элемента,
            if (array[currentIndex] < array[smallestIndex])
                // то запоминаем его
                smallestIndex = currentIndex;
        }
        // smallestIndex теперь наименьший элемент.
        // Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
        std::swap(array[startIndex], array[smallestIndex]);
    }
    // Теперь, когда весь массив отсортирован - выводим его на экран
    for (int index = 0; index < num; ++index)
        std::cout << "элемент" << index << " значение элемента " << array[index] << '\n';
    delete [] array; // очистка памяти
}
#endif // FILL_THE_ARRAY_H
