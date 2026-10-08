#include <iostream>
#include "c_complexNum.h"

auto ComlexNum()-> void {
    std::wcout << L"=== Комплексные числа ===" << L'\n';

    Complex a(3.0, 4.0);
    Complex b(1.0, -2.0);

    std::wcout << L"a = " << a << L'\n';
    std::wcout << L"b = " << b << L'\n';
    std::wcout << L'\n';

    // Арифметика
    std::wcout << L"a + b = " << (a + b) << L'\n';
    std::wcout << L"a - b = " << (a - b) << L'\n';
    std::wcout << L"a * b = " << (a * b) << L'\n';
    std::wcout << L"a / b = " << (a / b) << L'\n';
    std::wcout << L"сопряжённое a = " << a.conjugate() << L'\n';
    std::wcout << L'\n';

    // Модуль и аргумент
    std::wcout << L"|a| = " << a.modulus() << L'\n';
    std::wcout << L"arg(a) = " << a.argument() << L" рад" << L'\n';
    std::wcout << L'\n';

    // Возведение в степень
    std::wcout << L"a^3 (целая степень) = " << a.power(3) << L'\n';
    std::wcout << L"a^2.5 (вещественная) = " << a.powerDouble(2.5) << L'\n';
    std::wcout << L"a^(-1) = " << a.power(-1) << L'\n';
    std::wcout << L'\n';

    // Извлечение корня
    std::wcout << L"Корни 3-й степени из a:" << L'\n';
    auto roots = a.root(3);
    for (size_t i = 0; i < roots.size(); ++i)
        std::wcout << L"  z" << i << L" = " << roots[i] << L'\n';
    std::wcout << L'\n';

    // Формы записи
    std::wcout << L"Формы записи числа a = " << a.toAlgebraic() << L":" << L'\n';
    std::wcout << L"  Алгебраическая:   " << a.toAlgebraic() << L'\n';
    std::wcout << L"  Тригонометрическая: " << a.toTrigonometric() << L'\n';
    std::wcout << L"  Экспоненциальная:  " << a.toExponential() << L'\n';
    std::wcout << L'\n';

    std::wcout << L"Формы записи числа b = " << b.toAlgebraic() << L":" << L'\n';
    std::wcout << L"  Алгебраическая:   " << b.toAlgebraic() << L'\n';
    std::wcout << L"  Тригонометрическая: " << b.toTrigonometric() << L'\n';
    std::wcout << L"  Экспоненциальная:  " << b.toExponential() << L'\n';
}
