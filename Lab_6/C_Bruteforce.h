#ifndef C_BRUTEFORCE_H
#define C_BRUTEFORCE_H

#include"Constans.h"

// обьявление класса C_Bruteforce
class Bruteforce {
private:
    ushort* m_maxLen{nullptr}; // максимальная длина пароля
    wstr* m_alphaBet{nullptr}; // набор допустимых символов
    wstr* m_pass{nullptr}; // введённый пароль

    // метод класса перебора пароля
    RetFunc PassBrutFor(const wstr &xpass);
public:

    // конструктор по умолчанию
    Bruteforce();

    // конструктор копирования
    Bruteforce(const Bruteforce &xorigin);

    // деструктор
    ~Bruteforce();

    // методы класса устанавливают значение полю класса m_maxLen (длина пароля)
    RetFunc SetMaxLen(const ushort &xmaxLen);
    Bruteforce &MaxLen();

    // методы класса устанавливают значение полю класса m_alphaBet (набор символов)
    RetFunc SetAlphaBet(const wstr &xalphaBet);
    Bruteforce &CharSet();

    // методы класса устанавливают значение полю класса m_pass (пароль)
    RetFunc SetPass(const wstr &xpass);
    Bruteforce &InputPass();

    // методы класса Get
    const ushort &GetMaxLen() const {return *m_maxLen;} // метод класса читает значение поля класса m_maxLen
    const wstr &GetAlphaBet() const {return *m_alphaBet;} // метод класса читает значение поля класса m_alphaBet
    const wstr &GetPass() const {return *m_pass;} // метод класса читает значение поля класса m_pass

    // вывод текущих ограничений(алфавит, длина, оценка числа комбинаций)
    void PrintLimits() const;

    // метод класса вывода пароля
    void PrintPass();
};

#endif // C_BRUTEFORCE_H
