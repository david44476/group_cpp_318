#include<iostream>
#include <algorithm>
#include<iomanip>
#include"template_functions.h" // содержит определение моих шаблонных функций

constexpr unsigned short size{5}; // переменая для длины массива

// функций для задания № 7
auto Faza() -> void {

  std::cout << std::setw(30) << std::right << "Задание 7)" << '\n';
  std::cout << "Сколько вариантов подключения\n"
               "понадобится электрику при подключении\n"
               "обмоток для 3х-фазного двигателя A B C N,\n"
               "напечатайте все перестановок данной строки фаз\n"
               "использованием ссылки.\n\n";

  // деклорация функции перестановки символов в массиве
  auto swap (char(&ref_array)[size]) -> void;
/////////////////////////////////////////////

  char fazaArray[size] = {'A','B','C','N', '\0'}; // массив символов

  std::cout << "Начальное подключении обмоток для 3х-фазного двигателя A, B, C, N ; где N нулевой провод" << '\n';
  for (auto i{0}; i < size -2; ++i) {
      std::cout << "фаза " << fazaArray[i] << '\n';
    }
  std::cout << fazaArray[3] << ' ' << "нулевой провод" << '\n';
  std::cout << "\vВарианты подключении обмоток для 3х-фазного двигателя" << '\n';
  for (auto i{1}; i < size + 2; ++i) {
      std::cout << std::setw(40) << std::right<< "Вариант № " << i << '\n';
      swap(fazaArray); // функция для перестановки символов в массиве
      PrintArray2(fazaArray, size - 1, "вывод с перестановкой"); // функция для вывода массива
    }
}

// функция для перестановки символов в массиве
auto swap(char(&ref_array)[size]) -> void {
      for (auto x{0} ;x < size; ++x){
    std::next_permutation(std::begin(ref_array), std::end(ref_array) - 2);
  }
}


