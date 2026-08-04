#ifndef C_BRUTEFORCE_H
#define C_BRUTEFORCE_H

#include<string>

class Bruteforce {
private:
    std::wstring m_alphaBet; // набор допустимых символов
    unsigned short m_maxLen; // максимальная длина пароля
public:

    // конструктор: задаёт алфавит и максимальную длину пароля
    Bruteforce(const std::wstring &alphaBet, const unsigned short &maxLen);

    // вывод текущих ограничений(алфавит, длина, оценка числа комбинаций)
    void PrintLimits() const;

    // перебор: возврошает найденный пароль(гарантированно находит, если он укладывается в ограничения
    std::wstring FindPassword(const std::wstring &target) const;
};
#endif // C_BRUTEFORCE_H
