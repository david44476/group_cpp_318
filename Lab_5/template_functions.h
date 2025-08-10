#ifndef TEMPLATE_FUNCTIONS_H
#define TEMPLATE_FUNCTIONS_H
#include<iostream>
#include <random>
#include<ctime>
#include<limits>
#include <algorithm>

// шаблонная функция для нахождения максимального и минимального значения в массиве
template <typename T, typename D>
auto MinMax (T *fp_Array, const D& fr_size) -> void {
    T min{(*fp_Array)};
    T max{(*fp_Array)};
    for (auto i{0}; i < fr_size; ++i) {
        if ( *(fp_Array + i) < min) {min = *(fp_Array + i);}  // находим минимальное значение
        if ( *(fp_Array + i) > max) {max = *(fp_Array + i);}  // находим максимальное значение
    }
    std::cout << "минимальное число : " << min << '\n';
    std::cout << "максимальное число : " << max << '\n';
    std::cout << std::endl;
}


// шаблонная функция для вывода массива
template <typename T, typename D>
auto PrintArray (const T *fp_Array, const D& fr_size) -> void {
    for (auto i{0}; i < fr_size; ++i) {
        std::cout << fp_Array[i] << ' ';
    }
    std::cout << std::endl;
}


// шаблонная функция для вывода массива с номером элемента и его значением
template <typename T, typename D>
auto PrintArray2 (const T *fp_Array, const D& fr_size, const char* fp_str) -> void {
    std::cout << fp_str << "\n";
    for (auto i{0}; i < fr_size; ++i) {
        std::cout << "элемент [" << i << ']' << " значение " << fp_Array[i] << '\n';
    }
    std::cout << std::endl;
}


// функция для вывода массива с номером элемента его адресом и значением
template <typename T, typename D>
auto ArrayPrint (const T *fp_array, const D& fr_size, const char *fp_str) ->void {
    std::cout << fp_str << "\n";
    // перебираем элементы массива в цикле и выводим в консоль
    for (auto i{0}; i < fr_size; ++i) {
        std::cout << "адрес элемента [ " << i << " ]: " << fp_array + i
                  << " и значение = " << fp_array[i] << '\n';
    }
}


// шаблонная функция для заполнения массива Вихрем Мерсена
template <typename T, typename D>
auto MersWhir (T *fp_Array, const D& fr_size) -> void {
    // генерируем случайные числа
    std::random_device rd;
    std::mt19937 mers(rd());
    bool alreadyThere;
    for (auto i{0}; i < fr_size; ++i) {
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (auto i{0}; i < fr_size;) {
            alreadyThere = false;
            T newRandNum = static_cast<T>(mers());
            // цикл для заполнения массива уникальными значениями
            for (auto k{0}; k < i; ++k) {
                if (fp_Array[k] == newRandNum) {
                    alreadyThere = true;
                }
            }
            if (!alreadyThere) {
                fp_Array[i] = newRandNum;
                ++i;
            }
        }
    }
}


//шаблонная функция для своего генератора случайных чисел с диапазоном максимального и минимального значения
template <typename T, typename D>
auto MyGen (T *fp_Array,const D& fr_size, const D& fr_Gmin, const D& fr_Gmax) -> void {
    bool alreadyThere;
    srand(static_cast<unsigned int>(time(nullptr)));
    double fraction{1.0 / (static_cast<double>(RAND_MAX) + 1.0)};
    // Равномерное распределение случайного числа в диапазоне от min до max
    for (auto i{0}; i < fr_size; ++i) {
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (auto i{0}; i < fr_size;) {
            alreadyThere = false;
            T newRandNum = static_cast<T>((rand() * fraction * (fr_Gmax - fr_Gmin + 1) + fr_Gmin));
            // цикл для заполнения массива уникальными значениями
            for (auto k{0}; k < i; ++k) {
                if (fp_Array[k] == newRandNum) {
                    alreadyThere = true;
                }
            }
            if (!alreadyThere) {
                fp_Array[i] = newRandNum;
                ++i;
            }
        }
    }
}


// шаблонные функции для проверка на коректность ввода
template <typename T>
auto Type_Thecking (const T& f_a, T& fr_min, T& fr_max) -> T {
    while (true) {
        if ( ! (std::cin >> f_a) || f_a < fr_min || f_a > fr_max || f_a == ' ') {
            std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<T>::max(), '\n');
        }
        else break;
    }
    return f_a;
}


template <typename T>
auto Type_Thecking ( const T& fr_a) -> T {
    while (true) {
        if ( ! (std::cin >> fr_a)) {
            std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<T>::max(), '\n');
        }
        else break;
    }
    return fr_a;
}
//////////////////////////////////////////////////////////////////////////


// шаблоннфя функция для сортировки массива
template <typename T, typename D>
auto InsertionSort (T *fp_Array, const D& fr_size, bool (*fp_comparisonFcn)(short, short)) -> void {
    for(short i{0}; i < fr_size; ++i) {
        short j = i;
        while(j < fr_size) {
            if (comparisonFcn(fp_Array[i], fp_Array[j]))
                std::swap(fp_Array[i], fp_Array[j]);
            ++j;
        }
    }
}
#endif // TEMPLATE_FUNCTIONS_H
