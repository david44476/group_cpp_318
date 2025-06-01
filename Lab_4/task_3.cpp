#include<iostream>

auto FromAtoZ () -> void  // функция для вывода английского алфавита от A до Z
{
    char c;  // создаём переменную
    for ( c = 'A'; c <= 'Z'; ++c)  // в цикле перебераем алфавит
    {
        std::cout << '\t' << c << "\t\t\t\t" << static_cast<int>(c) << '\n';  //выводим алфавит с кодом ASCII символов
    }
}
