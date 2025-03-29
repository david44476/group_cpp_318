#include<iostream>

// обьявляем перечеслительный тип даных
enum Floor
{
    Floor_Parking, // порковка
    Floor_TradFloor, // торговом зал
    Floor_Cafe, // кафе
    Floor_Bowling, // боулинг клуб
    Floor_CinemaHall, // кино зал
    Floor_Casino, // казино
    Floor_PinHouse, // пин хаус
    Floor_Helipad, // верталётной площадка
};

void Elevator () // функция лифт
{
    // вывод в терминал предложения прокатится
    std::cout << "Предлогаем прокатится на вертуальном лифте по вертуальному торговому центру!\n";

    // запрос пользователю на выбор этажа
    skip:
    std::cout << "Введите этаж от нуля до семи и нажмите ввод: ";
    short fname; // обьявление переменной для этажа

    // проверка на корректность ввода
    if (!(std::cin >> fname))
    {
        std::cout << "Вы вели не корректное значение!\n";
        std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
        std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        goto skip;
    }

    // вывод этажа в соответствии с условием
    switch (fname)
    {
    case Floor_Parking:
        std::cout << "Вы находитесь на порковке !\n";
        break;

    case Floor_TradFloor:
        std::cout << "Вы находитесь в торговом зале !\n";
        break;

    case Floor_Cafe:
        std::cout << "Вы находитесь кафе !";
        break;

    case Floor_Bowling:
        std::cout << "Вы находитесь в боулинг клубе !\n";
        break;

    case Floor_CinemaHall:
        std::cout << "Вы находитесь в кино зале!\n";
        break;

    case Floor_Casino:
        std::cout << "Вы находитесь в казино !\n";
        break;

    case Floor_PinHouse:
        std::cout << "Вы находитесь в пин хаусе !\n";
        break;

    case Floor_Helipad:
        std::cout << "Вы находитесь на верталётной площадке !\n";
        break;

    default:
        // вывод в терминал при ошибочном вводе этажа
        std::cout << "Такого этаже здесь нет !\n";

        goto skip;
    }
    // запрос пользователю на выбор действия
    std:: cout << "Хотите продолжить введите 'да', а если хотите покинуть центр введите 'покинуть' и нажмите ввод: \n";
    std::string choice; // переменная для выбора
    std::cin >> choice; // ввод символа с клавиатуры

    // условие для действия по выбору пользователя
    if (choice == "да")
    {
        goto skip;
    }
    else if (choice == "покинуть") exit(0); // выход из праграммы по выбору пользователя
}
