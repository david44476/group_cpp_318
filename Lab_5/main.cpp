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
#define TASK 8
#if (TASK == 1)
#include "task_1.h"
#elif (TASK == 2)
#include "new_view.h"
#elif (TASK == 3)
#include"continent.h"
#elif (TASK == 4)
#include "string_packing.h"
#elif (TASK == 5)
#include "task_5.h"
#elif (TASK == 6)
#include "array_of_str.h"
#elif (TASK == 7)
#include "descrip_func.h"
#elif (TASK == 8)
#include "mail_address.h"
#else
#endif
int main () {
#if (TASK == 1)
    Task_1 (reinterpret_cast<void*>(main));
#elif (TASK == 2)
    NewView ();
#elif (TASK == 3)
    Continents ();
#elif (TASK == 4)
    StringPacking ();
#elif (TASK == 5)
    Normalize ();
#elif (TASK == 6)
    ArrayOfStr ();
#elif (TASK == 7)
    DescripFunc ();
#elif (TASK == 8)
    MailAddress ();
#endif
}
