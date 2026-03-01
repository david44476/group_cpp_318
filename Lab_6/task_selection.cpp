#include"constans.h"
#include"errmess.h"

// функция выбора задания
auto TaskSelection(const short& f_choice) -> ProgrEnum {

    // выбор задания
    switch (f_choice) {
    case 1: {
        errmess::Info(L"Вы выбрали задание № 1\n");
        return ProgrEnum::Task_1;
        break;
    }
    case 2: {
        errmess::Info(L"Вы выбрали задание № 2\n");
        return ProgrEnum::Task_2;
        break;
    }
    case 3: {
        errmess::Info(L"Вы выбрали задание № 3\n");
        return ProgrEnum::Task_3;
        break;
    }
    case 4: {
        errmess::Info(L"Вы выбрали задание № 4\n");
        return ProgrEnum::Task_4;
        break;
    }
    case 5: {
        errmess::Info(L"Вы выбрали задание № 5\n");
        return ProgrEnum::Task_5;
        break;
    }
    }
    return ProgrEnum::Task_0;
}
