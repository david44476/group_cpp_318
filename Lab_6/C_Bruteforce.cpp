#include<iostream>
#include<iomanip>
#include<vector>
#include"C_Bruteforce.h"

Bruteforce::Bruteforce(const std::string &alphaBet, const unsigned short &maxLen)
    : m_alphaBet{alphaBet}, m_maxLen{maxLen} {}

void Bruteforce::PrintLimits() const {
    std::cout << "=== Ограничения перебора ===" << '\n'
              << "Допустимые символы: " << m_alphaBet << '\n'
              << "Максимальная длина пароля: " << m_maxLen << '\n';

    long long numComb{0};
    long long power{1};
    for (auto len{1}; len <= m_maxLen; ++len) {
        power *= static_cast<long long>(m_alphaBet.size());
        numComb += power;
    }
    std::cout << "Примерное число комбинаций: " << numComb << '\n';
}

std::string Bruteforce::FindPassword(const std::string &target) const {

    // проверка: длина целевого пароля не должна превышать m_maxLen
    if (static_cast<unsigned short>(target.length()) > m_maxLen) {
        std::cerr << "Ошибка: Целевой пароль длинее, чем разрещено настройками перебора!!!" << '\n';
        return "";
    }

    // для каждой длины от 1 до m_maxLen
    for (auto len{1}; len <= m_maxLen; ++len) {

        // вектор индексов: каждый индекс - позиция символа в m_alphaBet
        std::vector<unsigned short> ind(len, 0);

        while (true) {

            // собиаем текущую комбинацию
            std::string candidate;
            candidate.reserve(len);
            for (auto i{0}; i < len; ++i) {
                candidate.push_back(m_alphaBet[ind[i]]);
            }

            // проверка: нашли?
            if (candidate == target) return candidate;

            // Инкремент индексов (как счётчик в системе счисления с основанием m_alphabet.size())
            auto pos = len - 1;
            while (pos >= 0) {
                ++ind[pos];
                if (ind[pos] < static_cast<unsigned short>(m_alphaBet.size())) {
                    break; // нет переполнения - продолжаем
                }
                ind[pos] = 0; // перенос в следующий разряд
                --pos;
            }
            if (pos < 0) break; // все комбинации len перебраны
        }
    }
    return ""; // по условию задачи сюда не должны попасть
}
