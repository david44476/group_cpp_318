#ifndef C_BRUTEFORCE_H
#define C_BRUTEFORCE_H

#include "constans.h" // содержит константы

// обьявляем класс Bruteforce
class Bruteforce {
private:
    wstr *m_alphaBet{nullptr}; // строка символов для перебора
    mutable ullong *m_combTried{nullptr}; // счётчик комбинаций перебора

    // метод класса обнуляет счётчик
    auto ResCombTri() -> void {
        if (m_combTried) *m_combTried = 0;
    }
public:

    // конструктор по умолчанию
    Bruteforce();

    // конструктор с параметрами
    explicit Bruteforce(const wstr &xalphaBet);

    // конструктор копирования
    explicit Bruteforce(const Bruteforce &xbrutForc);

    // оператор присваивания (глубокое копирование)
    Bruteforce& operator =(const Bruteforce &xbrutForc);

    // деструктор
    ~Bruteforce();

    // метод класса устанавливает значение поля класса m_alphaBet строка символов для перебора
    short SetAlpha(const wstr &xalphaBet);

    // метод класса читает значение поля класса m_alphaBet строка символов для перебора
    const wstr &GetAlpha() const {return *m_alphaBet;}

    // метод класса читает значение поля класса m_combTried счётчик комбинаций перебора
    const ullong &GetComb() const {return *m_combTried;}

    // метод класса перебора комбинаций пароля
    short CharSearch(const wstr &xpass, const ushort &xmaxLen);

    // метод класса выводит информацию о переборе
    void PrintAlpha(const wstr &xpass);
};
#endif // C_BRUTEFORCE_H
