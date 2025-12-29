#include<iostream>
#include <limits>
#include<string>
#include<iomanip>
#include"constans.h"
#include"stop.h"
#define MAX_LINES 25 // макс. количество строк
#define MAX_LENGTH 80 // макс. длина строки

// прототип типа на std::wstring
using wstr = std::wstring;
size_t arrayLength{0}; // длина массива
// деклорация функции создания массива строк
auto ArrayStr() -> wstr*;
// псевдоним типа указателя на функцию
using PtrFunc = wstr*(*)(wstr*(*)());
// деклорация функции сортировки
auto SelectOfSort (wstr *(* const PtrArray)()) -> PtrFunc;
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
        // вызов функции создания массива строк и сортировки
        SelectOfSort (ArrayStr);

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
        // создание нового массива длиной "количество строк введёное пользователем"
        wstr *newArray = new (std::nothrow) wstr [arrayLength];
        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!newArray) {
            // Обработка этого случая
            std::wcout << L"Память не выделенна!!!";
            return newArray = nullptr; // обнуляем указатель
        }
        // копируем исходный массив в новый
        for (size_t i : *newArray) {
            newArray[i] = arrayOfStrings[i];
        }
        // удаляем исходный массив
        delete [] arrayOfStrings; // освобождаем память
        arrayOfStrings = nullptr; // обнуляем указатель
        return newArray;
    }
}

wstr* (*fcnPtr)() = ArrayStr;

// функция сортировки в алфавитном порядке
auto AlphaOrder (wstr*(*const p_array)())-> wstr* {
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
auto LengthOfLines (wstr*(*const p_array)()) -> wstr* {
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
using PtrFunc = wstr*(*)(wstr*(*)());
// функция проверки ввода
auto Type_Thecking11 ( const short& fr_a) -> short {
    while (true) {
        if ( ! (std::cin >> fr_a)) {
            std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<short>::max(), '\n');
        }
        else break;
    }
    return fr_a;
}
// функция выбора сортировки
auto SelectOfSort (wstr*(*const PtrArray)()) -> PtrFunc {

    std::wcout << L"Выберите способ сортировки 1- в алфавитном порядке\n, 2- по длине строк\n"
                  "Ваш выбор: ";
    short choice;
    std::wcin >> choice;
    switch (choice) {
    case 1: {
        return AlphaOrder(PtrArray);
        break;
    }
    case 2: {
        return LengthOfLines(PtrArray);
        break;
    }
    default:
        std::wcout << L"Такой сортивки не предусмотрено!!!";
        return nullptr;
    }
}
