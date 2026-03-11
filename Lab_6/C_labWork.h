#ifndef C_LABWORK_H
#define C_LABWORK_H
#include<string>
#include"constans.h" // подключаем константы

// псевдонимы типов
using wstr = std::wstring;
using ushort = unsigned short;

// класс лабораторная работа
class C_labWork {
private:
#pragma pack(push, 2)
    // структура для хранения данных о лабораторной работе "Титульный лист"
    struct {
        ushort* s_labWorkNum{nullptr}; // номер лабораторной работы
        wstr* s_topLabWork{nullptr}; // тема лабораторной работы
        wstr* s_objLabWork{nullptr}; // цели лабораторной работы
        wstr* s_operSystem{nullptr}; // операционная система
        wstr* s_loc{nullptr}; // локаль(кодировка)
    } m_titlePage;

    // структура для хранения данных о разработчике
    struct {
        wstr s_devLop{}; // разработчик
        wstr s_group{}; // группа
    } m_devLop;

    // структура для хранения данных о задании по лабораторной работе
    struct {
        ushort s_taskNum{}; // номер задания
        wstr s_taskText{}; // текст задания
    } m_task;
#pragma pack(pop)
public:

    // конструктор копирования
    C_labWork(const C_labWork& copiLab) = delete;

    // конструктор без параметров
    explicit C_labWork();

    // конструктор с параметрами о разработчике по умочанию
    explicit C_labWork(const wstr& f_devLop, const wstr& f_group);

    // конструктор с параметрами о лабораторной работе и разработчике по умочанию
    explicit C_labWork(const ushort& f_labWorkNum, const wstr& f_topLabWork, const wstr& f_objLabWork,
              const wstr& f_devLop, const wstr& f_group);


    // деструктор
    ~C_labWork();

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
    void ReplaceAll(wstr& f_str, const wstr f_from = L";", const wstr f_to = L"\n");

    // фуекция преобразования локали в std::wstring
    wstr LocToWstr(const char* input);

    // функция определения операционной системы
    const wstr GetOsName() const;

    // функция выбора задания
    const ProgrEnum TaskSelec(const ushort& f_choice) const;

    // функция проверка на корректность ввода номера задания
    const ushort& TypeThecking(ushort& f_a, const ushort& f_min, const ushort& f_max) const;

    // функция проверка на коректность ввода выхода из программы
    const wchar_t& TypeThecking(wchar_t& f_c) const ;

    // функция проверка на корректность ввода номера лабораторной работы
    const unsigned char& TypeThecking(unsigned char& f_a) const;

    // функция вывода данных о лабораторной работе 'Титульный лист'
    void PrintLab(ushort fieldWidth = 25, wchar_t separator = L'=');

    // функция вывода данных по заданию
    void PrintTask(ushort fieldWidth = 25, wchar_t separator = L'=') ;

    // функция для останоки или продолжения выполнения программы по выбору пользователя
    const bool StopLab() const;
};
#endif // C_LABWORK_H
