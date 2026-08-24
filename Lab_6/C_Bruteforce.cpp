#include<iostream>
#include<vector>
#include"C_Bruteforce.h"
#include"checkInput.h"
#include"errmess.h"
#include"myEmoji.h"
#include"taskStr.h"

// конструктор по умолчанию
Bruteforce::Bruteforce(): m_alphaBet{nullptr}, m_combTried{nullptr} {
    std::wcout << TaskStr::seporStr; // вывод разделителя =
    Errmess::Every(L"Конструктор по умолчанию вызвался!!!");

    // проверяем выделение памяти для набора символов
    if (MemAlloc(m_alphaBet, L"строка символов") == Ret::Ok) {
        *m_alphaBet = L"0123456789"; // присваеваем строке символов значение по умолчанию
    } else return;

    // проверяем выделение памяти для счётчика комбинаций
    if (MemAlloc(m_combTried, L"значения счётчика комбинаций") == Ret::Ok) {
        *m_combTried = 0; // присваеваем счётчику значение по умолчанию
    } else {
        DelMem(m_alphaBet); // удаляем ранее выделенную память для строки символов
        return;
    }
} // Bruteforce::Bruteforce конструктор по умолчанию

// конструктор с параметрами
Bruteforce::Bruteforce(const wstr &xalphaBet): m_alphaBet{nullptr}, m_combTried{nullptr} {
    std::wcout << TaskStr::seporStr; // вывод разделителя =
    Errmess::Every(L"Конструктор с параметрами вызвался!!!");
    if (xalphaBet.empty()) {
        Errmess::Warning(L"Строка симловов для перебора комбинаций пароля пустая!!!");
        return;
    } else {

        // проверяем выделение памяти для набора символов
        if (MemAlloc(m_alphaBet, L"строка символов") == Ret::Ok) {
            *m_alphaBet = xalphaBet; // присваеваем строке символов значение
        } else return;

        // проверяем выделение памяти для счётчика комбинаций
        if (MemAlloc(m_combTried, L"значения счётчика комбинаций") == Ret::Ok) {
            *m_combTried = 0; // присваеваем счётчику значение по умолчанию
        } else {
            DelMem(m_alphaBet); // удаляем ранее выделенную память для строки символов
            return;
        }
    }
} // Bruteforce::Bruteforce конструктор с параметрами

// конструктор копирования
Bruteforce::Bruteforce(const Bruteforce &xbrutForc): m_alphaBet{nullptr}, m_combTried{nullptr} {
    std::wcout << TaskStr::seporStr; // вывод разделителя =
    Errmess::Every(L"Конструктор копирования  вызвался!!!");

    // проверяем выделение памяти для набора символов
    if (MemAlloc(m_alphaBet, L"строка символов") == Ret::Ok) {
        if (xbrutForc.m_alphaBet) {
            *m_alphaBet = *xbrutForc.m_alphaBet; // присваеваем строке символов значение
        } else m_alphaBet->clear(); // оставляем пустую строку
    }

    // проверяем выделение памяти для счётчика комбинаций
    if (MemAlloc(m_combTried, L"значения счётчика комбинаций") == Ret::Ok) {
        if (xbrutForc.m_combTried) { // если указатель на счётчик комбинаций не null
            *m_combTried = *xbrutForc.m_combTried; // присваеваем счётчику значение
        } else *m_combTried = 0;
    } else {
        DelMem(m_alphaBet); // удаляем ранее выделенную память для строки символов
    }
} // Bruteforce::Bruteforce конструктор копирования

// оператор присваивания (глубокое копирование)
Bruteforce& Bruteforce::operator =(const Bruteforce &xbrutForc) {
    std::wcout << TaskStr::seporStr; // вывод разделителя =
    Errmess::Every(L"Оператор присваивания отработал!!!");
    if (this == &xbrutForc) return *this;

    // готовим новый адрес для строки символов
    wstr *newAlphaBet{nullptr};

    // проверяем выделение памяти для набора символов
    if (MemAlloc(newAlphaBet, L"строка символов") != Ret::Ok) return *this; // не трогаем текущий объект
    if (xbrutForc.m_alphaBet) {  // если указатель на строку символов не null
        *newAlphaBet = *xbrutForc.m_alphaBet; // присваеваем значение строке символов по новому адресу
    } else newAlphaBet->clear(); // очищаем строку символов если источник null

    // готовим новый адрес для счётчика
    ullong *newCombTried{nullptr};

    // проверяем выделение памяти для счётчика комбинаций
    if (MemAlloc(newCombTried, L"значения счётчика комбинаций") != Ret::Ok) {
        DelMem(m_alphaBet); // удаляем ранее выделенную память для строки символов
        return *this;
    }
    if (xbrutForc.m_combTried) {  // если указатель на счётчик не null
        *newCombTried = *xbrutForc.m_combTried; // присваеваем значение строке счётчика по новому адресу
    } else *newCombTried = 0; // счётчик должен быть 0, если источник nullptr

    // безопасно заменяем старые данные на новые
    DelMem(m_alphaBet); // удаляем старый адрес
    m_alphaBet = newAlphaBet; // присваеваем новый адрес
    DelMem(m_combTried); // удаляем старый адрес
    m_combTried = newCombTried; // присваеваем новый адрес
    return *this;
} // Bruteforce::operator оператор присваивания


// деструктор
Bruteforce::~Bruteforce() {
    Errmess::Every(L"Деструктор вызвался!!!");
    if (m_alphaBet) {
        DelMem(m_alphaBet); // освобождаем память строки символов
    }
    if (m_combTried) {
        DelMem(m_combTried); // освобождаем память счётчика комбинаций
    }
}

// метод класса устанавливает значение поля класса m_alphaBet
auto Bruteforce::SetAlpha(const wstr &xalphaBet) -> short {
    if (xalphaBet.empty()) {
        Errmess::Warning(L"Строка симловов для перебора комбинаций пароля пустая!!!");
        return Ret::RetFunc::EmptyLine;
    }

    if (!m_alphaBet) { // если указатель null
        m_alphaBet = new(std::nothrow) wstr; // выделяем динамическую память

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!m_alphaBet) {
            Errmess::Exeption(L"Память для строки символов \"m_alphaBet\" не выделена!!!");
            return Ret::RetFunc::ErrMemory;
        }
    }
    *m_alphaBet = xalphaBet; // присваеваем значение
    return Ret::RetFunc::Ok;
} // Bruteforce::SetAlphaBet

// метод класса перебора комбинаций пароля
auto Bruteforce::CharSearch(const wstr &xpass, const ushort &xmaxLen) -> short {

    // Проверка инициализацию алфавита
    if (!m_alphaBet || m_alphaBet->empty()) {
        Errmess::Exeption(L"Строка символов для перебора пароля пустая!!!");
        return Ret::RetFunc::EmptyLine;
    }
    if (xpass.empty()) {
        Errmess::Warning(L"Строка пароля не должна быть пустой!!!");
        return Ret::RetFunc::EmptyLine;
    } else if (xpass.length() > xmaxLen) {
        Errmess::Exeption(L"Длина пароля превышает допустимое значение " + std::to_wstring(xmaxLen)
                          + L" символов!!!");
        return Ret::RetFunc::Overflow;
    }
    if (m_alphaBet->empty() || xmaxLen == 0) {
        Errmess::Exeption(L"Строка символов для перебора пароля пустая!!!");
        return Ret::RetFunc::EmptyLine;
    }
    ushort len{static_cast<ushort>(xpass.length())};
    std::vector<size_t> ind(len, 0); // индексы символов
    size_t n{m_alphaBet->size()};

    ResCombTri(); // обнуляем счётчик комбинаций перебора через приватный метод класса

    // собираем текущую комбинацию
    while (true) {
        wstr candidate(len, L' ');
        for (auto i{0}; i < len; ++i) {
            candidate[i] = (*m_alphaBet)[ind[i]];
        }
        if (m_combTried != nullptr) { // если указатель на счётчик не null
            ++(*m_combTried); // инкркментируем счётчик
        }

        // проверяем совпадение
        if (candidate == xpass) {
            return Ret::RetFunc::Ok;
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
            return Ret::RetFunc::NotFound; // пароль не найден
        }
    }
} // Bruteforce::CharSearch

// метод класса выводит информацию о переборе
auto Bruteforce::PrintAlpha(const wstr &xpass) -> void {
    if (!m_alphaBet) {
        Errmess::Exeption(L"Строка символов null!!!");
        return;
    }
    if (!m_combTried) {
        Errmess::Exeption(L"Счётчик null!!!");
        return;
    }
    Errmess::Every(L"Ваш пароль: " + xpass + L" принят!!!" );
    Errmess::Info(L"Строка символов для перебора пароля: " + *m_alphaBet + L'\n' + MyEmoji::realiz
                  + L"  Потребовалось перебрать " + std::to_wstring(*m_combTried) + L" комбинпций!!!");
} // Bruteforce::PrintAlpBet
