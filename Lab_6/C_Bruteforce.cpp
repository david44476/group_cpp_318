#include<iostream>
#include<limits>
#include"C_Bruteforce.h"
#include"errmess.h"

// определение класса C_Bruteforce

// конструктор по умолчанию
Bruteforce::Bruteforce() {
    // std::wcout << L"Конструктор по умолчанию вызвался!!!" << '\n';
    if (!m_maxLen) {
        m_maxLen = new(std::nothrow)ushort{static_cast<ushort>(RetFunc::OverFlow)};
        if (!m_maxLen) {
            errmess::Exeption(L"Для объекта m_maxLen память не выделена!!!");
            return;
        }
    } else m_maxLen = nullptr;

    if (!m_alphaBet) {
        m_alphaBet = new(std::nothrow)wstr{L"0123456789"};
        if (!m_alphaBet) {
            errmess::Exeption(L"Для объекта m_alphaBet память не выделена!!!");
            delete m_maxLen; // удаляем ранее диномически выделенную память
            m_maxLen = nullptr; // обнуляем указатель
            return;
        }
    } else m_alphaBet = nullptr;

    if (!m_pass) {
        m_pass = new(std::nothrow)wstr{L"12345"};
        if (!m_pass) {
            errmess::Exeption(L"Для объекта m_pass память не выделена!!!");
            delete m_maxLen; // удаляем ранее диномически выделенную память
            m_maxLen = nullptr; // обнуляем указатель
            delete m_alphaBet; // удаляем ранее диномически выделенную память
            m_alphaBet = nullptr; // обнуляем указатель
            return;
        }
    } else m_pass = nullptr;
}

// конструктор копирования
Bruteforce::Bruteforce(const Bruteforce &xorigin) {
    // std::wcout << L"Конструктор копирования вызвался!!!" << '\n';
    // проверка на самоприсваивание
    if (this == &xorigin) return;

    /* m_maxLen является указателем, поэтому нам нужно выполнить глубокое копирование,
     * при условии, что указатель original.m_maxLen не является нулевым*/
    if (xorigin.m_maxLen) {
        m_maxLen = new(std::nothrow)ushort;

        // обрабатываем случай когда память не выделина (new возврощает null)
        if (!m_maxLen) {
            errmess::Exeption(L"Для объекта m_maxLen память не выделена!!!");
            return;
        }
        *m_maxLen = *xorigin.m_maxLen;
    }

    /* m_alphaBet является указателем, поэтому нам нужно выполнить глубокое копирование,
     * при условии, что указатель m_alphaBet не является нулевым*/
    if (xorigin.m_alphaBet) {
        m_alphaBet = new(std::nothrow)wstr;

        // обрабатываем случай когда память не выделина (new возврощает null)
        if (!m_alphaBet) {
            errmess::Exeption(L"Для объекта m_alphaBet память не выделена!!!");
            delete m_maxLen;
            m_maxLen = nullptr;
            return;
        }
        *m_alphaBet = *xorigin.m_alphaBet;
    }

    /* m_pass является указателем, поэтому нам нужно выполнить глубокое копирование,
     * при условии, что указатель original.m_pass не является нулевым*/
    if (xorigin.m_pass) {
        m_pass = new(std::nothrow)wstr;

        // обрабатываем случай когда память не выделина (new возврощает null)
        if (!m_pass) {
            errmess::Exeption(L"Для объекта m_pass память не выделена!!!");
            delete m_maxLen;
            m_maxLen = nullptr;
            delete m_alphaBet;
            m_alphaBet = nullptr;
            return;
        }
        *m_pass = *xorigin.m_pass;
    }

}

// деструктор
Bruteforce::~Bruteforce() {
    // std::wcout << L"\nДеструктор вызвался!!!" << '\n';

    // освобождаем динамически выделенную память
    if (m_maxLen) { // если указатель m_maxLen не null освобождаем память
        // std::wcerr << "Bruteforce::~Bruteforce() called, m_maxLen = " << *m_maxLen << '\n';
        delete m_maxLen;
        m_maxLen = nullptr;
    }
    if (m_alphaBet) { // если указатель m_alphaBet не null освобождаем память
        // std::wcerr << "Bruteforce::~Bruteforce() called, m_alphaBet = " << *m_alphaBet << '\n';
        delete m_alphaBet;
        m_alphaBet = nullptr;
    }
    if (m_pass) { // если указатель m_pass не null освобождаем память
        // std::wcerr << "Bruteforce::~Bruteforce() called, m_pass = " << *m_pass << '\n';
        delete m_pass;
        m_pass = nullptr;
    }
}

// методы класса устанавливают значение полю класса m_maxLen (длина пароля)***************
RetFunc Bruteforce::SetMaxLen(const ushort &xmaxLen) {
    if (xmaxLen > RetFunc::ErrData && xmaxLen < RetFunc::OverFlow) {
        m_maxLen = new(std::nothrow) ushort;
        if (!m_maxLen) {
            errmess::Exeption(L"Для объекта m_maxLen память не выделена!!!");
            return RetFunc::ErrData;
        }
        *m_maxLen = xmaxLen;
        return RetFunc::Ok;
    }
    else return RetFunc::OutRange;
} // Bruteforce::SetMaxLen

Bruteforce &Bruteforce::MaxLen() {
    if (!m_maxLen) {
        m_maxLen = new(std::nothrow)ushort;
        if (!m_maxLen) {
            errmess::Exeption(L"Для объекта m_maxLen память не выделена!!!");
            return *this;;
        }
        *m_maxLen = static_cast<ushort>(RetFunc::OverFlow);
    }
    return *this;
} // Bruteforce::MaxLen
// ***************************************************************************************


// методы класса устанавливают значение полю класса m_alphaBet (набор символов)***********
RetFunc Bruteforce::SetAlphaBet(const wstr &xalphaBet) {
    if (!xalphaBet.empty()) {
        m_alphaBet = new(std::nothrow)wstr;
        if (!m_alphaBet) {
            errmess::Exeption(L"Для объекта m_maxLen память не выделена!!!");
            return RetFunc::ErrData;
        }
        *m_alphaBet = xalphaBet;
        return RetFunc::Ok;
    }
    else return RetFunc::OutRange;
} // Bruteforce::SetAlphaBet

Bruteforce &Bruteforce::CharSet() {
    if (!m_alphaBet) {
        m_alphaBet = new(std::nothrow)wstr;
        if (!m_alphaBet) {
            errmess::Exeption(L"Для объекта m_alphaBet память не выделена!!!");
            return *this;
        }
    }
    std::wcout << wstr(90, '-') << '\n';
    std::wcout << L"Выберите набор символов для проверки пароля" << '\n'
               << L"1) 1234567890" << '\n'
               << L"2) ABCDEFGHIJKLMNOPQRSTUVWXYZ" << '\n'
               << L"3) abcdefghijklmnopqrstuvwxyz" << '\n'
               << L"4) 1234567890@#$&" << '\n'
               << L"5) 1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@#$&: " << '\n';
    errmess::Info(L"Введите число от " + std::to_wstring(RetFunc::ErrData)
                  + L" до " + std::to_wstring(RetFunc::OutRange));

    short choice;
    while (true) {
        std::wcout << L" :> ";
        if (!(std::wcin >> choice) || choice < RetFunc::ErrData || choice > RetFunc::OutRange) {
            errmess::Exeption(L"Введены некорректные данные!!!\n");
            errmess::Info(L"Введите число от " + std::to_wstring(RetFunc::ErrData)
                          + L" до " + std::to_wstring(RetFunc::OutRange));
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else break;
    }
    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (choice) {

    case 1: {
        *m_alphaBet = L"1234567890";
        break;
    }
    case 2: {
        *m_alphaBet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        break;
    }
    case 3: {
        *m_alphaBet = L"abcdefghijklmnopqrstuvwxyz";
        break;
    }
    case 4: {
        *m_alphaBet = L"1234567890@#$&";
        break;
    }
    case 5: {
        *m_alphaBet = L"1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@#$&";
        break;
    }
    }
    return *this;
} // Bruteforce::CharSet
// ***************************************************************************************

// методы класса ввода пароля**************************************************************
RetFunc Bruteforce::SetPass(const wstr &xpass) {
    if (!xpass.empty()) {
        m_pass = new(std::nothrow)wstr;
        if (!m_pass) {
            errmess::Exeption(L"Для объекта m_maxLen память не выделена!!!");
            return RetFunc::ErrData;
        }
        *m_pass = xpass;
        return RetFunc::Ok;
    }
    else return RetFunc::EmptStr;
} // Bruteforce::SetPass

Bruteforce &Bruteforce::InputPass() {
    if (!m_pass) {
        m_pass = new(std::nothrow)wstr;
        if (!m_pass) {
            errmess::Exeption(L"Для объекта m_pass память не выделена!!!");
            return *this;
        }
    }
    std::wcout << wstr(90, '-') << '\n';
    std::wcout << L"Введите целевой пароль(он должен состоять только из "
                  "выбранных символов.)" << L" \"" << *m_alphaBet << L"\"" << '\n';
    while (true) {
        errmess::Info(L"Максимальная длина пароля (рекомендуется 2–3 символа, максимум "
                      + std::to_wstring(*m_maxLen) + L" символа(ов))." + L'\n');
        std::wcout << L":> ";
        std::getline(std::wcin, *m_pass);

        // проверяем на пустую строку пароля
        if (m_pass->empty()) {
            errmess::Warning(L"Пароль не введён!!!\n"
                             L"Введите целевой пароль: ");
            continue;
        }

        // проверяем длину пароля
        if (m_pass->length() > *m_maxLen) {
            errmess::Warning(L"Длина пароля превышает максимальную длину "
                             + std::to_wstring(*m_maxLen) + L" символа(ов)!!!\n");
            continue;
        }

        if (PassBrutFor(*m_pass)) {
            errmess::Warning(L"Ваш пароль не соответствует набору символов: " + *m_alphaBet + L'\n');
            continue;
        } else errmess::Info(L"Ваш пароль принят!!!\n");

        // если всё хорошо выходим из цикла
        break;
    }
    return *this;
} // Bruteforce::InputPass
// ***************************************************************************************

// вывод текущих ограничений(алфавит, длина, оценка числа комбинаций)
void Bruteforce::PrintLimits() const {
    std::wcout << wstr(90, '-') << '\n';
    std::wcout << L"=== Ограничения перебора ===" << '\n'
               << L"Допустимые символы: " << *m_alphaBet << '\n'
               << L"Максимальная длина пароля: " << *m_maxLen << L" символа(ов)." << '\n';
} // Bruteforce::PrintLimits

// метод класса перебора пароля
RetFunc Bruteforce::PassBrutFor(const wstr &xpass) {
    if (xpass.empty()) {
        errmess::Exeption(L"Строка пароля пустая!!!\n");
        return RetFunc::EmptStr;
    }

    // проверяем на инециализацию m_alphaBet
    if (!m_alphaBet || m_alphaBet->empty()) {
        errmess::Exeption(L"Строка проверки символов пустая!!!\n");
        return RetFunc::EmptStr;
    }

    // прверяем введённый пароль со строкой символов
    if (xpass.find_first_of(*m_alphaBet) == wstr::npos) return RetFunc::ErrData;
    else return RetFunc::Ok;
} // Bruteforce::PassBrutFor

// метод класса вывода пароля
void Bruteforce::PrintPass() {
    std::wcout << wstr(90, '-') << '\n';
    std::wcout << L"Ваш пароль: " << *m_pass << L" , содержит символы: " << *m_alphaBet
               << L", длиной " << *m_maxLen << L" символа(ов)." << '\n';

    long long numComb{0};
    long long power{1};
    for (auto len{1}; len <= *m_maxLen; ++len) {
        power *= static_cast<long long>(m_alphaBet->size());
        numComb += power;
    }
    errmess::Info(L"Примерное число комбинаций: " + std::to_wstring(numComb));
    std::wcout << std::endl;
} // Bruteforce::PrintPass
