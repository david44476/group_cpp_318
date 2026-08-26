#include<cstring>
#include"C_Palindrome.h"
#include"checkInput.h"
#include"messout.h"

// конструктор по умолчанию
Palindrome::Palindrome(): m_palin{nullptr}, m_size{0} {}

// конструктор с параметрами
Palindrome::Palindrome(const wchar_t* xpalin) {
    if (!xpalin) {
        MessOut::Exeption(L"Указатель на строку равен null!!!");
        return;
    }
    size_t len = std::wcslen(xpalin);
    if (len == 0) {
        MessOut::Warning(L"Строка проверки на палиндрон не должна быть пустой!!!");
        return;
    }

    // проверяем выделение памяти для набора символов на 1 больше для L'\0'
    if (MemAlloc(m_palin, L"строка проверки на полиндром", len + 1) != Ret::Ok) {
        m_size = 0;
        return;
    }
    m_size = len;

    // копируем по символьно
    for (auto i{0}; xpalin[i] != L'\0'; ++i) {
        m_palin[i] = xpalin[i];
    }

    // ставим терминатор
    m_palin[len] = L'\0';
}

// конструктор копирования
Palindrome::Palindrome(const Palindrome &xpalin): m_palin{nullptr}, m_size{xpalin.m_size} {
    if (m_size > 0 && MemAlloc(m_palin, L"строка проверки на полиндром", m_size + 1) == Ret::Ok) {
        std::wcsncpy(m_palin, xpalin.m_palin, m_size);
        m_palin[m_size] = L'\0';
    } else m_size = 0;
}

// оператор присваивания (глубокое копирование)
Palindrome& Palindrome::operator =(const Palindrome &xpalin) {
    if (this == &xpalin) return *this;
    DelMemArr(m_palin); // удаляем старую память
    m_size = xpalin.m_size;
    if (m_size > 0 && MemAlloc(m_palin, L"строка проверки на полиндром", m_size + 1) == Ret::Ok) {
        std::wcsncpy(m_palin, xpalin.m_palin, m_size);
        m_palin[m_size] = L'\0';
    } else m_size = 0;
    return *this;
}

// деструктор
Palindrome::~Palindrome() {
    if (m_palin) DelMemArr(m_palin);
}

// медот класса записывает значение полю класса m_palin строка для проверки на полиндром
auto Palindrome::SetPolin(const wchar_t* xpalin) -> short {
    if (!xpalin) {
        MessOut::Exeption(L"Указатель на строку равен null!!!");
        return Ret::NullPointer;
    } else if (!m_palin) {
        m_size = std::wcslen(xpalin);
        if (m_size > 0 && MemAlloc(m_palin, L"строка проверки на полиндром", m_size + 1) == Ret::Ok) {
            std::wcsncpy(m_palin, xpalin, m_size);
            m_palin[m_size] = L'\0';
        }
    }
    return Ret::Ok;
}

// метод класса проверки на полиндром
auto Palindrome::PalinWchar() -> bool {
    if (!m_palin) {
        MessOut::Warning(L"Сторока не должна быть пустой!!!");
        return false;
    }
    size_t i{0};
    size_t j{wcslen(m_palin) - 1};
    while (i < j) {
        if (m_palin[i] != m_palin[j]) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}
