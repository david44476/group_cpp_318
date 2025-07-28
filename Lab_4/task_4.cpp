#include<iostream>
#include<iomanip>
#include"template_functions.h" // Содержит определение моих шаблонных функций

//функция для  задания № 4
auto Task_4 () -> void {

  // деклорацция функций длязадания № 4
  auto FacItr (short a) -> unsigned long long;
  auto FacRec (short a) ->unsigned long long;
  auto Fibonacci() -> void;
  auto Pyramid(short b) -> void;
////////////////////////////////////////////////

  std::cout << std::setw(30) << std::right<< "Задание 4.a)" << '\n' << "Нахождение Факториала с помощью итерации и рекурсии" << '\n';
  std::cout << "Введите целое число: ";
  short b{}; // пременная для ввода пользователем
  b = Type_Thecking (b);  //проверка на коректность ввода

  // вызов функции для нахождения Факториала с помощью итерации
  std::cout << "Факториал найденный с помощью итерации = " << FacItr (b) << '\n';

  // вызов функции для нахождения Факториала с помощью рекурсии
  std::cout << "Факториал найденный с помощью рекурсии = " << FacRec (b) << '\n';

  std::cout << std::setw(30) << std::right<< "Задание 4.б)" << '\n' << "Находим Число Фибоначчи, соответствующее заданному числу пользователя" << '\n';

  // выызов функции для нахождения числа Фибоначчи с помощью итерации
  Fibonacci();

  std::cout << std::setw(29) << std::right<< "Задание 4.c)" << '\n';
  std::cout << "Введите целое число: ";
  b = Type_Thecking (b);  //проверка на коректность ввода
  Pyramid(b);
}


// функция для нахождения Факториала с помощью итерации
auto FacItr (short a) -> unsigned long long {
    long long fact {1};

    for (int i {1}; i <=a; i++) {
        fact = fact * i;
    }
    return static_cast<unsigned long long>(fact);
}

// функция для нахождения Факториала с помощью рекурсии
auto FacRec (short a) ->unsigned long long {
    if (a > 1) {
        return static_cast<unsigned long long>(a)* FacRec(a -1);
    }
    return 1;
}


// функция для нахождения числа Фибоначчи с помощью итерации
auto Fibonacci() -> void {
    int i {};
    int a {};
    int d {1};
    int c {0};
    std::cout << "Введите целое число: ";
    short q {};
    q = Type_Thecking(q);  // проверка на коректность ввода
    std::cout << "Число Фибоначчи, соответствующее заданному числу пользователя" << '\n';
    while (i < q) {
        a = d;
        d = c;
        c = a + d;
        std::cout << static_cast<unsigned>(c) << ' ';
        i++;
    }
    std::cout << std::endl;
}


// функция построения пирамидки
auto Pyramid(short b) -> void {
    int number = static_cast<int>((-1 + sqrt(1 + 4 * 2 * b)) / 2);
    for (int i = 1, sum; i <= number; ++i) {
        sum = 0;
        for (int k = number; k > i; --k) {
            std::cout << ' ';
        }
        std::cout << ' ';
        for (int j = 1; j <= i; ++j) {
            std::cout << j << ' ';
            sum += j;
        }
        std::cout << ' ' << sum << std::endl;
    }
}
