#include<iostream>
#include"C_Bruteforce.h"
#include"errmess.h"
#include"myEmoji.h"
#include"taskStr.h"
#include"checkInput.h"

// функция по заданию № 1
auto BrutFor() -> void {
    do {
        std::wcout << TaskStr::strTask1; // выводим задание
        constexpr ushort maxlen{4}; // максимальная длина пароля
        auto alphaBet{PtrCharInput(PtrCharSel)}; // вводим строку символов для перебора
        if (!alphaBet.empty()) { // проверяем не пустая ли строка символов для перебора
            Bruteforce brutFors{alphaBet}; // создаём объект для перебора
            auto pass{PtrEnterPass(maxlen, brutFors)}; // перебераем пароль
        }
        std::wcout << TaskStr::seporStr + L'\n';
        std::wcout << MyEmoji::queMark << L" Хотите продолжить демонстрацию задания № "
                   << static_cast<ushort>(ProgrEnum::Task_2) << '\n';
    } while (PtrExit());
} // BrutFor функция по заданию № 1

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
    ushort choice; // переменная для выбора набора символов
    while (true){
        Errmess::Info(TaskStr::msg); // выводим условия ввода

        // проверяем ввод
        if (PtrUshor(choice, static_cast<ushort>(ProgrEnum::Task_2),
                       static_cast<ushort>(ProgrEnum::Task_Max),
                       L"Данного набора символов не предусмотренно!!!")) {
            break;
        }
    }
    return choice;
} // CharSel функция выбора набора символов

// функция ввода набора симмволов
auto CharInput(const ushort (*PtrCharSel)()) -> const wstr {
    wstr xstr; // переменная для строки символов
    switch (PtrCharSel()) { // выбераем строку символов через указатель на функцию
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
} // CharInput функция ввода набора симмволов

// функция ввода пароля
auto EnterPass(const ushort &xmaxLen, Bruteforce &xbrutForce) -> const wstr {
    std::wcout << TaskStr::seporStr + L'\n';
    std::wcout << MyEmoji::listTasks << L" Введите пароль не больше " << xmaxLen << L" символа(ов)."
               << '\n';
    std::wcout << TaskStr::seporEmoji + L'\n';
    std::wcout << MyEmoji::warning << L"Пароль должен состоять только из выбранного набора символов: "
               << (xbrutForce.*PtrGetAlphaBet)() << '\n';
    wstr pass; // переменная ввода пароля
    while (true){
        Errmess::Info(TaskStr::passMsg); // выводим условия ввода пароля
        std::wcout << MyEmoji::fingRight << L' ';

        // проверяем ввод через указатель на функцию
        if (!PtrWstr(pass, static_cast<ushort>(ProgrEnum::Task_3),
                       static_cast<ushort>(ProgrEnum::Task_5),
                       L"Длина пароля не соответствует заданнаму в "
                           + std::to_wstring(xmaxLen) + L" символа(ов)!!!")) {
            continue;
        }

        // начинаем перебор
        if ((xbrutForce.*PtrCharSearch)(pass, xmaxLen)) {
            Errmess::Exeption(L"Ведённый пароль не соответствует заданному набору символов: "
                              + (xbrutForce.*PtrGetAlphaBet)());
            continue;
        } else { // если всё прошло успешно
            (xbrutForce.*PtrPrintAlpBet)(pass); // выводим информации о переборе
            break;
        }
    }
    return pass;
} // EnterPass функция ввода пароля
