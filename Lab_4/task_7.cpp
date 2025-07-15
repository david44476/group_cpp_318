#include<iostream>
#include <algorithm>
#include"task_7.h"

auto Faza() -> void {

    char fazaArray[size] = {'A','B','C','N'};

    std::cout << "Начальное подключении обмоток для 3х-фазного двигателя A, B, C, N ; где N нулевой провод" << '\n';
    for (auto i{0}; i < size -1; ++i) {
        std::cout << "фаза " << fazaArray[i] << '\n';
    }
    std::cout << "нулевой провод " << fazaArray[3] << '\n';

    std::cout << "варианты подключении обмоток для 3х-фазного двигателя" << '\n';
    for (auto i{0}; i < size; ++i) {
        swap(fazaArray);
        print(fazaArray);
    }
}

auto swap(char(&ref_array)[size]) -> void {
    for (auto i{0}, j{1}; i < size - 1; ++i, ++j) {
        char s = ref_array[i];
        ref_array[i] = ref_array[i];
        ref_array[i] = s;
    }
}

auto print (char(&ref_array)[size]) -> void {
    for (auto k : ref_array) {
        std::cout << k << ' ';
    }
    std::cout << std::endl;
}
