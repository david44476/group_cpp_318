#include<iostream>
#include<time.h>


auto Task_2a () -> void
{
    constexpr short sArray {5};  // переменная для длины массива
    short MyArray [sArray] [sArray];  // создаём массив

    for (short i = 0; i < sArray; ++i)
    {
        for (short j = 0; j < sArray; ++j)
        {
            if (i == j) {MyArray [i] [j] = 1;}

            else {MyArray [i] [j] = 0;}

            std::cout << MyArray [i] [j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "Размер матрици: = " << sizeof (MyArray ) << " байт \n";
}

auto Task_2b () -> void
{
    constexpr short sMatrix {8};  // переменная для длины массива
    short MyMatrix [sMatrix] [sMatrix];  // создаём массив
    short S;  // переменная для суммы элементов матрицы, лежащих выше главной диагонали
    const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    short min = -15;  // переменная для минимального диапазона
    short max = 15;   // переменная для максимального диапазона
    srand (static_cast<unsigned short>(time (nullptr)));

    for (short i = S = 0; i < sMatrix; ++i)
    {
        for (short j = 0; j < sMatrix; ++j)
        {
            short result = static_cast<short>(rand() * fraction * (max - min + 1) + min) ;
            MyMatrix [i] [j] = result;
            std::cout << MyMatrix [i] [j] <<  '\t';
            if (i < j) {S += MyMatrix [i] [j];}
        }
        std::cout << '\n';
    }
    std::cout << "Сумма элементов матрицы, лежащих выше главной диагонали = " << S << '\n';
}
