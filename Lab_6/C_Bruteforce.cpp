#include <iostream>
#include <string>

// псевдонимы типов
using wstr = std::wstring;
using ushort = unsigned short;

class C_Bruteforce {
private:
    wstr* targetPassword; // указатель на целевой пароль (динамическая память)
    wchar_t* charset; // динамически выделенный массив символов для перебора
    ushort charSize; // размер набора символов
    ushort maxLength; // максимальная длина пароля
};
