/*
* Лабораторная работа № 4
*
* Тема: Исследование массивов, указателей, ссылок.
*
* Разработчик: Давыдов Денис Владимирович.
*
* OS: UNIX
*
* locale (кодировка): UTF 8
*/

// создаём перечесление заданий
enum class ProgrEnum {Task_1, Task_2, Task_3, Task_4, Task_5, Task_6, Task_7, Task_8, Task_9};

// выбор задания
const ProgrEnum progrEnum = ProgrEnum::Task_9;


int main() {
  // условие для выбора задания № 1
  if (progrEnum == ProgrEnum::Task_1) {
#include "task_1.h"

      // вызов функции задания № 1
      Task_1 ();
    }


  // условие для выбора задания № 2
  else if (progrEnum == ProgrEnum::Task_2) {
#include"task_2.h"

      // вызов функции для задания № 2
      Task_2 ();
    }


  // условие для выбора задания № 3
  else if (progrEnum == ProgrEnum::Task_3) {
#include"task_3.h"

      // вызов функции для задания № 3
      FromAtoZ ();
    }

  // условие для выбора задания № 4
  else if (progrEnum == ProgrEnum::Task_4) {

      //деклорация функции для  задания № 4
      auto Task_4 () -> void ;

      // вызов функции для задания № 4
      Task_4 ();
    }

  // условие для выбора задания № 5
  else if (progrEnum == ProgrEnum::Task_5) {

      //  деклорация функции для создания массива по выбору пользователя
      auto CreateArray () -> void;

      // вызов функции для задания № 5
      CreateArray ();
    }

  // условие для выбора задания № 6
  else if (progrEnum == ProgrEnum::Task_6) {
#include"task_6.h"

      // вызов функции для задания № 6
      Task_6 ();
    }

  // условие для выбора задания № 7
  else if (progrEnum == ProgrEnum::Task_7) {
#include"task_7.h"

      // вызов функции для задания № 7
      Faza ();
    }

  // условие для выбора задания № 8
  else if (progrEnum == ProgrEnum::Task_8) {

      // деклорация функций для задания № 8
      auto LogicalFunctions () -> void;

      // вызов функции для задания № 8
      LogicalFunctions ();
    }

  // условие для выбора задания № 9
  else if (progrEnum == ProgrEnum::Task_9) {
#include"task_9.h"
      Task_9 ();
    }
}
