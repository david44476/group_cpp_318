#include<vector>
#include"C_Bruteforce.h"
#include"errmess.h"

// конструктор по умолчанию
Bruteforce::Bruteforce() {
    if (!m_alphaBet) { // если указатель null
        m_alphaBet = new(std::nothrow) wstr; // выделяем динамическую память

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!m_alphaBet) {
            Errmess::Exeption(L"Память для строки символов \"m_alphaBet\" не выделена!!!");
            return;
        } else *m_alphaBet = L"0123456789"; // присваеваем строке символов значение по умолчанию
    }

    if (!m_combTried) { // если указатель null
        m_combTried = new(std::nothrow) ullong; // выделяем динамическую память

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!m_combTried) {
            Errmess::Exeption(L"Память для счётчика \"m_combTried\" не выделена!!!");
            delete m_alphaBet; // освобождаем ранее выделенную память под строку символов m_alphaBet
            m_alphaBet = nullptr; // обнуляем указатель
            return;
        } else *m_combTried = 0; // присваеваем счётчику значение по умолчанию
    }
} // Bruteforce::Bruteforce конструктор по умолчанию

// конструктор с параметрами
Bruteforce::Bruteforce(const wstr &xalphaBet) : m_combTried{0} {
    if (xalphaBet.empty()) {
        Errmess::Warning(L"Строка симловов для перебора комбинаций пароля пустая!!!");
        return;
    }
    if (!m_alphaBet) { // если указатель null
        m_alphaBet = new(std::nothrow) wstr; // выделяем динамическую память

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!m_alphaBet) {
            Errmess::Exeption(L"Память для строки символов \"m_alphaBet\" не выделена!!!");
            return;
        } else *m_alphaBet = xalphaBet;
    }

    if (!m_combTried) { // если указатель null
        m_combTried = new(std::nothrow) ullong; // выделяем динамическую память

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!m_combTried) {
            Errmess::Exeption(L"Память для счётчика \"m_combTried\" не выделена!!!");
            delete m_alphaBet; // освобождаем ранее выделенную память под строку символов m_alphaBet
            m_alphaBet = nullptr; // обнуляем указатель
            return;
        } else *m_combTried = 0; // присваеваем счётчику значение
    }
} // Bruteforce::Bruteforce конструктор с параметрами

// конструктор копирования
Bruteforce::Bruteforce(const Bruteforce &xbrutForc) {

    // проверяем на само присваивание
    if (this == &xbrutForc) return;

    // проверяем что m_alphaBet неявляется null
    if (xbrutForc.m_alphaBet) {
        m_alphaBet = new(std::nothrow) wstr; // выделяем память

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!m_alphaBet) {
            Errmess::Exeption(L"Для объекта \"m_alphaBet\" память не выделена!!!");
            return;
        }
        *m_alphaBet = *xbrutForc.m_alphaBet; // выполняем копирование
    } else m_alphaBet = nullptr;

    // проверяем что m_combTried неявляется null
    if (xbrutForc.m_combTried) {
        m_combTried = new(std::nothrow) ullong;// выделяем память

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!m_combTried) {
            Errmess::Exeption(L"Для объекта \"m_combTried\" память не выделена!!!");
            delete m_alphaBet;
            m_alphaBet = nullptr;
            return;
        }
        *m_combTried = *xbrutForc.m_combTried; // выполняем копирование
    } else m_combTried = nullptr;
} // Bruteforce::Bruteforce конструктор копирования

// оператор присваивания (глубокое копирование)
Bruteforce& Bruteforce::operator = (const Bruteforce &xbrutForc) {
    if (this == &xbrutForc) return *this;

    // сначала выделяем новую память
    wstr *newAlphaBet = new wstr(*xbrutForc.m_alphaBet);
    ullong *newCombTried = new ullong(*xbrutForc.m_combTried);

    // безопастно удаляем старые
    delete m_alphaBet;
    delete m_combTried;

    // присваеваем новые
    m_alphaBet = newAlphaBet;
    m_combTried = newCombTried;

    return *this;
} // Bruteforce::operator оператор присваивания


// деструктор
Bruteforce::~Bruteforce() {
    Errmess::Info(L"Деструктор вызвался!!!");
    if (m_alphaBet != nullptr) {
        delete m_alphaBet;
        m_alphaBet = nullptr;
    }
    if (m_combTried != nullptr) {
        delete m_combTried;
        m_combTried = nullptr;
    }
}

// метод класса устанавливает значение поля класса m_alphaBet
auto Bruteforce::SetAlphaBet(const wstr &xalphaBet) -> RetFunc {
    if (xalphaBet.empty()) {
        Errmess::Warning(L"Строка симловов для перебора комбинаций пароля пустая!!!");
        return RetFunc::EmptyLine;
    }

    if (!m_alphaBet) { // если указатель null
        m_alphaBet = new(std::nothrow) wstr; // выделяем динамическую память

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!m_alphaBet) {
            Errmess::Exeption(L"Память для строки символов \"m_alphaBet\" не выделена!!!");
            return RetFunc::ErrMemory;
        } else *m_alphaBet = xalphaBet; // присваеваем значение
    }
    return RetFunc::Ok;
} // Bruteforce::SetAlphaBet

// метод класса перебора комбинаций пароля
auto Bruteforce::CharSearch(const wstr &xpass, const ushort &xmaxLen) -> RetFunc {

    // Проверка инициализацию алфавита
    if (!m_alphaBet || m_alphaBet->empty()) {
        Errmess::Exeption(L"Строка символов для перебора пароля пустая!!!");
        return RetFunc::EmptyLine;
    }
    if (xpass.empty()) {
        Errmess::Warning(L"Строка пароля не должна быть пустой!!!");
        return RetFunc::EmptyLine;
    } else if (xpass.length() > xmaxLen) {
        Errmess::Exeption(L"Длина пароля превышает допустимое значение " + std::to_wstring(xmaxLen)
                          + L" символов!!!");
        return RetFunc::Overflow;
    }
    if (m_alphaBet->empty() || xmaxLen == 0) {
        Errmess::Exeption(L"Строка символов для перебора пароля пустая!!!");
        return RetFunc::EmptyLine;
    }
    ushort len{static_cast<ushort>(xpass.length())};
    std::vector<size_t> ind(len, 0); // индексы символов
    size_t n{m_alphaBet->size()};

    ResCombTri(); // обнуляем счётчик через приватный метод класса

    // собираем текущую комбинацию
    while (true) {
        wstr candidate(len, L' ');
        for (auto i{0}; i < len; ++i) {
            candidate[i] = (*m_alphaBet)[ind[i]];
        }
        if (m_combTried != nullptr) {
            ++(*m_combTried);
        }

        // проверяем совпадение
        if (candidate == xpass) {
            return RetFunc::Ok;
        }

        // переходим к следующей комбинации
        auto pos = static_cast<ushort>(len) - 1;
        while (pos >= 0) {
            ++ind[pos];
            if (ind[pos] < n) {
                break; // нет переноса - следующая комбинация готова
            }

            // перенос в следующий разряд
            ind[pos] = 0;
            --pos;
        }

        // если вышли за начало - все комбинации перебраны
        if (pos < 0) {
            return RetFunc::NotFound; // пароль не найден
        }
    }
} // Bruteforce::CharSearch

// метод класса выводит информацию о переборе
auto Bruteforce::PrintAlpBet(const wstr &xpass) -> void {
    if (!m_alphaBet) {
        Errmess::Exeption(L"Строка символов null!!!");
        return;
    }
    if (!m_combTried) {
        Errmess::Exeption(L"Счётчик null!!!");
        return;
    }
    Errmess::Every(L"Ваш пароль: " + xpass + L" принят!!!" );
    Errmess::Info(L"Строка символов для перебора пароля: " + *m_alphaBet + L'\n'
                  + L" потребовалось " + std::to_wstring(*m_combTried) + L" итераций!!!");
} // Bruteforce::PrintAlpBet
