#include"C_Bruteforce.h"
#include"errmess.h"
#include<iostream>
#include<vector>

// конструктор с параметрами
Bruteforce::Bruteforce(const wstr &xalphaBet) {
    if (xalphaBet.empty()) {
        Errmess::Warning(L"Строка симловов для перебора комбинаций пароля пустая!!!");
        return;
    }
    m_alphaBet = xalphaBet;
} // Bruteforce::Bruteforce

// метод класса устанавливает значение поля класса m_alphaBet
RetFunc Bruteforce::SetAlphaBet(const wstr &xalphaBet) {
    if (xalphaBet.empty()) {
        Errmess::Warning(L"Строка симловов для перебора комбинаций пароля пустая!!!");
        return RetFunc::EmptyLine;
    }
    m_alphaBet = xalphaBet;
    return RetFunc::Ok;
} // Bruteforce::SetAlphaBet

// метод класса перебора комбинаций пароля
const RetFunc Bruteforce::CharSearch(const wstr &xpass, const ushort &xmaxLen) const {
    if (xpass.empty()) {
        Errmess::Warning(L"Строка пароля не должна быть пустой!!!");
        return RetFunc::EmptyLine;
    } else if (xpass.length() > xmaxLen) {
        Errmess::Exeption(L"Длина пароля превышает допустимое значение " + std::to_wstring(xmaxLen)
                          + L" символов!!!");
        return RetFunc::Overflow;
    }
    if (m_alphaBet.empty() || xmaxLen == 0) {
        Errmess::Exeption(L"Строка символов для перебора пароля пустая!!!");
        return RetFunc::EmptyLine;
    }

    ushort len{static_cast<ushort>(xpass.length())};
    std::vector<size_t> ind(len, 0); // индексы символов
    size_t n{m_alphaBet.size()};

    // собираем текущую комбинацию
    while (true) {
        wstr candidate(len, L' ');
        for (auto i{0}; i < len; ++i) {
            candidate[i] = m_alphaBet[ind[i]];
        }

        // проверяем совпадение
        if (candidate == xpass) {
            return RetFunc::Ok;
        }

        // переходим к следующей комбинации
        auto pos = static_cast<ushort>(len) - 1;
        while (pos >= 0) {
            ind[pos]++;
            if (ind[pos] < n) {
                break; // нет переноса - следующая комбинация готова
            }

            // перенос в следующий разряд
            ind[pos] = 0;
            --pos;
        }

        // если вышли за начало - все комбинации перебраны
        if (pos < 0) {
            return RetFunc::Overflow;
        }
    }
} // Bruteforce::CharSearch

void Bruteforce::PrintAlpBet(const wstr &xpass) {
    Errmess::Every(L"Ваш пароль: " + xpass + L" принят!!!" );
    std::wcout << L"Строка символов для перебора пароля: " << m_alphaBet << '\n';
}
