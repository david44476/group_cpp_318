#include <iostream>
#include<ctime>
#include <cstdlib>
#include"task_5.h"
static short choice; // переменная выбора типа данных для созданния массива
static size_t arraySize; // переменная для длины массива по выбору пользователя
constexpr int max_length {100}; // максимальное количиство считываемых символов

// функция создания массива по выбору пользователя
auto CreateArray() -> void {
    // переменые для проверки на коректность ввода
    constexpr short min = 0;
    constexpr short max = 100;
    std::cout << "Выберите какого типа даных хотите создать массив" << '\n'
              << "тип char нажмите 1,\n"
                 "тип short нажмите 2,\n"
                 "тип int нажмите 3,\n"
                 "тип float нажмите 4,\n"
              << "тип double нажмите 5 :";
    choice = Type_Thecking(choice, min, max);  // проверка на коректность ввода

    // Вводим размер массива с проверками корректности
    std::cout << "Введите число для длины массива от 1 до 100 : ";
    constexpr short sizeMin{1};
    constexpr short sizeMax{100};
    arraySize = static_cast<size_t>(Type_Thecking(arraySize, sizeMin, sizeMax));

    std::cout <<  arraySize << '\n';
    switch (choice){
    case Type_Char :{
        // создание массива типа char
        short Array[max_length];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        RandNumGen(Array, arraySize);
        PrintArray(Array, arraySize);
        InsertionSort(Array, arraySize);
        std::cout << "\vВывод отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
    }
        break;

        // создание массива типа short
    case Type_Short :{
        short Array[max_length];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        RandNumGen(Array, arraySize);
        PrintArray(Array, arraySize);
        InsertionSort(Array, arraySize);
        std::cout << "\vВывод отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
    }
        break;

        // создание массива типа int
    case Type_Int :{
        short Array[max_length];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        RandNumGen(Array, arraySize);
        PrintArray(Array, arraySize);
        InsertionSort(Array, arraySize);
        std::cout << "\vВывод отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
    }
        break;

        // создание массива типа float
    case Type_Float :{
        short Array[max_length];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        RandNumGen(Array, arraySize);
        PrintArray(Array, arraySize);
        InsertionSort(Array, arraySize);
        std::cout << "\vВывод отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
    }
        break;

        // создание массива типа double
    case Type_Double :{
        short Array[max_length];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        RandNumGen(Array, arraySize);
        PrintArray(Array, arraySize);
        InsertionSort(Array, arraySize);
        std::cout << "\vВывод отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
    }
        break;
    }
}

// функция для генерации случайных чисел
auto RandNumGen(void *xpArray, const size_t& size) -> void {

    srand(static_cast<unsigned int>(time(nullptr)));
    double fraction{1.0 / (static_cast<double>(RAND_MAX) + 1.0)};
    short min{1};
    short max{100};


    switch (choice) {
    case Type_Char :{

        srand(static_cast<unsigned int>(time(nullptr)));
        double fraction{1.0 / (static_cast<double>(RAND_MAX) + 1.0)};
        short min{65};
        short max{90};
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (size_t i{0}; i < size; ++i) {
            char *pdata =  static_cast<char*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (size_t i{0}; i < size; ++i) {
                pdata[i] = static_cast<char>((rand() * fraction * (max - min + 1) + min));
            }
        }
    }
        break;



    case Type_Short :{
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (size_t i{0}; i < size; ++i) {
            short *pdata =  static_cast<short*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (size_t i{0}; i < size; ++i) {
                pdata[i] = static_cast<short>((rand() * fraction * (max - min + 1) + min));
            }
        }
    }
        break;

    case Type_Int :{
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (size_t i{0}; i < size; ++i) {
            int *pdata =  static_cast<int*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (size_t i{0}; i < size; ++i) {
                pdata[i] = static_cast<int>((rand() * fraction * (max - min + 1) + min));
            }
        }
    }
        break;

    case Type_Float :{
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (size_t i{0}; i < size; ++i) {
            float *pdata =  static_cast<float*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (size_t i{0}; i < size; ++i) {
                pdata[i] = static_cast<float>((rand() * fraction * (max - min + 1) + min));
            }
        }
    }
        break;

    case Type_Double :{
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (size_t i{0}; i < size; ++i) {
            double *pdata =  static_cast<double*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (size_t i{0}; i < size; ++i) {
                pdata[i] = static_cast<double>((rand() * fraction * (max - min + 1) + min));
            }
        }
    }
        break;
    }
}


// функция вывода массива типон данных по выбору пользователя
auto PrintArray(void *xpArray, const size_t& size) -> void {
    switch (choice){
    // заполнение массива типа short
    case Type_Char :{
        for (size_t i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<char*>(xpArray) +i) << '\n';
        }
    }
        break;

        // заполнение массива типа short
    case Type_Short :{
        for (size_t i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<short*>(xpArray) +i) << '\n';
        }
    }
        break;
        // заполнение массива типа int
    case Type_Int :{
        for (size_t i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<int*>(xpArray) +i) << '\n';
        }
    }
        break;

        // заполнение массива типа float
    case Type_Float :{
        for (size_t i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<float*>(xpArray) +i) << '\n';
        }
    }
        break;

        // заполнение массива типа double
    case Type_Double :{
        for (size_t i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<double*>(xpArray) +i) << '\n';
        }
    }
        break;
    }
}

auto InsertionSort(void *xpArray, const size_t& size) -> void
{
    switch (choice) {
    case Type_Char:{
        for(size_t i = 1; i < size; i++)
        {
            char *pdata =  static_cast<char*>(xpArray);
            size_t j = i - 1;
            while(j >= 0 && pdata[j] > pdata[j + 1])
            {
                std::swap(pdata[j], pdata[j + 1]);
                j--;
            }
             pdata[i] = *(static_cast<char*>(xpArray) + i);
        }
    }
        break;

    case Type_Short:{
        for(size_t i = 1; i < size; i++)
        {
            short *pdata =  static_cast<short*>(xpArray);
            size_t j = i - 1;
            while(j >= 0 && pdata[j] > pdata[j + 1])
            {
                std::swap(pdata[j], pdata[j + 1]);
                j--;
            }
             pdata[i] = *(static_cast<short*>(xpArray) + i);
        }
    }
        break;

    case Type_Int:{
        for(size_t i = 1; i < size; i++)
        {
            int *pdata =  static_cast<int*>(xpArray);
            size_t j = i - 1;
            while(j >= 0 && pdata[j] > pdata[j + 1])
            {
                std::swap(pdata[j], pdata[j + 1]);
                j--;
            }
             pdata[i] = *(static_cast<int*>(xpArray) + i);
        }
    }
        break;

    case Type_Float:{
        for(size_t i = 1; i < size; i++)
        {
            float *pdata =  static_cast<float*>(xpArray);
            size_t j = i - 1;
            while(j >= 0 && pdata[j] > pdata[j + 1])
            {
                std::swap(pdata[j], pdata[j + 1]);
                j--;
            }
            pdata[i] = *(static_cast<float*>(xpArray) + i);
        }
    }
        break;

    case Type_Double:{
        for(size_t i = 1; i < size; i++)
        {
            double *pdata =  static_cast<double*>(xpArray);
            size_t j = i - 1;
            while(j >= 0 && pdata[j] > pdata[j + 1])
            {
                std::swap(pdata[j], pdata[j + 1]);
                j--;
            }
            pdata[i] = *(static_cast<double*>(xpArray) + i);
        }
    }
        break;
    }
}
