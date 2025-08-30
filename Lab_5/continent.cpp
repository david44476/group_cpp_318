#include<iostream>
#include<string>
#include<iomanip>
#include"constans.h"
#include"stop.h"

enum Сities : short {
    Cities_Kali, // колумбия Дата основания:1536 Население:2 471 474 Площадь:564 км²
    Cities_Bogota, // колумбия Дата основания:1538 Население:8 034 649 Площадь:1 775 км²
    Cities_Lima, // перу Дата основания:1535 Население:9 943 800 Площадь:2 672 км²
    Cities_Luton, // великобритания Дата основания:1876 Население:213 052 Площадь:43,4 км²
    Cities_Leeds, // великобритания Дата основания:1086 Население:536 280 Площадь:111 км²
    Cities_London, // великобритания Дата основания:47 Население:10 100 000 Площадь:1 602
    Cities_Cairns, // австралия Дата основания:1876 год 152 759 население  площадь 254 км²
    Cities_Geelong, // австралия Дата основания:1838 год Население:180 239 Площадь:1 329 км²
    Cities_Sydney, // австралия Дата основания  1788 Население:5 450 496 Площадь:12 144 км²
    Cities_Tomsk, // россия Дата основания:1604 Население:544 566 Площадь:294 км²
    Cities_Sochi, // россия Дата основания:1838 Население:445 149 Площадь:176.77 км²
    Cities_Moscow, // россия Дата основания:1147 Население:13 274 285 Площадь:2 561 км²
    Cities_Totall, // общее количество городов
};

// прототип типа на std::wstring
using wstr = std::wstring;

// структура континент
struct SContinent {
    wstr contTitle; // название континента
    wstr contSquare; // плошадь континента
    // вложенная структура страны
    struct SCountries {
        wstr coutTitle; // название страны
        wstr capital; // сталица страны
        wstr cuntSquare; // плошадь страны
        wstr coutPopulation; // численость население страны
        // вложенная структура города
        struct SСities {
            unsigned short yearOfFound; // год основания города
            wstr cityPopulation; // численость население города
        };
    };
}*Continent{nullptr};

// деклорация функциии преобразования символов в верхний регистр
auto Regist(wstr &r_text) -> wstr;

// деклорация функциии выбора гогода
auto ChoosCity (wstr (&r_Regist)(wstr &), wstr &r_city) -> short;

// деклорация функциии создания структуры
auto Cities () -> RetConst;

// деклорация функции вывода структуры
auto PrintCities (const short& r_town) -> void;

// функция по заданию №3
auto Continents () -> RetConst {

    setlocale(LC_ALL, "ru_RU.UTF8");

    wstr s = L"Задание 3)";
    std::wcout << std::setw(30) << std::right << s << '\n';
    std::wcout << L"Создайте структуру данных материк, страны/государства, столицы, область/регион, города.\n"
                  "То есть пользователь вводит город, в программе выводится область/регион этого города,\n"
                  "столица этого города, государство/страна этого города и материк этого города. Городов\n"
                  "должно быть не менее 10, и некоторые города имеют общие столицы или регионы или\n"
                  "материк, однако имеются которые не имеют общих пересечений. Если города нет в списке,\n"
                  "выдать пользователю «Данная информация отсутствует», и предложить повторить поиск или\n"
                  "выйти по нажатию «q».\n"
                  "В задании при выполнении необходимо применить следующее: создайте объекты структуры\n"
                  "в статической и динамической памяти (определение объектов статически и динамически).\n"
                  "Использование ссылки на структуру.\n" << std::endl;

    bool stop = false; // переменная для цикла do while
    do {
        std::wcout << L"Введите название города; на пример \" Москва \" и нажмите ввод: ";
        wstr city; // строковая переменная ввода города
        std::getline(std::wcin, city);
        short town = ChoosCity (Regist, city);
        std::wcout << L"Город " << city << '\n';
        // функциия создания структуры
        Cities ();
        // функция вывода структуры
        PrintCities (town);
        // вызов функции для останоки или продолжения выполнения программы по выбору пользователя
        if ( ! (stop == Stop())) return ErrData;
    }
    while ( ! stop); // выход из праграммы по выбору пользователя

    return Ok;
}


// функция преобразования символов в верхний регистр
auto Regist (wstr& r_text) -> wstr {
    short diff_ul{32}; // разница между пропесными и строчными символами алфавита
    short up_a {1071}; // десятичный код символа для проверки условия
    for (auto& i : r_text) {
        if (i >= up_a) i -= diff_ul;
    }
    return r_text;
}


// функциия выбора гогода
auto ChoosCity (wstr (&r_Regist)(wstr &), wstr& r_city) -> short {
    short id;
    wstr text {r_Regist(r_city)};
    if (text == L"МОСКВА") id = {Cities_Moscow};
    else if (text == L"СОЧИ") id = {Cities_Sochi};
    else if (text == L"ТОМСК") id = {Cities_Tomsk};
    else if (text == L"СИДНЕЙ") id = {Cities_Sydney};
    else if (text == L"ДЖЕЛОНГ") id = {Cities_Geelong};
    else if (text == L"КЭРНС") id = {Cities_Cairns};
    else if (text == L"ЛОНДОН") id = {Cities_London};
    else if (text == L"ЛИДС") id = {Cities_Leeds};
    else if (text == L"ЛУТОН") id = {Cities_Luton};
    else if (text == L"ЛИМА") id = {Cities_Lima};
    else if (text == L"БОГОТА") id = {Cities_Bogota};
    else if (text == L"КАЛИ") id = {Cities_Kali};
    else id = Cities_Totall;
    return id;
}

// создаём псевдоним для вложенной структуры страны
using  Countries = SContinent::SCountries;
Countries *Countri{nullptr};

// создаём псевдоним для вложенной структуры города
using Town = SContinent::SCountries::SСities;
Town *City{nullptr};

// функциия создания структуры
auto Cities () -> RetConst {

    //выделяется память и инициализируем поля для структуры Continent
    Continent = new (std::nothrow) SContinent[Cities_Luton]
        {{L"Евразия", L"53.6 млн.км²"},
         {L"Австралия", L"8.6 млн.км²"},
         {L"Южная Америка", L"17.84 млн.км²"}};

    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! Continent) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }

    //выделяется память и инициализируем поля для структуры Countri
    Countri = new (std::nothrow) Countries[Cities_London]
        {{L"Россия", L"Москва" , L"17.1 млн.км²", L"146 119 928 млн.чел"},
         {L"Австралия", L"Сидней", L"8.6 млн.км²", L"27 000 498 млн.чел"},
         {L"Великобритания", L"Лондон", L"243 610 км²", L"57 106 398 млн.чел"},
         {L"Колумбия", L"Богота", L"1.142 млн.км²", L"53 474 361 млн.чел"},
         {L"Перу", L"Лима", L"1.285 млн.км²", L"33 726 000 млн.чел"}};
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! Countri) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }

    //выделяется память и инициализируем поля для структуры City
    City = new (std::nothrow) Town[Cities_Totall]
        {{1536, L"2 471 474 млн.чел"}, // город Кали
            {1538, L"8 034 649 млн.чел"}, // город Богота
            {1535, L"9 943 800 млн.чел"}, // город Лима
            {1876, L"213 052 тыс.чел"}, // город Лутон
            {1086, L"536 280 тыс.чел"}, // город Лидс
            {47, L"10 100 000 млн.чел"}, // город Лондон
            {1876, L"152 759 млн.чел"}, // город Кэрнс
            {1838, L"180 239 млн.чел"}, // город Джелонг
            {1788, L"5 450 496 млн.чел"}, // город Сидней
            {1604, L"544 566 млн.чел"}, // город Томск
            {1838, L"445 149 млн.чел"}, // город Сочи
            {1147, L"13 274 285 млн.чел"}, // город Москва
        };

    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! City) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    return Ok;
}

// функция вывода структуры
auto PrintCities (const short& r_town) -> void {

    setlocale(LC_ALL, "ru_RU.UTF8");

    switch (r_town) {
    case Cities_Moscow: {
        std::wcout << L"Основан в " << City[Cities_Moscow].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_Moscow].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Kali].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Kali].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Kali].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Kali].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Kali].contTitle << L" состовляет: "
                   << Continent[Cities_Kali].contSquare << L'\n';

        break;
    }
    case Cities_Sochi: {
        std::wcout << L"Основан в " << City[Cities_Sochi].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_Sochi].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Kali].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Kali].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Kali].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Kali].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Kali].contTitle << L" состовляет: "
                   << Continent[Cities_Kali].contSquare << L'\n';

        break;
    }
    case Cities_Tomsk: {
        std::wcout << L"Основан в " << City[Cities_Tomsk].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_Tomsk].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Kali].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Kali].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Kali].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Kali].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Kali].contTitle << L" состовляет: "
                   << Continent[Cities_Kali].contSquare << L'\n';
        break;
    }
    case Cities_Sydney: {
        std::wcout << L"Основан в " << City[Cities_Sydney].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_Sydney].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Bogota].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Bogota].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Bogota].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Bogota].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Bogota].contTitle << L" состовляет: "
                   << Continent[Cities_Bogota].contSquare << L'\n';
        break;
    }
    case Cities_Geelong: {
        std::wcout << L"Основан в " << City[Cities_Geelong].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_Geelong].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Bogota].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Bogota].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Bogota].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Bogota].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Bogota].contTitle << L" состовляет: "
                   << Continent[Cities_Bogota].contSquare << L'\n';
        break;
    }
    case Cities_Cairns: {
        std::wcout << L"Основан в " << City[Cities_Cairns].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_Cairns].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Bogota].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Bogota].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Bogota].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Bogota].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Bogota].contTitle << L" состовляет: "
                   << Continent[Cities_Bogota].contSquare << L'\n';
        break;
    }
    case Cities_London: {
        std::wcout << L"Основан в " << City[Cities_London].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_London].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Lima].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Lima].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Lima].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Kali].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Kali].contTitle << L" состовляет: "
                   << Continent[Cities_Kali].contSquare << L'\n';
        break;
    }
    case Cities_Leeds: {
        std::wcout << L"Основан в " << City[Cities_Leeds].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_Leeds].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Lima].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Lima].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Lima].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Kali].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Kali].contTitle << L" состовляет: "
                   << Continent[Cities_Kali].contSquare << L'\n';
        break;
    }
    case Cities_Luton: {
        std::wcout << L"Основан в " << City[Cities_Luton].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_Luton].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Lima].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Lima].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Lima].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Kali].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Kali].contTitle << L" состовляет: "
                   << Continent[Cities_Kali].contSquare << L'\n';
        break;
    }
    case Cities_Lima: {
        std::wcout << L"Основан в " << City[Cities_Lima].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_Lima].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Luton].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Luton].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Luton].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Lima].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Lima].contTitle << L" состовляет: "
                   << Continent[Cities_Lima].contSquare << L'\n';
        break;
    }
    case Cities_Bogota: {
        std::wcout << L"Основан в " << City[Cities_Bogota].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_Bogota].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Luton].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Luton].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Luton].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Lima].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Lima].contTitle << L" состовляет: "
                   << Continent[Cities_Lima].contSquare << L'\n';
        break;
    }
    case Cities_Kali: {
        std::wcout << L"Основан в " << City[Cities_Kali].yearOfFound << L" году." << L'\n'
                   << L"Население города состовляет: " << City[Cities_Kali].cityPopulation << L'\n'
                   << L"Находится на територии страны: " << Countri[Cities_Leeds].coutTitle << L'\n'
                   << L"Столицей страны является: " << Countri[Cities_Leeds].capital << L'\n'
                   << L"Площадь страны состовляет: " << Countri[Cities_Leeds].cuntSquare << '\n'
                   << L"Находится на територии материка " << Continent[Cities_Lima].contTitle << L'\n'
                   << L"Площадь материка " << Continent[Cities_Lima].contTitle << L" состовляет: "
                   << Continent[Cities_Lima].contSquare << L'\n';
        break;
    }
    default:
        std::wcout <<L"Данная информация отсутствует!!!" << '\n';
        break;
    }

    // освобождаем память для города
    if (City) delete [] City ; // освобождаем память
    City  = {nullptr}; // обнуляем указатель

    // освобождаем память для страны
    if (Countri) delete [] Countri; // освобождаем память
    Countri = {nullptr}; // обнуляем указатель

    // освобождаем память для материка
    if (Continent) delete [] Continent; // освобождаем память
    Continent = {nullptr}; // обнуляем указатель
}

