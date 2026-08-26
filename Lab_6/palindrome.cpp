#include<iostream>
#include"checkInput.h"
#include"taskStr.h"
#include"C_Palindrome.h"

// деклорация функций***************************************************************************
void UpCasWchar(wchar_t* xstr); // функция преобразования в верний регистр
void RevWchar(wchar_t* xstr);  // функция разворачивает строку
void RemPunctChar(wchar_t* xstr); // функция удаления не нужных символов
// *********************************************************************************************

// функция по заданию № 2
auto PalDrom() -> void {
    do {
        std::wcout << TaskStr::strTask2; // выводим задание
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
                wchar_t* bufer{nullptr}; // временный буфер

                // проверяем выделение памяти
                if (MemAlloc(bufer, L"временный буфер", maxLen) == Ret::Ok ) {

                    // Копируем исходную строку во временный буфер
                    std::wcsncpy(bufer, enterStr, maxLen);
                    bufer[maxLen - 1] = L'\0'; // гарантия терминатора

                    // Цепочка преобразований
                    RemPunctChar(bufer); // удаляем символы пунктуации и пробелы
                    UpCasWchar(bufer); // преобразовываем в верхний регистр
                    RevWchar(bufer); // разворачиваем строку
                    Palindrome object; // создаём объект конструктором с параметрами
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
                } else continue;
                DelMemArr(bufer); // удаляем ранее выделеную память
            }
        }
        std::wcout << TaskStr::seporStr; // вывод разделителя =
        std::wcout << MyEmoji::queMark << L" Хотите продолжить демонстрацию задания № "
                   << static_cast<ushort>(ProgrEnum::Task_3) << '\n';
    } while (PtrExit());
}

// функция удаления не нужных символов
auto RemPunctChar(wchar_t* xstr) -> void {
    if (!xstr) {
       // MessOut::Warning(L"Строка не должна быть пустой!!!");
        return;
    }
    size_t ind{0};
    for (auto i{0}; xstr[i] != L'\0'; ++i) {
        if (!(std::iswpunct(xstr[i])) && !(std::iswspace(xstr[i]))) xstr[ind++] = xstr[i];
    }
    xstr[ind] = L'\0';
}

// функция преобразования в верний регистр
auto UpCasWchar(wchar_t* xstr) -> void {
    if (!xstr) {
        //MessOut::Warning(L"Строка не должна быть пустой!!!");
        return;
    }
    for (auto i{0}; i < wcslen(xstr); ++i) {
        xstr[i] = std::towupper(xstr[i]);
    }
}

// функция разворачивает строку
auto RevWchar(wchar_t* xstr) -> void {
    if (!xstr) {
        //MessOut::Warning(L"Строка не должна быть пустой!!!");
        return;
    }
    size_t i{0};
    size_t j(wcslen(xstr) - 1);
    while (i < j) {
        wchar_t tmp{xstr[i]};
        xstr[i] = xstr[j];
        xstr[j] = tmp;
        ++i;
        --j;
    }
}
