#include"task_8.h"

#define FUNCTION_POINTER 1

// функций для задания № 8
auto LogicalFunctions () -> void {

  std::cout << std::setw(40) << std::right << "Задание 8)" << '\n';

  // переменные для ввода пользователем
  ubit_t a;
  ubit_t b;
  ///////////////

  bool stop = false; // переменная для цикла do while
  do {
      std::cout << "Введите  целочисленное значение для переменной a и нажмите ввод : ";
      a = Type_Thecking (a); // проверка на корректность ввода
      std::cout << "Введите  целочисленное значение для переменной b и нажмите ввод : ";
      b = Type_Thecking (b); // проверка на корректность ввода
      std::cout << "Веберите логическую операцию и введите соответствующий символ: \n"
                   "& - И (&)\n"
                   "| - ИЛИ (|)\n"
                   "^ - ИСКЛЮЧАЮЩЕЕ ИЛИ (^)\n и нажми ввод : ";

      uchar_t choice = Choice_Type_Thecking (choice); // проверка на корректность ввода

#if FUNCTION_POINTER == 1
      binary_op ptrFunc;
      ptrFunc = Select(choice);
#elif FUNCTION_POINTER == 2
      funcStd ptrFunc;
      ptrFunc = Select1(choice);
#endif

      // запрос пользователю на выбор действия
      std:: cout << "Хотите продолжить введите 'Y, а если хотите прекратить 'N' и нажмите ввод: \n";

      char choice2 = Type_Thecking (choice2); // проверка на корректность ввода

      // условие для действия по выбору пользователя
      if (choice2 == 'Y' || choice2 == 'y') stop = false;

      else if (choice2 == 'N' || choice2 == 'n') stop = true;
    }
  while ( ! stop); // выход из праграммы по выбору пользователя
}









