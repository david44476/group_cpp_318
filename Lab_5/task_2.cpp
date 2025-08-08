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
}*creature{nullptr}; // создаём экземпляр структуры

// деклорация функции для создания нового вида
auto NewView () -> RetConst;

// деклорация функции для вывода нового вида в консоль
auto PrintCreature (const s_Creature& creature) -> void;

auto Task_2 () -> RetConst {
    std::string s = "Задание 2)";
    std::cout << std::setw(30) << std::right << s << '\n';
    std::cout << "Создайте программу «Новый вид».Используя структуры данных.\n"
                 "Пользователю выводится сообщение побыть создателем \n"
                 "и ввести рандомную последовательность которую от него просят, \n"
                 "после чего выводится «Новый вид» существа который вы создали.\n\n";

    bool stop = false; // переменная для цикла do while
    do {
        NewView (); // вызов функции для создания нового вида
        PrintCreature(*creature); // вызов функции для вывода нового вида в консоль
        delete creature; // освобождаем память
        creature = nullptr; // обнуляем указатель
        Stop(); // вызов функции для останоки или продолжения выполнения программы по выбору пользователя
    }
    while ( ! stop); // выход из праграммы по выбору пользователя

    return Ok;
}

// функция для создания нового вида
auto NewView () -> RetConst {

    std::cout << "Предлогаем вам побыть создателем и создать новы вид сущесва!!!" << '\n' << '\n';

    std::cout << "Введите голову сущесва например \" голова дракона \" и нажмите ввод: " << '\n';
    std::string head; // переменная для инициализации головы
    std::getline(std::cin, head);

    std::cout << "Введите тело сущесва например \" тело дракона \" и нажмите ввод: " << '\n';
    std::string body; // переменная для инициализации тела
    std::getline(std::cin, body);

    std::cout << "Введите морду сущесва например \" морда дракона \" и нажмите ввод: " << '\n';
    std::string muzzle; // переменная для инициализации морды
    std::getline(std::cin, muzzle);

    std::cout << "Введите уши сущесва например \" уши дракона \" и нажмите ввод: " << '\n';
    std::string ears; // переменная для инициализации ушей
    std::getline(std::cin, ears);

    std::cout << "Введите глаза сущесва например \" глаза дракона \" и нажмите ввод: " << '\n';
    std::string eyes; // переменная для инициализации глаз
    std::getline(std::cin, eyes);

    std::cout << "Введите передние конечности сущесва например \" передние лапы дракона \" "
                 "и нажмите ввод: " << '\n';
    std::string foreLimbs; // переменная для инициализации передних конечностей
    std::getline(std::cin, foreLimbs);

    std::cout << "Введите задние конечности сущесва например \" задние лапы дракона \" "
                 "и нажмите ввод: " << '\n';
    std::string hindLimbs; // переменная для инициализации задних конечностей
    std::getline(std::cin, hindLimbs);

    std::cout << "Введите хвост сущесва например \" хвост дракона \" и нажмите ввод: " << '\n';
    std::string tail; // переменная для инициализации хвоста
    std::getline(std::cin, tail);

    std::cout << "Введите крылья сущесва например \" крылья дракона \" и нажмите ввод: " << '\n';
    std::string wings; // переменная для инициализации крыльев
    std::getline(std::cin, wings);

    // инициализируем экземпляр структуры s_Creature
    creature = new (std::nothrow)s_Creature {head, body,
                // инициализируе экземпляр вложенной структуры Head
                {muzzle, ears, eyes},
                // инициализируе экземпляр вложенной структуры Body
                {foreLimbs, hindLimbs, tail, wings}};
    if (!creature) { // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        // Обработка этого случая
        std::cout << "память не выделенна!!!";
        return ErrMemory;
    }
    return Ok;
}


// функция для вывода нового вида в консоль
auto PrintCreature (const s_Creature &creature) -> void {
    std::cout << creature.head << '\n' << creature.body << '\n'
              << creature.Head.muzzle << '\n' << creature.Head.ears << '\n'
              << creature.Head.eyes << '\n' << creature.Body.foreLimbs << '\n'
              << creature.Body.hindLimbs << '\n' << creature.Body.tail << '\n'
              << creature.Body.wings << std::endl;
}
