#include<iostream>
#include<iomanip>
#include"Claboratory.h"
#include"errmess.h"
#include"check_the_input.h"
#include"constans.h"
#include"denamic_objects.h"

// установка полей класса
auto Claboratory::WrClaboratory(const wstr& f_labWorkNum, const wstr& f_topicLabWork,
                                const wstr& f_objecLabWork) -> void {

    // устанавливаем номер лабораторной работы
    if (!f_labWorkNum.empty()) {
        m_labWorkNum = new (std::nothrow) wstr{f_labWorkNum};

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        MemoError(m_labWorkNum);
    }

    // устанавливаем тему лабораторной работы
    if (!f_topicLabWork.empty()) {
        m_topicLabWork = new (std::nothrow) wstr{f_topicLabWork};

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        MemoError(m_topicLabWork);
    }

    // устанавливаем цели лабораторной работы
    if (!f_objecLabWork.empty()) {
        m_objecLabWork = new (std::nothrow) wstr{f_objecLabWork};

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        MemoError(m_objecLabWork);
    }
}

// вывод информации по лабараторной работе
auto Claboratory::PrintLab() -> void {
    std::wcout << std::setw (30) << std::right << *m_labWorkNum + *m_topicLabWork +
               *m_objecLabWork + m_devLabWork + m_os + m_locale;
}

// функция выбора задания
auto Claboratory::TaskSelection(const short& f_choice) -> const short {

    // выбор задания
    switch (f_choice) {
    case 1: {
        errmess::Info(L"Вы выбрали задание № 1\n");
        return static_cast<short>(ProgrEnum::Task_1);
        break;
    }
    case 2: {
        errmess::Info(L"Вы выбрали задание № 2\n");
        return static_cast<short>(ProgrEnum::Task_2);
        break;
    }
    case 3: {
        errmess::Info(L"Вы выбрали задание № 3\n");
        return static_cast<short>(ProgrEnum::Task_3);
        break;
    }
    case 4: {
        errmess::Info(L"Вы выбрали задание № 4\n");
        return static_cast<short>(ProgrEnum::Task_4);
        break;
    }
    case 5: {
        errmess::Info(L"Вы выбрали задание № 5\n");
        return static_cast<short>(ProgrEnum::Task_5);
        break;
    }
    }
    return static_cast<short>(ProgrEnum::Task_Max);
}

// функция для останоки или продолжения выполнения программы по выбору пользователя
auto Claboratory::StopLab() -> bool {
    bool  stop {false};

    // запрос пользователю на выбор действия
    errmess::Info(L"Хотите продолжить введите 'Д', а если хотите прекратить 'Н' и нажмите ввод: ");
    wchar_t choice = {Type_Thecking(choice)}; // проверка на корректность ввода;

    // условие для действия по выбору пользователя
    if (choice == L'Д' || choice == L'д') stop = false;

    else if (choice == L'Н' || choice == L'н') stop = true;
    return stop;
}

// функция вывода номера и текста задания
auto Claboratory::Ctask::printTask() -> void {
    std::wcout << std::setw (30) << std::right << m_task << '\n' << m_taskText;
}
