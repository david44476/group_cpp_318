#include<iostream>
#include<iomanip>
#include<string>
#include"constans.h"
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
} *p_creator{nullptr};

// функция для создания частей тела
auto ParOfBody (const char *f_str) -> std::string;

// деклорация функции для создания нового вида
auto Сreator (s_Creature *f_creator, std::string (&r_ParOfBody)(const char*)) -> void;

// деклорация функции для вывода нового вида в консоль
auto PrintCreature (const s_Creature *p_creature, const char* p_str) -> void;

// функция для задания №2
auto NewView () -> RetConst {
    std::string s = "Задание 2)";
    std::cout << std::setw(30) << std::right << s << '\n';
    std::cout << "Создайте программу «Новый вид».Используя структуры данных.\n"
                 "Пользователю выводится сообщение побыть создателем\n"
                 "и ввести рандомную последовательность которую от него просят,\n"
                 "после чего выводится «Новый вид» существа который вы создали.\n" << std::endl;

    std::cout << "Предлогаем вам побыть создателем и создать новы вид сущесва!!!" << '\n' << '\n';

    bool stop = false; // переменная для цикла do while
    do {
        // создаём экземпляр структуры в динамической памяти
        p_creator = new (std::nothrow) s_Creature;
        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if ( ! p_creator) {
            // Обработка этого случая
            std::cout << "память не выделенна!!!";
            return ErrMemory;
        }

        Сreator (p_creator, ParOfBody); // вызов функции для создания нового вида;
        PrintCreature (p_creator, "Созданный вами вид"); // вызов функции для вывода нового вида в консоль
        if (p_creator) delete p_creator; // освобождаем память
        p_creator = nullptr; // обнуляем указатель
        if ( ! (stop == Stop())) return ErrData ; // вызов функции для останоки или продолжения выполнения программы по выбору пользователя
    }
    while ( ! stop); // выход из праграммы по выбору пользователя

    return Ok;
}


// функция для создания нового вида
auto Сreator (s_Creature *p_creator, std::string (&r_ParOfBody)(const char*)) -> void {

    p_creator->head = r_ParOfBody ("Введите голову сущесва например \" голова дракона \" и нажмите ввод: ");

    p_creator->body = r_ParOfBody ("Введите тело сущесва например \" тело дракона \" и нажмите ввод: ");

    p_creator->Head.muzzle = r_ParOfBody ("Введите морду сущесва например \" морда дракона \" и нажмите ввод: ");

    p_creator->Head.ears = r_ParOfBody ("Введите уши сущесва например \" уши дракона \" и нажмите ввод: ");

    p_creator->Head.eyes = r_ParOfBody ("Введите глаза сущесва например \" глаза дракона \" и нажмите ввод: ");

    p_creator->Body.foreLimbs = r_ParOfBody ("Введите передние конечности сущесва например "
                                          "\" передние лапы дракона \"и нажмите ввод: ");

    p_creator->Body.hindLimbs = r_ParOfBody ("Введите задние конечности сущесва например "
                                          "\" задние лапы дракона \"и нажмите ввод: ");

    p_creator->Body.tail = r_ParOfBody ("Введите хвост сущесва например \" хвост дракона \" и нажмите ввод: ");

    p_creator->Body.wings = r_ParOfBody ("Введите крылья сущесва например \" крылья дракона \" и нажмите ввод: ");
}


// функция для вывода нового вида в консоль
auto PrintCreature (const s_Creature *p_creator, const char* p_str) -> void {
    std::cout << p_str << '\n';
        std::cout << p_creator->head << '\n' << p_creator->body << '\n' << p_creator->Head.muzzle << '\n'
                  << p_creator->Head.ears << '\n' << p_creator->Head.eyes << p_creator->Body.foreLimbs << '\n'
                  << p_creator->Body.hindLimbs << '\n' << p_creator->Body.tail << '\n'
                  << p_creator->Body.wings << '\n';
}


// функция создания частей тела существа
auto ParOfBody (const char *f_str) -> std::string {
    std::cout << f_str << '\n';
    std::string newPart;
    std::getline(std::cin, newPart);
    return newPart;
}
