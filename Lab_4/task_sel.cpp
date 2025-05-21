#include<iostream>
#include<random>
#include<time.h>
#include"progr_enum.h"
#include"functions.h"
void Task_Sel (ProgrEnum progrEnum1)
{
    if  (progrEnum1 == ProgrEnum::Task_1)
    {
        std::cout << "\t Задание № 1\n" << "Вывод элементов массива с "
                           "минимальным и максимальным значениями \n";


        std::random_device rd;
        std::mt19937 mersenne (rd ());

        constexpr  short arraySize = 10;
        short iArray [arraySize];
        short min = *iArray;
        short max = *iArray;

        for (short i = 0; i < arraySize; i++)
        {
            iArray [i] = (static_cast< short>(mersenne()));
            std::cout << iArray [i] <<  '\n';
            if ( *(iArray + i) < min) {min = *(iArray + i);}

            if ( *(iArray + i)  > max) {max = *(iArray + i) ;}
        }
        std::cout << "Минимальное значение = " << min << '\n'
                      << "Максимальное значение = " << max << '\n'
                      << "Размер массива = " << sizeof (iArray) << " байт" << '\n';
    }


    else if  (progrEnum1 == ProgrEnum::Task_2)
    {
        std::cout << "\t Задание 2.a)" << '\n' << "Вывод единичной матрици" << '\n';

        constexpr short strArray {5};
        constexpr short stArray {5};
        short myArray [strArray] [stArray];

        for (short i = 0; i < strArray; ++i)
        {
            for (short j = 0; j < stArray; ++j)
            {
                if (i == j) {myArray [i] [j] = 1;}

                else {myArray [i] [j] = 0;}

                std::cout << myArray [i] [j] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << "Размер матрици: = " << sizeof (myArray ) << " байт \n";


        std::cout << "\t Задание 2.b)" << '\n' << "Находим сумму элементов матрицы, "
                                                  "лежащих выше главной диагонали:\n\t квадратная матрица 8*8\n";

        constexpr short strMatrix {8};
        constexpr short stlMatrix {8};
        short myMatrix [strMatrix] [stlMatrix];
        short S;
        srand (static_cast<unsigned int>(time (nullptr)));

        for (short i = S = 0; i < strMatrix; ++i)
        {
            for (short j = 0; j < stlMatrix; ++j)
            {
                short result = -15 + rand () % 15;
                myMatrix [i] [j] = result;
                std::cout << myMatrix [i] [j] <<  '\t';
                if (i < j) S += myMatrix [i] [j];
            }
            std::cout << '\n';
        }
        std::cout << "Сумма элементов матрицы, лежащих выше главной диагонали = " << S << '\n';
    }


    else if  (progrEnum1 == ProgrEnum::Task_3)
    {
        std::cout << "\t Задание 3" << '\n' << "Алфавит английского языка" << '\t' << "Десятичный код символа" << '\n';

        char c;
        for ( c = 'A'; c <= 'Z'; ++c)
        {
            std::cout << '\t' << c << "\t\t\t\t" << static_cast<int>(c) << '\n';
        }
    }


    else if (progrEnum1 == ProgrEnum::Task_4)
    {
        std::cout << "\t Задание 4.а)" << '\n' << "Находим факториал с помощью рекурсии и итерации" << '\n' << "Введите целое число: ";

        short n {};
        n = Type_Thecking(n);  // проверка на коректность ввода
        std::cout << "Факториал найденный с помощью итераций = " << FacIter (n) << '\n';
        std::cout <<  "Факториал найденный с помощью рекурсии = " << FacRec (n) << '\n';


        std::cout << "\t Задание 4.б)" << '\n' << "находим Число Фибоначчи, соответствующее заданному числу пользователя" << '\n';

        int i {};
        int a {};
        int b {1};
        int c {0};
        std::cout << "Введите целое число: ";
        short q {};
        q = Type_Thecking(q);  // проверка на коректность ввода
        std::cout << "Число Фибоначчи, соответствующее заданному числу пользователя" << '\n';
        while (i < q)
        {
            a = b;
            b = c;
            c = a + b;
            std::cout << static_cast<unsigned>(c) << ' ';
            i++;
        }
        std::cout << '\n';
    }
}
