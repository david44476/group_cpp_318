#include<iostream>
#include"C_Bruteforce.h" // содержит обьявление класса Bruteforce
#include"errmess.h" // содержит сообщения о действиях
#include"myEmoji.h" // содержит эмодзи
#include"taskStr.h" // содержит строки вывода информации по заданиям
#include"checkInput.h" // содержит деклорации функций и указатели на них

// деклорация функций***************************************************************************

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
            std::wcout << TaskStr::strTask1; // выводим задание
            constexpr ushort maxlen{8}; // максимальная длина пароля

#if 1 // конструктор с параметрами: строку символов перебора вводит пользователь
            std::wcout << TaskStr::seporStr;
            wstr alphaBet;

            // цикл проверки ввода
            do {
                Errmess::Input(L"Введите желаемые символы для перебора пароля!!!");
                Errmess::Info(L"Без пробелов и табуляций");
                std::wcout << MyEmoji::fingRight << L' '; // приглашение к вводу
            } while ((PtrInStr(alphaBet))); // проверяем условия ввода
            Bruteforce brutFors{alphaBet}; // создаём объект конструктором с параметрами
            Errmess::Info(L"Вводим пароль!!!");
            auto pass{PtrEnterPass(maxlen, brutFors)}; // вводим и перебераем пароль копии

#elif 0 // конструктор с параметрами: строка символов перебора инециализируется через функцию
            auto alphaBet{PtrCharSel()}; // вводим строку символов для перебора
            Bruteforce brtFrс{alphaBet}; // создаём объект конструктором с параметрами
            Errmess::Info(L"Вводим пароль!!!");
            auto pass{PtrEnterPass(maxlen, brtFrс)}; // вводим и перебераем пароль копии

#elif 0 // конструктор по умолчанию: строка символов перебора инециализируется через функцию
            Bruteforce brut; // создаём объект конструктором по умолчанию
            Errmess::Info(L"Вводим строку символов для перебора!!!");
            (brut.*PtrSetAlpha)(PtrCharSel()); // записываем строку символов
            auto pass{PtrEnterPass(maxlen, brut)}; // вводим и перебераем пароль копии

#elif 0 // конструктор копирования: строка символов перебора инециализируется через функцию
            Bruteforce brut; // создаём объект конструктором по умолчанию
            Errmess::Info(L"Вводим пароль для оригинала!!!");
            auto pass{PtrEnterPass(maxlen, brut)}; // вводим и перебераем пароль копии
            {
                Bruteforce brtFrs{brut}; // создаём объект конструктором копирования
                Errmess::Info(L"Выбираем строку символов для копии!!! ");
                (brtFrs.*PtrSetAlpha)(PtrCharSel()); // записываем строку символов в копию
                std::wcout << TaskStr::seporStr; // вывод разделителя =
                Errmess::Info(L"Вводим пароль для копии!!!");
                pass = {PtrEnterPass(maxlen, brtFrs)}; // вводим и перебераем пароль копии
                std::wcout << TaskStr::seporStr; // вывод разделителя =
                Errmess::Info(L"Строка символов копии: " + (brtFrs.*PtrGetAlpha)());
            }
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Info(L"Строка символов оригинала: " + (brut.*PtrGetAlpha)());

#elif 0 // оператор присваивания: строка символов перебора инециализируется через функцию

            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Info(L"Выбираем набор символов для оригинала!!!");
            Bruteforce brut{PtrCharSel()}; // создаём объект конструктором с параметрами
            Errmess::Info(L"Вводим пароль для оригинала!!!");
            auto pass{PtrEnterPass(maxlen, brut)}; // вводим и перебераем пароль оригинала
            {
                Bruteforce brut2; // создаём объект конструктором по умолчанию
                brut2 = brut;
                Errmess::Info(L"Вводим пароль для копии!!!");
                pass = PtrEnterPass(maxlen, brut); // вводим и перебераем пароль копии
                std::wcout << TaskStr::seporStr; // вывод разделителя =
                Errmess::Info(L"Строка символов копии: " + (brut2.*PtrGetAlpha)());
            }
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            Errmess::Info(L"Строка символов оригинала: " + (brut.*PtrGetAlpha)());

#endif
        }
        std::wcout << TaskStr::seporStr; // вывод разделителя =
        std::wcout << MyEmoji::queMark << L" Хотите продолжить демонстрацию задания № "
                   << static_cast<ushort>(ProgrEnum::Task_2) << '\n';
    } while (PtrExit());
} // BrutFor функция по заданию № 1

// функция выбора набора символов
auto CharSel() -> const wstr {
    std::wcout << TaskStr::seporStr; // вывод разделителя =
    Errmess::Info(L"Выберите набор символов для перебора комбинаций пароля:");
    std::wcout << TaskStr::seporEmoji;
    std::wcout << L"1) 0 -> 9" << '\n'
               << L"2) a -> z" << '\n'
               << L"3) A -> Z" << '\n'
               << L"4) 0 -> 9 + @ # $ &" << '\n'
               << L"5) 0 -> 9 + a -> z + A -> Z + @ # $ &" << '\n';
    std::wcout << TaskStr::seporEmoji; // вывод разделителя эмодзи
    ushort choice; // переменная для выбора набора символов

    // цикл проверки ввода
    do {
        Errmess::Input(TaskStr::msg); // выводим условия ввода
        std::wcout << MyEmoji::fingRight << L' '; // прглашение к вводу
    } while (PtrCheInput(choice, static_cast<ushort>(ProgrEnum::Task_2), // проверяем условия ввода
                         static_cast<ushort>(ProgrEnum::Task_Max),
                         L"Данного набора символов не предусмотренно!!!", PtrNumStr) != Ret::Ok);

    switch (choice) { // выбераем строку символов
    case 1: {
        return L"0123456789";
    }
    case 2: {
        return L"abcdefghijklmnopqrstuvwxyz";
    }
    case 3: {
        return L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    case 4: {
        return L"0123456789@#$&";
    }
    case 5: {
        return L"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@#$&";
    }
    default: return L"";
    }
} // CharSel функция выбора набора символов

// функция ввода пароля
auto EnterPass(const ushort &xmaxLen, Bruteforce &xbrutForce) -> const wstr {
    std::wcout << TaskStr::seporStr; // вывод разделителя
    wstr pass; // переменная ввода пароля

    // Собираем сообщение в отдельную строку — так проще и безопаснее
    const wstr passMsg{L"Введите пароль от " + std::to_wstring(static_cast<ushort>(ProgrEnum::Task_3))
                       + L" до " + std::to_wstring(static_cast<ushort>(xmaxLen)) + L" символов."};
    while (true){

        // цикл проверки ввода
        do {
            Errmess::Input(passMsg); // выводим условия ввода пароля
            Errmess::Info(L"Длина пароля не должна превышать " + std::to_wstring(xmaxLen) + L" символа(ов).");
            std::wcout << TaskStr::seporEmoji; // вывод разделителя эмодзи
            Errmess::Info(L"Пароль должен состоять только из выбранного набора символов: "
                          + (xbrutForce.*PtrGetAlpha)());
            std::wcout << MyEmoji::fingRight << L' '; // приглашение к вводу
        } while ((PtrWstr(pass, static_cast<ushort>(ProgrEnum::Task_3), // проверяем условия ввода
                          xmaxLen, L"Длина пароля не соответствует заданнаму в "
                              + std::to_wstring(xmaxLen) + L" символа(ов)!!!")) != Ret::Ok);

        // начинаем перебор
        if ((xbrutForce.*PtrCharSearch)(pass, xmaxLen) != Ret::Ok) {
            std::wcout << TaskStr::disapFace; // вывод разделителя эмодзи
            Errmess::Exeption(L"Ведённый пароль не соответствует заданному набору символов: "
                              + (xbrutForce.*PtrGetAlpha)());
            std::wcout << TaskStr::seporStr; // вывод разделителя =
            continue;
        } else { // если всё прошло успешно
            std::wcout << TaskStr::satFace; // вывод разделителя эмодзи
            (xbrutForce.*PtrPrintAlpha)(pass); // выводим информации о переборе
            break;
        }
    }
    return pass;
} // EnterPass функция ввода пароля
