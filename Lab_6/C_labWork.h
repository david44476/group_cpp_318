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
        ushort* s_labWorkNum; // номер лабораторной работы
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

    // конструктор копирования
    C_labWork(const C_labWork& copiLab) {}
public:

    // конструктор без параметров
    C_labWork();

    // конструктор с параметрами
    C_labWork(const wstr& f_devLop, const wstr& f_group);


    // деструктор
    ~C_labWork() {
        std::wcout << L"деструктор отработал\n";
    }

    // устанавливаем поля класса
    void WrlabWork();

    // устанавливаем переменную номер лабораторной работы
    void WrLabWorkNum();

    // устанавливаем переменную темы лабораторной работы
    void WrTopLabWork();

    // устанавливаем цели лабораторной работы
    void WrObjLabWork();

    // устанавливаем операционную систему лабораторной работы
    void WrOperSystem();

    // устанавливаем локаль(кодировка)
    void WrLoc();

    // устанавливаем разработчика лабораторной работы
    void WrDevLop();

    // устанавливаем группу разработчика лабораторной работы
    void WrGroup();

    // устанавливаем переменную номер задания
    void WrTask();

    // читаем переменную номер задания
    const ushort& RdTask() const;

    // устанавливаем текс задания
    void WrTaskText(const wstr& f_taskText);

    // функция замены символов
    void ReplaceAll(wstr& f_str, const wstr& f_from, const wstr& f_to);

    // фуекция преобразования локали в std::wstring
    wstr LocToWstr(const char* input);

    // функция определения операционной системы
    const wstr GetOsName() const;

    // функция выбора задания
    const ProgrEnum TaskSelec(const ushort& f_choice) const;

    // функция проверка на корректность ввода номера лабораторной работы
    const ushort& TypeThecking(ushort& f_a) const ;

    // функция проверка на корректность ввода номера задания
    const ushort& TypeThecking(ushort& f_a, const ushort& f_min, const ushort& f_max) const;

    // функция проверка на коректность ввода выхода из программы
    const wchar_t& TypeThecking(wchar_t& f_c) const ;

    // функция вывода данных о лабораторной работе 'Титульный лист'
    void PrintLab();

    // функция вывода данных по заданию
    void PrintTask();

    // функция для останоки или продолжения выполнения программы по выбору пользователя
    const bool StopLab() const;
};

// псевдоним указателя на функцию
using pFunc = void (C_labWork::*const)();
pFunc PWrlabWork = &C_labWork::WrlabWork; // указатель на функцию WrlabWork
pFunc PWrLabWorkNum = &C_labWork::WrLabWorkNum; // указатель на функцию WrLabWorkNum
pFunc PWrTopLabWork = &C_labWork::WrTopLabWork; // указатель на функцию WrTopLabWork
pFunc PWrObjLabWork = &C_labWork::WrObjLabWork; // указатель на функцию WrObjLabWork
pFunc PWrOperSystem = &C_labWork::WrOperSystem; // указатель на функцию WrOperSystem
pFunc PWrLoc = &C_labWork::WrLoc; // указатель на функцию WrLoc
pFunc PWrDevLop = &C_labWork::WrDevLop; // указатель на функцию WrDevLop
pFunc PWrGroup = &C_labWork::WrGroup; // указатель на функцию WrGroup
pFunc PWrTask = &C_labWork::WrTask; // указатель на функцию WrTask

// указатель на функцию RdTask
const ushort&  (C_labWork::*const PRdTask)() const = &C_labWork::RdTask;

// указатель на функцию WrTaskText
void (C_labWork::*const PWrTaskText)(const wstr&) = &C_labWork::WrTaskText;

// указатель на функцию ReplaceAll
void (C_labWork::*const PReplaceAll)(wstr&, const wstr&, const wstr&) = &C_labWork::ReplaceAll;

// указатель на функцию LocToWstr
wstr (C_labWork::*const PLocToWstr)(const char*) = &C_labWork::LocToWstr;

// указатель на функцию GetOsName
const wstr (C_labWork::*const PGetOsName)() const = &C_labWork::GetOsName;

// указатель на функцию TaskSelec
const ProgrEnum (C_labWork::*const PTaskSelec)(const ushort&) const = &C_labWork::TaskSelec;

// указатели на перегруженные функцию TypeThecking
const ushort& (C_labWork::*const PTypeThecking)(ushort&) const = &C_labWork::TypeThecking;
const ushort& (C_labWork::*const PTypeThecking1)(ushort&, const ushort&, const ushort&) const = &C_labWork::TypeThecking;
const wchar_t& (C_labWork::*const PTypeThecking2)(wchar_t&) const = &C_labWork::TypeThecking;

// указатель на функцию PrintLab
void (C_labWork::*const PPrintLab)() = &C_labWork::PrintLab;

// указатель на функцию PrintTask
void (C_labWork::*const PPrintTask)() = &C_labWork::PrintTask;

// указатель на функцию StopLab
const bool (C_labWork::*const PStopLab)() const = &C_labWork::StopLab;
#endif // C_LABWORK_H
