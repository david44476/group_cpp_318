#include<iostream>
#include<iomanip>
#include"template_functions.h" // содержит определение моих шаблонных функций
#include"task_5.h"

// функция сравнения, которая выполняет сортировку в порядке возрастания
auto ascending (short a, short b) -> bool {
  return a > b; // меняем местами, если первый элемент больше второго
}


// функция сравнения, которая выполняет сортировку в порядке убывания
auto descending (short a, short b) -> bool {
  return a < b; // меняем местами, если второй элемент меньше первого
}

static short choice; // переменная выбора типа данных для созданния массива
static short arraySize; // переменная для длины массива по выбору пользователя
constexpr int max_length {100}; // максимальное количиство считываемых символов

// функция создания массива по выбору пользователя
auto CreateArray () -> void {

  std::cout << std::setw(30) << std::right<< "Задание 5)" << '\n';

  std::cout << "Cоздайте массив любого типа данных,\n"
               "который задается пользователем\n"
               "(char-1, 2-short, 3-int, 4-float, 5-double),\n"
               "количество элементов в котором ввводит пользователь.\n"
               "Заполните его с помощью рандома rand() сделайте\n"
               "сортировку массива любым методом (не используя\n"
               "библиотечную функцию сортировки).\n\n";

  std::cout << "Создание массива по параметрам пользоватля" << '\n';

  // переменые для проверки на коректность ввода
  constexpr short min {static_cast<short>(Type_Char)};
  constexpr short max {static_cast<short>(Type_Double)};
  std::cout << "Выберите какого типа даных хотите создать массив" << '\n'
                << "тип char нажмите 1,\n"
                "тип short нажмите 2,\n"
                "тип int нажмите 3,\n"
                "тип float нажмите 4,\n"
                "тип double нажмите 5 : ";

  choice = Type_Thecking (choice, min, max); // проверка на коректность ввода

  // переменные для проверки ввода длины массива и для диапазона генераии случайных чисел
  short sizeMin{1};
  short sizeMax{100};
  ////////////////////////

  switch (choice) {

    // создание массива типа char
    case Type_Char : {
        short sizeMax{25}; // указываем длину массива типа char
        short min{65}; // минимальное значение для генератора случайных чисел
        short max{90}; // максимальное значение для генератора случайных
        // Вводим размер массива с проверками корректности
        std::cout << "\vВведите число для длины массива от 1 до 25 и нажмите ввод : ";
        arraySize = Type_Thecking (arraySize, min, max); // проверка на коректность ввода
        char Array[max_length]; // создание массива типа char
        MyGen (Array, arraySize, sizeMin, sizeMax); //функция для своего генератора случайных чисел
        PrintArray2 (Array, arraySize, "\vВывод не отсортированного массива");
        InsertionSort (Array, arraySize, ascending); // функция для сортировки массива в порядке возростания
        PrintArray2 (Array, arraySize, "Вывод отсортированного массива, в порядке возростания");
        InsertionSort (Array, arraySize, descending); // функция для сортировки массива в порядке убывания
        PrintArray2 (Array, arraySize, "Вывод отсортированного массива, в порядке убывания");
      }
      break;

      // создание массива типа short
    case Type_Short : {
        // Вводим размер массива с проверками корректности
        std::cout << "\vВведите число для длины массива от 1 до 100 нажмите ввод : ";
        arraySize = Type_Thecking (arraySize, sizeMin, sizeMax); // проверка на коректность ввода
        short Array[max_length]; // создание массива типа short
        MyGen (Array, arraySize, sizeMin, sizeMax); //функция для своего генератора случайных чисел
        PrintArray2 (Array, arraySize, "\vВывод не отсортированного массива"); // функция для вывода массива
        InsertionSort (Array, arraySize, ascending); // функция для сортировки массива в порядке возростания
        PrintArray2 (Array, arraySize, "Вывод отсортированного массива, в порядке возростания"); // функция для вывода массива
        InsertionSort (Array, arraySize, descending); // функция для сортировки массива в порядке убывания
        PrintArray2 (Array, arraySize, "Вывод отсортированного массива, в порядке убывания"); // функция для вывода массива
      }
      break;

      // создание массива типа int
    case Type_Int : {
        // Вводим размер массива с проверками корректности
        std::cout << "\vВведите число для длины массива от 1 до 100 нажмите ввод : ";
        arraySize = Type_Thecking (arraySize, sizeMin, sizeMax); // проверка на коректность ввода
        int Array[max_length]; // создание массива типа int
        MyGen (Array, arraySize, sizeMin, sizeMax); //функция для своего генератора случайных чисел
        PrintArray2 (Array, arraySize, "\vВывод не отсортированного массива"); // функция для вывода массива
        InsertionSort (Array, arraySize, ascending); // функция для сортировки массива в порядке возростания
        PrintArray2 (Array, arraySize, "Вывод отсортированного массива, в порядке возростания"); // функция для вывода массива
        InsertionSort (Array, arraySize, descending); // функция для сортировки массива в порядке убывания
        PrintArray2 (Array, arraySize, "Вывод отсортированного массива, в порядке убывания"); // функция для вывода массива
      }
      break;

      // создание массива типа float
    case Type_Float : {
        // Вводим размер массива с проверками корректности
        std::cout << "\vВведите число для длины массива от 1 до 100 нажмите ввод : ";
        arraySize = Type_Thecking (arraySize, sizeMin, sizeMax); // проверка на коректность ввода
        float Array[max_length]; // создание массива типа float
        MyGen (Array, arraySize, sizeMin, sizeMax); //функция для своего генератора случайных чисел
        PrintArray2 (Array, arraySize, "\vВывод не отсортированного массива"); // функция для вывода массива
        InsertionSort (Array, arraySize, ascending); // функция для сортировки массива в порядке возростания
        PrintArray2 (Array, arraySize, "Вывод отсортированного массива, в порядке возростания"); // функция для вывода массива
        InsertionSort (Array, arraySize, descending); // функция для сортировки массива в порядке убывания
        PrintArray2 (Array, arraySize, "Вывод отсортированного массива, в порядке убывания"); // функция для вывода массива
      }
      break;

      // создание массива типа double
    case Type_Double : {
        // Вводим размер массива с проверками корректности
        std::cout << "\vВведите число для длины массива от 1 до 100 нажмите ввод : ";
        arraySize = Type_Thecking (arraySize, sizeMin, sizeMax); // проверка на коректность ввода
        double Array[max_length]; // создание массива типа double
        MyGen (Array, arraySize, sizeMin, sizeMax); //функция для своего генератора случайных чисел
        PrintArray2 (Array, arraySize, "\vВывод не отсортированного массива"); // функция для вывода массива
        InsertionSort (Array, arraySize, ascending); // функция для сортировки массива в порядке возростания
        PrintArray2 (Array, arraySize, "Вывод отсортированного массива, в порядке возростания"); // функция для вывода массива
        InsertionSort (Array, arraySize, descending); // функция для сортировки массива в порядке убывания
        PrintArray2 (Array, arraySize, "Вывод отсортированного массива, в порядке убывания"); // функция для вывода массива
      }
      break;
    }
}





