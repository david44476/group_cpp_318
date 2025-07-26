#include<iostream>
#include <functional>
#include"type_thecking.h"

#define FUNCTION_POINTER 1

// создаём псевдоним типа для unsigned int
using bit_t = unsigned int;

// создаём псевдоним типа для unsigned char
using uchar_t = unsigned char;

// создаём псевдоним типа на указатель функции
using binary_op = bool(*)(bit_t, bit_t);

// функция для логического И (&)
auto AndOperatin(bit_t var1, bit_t var2) -> bool {
    return var1 & var2;
}

// функция для логического ИЛИ (|)
auto OrOperatin(bit_t var1, bit_t var2) -> bool {
    return var1 | var2;
}

// функция для логического ИСКЛЮЧАЮЩЕГО ИЛИ (^)
auto XorOperatin(bit_t var1, bit_t var2) -> bool {
    return var1 ^ var2;
}

// переменные для ввода пользователем
static bit_t a;
static bit_t b;

auto Select(const uchar_t& choice, bit_t&, bit_t&) -> bool;

auto LogicalFunctions() -> void {
    bool stop = false;
    do {
        std::cout << "Введите  целочисленное значение для переменной a и нажмите ввод : ";
        a = Type_Thecking(a);
        std::cout << "Введите  целочисленное значение для переменной b и нажмите ввод : ";
        b = Type_Thecking(b);
        std::cout << "Веберите логическую операцию и введите соответствующий символ: \n"
                     "& - И (&)\n"
                     "| - ИЛИ (|)\n"
                     "^ - ИСКЛЮЧАЮЩЕЕ ИЛИ (^)\n и нажми ввод : ";

        uchar_t choice = Choice_Type_Thecking(choice);

#if FUNCTION_POINTER == 1
        std::cout << "результат операции " << a << ' ' << choice << ' ' << b << " = " << Select(choice, a, b) << '\n';
#elif FUNCTION_POINTER == 2
#endif

        // запрос пользователю на выбор действия
        std:: cout << "Хотите продолжить введите 'Y, а если хотите прекратить 'N' и нажмите ввод: \n";

        char choice2 {};

        // проверка на корректность ввода
        choice2 = Type_Thecking (choice2);

        // условие для действия по выбору пользователя
        if (choice2 == 'Y' || choice2 == 'y') stop = false;

        else if (choice2 == 'N' || choice2 == 'n') stop = true;
    }
    while( ! stop); // выход из праграммы по выбору пользователя
}


// обычный уеказатель на функцию И (&)
static constexpr binary_op binAnd{AndOperatin};

// обычный уеказатель на функцию ИЛИ (|)
static constexpr binary_op binOr{OrOperatin};

// обычный уеказатель на функцию ИСКЛЮЧАЮЩЕЕ ИЛИ (^)
static constexpr binary_op binXor{XorOperatin};

// указатель на функцию std::function
std::function<bool(bit_t a, bit_t b)> fcnPtr;

auto Select(const uchar_t& choice, bit_t&, bit_t&) -> bool {
    // указываем длину массива
    constexpr bit_t sizeArr{3};
    // создаём массив из указателей на функции
    bool (*funcArray[sizeArr])(bit_t, bit_t) = {binAnd, binOr, binXor};
    for (bit_t i{0}; i < sizeArr; ++i) {
        switch (choice) {
        case '&':
            return funcArray[i];
            break;
        case '|':
            return funcArray[i + 1];
            break;
        case '^':
            return funcArray[i + 2];
            break;
        default: return false;
        }
    }
}





