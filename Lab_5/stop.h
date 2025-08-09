#ifndef STOP_H
#define STOP_H
#include<iostream>
#include<limits>

// деклорация функции для проверки ввода
auto Type_Thecking (char c) -> char;

// функция для останоки или продолжения выполнения программы по выбору пользователя
auto Stop () -> bool {
    bool  stop = false;
    // запрос пользователю на выбор действия
    std:: cout << "Хотите продолжить введите 'Y, а если хотите прекратить 'N' и нажмите ввод: ";
    char choice{};
    choice = Type_Thecking (choice); // проверка на корректность ввода
    std::cout << '\n';

    // условие для действия по выбору пользователя
    if (choice == 'Y' || choice == 'y') stop = false;

    else if (choice == 'N' || choice == 'n') stop = true;

    std::cin.ignore (std::numeric_limits<char>::max (), '\n');
    return stop;
}
#endif // STOP_H
