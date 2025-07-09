#include<iostream>

// функция для нахождения Факториала с помощью итерации
auto FacItr (short a) -> unsigned long long {
    long long fact {1};

    for (int i {1}; i <=a; i++) {
        fact = fact * i;
    }
    return static_cast<unsigned long long>(fact);
}

// функция для нахождения Факториала с помощью рекурсии
auto FacRec (short a) ->unsigned long long {
    if (a > 1) {
        return static_cast<unsigned long long>(a)* FacRec(a -1);
    }
    return 1;
}


// функция для нахождения числа Фибоначчи с помощью итерации
auto Fibonacci() -> void {
#include<type_thecking.h>
    int i {};
    int a {};
    int d {1};
    int c {0};
    std::cout << "Введите целое число: ";
    short q {};
    q = Type_Thecking(q);  // проверка на коректность ввода
    std::cout << "Число Фибоначчи, соответствующее заданному числу пользователя" << '\n';
    while (i < q) {
        a = d;
        d = c;
        c = a + d;
        std::cout << static_cast<unsigned>(c) << ' ';
        i++;
    }
    std::cout << std::endl;
}


#include<math.h>
auto Pyramid(short b) -> void {
    int number = static_cast<int>((-1 + sqrt(1 + 4 * 2 * b)) / 2);
    for (int i = 1, sum; i <= number; ++i) {
        sum = 0;
        for (int k = number; k > i; --k) {
            std::cout << ' ';
        }
        std::cout << ' ';
        for (int j = 1; j <= i; ++j) {
            std::cout << j << ' ';
            sum += j;
        }
        std::cout << ' ' << sum << std::endl;
    }
}
