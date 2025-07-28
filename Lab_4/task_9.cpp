#include<iostream>
#include <cstdlib>
#include<iomanip>
#include"template_functions.h" // содержит мои функции для проверки ввода символьнных переменных

// деклорацция функций для задания № 9
// шаблонная функция  которая выполняет сортировку
template <typename T, typename D, typename A>
auto InsertionSort1 (T *xpArray, const D& size, A (*comparisonFcn)(short)) -> void;
// функция которая выполняет сравнивание с условием чётности элементов
auto Parity (short a) -> bool;
////////////////////////////////////////////////////////////////////////////////////////

// функций для задания № 9
auto Task_9 () -> void {

  std::cout << std::setw(30) << std::right << "Задание 9)" << '\n';
  std::cout << "Передайте указатель в функцию на массив типа char\n"
               "и для 12-ти элементов. Необходимо реализовать в\n"
               "этой функции, которая поменяет значения четных\n"
               "и нечетных ячеек массива.\n\n";

constexpr short size{12}; // переменная для длины массива

  short min{65}; // минимальное значение для генератора случайных чисел
  short max{90}; // максимальное значение для генератора случайных чисел

  char array [size]; // создание массива

  MyGen (array, size, min, max); //функция для своего генератора случайных чисел
  PrintArray2 (array, size, "исходный массив"); // функция для вывода массива
  InsertionSort1 (array, size, Parity); // функция которая выполняет сортировку
  PrintArray2 (array, size, "отсортированный массив с условием чётности элементов"); // функция для вывода массива
}


// шаблонная функция  которая выполняет сортировку
template <typename T, typename D, typename A>
auto InsertionSort1 (T *xpArray, const D& size, A (*comparisonFcn)(short)) -> void {
  for(auto i{0}; i < size; ++i) {
      if (comparisonFcn(static_cast<char>(i))) {
          auto tmp = xpArray[i];
          xpArray[i] =xpArray[i + 1];
          xpArray[i + 1] = tmp;
        }
    }
}


// функция которая выполняет сравнивание с условием чётности элементов
auto Parity (short a) -> bool {

  return a % 2 == 0;
}
