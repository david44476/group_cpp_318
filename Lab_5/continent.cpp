#include "constans.h"
#include<iostream>
#include<string>
#include<iomanip>

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
    wstr *title; // название города
    wstr *district; // район города
    unsigned short *yearOfFound; // год основания города
    float *square; // площадь города
    float *population; // население города
};

// структура страны
struct s_Countries {
    wstr *title; // название страны
    wstr *capital; // сталица страны
    wstr *area; // область страны
    float *square; // плошадь страны
    float *population; // население страны
    s_Сities Сiti; // вложенная сруктура город
};

// структура континент
struct s_Continent {
    wstr *title; // название континента
    float *square; // плошадь континента
    s_Countries s_Countri; // вложенная структура страна
} *Continent{nullptr};

// деклорация функциии преобразования символов в верхний регистр
auto Regist(wstr &text) -> wstr;

// деклорация функциии выбора гогода
auto ChoosCity ( s_Continent *p_Continent, const wstr &r_text) -> short;

// деклорация функциии инициализации экземляров структуры
auto CreatOfCont (s_Continent *p_Continent) -> RetConst;

// деклорация функциии вывода структуры в консоль
auto RrintContinent (s_Continent *p_Continent, const short &type) -> void;


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
    city = Regist(city);
    std::wcout << L"Город " << city << '\n';
    short type = ChoosCity (Continent, city);
    std::wcout << L"Город " << city << '\n';
    CreatOfCont (Continent);
    std::wcout << L"Город " << city << '\n';
    RrintContinent (Continent, type);
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
auto ChoosCity ( s_Continent *p_Continent, const wstr &r_text) -> short {
    short type;
    if (r_text == L"МОСКВА") type = Cities_Moscow;
    else if (r_text == L"СОЧИ") type = Cities_Sochi;
    else if (r_text == L"ТОМСК") type = Cities_Tomsk;
    else if (r_text == L"СИДНЕЙ") type = Cities_Sydney;
    else if (r_text == L"ДЖЕЛОНГ") type = Cities_Geelong;
    else if (r_text == L"КЭРНС") type = Cities_Cairns;
    else if (r_text == L"ЛОНДОН") type = Cities_London;
    else if (r_text == L"ЛИДС") type = Cities_Leeds;
    else if (r_text == L"ЛУТОН") type = Cities_Luton;
    else if (r_text == L"ЛИМА") type = Cities_Lima;
    else if (r_text == L"БОГОТА") type = Cities_Bogota;
    else if (r_text == L"КАЛИ") type = Cities_Kali;

    return type;
}

// функциия инициализации экземляров структуры
auto CreatOfCont (s_Continent *p_Continent) -> RetConst {
    //выделяется память для структуры
    p_Continent = new (std::nothrow) s_Continent;
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if ( ! p_Continent) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }

    // if (p_Continent) delete p_Continent; // освобождаем память
    // p_Continent = nullptr; // обнуляем указатель

    //выделяется память для поля *title структуры Continent
    p_Continent->title = new (std::nothrow) wstr [Cities_Lima];
    if ( ! p_Continent->title) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    p_Continent->title[0] = L"Евразия"; // название материка
    p_Continent->title[1] = L"Южная Америка"; // названте материка

    // if (p_Continent->title) delete [] p_Continent->title; // освобождаем память
    // p_Continent->title = nullptr; // обнуляем указатель

    //выделяется память для поля *square структуры Continent
    p_Continent->square = new (std::nothrow) float [Cities_Lima];
    if ( ! p_Continent->square) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }
    p_Continent->square[0] =  53.6f; // площадь матирика Евразия в млн.км²
    p_Continent->square[1] = 17.84f; // площадь матирика Южная Америка в млн.км²

    // if (p_Continent->square) delete [] p_Continent->square; // освобождаем память
    // p_Continent->square = nullptr; // обнуляем указатель

    return Ok;
}

// функциия вывода структуры в консоль
auto RrintContinent (s_Continent *p_Continent, const short &type) -> void {

    switch (type) {
    case Cities_Moscow: {
        std::wcout << L"Находится на територии материка " + p_Continent->title[0] << '\n';
        break;
    }
    case Cities_Sochi: {
        break;
    }
    case Cities_Tomsk: {
        break;
    }
    case Cities_Sydney: {
        break;
    }
    case Cities_Geelong: {
        break;
    }
    case Cities_Cairns: {
        break;
    }
    case Cities_London: {
        break;
    }
    case Cities_Leeds: {
        break;
    }
    case Cities_Luton: {
        break;
    }
    case Cities_Lima: {
        break;
    }
    case Cities_Bogota: {
        break;
    }
    case Cities_Kali: {
        break;
    }
    default:
        std::wcout <<L"Данная информация отсутствует!!!" << '\n';
        break;
    }

    if (p_Continent->title) delete [] p_Continent->title; // освобождаем память
    p_Continent->title = nullptr; // обнуляем указатель

    if (p_Continent->square) delete [] p_Continent->square; // освобождаем память
    p_Continent->square = nullptr; // обнуляем указатель

    if (p_Continent) delete p_Continent; // освобождаем память
    p_Continent = nullptr; // обнуляем указатель

}
