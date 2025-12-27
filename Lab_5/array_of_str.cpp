#include<iostream>
#include<string>
#include<iomanip>
#include"constans.h"
#include"stop.h"
#define MAX_LINES 25 // макс. количество строк
#define MAX_LENGTH 80 // макс. длина строки

// прототип типа на std::wstring
using wstr = std::wstring;
// деклорация функции проверки ввода
auto Type_Thecking ( const unsigned short& fr_a) -> unsigned short;
// деклорация функции создания массива строк
auto ArrayStr() -> wstr*;

// функция по заданию №6
auto ArrayOfStr () -> RetConst {

    setlocale(LC_ALL, "ru_RU.UTF8");

    wstr s = L"Задание 6)";
    std::wcout << std::setw(30) << std::right << s << '\n';
    std::wcout << L"Дан массив строк (максимально 25 строк, каждая строка не более 80 символов).\n"
                  "Строки вводятся пользователем, признак завершения ввода – ввод пустой строки.\n"
                  "Упорядочить строки по длине или по алфавиту (по выбору пользователя).\v" << std::endl;

    bool stop {false}; // переменная для цикла do while
    do {
        // вызов функции создания массива строк
        //ArrayStr();

        // вызов функции для останоки или продолжения выполнения программы по выбору пользователя
        if (!(stop == Stop())) return ErrData;
    }
    while (!stop); // выход из праграммы по выбору пользователя
    return Ok;
}

// функция создания массива строк
auto ArrayStr () -> wstr* {
    std::wcout << L"Введите строки но не более 25 строк (после каждого ввода строки нажмите ввод),\n"
                  "каждая строка не более 80 символов (пустая строка — завершение ввода): " << '\n';
    wstr line; // переменная для ввода строк
    size_t arrayLength{0}; // длина массива
    wstr *arrayOfStrings = new (std::nothrow) wstr [MAX_LINES];
    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if (!arrayOfStrings) {
        // Обработка этого случая
        std::wcout << L"Память не выделенна!!!";
        return arrayOfStrings = nullptr; // обнуляем указатель
    }
    else {
        while (arrayLength < MAX_LINES) {
            std::getline(std::wcin, line);
            if (line.empty()) {
                break;
            }
            if (line.length() > MAX_LENGTH) {
                std::wcout << L"Строка слишком длинная (максимум " << MAX_LENGTH << " символов).\n";
                continue;
            }
            arrayOfStrings[arrayLength] = line;
            ++arrayLength;
        }
        wstr *newArray = new (std::nothrow) wstr [arrayLength];
        for (size_t i : *newArray) {
            newArray[i] = arrayOfStrings[i];
        }
        delete [] arrayOfStrings; // освобождаем память
        arrayOfStrings = nullptr; // обнуляем указатель
        return newArray;
    }
}

// функция сортировки в алфавитном порядке
auto AlphaOrder (wstr (*const p_array)())-> wstr* {
    wstr *newArray = p_array();
    for (int i = 0; i < newArray->size() - 1; ++i) {
        for (int j = 0; j < newArray->size() - i - 1; ++j) {
            if (newArray[j] > newArray[j + 1]) {
                std::swap(newArray[j], newArray[j + 1]);
            }
        }
    }
    return newArray;
}

// функция сортировки по длине строк
auto LengthOfLines (wstr (*const p_array)()) -> wstr* {
    wstr *newArray = p_array();
    for (int i = 0; i < newArray->size() - 1; ++i) {
        for (int j = 0; j < newArray->size()- i - 1; ++j) {
            if (newArray[i].length() > newArray[j + 1].length()) {
                std::swap(newArray[j], newArray[j + 1]);
            }
        }
    }
    return newArray;
}

// псевдоним типа указателя на функцию
using PtrFunc = wstr(*)(wstr(*));

// функция выбора сортировки
auto SelectOfSort () -> PtrFunc {

    std::wcout << L"Выберите способ сортировки 1- в алфавитном порядке\n, 2- по длине строк\n"
                  "Ваш выбор: ";
    short choice = (Type_Thecking(choice));
    switch (choice) {
    case 1: {
        return AlphaOrder;
        break;
    }
    case 2: {
        return LengthOfLines;
        break;
    }
    default:
        std::wcout << L"Такой сортивки не предусмотрено!!!";
        return nullptr;
    }
}
