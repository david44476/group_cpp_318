#include<iostream>
#include<limits>

// функция на корректность ввода
auto Type_Thecking (short a, short min, short max ) -> short
{
    while (true)
    {
        if ( ! (std::cin >> a) || a < min || a > max || std::cin.fail()) // условия для проверки
        {
            std::cout << "Вы ввели не верные даные!\n Попробуйте ещё раз! : ";
            std::cin.clear (); // обнуляем флаги состояния ошибки потока
            std::cin.ignore (std::numeric_limits<short>::max (), '\n'); // функция для игнорирования (или отбрасывания) определенного количества символов из буфера ввода
        }
        else break;
    }
    return a;
}


// функция на корректность ввода
auto Type_Thecking (char) -> char
{
    char choice;
    while (true)
    {
        std::cin >> choice; // ввод символа для проверки
        if ( ! (choice == 'y' || choice == 'n' || choice == 'Y' || choice == 'N')) // условия для проверки
        {
            std::cout << "Вы ввели не верный символ!\n Попробуйте ещё раз! : ";
            std::cin.clear (); // // обнуляем флаги состояния ошибки потока
            std::cin.ignore (std::numeric_limits<char>::max (), '\n'); // функция для игнорирования (или отбрасывания) определенного количества символов из буфера ввода
        }
        else break;
    }
    return choice;
}
// функция на корректность ввода
auto Type_Thecking (short a) -> short
{
    while (true)
    {
        if ( ! (std::cin >> a)) // условия для проверки
        {
            std::cout << "Вы ввели не верные даные!\n Попробуйте ещё раз! : ";
            std::cin.clear (); // обнуляем флаги состояния ошибки потока
            std::cin.ignore (std::numeric_limits<short>::max (), '\n'); // функция для игнорирования (или отбрасывания) определенного количества символов из буфера ввода
        }
        else break;
    }
    return a;
}
