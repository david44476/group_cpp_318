#include<iostream>
#include<string>
#include<iomanip>
#include"constans.h"
#include"stop.h"
#define MAX_COUNTRY 3
#define MAX_CITY 9
#define MAX_STREET 36

// пространство имён для функций вывода ошибок
namespace errmess {
auto Exeption (const std::wstring &str) {
    std::wcout << L"Ошибка: " << str << '\n';
}

auto Warning (const std::wstring &str) {
    std::wcout << L"Предупреждение: " << str << '\n';
}

auto Info (const std::wstring &str) {
    std::wcout << L"Информация: " << str << '\n';
}
}// errmess

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

// деклорация функций
auto Contains (wstr *f_arr, const size_t &f_size,wstr &f_value, wstr (*) (wstr)) -> bool;
auto Trim (const wstr &f_str) -> wstr;
auto DelStr (wstr f_str) -> wstr;

// указатель на функцию Contains
using PtrContains = bool (*) (wstr*, const size_t&, wstr&, wstr (*) (wstr));
const PtrContains P_Contains {Contains};

// указатель на функцию Trim
using PtrTrim = wstr (*) (const wstr&);
const PtrTrim P_Trim {Trim};

// указатель на функцию DelStr
using PtrDlStr = wstr (*) (wstr);
const PtrDlStr P_DelStr {DelStr};

// функция проверки наличия элемента в массиве
auto Contains ( wstr *f_arr, const size_t &f_size, wstr &f_value, wstr (*) (wstr)) -> bool {
    for (size_t i = 0; i < f_size; ++i) {
        if (P_DelStr (f_arr[i]) == P_DelStr (f_value)) return true;
    }
    return false;
}

// вспомогательная функция: удаление пробелов по краям
auto Trim (const wstr &f_str) -> wstr {
    size_t start = f_str.find_first_not_of(L' ');
    size_t end = f_str.find_last_not_of(L' ');

    if (start == wstr::npos) return L"";
    return f_str.substr(start, end - start + 1);
}

// функция удаления подстроки
auto DelStr (wstr f_str) -> wstr {
    const wstr sepor{'.'}; // переменная для поиска индексов
    size_t start = f_str.find_first_not_of (sepor); // находим начальный индекс слова
    auto stop = f_str.find (sepor, start); // находим конечный индекс слова
    f_str.erase (0, stop + 1); // удаляем подстроку
    return f_str;
}

// функция выделения из строки компонентов адреса
auto Parse (wstr &f_line, Address *f_address) -> RetConst {
    if (f_line.empty ()) {
        errmess::Warning (L"пустая строка!");
    }

    const wstr sepor{','}; // переменная для поиска индексов
    auto start = f_line.find_first_not_of (sepor); // находим начальный индекс слова

    if (start == wstr::npos) {
        errmess::Exeption (L"не найдено запятой!");
        return ErrData;
    }

    //wstr str; // переменная для проверки с базой

    // Извлекаем S_Country
    auto stop = f_line.find (sepor, start); // находим конечный индекс слова
    if (stop == wstr::npos) stop = f_line.length();

    f_address->S_Country = f_line.substr (start, stop - start); // извлекаем из строки страну
    //str = P_DelStr (f_address->S_Country); // удаляем не нужную подстроку
    f_address->S_Country = P_Trim (f_address->S_Country); // удаление пробелов

    // проверяем на соответствие с базой
    if (!P_Contains (Country, MAX_COUNTRY, f_address->S_Country, DelStr)) {
        errmess::Exeption (L"страны нет в базе!");
        return ErrData;
    }
    start = stop + 1;

    // Извлекаем S_City
    stop = f_line.find (sepor, start); // находим конечный индекс слова
    if (stop == wstr::npos) stop = f_line.length();

    f_address->S_City = f_line.substr (start, stop - start); // извлекаем из строки город
    //str = P_DelStr (f_address->S_City); // удаляем не нужную подстроку
    f_address->S_City = P_Trim (f_address->S_City);  // удаление пробелов

    if (!P_Contains (City, MAX_CITY, f_address->S_City, DelStr)) {
        errmess::Exeption (L"города нет в базе!");
        return ErrData;
    }
    start = stop + 1;

    // Извлекаем S_Street
    stop = f_line.find (sepor, start); // находим конечный индекс слова
    if (stop == wstr::npos) stop = f_line.length();

    f_address->S_Street = f_line.substr (start, stop - start); // извлекаем из строки город
    //str = P_DelStr (f_address->S_Street); // удаляем не нужную подстроку
    f_address->S_Street = P_Trim (f_address->S_Street);  // удаление пробелов

    if (!P_Contains (Street, MAX_STREET, f_address->S_Street, DelStr)) {
        errmess::Exeption (L"улицы нет в базе!");
        return ErrData;
    }
    start = stop + 1;

    // Извлекаем S_House
    stop = f_line.find (sepor, start); // находим конечный индекс слова
    if (stop == wstr::npos) stop = f_line.length();

    f_address->S_House = f_line.substr (start, stop - start); // извлекаем из строки дом
    f_address->S_House = P_Trim (f_address->S_House);  // удаление пробелов
    start = stop + 1;

    // Извлекаем S_Flat
    stop = f_line.find (sepor, start); // находим конечный индекс слова
    if (stop == wstr::npos) stop = f_line.length();

    f_address->S_Flat = f_line.substr (start, stop - start); // извлекаем из строки квартиру
    f_address->S_Flat = P_Trim (f_address->S_Flat);  // удаление пробелов

    return Ok;
}

// функция приводит компоненты адреса к каноническому виду
auto Unify (Address *f_address) -> void {
    if (f_address == nullptr) {
        errmess::Warning (L"пустая строка!");
    }

    // Обработка S_Country
    auto pos = f_address->S_Country.find (L"с-на.", 0); // находим начальный индекс заменяемой подстроки страны
    if (pos != std::string::npos) {
        f_address->S_Country.replace (pos, 5, L"страна"); // заменяем подстроку
    }

    // Обработка S_City
    pos = f_address->S_City.find (L"г.", 0); // находим начальный индекс заменяемой подстроки города
    if (pos != std::string::npos) {
        f_address->S_City.replace (pos, 2, L"город"); // заменяем подстроку
    }

    // Обработка S_Street
    pos = f_address->S_Street.find(L"ул.", 0); // находим начальный индекс заменяемой подстроки улицы
    if (pos != std::string::npos) {
        f_address->S_Street.replace (pos, 3, L"улица"); // заменяем подстроку
    }

    pos = f_address->S_Street.find (L"пр-д.", 0); // находим начальный индекс заменяемой подстроки проезда
    if (pos != std::string::npos) {
        f_address->S_Street.replace (pos, 5, L"проезд"); // заменяем подстроку
    }

    pos = f_address->S_Street.find (L"мик-н.", 0); // находим начальный индекс заменяемой подстроки микрорайона
    if (pos != std::string::npos) {
        f_address->S_Street.replace (pos, 6, L"микрорайон"); // заменяем подстроку
    }

    pos = f_address->S_Street.find (L"пер-к.", 0); // находим начальный индекс заменяемой подстроки переулка
    if (pos != std::string::npos) {
        f_address->S_Street.replace (pos, 6, L"переулок"); // заменяем подстроку
    }

    pos = f_address->S_Street.find (L"пл-дь.", 0); // находим начальный индекс заменяемой подстроки площади
    if (pos != std::string::npos) {
        f_address->S_Street.replace (pos, 6, L"площадь"); // заменяем подстроку
    }

    pos = f_address->S_Street.find (L"в-з.", 0); // находим начальный индекс заменяемой подстроки взвоза
    if (pos != std::string::npos) {
        f_address->S_Street.replace (pos, 4, L"взвоз"); // заменяем подстроку
    }

    // Обработка S_House
    pos = f_address->S_House.find (L"д.", 0); // находим начальный индекс заменяемой подстроки дома
    if (pos != std::string::npos) {
        f_address->S_House.replace (pos, 2, L"дом"); // заменяем подстроку
    }

    // Обработка S_Flat
    pos = f_address->S_Flat.find (L"кв.", 0); // находим начальный индекс заменяемой подстроки квартиры
    if (pos != std::string::npos) {
        f_address->S_Flat.replace (pos, 3, L"квартира"); // заменяем подстроку
    }
}

// функция вывода структуры
auto Format (const Address &f_address) -> wstr {
    return f_address.S_Country + L", " + f_address.S_City + L", " +
           f_address.S_Street + L", " + f_address.S_House + L", " + f_address.S_Flat + L'\n';
}

// функция вывода базы знаний
auto PrintArray (const wstr *f_Array, const size_t &f_size, const wchar_t *f_str) -> void {
    std::wcout << std::setw (30) << std::right << f_str << '\n';
    const unsigned dev{3}; // переменная для деления
    unsigned short count{1}; // переменная счётчик
    for (size_t i{0}; i < f_size; ++i) {
        std::wcout << f_Array[i] << ", ";
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


    wstr line; // переменная для ввода строки

    PrintArray (Country, MAX_COUNTRY, L"База стран: "); // вывод базы стран
    PrintArray (City, MAX_CITY, L"База городов: "); // вывод базы городов
    PrintArray (Street, MAX_STREET, L"База улиц: "); // вывод базы улиц

    bool stop {false}; // переменная для цикла do while
    do {

        std::wcout << L"Введите почтовый адрес в формате: " << '\n'
                   << L"с-на. Россия, г. Томск, пл-дь. Южная, д. 444, кв. 76.\n" << '\v';

        //выделяется память под поля для структуры address
        address = new (std::nothrow) Address;

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!address) {

            // Обработка этого случая
            std::wcout << L"Память не выделенна!!!";
            return ErrMemory;
        }
        while (std::getline (std::wcin, line)) {
            if (Parse (line, address)) {
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
