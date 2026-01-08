#include<iostream>
#include<string>
#include <iomanip>

// псевдоним типа
using wstr = std::wstring;

// структура адреса
struct Address {
    wstr Country; // страна
    wstr City; // город
    wstr Street; //улица
    wstr House; // дом
}*address{nullptr};

void Parse (wstr& line, Address* address);
void Unify (Address* address);
wstr Format(const Address& address);

// функция по заданию №8
auto MailAddress () -> void {

    setlocale (LC_ALL, "ru_RU.UTF-8");

    wstr s = L"Задание 7)";
    std::wcout << std::setw (30) << std::right << s << '\n';
    std::wcout << L"Разработать программу, обрабатывающую почтовые адреса." << '\n';

    // std::wcout << L"Введите почтовый адрес в Формате: " << '\n'
    //             << L"Россия, г. Екатеринбург, пр-д. Ермолаева, д. 32" << '\n';
    wstr line = L"Россия, г. Екатеринбург, пр-д. Ермолаева, д. 32";
    try {
        Parse(line, address);
        Unify(address);
        Format(*address);

        while (std::getline (std::wcin, line)) {
            Parse (line, address);
            Unify (address);
            Format (*address);
        }
    } catch (const char* error_message) {
        std::cerr << error_message;
    }
}

// функция выделения из строки компоненты адреса
void Parse(wstr& line, Address* address) {
    if (line.empty () || address == nullptr) {
        throw L"exception\n";
    }

    size_t start = 0;
    size_t stop;

    // Извлекаем House
    stop = line.find (L',', start);
    if (stop == wstr::npos) {
        throw L"Неверный формат: пропущена запятая\n";
    }
    address->House = line.substr (start, stop - start);
    start = stop + 1;

    // Извлекаем Street
    stop = line.find (L',', start);
    if (stop == wstr::npos) {
        throw L"Неверный формат: пропущена запятая\n";
    }
    address->Street = line.substr (start, stop - start);
    start = stop + 1;

    // Извлекаем City
    stop = line.find (L',', start);
    if (stop == wstr::npos) {
        throw L"Неверный формат: пропущена запятая\n";
    }
    address->City = line.substr (start, stop - start);
    start = stop + 1;

    // Извлекаем Country (всё, что осталось)
    address->Country = line.substr (start);
}

// функция приводит компоненты адреса к каноническому виду
void Unify (Address* address) {
    if (address == nullptr) {
        throw L"exception\n";
    }
    wstr Str = L"д.";
    // Обработка House
    size_t pos {address->House.find (L"д.", 0)};
    if (pos != wstr::npos) {
        address->House.replace (pos, 2, L"дом");
    } else {
        address->House.insert (0, L"дом ");
    }

    // Удаление пробелов по краям
    address->House.erase (0, address->House.find_first_not_of(L' '));
    address->House.erase (address->House.find_last_not_of(L' ') + 1);

    // Обработка Street
    pos = address->Street.find (L"ул.", 0);
    if (pos != wstr::npos) {
        address->Street.replace (pos, 3, L"улица");
    }
    pos = address->Street.find (L"пр-д.", 0);
    if (pos != wstr::npos) {
        address->Street.replace (pos, 5, L"проезд");
    }
    pos = address->Street.find (L"улица", 0);
    if (pos == wstr::npos) {
        address->Street.insert (0, L"улица ");
    }
    address->Street.erase (0, address->Street.find_first_not_of(L' '));
    address->Street.erase (address->Street.find_last_not_of(L' ') + 1);

    // Обработка City
    pos = address->City.find (L"г.", 0);
    if (pos != wstr::npos) {
        address->City.replace (pos, 2, L"город");
    }
    pos = address->City.find (L"город", 0);
    if (pos == wstr::npos) {
        address->City.insert (0, L"город ");
    }
    address->City.erase (0, address->City.find_first_not_of(L' '));
    address->City.erase (address->City.find_last_not_of(L' ') + 1);

    // Обработка Country (только удаление пробелов)
    address->Country.erase (0, address->Country.find_first_not_of(L' '));
    address->Country.erase (address->Country.find_last_not_of(L' ') + 1);
}

auto Format(const Address& address) -> wstr {
return address.Country + L", " + address.City <+ L", " +
           address.Street + L", " + address.House + L'\n';
}
