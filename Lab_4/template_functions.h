#ifndef TEMPLATE_FUNCTIONS_H
#define TEMPLATE_FUNCTIONS_H
#include<iostream>
#include <random>
#include<ctime>
#include<limits>
#include <algorithm>

// шаблонная функция для нахождения максимального и минимального значения в массиве
template <typename T, typename D>
auto MinMax (T *Array, const D& size) -> void {
  T min{(*Array)};
  T max{(*Array)};
  for (auto i{0}; i < size; ++i) {
      if ( *(Array + i) < min) {min = *(Array + i);}  // находим минимальное значение
      if ( *(Array + i) > max) {max = *(Array + i);}  // находим максимальное значение
    }
  std::cout << "минимальное число : " << min << '\n';
  std::cout << "максимальное число : " << max << '\n';
  std::cout << std::endl;
}


// шаблонная функция для вывода массива
template <typename T, typename D>
auto PrintArray (T *Array, const D& size) -> void {
  for (auto i{0}; i < size; ++i) {
      std::cout << Array[i] << ' ';
    }
  std::cout << std::endl;
}


// шаблонная функция для вывода массива для 5 задания
template <typename T, typename D>
auto PrintArray2 (T *Array, const D& size, const char* str) -> void {
  std::cout << str << "\n";
  for (auto i{0}; i < size; ++i) {
      std::cout << "элемент [" << i << ']' << " значение " << Array[i] << '\n';
    }
  std::cout << std::endl;
}


// шаблонная функция для заполнения массива Вихрем Мерсена
template <typename T, typename D>
auto MersWhir (T *Array, const D& size) -> void {
  // генерируем случайные числа
  std::random_device rd;
  std::mt19937 mers(rd());
  bool alreadyThere;
  for (auto i{0}; i < size; ++i) {
      // Равномерное распределение случайного числа в диапазоне от min до max
      for (auto i{0}; i < size;) {
          alreadyThere = false;
          T newRandNum = static_cast<T>(mers());
          // цикл для заполнения массива уникальными значениями
          for (auto k{0}; k < i; ++k) {
              if (Array[k] == newRandNum) {
                  alreadyThere = true;
                }
            }
          if (!alreadyThere) {
              Array[i] = newRandNum;
              ++i;
            }
        }
    }
}


//шаблонная функция для своего генератора случайных чисел с диапазоном максимального и минимального значения
template <typename T, typename D>
auto MyGen (T *Array,const D& size, const D& Gmin, const D& Gmax) -> void {
  bool alreadyThere;
  srand(static_cast<unsigned int>(time(nullptr)));
  double fraction{1.0 / (static_cast<double>(RAND_MAX) + 1.0)};
  // Равномерное распределение случайного числа в диапазоне от min до max
  for (auto i{0}; i < size; ++i) {
      // Равномерное распределение случайного числа в диапазоне от min до max
      for (auto i{0}; i < size;) {
          alreadyThere = false;
          T newRandNum = static_cast<T>((rand() * fraction * (Gmax - Gmin + 1) + Gmin));
          // цикл для заполнения массива уникальными значениями
          for (auto k{0}; k < i; ++k) {
              if (Array[k] == newRandNum) {
                  alreadyThere = true;
                }
            }
          if (!alreadyThere) {
              Array[i] = newRandNum;
              ++i;
            }
        }
    }
}


// шаблонные функции для проверка на коректность ввода
template <typename T>
auto Type_Thecking (T a, T min, T max) -> T {
  while (true) {
      if (! (std::cin >> a) || a < min || a > max || a == ' ') {
          std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
          std::cin.clear ();
          std::cin.ignore (std::numeric_limits<T>::max(), '\n');
        }
      else break;
    }
  return a;
}


template <typename T>
auto Type_Thecking ( T a) -> T {
  while (true) {
      if (! (std::cin >> a)) {
          std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
          std::cin.clear ();
          std::cin.ignore (std::numeric_limits<T>::max(), '\n');
        }
      else break;
    }
  return a;
}
//////////////////////////////////////////////////////////////////////////


// шаблоннфя функция для сортировки массива
template <typename T, typename D>
auto InsertionSort (T *xpArray, const D& size, bool (*comparisonFcn)(short, short)) -> void {
        for(short i{0}; i < size; ++i) {
            short j = i;
            while(j < size) {
                if (comparisonFcn(xpArray[i], xpArray[j]))
                    std::swap(xpArray[i], xpArray[j]);
                ++j;
            }
        }
    }
#endif // TEMPLATE_FUNCTIONS_H
