#include<iostream>
#include<string>
#include<iomanip>
#include"constans.h"

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

// структура города
struct s_Сities {
    std::string title; // название города
    std::string district; // район города
    unsigned short yearOfFound; // год основания города
    float square; // площадь города
    float population; // население города
};

// структура страны
struct s_Countries {
    std::string title; // название страны
    std::string capital; // сталица страны
    std::string area; // область страны
    float square; // плошадь страны
    float population; // население страны
    s_Сities Сiti; // вложенная сруктура город
};

// структура континент
struct s_Continent {
    std::string title; // название континента
    float square; // плошадь континента
    s_Countries s_Countri; // вложенная структура страна
} *Continent{nullptr}, *Countri{nullptr}, *Сiti{nullptr};

using wstr = std::wstring;

auto ChoosCity (const wstr&) -> Сities;

auto Regist(wstr &text) -> wstr;

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
                  "Использование ссылки на структуру." << std::endl;

    std::wcout << L"Введите название города; на пример \" Москва \" и нажмите ввод: ";
    wstr city; // строковая переменная ввода города
    std::getline(std::wcin, city);
    city = Regist(city);
    short choice = static_cast<short>(ChoosCity (city));


    // // создаём экземпляр структуры в динамической памяти
    // Continent = {new (std::nothrow) s_Continent};
    // // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    // if ( ! Continent) {
    //     // Обработка этого случая
    //     std::wcout << L"память не выделенна!!!";
    //     return ErrMemory;
    // }
    // if (Continent) delete Continent; // освобождаем память
    // Continent = nullptr; // обнуляем указатель
    return Ok;
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

auto ChoosCity(const wstr &text) -> Сities {
    if (text == L"МОСКВА")return Cities_Moscow;
    else if (text == L"СОЧИ") return Cities_Sochi;
    else if (text == L"ТОМСК") return Cities_Tomsk;
    else if (text == L"СИДНЕЙ") return Cities_Sydney;
    else if (text == L"ГЕЛОНГ") return Cities_Geelong;
    else if (text == L"КЭРНС") return Cities_Cairns;
    else if (text == L"ЛОНДОН") return Cities_London;
    else if (text == L"ЛИДС") return Cities_Leeds;
    else if (text == L"ЛУТОН") return Cities_Luton;
    else if (text== L"ЛИМА") return Cities_Lima;
    else if (text == L"БОГОТА") return Cities_Bogota;
    else if (text == L"КАЛИ") return Cities_Kali;
    else std::wcout << L"Данная информация отсутствует!" << '\n';
}
