#include<iostream>
#include<limits>
#include<iomanip>
#include"C_Bruteforce.h"

// функция выбора набора символов для проверки пароля
std::wstring SelCharCheck();

// функция ввода пароля
std::wstring EnterPassword();

// псевдоним типа для указателей
using PtrString = std::wstring (*)();
PtrString PtrSelCharCheck = SelCharCheck; // указатель на функцию SelCharCheck
PtrString PtrEnterPassword = EnterPassword; // указатель на функцию EnterPassword

// указатель на метод - класса PrintLimits
void (Bruteforce::*PtrPrintLimits)() const  = &Bruteforce::PrintLimits;

// указатель на метод - класса FindPassword
std::wstring (Bruteforce::*PtrFindPassword)(const std::wstring &target) const = &Bruteforce::FindPassword;

// деклорация функции выхода из программы
bool Exit();
bool (*PtrExit)() = Exit; // указатель на функцию Exit


// функция по заданию № 1
void Brutfor() {

    /*это команда отключить синхронизацию потоков C++ (cin, cout)
     * со стандартными потоками C (stdin, stdout)*/
    //std::ios::sync_with_stdio(false);

    std::wstring s = L"Задание 1)";
    std::wcout << std::setw(30) << std::right << s << '\n';
    std::wcout << LR"(
Требуется разработать свой класс Bruteforce, т.е. пользователь вводит какой-то пароль,
и программа методом перебора всех возможных вариантов находит этот пароль.

Предполагается, что программа не может отработать и не найти пароль.
Ограничение перебора осуществляется пользователем: будут ли включены в перебор
цифры, заглавные буквы, символы и т.д.

При вводе в терминале выведите эти ограничения (можно указать, какие символы,
буквы и цифры участвуют при задании пароля).

Рекомендую реализовать ограничитель длины вводимого пароля до 4 символов —
больше не надо, иначе программа долго будет работать.
Еще лучше, если на этапе разработки программы длина пароля будет 2–3 символа.

Кроме того, задайте в программе множество допустимых символов пароля.
)";

    do {
        std::wcout << std::wstring(90, '-') << '\n'
                   << L"=== Настройка перебора паролей ===\n";

        // переменная выбраных сиволов для проверки
        std::wstring alphaBet{PtrSelCharCheck()}; // вызываем функцию через указатель и присваеваем значение

        // ввод целевого пароля
        std::wstring target{PtrEnterPassword()}; // вызываем функцию через указатель и присваеваем значение
        const unsigned short maxLen{static_cast<unsigned short>(target.length())}; // длина пароля

        Bruteforce pass{alphaBet, maxLen};
        (pass.*PtrPrintLimits)(); // вызываем метод - класса PrintLimits через указатель

        std::wcout << std::wstring(90, '-') << '\n';
        std::wcout << L"=== Начинаем перебор ===" << '\n';

        // вызываем метод - класса FindPassword через указатель и присваеваем значение переменной
        std::wstring found{(pass.*PtrFindPassword)(target)};

        if (!found.empty()) {
            std::wcout << L"Пароль найден: " << found << '\n';
        } else std::wcout << L"Пароль не найден в заданных ограничениях." << '\n';

    } while (PtrExit());
}

// функция выбора набора символов для проверки пароля
std::wstring SelCharCheck() {
    std::wcout << L"Выберите набор символов для проверки пароля" << '\n'
              << L"1) 1234567890" << '\n'
              << L"2) ABCDEFGHIJKLMNOPQRSTUVWXYZ" << '\n'
              << L"3) abcdefghijklmnopqrstuvwxyz" << '\n'
              << L"4) 1234567890@#$&" << '\n'
              << L"5) 1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@#$&: ";

    short choice;
    while (true) {
        if (!(std::wcin >> choice) || choice < 1 || choice > 5) {
            std::wcout << L"Введены некорректные данные!!!" << '\n'
                      << L"Введите число от 1 до 5:";
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else break;
    }
    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::wstring str;
    switch (choice) {

    case 1: {
        str = L"1234567890";
        break;
    }
    case 2: {
        str = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        break;
    }
    case 3: {
        str = L"abcdefghijklmnopqrstuvwxyz";
        break;
    }
    case 4: {
        str = L"1234567890@#$&";
        break;
    }
    case 5: {
        str = L"1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@#$&";
        break;
    }
    default: {
        std::cout << L"Такого набора символов нет!!!" << '\n';
    }
    }
    return str;
}

// функция ввода пароля
std::wstring EnterPassword() {

    // ввод целевого пароля
    std::wstring target;
    constexpr unsigned short maxLen{5};
    std::wcout << std::wstring(90, '-') << '\n';
    std::wcout << L"Введите целевой пароль(он должен состоять только из "
                 "выбранных символов.)" << '\n';
    while (true) {
        std::wcout << L"Максимальная длина пароля (рекомендуется 2–3 символа, максимум "
                   << maxLen << L" символа(ов)): ";
        std::getline(std::wcin, target);

        // проверяем на пустую строку пароля
        if (target.empty()) {
            std::wcout << L"Пароль не введён!!!" << '\n'
                       << L"Введите целевой пароль: ";
            continue;
        }

        // проверяем длину пароля
        if (target.length() > maxLen) {
            std::wcout << L"Длина пароля превыхает максимальную длину!!!" << '\n';
            continue;
        }

        // если всё хорошо выходим из цикла
        break;
    }
    return target;
}
