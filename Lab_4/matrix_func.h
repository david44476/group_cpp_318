#ifndef TEST_H
#define TEST_H
#include<iostream>
#include<time.h>
#include <iomanip>
#include <cstring>

#define MAX_ROWS 100 // максимальное количество строк
#define MAX_COLUMNS 100 // максимальное количество столбцов

//построение единичной матрици
template <typename T, typename D>
auto IdentityMatrix (T MyArray[][MAX_COLUMNS], const D& nRow, const D& nCol) -> void {
  for (auto i = 0; i < nRow; ++i) {
      for (auto j = 0; j < nCol; ++j)
        {
          if (i == j) {MyArray [i] [j] = 1;}
          else {MyArray [i] [j] = 0;}
        }
    }
}

// Находим сумму элементов матрицы, лежащих выше главной диагонали
template <typename T, typename D>
auto SumMatrix (T Array [][MAX_COLUMNS], const D& nRow, const D& nCol) -> T {
  T S{0};  // переменная для суммы элементов матрицы, лежащих выше главной диагонали
  for (auto i = S = 0; i < nRow; ++i) {
      for (auto j = 0; j < nCol; ++j) {
          if (i < j) {S += Array [i] [j];}
        }
    }
  return S;
}

//шаблонная функция для своего генератора случайных чисел
template <typename T, typename D>
auto MyGen2 (T Array[][MAX_COLUMNS], const D& nRow, const D& nCol ,const D& Gmin, const D& Gmax) -> void {
  srand(static_cast<unsigned int>(time(nullptr)));
  double fraction{1.0 / (static_cast<double>(RAND_MAX) + 1.0)};
  // Равномерное распределение случайного числа в диапазоне от min до max
  for (auto i{0}; i < nRow; ++i) {
      // Равномерное распределение случайного числа в диапазоне от min до max
      for (auto j{0}; j < nCol;++j) {
          Array[i][j] = static_cast< T>((rand() * fraction * (Gmax - Gmin + 1) + Gmin));
        }
    }
}


// шаблонная фуиуция для вывода массива
template <typename T, typename D>
auto PrintArray (T Array[][MAX_COLUMNS], const D& nRow, const D& nCol, const char* str) -> void {
  std::cout << std::setw(40) << std::right << str << "\n";
  for (auto i{0}; i < nRow; ++i) {
      for(auto j{0}; j < nCol; ++j) {
          std::cout << std::setw(6) << std::right << Array[i][j] << " ";
        }
      std::cout << "\n";
    }
  std::cout << "\n";
}
#endif // TEST_H
