# 3 Тестовые задания
## 3.1 Что выводят программы, если есть ошибки исправьте их:
### a)
```cpp
//исходный код
#include <iostream>
int return 5(){
 return 5;
}
int return8(){
 return;
}
int main(){
 std::cout << (return5() + return8() ) << std::endl;
 return 0
}
```


```cpp
// исправленный код
#include <iostream>
int return5(){
 return 5;
}
int return8(){
 return 0;
}
int main(){
 std::cout << (return5() + return8() ) << std::endl; // программа выводит 5
 return 0;
}
```


### b)
```cpp
//исходный код
int return() {
 return 5;
 int return()
 {
 int k ;
 k{3};
 return k;
 }
}
int main(){
 std::cout << return() << std::endl;
 std::cout << return() << std::endl;
}
```


```cpp
// исправленный код
#include<iostream>
int return1(){
 return 5;
}
 int return2()
 {
 int k{3};
 return k;
 }
int main(){
 std::cout << return1() << std::endl; // // программа выводит 5
 std::cout << return2() << std::endl; // программа выводит 3
}
```


### c)
```cpp
//исходный код
#include <iostream>
void prints
()
{
 std::cout << 'O_o' << std::endl;
}
int main ()
{
 std::cout << prints() << std::endl;
 return 0;
}
```


```cpp
// исправленный код
#include <iostream>
void prints()
{
    std::cout << "O_o" << std::endl;
}

int main()
{
    prints(); //программа выводит O_o
    // std::cout << prints() << std::endl;
    return 0;
}
```


### d)
```cpp
//исходный код
#include <iostream>
int getNumbers()
{
 return 6;
 return 8;
}
int main()
{
 std::cout << getNumbers() << std::endl;
 std::cout << getNumbers() << std::endl;
 std::cout << getNumbers << std::endl;
 return 0;
}
```

```cpp
// исправленный код
#include <iostream>
int getNumbers()
{
 return 6;
}
int main()
{
 std::cout << getNumbers() << std::endl; //программа выводит 6
 std::cout << getNumbers() << std::endl; //программа выводит 6
 std::cout << getNumbers() << std::endl; //программа выводит 6
 return 0;
}
```


### e)
```cpp
//исходный код
int main()
{
 std::cout << multiply(7, 8) << std::endl;
 return 0;
}
void multiply(int a)
{
 return a * b
}
int main() {
 int x;
 std::cin >> x;
 constexpr int y(x);
 std::cout << y << std::endl;
return 0;
}
```


```cpp
// исправленный код
#include<iostream>

int multiply(int a, int b)
{
 return (a * b);
}

int main() {
 int x;
 std::cin >> x;
 const int y(x);
 std::cout << y << std::endl; // выводит значение константы y
 std::cout << multiply(7, 8) << std::endl;  // выводит значение функции multiply
return 0;
}
```


### f)
```cpp
//исходный код
#include <iostream>
#define VALUE
int main() {
#if (VALUE == 0)
 std::cout << VALUE <<"\n";
#elif (VALUE == 1)
 std::cout << VALUE <<"\n";
#else
 std::cout << VALUE <<"\n";
#endif
}
```

```cpp
// исправленный код
#include <iostream>
#define VALUE 2
int main() {
#if (VALUE == 0)
 std::cout << VALUE <<"\n";
#elif (VALUE == 1)
 std::cout << VALUE <<"\n";
#else
 std::cout << VALUE <<"\n"; // программа выводит значение VALUE
#endif
}
```


### g)
```cpp
//исходный код
#include <iostream>
namespace Mix {
enum class Fruits {
 LEMON,
 APPLE
}
enum class Colors {
 RED,
 BLACK
}
};
int main() {
 Fruits fruit = Fruits::LEMON;
 std::cout << "MIX\n";
 return 1;
}
```

```cpp
// исправленный код
#include <iostream>
namespace Mix{
enum class Fruits {
 LEMON,
 APPLE,
};
enum class Colors {
 RED,
 BLACK,
};
}
int main() {
 using namespace Mix;
 Fruits fruit = Fruits::LEMON;
 std::cout << "MIX\n"; // программа выводит значение переменной Mix
 return (0);
}
```


### h)
```cpp
//исходный код
#include <iostream>
namespace DoMath
{
 int subtract(int x, int y)
 {
 return x , y;
 }
namespace DoMath
{
 int add(int x, int y)
 {
 return x | y;
 }
}
}
int main(void)
{
 std::cout << DoMath::add(5, 4) << '\n';
 std::cout << DoMath::subtract(5, 4) << '\n';
 return 0;
}
```

```cpp
// исправленный код
#include <iostream>
namespace DoMath
{
 int subtract(int x, int y)
 {
 return x * y;
 }
namespace DoMath
{
 int add(int x, int y)
 {
 return x | y;
 }
}
}
int main(void)
{
 std::cout << DoMath::DoMath::add(5, 4) << '\n'; // программа выводит результат выражения x|y
 std::cout << DoMath::subtract(5, 4) << '\n'; // программа выводит результат выражения x*y
 return 0;
}
```

## 3.2 Чтобы программа cкомпилировалась нужно что-то добавить, нельзя удалять или комментировать программный код:

```cpp
// исходный код
#include <iostream>
int tmp = 1;
int main() {
tmp = 3;
 std::cout << "Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять
здесь пустые строки или
комментировать
<< std::endl;
 return 0;
int getNumbers( {
 int tmp = 1;
 return 8;
}
```


```cpp
// имправленный код
#include <iostream>
int tmp = 1;
int main() {
    int tmp = 3;

    std::cout << "Глобальная переменная tmp = " << ::tmp << '\n' << "Локальная переменная tmp = " << tmp << '\n';

    std::cout << " zzz \""":)""\" Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять\n\n";

    std:: cout << "здесь пустые строки или\n\n";

    std:: cout << "комментировать!" << std::endl;

    return 0;
}

int getNumbers() {
    int tmp = 1;
    return 8;
}
```
