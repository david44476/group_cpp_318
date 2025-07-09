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
auto RandNumGen(void *xpArray, const size_t& size) -> void;  // функция для генерации случайных чисел
auto PrintArray(void *xpArray, const size_t& size) -> void;  // функция для вывода массива
auto InsertionSort(void *xpArray, const size_t& size) -> void;  // функция для сортировки массива
#endif // TASK_5_H
