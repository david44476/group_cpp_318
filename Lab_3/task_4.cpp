/* подключаем библиотеку для ввода/вывода */
#include<iostream>
#include"type_checking.h"
// обьявляем перечеслительный тип даных
enum Animal
{
    ANIMAL_PIG = 1, // свинья
    ANIMAL_GHICKEN, // курица
    ANIMAL_GOAT, // козел
    ANIMAL_CAT, // кошка
    ANIMAL_DOG, // собака
};

void print_Number_Of_Legs (short); // декларируем функцию для вывода количества лап соответствующего типа животного

void get_Animal_Name () // функция для вывода имя животного в консоль
{
    bool stop = false;
    do
    {
        // запрос пользователю ввести номер животного из списка
        std::cout << "Введите число из списка с животными:\n свинья = 1, курица = 2, козёл = 3, кошка = 4, собака = 5 и нажмите ввод: ";
        short name{}; // обьявляем переменную для номера животного

        short min {ANIMAL_PIG};
        short max {ANIMAL_DOG};

        // проверка на корректность ввода
        name = Type_Thecking  (name, min, max);

        // вывод имя животного в консоль в соответствии с условием
        switch (name)
        {
        case ANIMAL_PIG:
            std::cout << "Свинья\n";
            print_Number_Of_Legs (name); // вызов функции для вывода количества лап соответствующего типа животного.
            break;
        case ANIMAL_GHICKEN:
            std::cout << "Курица\n";
            print_Number_Of_Legs (name); // вызов функции для вывода количества лап соответствующего типа животного.
            break;
        case ANIMAL_GOAT:
            std::cout << "Козел\n";
            print_Number_Of_Legs (name); // вызов функции для вывода количества лап соответствующего типа животного.
            break;
        case ANIMAL_CAT:
            std::cout << "Кошка\n";
            print_Number_Of_Legs (name); // вызов функции для вывода количества лап соответствующего типа животного.
            break;
        case ANIMAL_DOG:
            std::cout << "Собака\n";
            print_Number_Of_Legs (name); // вызов функции для вывода количества лап соответствующего типа животного.
            break;
        default:
            std::cout << "Что то пошло не по плану!!!\n";
            break;
        }
        // запрос пользователю на выбор действия
        std:: cout << "Хотите продолжить введите 'Y', а если хотите покинуть введите 'N' и нажмите ввод: ";
        char choice {};

        // проверка на корректность ввода
        choice = Type_Thecking (choice);

        // условие для действия по выбору пользователя
        if (choice == 'Y' || choice == 'y') stop = false;

        else if (choice == 'N' || choice == 'n') stop = true;
    }
    while( ! stop);
}

void print_Number_Of_Legs (short name) // функция для вывода количества лап соответствующего типа животного.
{
    // вывод количества лап соответствующего типа животного.
    switch (name)
    {
    case ANIMAL_PIG:
        std::cout << "Это свинья,  у неё четыре лапы\n";
        break;
    case ANIMAL_GHICKEN:
        std::cout << "Это курица, у неё две лапки\n";
        break;
    case ANIMAL_GOAT:
        std::cout << "Это козел, у него четыре лапы\n";
        break;
    case ANIMAL_CAT:
        std::cout << "Это кошка, у неё четыре лапы\n";
        break;
    case ANIMAL_DOG:
        std::cout << "Это собака, у неё четыре лапы\n";
        break;
    default:
        std::cout << "Что то пошло не по плану!!!\n";
    }
}

