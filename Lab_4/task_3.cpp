#include<iostream>

// функция для вывода английского алфавита от A до Z
auto FromAtoZ () -> void {
    char c;  // создаём переменную
    // в цикле перебераем алфавит
    for ( c = 'A'; c <= 'Z'; ++c) {
        std::cout << '\t' << c << "\t\t\t\t" << static_cast<int>(c) << '\n';  //выводим алфавит с кодом ASCII символов
    }
}
