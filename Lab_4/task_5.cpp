#include <iostream>
#include<ctime>
#include <cstdlib>
#include"type_thecking.h"  // подключаем заголовочнй файл с функцией для проверки коректности ввода
#include<task_5.h>

static short choice;
static short arraySize;

// функция создания массива по выбору пользователя
auto MyArray() -> void
{
    constexpr int max_length {100}; // максимальное количиство считываемых символов
    // переменые для проверки на коректность ввода
    constexpr short min = static_cast<short>(Type_Char);
    constexpr short max = static_cast<short>(Type_Double);
    std::cout << "Выберите какого типа даных хотите создать массив" << '\n'
              << "Тип char нажмите 1, тип short нажмите 2, тип int нажмите 3, тип float нажмите 4,"
              << "тип double нажмите 5 :";
    choice = Type_Thecking(choice, min, max);  // проверка на коректность ввода

    // Вводим размер массива с проверками корректности
    std::cout << "Введите число для длины массива от 1 до 100 : ";
    constexpr short sizeMin{1};
    constexpr short sizeMax{100};
    arraySize = Type_Thecking(arraySize, sizeMin, sizeMax);

    switch (choice)
    {
    // создание массива типа char
    case Type_Char :
    {
        char Array[arraySize];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
        break;
    }
        // создание массива типа short
    case Type_Short :
    {
        short Array[arraySize];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
    }
        break;
        // создание массива типа int
    case Type_Int :
    {
        int Array[arraySize];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
        break;
    }
        // создание массива типа float
    case Type_Float :
    {
        float Array[arraySize];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
    }
        break;
        // создание массива типа double
    case Type_Double :
    {
        double Array[arraySize];
        std::cout << "\vВывод не отсортированного массива" << '\n';
        PrintArray(Array, arraySize);
        break;
    }
    }
}



auto randNumGen() -> void*
{
    switch (choice)
    {
    case Type_Char :
    {
        short min{65};
        short max{90};
        srand(static_cast<unsigned int>(time(nullptr)));
        double fraction = 1.0 / (static_cast<char>(RAND_MAX) + 1.0);

        // Равномерное распределение случайного числа в диапазоне от min до max
        char ranNum = static_cast<char>((rand() * fraction * (max - min + 1) + min));
        //std::cout << " значение ranNum " << ranNum;
        void *size = static_cast<char*>(&ranNum);
        return size;
    }
    case Type_Short :
    {
        short min{1};
        short max{100};
        srand(static_cast<unsigned int>(time(nullptr)));
        double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

        // Равномерное распределение случайного числа в диапазоне от min до max
        short ranNum = static_cast<short>((rand() * fraction * (max - min + 1) + min));
        void *size = static_cast<short*>(&ranNum);
        return size;
    }
    case Type_Int :
    {
        short min{1};
        short max{100};
        srand(static_cast<unsigned int>(time(nullptr)));
        double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

        // Равномерное распределение случайного числа в диапазоне от min до max
        int ranNum = static_cast<int>((rand() * fraction * (max - min + 1) + min));
        void *size = static_cast<int*>(&ranNum);
        return size;
    }
    case Type_Float :
    {
        short min{1};
        short max{100};
        srand(static_cast<unsigned int>(time(nullptr)));
        double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

        // Равномерное распределение случайного числа в диапазоне от min до max
        float ranNum = static_cast<float>((rand() * fraction * (max - min + 1) + min));
        void *size = static_cast<float*>(&ranNum);
        return size;
    }
    case Type_Double :
    {
        short min{1};
        short max{100};
        srand(static_cast<unsigned int>(time(nullptr)));
        double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

        // Равномерное распределение случайного числа в диапазоне от min до max
        double ranNum = static_cast<double>((rand() * fraction * (max - min + 1) + min));
        void *size = static_cast<double*>(&ranNum);
        return size;
    }
    }
    return 0;
}


auto PrintArray(void *ptrArray, short size) -> void
{
    switch (choice)
    {
    // заполнение массива типа char
    case Type_Char :
    {
        for (auto i{0}; i < size; ++i)
        {
            char *ptrArray = static_cast<char*>(randNumGen());
            std::cout << "элемент [" << i << ']'  << " значение " << ptrArray[i] << '\n';
        }
        break;
    }

        // заполнение массива типа short
    case Type_Short :
    {
        for (auto i{0}; i < size; ++i)
        {
            short *ptrArray = (static_cast<short*>(randNumGen()) + i);
            std::cout << "элемент [" << i << ']'  << " значение " << ptrArray[i] << '\n';
        }
        break;
    }

        // заполнение массива типа int
    case Type_Int :
    {
        for (auto i{0}; i < size; ++i)
        {
            int *ptrArray = (static_cast<int*>(randNumGen()) + i);
            std::cout << "элемент [" << i << ']'  << " значение " << ptrArray[i] << '\n';
        }
        break;
    }

        // заполнение массива типа float
    case Type_Float :
    {
        for (auto i{0}; i < size; ++i)
        {
            float *ptrArray = (static_cast<float*>(randNumGen()) + i);
            std::cout << "элемент [" << i << ']'  << " значение " << ptrArray[i] << '\n';
        }
        break;
    }

        // заполнение массива типа double
    case Type_Double :
    {
        for (auto i{0}; i < size; ++i)
        {
            double *ptrArray = (static_cast<double*>(randNumGen()) + i);
            std::cout << "элемент [" << i << ']'  << " значение " << ptrArray[i] << '\n';
        }
        break;
    }
    }
}


