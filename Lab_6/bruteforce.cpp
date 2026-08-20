#include<iostream>
#include<limits>
#include"C_Bruteforce.h"
#include"errmess.h"
#include"myEmoji.h"
#include"taskStr.h"
#include"checkInput.h"

// деклорация функций***************************************************************************
const ushort CharSel(); // функция выбора набора символов
const ushort (*const PtrCharSel)() = CharSel; // указатель на функцию выбора набора символов
const wstr CharInput(const ushort (*)()); // функция ввода набора символов

// указатель на функцию ввода набора символов
const wstr (*const PtrCharInput)(const ushort (*)()) = CharInput;
const wstr EnterPass(const ushort &, const wstr&, const Bruteforce &); // функция ввода пароля

// указатель на функцию ввода пароля
const wstr (*const PtrEnterPass)(const ushort&, const wstr&, const Bruteforce &) = EnterPass;
// *********************************************************************************************

// функция по заданию № 1
auto BrutFor() -> void {
    do {
        std::wcout << TaskStr::strTask1;
        constexpr ushort maxlen{4}; // максимальная длина пароля
        wstr alphaBet{PtrCharInput(PtrCharSel)}; // вводим строку символов для перебора
        if (!alphaBet.empty()) { // проверяем не пустая ли строка символов для перебора
            Bruteforce brutFors{alphaBet}; // создаём объект для перебора
            wstr pass{PtrEnterPass(maxlen, alphaBet, brutFors)}; // перебераем пароль
            //brutFors.PrintAlpBet(pass);
        }
        std::wcout << TaskStr::seporStr + L'\n';
        std::wcout << MyEmoji::queMark << L" Хотите продолжить демонстрацию задания № "
                   << static_cast<ushort>(ProgrEnum::Task_2) << '\n';
    } while (PtrExit());
} // BrutFor

// функция выбора набора символов
auto CharSel() -> const ushort {
    std::wcout << TaskStr::seporStr + L'\n';
    std::wcout << MyEmoji::listTasks << L" Выберите набор символов для перебора комбинаций пароля:"
               << '\n' << L"1) 0 - 9" << '\n'
               << L"2) a - z" << '\n'
               << L"3) A - Z" << '\n'
               << L"4) 0 - 9, @ # $ &" << '\n'
               << L"5) 0 - 9, a - z, A - Z, @ # $ &" << '\n';
    std::wcout << TaskStr::seporEmoji + L'\n';

    // Собираем сообщение в отдельную строку — так проще и безопаснее
    std::wstring msg = L"Введите число от ";
    msg += std::to_wstring(static_cast<ushort>(ProgrEnum::Task_2));
    msg += L" до ";
    msg += std::to_wstring(static_cast<ushort>(ProgrEnum::Task_Max));
    msg += L": ";
    ushort choice;
    while (true){
        Errmess::Info(msg);
        std::wcout << MyEmoji::fingRight << L' ';
        if (CheckInput(choice, static_cast<ushort>(ProgrEnum::Task_2),
                       static_cast<ushort>(ProgrEnum::Task_Max),
                       L"Данного набора символов не предусмотренно!!!")) {
            break;
        }
    }
    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
    return choice;
} // CharSel

// функция ввода набора симмволов
auto CharInput(const ushort (*PtrCharSel)()) -> const wstr {
    wstr xstr;
    switch (PtrCharSel()) {
    case 1: {
        xstr = L"0123456789";
        break;
    }
    case 2: {
        xstr = L"abcdefghijklmnopqrstuvwxyz";
        break;
    }
    case 3: {
        xstr = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        break;
    }
    case 4: {
        xstr = L"0123456789@#$&";
        break;
    }
    case 5: {
        xstr = L"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@#$&";
        break;
    }
    }
    return xstr;
} // CharInput

// функция ввода пароля
auto EnterPass(const ushort &xmaxLen, const wstr &xalphaBet, const Bruteforce &xbrutForce) -> const wstr {
    std::wcout << TaskStr::seporStr + L'\n';
    std::wcout << MyEmoji::listTasks << L" Введите пароль не больше " << xmaxLen << L" символа(ов)."
               << '\n';
    std::wcout << TaskStr::seporEmoji + L'\n';
    std::wcout << MyEmoji::warning << L"Пароль должен состоять только из выбранного набора символов: "
               << xbrutForce.GetAlphaBet() << '\n';

    // Собираем сообщение в отдельную строку — так проще и безопаснее
    std::wstring msg = L"Введите пароль от ";
    msg += std::to_wstring(static_cast<ushort>(ProgrEnum::Task_3));
    msg += L" до ";
    msg += std::to_wstring(static_cast<ushort>(ProgrEnum::Task_5));
    msg += L" символов: ";
    wstr pass;
    while (true){
        Errmess::Info(msg);
        std::wcout << MyEmoji::fingRight << L' ';
        if (!CheckInput(pass, static_cast<ushort>(ProgrEnum::Task_3),
                       static_cast<ushort>(ProgrEnum::Task_5),
                       L"Длина пароля превышает максимальную длину в "
                           + std::to_wstring(xmaxLen) + L" символа(ов)!!!")) {
            continue;
        }

        if (xbrutForce.CharSearch(pass, xmaxLen)) {
            Errmess::Exeption(L"Ведённый пароль не соответствует заданному набору символов: "
                              + xbrutForce.GetAlphaBet());
            continue;
        } else {
            Errmess::Every(L"Ваш пароль принят!!!");
            break;
        }
    }
    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
    return pass;
} // EnterPass
