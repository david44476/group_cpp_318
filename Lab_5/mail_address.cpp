#include<iostream>
#include<string>
#include<iomanip>
#include"constans.h"
#define MAX_COUNTRY 3
#define MAX_CITY 9
#define MAX_STREET 36
#define null 0

// псевдоним типа
using wstr = std::wstring;

// массив стран
wstr Country[MAX_COUNTRY] {L"с-на. Россия", L"с-на. Англия", L"с-на. Италия"};

// массив городов
wstr City[MAX_CITY] {L"г. Москва", L"г. Томск", L"г. Краснокаменск", // города России
            L"г. Лондон", L"г. Лидс", L"г. Манчестер", // города Англии
            L"г. Рим", L"г. Милан", L"г. Неаполь"}; // города Италии

// массив улиц
wstr Street[MAX_STREET]

    // улицы Москвы
    {L"ул. Абельмановская", L"ул. Авангардная", L"про-т. Балаклавский", L"пер-к. Банковский",

        // улицы Томска
        L"ул. Дальне-Ключевская", L"в-з. Кузнечный", L"пл-дь. Южная", L"ул. Елизаровых",

        // улицы Краснокаменска
        L"мик-н. Солнечный", L"про-т Строителей", L"про-т Шахтёров", L"ул. Энергетиков",

        // улицы Лондона
        L"ул. Бейкер-стрит", L"ул. Пикадилли", L"ул. Олдвич", L"ул. Уайтхолл",

        // улицы Линса
        L"ул. Кабан Лейн", L"ул. Парк-Роу", L"ул. Сити-сквер", L"ул. Ист-Парад",

        // улицы Манчестера
        L"ул. Канал - стрит", L"ул. Рыночная", L"ул. Корпоративная", L"ул. Новая Соборная",

        // улицы Рима
        L"ул. Аргилет", L"ул. Злодейская", L"ул. Этрусская", L"ул. Виа Джулия",

        // улицы Милана
        L"про-т. Беатриче д’Эсте", L"ул. Корсо Венеция", L"ул. Виа Данте", L"ул. Виале Блиньи",

        // улицы Неаполя
        L"ул. Виа Толедо", L"ул. Виа Дуомо", L"ул. СпаккаНаполи", L"про-т. Корсо Умберто I"
    };

// структура адреса
struct Address {
    wstr S_Country; //страна
    wstr S_City; // город
    wstr S_Street; // улица
    wstr S_House; // дом
    wstr S_Flat; // квартира
} *address{nullptr};

// функция выделения из строки компонентов адреса
auto Parse (wstr& line, Address *address) -> void {
    if (line.empty ()) {
        std::wcout << L"exception\n";
    }

    const wstr sepor{','};
    size_t start{line.find_first_not_of(sepor)}; // начальный индекс первого слова

    // Извлекаем S_Country
    auto stop = line.find_first_of(sepor, start + 1);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_Country = line.substr (start, stop);
    std::wcout << address->S_Country << '\n';
    // извлекаем строку из массива стран для сравнения
    for (size_t j{0}; j < std::size(Country); ++j) {
        if (address->S_Country.compare(Country[j]) == null)
            std::wcout << L"Данной страны нет в базе!\n";
        //return;
    }
    start = stop + 1;

    // Извлекаем S_City
    stop = line.find_first_of (sepor, start + 1);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_City = line.substr (start, stop - start);
    std::wcout << address->S_City << '\n';
    // извлекаем строку из массива городов для сравнения
    for (size_t j{0}; j < std::size(City); ++j) {
        if (address->S_City.compare(City[j]) == null)
            std::wcout << L"Данного города нет в базе!\n";
        //return;
    }
    start = stop + 1;

    // Извлекаем S_Street
    stop = line.find_first_of (sepor, start + 1);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_Street = line.substr(start, stop - start);
    std::wcout << address->S_Street << '\n';
    // извлекаем строку из массива улиц для сравнения
    for (size_t j{0}; j < std::size(Street); ++j) {
        if (address->S_Street.compare(Street[j]) == null)
            std::wcout << L"Данного города нет в базе!\n";
        //return;
    }
    start = stop + 1;

    // Извлекаем S_House
    stop = line.find_first_of (sepor, start + 1);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_House = line.substr (start, stop - start);
    std::wcout << address->S_House << '\n';
    start = stop + 1;

    // Извлекаем S_Flat
    address->S_Flat = line.substr(start);
    std::wcout << address->S_Flat << '\n';
}

// функция приводит компоненты адреса к каноническому виду
auto Unify (Address *address) -> void {
    if (address == nullptr) {
        std::wcout << L"exception\n";
    }

    // Обработка S_Country
    auto pos = address->S_Country.find (L"с-на.", 0);
    if (pos != std::string::npos) {
        address->S_Country.replace (pos, 5, L"страна");
    }
    
    // Удаление пробелов по краям
    address->S_Country.erase (0, address->S_Country.find_first_not_of (' '));
    address->S_Country.erase (address->S_Country.find_last_not_of (' ') + 1);

    // Обработка S_City
    pos = address->S_City.find (L"г.", 0);
    if (pos != std::string::npos) {
        address->S_City.replace (pos, 2, L"город");
    }
    
    // Удаление пробелов по краям
    address->S_City.erase (0, address->S_City.find_first_not_of (' '));
    address->S_City.erase (address->S_City.find_last_not_of (' ') + 1);

    // Обработка S_Street
    pos = address->S_Street.find(L"ул.", 0);
    if (pos != std::string::npos) {
        address->S_Street.replace (pos, 3, L"улица");
    }

    pos = address->S_Street.find (L"пр-д.", 0);
    if (pos != std::string::npos) {
        address->S_Street.replace (pos, 5, L"проезд");
    }

    pos = address->S_Street.find (L"мик-н.", 0);
    if (pos != std::string::npos) {
        address->S_Street.replace (pos, 6, L"микрорайон");
    }

    pos = address->S_Street.find (L"пер-к.", 0);
    if (pos != std::string::npos) {
        address->S_Street.replace (pos, 6, L"переулок");
    }

    pos = address->S_Street.find (L"пл-дь.", 0);
    if (pos != std::string::npos) {
        address->S_Street.replace (pos, 6, L"площадь");
    }

    pos = address->S_Street.find (L"в-з.", 0);
    if (pos != std::string::npos) {
        address->S_Street.replace (pos, 4, L"площадь");
    }
    
    // Удаление пробелов по краям
    address->S_Street.erase (0, address->S_Street.find_first_not_of (' '));
    address->S_Street.erase (address->S_Street.find_last_not_of (' ') + 1);

    // Обработка S_House
    pos = address->S_House.find (L"д.", 0);
    if (pos != std::string::npos) {
        address->S_House.replace (pos, 2, L"дом");
    }
    
    // Удаление пробелов по краям
    address->S_House.erase (0, address->S_House.find_first_not_of (' '));
    address->S_House.erase (address->S_House.find_last_not_of (' ') + 1);

    // Обработка S_Flat
    pos = address->S_Flat.find (L"кв.", 0);
    if (pos != std::string::npos) {
        address->S_Flat.replace (pos, 3, L"квартира");
    }
    
    // Удаление пробелов по краям
    address->S_Flat.erase (0, address->S_Flat.find_first_not_of (' '));
    address->S_Flat.erase (address->S_Flat.find_last_not_of (' ') + 1);

}

// функция вывода структуры
auto Format (const Address& address) -> wstr {
    return address.S_Country + L", " + address.S_City + L", " +
           address.S_Street + L", " + address.S_House + L", " + address.S_Flat + L'\n';
}

// функция вывода базы знаний
auto PrintArray (const wstr *fp_Array, const short& fr_size, const wchar_t* p_str) -> void {
    std::wcout << p_str << '\n';
    const unsigned dev{3}; // переменная для деления
    unsigned short count{1}; // переменная счётчик
    for (size_t i{0}; i < fr_size; ++i) {
        std::wcout << fp_Array[i] << ", ";
        if (count%dev == 0) std::wcout << '\n';
        ++count;
    }
    std::cout << std::endl;
}

// функция по заданию №8
auto MailAddress () -> RetConst {

    setlocale (LC_ALL, "ru_RU.UTF-8");

    wstr s = L"Задание 8)";
    std::wcout << std::setw (30) << std::right << s << '\n';
    std::wcout << L"Разработать программу, обрабатывающую почтовые адреса." << '\n';

    std::wcout << L"Введите почтовый адрес в формате: " << '\n'
               << L"с-на. Англия, г. Сочи, мик-н. Солнечный, д. 444, кв. 76." << '\n';

    //выделяется память под поля для структуры address
    address = new (std::nothrow) Address;

    PrintArray (Country, MAX_COUNTRY, L"База стран: "); // вывод базы стран
    PrintArray (City, MAX_CITY, L"База городов: "); // вывод базы городов
    PrintArray (Street, MAX_STREET, L"База улиц: "); // вывод базы улиц

    wstr line; // переменная для ввода строки
    while (std::getline(std::wcin, line)) {

        Parse (line, address);
        Unify (address);
        std::wcout << Format (*address) << "\n";
    }

    if (address) delete address ; // освобождаем память
    address  = {nullptr}; // обнуляем указатель
    return Ok;
}
