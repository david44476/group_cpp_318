#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include "constans.h"
#include "stop.h"

#define MAX_LINES 25 // максимальное количество строк
#define MAX_LENGTH 80 // максимальна длина строки

// псевдоним типа
using wstr = std::wstring;

// структура функций для создания и сортировки массива строк
struct S_FuncStr {

    // функция создания массива строк
    auto ArrayStr(short& fr_size) -> wstr* {
        wstr line; // переменная для ввода строк

        // создание денамического массива строк
        wstr* arrayOfStrings = new (std::nothrow) wstr[MAX_LINES];

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!arrayOfStrings) {

            // Обработка этого случая
            std::wcout << L"Память не выделена!\n";
            return nullptr;
        }

        fr_size = 0; // длина массива
        while (fr_size < MAX_LINES) {
            std::getline(std::wcin, line);
            if (line.empty()) break;
            if (line.length() > MAX_LENGTH) {
                std::wcout << L"Строка слишком длинная (максимум " << MAX_LENGTH << L" символов).\n";
                continue;
            }

            // присваемаем элементам массива строки введёные пользователем
            arrayOfStrings[fr_size++] = line;
        }

        // создание нового денамического массива длиной "количество введёных строк"
        wstr* newArray = new (std::nothrow) wstr[fr_size];

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!newArray) {

            // Обработка этого случая
            std::wcout << L"Память не выделена!\n";
            delete[] arrayOfStrings; // освобождаем память
            return nullptr;
        }

        // копируем исходный массив в новый
        for (size_t i {0}; i < fr_size; ++i) {
            newArray[i] = arrayOfStrings[i];
        }
        delete[] arrayOfStrings; // освобождаем память исходного массива
        arrayOfStrings = nullptr; // обнуляем указатель на исходный массив
        return newArray; // возврощаем указатель на новый массив
    }

    // функция сортировки в алфавитном порядке
    auto AlphaOrder(wstr* fp_Array, const size_t& fr_size) -> void {
        for (size_t i {0}; i < fr_size - 1; ++i) {
            for (size_t j = 0; j < fr_size - i - 1; ++j) {
                if (fp_Array[j] > fp_Array[j + 1]) {
                    std::swap(fp_Array[j], fp_Array[j + 1]);
                }
            }
        }
    }

    //функция сортировки по длине строк
    auto LengthOfLines(wstr* fp_Array, const size_t& fr_size) -> void {
        for (size_t i {0}; i < fr_size - 1; ++i) {
            for (size_t j = 0; j < fr_size - i - 1; ++j) {
                if (fp_Array[j].length() > fp_Array[j + 1].length()) {
                    std::swap(fp_Array[j], fp_Array[j + 1]);
                }
            }
        }
    }

    // функция сортировки по выбору пользователя
    auto SelectOfSort(wstr* fp_Array, const size_t& fr_size, const wchar_t& choice) -> void {
        switch (choice) {
        case '1':

            // вызов фукнции сортировки в алфавитном порядке
            AlphaOrder(fp_Array, fr_size);
            break;
        case '2':

            // вызов фукнции сортировки по длине строк
            LengthOfLines(fp_Array, fr_size);
            break;
        default:
            std::wcout << L"Такой сортировки не предусмотрено!\n";
        }
    }

    //функция вывода массива строк
    auto PrintArraySTR(const wstr* fp_Array, const size_t& fr_size) -> void {
        for (size_t i {0}; i < fr_size; ++i) {
            std::wcout << fp_Array[i] << ',';
        }
        std::wcout <<std::endl;
    }

    // функция проверки ввода символа
    auto Type_Thecking1 ( wchar_t& fr_a) -> wchar_t {
        while (true) {
            if ( ! (std::wcin >> fr_a)) {
                std::cout << "Вы ввели не верные даные!" << '\n' << "Попробуйте ещё: ";
                std::cin.clear ();
                std::cin.ignore (std::numeric_limits<wchar_t>::max(), '\n');
            }
            else break;
        }
        return fr_a;
    }

    // указатель на структуру функций
} *StrFunc{nullptr};

// функция по заданию №6
auto ArrayOfStr() -> RetConst {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    wstr s = L"Задание 6)";
    std::wcout << std::setw(30) << std::right << s << '\n';
    std::wcout << "Дан массив строк (максимально 25 строк, каждая строка не более 80 символов).\n"
                  "Строки вводятся пользователем, признак завершения ввода – ввод пустой строки.\n"
                  "\v";

    short arrayLength {0}; // длина массива
    bool stop = false; // переменная для цикла while

    do {
        std::wcout << L"Введите строки (не более 25), каждая не длиннее 80 символов.\n"
                      "Пустая строка — завершение ввода:\n";

        // вызов функции создания массива строк
        wstr* newArray = StrFunc->ArrayStr(arrayLength);
        if (!newArray) {
            std::wcout << L"Ошибка выделения памяти!\n";
            return ErrData;
        }

        std::wcout << L"Неотсортированный массив:\n";

        // вызов функции вывода массива строк
        StrFunc->PrintArraySTR(newArray, arrayLength);

        std::wcout << L"Выберите способ сортировки:\n"
                      "1 — по алфавиту\n"
                      "2 — по длине строк\n"
                      "Ваш выбор: ";

        // проверка ввода
        wchar_t choice = (StrFunc->Type_Thecking1(choice));

        // вызов функции сортировки массива строк по выбору пользователя
        StrFunc->SelectOfSort(newArray, arrayLength, choice);

        std::wcout << L"Отсортированный массив:\n";

        // вызов функции вывода массива строк
        StrFunc->PrintArraySTR(newArray, arrayLength);

        delete[] newArray; // освобождаем память
        newArray = nullptr; // обнуляем указатель

        if (!(stop == Stop())) return ErrData;
    } while (!stop);

    return Ok;
}
