/* подключаем библиотеку для ввода/вывода */
#include<iostream>

// обьявляем перечеслительный тип даных
enum Animal
{
    ANIMAL_PIG = 1,
    ANIMAL_GHICKEN,
    ANIMAL_GOAT,
    ANIMAL_CAT,
    ANIMAL_DOG,
};

void printNumberOfLegs(short); // декларируем функцию для вывода количества лап соответствующего типа животного.


void getAnimalName(short name) // функция для вывода имя животного в консоль
{
    // вывод имя животного в консоль в соответствии с условием
    switch (name)
    {
    case ANIMAL_PIG:
        std::cout << "Свинья\n";
        printNumberOfLegs(name); // вызов функции для вывода количества лап соответствующего типа животного.
        break;
    case ANIMAL_GHICKEN:
        std::cout << "Курица\n";
        printNumberOfLegs(name); // вызов функции для вывода количества лап соответствующего типа животного.
        break;
    case ANIMAL_GOAT:
        std::cout << "Козел\n";
        printNumberOfLegs(name); // вызов функции для вывода количества лап соответствующего типа животного.
        break;
    case ANIMAL_CAT:
        std::cout << "Кошка\n";
        printNumberOfLegs(name); // вызов функции для вывода количества лап соответствующего типа животного.
        break;
    case ANIMAL_DOG:
        std::cout << "Собака\n";
        printNumberOfLegs(name); // вызов функции для вывода количества лап соответствующего типа животного.
        break;
    default:
        std::cout << "Что то пошло не по плану!!!\n";
    }
}

void printNumberOfLegs(short name) // функция для вывода количества лап соответствующего типа животного.
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

