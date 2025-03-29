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

void get_Animal_Name () // функция для вывода имя животного в консоль
{
    // запрос пользователю ввести номер животного из списка
skip:
    std::cout << "Введите число из списка с животными:\n свинья = 1, курица = 2, козёл = 3, кошка = 4, собака = 5 и нажмите ввод: ";
    short name; // обьявляем переменную для номера животного

    // проверка на корректность ввода
    if (!(std::cin >> name))
    {
        std::cout << "Вы вели не корректное значение!\n";
        std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
        std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        goto skip;
    }

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
        goto skip;
    }
    // запрос пользователю на выбор действия
    std:: cout << "Хотите продолжить введите 'да', а если хотите покинуть  введите 'нет' и нажмите ввод: ";
    std::string choice; // переменная для выбора
    std::cin >> choice; // ввод символа с клавиатуры

    // условие для действия по выбору пользователя
    if (choice == "да")
    {
        goto skip;
    }
    else if (choice == "нет") exit(0); // выход из праграммы по выбору пользователя

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

