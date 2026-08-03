#include<iostream>
#include<limits>

bool Exit() {
    std::cout << "Желаете продолжить введите Y, если нет введите N: ";
    char choice;
    while (true) {
        if (!(std::cin >> choice)) {

            // ошибка ввода
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода: Введите Y или N: ";
            continue;
        }

        // преобразуем символ в верхний регистр
        choice = std::toupper(choice);

        if (choice == 'Y') {
            return true;
        } else if (choice == 'N') {
            return false;
        } else std::cout << "Введйн не верный символ! Введите Y или N: ";
    }
}
