#include<iostream>
#include"type_checking.h"
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
    bool stop = false;
    do
    {
        // вывод в терминал предложения прокатится
        std::cout << "Предлогаем прокатится на вертуальном лифте по вертуальному торговому центру!\n";

        // запрос пользователю на выбор этажа
        std::cout << "Введите этаж от нуля до семи и нажмите ввод: ";
        short fname{}; // обьявление переменной для этажа

        short min {1}; // минимальный этаж
        short max {7}; // максимальный этаж

        // проверка на корректность ввода
        fname = Type_Thecking  (fname, min, max);

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
            break;;
        }
        // запрос пользователю на выбор действия
        std:: cout << "Хотите продолжить введите 'Y, а если хотите покинуть центр введите 'N' и нажмите ввод: \n";

        char choice {};

        // проверка на корректность ввода
        choice = Type_Thecking (choice);

        // условие для действия по выбору пользователя
        if (choice == 'Y' || choice == 'y') stop = false;

        else if (choice == 'N' || choice == 'n') stop = true;
    }
    while( ! stop); // выход из праграммы по выбору пользователя
}

