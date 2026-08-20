#ifndef C_BRUTEFORCE_H
#define C_BRUTEFORCE_H
#include"constans.h"

// обьявляем класс Bruteforce
class Bruteforce {
private:
    wstr *m_alphaBet{nullptr}; // строка символов для перебора
    mutable ullong *m_combTried{nullptr}; // счётчик итераций перебора

    // метод класса обнуляет счётчик
    void ResCombTri() {
        if (m_combTried) *m_combTried = 0;
    }
public:

    // конструктор по умолчанию
    Bruteforce();

    // конструктор с параметрами
    Bruteforce(const wstr &xalphaBet);

    // конструктор копирования
    Bruteforce(const Bruteforce &xbrutForc);

    // оператор присваивания (глубокое копирование)
    Bruteforce& operator=(const Bruteforce &xbrutForc);

    // деструктор
    ~Bruteforce();

    // метод класса устанавливает значение поля класса m_alphaBet строка символов для перебора
    RetFunc SetAlphaBet(const wstr &xalphaBet);

    // метод класса читает значение поля класса m_alphaBet строка символов для перебора
    const wstr &GetAlphaBet() const {return *m_alphaBet;}

    // метод класса читает значение поля класса m_combTried счётчик итераций перебора
    const ullong &GetCombTried() const {return *m_combTried;}

    // метод класса перебора комбинаций пароля
    RetFunc CharSearch(const wstr &xpass, const ushort &xmaxLen);

    // метод класса выводит информацию о переборе
    void PrintAlpBet(const wstr &xpass);
};
#endif // C_BRUTEFORCE_H
