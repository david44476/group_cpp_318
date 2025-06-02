#include <iostream>
#include"type_thecking.h"  // подключаем заголовочнй файл с функцией для проверки коректности ввода
#include"fill_the_array.h"  // // подключаем заголовочнй файл с функцией для создания массива

// создаём перечесление типов даных
enum MyArray
{
    MayArray_Char = 1,
    MayArray_Short,
    MayArray_Int,
    MayArray_Float,
    MayArray_Double,
};

// функция создания массива по выбору пользователя
auto MyArray() -> void
{
    // переменые для проверки на коректность ввода
    short min = static_cast<short>(MayArray_Char);
    short max = static_cast<short>(MayArray_Double);

    std::cout << "Выберите какого типа даных хотите создать массив" << '\n'
              << "Тип char нажмите 1, тип short нажмите 2, тип int нажмите 3, тип float нажмите 4,"
              << "тип double нажмите 5 :";

    short choice;
    short (* PtrType_Thecking)(short a, short min, short max) = Type_Thecking;  // указатель на функцию
    choice = PtrType_Thecking(choice, min, max);  // проверка на коректность ввода

    switch (choice)
    {
        // создание массива типа char
    case MayArray_Char :
        char cvalue;
        FillTheArray(cvalue);
        break;

        // создание массива типа short
    case MayArray_Short :
        short svalue;
        FillTheArray(svalue);
        break;

        // создание массива типа int
    case MayArray_Int :
        int ivalue;
        FillTheArray(ivalue);
        break;

        // создание массива типа float
    case MayArray_Float :
        float fvalue;
        FillTheArray(fvalue);
        break;

        // создание массива типа double
    case MayArray_Double :
        double dvalue;
        FillTheArray(dvalue);
        break;
    }
}
