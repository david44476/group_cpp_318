#include<iostream>
#include<limits>

// проверка на коректность ввода
auto Type_Thecking (char& c) -> char {
    while (true) {
        std::cin >> c;
        if ( ! (c == 'Y' || c == 'y' || c == 'N' || c == 'n') || c == ' ') {
            std::cout << "Вы ввели не верный символ!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<char>::max (), '\n');
        }
        else break;
    }
    return c;
}

// проверка на коректность ввода
auto Choice_Type_Thecking (unsigned char c) -> unsigned char {
    while (true) {
        std::cin >> c;
        if ( ! (c == '&' || c == '|' || c == '^')) {
            std::cout << "Вы ввели не верный символ!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<char>::max (), '\n');
        }
        else break;
    }
    return c;
}

// функция для проверки ввода типа char введённое пользователем от A до Z
auto Char_Type_Thecking (char& c) -> char {
    while (true) {
        std::cin >> c;
        if ( ! (c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
            std::cout << "Вы ввели не верный символ!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<char>::max (), '\n');
        }
        else break;
    }
    return c;
}
