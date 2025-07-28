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

  std::cout << std::setw(30) << std::right<< "Задание 2.a)" << '\n' << '\n';

  constexpr short sArray {5};  // переменная для длины массива
  short MyArray [MAX_ROWS] [MAX_COLUMNS];  // создаём массив
  IdentityMatrix (MyArray, sArray, sArray);  // вызов функции для построения единичной матрици
  PrintArray(MyArray, sArray, sArray, "Вывод единичной матрии");  //вывов единичной матрици
}

auto Task_2b () -> void {
  std::cout << std::setw(30) << std::right<< "Задание 2.b)" << '\n' << "Находим сумму элементов матрицы, "
            << "лежащих выше главной диагонали:\n"
            << std::setw(47) << std::right << "квадратная матрица 8*8\n";

  constexpr short sMatrix {8};  // переменная для длины массива
  short Matrix [MAX_ROWS] [MAX_COLUMNS];  // создаём массив
  short min = -15;  // переменная для минимального диапазона
  short max = 15;   // переменная для максимального диапазона
  MyGen2(Matrix, sMatrix, sMatrix, min, max);  // вызов функции для заполнения массива своим генератором случайных чисел
  PrintArray(Matrix, sMatrix, sMatrix, "Исходный массив"); // функция для вывода массива
  std::cout << "Сумма элементов матрицы, лежащих выше главной диагонали = " << SumMatrix(Matrix, sMatrix, sMatrix) << std::endl;
}
