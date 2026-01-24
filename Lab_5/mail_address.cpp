#include<iostream>
#include<string>
#include<iomanip>
#include"constans.h"
#include"stop.h"
#define MAX_COUNTRY 3
#define MAX_CITY 9
#define MAX_STREET 36

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

// функция проверки наличия элемента в массиве
bool Contains(const wstr* arr, size_t size, const wstr& value) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == value) return true;
    }
    return false;
}

// вспомогательная функция: удаление пробелов по краям
wstr Trim(const wstr& str) {
    size_t start = str.find_first_not_of(L' ');
    size_t end = str.find_last_not_of(L' ');

    if (start == wstr::npos) return L"";
    return str.substr(start, end - start + 1);
}

// функция выделения из строки компонентов адреса
auto Parse (wstr& line, Address *address) -> bool {
    if (line.empty ()) {
        std::wcout << L"exception\n";
    }

    const wstr sepor{','};
    size_t start = line.find_first_not_of (sepor);

    if (start == wstr::npos) {
        std::wcout << L"Ошибка: не найдено данных\n";
        return false;
    }

    // Извлекаем S_Country
    size_t stop = line.find (sepor, start);
    if (stop == wstr::npos) stop = line.length();

    address->S_Country = line.substr (start, stop - start);
    address->S_Country = Trim (address->S_Country);  // удаление пробелов

    if (!Contains (Country, MAX_COUNTRY, address->S_Country)) {
        std::wcout << L"Ошибка: страны нет в базе\n";
        return false;
    }
    start = stop + 1;

    // Извлекаем S_City
    stop = line.find (sepor, start);
    if (stop == wstr::npos) stop = line.length();

    address->S_City = line.substr (start, stop - start);
    address->S_City = Trim (address->S_City);  // удаление пробелов

    if (!Contains (City, MAX_CITY, address->S_City)) {
        std::wcout << L"Ошибка: города нет в базе\n";
        return false;
    }
    start = stop + 1;

    // Извлекаем S_Street
    stop = line.find (sepor, start);
    if (stop == wstr::npos) stop = line.length();

    address->S_Street = line.substr (start, stop - start);
    address->S_Street = Trim (address->S_Street);  // удаление пробелов

    if (!Contains (Street, MAX_STREET, address->S_Street)) {
        std::wcout << L"Ошибка: улицы нет в базе\n";
        return false;
    }
    start = stop + 1;

    // Извлекаем S_House
    stop = line.find (sepor, start);
    if (stop == wstr::npos) stop = line.length();

    address->S_House = line.substr (start, stop - start);
    address->S_House = Trim (address->S_House);  // удаление пробелов
    start = stop + 1;

    // Извлекаем S_Flat
    stop = line.find (sepor, start);
    if (stop == wstr::npos) stop = line.length();

    address->S_Flat = line.substr (start, stop - start);
    address->S_Flat = Trim (address->S_Flat);  // удаление пробелов

    return true;
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

    // Обработка S_City
    pos = address->S_City.find (L"г.", 0);
    if (pos != std::string::npos) {
        address->S_City.replace (pos, 2, L"город");
    }

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

    // Обработка S_House
    pos = address->S_House.find (L"д.", 0);
    if (pos != std::string::npos) {
        address->S_House.replace (pos, 2, L"дом");
    }

    // Обработка S_Flat
    pos = address->S_Flat.find (L"кв.", 0);
    if (pos != std::string::npos) {
        address->S_Flat.replace (pos, 3, L"квартира");
    }
}

// функция вывода структуры
auto Format (const Address& address) -> wstr {
    return address.S_Country + L", " + address.S_City + L", " +
           address.S_Street + L", " + address.S_House + L", " + address.S_Flat + L'\n';
}

// функция вывода базы знаний
auto PrintArray (const wstr *fp_Array, const short& fr_size, const wchar_t* p_str) -> void {
    std::wcout << std::setw (30) << std::right << p_str << '\n';
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
               << L"с-на. Россия, г. Краснокаменск, мик-н. Солнечный, д. 444, кв. 76.\n" << '\v';
    wstr line; // переменная для ввода строки

    PrintArray (Country, MAX_COUNTRY, L"База стран: "); // вывод базы стран
    PrintArray (City, MAX_CITY, L"База городов: "); // вывод базы городов
    PrintArray (Street, MAX_STREET, L"База улиц: "); // вывод базы улиц

    bool stop {false}; // переменная для цикла do while
    do {

        //выделяется память под поля для структуры address
        address = new (std::nothrow) Address;

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!address) {

            // Обработка этого случая
            std::wcout << L"Память не выделенна!!!";
            return ErrMemory;
        }
        while (std::getline (std::wcin, line)) {
            if (!Parse (line, address)) {
                break;
            }
            Unify (address);
            std::wcout << Format (*address) << L"\n";
            break;
        }

        if (address) delete address ; // освобождаем память
        address  = {nullptr}; // обнуляем указатель

        // вызов функции для останоки или продолжения выполнения программы по выбору пользователя
        if (!(stop == Stop ())) return ErrData;

    } while (!stop); // выход из праграммы по выбору пользователя
    return Ok;
}
