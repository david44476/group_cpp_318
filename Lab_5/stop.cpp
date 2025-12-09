#include<iostream>
#include<limits>

// проверка на коректность ввода
auto Type_Thecking (wchar_t& c) -> wchar_t {
    while (true) {
        std::wcin >> c;
        if ( ! (c == L'Д' || c == L'д' || c == L'Н' || c == L'н') || c == L' ') {
            std::wcout << L"Вы ввели не верный символ!" << L'\n' << L"Попробуйте ещё: ";
            std::wcin.clear ();
            std::wcin.ignore (std::numeric_limits<wchar_t>::max (), '\n');
        }
        else break;
    }
    return c;
}

// функция для останоки или продолжения выполнения программы по выбору пользователя
auto Stop () -> bool {
    bool  stop {false};
    // запрос пользователю на выбор действия
    std::wcout << L"Хотите продолжить введите 'Д', а если хотите прекратить 'Н' и нажмите ввод: ";
    wchar_t choice{};
    choice = {Type_Thecking (choice)}; // проверка на корректность ввода
    std::wcout << L'\n';

    // условие для действия по выбору пользователя
    if (choice == L'Д' || choice == L'д') stop = false;

    else if (choice == L'Н' || choice == L'н') stop = true;

    std::wcin.ignore (std::numeric_limits<wchar_t>::max (), '\n');
    return stop;
}
