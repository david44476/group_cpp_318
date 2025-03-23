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

auto Elevator (short fname) -> short // функция лифт
{
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

        // вывод в терминал выбора этажа
        std::cout << "Выберите этаж !: ";
        std::cin >> fname; // ввод с клавиатуры номера этажа
        Elevator (fname); // вызов функци лифт
    }
    std:: cout << "Хотите продолжить введите 'y', а если хотите покинть центр введите 'p' и нажмите ввод: \n";
    char choice;
    std::cin >> choice;
    if (choice == 'y')
    {
        std::cout << "Выберите этаж !: ";
        std::cin >> fname;
        Elevator (fname);
    }
    else if (choice == 'p') exit(0);


    return 0;
}
