#include<iostream>
#include<string>
#include<iomanip>

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

// void Parse (wstr& line, Address* address);
// void Unify (Address* address);
// wstr Format(const Address& address);

// функция выделения из строки компонентов адреса
void Parse (wstr& line, Address* address) {
    if (line.empty ()) {
        std::wcout << L"exception\n";
    }

    size_t start {0};

    // Извлекаем S_Country
    auto stop = line.find (',', start);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_Country = line.substr (start, stop - start);
    std::wcout << L"Всё в порядке!\n";
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
void Unify (Address* address) {
    if (address == nullptr) {
        std::wcout << L"exception\n";
    }

    // Обработка S_Country
    auto pos = address->S_Country.find (L"с-на.", 0);
    if (pos != std::string::npos) {
        address->S_Country.replace (pos, 5, L"страна");
    } else {
        address->S_Country.insert (0, L"страна ");
    }
    // Удаление пробелов по краям
    address->S_Country.erase (0, address->S_House.find_first_not_of (' '));
    address->S_Country.erase (address->S_House.find_last_not_of (' ') + 1);

    // Обработка S_City
    pos = address->S_City.find (L"г.", 0);
    if (pos != std::string::npos) {
        address->S_City.replace (pos, 2, L"город");
    } else {
        address->S_City.insert (0, L"город ");
    }
    // Удаление пробелов по краям
    address->S_City.erase (0, address->S_House.find_first_not_of (' '));
    address->S_City.erase (address->S_House.find_last_not_of (' ') + 1);

    // Обработка S_Street
    pos = address->S_Street.find(L"ул.", 0);
    if (pos != std::string::npos) {
        address->S_Street.replace (pos, 3, L"улица");
    }
    pos = address->S_Street.find (L"пр-д.", 0);
    if (pos != std::string::npos) {
        address->S_Street.replace (pos, 5, L"проезд");
    }
    pos = address->S_Street.find (L"улица", 0);
    if (pos == std::string::npos) {
        address->S_Street.insert (0, L"улица ");
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
    } else {
        address->S_Flat.insert (0, L"квартира ");
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
auto MailAddress () -> void {

    setlocale (LC_ALL, "ru_RU.UTF-8");

    wstr s = L"Задание 8)";
    std::wcout << std::setw (30) << std::right << s << '\n';
    std::wcout << L"Разработать программу, обрабатывающую почтовые адреса." << '\n';
    std::wcout << L"Всё в порядке!\n";
    std::wcout << L"Введите почтовый адрес в формате: " << '\n'
               << L"с-на. Россия, г. Краснокаменск, мик-н. 4, д. 444, кв. 76" << '\n';

    wstr line = L"Россия, г. Краснокаменск, мик-н. Северный, д. 444";
    //wstr line;

    //while (std::getline(std::wcin, line)) {

    Parse(line, address);
    Unify(address);
    std::wcout << Format(*address) << "\n";
    //}
}
