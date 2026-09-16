#include <iostream>
#include "checkInput.h" // содержит деклорации функций и указатели на них
#include "taskStr.h" // содержит строки вывода информации по заданиям
#include "C_Palindrome.h" // содержит обьявление класса Palindrome

// деклорация функций и указателей**************************************************************
void UpCasWchar(wchar_t* xstr); // функция преобразования в верний регистр
void RevWchar(wchar_t* xstr);  // функция разворачивает строку
void RemPunctChar(wchar_t* xstr); // функция удаления не нужных символов
using PalFunc = void (*const)(wchar_t*); // псевдоним типа функций
PalFunc PtrUpCasWcha = UpCasWchar; // указатель на функцию преобразования в верний регистр
PalFunc PtrRevWchar = RevWchar; // указатель на функцию разворачивает строку
PalFunc PtrRemPunctChar = RemPunctChar; // указатель на функцию удаления не нужных символов
// *********************************************************************************************

// функция по заданию № 2
auto PalDrom() -> void {
    do {
        std::wcout << TaskStr::strTask2 + TaskStr::seporStr; // выводим задание
        constexpr size_t maxLen{50};
        wchar_t enterStr[maxLen]{};
        while (true) {
            MessOut::Input(L"Введите строку для проверки на палиндром. Для выхода введите \"q\":");
            std::wcout << MyEmoji::fingRight << L' ';
            short res{CheckInput(enterStr, maxLen)};
            if (res == Ret::Exit) {
                MessOut::Info(L"Выход из программы по желанию пользователя!!!");
                break;
            }else if (res == Ret::EmptyLine) {
                continue;
            }else if (res == Ret::Ok) {
                size_t bufLen{std::wcslen(enterStr) + 1}; // длина строки временного буфера
                wchar_t* bufer{nullptr}; // временный буфер

                // проверяем выделение памяти
                if (MemAlloc(bufer, L"временный буфер", bufLen) == Ret::Ok ) {

                    // Копируем исходную строку во временный буфер
                    std::wcsncpy(bufer, enterStr, bufLen);
                    bufer[bufLen] = L'\0'; // гарантия терминатора

                    // Цепочка преобразований
                    PtrRemPunctChar(bufer); // удаляем символы пунктуации и пробелы
                    PtrUpCasWcha(bufer); // преобразовываем в верхний регистр
                    PtrRevWchar(bufer); // разворачиваем строку
                    Palindrome object; // создаём объект конструктором по умолчанию
                    object.SetPolin(bufer);
                    if (object.PalinWchar()) { // проверка на палиндром через метод класса
                        std::wcout << TaskStr::satFace; // вывод разделителя эмодзи
                        std::wcout << MyEmoji::ok << L" Строка \"" <<  enterStr
                                   << L"\" является палиндромом!!!" << L'\n';
                        std::wcout << TaskStr::seporStr; // вывод разделителя =
                    } else {
                        std::wcout << TaskStr::disapFace; // вывод разделителя эмодзи
                        std::wcout << MyEmoji::error << L" Строка \"" << enterStr
                                   << L"\" не является палиндромом!!!" << L'\n';
                        std::wcout << TaskStr::seporStr; // вывод разделителя =
                    }
                } else {
                    MessOut::Warning(L"Память для временного буфера не выделена!!!");
                    continue;
                }
                DelMemArr(bufer); // удаляем ранее выделеную память для временного буфера
            }
        }
        std::wcout << TaskStr::seporStr; // вывод разделителя =
        std::wcout << MyEmoji::queMark << L" Хотите продолжить демонстрацию задания № "
                   << static_cast<ushort>(ProgrEnum::Task_3) << '\n';
    } while (PtrExit());
} // PalDrom функция по заданию № 2

// функция удаления не нужных символов
auto RemPunctChar(wchar_t* xstr) -> void {
    if (!xstr) {
        MessOut::Warning(L"Строка не должна быть пустой!!!");
        return;
    }
    size_t ind{0};
    for (auto i{0}; xstr[i] != L'\0'; ++i) {
        if (!(std::iswpunct(xstr[i])) && !(std::iswspace(xstr[i]))) xstr[ind++] = xstr[i];
    }
    xstr[ind] = L'\0';
} // RemPunctChar функция удаления не нужных символов

// функция преобразования в верний регистр
auto UpCasWchar(wchar_t* xstr) -> void {
    if (!xstr) {
        MessOut::Warning(L"Строка не должна быть пустой!!!");
        return;
    }
    for (auto i{0}; i < wcslen(xstr); ++i) {
        xstr[i] = std::towupper(xstr[i]);
    }
} //UpCasWchar функция преобразования в верний регистр

// функция разворачивает строку
auto RevWchar(wchar_t* xstr) -> void {
    if (!xstr) {
        MessOut::Warning(L"Строка не должна быть пустой!!!");
        return;
    }
    if (wcslen(xstr) <= 1) return;
    size_t i{0};
    size_t j(wcslen(xstr) - 1);
    while (i < j) {
        wchar_t tmp{xstr[i]};
        xstr[i] = xstr[j];
        xstr[j] = tmp;
        ++i;
        --j;
    }
} // RevWchar функция разворачивает строку
