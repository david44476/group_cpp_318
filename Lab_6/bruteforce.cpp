#include<iostream>
#include<limits>
#include"C_Bruteforce.h"

// функция выбора набора символов для проверки пароля
std::string SelCharCheck();

// функция ввода пароля
std::string EnterPassword();

// псевдоним типа для указателей
using PtrString = std::string (*)();
PtrString PtrSelCharCheck = SelCharCheck; // указатель на функцию SelCharCheck
PtrString PtrEnterPassword = EnterPassword; // указатель на функцию EnterPassword

void Brutfor() {

    /*это команда отключить синхронизацию потоков C++ (cin, cout)
     * со стандартными потоками C (stdin, stdout)*/
    std::ios::sync_with_stdio(false);

    std::cout << "=== Настройка перебора паролей ===\n";

    // переменная выбраных сиволов для проверки
    std::string alphaBet{PtrSelCharCheck()}; // вызываем функцию через указатель и присваеваем значение

    // ввод целевого пароля
    std::string target{PtrEnterPassword()}; // вызываем функцию через указатель и присваеваем значение
    const unsigned short maxLen{static_cast<unsigned short>(target.length())}; // длина пароля

    Bruteforce pass{alphaBet, maxLen};
    pass.PrintLimits();

    std::cout << "=== Начинаем перебор ===" << '\n';
    std::string found{pass.FindPassword(target)};

    if (!found.empty()) {
        std::cout << "Пароль найден: " << found << '\n';
    } else std::cout << "Пароль не найден в заданных ограничениях." << '\n';
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
    constexpr unsigned short maxLen{4};
    std::cout << "Введите целевой пароль(он должен состоять только из "
                 "выбранных символов и не длиннее: " << '\n'
                 << "Максимальная длина пароля (рекомендуется 2–3символа, максимум 4 символа): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, target);
    while (true) {
        if (target.empty()) {
            std::cout << "Пароль не введён!!!" << '\n'
                      << "Введите целевой пароль: ";
        } else break;
    }
    while (true) {
        if (target.length() > maxLen) {
            std::cout << "Длина пароля превыхает максимальную длину!!!" << '\n'
                      << "Ввеедите пароль не более " << maxLen << " символов: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else break;
    }
    return target;
}
