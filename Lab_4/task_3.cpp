#include<iostream>
#include <iomanip>

// функция для вывода английского алфавита от A до Z
auto FromAtoZ () -> void {
  std::cout << std::setw(30) << std::right<< " Задание 3)" << '\n';
  std::cout << "Разработайте программу, которая, используя циклы\n"
               "(while, do while или for), выводит буквы\n"
               "английского алфавита от a до z вместе с десятичными кодами\n"
               "с таблицы ASCII. Сама таблица приведена в лекции по типам данных,\n"
               "но её можно также найти в интернете. Подсказка:\n"
               "чтобы выводить символы как целые числа ? \n"
               "используйте static cast . Пример вывода\n"
               "(коды ASCII в примере приведены неправильно):\n"
               "Алфавит Десятичный код символа английского языка\n\n";
  std::cout << "Алфавит английского языка" << std::setw(50) << std::right << "Десятичный код символа" << '\n';



  char c;  // создаём переменную
  // в цикле перебераем алфавит
  for ( c = 'A'; c <= 'Z'; ++c) {
      std::cout << std::setw(12) << std::right << c << std::setw(33) << std::right << static_cast<int>(c) << '\n';  //выводим алфавит с кодом ASCII символов
    }
}
