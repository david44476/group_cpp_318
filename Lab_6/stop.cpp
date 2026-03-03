#include"check_the_input.h"
#include"errmess.h"

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
