# 3 Тестовые задания
## Найдите ошибки в программах и исправьте их, напишите результат вывода программ:
### a)
```cpp
//исходный код
void main( {
 short array[]{1,3,5,7,9};
 short *ptr = array;
 ptr = 111;
 for (int i = 0; i < sizeof(array); ++i)
 std::cout << " Значение элемента " << i << ": " << array +i << '\n';
}
```

```cpp
// исправленный код
#include<iostream>
int main()
{
    short array[]{1,3,5,7,9};
    short *ptr = array;
    *ptr = 111;
    for (short i = 0; i < static_cast<signed>(sizeof(array) / sizeof(array[0])); ++i)
        std::cout << " Значение элемента " << i << ": " << *(array +i) << '\n';
    
    return 0;
}
/* вывод программы
 Значение элемента 0: 111
 Значение элемента 1: 3
 Значение элемента 2: 5
 Значение элемента 3: 7
 Значение элемента 4: 9
 */
```


### b)
```cpp
//исходный код
int main() {
 int array[size]{1,3,5,7,9};
 Func(&array, size);
}
void Func(int *ptr, int size) {
 for (int i = 0; i < size; ++i)
 std::cout << " Значение элемента " ББ<< ptr[i] << '\n';
 std::cout << " Адрес элемента " << ptr[i << '\n';
}
```

```cpp
// исправленный код
#include<iostream>

void Func(int *ptr, int size);

int main()
{
    constexpr int size {5};
    int array[size]{1,3,5,7,9};
    Func(array, size);

    return 0;
}


void Func(int *ptr, int size) {
    for (int i = 0; i < size; ++i)
    {
        std::cout << " Значение элемента " << i << '=' << ptr[i] << '\n';
        std::cout << " Адрес элемента " << i << ' ' << &ptr[i] << '\n';
    }
}
/* вывод программы
 Значение элемента 0=1
 Адрес элемента 0 0x61fe98
 Значение элемента 1=3
 Адрес элемента 1 0x61fe9c
 Значение элемента 2=5
 Адрес элемента 2 0x61fea0
 Значение элемента 3=7
 Адрес элемента 3 0x61fea4
 Значение элемента 4=9
 Адрес элемента 4 0x61fea8
*/
```

### c)
```cpp
//исходный код
#include <iostream>
int main() {
 short value;
 short *p;
 p = value;
 *p = value;
 *p = &value;
 *p = *&value;
}
```

```cpp
// исправленный код
#include <iostream>
int main() {
 short value;
 short *p;
 p = &value;
 *p = value;
 *p = value;
 *p = *&value;
}
```

### d)
```cpp
//исходный код
#include <iostream>
int main() {
 char cvalue;
 int ivalue;
 short * ps;
 char *pc;
 void *pv {(int*)(cvalue)};
 void *pv_1 {(char*)(&ivalue)};
 std::cout << "pv->int" << *static_cast<int>(pv) << std::endl;
 int *pi = {(int)(pv)};
 std::cout << "pi=" << pv_1 << std::endl;
}
```

```cpp
// исправленный код
#include <iostream>
int main() {
 char cvalue;
 int ivalue;
 short *ps = nullptr;
 char *pc = nullptr;
 void *pv {(int*)(&cvalue)};
 void *pv_1 {(char*)(&ivalue)};
 std::cout << "pv -> int " << *static_cast<int*>(pv) << std::endl;
 int *pi = {(int*)(pv_1)};
 std::cout << "pi = " << *pi << std::endl;

 return 0;
}
/* вывод программы
 pv -> int 512
 pi = 65535
*/
```

### e)
```cpp
//исходный код
#include <iostream>
int main() {
 short value, value1(3);
 short &ref;
 const short &ref1 = value;
 const short &ref2 = 78;
 ref1 = 3;
 *&value = 4;
 const *short const p3;
}
```

```cpp
// исправленный код
#include <iostream>
int main() {
 short value, value1(3);
 short &ref = value1;
 const short &ref1 = value;
 const short &ref2 = 78;
// ref1 = 3; // error: ref - это константа
 *&value = 4;
 const short *const p3 = nullptr;
}
```


### f)
```cpp
//исходный код
int main() {
 short value = 13;
 short value_1 = 100;
 short *ptr = &value;
 std::cout << &value << '\n';
 std::cout << (value +=1) << '\n';
 ptr = 9;
 std::cout << (value = value_1 + *ptr) << '\n';
 std::cout << "Результат: " << value << '\n';
}
```

```cpp
// исправленный код
#include<iostream>
int main() {
 short value = 13;
 short value_1 = 100;
 short *ptr = &value;
 std::cout << &value << '\n';
 std::cout << (value +=1) << '\n';
 *ptr = 9;
 std::cout << (value = value_1 + *ptr) << '\n';
 std::cout << "Результат: " << value << '\n';

 return 0;
}
/* вывод программы
0x61fe96
14
109
Результат: 109
*/
```

## Исправьте ошибки можно что-то добавлять а удалять нельзя.
### g)
```cpp
//исходный код
int main() {
int value1 45;
int value 63;
int *ptr = &value;
*ptr = &value;
ptr = value;
std::cout << "Результат value1 + value2 : " << value1 + ptr << '\n';
}
```

```cpp
// исправленный код
#include<iostream>
int main() {
int value1 (45);
int value (63);
int *ptr = &value;
*ptr = value;
ptr = &value;
std::cout << "Результат value1 + value2 : " << value1 + *ptr << '\n';
return 0;
}
/* вывод программы
Результат value1 + value2 : 108
*/
```

## Исправьте ошибки можно что-то добавлять а удалять нельзя. Что выведет программа:
### a)
```cpp
//исходный код
int main() {
 std::cout << "Hi !\n";
 exit;
 std::cout << 3
}
```

```cpp
// исправленный код
#include<iostream>
int main() {
 std::cout << "Hi !\n";
 exit(0);
 std::cout << 3;
 return 0;
}
/* вывод программы
Hi !
*/
```

### b)
```cpp
//исходный код
int main() {
switch (2) {
 case 1
 std::cout << 1 << '\n';
 case 2
 std::cout << 2 << '\n'
 case
 std::cout << 3 << '\n';
 case 4
 std::cout << 4 << '\n'
 default:
 std::cout << 5 <
 ```
 
 ```cpp
 // исправленный код
#include<iostream>
int main() {
    switch (2) {
    case 1:
        std::cout << 1 << '\n';
        break;
    case 2:
        std::cout << 2 << '\n';
        break;
    case 3:
        std::cout << 3 << '\n';
        break;
    case 4:
        std::cout << 4 << '\n';
        break;
    default:
        std::cout << 5 << '\n';
    }
    return 0;
}
/* вывод программы
2
*/
```
 
 ### c)
 ```cpp
 //исходный код
#include <iostream>
const int size = 5;
void Func(int ptr, int size) {
 for (int i = 0; i < size; ++i)
 std::cout << ptr[i] << '\n'; // вывод элементов масива в цикле
 ptr = 5; // первому элементу массива присваиваем значение 5
 std::cout << '\n';
 for (int i = 0; i < size; ++i)
 std::cout << *ptr++ << '\n'; // вывод элементов масива в цикле
 *ptr = 55; // первому элементу массива присваиваем значение 55
 std::cout << '\n';
}
int main() {
 int array[];
 Func(array, size);
 for (int i = 0; i < size; ++i)
 std::cout << array[i] << '\n';
}
```

```cpp
// исправленный код
#include <iostream>
const int size = 5;
void Func(int *ptr, int size) {
 for (int i = 0; i < size; ++i)
 std::cout << &ptr[i] << '\n'; // вывод элементов масива в цикле
 *ptr = 5; // первому элементу массива присваиваем значение 5
 std::cout << '\n';
 for (int i = 0; i < size; ++i)
 std::cout << *ptr++ << '\n'; // вывод элементов масива в цикле
 *(ptr - size) = 55; // первому элементу массива присваиваем значение 55
// for (int i = 0; i < size; ++i)
// std::cout << &ptr[i] << '\n'; // вывод элементов масива в цикле
 std::cout << '\n';
}

int main() {
    int array[size]{1, 2, 3, 4, 5};
    Func(array, size);
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << '\n';
    return 0;
}
/* вывод программы
0x61fe88
0x61fe8c
0x61fe90
0x61fe94
0x61fe98

5
2
3
4
5

55
2
3
4
5
*/
```
