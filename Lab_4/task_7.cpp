#include<iostream>
#include <algorithm>
#include"task_7.h"

auto Faza() -> void {
    
    char fazaArray[size] = {'A','B','C','N', '\0'};
    
    std::cout << "Начальное подключении обмоток для 3х-фазного двигателя A, B, C, N ; где N нулевой провод" << '\n';
    for (auto i{0}; i < size -1; ++i) {
        std::cout << "фаза " << fazaArray[i] << '\n';
    }
    std::cout << fazaArray[3] << ' ' << "нулевой провод" << '\n';
    
    std::cout << "\vВарианты подключении обмоток для 3х-фазного двигателя" << '\n';
    for (auto i{1}; i < size + 2; ++i) {
        std::cout << "\tВариант № " << i << '\n';
        swap(fazaArray);
        print(fazaArray);
    }
}

// функция для перестановки символов в массиве
auto swap(char(&ref_array)[size]) -> void {
    for (auto x{0} ;x < size; ++x){
        std::next_permutation(std::begin(ref_array), std::end(ref_array) - 2);
    }
}

// функция для вывода массива
auto print (char(&ref_array)[size]) -> void {
    for (auto k : ref_array) {
        std::cout << k << ' ';
    }
    std::cout << std::endl;
}

