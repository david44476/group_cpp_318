#include<codecvt>
#include<iostream>
#include<clocale>
#include<string>
#include<limits>
#include<iomanip>
#include"errmess.h"
#include"C_labWork.h"
#include"denamic_objects.h"

// конструктор без параметров
C_labWork::C_labWork() {
    std::wcout << L"конструктор вызвался\n";
    (this->*PWrlabWork)();
}

// конструктор с параметрами
C_labWork::C_labWork(const wstr& f_devLop, const wstr& f_group) {
    m_devLop.s_devLop = f_devLop;
    m_devLop.s_group = f_group;

    // устанавливаем переменную номер лабораторной работы
    (this->*PWrLabWorkNum)();

    // устанавливаем тему лабораторной работы
    (this->*PWrTopLabWork)();

    // устанавливаем цели лабораторной работы
    (this->*PWrObjLabWork)();

    // устанавливаем операционную систему лабораторной работы
    (this->*PWrOperSystem)();

    // устанавливаем локаль(кодировка) лабораторной работы
    (this->*PWrLoc)();
}

// устанавливаем поля класса
void C_labWork::WrlabWork() {

    // устанавливаем переменную номер лабораторной работы
    (this->*PWrLabWorkNum)();

    // устанавливаем тему лабораторной работы
    (this->*PWrTopLabWork)();

    // устанавливаем цели лабораторной работы
    (this->*PWrObjLabWork)();

    // устанавливаем операционную систему лабораторной работы
    (this->*PWrOperSystem)();

    // устанавливаем локаль(кодировка) лабораторной работы
    (this->*PWrLoc)();

    // устанавливаем разработчика лабораторной работы
    (this->*PWrDevLop)();

    // устанавливаем группу разработчика лабораторной работы
    (this->*PWrGroup)();
}

// устанавливаем переменную номер лабораторной работы
void C_labWork::WrLabWorkNum() {
    std::wcout << L"Введите номер лабораторной работы и нажмите ввод: ";
    m_titlePage.s_labWorkNum = new (std::nothrow)ushort;
    MemoError(m_titlePage.s_labWorkNum);
    ushort p_str{C_labWork::TypeThecking(p_str)};
    m_titlePage.s_labWorkNum = &p_str;
}

// устанавливаем тему лабораторной работы
void C_labWork::WrTopLabWork() {
    std::wcout << L"Введите тему лабораторной работы например \"Исследование С++ классов в IDE Qt Creator\""
                  " и нажмите ввод: " ;
    std::getline(std::wcin, m_titlePage.s_topLabWork);
}

// устанавливаем цели лабораторной работы
void C_labWork::WrObjLabWork() {
    std::wcout << L"Введите цели лабораторной работы строго через ';' например: "
                  "1.Закрепить на практике представление о классах;\n"
                  "2.Научиться инкапсулировать данные в классах языка С++. "
                  "и нажмите ввод: ";
    while (std::getline(std::wcin, m_titlePage.s_objLabWork)) {
        (this->*PReplaceAll)(m_titlePage.s_objLabWork, L";", L"\n"); // заменяем ';' на '\n'
        break;
    }
}

// устанавливаем операционную систему лабораторной работы
void C_labWork::WrOperSystem() {
    m_titlePage.s_operSystem = {(this->*PGetOsName)()};
}

// устанавливаем локаль(кодировка) лабораторной работы
void C_labWork::WrLoc() {
m_titlePage.s_loc = (this->*PLocToWstr)(std::setlocale(LC_ALL, nullptr));
}

// устанавливаем разработчика лабораторной работы
void C_labWork::WrDevLop() {
std::wcout << L"Введите фамилию имя отчество разработчика лабораторной работы например: "
              "Давыдов Денис Владимирович и нажмите ввод: ";
std::getline(std::wcin, m_devLop.s_devLop);
}

// устанавливаем группу разработчика лабораторной работы
void C_labWork::WrGroup() {
std::wcout << L"Введите группу разработчика лабораторной работы например: "
              "\"cpp_318\" и нажмите ввод: ";
std::getline(std::wcin, m_devLop.s_group);
}

// устанавливаем переменную номер задания
void C_labWork::WrTask() {
    std::wcout << L"Ведите номер задания от " << static_cast<ushort>(ProgrEnum::Task_2) << L" до "
               <<  static_cast<ushort>(ProgrEnum::Task_Max) << L" и нажмите ввод: ";
    m_task.s_taskNum = (this->*PTypeThecking1)(m_task.s_taskNum, static_cast<ushort>(ProgrEnum::Task_2),
                                    static_cast<ushort>(ProgrEnum::Task_Max));
}

// читаем переменную номер задания
const ushort& C_labWork::RdTask() const {return m_task.s_taskNum;}

// устанавливаем текс задания
void C_labWork::WrTaskText(const wstr& f_taskText) {
    if (!f_taskText.empty()) {
        m_task.s_taskText = f_taskText;
    }
}

// функция замены символов
void C_labWork::ReplaceAll(wstr& f_str, const wstr& f_from, const wstr& f_to) {
    size_t start_pos = 0;
    while ((start_pos = f_str.find(f_from, start_pos)) != wstr::npos) {
        f_str.replace(start_pos, f_from.length(), f_to);
        start_pos += f_to.length();  // учитываем длину замены
    }
}

// функция преобразования локали в std::wstring
wstr C_labWork::LocToWstr(const char* input) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(input);
}

// функция выбора задания
const ProgrEnum C_labWork::TaskSelec(const ushort& f_choice) const {

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
    return ProgrEnum::Task_Max;
}

// функция проверка на корректность ввода номера лабораторной работы
const ushort& C_labWork::TypeThecking(ushort& f_a) const  {
    while (true)
    {
        if (!(std::wcin >> f_a) || std::wcin.fail()) // условия для проверки
        {
            errmess::Exeption(L"Вы ввели не верные даные! Попробуйте ещё раз! : ");
            std::wcin.clear(); // обнуляем флаги состояния ошибки потока

            // функция для игнорирования (или отбрасывания) определенного количества символов из буфера ввода
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {

            // функция для игнорирования (или отбрасывания) определенного количества символов из буфера ввода
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return f_a;
}

// функция проверка на корректность ввода номера задания
const ushort& C_labWork::TypeThecking(ushort& f_a, const ushort& f_min, const ushort& f_max) const {
    while (true)
    {
        if (!(std::wcin >> f_a) || f_a < f_min || f_a > f_max || std::wcin.fail()) // условия для проверки
        {
            errmess::Exeption(L"Вы ввели не верные даные! Попробуйте ещё раз! : ");
            std::wcin.clear(); // обнуляем флаги состояния ошибки потока

            // функция для игнорирования (или отбрасывания) определенного количества символов из буфера ввода
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {

            // функция для игнорирования (или отбрасывания) определенного количества символов из буфера ввода
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return f_a;
}

// функция проверка на коректность ввода выхода из программы
const wchar_t& C_labWork::TypeThecking(wchar_t& f_c) const {
    while (true) {
        if (!((std::wcin >> f_c) || f_c == L'Д' || f_c == L'д' || f_c == L'Н' || f_c == L'н') || f_c == L' '
            || std::wcin.fail()) {
            errmess::Exeption(L"Вы ввели не верный символ! Попробуйте ещё: ");
            std::wcin.clear(); // обнуляем флаги состояния ошибки потока

            // функция для игнорирования (или отбрасывания) определенного количества символов из буфера ввода
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {

            // функция для игнорирования (или отбрасывания) определенного количества символов из буфера ввода
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return f_c;
}

// функция определения операционной системы
const wstr C_labWork::GetOsName() const {
#ifdef _WIN32
    return L"Windows (32-bit)";
#elif defined(_WIN64)
    return L"Windows (64-bit)";
#elif defined(__linux__)
    return L"Linux";
#elif defined(__APPLE__) || defined(__MACH__)
    return L"macOS";
#else
    return L"Unknown OS";
#endif
}

// функция вывода данных о лабораторной работе 'Титульный лист'
void C_labWork::PrintLab() {
    std::wcout <<std::setw(30) << std::right << L"Лабораторная работа № " << m_titlePage.s_labWorkNum << '\n'
               << L"Тема: " + m_titlePage.s_topLabWork << '\n' << L"Цели: " << '\n' << m_titlePage.s_objLabWork << '\n'
               << L"Разработчик: " + m_devLop.s_devLop << '\n' << L"Группа: " + m_devLop.s_group << '\n'
               << L"Операционная система: " + m_titlePage.s_operSystem << '\n' << L"Локаль(кодировка): LC_ALL "
                      + m_titlePage.s_loc << '\n';
}

// функция вывода данных по заданию
void C_labWork::PrintTask() {
    std::wcout <<std::setw(30) << std::right << L"Задание № " << m_task.s_taskNum << ")" << '\n' << m_task.s_taskText;
}

// функция для останоки или продолжения выполнения программы по выбору пользователя
const bool C_labWork::StopLab() const  {
    bool  stop {false};

    // запрос пользователю на выбор действия
    errmess::Info(L"Хотите продолжить введите 'Д', а если хотите прекратить 'Н' и нажмите ввод: ");
    wchar_t choice = {(this->*PTypeThecking2)(choice)}; // проверка на корректность ввода;

    // условие для действия по выбору пользователя
    if (choice == L'Д' || choice == L'д') stop = false;

    else if (choice == L'Н' || choice == L'н') stop = true;
    return stop;
}
