#ifndef TASK_5_H
#define TASK_5_H
#include<iostream>
enum Type
{
    Type_Char = 1,
    Type_Short,
    Type_Int,
    Type_Float,
    Type_Double,
};
auto MyArray() -> void;  // функция создания массива по выбору пользователя
auto randNumGen() -> void*;
auto PrintArray(void *array, short size) -> void;
#endif // TASK_5_H
