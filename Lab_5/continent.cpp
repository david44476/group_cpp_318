#include<iostream>
#include<string>
#include<iomanip>
#include "constans.h"

enum Сities {
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
struct s_Continent {
    wstr *contTitle; // название континента
    wstr *contSquare; // плошадь континента
    // вложенная структура страны
    struct s_Countries {
        wstr *coutTitle; // название страны
        wstr *capital; // сталица страны
        wstr *cuntSquare; // плошадь страны
        wstr *coutPopulation; // численость население страны
        // вложенная структура города
        struct s_Сities {
            unsigned short *yearOfFound; // год основания города
            wstr *cityPopulation; // численость население города
        };
    };
} *Continent{nullptr};

// создаём псевдоним для вложенной структуры страны
using  Countries = s_Continent::s_Countries;
Countries *Countri;

// создаём псевдоним для вложенной структуры города
using town = s_Continent::s_Countries::s_Сities;
town *Citi;

// деклорация функциии преобразования символов в верхний регистр
auto Regist(wstr &text) -> wstr;

// деклорация функциии выбора гогода
auto ChoosCity (wstr (&r_Regist)(wstr &), wstr &r_city) -> short;

// деклорация функциии создания структуры
auto Cities (s_Continent &Continent) -> RetConst;

// деклорация функции вывода структуры
auto PrintCities (s_Continent &Continent, const short &r_town) -> void;

// функция по заданию №3
auto Continents () -> void {

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
                  "Использование ссылки на структуру." << std::endl;

    std::wcout << L"Введите название города; на пример \" Москва \" и нажмите ввод: ";
    wstr city; // строковая переменная ввода города
    std::getline(std::wcin, city);
    short town = ChoosCity (Regist, city);
    std::wcout << L"Город " << city << '\n';
    Cities (*Continent);
    std::wcout << L"Город " << city << '\n';
    PrintCities (*Continent, town);
    std::wcout << L"Город " << city << '\n';
}


// функция преобразования символов в верхний регистр
auto Regist (wstr& text) -> wstr {
    short diff_ul{32}; // разница между заглавными и строчными символами алфавита
    short up_a {1071}; // десятичный код символа для проверки условия
    for (auto& i : text) {
        if (i >= up_a) i -= diff_ul;
    }
    return text;
}


// функциия выбора гогода
auto ChoosCity (wstr (&r_Regist)(wstr &), wstr &r_city) -> short {
    short type;
    if (r_Regist(r_city) == L"МОСКВА") type = Cities_Moscow;
    else if (r_Regist(r_city) == L"СОЧИ") type = Cities_Sochi;
    else if (r_Regist(r_city) == L"ТОМСК") type = Cities_Tomsk;
    else if (r_Regist(r_city) == L"СИДНЕЙ") type = Cities_Sydney;
    else if (r_Regist(r_city) == L"ДЖЕЛОНГ") type = Cities_Geelong;
    else if (r_Regist(r_city) == L"КЭРНС") type = Cities_Cairns;
    else if (r_Regist(r_city) == L"ЛОНДОН") type = Cities_London;
    else if (r_Regist(r_city) == L"ЛИДС") type = Cities_Leeds;
    else if (r_Regist(r_city) == L"ЛУТОН") type = Cities_Luton;
    else if (r_Regist(r_city) == L"ЛИМА") type = Cities_Lima;
    else if (r_Regist(r_city) == L"БОГОТА") type = Cities_Bogota;
    else if (r_Regist(r_city) == L"КАЛИ") type = Cities_Kali;

    return type;
}


// функциия создания структуры
auto Cities (s_Continent &Continent) -> RetConst {

    //выделяется память для поля название материка
    Continent.contTitle = {new (std::nothrow) wstr [Cities_Lima]};
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! Continent.contTitle) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    Continent.contTitle[Cities_Kali] = L"Евразия"; // название материка
    Continent.contTitle[Cities_Bogota] = L"Южная Америка"; // названте материка
    Continent.contTitle[Cities_Lima] = L"Австралия"; // названте материка

    //выделяется память для поля площадь материка
    Continent.contSquare = {new (std::nothrow) wstr [Cities_Luton]};
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! Continent.contSquare) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    Continent.contSquare[Cities_Kali] =  L"53.6 млн.км²"; // площадь матирика Евразия в млн.км²
    Continent.contSquare[Cities_Bogota] = L"17.84 млн.км²"; // площадь матирика Южная Америка в млн.км²
    Continent.contSquare[Cities_Lima] = L"8.6 млн.км²"; // площадь матирика Австралии в млн.км²


    //выделяется память для поля название страны
    Countri->coutTitle = {new (std::nothrow) wstr [Cities_Leeds]};
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! Countri->coutTitle) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    Countri->coutTitle[Cities_Kali] = L"Россия"; // инициализация название страны
    Countri->coutTitle[Cities_Bogota] = L"Великобритания"; // инициализация название страны
    Countri->coutTitle[Cities_Lima] = L"Колумбия"; // инициализация название страны
    Countri->coutTitle[Cities_Luton] = L"Австралия"; // инициализация название страны
    Countri->coutTitle[Cities_Leeds] = L"Перу"; // инициализация название страны

    //выделяется память для поля площадь страны
    Countri->cuntSquare = {new (std::nothrow) wstr [Cities_Luton]};
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! Countri->cuntSquare) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    Countri->cuntSquare[Cities_Kali] = L"17.1 млн.км²"; // инициализация площади России в млн.км²
    Countri->cuntSquare[Cities_Bogota] = L"243 610 км²" ; // инициализация площади Великобритании в млн.км²
    Countri->cuntSquare[Cities_Lima] = L"1.142 млн.км²"; // инициализация площади Колумбия в млн.км²
    Countri->cuntSquare[Cities_Luton] = L"1.285 млн.км²"; // инициализация площади Перу в млн.км²

    //выделяется память для поля численость населения страны
    Countri->coutPopulation = {new (std::nothrow) wstr [Cities_Luton]};
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! Countri->coutPopulation ) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    Countri->coutPopulation[Cities_Kali] = L"146 119 928 млн.чел" ; // инициализация числености населения России
    Countri->coutPopulation[Cities_Bogota] = L"57 106 398 млн.чел"; // инициализация числености населения Англии
    Countri->coutPopulation[Cities_Lima] = L"53 474 361 млн.чел"; // инициализация числености населения Колумбии
    Countri->coutPopulation[Cities_Luton] =  L"27 000 498 млн.чел"; // инициализация числености населения Австралии
    Countri->coutPopulation[Cities_Leeds] = L"33 726 000 млн.чел"; // инициализация числености населения Перу

    //выделяется память для поля столица страны
    Countri->capital = {new (std::nothrow) wstr [Cities_Luton]};
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! Countri->capital ) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    Countri->capital[Cities_Kali] = L"Москва"; // инициализация названия столици России
    Countri->capital[Cities_Bogota] = L"Лондон"; // инициализация названия столици Англии
    Countri->capital[Cities_Lima] = L"Богота"; // инициализация названия столици Колумбии
    Countri->capital[Cities_Luton] = L"Сидней"; // инициализация названия столици Австралии
    Countri->capital[Cities_Leeds] = L"Лима"; // инициализация названия столици Перу


    //выделяется память для поля год основания города
    Citi->yearOfFound = {new (std::nothrow) unsigned short [Cities_Totall]};
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! Citi->yearOfFound) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    // инециализация год основания для городов
    Citi->yearOfFound[Cities_Moscow] = 1147;
    Citi->yearOfFound[Cities_Sochi] = 1838;
    Citi->yearOfFound[Cities_Tomsk] = 1604;
    Citi->yearOfFound[Cities_Sydney] = 1788;
    Citi->yearOfFound[Cities_Geelong] = 1838;
    Citi->yearOfFound[Cities_Cairns] = 1876;
    Citi->yearOfFound[Cities_London] = 47;
    Citi->yearOfFound[Cities_Leeds] = 1086;
    Citi->yearOfFound[Cities_Luton] = 1876;
    Citi->yearOfFound[Cities_Lima] = 1535;
    Citi->yearOfFound[Cities_Bogota] = 1538;
    Citi->yearOfFound[Cities_Kali] = 1536;
    //////////////////////////////////////////////////////////////

    //выделяется память для поля населения города
    Citi->cityPopulation = {new (std::nothrow) wstr [Cities_Totall]};
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! Citi->cityPopulation) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    // инециализация числености населения для городов
    Citi->cityPopulation[Cities_Moscow] = L"13 274 285 млн.чел";
    Citi->cityPopulation[Cities_Sochi] = L"445 149 млн.чел";
    Citi->cityPopulation[Cities_Tomsk] = L"544 566 млн.чел";
    Citi->cityPopulation[Cities_Sydney] = L"5 450 496 млн.чел";
    Citi->cityPopulation[Cities_Geelong] = L"180 239 млн.чел";
    Citi->cityPopulation[Cities_Cairns] = L"152 759 млн.чел";
    Citi->cityPopulation[Cities_London] = L"10 100 000 млн.чел";
    Citi->cityPopulation[Cities_Leeds] = L"536 280 тыс.чел";
    Citi->cityPopulation[Cities_Luton] = L"213 052 тыс.чел";
    Citi->cityPopulation[Cities_Lima] = L"9 943 800 млн.чел";
    Citi->cityPopulation[Cities_Bogota] = L"8 034 649 млн.чел";
    Citi->cityPopulation[Cities_Kali] = L"2 471 474 млн.чел";
    ///////////////////////////////////////////////////////////////////////////
    return Ok;
}

// функция вывода структуры
auto PrintCities (s_Continent &Continent, const short &r_town) -> void {
    switch (r_town) {
    case Cities_Moscow: {
        std::wcout << L"Основан в " + Citi->cityPopulation[Cities_Moscow] + L'\n'
                          +  L" Находится на територии материка "
                          + Continent.contTitle[Cities_Kali] + L'\n'
                          +  L"Площадь материка " + Continent.contTitle[Cities_Kali] + L" состовляет:"
                          + Countri->cuntSquare[Cities_Kali] + L'\n'
                          + L"Является столицей страны: " + Countri->coutTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Sochi: {
        std::wcout << L"Находится на територии материка " + Continent.contTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Tomsk: {
        std::wcout << L"Находится на територии материка " + Continent.contTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Sydney: {
        std::wcout << L"Находится на територии материка " + Continent.contTitle[Cities_Lima] << '\n';
        break;
    }
    case Cities_Geelong: {
        std::wcout << L"Находится на територии материка " + Continent.contTitle[Cities_Lima] << '\n';
        break;
    }
    case Cities_Cairns: {
        std::wcout << L"Находится на територии материка " + Continent.contTitle[Cities_Lima] << '\n';
        break;
    }
    case Cities_London: {
        std::wcout << L"Находится на територии материка " + Continent.contTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Leeds: {
        std::wcout << L"Находится на територии материка " + Continent.contTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Luton: {
        std::wcout << L"Находится на територии материка " + Continent.contTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Lima: {
        std::wcout << L"Находится на територии материка " + Continent.contTitle[Cities_Bogota] << '\n';
        break;
    }
    case Cities_Bogota: {
        std::wcout << L"Находится на територии материка " + Continent.contTitle[Cities_Bogota] << '\n';
        break;
    }
    case Cities_Kali: {
        std::wcout << L"Находится на територии материка " + Continent.contTitle[Cities_Bogota] << '\n';
        break;
    }
    default:
        std::wcout <<L"Данная информация отсутствует!!!" << '\n';
        break;
    }

    // освобождаем память для населения города
    if (Citi->cityPopulation) delete [] Citi->cityPopulation; // освобождаем память
    Citi->cityPopulation = nullptr; // обнуляем указатель

    // освобождаем память для год основания
    if (Citi->yearOfFound) delete [] Citi->yearOfFound; // освобождаем память
    Citi->yearOfFound = nullptr; // обнуляем указатель

    // освобождаем память для столици страны
    if (Countri->capital ) delete [] Countri->capital ; // освобождаем память
    Countri->capital  = nullptr; // обнуляем указатель

    // освобождаем память для числености населения страны
    if (Countri->coutPopulation) delete [] Countri->coutPopulation; // освобождаем память
    Countri->coutPopulation = nullptr; // обнуляем указатель

    // освобождаем память для площади страны
    if (Countri->cuntSquare) delete [] Countri->cuntSquare; // освобождаем память
    Countri->cuntSquare = nullptr; // обнуляем указатель

    // освобождаем память для названия страны
    if (Countri->coutTitle) delete [] Countri->coutTitle; // освобождаем память
    Countri->coutTitle = nullptr; // обнуляем указатель

    // освобождаем память для площади материка
    if (Continent.contSquare) delete [] Continent.contSquare; // освобождаем память
    Continent.contSquare = nullptr; // обнуляем указатель

    // освобождаем память для названия материка
    if (Continent.contTitle) delete [] Continent.contTitle; // освобождаем память
    Continent.contTitle = nullptr; // обнуляем указатель
}
