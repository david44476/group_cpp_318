#include<iostream>
#include<limits>

// проверка на коректность ввода
auto Type_Thecking (short a, short min, short max) -> short
{
    while (true)
    {
        if (! (std::cin >> a) || a < min || a > max || a == ' ')
        {
            std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<short>::max(), '\n');
        }
        else break;
    }
    return (a);
}


// проверка на коректность ввода
auto Type_Thecking (char c) -> char
{
    while (true)
    {
        std::cin >> c;
        if ( ! (c == 'Y' || c == 'y' || c == 'N' || c == 'n') || c == ' ')
        {
            std::cout << "Вы ввели не верный символ!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<char>::max(), '\n');
        }
        else break;
    }
    return (c);
}


// проверка на коректность ввода
auto Type_Thecking (short a) -> short
{
    while (true)
    {
        if (! (std::cin >> a))
        {
            std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<short>::max(), '\n');
        }
        else break;
    }
    return (a);
}
