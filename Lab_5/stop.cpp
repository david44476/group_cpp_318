#include<iostream>
#include<limits>

// проверка на коректность ввода
auto Type_Thecking (wchar_t& c) -> wchar_t {
    while (true) {
        std::wcin >> c;
        if ( ! (c == L'Y' || c == L'y' || c == L'N' || c == L'n') || c == L' ') {
            std::wcout << L"Вы ввели не верный символ!" << L'\n' << L"Попробуйте ещё: ";
            std::wcin.clear ();
            std::wcin.ignore (std::numeric_limits<wchar_t>::max (), L'\n');
        }
        else break;
    }
    return c;
}

// функция для останоки или продолжения выполнения программы по выбору пользователя
auto Stop () -> bool {
    bool  stop = false;
    // запрос пользователю на выбор действия
    std::wcout << L"Хотите продолжить введите 'Y, а если хотите прекратить 'N' и нажмите ввод: ";
    wchar_t choice{};
    choice = Type_Thecking (choice); // проверка на корректность ввода
    std::wcout << L'\n';

    // условие для действия по выбору пользователя
    if (choice == L'Y' || choice == L'y') stop = false;

    else if (choice == L'N' || choice == L'n') stop = true;

    std::wcin.ignore (std::numeric_limits<wchar_t>::max (), L'\n');
    return stop;
}

