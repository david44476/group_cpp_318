#include <iostream>
#include "c_bruteforce.h" // содержит обьявление класса Bruteforce
#include "messout.h" // содержит сообщения о действиях
#include "myEmoji.h" // содержит эмодзи
#include "taskStr.h" // содержит строки вывода информации по заданиям
#include "checkInput.h" // содержит деклорации функций и указатели на них

// деклорация функций и указателей**************************************************************

// метод класса устанавливает значение поля класса m_alphaBet строка символов для перебора
short (Bruteforce::*const PtrSetAlpha)(const wstr &xalphaBet) = &Bruteforce::SetAlpha;

// указатель на медот класса перебора комбинаций пароля
short (Bruteforce::*const PtrCharSearch)(const wstr &, const ushort &) = &Bruteforce::CharSearch;

// указатель на метод класса выводящий информацию о переборе
void (Bruteforce::*const PtrPrintAlpha)(const wstr &) = &Bruteforce::PrintAlpha;

// указатель на метод класса выводящий строку символов для перебора пароля
const wstr& (Bruteforce::*const PtrGetAlpha)() const = &Bruteforce::GetAlpha;

const wstr CharSel(); // функция выбора набора символов
const wstr (*const PtrCharSel)() = CharSel; // указатель на функцию выбора набора символов
const wstr EnterPass(const ushort&, Bruteforce&); // функция ввода пароля

// указатель на функцию ввода пароля
const wstr (*const PtrEnterPass)(const ushort&, Bruteforce&) = EnterPass;
// *********************************************************************************************

// функция по заданию № 1
auto BrutFor() -> void {
    do {
        {
            std::wcout << TaskStr::strTask1 + TaskStr::seporStr;
            constexpr ushort maxlen{4};

#if 1   // конструктор с параметрами: строку символов вводит пользователь
            wstr alphaBet;
            do {
                MessOut::Input(L"Введите желаемые символы для ввода пароля!!!");
                MessOut::Info(L"Без пробелов и табуляций");
                std::wcout << MyEmoji::fingRight << L' ';
            } while (PtrInStr(alphaBet));
            std::wcout << TaskStr::seporStr;

            Bruteforce brutFors{alphaBet};
            // добавлен вызов EnterPass — без него перебор не запускался
            auto pass{PtrEnterPass(maxlen, brutFors)};
            MessOut::Info(L"Ваш пароль подобран: " + pass);

#elif 0  // конструктор с параметрами через функцию выбора
            auto alphaBet{PtrCharSel()};
            Bruteforce brtFrs{alphaBet};
            auto pass{PtrEnterPass(maxlen, brtFrs)};

#elif 0  // конструктор по умолчанию
            Bruteforce brut;
            (brut.*PtrSetAlpha)(PtrCharSel());
            auto pass{PtrEnterPass(maxlen, brut)};

#elif 0  // конструктор копирования
            Bruteforce brut;
            MessOut::Input(L"Вводим пароль для оригинала!!!");
            auto pass{PtrEnterPass(maxlen, brut)};
            {
                Bruteforce brtFrs{brut};
                MessOut::Input(L"Выбираем строку символов для копии!!!");
                (brtFrs.*PtrSetAlpha)(PtrCharSel());
                std::wcout << TaskStr::seporStr;
                MessOut::Input(L"Вводим пароль для копии!!!");
                pass = PtrEnterPass(maxlen, brtFrs);
                MessOut::Info(L"Строка символов копии: " + (brtFrs.*PtrGetAlpha)());
            }
            std::wcout << TaskStr::seporStr;
            MessOut::Info(L"Строка символов оригинала: " + (brut.*PtrGetAlpha)());

#elif 0  // оператор присваивания
            MessOut::Input(L"Выбираем набор символов для оригинала!!!");
            Bruteforce brut{PtrCharSel()};
            std::wcout << TaskStr::seporStr;
            MessOut::Info(L"Вводим пароль для оригинала!!!");
            auto pass{PtrEnterPass(maxlen, brut)};
            {
                Bruteforce brut2;
                brut2 = brut;
                std::wcout << TaskStr::seporStr;
                MessOut::Info(L"Вводим пароль для копии!!!");
                pass = PtrEnterPass(maxlen, brut2);          // FIX: brut → brut2
                MessOut::Info(L"Строка символов копии: " + (brut2.*PtrGetAlpha)());
            }
            std::wcout << TaskStr::seporStr;
            MessOut::Info(L"Строка символов оригинала: " + (brut.*PtrGetAlpha)());

#endif
        }
        std::wcout << TaskStr::seporStr;
        std::wcout << MyEmoji::queMark << L" Хотите продолжить демонстрацию задания № "
                   << static_cast<ushort>(ProgrEnum::Task_2) << '\n';
    } while (PtrExit());
}// BrutFor функция по заданию № 1

// функция выбора набора символов
auto CharSel() -> const wstr {
    MessOut::Info(L"Выберите набор символов для перебора комбинаций пароля:");
    std::wcout << TaskStr::seporEmoji;
    std::wcout << L"1) 0 -> 9" << '\n'
               << L"2) a -> z" << '\n'
               << L"3) A -> Z" << '\n'
               << L"4) 0 -> 9 + @ # $ &" << '\n'
               << L"5) 0 -> 9 + a -> z + A -> Z + @ # $ &" << '\n';
    std::wcout << TaskStr::seporEmoji;
    ushort choice;

    do {
        MessOut::Input(TaskStr::msg);
        std::wcout << MyEmoji::fingRight << L' ';
    } while (PtrCheInput(choice,
                         static_cast<ushort>(ProgrEnum::Task_2),
                         static_cast<ushort>(ProgrEnum::Task_Max),
                         L"Данного набора символов не предусмотрено!!!", PtrNumStr) != Ret::Ok);

    switch (choice) {
    case 1: return L"0123456789";
    case 2: return L"abcdefghijklmnopqrstuvwxyz";
    case 3: return L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    case 4: return L"0123456789@#$&";
    case 5: return L"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@#$&";
    default: return L"";
    }
}// CharSel функция выбора набора символов

// функция ввода пароля
auto EnterPass(const ushort &xmaxLen, Bruteforce &xbrutForce) -> const wstr {
    std::wcout << TaskStr::seporEmoji;
    wstr pass;

    const wstr passMsg{L"Введите пароль от "
                       + std::to_wstring(static_cast<ushort>(ProgrEnum::Task_3))
                       + L" до " + std::to_wstring(xmaxLen) + L" символов."};

    while (true) {
        do {
            MessOut::Input(passMsg);
            MessOut::Info(L"Длина пароля не должна превышать "
                          + std::to_wstring(xmaxLen) + L" символа(ов).");
            std::wcout << TaskStr::seporEmoji;
            std::wcout << MyEmoji::fingRight << L' ';
        } while (PtrWstr(pass,
                         static_cast<ushort>(ProgrEnum::Task_3),
                         xmaxLen,
                         L"Длина пароля не соответствует заданному в "
                             + std::to_wstring(xmaxLen) + L" символа(ов)!!!"
                         ) != Ret::Ok);

        // запускаем перебор
        if ((xbrutForce.*PtrCharSearch)(pass, xmaxLen) != Ret::Ok) {
            std::wcout << TaskStr::disapFace;
            MessOut::Exeption(L"Введённый пароль не соответствует набору символов: "
                              + (xbrutForce.*PtrGetAlpha)());
            std::wcout << TaskStr::seporStr;
            continue;   // пусть введёт заново
        }

        // успех
        std::wcout << TaskStr::satFace;
        (xbrutForce.*PtrPrintAlpha)(pass);
        std::wcout << TaskStr::seporStr;
        break;
    }
    return pass;
}// EnterPass функция ввода пароля
