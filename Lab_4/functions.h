#ifndef FUNCTIONS_H
#define FUNCTIONS_H
auto Type_Thecking (short a, short min, short max) -> short;  // проверка на коректность ввода
auto Type_Thecking (short c) -> short;  // проверка на коректность ввода
auto Type_Thecking (char a) -> char;  // проверка на коректность ввода
auto MersWhir (short MyArray[ ], const short size) -> void;  // функуия для заполнения массива Вихрем Мерсена
auto MyGen (short MyArray[ ], const short size) -> void;
#endif // FUNCTIONS_H
