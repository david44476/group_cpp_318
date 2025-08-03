#include<iostream>
#include <iomanip>
#include"type_thecking.h" // содержит мои функции для проверки ввода символьнных переменных
#include"template_functions.h" // содержит определение моих шаблонных функций

// функция для задания № 6
auto Task_6 () -> void {

  // деклорация функций для задания № 6
  auto Task_6a () -> void;
  auto Task_6b () -> void;
  /////////////////////////

  // функции для демонстрации использование операторов & (адрес) и * (значение по адресу)
  Task_6a ();
  Task_6b ();
}

// функция для задания № 6а
auto Task_6a() -> void {
  std::cout << std::setw(30) << std::right<< "Задание 6a) " << '\n';

  std::cout << "Напишите программу, чтобы продемонстрировать\n"
               "использование операторов &(адрес) и *(значение по адресу).\n"
               "Запросите пользователя ввести три числа m, fx, cht.\n\n";

  std::cout << "Введите значение для переменной m от -32768 до 32767 нажмите ввод : ";
  short m;
  m= Type_Thecking(m); // проверка на коректность ввода
  std::cout << "Введите значение для переменной fx от 1.7 * 10^308 до 1.7 * 10^308 нажмите ввод : ";
  double fx;
  fx = Type_Thecking(fx); // проверка на коректность ввода
  std::cout << "Введите значение для переменной cht от A до Z в любом регистре нажмите ввод : ";
  char cht;
  cht = Char_Type_Thecking(cht); // проверка на коректность ввода

  std::cout << "\vЗначение переменной m = " <<  m << '\n'
            << "Значение переменной fx = " << setiosflags(std::ios::fixed)<< fx << '\n'
            << "Значение переменной cht = " << cht << '\n';

  std::cout << "\vИспользование & оператор:" << '\n'
            << "Адрес переменной m = " << &m << '\n'
            << "Адрес переменной fx = " << &fx << '\n'
            << "Адрес переменной cht = " << static_cast<void*>(&cht) << '\n';

  std::cout << "\vИспользуя операторы & и *:" << '\n';
  short *ptrm{&m};  // указатель на переменную m
  double *ptrfx{&fx};  // указатель на переменную fx
  char *ptrcht{&cht};  // указатель на переменную cht
  std::cout << "значение по адресу переменной m " << &m << " = " << *ptrm << '\n'
            << "значение по адресу переменной fx " << &fx << " = " << *ptrfx << '\n'
            << "значение по адресу переменной cht " << static_cast<void*>(&cht)<< " = " << *ptrcht << '\n';

  std::cout << "\vИспользуя только переменную указателя:" << '\n'
            << "адрес переменной m = " << *&ptrm << '\n'
            << "адрес переменной fx = " << *&ptrfx  << '\n'
            << "адрес переменной cht = " << static_cast<void*>(*&ptrcht) << '\n';

  std::cout << "\vИспользование только оператора указателя:" <<'\n'
            << "значение по адресу переменной m = "<< ptrm << " = " << *ptrm << '\n'
            << "значение по адресу переменной fx = " << ptrfx << " = " << *ptrfx << '\n'
            << "значение по адресу переменной cht = " << static_cast<void*>(ptrcht) << " = " << *ptrcht << '\n';
}


// функция для задания № 6b
// деклорация функции для вывода массмва
auto PrinArray (void *xpArray, const short& size) -> void;

auto Task_6b () -> void {
  std::cout << std::setw(30) << std::right<< "\vЗадание 6b)" << '\n';
  std::cout << "Реализуйте хранения n элементов в массиве и печати элементов\n"
              "с помощью указателя, как представлено в иллюстрированной презентации:\n\n";

  using pFunc = void(*)(void*, const short&); // псевдоним типа указателя на функцию
  constexpr pFunc pPrinArray = PrinArray;  // указатель на функцию вывода массива
  constexpr short max_length{10};  // максимальное количиство считываемых символов
  static short arraySize; // переменная для длины массива по выбору пользователя
  short sizeMin{1}; // переменная для проверки ввода длины массива
  short sizeMax{10}; // переменная для проверки ввода длины массива
  // Вводим размер массива с проверками корректности
  std::cout << "Введите число для длины массива от 1 до 10 : ";
  arraySize = Type_Thecking (arraySize, sizeMin, sizeMax);

  short array[max_length];
  MersWhir (array, arraySize); // функция для генерации случайных чисел вихрем Мерсена
  pPrinArray (array, arraySize); // функция для вывода массива
}


// функция для вывода массива
auto PrinArray (void *xpArray, const short& size) -> void {
  short *Array = static_cast<short*>(xpArray);

  std::cout << "элемент ";
  for (auto i{0}; i < size; ++i) {
      std:: cout << '\t' << '[' << i << ']' << '\t';
    }
  std::cout << '\n' << '\v';

  std::cout << "значение =  ";
  for (auto i{0}; i < size; ++i) {
      std:: cout << '\t' << Array[i] << ' ' << '\t';
    }
  std::cout << '\n' << '\v';

  std::cout << "адрес ";
  for (auto i{0}; i < size; ++i) {
      std:: cout << '\t' << &Array[i] << ' ';
    }
  std::cout << '\n' << '\v';

  for (auto i{0}; i < size; ++i) {
      std::cout << "ptr [" << i << ']' << " адрес " << &Array[i] << " значение = " << Array[i] << "\t\t"
                << "*ptr [" << i << ']' << " адрес " << Array + i << " значение = " << *(Array + i) << '\n';
    }
}
