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
        //std::sort(std::begin(fazaArray), std::end(fazaArray));
        swap(fazaArray);
        print(fazaArray);
    }
}

auto swap(char(&ref_array)[size]) -> void {
    for (auto i{0}; i < size - 4; ++i) {
        if (i == 0) {
            std::swap(ref_array[i + 1], ref_array[i + 2]);
        }
        if (i == 1) {
            std::swap(ref_array[i + 2], ref_array[i]);
        }
        if (i == 2) {
            std::swap(ref_array[i + 1], ref_array[i]);
        }
    }
}

auto print (char(&ref_array)[size]) -> void {
    for (auto k : ref_array) {
        std::cout << k << ' ';
    }
    std::cout << std::endl;
}
