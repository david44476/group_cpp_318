#ifndef TASK_8_H
#define TASK_8_H
#include <functional>

auto LogicalFunctions () -> void; // деклорация функции для задания № 8

// создаём псевдоним типа для unsigned int
using ubit_t = unsigned int;

// создаём псевдоним типа для unsigned char
using uchar_t = unsigned char;

// создаём псевдоним типа указателя на функции
using binary_op = bool(*)(ubit_t, ubit_t);

// создаём псевдоним типа указателя на функцию std::function
using funcStd = std::function<bool (ubit_t a, ubit_t b)>;

// функция для логического И (&)
auto AndOperatin (ubit_t var1, ubit_t var2) -> bool {
  return var1 & var2;
}

// функция для логического ИЛИ (|)
auto OrOperatin (ubit_t var1, ubit_t var2) -> bool {
  return var1 | var2;
}

// функция для логического ИСКЛЮЧАЮЩЕГО ИЛИ (^)
auto XorOperatin (ubit_t var1, ubit_t var2) -> bool {
  return var1 ^ var2;
}

///////////////////////////////////////////////////
auto Select (const uchar_t choice) -> binary_op {
  switch (choice) {
    case '&':
      return AndOperatin;
      break;
    case '|':
      return OrOperatin;
      break;
    case '^':
      return XorOperatin;
      break;
    default: return nullptr;
    }
}
///////////////////////////////////////////////////
auto Select1 (const uchar_t choice) -> funcStd {
  switch (choice) {
    case '&':
      return AndOperatin;
      break;
    case '|':
      return OrOperatin;
      break;
    case '^':
      return XorOperatin;
      break;
    default: return nullptr;
    }
}
#endif // TASK_8_H
