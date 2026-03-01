#include<iostream>
#include<limits>
#include"errmess.h"

// проверка на коректность ввода
auto Type_Thecking(wchar_t& f_c) -> wchar_t {
    while (true) {
        if (!((std::wcin >> f_c) || f_c == L'Д' || f_c == L'д' || f_c == L'Н' || f_c == L'н') || f_c == L' '
            || std::wcin.fail()) {
            errmess::Exeption(L"Вы ввели не верный символ! Попробуйте ещё: ");
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max (), '\n');
        }
        else break;
    }
    return f_c;
}

// функция для останоки или продолжения выполнения программы по выбору пользователя
auto Stop() -> bool {
    bool  stop {false};

    // запрос пользователю на выбор действия
    errmess::Info(L"Хотите продолжить введите 'Д', а если хотите прекратить 'Н' и нажмите ввод: ");
    wchar_t choice = {Type_Thecking(choice)}; // проверка на корректность ввода;

    // условие для действия по выбору пользователя
    if (choice == L'Д' || choice == L'д') stop = false;

    else if (choice == L'Н' || choice == L'н') stop = true;
    return stop;
}
