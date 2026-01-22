
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
};

void Parse (wstr& line, Address* address);
void Unify (Address* address);
wstr Format(const Address& address);

// функция выделения из строки компонентов адреса
void Parse (wstr& line, Address* address) {
    if (line.empty ()) {
        std::wcout << L"exception\n";
    }

    size_t start = 0;

    // Извлекаем S_Country
    auto stop = line.find (',', start);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_Country = line.substr (start, stop - start);
    ++start;

    // Извлекаем S_City
    stop = line.find (',', start);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_City = line.substr (start, stop - start);
    ++start;

    // Извлекаем S_Street
    stop = line.find(',', start);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_Street = line.substr(start, stop - start);
    ++start;

    // Извлекаем S_House
    stop = line.find (',', start);
    if (stop == std::string::npos) {
        std::wcout << L"Неверный формат: пропущена запятая\n";
    }
    address->S_House = line.substr (start, stop - start);
    ++start;

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
        address->S_Country.replace (pos, 2, L"страна");
    } else {
        address->S_Country.insert (0, L"страна");
    }
    // Удаление пробелов по краям
    address->S_Country.erase (0, address->S_House.find_first_not_of (' '));
    address->S_Country.erase (address->S_House.find_last_not_of (' ') + 1);

    // Обработка S_City
    pos = address->S_City.find (L"г.", 0);
    if (pos != std::string::npos) {
        address->S_City.replace (pos, 2, L"город");
    } else {
        address->S_City.insert (0, L"город");
    }
    // Удаление пробелов по краям
    address->S_City.erase (0, address->S_House.find_first_not_of (' '));
    address->S_City.erase (address->S_House.find_last_not_of (' ') + 1);

}

auto Format(const Address& address) -> wstr{
    return address.S_Country + L", " + address.S_City + L", " +
           address.S_Street + L", " + address.S_House + L'\n';
}

// функция по заданию №8
auto MailAddress () -> void {

    setlocale (LC_ALL, "ru_RU.UTF-8");

    wstr s = L"Задание 8)";
    std::wcout << std::setw (30) << std::right << s << '\n';
    std::wcout << L"Разработать программу, обрабатывающую почтовые адреса." << '\n';

    // std::wcout << L"Введите почтовый адрес в Формате: " << '\n'
    //            << L"Россия, г. Краснокаменск, мик-н. 4, д. 444, кв. 76" << '\n';

    wstr line = L"Россия, г. Краснокаменск, мик-н. Северный, д. 444";
    Address *address;
    //while (getline(std::wcin, line)) {
    Parse(line, address);
    Unify(address);
    std::wcout << Format(*address) << "\n";
    //}
}
