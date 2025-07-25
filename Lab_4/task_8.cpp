#include<iostream>
#include <bitset>
#include"task_8.h"
#include"type_thecking.h"

// создаём псевдоним типа для unsigned int
using bit_t = unsigned int;

// уеказатель на функцию
static bool (*FunсPtr)( bit_t, const bit_t);

// деклорация функциии
auto RGB (bool (*FunсPtr)(bit_t, const bit_t), bit_t, bit_t ) -> void;

const bit_t redBits = 0xFF000000;
const bit_t greenBits = 0x00FF0000;
const bit_t blueBits = 0x0000FF00;
const bit_t alphaBits = 0x000000FF;

// протатип функции для проверки ввода
auto Type_Thecking (bit_t a) -> bit_t;

// функция для логического И (&)
auto andOperatin(bit_t var1, bit_t var2) -> bool {
    return var1 & var2;
}

// функция для логического ИЛИ (|)
auto orOperatin(bit_t var1, bit_t var2) -> bool {
    return var1 | var2;
}

// функция для логического ИСКЛЮЧАЮЩЕГО ИЛИ (^)
auto xorOperatin(bit_t var1, bit_t var2) -> bool {
    return var1 ^ var2;
}



static bit_t pixel; // переменная для диапазона от 0 до 255
static bit_t shift; // переменная для битового сдвига

auto LogicalFunctions() -> void {
    std::cout << "Введите  целочисленное значение для переменных pixel от 0 до 255 : ";
    pixel = Type_Thecking(pixel);
    std::cout << "Введите  целочисленное значение для переменных shift : ";
    shift = Type_Thecking(shift);
    std::cout << "Веберите логическую операцию : \n"
                 "1 - И\n"
                 "2 - ИЛИ\n"
                 "3 - ИСКЛЮЧАЮЩЕЕ ИЛИ\n";
    bit_t choice = Type_Thecking(choice);

# define SELECT_OF_OPERATION 1
#if SELECT_OF_OPERATION == 1
    RGB(andOperatin(pixel, redBits));
#elif SELECT_OF_OPERATION == 2
#else
#endif
}

auto RGB (bool (*FunсPtr)(bit_t, const bit_t), bit_t, bit_t ) -> void {
    /* Используем побитовое И для изоляции красных пикселей, а затем сдвигаем значение вправо
     в диапазон от 0 до 255*/
    unsigned char red = FunсPtr(pixel, redBits) >> shift;
    unsigned char green = FunсPtr(pixel, greenBits) >> shift;
    unsigned char blue = FunсPtr(pixel, blueBits) >> shift;
    unsigned char alpha = FunсPtr(pixel, alphaBits);
    std::cout << "Ваш цвет содержит:\n";
    std::cout << static_cast<int>(red) << " из 255 красного\n";
    std::cout << static_cast<int>(green) << " из 255 зелёного\n";
    std::cout << static_cast<int>(blue) << " из 255 голубого\n";
    std::cout << static_cast<int>(alpha) << " из 255 степени не прозрачности\n";
}

