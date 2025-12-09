#include<iostream>
#include<iomanip>
#include<string>
#include"constans.h"
#include"stop.h"

// создаём структуру для головы
struct s_Head {
    std::wstring muzzle; // морда
    std::wstring ears; // уши
    std::wstring eyes; // глаза
};
// создаём структуру для тела
struct s_Body {
    std::wstring foreLimbs; // передние конечности
    std::wstring hindLimbs; // задние конечности
    std::wstring tail; // хвост
    std::wstring wings; // крылья
};
// создаём структуру для существа
struct s_Creature {
    std::wstring head; // поле для головы
    std::wstring body; // поле для тела
    s_Head Head; // вложенная структура для головы
    s_Body Body; // вложенная структура для тела
} *p_creator{nullptr};

// функция для создания частей тела
auto ParOfBody(const wchar_t *f_str) -> std::wstring;

// деклорация функции для создания нового вида
auto Сreator (s_Creature *f_creator, std::wstring (&r_ParOfBody)(const wchar_t*)) -> void;

// деклорация функции для вывода нового вида в консоль
auto PrintCreature (const s_Creature *p_creature, const wchar_t* p_str) -> void;

// функция для задания №2
auto NewView () -> RetConst {

    setlocale(LC_ALL, "ru_RU.UTF8");

    std::wstring s = L"Задание 2)";
    std::wcout << std::setw(30) << std::right << s << '\n';
    std::wcout << L"Создайте программу «Новый вид».Используя структуры данных.\n"
                 "Пользователю выводится сообщение побыть создателем\n"
                 "и ввести рандомную последовательность которую от него просят,\n"
                 "после чего выводится «Новый вид» существа который вы создали.\n" << std::endl;

    std::wcout << L"Предлогаем вам побыть создателем и создать новы вид сущесва!!!" << '\n' << '\n';

    bool stop = false; // переменная для цикла do while
    do {
        // создаём экземпляр структуры в динамической памяти
        p_creator = new (std::nothrow) s_Creature;
        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if ( ! p_creator) {
            // Обработка этого случая
            std::wcout << L"память не выделенна!!!";
            return ErrMemory;
        }

        Сreator (p_creator, ParOfBody); // вызов функции для создания нового вида;
        PrintCreature (p_creator, L"Созданный вами вид"); // вызов функции для вывода нового вида в консоль
        if (p_creator) delete p_creator; // освобождаем память
        p_creator = {nullptr}; // обнуляем указатель
        if ( ! (stop == Stop())) return ErrData;
    }
    while ( ! stop); // выход из праграммы по выбору пользователя

    return Ok;
}


// функция для создания нового вида
auto Сreator (s_Creature *p_creator, std::wstring (&r_ParOfBody)(const wchar_t*)) -> void {

    p_creator->head = r_ParOfBody (L"Введите голову сущесва например \" голова дракона \" и нажмите ввод: ");

    p_creator->body = r_ParOfBody (L"Введите тело сущесва например \" тело дракона \" и нажмите ввод: ");

    p_creator->Head.muzzle = r_ParOfBody (L"Введите морду сущесва например \" морда дракона \" и нажмите ввод: ");

    p_creator->Head.ears = r_ParOfBody (L"Введите уши сущесва например \" уши дракона \" и нажмите ввод: ");

    p_creator->Head.eyes = r_ParOfBody (L"Введите глаза сущесва например \" глаза дракона \" и нажмите ввод: ");

    p_creator->Body.foreLimbs = r_ParOfBody (L"Введите передние конечности сущесва например "
                                            "\" передние лапы дракона \"и нажмите ввод: ");

    p_creator->Body.hindLimbs = r_ParOfBody (L"Введите задние конечности сущесва например "
                                            "\" задние лапы дракона \"и нажмите ввод: ");

    p_creator->Body.tail = r_ParOfBody (L"Введите хвост сущесва например \" хвост дракона \" и нажмите ввод: ");

    p_creator->Body.wings = r_ParOfBody (L"Введите крылья сущесва например \" крылья дракона \" и нажмите ввод: ");
}


// функция для вывода нового вида в консоль
auto PrintCreature (const s_Creature *p_creator, const wchar_t* p_str) -> void {
    std::wcout << p_str << '\n';
    std::wcout << p_creator->head << '\n' << p_creator->body << '\n' << p_creator->Head.muzzle << '\n'
              << p_creator->Head.ears << '\n' << p_creator->Head.eyes << p_creator->Body.foreLimbs << '\n'
              << p_creator->Body.hindLimbs << '\n' << p_creator->Body.tail << '\n'
              << p_creator->Body.wings << '\n';
}


// функция создания частей тела существа
auto ParOfBody (const wchar_t *f_str) -> std::wstring {
    std::wcout << f_str << '\n';
    std::wstring newPart;
    std::getline(std::wcin, newPart);
    return newPart;
}
