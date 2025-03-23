/* подключаем библиотеку для ввода/вывода */
#include<iostream>

// функция для вычесления максимума
int Fun_Max (int param, int setpoint)
{
    std::cout << "максимум = " << (param < setpoint ? setpoint : param) << '\n'; // вывод в терминал результата
    return 0;
}

// функция для вычесления минимума
int Fun_Min (int param, int setpoint)
{
    std::cout << "минимум = " << (param > setpoint ? setpoint : param) << '\n'; // вывод в терминал результата
    return 0;
}

// функция для вычесления максимума
unsigned short Fun_Max (unsigned short param, unsigned short setpoint)
{
    std::cout << "максимум = " << (param < setpoint ? setpoint : param) << '\n'; // вывод в терминал результата
    return 0;
}

// функция для вычесления минимума
unsigned short Fun_Min (unsigned short param, unsigned short setpoint)
{
    std::cout << "минимум = " << (param > setpoint ? setpoint : param) << '\n'; // вывод в терминал результата
    return 0;
}

// функция для вычесления порогового значения по максимуму
int Fun_Max (int param, int setpoint, int porog)
{
    if ((param >= porog) || (setpoint >= porog))
    {
        std::cout << "параметры выше порогового " << porog << '\n'; // вывод в терминал результата
    }
    return 0;
}

// функция для вычесления порогового значения по минимуму
int Fun_Min (int param, int setpoint, int porog)
{
    if ((param <= porog) || (setpoint <= porog))
    {
        std::cout << "параметры ниже порогового " << porog << '\n'; // вывод в терминал результата
    }
    return 0;
}
