#include<iostream>
#include <algorithm>// содержит прототип функции sort()
#include"task_7.h"

auto Faza() -> void {
    char fazaArray[size] = {'A','B','C','N'};
    // Упорядочиваем при помощи библиотечной  функции
    //std::sort(std::begin(fazaArray), std::end(fazaArray));

    for (auto& i : fazaArray) {
        std::cout << i;
    }
    std::cout << '\n';
}
