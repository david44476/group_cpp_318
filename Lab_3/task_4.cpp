/* подключаем библиотеку для ввода/вывода */
#include<iostream>

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


void get_Animal_Name (short name) // функция для вывода имя животного в консоль
{
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
    }
}

void print_Number_Of_Legs (short name) // функция для вывода количества лап соответствующего типа животного.
{
    // вывод количества лап соответствующего типа животного.
    switch (name)
    {
    case ANIMAL_PIG:
        std::cout << "Это свинья  у неё четыре лапы\n";
        break;
    case ANIMAL_GHICKEN:
        std::cout << "Это курица у неё две лапки\n";
        break;
    case ANIMAL_GOAT:
        std::cout << "Это козел у него четыре лапы\n";
        break;
    case ANIMAL_CAT:
        std::cout << "Это кошка у неё четыре лапы\n";
        break;
    case ANIMAL_DOG:
        std::cout << "Это собака у неё четыре лапы\n";
        break;
    default:
    std::cout << "Что то пошло не по плану!!!\n";
    }
}

