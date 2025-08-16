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

// структура города
struct s_Сities {
    wstr *cityTitle; // название города
    unsigned short *yearOfFound; // год основания города
    float *cityPopulation; // численость население города
} Сities{nullptr};

// структура страны
struct s_Countries {
    wstr *coutTitle; // название страны
    wstr *capital; // сталица страны
    float *cuntSquare; // плошадь страны
    float *coutPopulation; // численость население страны
    s_Сities Сiti; // вложенная сруктура город
} *Countries{nullptr};

// структура континент
struct s_Continent {
    wstr *contTitle; // название континента
    float *contSquare; // плошадь континента
    s_Countries s_Countri; // вложенная структура страна
} *Continent{nullptr};


// деклорация функциии преобразования символов в верхний регистр
auto Regist(wstr &text) -> wstr;

// деклорация функциии выбора гогода
auto ChoosCity (wstr (&r_Regist)(wstr &), wstr &r_city) -> short;

// деклорация функциии вывода структуры в консоль
auto RrintContinent (s_Continent *p_Continent, const short &r_town) ->  RetConst;


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
    RrintContinent (Continent, town);
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


// функциия вывода структуры Continent в консоль
auto RrintContinent (s_Continent *p_Continent, const short &r_town) -> RetConst {

    //выделяется память для структуры материк
    p_Continent = new (std::nothrow) s_Continent;
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! p_Continent) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }

    //выделяется память для поля название материка
    p_Continent->contTitle = new (std::nothrow) wstr [Cities_Luton];
    if ( ! p_Continent->contTitle) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    p_Continent->contTitle[Cities_Kali] = L"Евразия"; // название материка
    p_Continent->contTitle[Cities_Bogota] = L"Южная Америка"; // названте материка
    p_Continent->contTitle[Cities_Lima] = L"Австралия"; // названте материка

    //выделяется память для поля площадь материка
    p_Continent->contSquare = new (std::nothrow) float [Cities_Luton];
    if ( ! p_Continent->contSquare) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    p_Continent->contSquare[Cities_Kali] =  53.6f; // площадь матирика Евразия в млн.км²
    p_Continent->contSquare[Cities_Bogota] = 17.84f; // площадь матирика Южная Америка в млн.км²
    p_Continent->contSquare[Cities_Lima] = 8.6f; // площадь матирика Австралии в млн.км²

    //выделяется память для поля название страны
    p_Continent->s_Countri.coutTitle = new (std::nothrow) wstr [Cities_Luton];
    if ( ! p_Continent->s_Countri.coutTitle) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    p_Continent->s_Countri.coutTitle[Cities_Kali] = L"Россия"; // инициализация название страны
    p_Continent->s_Countri.coutTitle[Cities_Bogota] = L"Великобритания"; // инициализация название страны
    p_Continent->s_Countri.coutTitle[Cities_Lima] = L"Колумбия"; // инициализация название страны
    p_Continent->s_Countri.coutTitle[Cities_Luton] = L"Австралия"; // инициализация название страны
    p_Continent->s_Countri.coutTitle[Cities_Leeds] = L"Перу"; // инициализация название страны

    //выделяется память для поля площадь страны
    p_Continent->s_Countri.cuntSquare = new (std::nothrow) float [Cities_Luton];
    if ( ! p_Continent->s_Countri.cuntSquare[Cities_Luton]) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    p_Continent->s_Countri.cuntSquare[Cities_Kali] = 2561; // инициализация площади России
    p_Continent->s_Countri.cuntSquare[Cities_Bogota] = 1602; // инициализация площади Великобритании
    p_Continent->s_Countri.cuntSquare[Cities_Lima] = 1775; // инициализация площади Колумбия
    p_Continent->s_Countri.cuntSquare[Cities_Luton] = 2672; // инициализация площади Перу

    //выделяется память для поля численость населения страны
    p_Continent->s_Countri.coutPopulation = new (std::nothrow) float [Cities_Luton];
    if ( ! p_Continent->s_Countri.coutPopulation) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    p_Continent->s_Countri.coutPopulation[Cities_Kali] = 146.119928f ; // инициализация числености населения России
    p_Continent->s_Countri.coutPopulation[Cities_Bogota] = 57.106398f; // инициализация числености населения Англии
    p_Continent->s_Countri.coutPopulation[Cities_Lima] = 53.474361f; // инициализация числености населения Колумбии
    p_Continent->s_Countri.coutPopulation[Cities_Luton] =  27.000498f; // инициализация числености населения Австралии
    p_Continent->s_Countri.coutPopulation[Cities_Leeds] = 33.726000f; // инициализация числености населения Перу

    //выделяется память для поля сталица страны
    p_Continent->s_Countri.capital = new (std::nothrow) wstr [Cities_Luton];
    if ( ! p_Continent->s_Countri.capital) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    p_Continent->s_Countri.capital[Cities_Kali] = L"Москва"; // инициализация названия столици России
    p_Continent->s_Countri.capital[Cities_Bogota] = L"Лондон"; // инициализация названия столици Англии
    p_Continent->s_Countri.capital[Cities_Lima] = L"Богота"; // инициализация названия столици Колумбии
    p_Continent->s_Countri.capital[Cities_Luton] = L"Сидней"; // инициализация названия столици Австралии
    p_Continent->s_Countri.capital[Cities_Leeds] = L"Лима"; // инициализация названия столици Перу

    switch (r_town) {
    case Cities_Moscow: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Sochi: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Tomsk: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Sydney: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Lima] << '\n';
        break;
    }
    case Cities_Geelong: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Lima] << '\n';
        break;
    }
    case Cities_Cairns: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Lima] << '\n';
        break;
    }
    case Cities_London: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Leeds: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Luton: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Kali] << '\n';
        break;
    }
    case Cities_Lima: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Bogota] << '\n';
        break;
    }
    case Cities_Bogota: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Bogota] << '\n';
        break;
    }
    case Cities_Kali: {
        std::wcout << L"Находится на територии материка " + Continent->contTitle[Cities_Bogota] << '\n';
        break;
    }
    default:
        std::wcout <<L"Данная информация отсутствует!!!" << '\n';
        break;
    }

    // освобождаем память для столици страны
    if (p_Continent->s_Countri.capital) delete [] p_Continent->s_Countri.capital; // освобождаем память
    p_Continent->s_Countri.capital = nullptr; // обнуляем указатель

    // освобождаем память для числености населения страны
    if (p_Continent->s_Countri.coutPopulation) delete [] p_Continent->s_Countri.coutPopulation; // освобождаем память
    p_Continent->s_Countri.coutPopulation = nullptr; // обнуляем указатель

    // освобождаем память для площади страны
    if (p_Continent->s_Countri.cuntSquare) delete [] p_Continent->s_Countri.cuntSquare; // освобождаем память
    p_Continent->s_Countri.cuntSquare = nullptr; // обнуляем указатель

    // освобождаем память для названия страны
    if (p_Continent->s_Countri.coutTitle) delete [] p_Continent->s_Countri.coutTitle; // освобождаем память
    p_Continent->s_Countri.coutTitle = nullptr; // обнуляем указатель

    // освобождаем память для площади материка
    if (p_Continent->contSquare) delete [] p_Continent->contSquare; // освобождаем память
    p_Continent->contSquare = nullptr; // обнуляем указатель

    // освобождаем память для названия материка
    if (p_Continent->contTitle) delete [] p_Continent->contTitle; // освобождаем память
    p_Continent->contTitle = nullptr; // обнуляем указатель

    // освобождаем память для структуры материк
    if (p_Continent) delete p_Continent; // освобождаем память
    p_Continent = nullptr; // обнуляем указатель

    return Ok;
}
