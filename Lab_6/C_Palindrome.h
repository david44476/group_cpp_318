#ifndef C_PALINDROME_H
#define C_PALINDROME_H

#include "constans.h" // содержит константы

// обьявляем класс Palindrome

class Palindrome {
private:
    static constexpr ushort m_maxLen{17};
    wchar_t m_palDron[m_maxLen];
};

#endif // C_PALINDROME_H
