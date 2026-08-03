#include<iostream>
#include<limits>
#include<iomanip>
#include"C_Bruteforce.h"

// функция выбора набора символов для проверки пароля
std::string SelCharCheck();

// функция ввода пароля
std::string EnterPassword();

// псевдоним типа для указателей
using PtrString = std::string (*)();
PtrString PtrSelCharCheck = SelCharCheck; // указатель на функцию SelCharCheck
PtrString PtrEnterPassword = EnterPassword; // указатель на функцию EnterPassword

// указатель на метод - класса PrintLimits
void (Bruteforce::*PtrPrintLimits)() const  = &Bruteforce::PrintLimits;

// указатель на метод - класса FindPassword
std::string (Bruteforce::*PtrFindPassword)(const std::string &target) const = &Bruteforce::FindPassword;

// деклорация функции выхода из программы
bool Exit();
bool (*PtrExit)() = Exit; // указатель на функцию Exit

void Brutfor() {

    /*это команда отключить синхронизацию потоков C++ (cin, cout)
     * со стандартными потоками C (stdin, stdout)*/
    std::ios::sync_with_stdio(false);

    do {
        std::cout << "=== Настройка перебора паролей ===\n";

        // переменная выбраных сиволов для проверки
        std::string alphaBet{PtrSelCharCheck()}; // вызываем функцию через указатель и присваеваем значение

        // ввод целевого пароля
        std::string target{PtrEnterPassword()}; // вызываем функцию через указатель и присваеваем значение
        const unsigned short maxLen{static_cast<unsigned short>(target.length())}; // длина пароля

        Bruteforce pass{alphaBet, maxLen};
        (pass.*PtrPrintLimits)(); // вызываем метод - класса PrintLimits через указатель

        std::cout << std::string(80, '-') << '\n';
        std::cout << "=== Начинаем перебор ===" << '\n';

        // вызываем метод - класса FindPassword через указатель и присваеваем значение переменной
        std::string found{(pass.*PtrFindPassword)(target)};

        if (!found.empty()) {
            std::cout << "Пароль найден: " << found << '\n';
        } else std::cout << "Пароль не найден в заданных ограничениях." << '\n';

    } while (PtrExit());
}

// функция выбора набора символов для проверки пароля
std::string SelCharCheck() {
    std::cout << "Выберите набор символов для проверки пароля" << '\n'
              << "1) 1234567890" << '\n'
              << "2) ABCDEFGHIJKLMNOPQRSTUVWXYZ" << '\n'
              << "3) abcdefghijklmnopqrstuvwxyz" << '\n'
              << "4) 1234567890@#$&" << '\n'
              << "5) 1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@#$&: ";

    short choice;
    while (true) {
        if (!(std::cin >> choice) || choice < 1 || choice > 5) {
            std::cout << "Введены некорректные данные!!!" << '\n'
                      << "Введите число от 1 до 5:";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else break;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string str;
    switch (choice) {

    case 1: {
        str = "1234567890";
        break;
    }
    case 2: {
        str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        break;
    }
    case 3: {
        str = "abcdefghijklmnopqrstuvwxyz";
        break;
    }
    case 4: {
        str = "1234567890@#$&";
        break;
    }
    case 5: {
        str = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@#$&";
        break;
    }
    default: {
        std::cout << "Такого набора символов нет!!!" << '\n';
    }
    }
    return str;
}

// функция ввода пароля
std::string EnterPassword() {

    // ввод целевого пароля
    std::string target;
    constexpr unsigned short maxLen{5};
    std::cout << std::string(80, '-') << '\n';
    std::cout << "Введите целевой пароль(он должен состоять только из "
                 "выбранных символов.)" << '\n';
    while (true) {
        std::cout << "Максимальная длина пароля (рекомендуется 2–3 символа, максимум "
                  << maxLen << " символа(ов)): ";
        std::getline(std::cin, target);

        // проверяем на пустую строку пароля
        if (target.empty()) {
            std::cout << "Пароль не введён!!!" << '\n'
                      << "Введите целевой пароль: ";
            continue;
        }

        // проверяем длину пароля
        if (target.length() > maxLen) {
            std::cout << "Длина пароля превыхает максимальную длину!!!" << '\n';
            continue;
        }

        // если всё хорошо выходим из цикла
        break;
    }
    return target;
}
