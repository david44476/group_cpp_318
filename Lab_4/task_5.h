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

auto CreateArray() -> void;  // функция создания массива по выбору пользователя
auto RandNumGen(void *xpArray, const short& size) -> void;  // функция для генерации случайных чисел
auto PrintArray(void *xpArray, const short& size) -> void;  // функция для вывода массива
auto InsertionSort(void *xpArray, const short& size, bool (*comparisonFcn)(short, short)) -> void;  // функция для сортировки массива
auto descending(short a, short b) -> bool;  // функция сравнения, которая выполняет сортировку в порядке убывания
auto ascending(short a, short b) -> bool;  // функция сравнения, которая выполняет сортировку в порядке возрастания
#endif // TASK_5_H
