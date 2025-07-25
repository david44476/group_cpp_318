﻿#include <iostream>
#include<ctime>
#include <cstdlib>
#include"task_5.h"
#include"type_thecking.h"
static short choice; // переменная выбора типа данных для созданния массива
static short arraySize; // переменная для длины массива по выбору пользователя
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
              << "тип double нажмите 5 : ";
    choice = Type_Thecking(choice, min, max);  // проверка на коректность ввода

    using pFunc = void(*)(void*, const short&);
    constexpr pFunc pRandNumGen= RandNumGen; // указатель на функцию генерации случайных чисел
    constexpr pFunc pPrintArray = PrintArray;  // указатель на функцию вывода массива
    constexpr void (*pInsertionSort)(void *xpArray, const short& size, bool (*comparisonFcn)(short, short)) = InsertionSort;  // указатель на функцию сортировки массива
    // bool (*comparisonFcn)(int, int);
    short sizeMin{1};  // переменная для проверки ввода длины массива
    short sizeMax{100};  // переменная для проверки ввода длины массива

    switch (choice) {

    // создание массива типа char
    case Type_Char : {
        short sizeMax{25};
        // Вводим размер массива с проверками корректности
        std::cout << "Введите число для длины массива от 1 до 25 : ";
        arraySize = Type_Thecking(arraySize, sizeMin, sizeMax);
        char Array[max_length];
        pRandNumGen(Array, arraySize);
        std::cout << "\vВывод не отсортированного массива" << '\n';
        pPrintArray(Array, arraySize);
        pInsertionSort(Array, arraySize, ascending);
        std::cout << "\vВывод отсортированного массива, в порядке возростания" << '\n';
        pPrintArray(Array, arraySize);
        pInsertionSort(Array, arraySize, descending);
        std::cout << "\vВывод отсортированного массива, в порядке убывания" << '\n';
        pPrintArray(Array, arraySize);
    }
        break;

        // создание массива типа short
    case Type_Short : {
        // Вводим размер массива с проверками корректности
        std::cout << "Введите число для длины массива от 1 до 100 : ";
        arraySize = Type_Thecking(arraySize, sizeMin, sizeMax);
        short Array[max_length];
        pRandNumGen(Array, arraySize);
        std::cout << "\vВывод не отсортированного массива" << '\n';
        pPrintArray(Array, arraySize);
        pInsertionSort(Array, arraySize, ascending);
        std::cout << "\vВывод отсортированного массива, в порядке возростания" << '\n';
        pPrintArray(Array, arraySize);
        pInsertionSort(Array, arraySize, descending);
        std::cout << "\vВывод отсортированного массива, в порядке убывания" << '\n';
        pPrintArray(Array, arraySize);
    }
        break;

        // создание массива типа int
    case Type_Int : {
        // Вводим размер массива с проверками корректности
        std::cout << "Введите число для длины массива от 1 до 100 : ";
        arraySize = Type_Thecking(arraySize, sizeMin, sizeMax);
        int Array[max_length];
        pRandNumGen(Array, arraySize);
        std::cout << "\vВывод не отсортированного массива" << '\n';
        pPrintArray(Array, arraySize);
        pInsertionSort(Array, arraySize, ascending);
        std::cout << "\vВывод отсортированного массива, в порядке возростания" << '\n';
        pPrintArray(Array, arraySize);
        pInsertionSort(Array, arraySize, descending);
        std::cout << "\vВывод отсортированного массива, в порядке убывания" << '\n';
        pPrintArray(Array, arraySize);
    }
        break;

        // создание массива типа float
    case Type_Float : {
        // Вводим размер массива с проверками корректности
        std::cout << "Введите число для длины массива от 1 до 100 : ";
        arraySize = Type_Thecking(arraySize, sizeMin, sizeMax);
        float Array[max_length];
        pRandNumGen(Array, arraySize);
        std::cout << "\vВывод не отсортированного массива" << '\n';
        pPrintArray(Array, arraySize);
        pInsertionSort(Array, arraySize, ascending);
        std::cout << "\vВывод отсортированного массива, в порядке возростания" << '\n';
        pPrintArray(Array, arraySize);
        pInsertionSort(Array, arraySize, descending);
        std::cout << "\vВывод отсортированного массива, в порядке убывания" << '\n';
        pPrintArray(Array, arraySize);
    }
        break;

        // создание массива типа double
    case Type_Double : {
        // Вводим размер массива с проверками корректности
        std::cout << "Введите число для длины массива от 1 до 100 : ";
        arraySize = Type_Thecking(arraySize, sizeMin, sizeMax);
        double Array[max_length];
        pRandNumGen(Array, arraySize);
        std::cout << "\vВывод не отсортированного массива" << '\n';
        pPrintArray(Array, arraySize);
        pInsertionSort(Array, arraySize, ascending);
        std::cout << "\vВывод отсортированного массива, в порядке возростания" << '\n';
        pPrintArray(Array, arraySize);
        pInsertionSort(Array, arraySize, descending);
        std::cout << "\vВывод отсортированного массива, в порядке убывания" << '\n';
        pPrintArray(Array, arraySize);
    }
        break;
    }
}

// функция для генерации случайных чисел
auto RandNumGen(void *xpArray, const short& size) -> void {

    srand(static_cast<unsigned int>(time(nullptr)));
    double fraction{1.0 / (static_cast<double>(RAND_MAX) + 1.0)};
    short min{1};
    short max{100};
    bool alreadyThere;


    switch (choice) {
    case Type_Char :{

        short min{65};
        short max{90};
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (auto i{0}; i < size; ++i) {
            char *pdata =  static_cast<char*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (auto i{0}; i < size;) {
                alreadyThere = false;
                char newRandNum = static_cast<char>((rand() * fraction * (max - min + 1) + min));
                // цикл для заполнения массива уникальными значениями
                for (auto k{0}; k < i; ++k) {
                    if (pdata[k] == newRandNum) {
                        alreadyThere = true;
                    }
                }
                if (!alreadyThere) {
                    pdata[i] = newRandNum;
                    ++i;
                }
            }
        }
    }
        break;

    case Type_Short : {
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (auto i{0}; i < size; ++i) {
            short *pdata =  static_cast<short*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (auto i{0}; i < size;) {
                alreadyThere = false;
                short newRandNum = static_cast<short>((rand() * fraction * (max - min + 1) + min));
                // цикл для заполнения массива уникальными значениями
                for (auto k{0}; k < i; ++k) {
                    if (pdata[k] == newRandNum) {
                        alreadyThere = true;
                    }
                }
                if (!alreadyThere) {
                    pdata[i] = newRandNum;
                    ++i;
                }
            }
        }
    }
        break;

    case Type_Int : {
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (auto i{0}; i < size; ++i) {
            int *pdata =  static_cast<int*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (auto i{0}; i < size;) {
                alreadyThere = false;
                int newRandNum = static_cast<int>((rand() * fraction * (max - min + 1) + min));
                // цикл для заполнения массива уникальными значениями
                for (auto k{0}; k < i; ++k) {
                    if (pdata[k] == newRandNum) {
                        alreadyThere = true;
                    }
                }
                if (!alreadyThere) {
                    pdata[i] = newRandNum;
                    ++i;
                }
            }
        }
    }
        break;

    case Type_Float : {
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (auto i{0}; i < size; ++i) {
            float *pdata =  static_cast<float*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (auto i{0}; i < size;) {
                alreadyThere = false;
                float newRandNum = static_cast<float>((rand() * fraction * (max - min + 1) + min));
                // цикл для заполнения массива уникальными значениями
                for (auto k{0}; k < i; ++k) {
                    if (std::abs(pdata[k] - newRandNum) <= 1) {
                        alreadyThere = true;
                    }
                }
                if (!alreadyThere) {
                    pdata[i] = newRandNum;
                    ++i;
                }
            }
        }
    }
        break;

    case Type_Double : {
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (auto i{0}; i < size; ++i) {
            double *pdata =  static_cast<double*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (auto i{0}; i < size;) {
                alreadyThere = false;
                double newRandNum = static_cast<double>((rand() * fraction * (max - min + 1) + min));
                // цикл для заполнения массива уникальными значениями
                for (auto k{0}; k < i; ++k) {
                    if (std::abs(pdata[k] - newRandNum) <= 0.001) {
                        alreadyThere = true;
                    }
                }
                if (!alreadyThere) {
                    pdata[i] = newRandNum;
                    ++i;
                }
            }
        }
    }
        break;
    }
}


// функция вывода массива типон данных по выбору пользователя
auto PrintArray(void *xpArray, const short& size) -> void {
    switch (choice) {
    // заполнение массива типа short
    case Type_Char : {
        for (auto i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<char*>(xpArray) +i) << '\n';
        }
    }
        break;

        // заполнение массива типа short
    case Type_Short : {
        for (auto i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<short*>(xpArray) +i) << '\n';
        }
    }
        break;

        // заполнение массива типа int
    case Type_Int : {
        for (auto i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<int*>(xpArray) +i) << '\n';
        }
    }
        break;

        // заполнение массива типа float
    case Type_Float : {
        for (auto i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<float*>(xpArray) +i) << '\n';
        }
    }
        break;

        // заполнение массива типа double
    case Type_Double : {
        for (auto i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<double*>(xpArray) +i) << '\n';
        }
    }
        break;
    }
}


// функция для сортировки массива
auto InsertionSort(void *xpArray, const short& size, bool (*comparisonFcn)(short, short)) -> void {
    switch (choice) {
    case Type_Char: {
        char *pdata =  static_cast<char*>(xpArray);
        for(short i{0}; i < size; ++i)  {
            short j = i;
            while(j < size) {
                if (comparisonFcn(pdata[i], pdata[j]))
                    std::swap(pdata[i], pdata[j]);
                ++j;
            }
            //pdata[i] = *(static_cast<char*>(xpArray) + i);
        }
    }
        break;

    case Type_Short: {
        short *pdata =  static_cast<short*>(xpArray);
        for(short i{0}; i < size; ++i)  {
            short j = i;
            while(j < size) {
                if (comparisonFcn(pdata[i], pdata[j]))
                    std::swap(pdata[i], pdata[j]);
                ++j;
            }
            pdata[i] = *(static_cast<short*>(xpArray) + i);
        }
    }
        break;

    case Type_Int: {
        int *pdata =  static_cast<int*>(xpArray);
        for(short i{0}; i < size; ++i)  {
            short j = i;
            while(j < size) {
                if (comparisonFcn(pdata[i], pdata[j]))
                    std::swap(pdata[i], pdata[j]);
                ++j;
            }
            pdata[i] = *(static_cast<int*>(xpArray) + i);
        }
    }
        break;

    case Type_Float: {
        float *pdata =  static_cast<float*>(xpArray);
        for(short i{0}; i < size; ++i)  {
            short j = i;
            while(j < size) {
                if (comparisonFcn(pdata[i], pdata[j]))
                    std::swap(pdata[i], pdata[j]);
                ++j;
            }
            pdata[i] = *(static_cast<float*>(xpArray) + i);
        }
    }
        break;

    case Type_Double: {
        double *pdata =  static_cast<double*>(xpArray);
        for(short i{0}; i < size; ++i)  {
            short j = i;
            while(j < size) {
                if (comparisonFcn(pdata[i], pdata[j]))
                    std::swap(pdata[i], pdata[j]);
                ++j;
            }
            pdata[i] = *(static_cast<double*>(xpArray) + i);
        }
    }
        break;
    }
}


// функция сравнения, которая выполняет сортировку в порядке возрастания
auto ascending(short a, short b) -> bool {
    return a > b; // меняем местами, если первый элемент больше второго
}


// функция сравнения, которая выполняет сортировку в порядке убывания
auto descending(short a, short b) -> bool {
    return a < b; // меняем местами, если второй элемент больше первого
}
