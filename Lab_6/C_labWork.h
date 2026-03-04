#ifndef C_LABWORK_H
#define C_LABWORK_H
#include <iostream>
#include<string>
#include"constans.h"

// псевдонимы типов
using wstr = std::wstring;
using ushort = unsigned short;

// класс лабораторная работа
class C_labWork {
private:

    // структура для хранения данных о лабораторной работе "Титульный лист"
    struct {
        ushort s_labWorkNum; // номер лабораторной работы
        wstr s_topLabWork; // тема лабораторной работы
        wstr s_objLabWork; // цели лабораторной работы
        wstr s_operSystem; // операционная система
        wstr s_loc; // локаль(кодировка)
    } m_titlePage;

    // структура для хранения данных о разработчике
    struct {
        wstr s_devLop; // разработчик
        wstr s_group; // группа
    } m_devLop;

    // структура для хранения данных о задании по лабораторной работе
    struct {
        ushort s_taskNum; // номер задания
        wstr s_taskText; // текст задания
    } m_task;
public:

    // конструктор
    C_labWork() {
        std::wcout << L"конструктор вызвался\n";
        WrlabWork();
    }

        // деструктор
        ~C_labWork() {
        std::wcout << L"деструктор отработал\n";
    }

    void WrlabWork();

    // устанавливаем переменную номер задания
    void WrTask();

    // читаем переменную номер задания
    const ushort& RdTask() const;

    // устанавливаем текс задания
    void WrTaskText(const wstr& f_taskText);

    // функция замены символов
    void ReplaceAll(wstr& f_str, const wstr& f_from, const wstr& f_to);

    // фуекция преобразования локали в std::wstring
    wstr LocToWstring(const char* input);

    // функция выбора задания
    ProgrEnum TaskSelec(const ushort f_choice);

    // функция проверка на корректность ввода номера лабораторной работы
    const ushort& TypeThecking(ushort& f_a) const ;

    // функция проверка на корректность ввода номера задания
    const ushort& TypeThecking(ushort& f_a, const ushort& f_min, const ushort& f_max) const;

    // функция проверка на коректность ввода выхода из программы
    const wchar_t& TypeThecking(wchar_t& f_c) const ;

    // функция определения операционной системы
    const wstr GetOsName() const;

    // функция вывода данных о лабораторной работе 'Титульный лист'
    void PrintLab();

    // функция вывода данных по заданию
    void PrintTask();

    // функция для останоки или продолжения выполнения программы по выбору пользователя
    const bool StopLab();
};
#endif // C_LABWORK_H
