#include <iostream>
#include"type_thecking.h"
#include"fill_the_array.h"
enum MyArray
{
    MayArray_Char = 1,
    MayArray_Short,
    MayArray_Int,
    MayArray_Float,
    MayArray_Double,
};

auto MyArray() -> void
{
    std::cout << "Выберите какого типа даных хотите создать массив" << '\n'
              << "Тип char нажмите 1, тип short нажмите 2, тип int нажмите 3, тип float нажмите 4,"
              << "тип double нажмите 5 :";
    short choice;
    choice = Type_Thecking(choice);

    switch (choice)
    {
    case MayArray_Char :
        char cvalue;
        FillTheArray(cvalue);
        break;

    case MayArray_Short :
        short svalue;
        FillTheArray(svalue);
        break;

    case MayArray_Int :
        int ivalue;
        FillTheArray(ivalue);
        break;

    case MayArray_Float :
        float fvalue;
        FillTheArray(fvalue);
        break;

    case MayArray_Double :
        double dvalue;
        FillTheArray(dvalue);
        break;
    }
}
