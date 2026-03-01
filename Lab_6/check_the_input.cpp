#include<iostream>
#include<limits>
#include"errmess.h" // подключаем функций вывода ошибок

// функция на корректность ввода
auto Type_Thecking(short& f_a, const short& f_min, const short& f_max) -> short
{
    while (true)
    {
        if (!(std::wcin >> f_a) || f_a < f_min || f_a > f_max || std::wcin.fail()) // условия для проверки
        {
            errmess::Exeption(L"Вы ввели не верные даные! Попробуйте ещё раз! : ");
            std::wcin.clear(); // обнуляем флаги состояния ошибки потока

            // функция для игнорирования (или отбрасывания) определенного количества символов из буфера ввода
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else  break;
    }
    return f_a;
}
