# Тестовые задания
## Найдите в программах ошибки выделите их и представте ниже рабочий вариант программы.
### a)
``` cpp
// Исходный код
#if 0 Подключаем библиотеку для ввода/вывода #endif
#include <iostream>
Int main() {/* Открытая скобка - окончание блока
стейтмена, кода относящийся к функции main */
// Тело
функции
} /* /* Закрытая скобка - окончание блока стейтмена, кода относящийся к функции main */ */
```

``` cpp
// Исправленный код
#if 0
Подключаем библиотеку для ввода/вывода
#endif
#include <iostream>
int main() {/* Открытая скобка - начало блока
стейтмена, кода относящийся к функции main */
// Тело функции
} // Закрытая скобка - окончание блока стейтмена, кода относящийся к функции main
```

### b)
``` cpp
// Исходный код
#if 0 Подключаем библиотеку для ввода/вывода
#endif
#include <iostream
int MAIN() {/* Открытая скобка - окончание блока
стейтмена, кода относящийся к функции main */
// Тело функции
} /* /* Закрытая скобка - окончание блока стейтмена, кода относящийся к функции
```

``` cpp
// Исправленный код
#if 0
Подключаем библиотеку для ввода/вывода
#endif
#include <iostream>
int main() {/* Открытая скобка - начало блока
стейтмена, кода относящийся к функции main */
// Тело функции
} // Закрытая скобка - окончание блока стейтмена, кода относящийся к функции main
```

### c)
``` cpp
// Исходный код
#if 0
Подключаем библиотеку для ввода/вывода
#endif
#include <iostream
int майн() /* Открытая скобка - окончание блока
стейтмена, кода относящийся к функции main */
// Тело функции
} /* */ Закрытая скобка - окончание блока стейтмена, кода относящийся к функции
```

``` cpp
// Исправленный код
#if 0
Подключаем библиотеку для ввода/вывода
#endif
#include <iostream>
int main() {/* Открытая скобка - начало блока
стейтмена, кода относящийся к функции main */
// Тело функции
} // Закрытая скобка - окончание блока стейтмена, кода относящийся к функции main
```

### d)
``` cpp
// Исходный код
/*
* Лабораторная работа №1
* Исследование комментариев С++:
*
* Developer:
* /
#if 0
Подключаем библиотеку для ввода/вывода
#endif
#include <iostream
int майн() { /* Открытая скобка - окончание блока
//
стейтмена, кода относящийся к функции main */
// Тело функции
} //Закрытая скобка - окончание блока стейтмена, кода относящийся к функции
```

``` cpp
// Исправленный код
/*
* Лабораторная работа №1
* Исследование комментариев С++:
*
* Developer:
*/
#if 0
Подключаем библиотеку для ввода/вывода
#endif
#include <iostream>
int main() { /* Открытая скобка - начало блока
стейтмена, кода относящийся к функции main */
// Тело функции
} // Закрытая скобка - окончание блока стейтмена, кода относящийся к функции main
```

### f)
``` cpp
// Исходный код
/ *
* Лабораторная работа №1
* Исследование комментариев С++:
*
* Developer:
* /
#if 0
Подключаем библиотеку для ввода/вывода
#endif
#
include <iostream>
int main() } /* *Открытая скобка - окончание блока
//
стейтмена, кода относящийся к функции main */
//// Тело функции
```

``` cpp
// Исправленный код
/*
* Лабораторная работа №1
* Исследование комментариев С++:
*
* Developer:
*/
#if 0
Подключаем библиотеку для ввода/вывода
#endif
#include <iostream>
int main() { /* Открытая скобка - начало блока
стейтмена, кода относящийся к функции main */
// Тело функции
} // Закрытая скобка - окончание блока стейтмена, кода относящийся к функции main
```
