 Тестовые задания
1. Найдите в программе ошибки, представите ниже рабочий вариант программы.
```cpp
// исходный код
nt main() {
 short a;
 a(65599); // не допустимое значение и не правильная инициализация для данной переменной
 int 5 = 4; // не допустимый символ в названии переменной
 int л = 4; // не допустимый символ в названии переменной
 char ch;
 ch{5};
 float f;
 f = 3,2;
}}
```

```cpp
//исправленный код
int main() {
 short a(32767);
 int b = 4;
 int c = 4;
 char ch{5};
 float f;
 f = 3,2;
}
```

2. Какие значения выводит эта программа?

а) Почему z выводит неожиданные значения?
```cpp
#include <iostream>
int main() {
    int x = 5;
    x = x - 2;
    //a
    std::cout << x << std::endl; // #a вывод 3
    int y = x; //
    //b
    std::cout << y << std::endl; // #b вывод 3
    //c
    std::cout << x + y << std::endl; // #c вывод 6
    //d
    std::cout << x << std::endl; // #d вывод 3
    int z;
    //e
    std::cout << z << std::endl; /* #e вывод 32764 z выводит неожиданные значения т.к она неинициализированная и находится в локальной области видитоси
                              ей присваивается ячейка в памяти, в которой уже может находиться какой-нибудь мусор */
}
```

b)
```cpp
#include <iostream>
int main() {
 int x = 1;
 x = x++;
 std::cout << x << "\n"; // выведет значение x = 1
}
```

c)
```cpp
#include <iostream>
int main(){
 int x = 1;
 std::cout << ++x << "\n"; // выведет значение x = 2
}
```

3. Найдите в программе ошибки, можно только что-то добавлять убирать нельзя, и выведите
результат.
a)
```cpp
// исходный код
const int option_1 = 0;
const int option_2 = 1;
const int option_3 = 2;
const int option_4 = 3;
const int option_5 = 4;
const int option_6 = 5;
const int option_7 = 6;
const int option_8{7};
int main( {
 bitset<8> bits(0x4);
 bits.set(option_1);
 bits.flip(option_3);
 bits.reset(option_7);
 cin << "Bit 1 has value: " << bits.test(option_1) << '/n';
 cin << Bit 3 has value: " << bits.test() << '\n';
 cin << "Bit 7 has value: " << bits.test() < '\n';
 cin<< "All the bits: " << bits << '\n;
}
```

```cpp
// исправленный код
#include<iostream>
#include<bitset>
const int option_1 = 0;
const int option_2 = 1;
const int option_3 = 2;
const int option_4 = 3;
const int option_5 = 4;
const int option_6 = 5;
const int option_7 = 6;
const int option_8{7};
int main() {
 std::bitset<8> bits(0x4);
 bits.set(option_1);
 bits.flip(option_3);
 bits.reset(option_7);
 std::cout << "Bit 1 has value: " << bits.test(option_1) << '\n'; // Bit 1 has value: 1
 std::cout << "Bit 3 has value: " << bits.test(option_3) << '\n'; // Bit 3 has value: 0
 std::cout << "Bit 7 has value: " << bits.test(option_7) << '\n'; // Bit 7 has value: 0
 std::cout << "All the bits: " << bits << '\n'; // All the bits: 00000001
}
```

b)
```cpp
// исходный код
int main(){
 uint8_t a(1), b(1), c(3
 a = a < 1;
 printf("a: \n", a)
 b <<= 1;
 printf("b: %d \n", b);
 c |= 1;
 print("c: \n", c);
 }
 ```
 
 ```cpp
// исправленный код
#include <cstdint>
#include <stdio.h>
int main(){
 uint8_t a(1), b(1), c(3);
 a = a << 1; 
 printf("a: %d \n", a); // вывод а: 2
 b <<= 1; 
 printf("b: %d \n", b); // вывод b: 2
 c |= 1; 
 printf("c: %d \n", c); // вывод c: 3
}
```


c)
```cpp
// исходный код
int main() {
 int x (08);
 std::cout << "x: " << x < endl;
 int y = 0x5;
 std::cout << "y: " < y << std::endl;
 int bin(0);
 bin = 0b101;
 out << "bin 0b101: " << bin << std::endl
}
```

```cpp
// исправленный код
#include<iostream>
int main() {
 int x  (0x8);
 std::cout << "x: " << x << std::endl; // вывод x: 8
 int y = 0x5;
 std::cout << "y: " << y << std::endl; // вывод y: 5
 int bin(0);
 bin = 0b101;
 std::cout << "bin 0b101: " << bin << std::endl; // вывод bin 0b101: 5
}
```

d)
```cpp
// исходный код
int main() {
 int x{8};
 std::cout << "hex: " << h << x << ndl;
 std::cout << "oct: " << o<< x << std::endl;
 out << "dec: " << dec << x << std::endl;
}
```

```cpp
// исправленный код
#include<iostream>
int main() {
 int x{8};
 std::cout << "hex: " << std::hex << x << std::endl; // вывод hex: 8
 std::cout << "oct: " << std::oct << x << std::endl; // вывод oct: 10
 std::cout << "dec: " << std::dec << x << std::endl; // вывод dec: 8
}
```

4 Вычислите следующие выражения c использованием С++.
a) (true или false):
```cpp
(true && true) || false = true
(false && true) || true = true
(false && true) || false || true = true
(5 > 6 || 4 > 3) && (7 > 8) = false
!(7 > 6 || 3 > 4) = !7 < !6 && !3 < !4) = false
```

b) Какой результат 0110 >> 2 в двоичной системе счисления?
```cpp
0110 >> 2 = 0001
```

c) Какой результат 5 & 12 в десятичной системе счисления?
```cpp
5 & 12 = 4
```

d) Какой результат 5 ^ 12 в десятичной системе счисления?
```cpp
5 ^ 12 = 9
```

5 Конвертируйте двоичное число 0100 1101 в десятичную систему счисления.
```cpp
0100 1101 = 77
```

