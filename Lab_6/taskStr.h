#ifndef TASKSTR_H
#define TASKSTR_H
#include"constans.h"
#include"myEmoji.h"

// пространство имён строк заданий
namespace TaskStr {
const wstr seporStr{wstr(80, L'=')}; // разделитель '='
const wstr seporEmoji{wstr(40, MyEmoji::fingBott)}; // эмодзи разделитель

// сторока содержит информацию по лабораторной работе
const wstr lab6{seporStr + L'\n'
                + L'\t' + MyEmoji::computer + L" ЛАБОРАТОРНАЯ РАБОТА № 6 " + MyEmoji::computer + L'\n'
                + seporEmoji + L'\n' + L'\v'
                + L"   " + MyEmoji::brain + L" Тема: “Исследование С++ классов в IDE Qt Creator”"
                + L'\n' + L'\v'
                + L"   " + MyEmoji::purpose + L" Цели работы:" + L'\n'
                + L'\t' + L"1. Закрепить на практике представление о классах." + L'\n'
                + L'\t' + L"2. Научиться инкапсулировать данные в классах языка С++." + L'\n' + L'\v'
                + L"   " + MyEmoji::shadow + L" Разработчик: Давыдов Денис Владимирович." + L'\n' + L'\v'
                + L"   " + MyEmoji::computer + L" OS: UNIX." + L'\n' + L'\v'
                + L"   " + MyEmoji::local + L" locale (кодировка): UTF 8" + L'\n'
                + seporStr + L'\n'};

// строка по заданию № 1
const wstr strTask1{seporStr + L'\n'
                    + L'\t' + MyEmoji::light + L" ЗАДАНИЕ № 1: КЛАСС Bruteforce " + MyEmoji::light + L'\n'
                    + seporEmoji + L'\n'
                    + L'\n' + L"   " + MyEmoji::purpose + L" Цель:" + L'\n'
                    + L'\t' + L"- реализовать перебор пароля до гарантированного нахождения." + L'\n' + L'\v'
                    + L"   " + MyEmoji::listTasks + L" Ввод и ограничения:" + L'\n'
                    + L'\t' + L"- Пароль вводит пользователь." + L'\n'
                    + L'\t' + L"- Пользователь выбирает набор символов: цифры, буквы, символы." + L'\n'
                    + L'\t' + L"- В терминале обязательно вывести,"
                    + L"какие символы участвуют в переборе." + L'\n' + L'\v'
                    + L"   " + MyEmoji::warning + L" Ограничения по длине:" + L'\n'
                    + L'\t' + L"- Максимум 4 символа (иначе время перебора слишком велико)." + L'\n'
                    + L'\t' + L"- Для разработки оптимально 2–3 символа.)" + L'\n'};

// строка по заданию № 2
const wstr strTask2{seporStr + L'\n'
                    + L'\t' + MyEmoji::light + L" ЗАДАНИЕ № 2: ПРОВЕРКА НА ПАЛИНДРОМ "
                    + MyEmoji::light + L'\n' + seporEmoji + L'\n'
                    + L'\n' + L"   " + MyEmoji::listTasks + L" Ввод:" + L'\n'
                    + L'\t' + L"- Числа или символы от пользователя." + L'\n'
                    + L'\t' + L"- Лимит: не более 17 символов." + L'\n' + L'\v'
                    + L"   " + MyEmoji::magnifier + L" Что проверяем:" + L'\n'
                    + L'\t' + L"- Является ли строка палиндромом (перевертнем)." + L'\n'
                    + L'\t' + L"- Примеры: 101, 22322, «топот»." + L'\n' + L'\v'
                    + L"   " + MyEmoji::realiz + L" Реализация:" + L'\n'
                    + L'\t' + L"- Проверка инкапсулирована в классе." + L'\n'
                    + L'\t' + L"- Поддержка латиницы и кириллицы." + L'\n'
                    + L'\t' + L"- Выход по символу «q»." + L'\n'
                    + L'\t' + L"- При пустом вводе — ожидание строки.)" + L'\n'};

// строка по заданию № 3
const wstr strTask3{seporStr + L'\n'
                    + L'\t' + MyEmoji::light + L" ЗАДАНИЕ № 3: СИСТЕМА «АВТОБАЗА» " + MyEmoji::light + L'\n'
                    + seporEmoji + L'\n'
                    + L'\n' + MyEmoji::shadow + L" Роли и функции:" + L'\n' + L'\v'
                    + L"   " + MyEmoji::joystick + L" Диспетчер:" + L'\n'
                    + L'\t' + L"- распределяет заявки на рейсы между водителями;" + L'\n'
                    + L'\t' + L"- назначает автомобиль под рейс;" + L'\n'
                    + L'\t' + L"- может отстранить водителя от работы." + L'\n' + L'\v'
                    + L"   " + MyEmoji::car + L" Водитель:" + L'\n'
                    + L'\t' + L"- подаёт заявку на ремонт автомобиля;" + L'\n'
                    + L'\t' + L"- отмечает выполнение рейса;" + L'\n'
                    + L'\t' + L"- фиксирует текущее состояние автомобиля." + L'\n' + L'\v'
                    + L"   " + MyEmoji::chain + L" Требование:" + L'\n'
                    + L'\t' + L"- реализовать взаимодействие между классами:" + L'\n'
                    + L'\t' + L'\t' + L"* диспетчер управляет объектами (водителями и автомобилями);" + L'\n'
                    + L'\t' + L'\t' + L"* водитель сообщает диспетчеру о событиях." + L'\n'};

// строка по заданию № 4
const wstr strTask4{seporStr + L'\n'
                    + L'\t' + MyEmoji::light + L" ЗАДАНИЕ № 4: КЛАСС ДЛЯ КОМПЛЕКСНЫХ ЧИСЕЛ "
                    + MyEmoji::light + L'\n' + seporEmoji + L'\n'
                    + L'\n' + L"   " + MyEmoji::purpose + L" Цель:" + L'\n'
                    + L'\t' + L"- реализовать класс для работы с комплексными числами." + L'\n' + L'\v'
                    + L"   " + MyEmoji::realiz + L" Основные операции:" + L'\n'
                    + L'\t' + L"- сложение, вычитание;" + L'\n'
                    + L'\t' + L"- умножение, деление;" + L'\n'
                    + L'\t' + L"- сопряжение;" + L'\n'
                    + L'\t' + L"- возведение в степень, извлечение корня." + L'\n' + L'\v'
                    + L"   " + MyEmoji::plus + L" Дополнительно:" + L'\n'
                    + L'\t' + L"- поддержка разных форм записи:" + L'\n'
                    + L'\t' + L'\t' + L"* алгебраическая;" + L'\n'
                    + L'\t' + L'\t' + L"* тригонометрическая;" + L'\n'
                    + L'\t' + L'\t' + L"* экспоненциальная." + L'\n'};

// строка по заданию № 5
const wstr strTask5{seporStr + L'\n'
                    + L'\t' + MyEmoji::light + L" ЗАДАНИЕ № 5: ПРОВЕРКА ПРОХОЖДЕНИЯ КИРПИЧА В ОТВЕРСТИЕ "
                    + MyEmoji::light + L'\n' + seporEmoji + L'\n'
                    + L'\n' + L"   " + MyEmoji::listTasks + L" Ввод:" + L'\n'
                    + L'\t' + L"- Размеры 3D‑отверстия (h, l, w) от пользователя, в мм." + L'\n' + L'\v'
                    + L"   " + MyEmoji::realiz + L" Реализация:" + L'\n'
                    + L'\t' + L"- Класс «Кирпич»." + L'\n'
                    + L'\t' + L"- Класс «Модель3д»." + L'\n'
                    + L'\t' + L"- Сравнение через дружественную функцию." + L'\n' + L'\v'
                    + L"   " + MyEmoji::glasses + L" Визуализация в терминале:" + L'\n'
                    + L'\t' + L"- 3D‑проекция стандартного кирпича." + L'\n'
                    + L'\t' + L"- 3D‑проекция введённого отверстия." + L'\n' + L'\v'
                    + L"   " + MyEmoji::cup + L" Результат:" + L'\n'
                    + L'\t' + L"- Ответ: проходит кирпич или нет (зазором пренебречь)." + L'\n'
                    + seporStr + L'\n'};

// Собираем сообщение в отдельную строку — так проще и безопаснее
const wstr msg{L"Введите число от " + std::to_wstring(static_cast<ushort>(ProgrEnum::Task_2)) + L" до "
 + std::to_wstring(static_cast<ushort>(ProgrEnum::Task_Max)) + L": "};

// Собираем сообщение в отдельную строку — так проще и безопаснее
const wstr passMsg{L"Введите пароль от " + std::to_wstring(static_cast<ushort>(ProgrEnum::Task_3)) + L" до "
+ std::to_wstring(static_cast<ushort>(ProgrEnum::Task_5)) + L" символов."};

};
#endif // TASKSTR_H
