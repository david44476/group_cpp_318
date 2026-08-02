#include <iostream>

enum class ProgrEnum{Task_1, Task_2, Task_3, Task_4, Task_5};
const ProgrEnum progrEnum = ProgrEnum::Task_1;

int main()
{
    if (progrEnum == ProgrEnum::Task_1) {
        void Brutfor();
        Brutfor();
    }
    else if (progrEnum == ProgrEnum::Task_2) {

    }
    else if (progrEnum == ProgrEnum::Task_3) {

    }
    else if (progrEnum == ProgrEnum::Task_4) {

    }
    else if (progrEnum == ProgrEnum::Task_5) {

    } else std::cout << "Задания закончились!!!";
    return 0;
}
