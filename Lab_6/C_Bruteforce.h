#ifndef C_BRUTEFORCE_H
#define C_BRUTEFORCE_H
#include"constans.h"

// обьявляем класс Bruteforce
class Bruteforce {
private:
    wstr m_alphaBet;
public:

    // конструктор по умолчанию
    Bruteforce(): m_alphaBet{L"0123456789"} {}

    // конструктор с параметрами
    Bruteforce(const wstr &xalphaBet);

    // метод класса устанавливает значение поля класса m_alphaBet
    RetFunc SetAlphaBet(const wstr &xalphaBet);

    // метод класса читает значение поля класса m_alphaBet
    const wstr &GetAlphaBet() const {return m_alphaBet;}

    // метод класса перебора комбинаций пароля
    const RetFunc CharSearch(const wstr &xpass, const ushort &xmaxLen) const;

    void PrintAlpBet(const wstr &xpass);
};

#endif // C_BRUTEFORCE_H
