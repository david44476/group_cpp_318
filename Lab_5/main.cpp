/*
* Лабораторная работа № 5
*
* Тема: “Исследование строк, структур памяти С++ в IDE Qt Creator”
*
* Цель работы:
*    1. Закрепить на практике представление о строках и типах памяти.
*    2. Научиться пользоваться памятью используя механизмы языка С++.
*
* Разработчик: Давыдов Денис Владимирович.
*
* OS: UNIX
*
* locale (кодировка): UTF 8
*/
#define TASK 2
#if (TASK == 1)
#include "task_1.h"
#elif (TASK == 2)
#include "task_2.h"
#elif (TASK == 3)
#include "task_3.h"
#elif (TASK == 4)
#include "task_4.h"
#elif (TASK == 5)
#include "task_5.h"
#elif (TASK == 6)
#include "task_6.h"
#elif (TASK == 7)
#include "task_7.h"
#elif (TASK == 8)
#include "task_8.h"
#else
#endif
int main () {
#if (TASK == 1)
    Task_1();
#elif (TASK == 2)
    Task_2();
#elif (TASK == 3)
    task_3();
#elif (TASK == 4)
    task_4();
#elif (TASK == 5)
    task_5();
#elif (TASK == 6)
    task_6();
#elif (TASK == 7)
    task_7();
#elif (TASK == 8)
    task_8();
#else
// и тд
#endif
}
