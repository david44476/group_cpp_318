#ifndef C_PALINDROME_H
#define C_PALINDROME_H

#include "constans.h" // содержит константы

// обьявляем класс Palindrome

class Palindrome {
private:
    ushort m_size{0}; // размер строки для проверки на полиндром
    wchar_t* m_palin{nullptr}; // строка для проверки на полиндром
public:

    // конструктор по умолчанию
    Palindrome();

    // конструктор с параметрами
    Palindrome(const wchar_t* xpalin);

    // конструктор копирования
    Palindrome(const Palindrome &xpalin);

    // оператор присваивания (глубокое копирование)
    Palindrome& operator =(const Palindrome &xpalin);

    // деструктор
    ~Palindrome();

    // медот класса записывает значение полю класса m_palin строка для проверки на полиндром
    void SetPolin(const wchar_t* xpolin);

    // метод класса для проверки строки на полиндром
    bool PalinWchar(wchar_t* xstr);
};

#endif // C_PALINDROME_H
