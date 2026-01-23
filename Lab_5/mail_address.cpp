#include<iostream>
#include<string>
#include<iomanip>
#include"constans.h"

// псевдоним типа
using wstr = std::wstring;

// структура адреса
struct Address {
    wstr S_Country; // страна
    wstr S_City; // город
    wstr S_Street; //улица
    wstr S_House; // дом
    wstr S_Flat; // квартира
} *address{nullptr};

// функция выделения из строки компонентов адреса
auto Parse (wstr& line, Address *address) -> void {
    if (line.empty ()) {
        std::wcout << L"exception\n";
    }

    size_t start {0};

    // Извлекаем S_Country
    auto stop = line.find (',', start);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_Country = line.substr (start, stop);
    start = stop + 1;

    // Извлекаем S_City
    stop = line.find (',', start);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_City = line.substr (start, stop - start);
    start = stop + 1;

    // Извлекаем S_Street
    stop = line.find(',', start);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_Street = line.substr(start, stop - start);
    start = stop + 1;

    // Извлекаем S_House
    stop = line.find (',', start);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_House = line.substr (start, stop - start);
    start = stop + 1;

    // Извлекаем S_Flat
    stop = line.find(',', start);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_Flat = line.substr(start, stop - start);
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
    address->S_Street.erase (0, address->S_Street.find_first_not_of (' '));
    address->S_Street.erase (address->S_Street.find_last_not_of (' ') + 1);

    // Обработка S_House
    pos = address->S_House.find (L"д.", 0);
    if (pos != std::string::npos) {
        address->S_House.replace (pos, 2, L"дом");
    } else {
        address->S_House.insert (0, L"дом ");
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

auto Format (const Address& address) -> wstr {
    return address.S_Country + L", " + address.S_City + L", " +
           address.S_Street + L", " + address.S_House + L", " + address.S_Flat + L'\n';
}

// функция по заданию №8
auto MailAddress () -> RetConst {

    setlocale (LC_ALL, "ru_RU.UTF-8");

    wstr s = L"Задание 8)";
    std::wcout << std::setw (30) << std::right << s << '\n';
    std::wcout << L"Разработать программу, обрабатывающую почтовые адреса." << '\n';
    std::wcout << L"Введите почтовый адрес в формате: " << '\n'
               << L"с-на. Россия, г. Краснокаменск, мик-н. 4, д. 444, кв. 76" << '\n';

    //wstr line = L"с-на. Россия, г. Краснокаменск, ул. Северный, д. 444, кв. 76";

    wstr line;
    address = new (std::nothrow) Address[100];
    if ( ! address) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return ErrMemory;
    }

    while (std::getline(std::wcin, line)) {

        Parse (line, address);
        Unify (address);
        std::wcout << Format (*address) << "\n";
    }
    return Ok;
}
