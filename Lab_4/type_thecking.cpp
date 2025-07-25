#include<iostream>
#include<limits>

// проверка на коректность ввода
auto Type_Thecking (short a, short min, short max) -> short {
    while (true) {
        if (! (std::cin >> a) || a < min || a > max || a == ' ') {
            std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<short>::max(), '\n');
        }
        else break;
    }
    return a;
}


// проверка на коректность ввода
auto Type_Thecking (char c) -> char {
    while (true) {
        std::cin >> c;
        if ( ! (c == 'Y' || c == 'y' || c == 'N' || c == 'n') || c == ' ') {
            std::cout << "Вы ввели не верный символ!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<char>::max(), '\n');
        }
        else break;
    }
    return c;
}


// проверка на коректность ввода
auto Type_Thecking (short a) -> short {
    while (true) {
        if (! (std::cin >> a)) {
            std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<short>::max(), '\n');
        }
        else break;
    }
    return a;
}

auto Type_Thecking (unsigned int a) -> unsigned int {
    while (true) {
        if (! (std::cin >> a)) {
            std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<unsigned short>::max(), '\n');
        }
        else break;
    }
    return a;
}


// проверка на коректность ввода
auto Type_Thecking(double a) -> double {
    while (true) {
        if (! (std::cin >> a)) {
            std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<double>::max(), '\n');
        }
        else break;
    }
    return a;
}


// функция для проверки ввода типа char введённое пользователем от A до Z
auto Char_Type_Thecking (char c) -> char {
    while (true) {
        if (! (std::cin >> c) || ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))) {
            std::cout << "Вы ввели не верный символ!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<char>::max(), '\n');
        }
        else break;
    }
    return c;
}
