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

// деклорацция функций длязадания № 5
auto CreateArray () -> void;  // функция создания массива по выбору пользователя
auto descending (short a, short b) -> bool;  // функция сравнения, которая выполняет сортировку в порядке убывания
auto ascending (short a, short b) -> bool;  // функция сравнения, которая выполняет сортировку в порядке возрастания
#endif // TASK_5_H
