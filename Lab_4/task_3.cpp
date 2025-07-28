#include<iostream>
#include <iomanip>

// функция для вывода английского алфавита от A до Z
auto FromAtoZ () -> void {
  std::cout << std::setw(40) << std::right<< " Задание 3)" << '\n' << "Алфавит английского языка" << std::setw(50) << std::right << "Десятичный код символа" << '\n';

    char c;  // создаём переменную
    // в цикле перебераем алфавит
    for ( c = 'A'; c <= 'Z'; ++c) {
        std::cout << std::setw(12) << std::right << c << std::setw(33) << std::right << static_cast<int>(c) << '\n';  //выводим алфавит с кодом ASCII символов
    }
}
