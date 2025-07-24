#include<iostream>
#include"type_thecking.h"

// функция для логического И (&)
auto andOperatin(short var1, short var2) -> bool {
    return var1 & var2;
}

// функция для логического ИЛИ (|)
auto orOperatin(short var1, short var2) -> bool {
    return var1 || var2;
}

// функция для логического ИСКЛЮЧАЮЩЕГО ИЛИ (^)
auto xorOperatin(short var1, short var2) -> bool {
    return var1 ^ var2;
}

// уеказатель на функцию
static bool (*FunсPtr)(short, short);


auto LogicalFunctions() -> void {
    std::cout << "Введите  целочисленное значение для переменных a : ";
    short a = Type_Thecking(a);
    std::cout << "Введите  целочисленное значение для переменных b : ";
    short b = Type_Thecking(b);
    std::cout << "Веберите логическую операцию : \n"
                 "1 - И\n"
                 "2 - ИЛИ\n"
                 "3 - ИСКЛЮЧАЮЩЕЕ ИЛИ\n";
    short choice = Type_Thecking(choice);
}

