#include<iostream>
#include<iomanip>
#include"template_functions.h" // содержит определение моих шаблонных функций
#include"type_thecking.h" // содержит мои функции для проверки ввода символьнных переменных
#include"task_8.h"

#define FUNCTION_POINTER 1
#if FUNCTION_POINTER == 1
auto Select (const uchar_t choice) -> binary_op {
#elif FUNCTION_POINTER == 2
auto Select (const uchar_t choice) -> funcStd {
#endif
    switch (choice) {
    case '&':
        return AndOperatin;
        break;
    case '|':
        return OrOperatin;
        break;
    case '^':
        return XorOperatin;
        break;
    default: return nullptr;
    }
}

// функций для задания № 8
auto LogicalFunctions () -> void {

    std::cout << std::setw(30) << std::right << "Задание 8)" << '\n';
    std::cout << "Разработайте программу, которая работает\n"
                 "с логическими функциями: И, ИЛИ, XОR, которые\n"
                 "задаются пользователем (1-И, 2-ИЛИ, 3-XОR), и\n"
                 "принимает два целых числа в качестве\n"
                 "аргументов и возвращает результат операции.\n"
                 "Вместо того, чтобы писать эти функции каждый раз,\n"
                 "определите их как Callback функции и\n"
                 "передать их в другую функцию, которая участвует\n"
                 "в вычислении. Используйте условную компиляцию\n"
                 "для выбора заголовка функции, в которую передается\n"
                 "callback через std::function и обычный указатель.\n\n";

    // переменные для ввода пользователем
    ubit_t a;
    ubit_t b;
    ///////////////

    bool stop = false; // переменная для цикла do while
    do {
        std::cout << "Введите  целочисленное значение для переменной a и нажмите ввод : ";
        a = Type_Thecking (a); // проверка на корректность ввода
        std::cout << "Введите  целочисленное значение для переменной b и нажмите ввод : ";
        b = Type_Thecking (b); // проверка на корректность ввода
        std::cout << "Веберите логическую операцию и введите соответствующий символ: \n"
                     "& - И (&)\n"
                     "| - ИЛИ (|)\n"
                     "^ - ИСКЛЮЧАЮЩЕЕ ИЛИ (^)\n и нажмите ввод : ";

        uchar_t choice = Choice_Type_Thecking (choice); // проверка на корректность ввода


        std::cout << "результат операции = " << Select(choice) << '\n';


        // запрос пользователю на выбор действия
        std:: cout << "Хотите продолжить введите 'Y, а если хотите прекратить 'N' и нажмите ввод: \n";

        char choice2 = Type_Thecking (choice2); // проверка на корректность ввода

        // условие для действия по выбору пользователя
        if (choice2 == 'Y' || choice2 == 'y') stop = false;

        else if (choice2 == 'N' || choice2 == 'n') stop = true;
    }
    while ( ! stop); // выход из праграммы по выбору пользователя
}









