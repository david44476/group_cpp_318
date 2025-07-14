#include<iostream>
#include"task_6.h"
#include <iomanip>
#include"type_thecking.h"

// функция для задания 6а
auto Task_6a() -> void{
    std::cout << "\t Задание 6a) " << '\n';
    std::cout << "Введите значение для переменной m от -32768 до 32767:";
    short m;
    m= Type_Thecking(m);
    std::cout << "Введите значение для переменной fx от 1.7 * 10^308 до 1.7 * 10^308:";
    double fx;
    fx = Type_Thecking(fx);
    std::cout << "Введите значение для переменной cht от A до Z в любом регистре:";
    char cht;
    cht = Char_Type_Thecking(cht);

    std::cout << "\vЗначение переменной m = " <<  m << '\n'
              << "Значение переменной fx = " << setiosflags(std::ios::fixed)<< fx << '\n'
              << "Значение переменной cht = " << cht << '\n';

    std::cout << "\vИспользование & оператор:" << '\n'
              << "Адрес переменной m = " << &m << '\n'
              << "Адрес переменной fx = " << &fx << '\n'
              << "Адрес переменной cht = " << static_cast<void*>(&cht) << '\n';

    std::cout << "\vИспользуя операторы & и *:" << '\n';
    short *ptrm{&m};  // указатель на переменную m
    double *ptrfx{&fx};  // указатель на переменную fx
    char *ptrcht{&cht};  // указатель на переменную cht
    std::cout << "значение по адресу переменной m " << &m << " = " << *ptrm << '\n'
              << "значение по адресу переменной fx " << &fx << " = " << *ptrfx << '\n'
              << "значение по адресу переменной cht " << static_cast<void*>(&cht)<< " = " << *ptrcht << '\n';

    std::cout << "\vИспользуя только переменную указателя:" << '\n'
              << "адрес переменной m = " << *&ptrm << '\n'
              << "адрес переменной fx = " << *&ptrfx  << '\n'
              << "адрес переменной cht = " << static_cast<void*>(*&ptrcht) << '\n';

    std::cout << "\vИспользование только оператора указателя:" <<'\n'
              << "значение по адресу переменной m = "<< ptrm << " = " << *ptrm << '\n'
              << "значение по адресу переменной fx = " << ptrfx << " = " << *ptrfx << '\n'
              << "значение по адресу переменной cht = " << static_cast<void*>(ptrcht) << " = " << *ptrcht << '\n';
}

// функция для задания 6b
auto Task_6b() -> void{
std::cout << "\v\t Задание 6b)" << '\n';
    using pFunc = void(*)(void*, const size_t&);
    pFunc pRanNumGen= RanNumGen; // указатель на функцию генерации случайных чисел
    pFunc pPrinArray = PrinArray;  // указатель на функцию вывода массива
    constexpr short max_length{10};  // максимальное количиство считываемых символов
    static size_t arraySize; // переменная для длины массива по выбору пользователя
    short sizeMin{1};  // переменная для проверки ввода длины массива
    short sizeMax{10};  // переменная для проверки ввода длины массива
    // Вводим размер массива с проверками корректности
    std::cout << "\vВведите число для длины массива от 1 до 10 : ";
    arraySize = static_cast<size_t>(Type_Thecking(arraySize, sizeMin, sizeMax));

    short array[max_length];
    pRanNumGen(array, arraySize);
    pPrinArray(array, arraySize);
}

// функция для генерации случайных чисел
auto RanNumGen(void *xpArray, const size_t& size) -> void {

    srand(static_cast<unsigned int>(time(nullptr)));
    double fraction{1.0 / (static_cast<double>(RAND_MAX) + 1.0)};
    short min{1};
    short max{100};
    bool alreadyThere;
    // Равномерное распределение случайного числа в диапазоне от min до max
    for (size_t i{0}; i < size; ++i) {
        short *pdata =  static_cast<short*>(xpArray);
        // Равномерное распределение случайного числа в диапазоне от min до max
        for (size_t i{0}; i < size;) {
            alreadyThere = false;
            short newRandNum = static_cast<short>((rand() * fraction * (max - min + 1) + min));
            // цикл для заполнения массива уникальными значениями
            for (size_t k{0}; k < i; ++k) {
                if (pdata[k] == newRandNum) {
                    alreadyThere = true;
                }
            }
            if (!alreadyThere) {
                pdata[i] = newRandNum;
                ++i;
            }
        }
    }
}

// функция для вывода массива
auto PrinArray(void *xpArray, const size_t& size) -> void {
    short *Array = static_cast<short*>(xpArray);

    std::cout << "элемент ";
    for (size_t i{0}; i < size; ++i) {
        std:: cout << '\t' << '[' << i << ']' << '\t';
    }
    std::cout << '\n' << '\v';

    std::cout << "значение =  ";
    for (size_t i{0}; i < size; ++i) {
        std:: cout << '\t' << Array[i] << ' ' << '\t';
    }
    std::cout << '\n' << '\v';

    std::cout << "адрес ";
    for (size_t i{0}; i < size; ++i) {
        std:: cout << '\t' << &Array[i] << ' ';
    }
    std::cout << '\n' << '\v';

    for (size_t i{0}; i < size; ++i) {
        std::cout << "ptr [" << i << ']' << " адрес " << &Array[i] << " значение = " << Array[i] << "\t\t"
                  << "*ptr [" << i << ']' << " адрес " << &*(Array + i) << " значение = " << *(Array + i) << '\n';
    }
}
