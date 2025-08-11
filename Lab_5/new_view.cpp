#include<iostream>
#include<iomanip>
#include<string>
#include "constans.h"
#include"stop.h"

// создаём структуру для головы
struct s_Head {
    std::string muzzle; // морда
    std::string ears; // уши
    std::string eyes; // глаза
};
// создаём структуру для тела
struct s_Body {
    std::string foreLimbs; // передние конечности
    std::string hindLimbs; // задние конечности
    std::string tail; // хвост
    std::string wings; // крылья
};
// создаём структуру для существа
struct s_Creature {
    std::string head; // поле для головы
    std::string body; // поле для тела
    s_Head Head; // вложенная структура для головы
    s_Body Body; // вложенная структура для тела
};

// деклорация функции для создания нового вида
auto Сreator (s_Creature *pcreature) -> s_Creature;

// деклорация функции для вывода нового вида в консоль
auto PrintCreature (const s_Creature &f_creature, const char* f_str) -> void;

// функция для создания частей тела
auto ParOfBody (const char *f_str) -> std::string;

// функция для задания №2
auto NewView () -> RetConst {
    std::string s = "Задание 2)";
    std::cout << std::setw(30) << std::right << s << '\n';
    std::cout << "Создайте программу «Новый вид».Используя структуры данных.\n"
                 "Пользователю выводится сообщение побыть создателем \n"
                 "и ввести рандомную последовательность которую от него просят, \n"
                 "после чего выводится «Новый вид» существа который вы создали.\n\n";

    std::cout << "Предлогаем вам побыть создателем и создать новы вид сущесва!!!" << '\n' << '\n';

    bool stop = false; // переменная для цикла do while
    do {
        // создаём экземпляр структуры в динамической памяти
        s_Creature *p_creator = new (std::nothrow) s_Creature;
        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if ( ! p_creator) {
            // Обработка этого случая
            std::cout << "память не выделенна!!!";
            return ErrMemory;
        }
        Сreator (p_creator); // вызов функции для создания нового вида;
        PrintCreature (*p_creator, "Созданный вами вид"); // вызов функции для вывода нового вида в консоль
        delete p_creator; // освобождаем память
        p_creator = nullptr; // обнуляем указатель
        if ( ! (stop == Stop())) return ErrData ; // вызов функции для останоки или продолжения выполнения программы по выбору пользователя
    }
    while ( ! stop); // выход из праграммы по выбору пользователя

    return Ok;
}

// функция для создания нового вида
auto Сreator (s_Creature *p_creator) -> s_Creature {

    p_creator->head = ParOfBody ("Введите голову сущесва например \" голова дракона \" и нажмите ввод: ");

    p_creator->body = ParOfBody ("Введите тело сущесва например \" тело дракона \" и нажмите ввод: ");

    p_creator->Head.muzzle = ParOfBody ("Введите морду сущесва например \" морда дракона \" и нажмите ввод: ");

    p_creator->Head.ears = ParOfBody ("Введите уши сущесва например \" уши дракона \" и нажмите ввод: ");

    p_creator->Head.eyes = ParOfBody ("Введите глаза сущесва например \" глаза дракона \" и нажмите ввод: ");

    p_creator->Body.foreLimbs = ParOfBody ("Введите передние конечности сущесва например "
                                         "\" передние лапы дракона \"и нажмите ввод: ");

    p_creator->Body.hindLimbs = ParOfBody ("Введите задние конечности сущесва например "
                                         "\" задние лапы дракона \"и нажмите ввод: ");

    p_creator->Body.tail = ParOfBody ("Введите хвост сущесва например \" хвост дракона \" и нажмите ввод: ");

    p_creator->Body.wings = ParOfBody ("Введите крылья сущесва например \" крылья дракона \" и нажмите ввод: ");

    std::cout << std::endl;

    return *p_creator;
}


// функция для вывода нового вида в консоль
auto PrintCreature (const s_Creature &f_creature, const char* f_str) -> void {
    std::cout << f_str << '\n';
    std::cout << f_creature.head << '\n' << f_creature.body << '\n'
              << f_creature.Head.muzzle << '\n' << f_creature.Head.ears << '\n'
              << f_creature.Head.eyes << '\n' << f_creature.Body.foreLimbs << '\n'
              << f_creature.Body.hindLimbs << '\n' << f_creature.Body.tail << '\n'
              << f_creature.Body.wings << std::endl;
}


// функция создания частей тела существа
auto ParOfBody (const char *f_str) -> std::string {
    std::cout << f_str << '\n';
    std::string newPart;
    std::getline(std::cin, newPart);
    return newPart;
}
