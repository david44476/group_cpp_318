#include"matrix_func.h" // содержит определение моих шаблонных функций

//функция для вызова задания № 2
auto Task_2 () -> void {

  // деклорацция функций длязадания № 2
  auto Task_2a () -> void;
  auto Task_2b () -> void;
  ///////////////////////////

  // задания 2.a) вызов функции для вывода единичной матрици
  Task_2a ();

  // задания 2.b) вызов функции для вывода суммы элементов матрицы лежащих выше главной диагонали
  Task_2b ();
}

auto Task_2a () -> void {

  std::cout << std::setw(30) << std::right<< "Задание 2.a)" << '\n';

  std::cout << "a) Создайте единичную матрицу размером\n"
               "который задается константами 5х5 (как показано на рисунке справа)\n"
               "и выведите ее в консоль с соблюдением размера.\n\n";

  constexpr short sArray {5};  // переменная для длины массива
  short MyArray [MAX_ROWS] [MAX_COLUMNS];  // создаём массив
  IdentityMatrix (MyArray, sArray, sArray);  // вызов функции для построения единичной матрици
  PrintArray(MyArray, sArray, sArray, "\tВывод единичной матрии");  //вывов единичной матрици
}

auto Task_2b () -> void {
  std::cout << std::setw(30) << std::right<< "Задание 2.b)" << '\n';

  std::cout << "Создайте двумерный массив (матрицу) 8х8,\n"
               "заполните его псевдослучайными числами в пределах\n"
               "от -15 до 15, полученными с помощью srand() и rand().\n"
               "С помощью вложенных циклов реализуйте функцию,\n"
               "которая находит сумму элементов матрицы, лежащих\n"
               "выше главной диагонали (как показано на рисунке справа).\n"
               "В консоль должна быть выведена матрица с\n"
               "соблюдением её размера, а также результат сложения.\n\n";

  constexpr short sMatrix {8};  // переменная для длины массива
  short Matrix [MAX_ROWS] [MAX_COLUMNS];  // создаём массив
  short min = -15;  // переменная для минимального диапазона
  short max = 15;   // переменная для максимального диапазона
  MyGen2(Matrix, sMatrix, sMatrix, min, max);  // вызов функции для заполнения массива своим генератором случайных чисел
  PrintArray(Matrix, sMatrix, sMatrix, "\t\tквадратная матрица 8*8"); // функция для вывода массива
  std::cout << "Сумма элементов матрицы, лежащих выше главной диагонали = " << SumMatrix(Matrix, sMatrix, sMatrix) << std::endl;
}
