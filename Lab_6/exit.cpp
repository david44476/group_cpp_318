#include<iostream>
#include<limits>

#include<iostream>
#include<limits>

bool Exit() {
    std::wcout << std::wstring(90, '-') << '\n';
    std::wcout << L"Желаете продолжить введите Y, если нет введите N: ";
    wchar_t choice;
    while (true) {
        if (!(std::wcin >> choice)) {

            // ошибка ввода
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::wcout << L"Ошибка ввода: Введите Y или N: ";
            continue;
        }

        // преобразуем символ в верхний регистр
        choice = std::towupper(choice);

        if (choice == L'Y') {
            return true;
        } else if (choice == L'N') {
            return false;
        } else std::wcout << L"Введйн не верный символ! Введите Y или N: ";
    }
}
