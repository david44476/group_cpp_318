#include <iostream>
#include<ctime>
#include <cstdlib>
#include"task_5.h"
#include"type_thecking.h"
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

    using pFunc = void(*)(void*, const size_t&);
    pFunc pRandNumGen= RandNumGen; // указатель на функцию генерации случайных чисел
    pFunc pPrintArray = PrintArray;  // указатель на функцию вывода массива
    pFunc pInsertionSort = InsertionSort;  // указатель на функцию сортировки массива
    short sizeMin{1};  // переменная для проверки ввода длины массива
    short sizeMax{100};  // переменная для проверки ввода длины массива

    switch (choice) {

    // создание массива типа char
    case Type_Char : {
        short sizeMax{25};
        // Вводим размер массива с проверками корректности
        std::cout << "Введите число для длины массива от 1 до 25 : ";
        arraySize = static_cast<size_t>(Type_Thecking(arraySize, sizeMin, sizeMax));
        char Array[max_length];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        pRandNumGen(Array, arraySize);
        pPrintArray(Array, arraySize);
        pInsertionSort(Array, arraySize);
        std::cout << "\vВывод отсортированного массива" << '\n';
        pPrintArray(Array, arraySize);
    }
        break;

        // создание массива типа short
    case Type_Short : {
        // Вводим размер массива с проверками корректности
        std::cout << "Введите число для длины массива от 1 до 100 : ";
        arraySize = static_cast<size_t>(Type_Thecking(arraySize, sizeMin, sizeMax));
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
    case Type_Int : {
        // Вводим размер массива с проверками корректности
        std::cout << "Введите число для длины массива от 1 до 100 : ";
        arraySize = static_cast<size_t>(Type_Thecking(arraySize, sizeMin, sizeMax));
        int Array[max_length];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        RandNumGen(Array, arraySize);
        PrintArray(Array, arraySize);
        InsertionSort(Array, arraySize);
        std::cout << "\vВывод отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
    }
        break;

        // создание массива типа float
    case Type_Float : {
        // Вводим размер массива с проверками корректности
        std::cout << "Введите число для длины массива от 1 до 100 : ";
        arraySize = static_cast<size_t>(Type_Thecking(arraySize, sizeMin, sizeMax));
        float Array[max_length];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        RandNumGen(Array, arraySize);
        PrintArray(Array, arraySize);
        InsertionSort(Array, arraySize);
        std::cout << "\vВывод отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
    }
        break;

        // создание массива типа double
    case Type_Double : {
        // Вводим размер массива с проверками корректности
        std::cout << "Введите число для длины массива от 1 до 100 : " << '\n';
        arraySize = static_cast<size_t>(Type_Thecking(arraySize, sizeMin, sizeMax));
        double Array[max_length];
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
    bool alreadyThere;


    switch (choice) {
    case Type_Char :{

        short min{65};
        short max{90};
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (size_t i{0}; i < size; ++i) {
            char *pdata =  static_cast<char*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (size_t i{0}; i < size;) {
                alreadyThere = false;
                char newRandNum = static_cast<char>((rand() * fraction * (max - min + 1) + min));
                for (size_t k{0}; k < i; ++k) {
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
        for (size_t i{0}; i < size; ++i) {
            short *pdata =  static_cast<short*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (size_t i{0}; i < size;) {
                alreadyThere = false;
                short newRandNum = static_cast<short>((rand() * fraction * (max - min + 1) + min));
                for (size_t k{0}; k < i; ++k) {
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
        for (size_t i{0}; i < size; ++i) {
            int *pdata =  static_cast<int*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (size_t i{0}; i < size;) {
                alreadyThere = false;
                int newRandNum = static_cast<int>((rand() * fraction * (max - min + 1) + min));
                for (size_t k{0}; k < i; ++k) {
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
        for (size_t i{0}; i < size; ++i) {
            float *pdata =  static_cast<float*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (size_t i{0}; i < size;) {
                alreadyThere = false;
                float newRandNum = static_cast<float>((rand() * fraction * (max - min + 1) + min));
                for (size_t k{0}; k < i; ++k) {
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

    case Type_Double : {
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (size_t i{0}; i < size; ++i) {
            double *pdata =  static_cast<double*>(xpArray);
            // Равномерное распределение случайного числа в диапазоне от min до max
            for (size_t i{0}; i < size;) {
                alreadyThere = false;
                double newRandNum = static_cast<double>((rand() * fraction * (max - min + 1) + min));
                for (size_t k{0}; k < i; ++k) {
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
    }
}


// функция вывода массива типон данных по выбору пользователя
auto PrintArray(void *xpArray, const size_t& size) -> void {
    switch (choice) {
    // заполнение массива типа short
    case Type_Char : {
        for (size_t i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<char*>(xpArray) +i) << '\n';
        }
    }
        break;

        // заполнение массива типа short
    case Type_Short : {
        for (size_t i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<short*>(xpArray) +i) << '\n';
        }
    }
        break;

        // заполнение массива типа int
    case Type_Int : {
        for (size_t i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<int*>(xpArray) +i) << '\n';
        }
    }
        break;

        // заполнение массива типа float
    case Type_Float : {
        for (size_t i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<float*>(xpArray) +i) << '\n';
        }
    }
        break;

        // заполнение массива типа double
    case Type_Double : {
        for (size_t i{0}; i < size; ++i) {
            std::cout << "элемент [" << i << ']'  << " значение " << *(static_cast<double*>(xpArray) +i) << '\n';
        }
    }
        break;
    }
}


// функция для сортировки массива
auto InsertionSort(void *xpArray, const size_t& size) -> void {
    short sizeArray = static_cast<short>(size);
    switch (choice) {
    case Type_Char: {
        for(short i = 1; i < sizeArray; i++)
        {
            char *pdata =  static_cast<char*>(xpArray);
            short j = i - 1;
            while(j >= 0 && pdata[j] > pdata[j + 1])
            {
                std::swap(pdata[j], pdata[j + 1]);
                j--;
            }
            pdata[i] = *(static_cast<char*>(xpArray) + i);
        }
    }
        break;

    case Type_Short: {
        for(short i = 1; i < sizeArray; i++)
        {
            short *pdata =  static_cast<short*>(xpArray);
            short j = i - 1;
            while(j >= 0 && pdata[j] > pdata[j + 1])
            {
                std::swap(pdata[j], pdata[j + 1]);
                j--;
            }
            pdata[i] = *(static_cast<short*>(xpArray) + i);
        }
    }
        break;

    case Type_Int: {
        for(short i = 1; i < sizeArray; i++)
        {
            int *pdata =  static_cast<int*>(xpArray);
            short j = i - 1;
            while(j >= 0 && pdata[j] > pdata[j + 1])
            {
                std::swap(pdata[j], pdata[j + 1]);
                j--;
            }
            pdata[i] = *(static_cast<int*>(xpArray) + i);
        }
    }
        break;

    case Type_Float: {
        for(short i = 1; i < sizeArray; i++)
        {
            float *pdata =  static_cast<float*>(xpArray);
            short j = i - 1;
            while(j >= 0 && pdata[j] > pdata[j + 1])
            {
                std::swap(pdata[j], pdata[j + 1]);
                j--;
            }
            pdata[i] = *(static_cast<float*>(xpArray) + i);
        }
    }
        break;

    case Type_Double: {
        for(short i = 1; i < sizeArray; i++)
        {
            double *pdata =  static_cast<double*>(xpArray);
            short j = i - 1;
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
