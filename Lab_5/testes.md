#3 Тестовые задания

##1) Найдите ошибку в потере данных, измените код чтобы не было потери данных:
``` cpp
// исходный код
#include<iostream>
int main() {
float a=3.14;
char *pj;
pj = (char*)&a;
std::cout << *pj << '\n';
}
```

```cpp
// исправленный код
#include<iostream>
int main() {
    float a=3.14;
    float *pj;
    pj = (float*)&a;
    std::cout << *pj << '\n';
}
```

##2) Исправьте ошибки в программе и реализуйте вывод значение и адрес объекта a через указатели pj и pk:
```cpp
// исходный код
nt main(){
int a=10, *pj;
void *pk;
pj = pk = &a;
pj++;
k++;
std::cout << pk << '\n';
std::cout << pj << '\n'
}
```

```cpp
// исправленный код
#include<iostream>
int main(){
    int a = 10, *pj;
    pj = &a;
    void *pk = pj;
    (*pj)++;
    std::cout << "адрес переменной a: " << pk << '\n';
    std::cout << "значение перемнной a = " << *pj << '\n';

    return 0;
}
```

##3) Помогите другу разработчику доработайте или исправьте код, который сделал:
##Номер телефона, например (212) 767-8900, можно условно разделить на три части: код
##города (212), номер телефонной станции (767) и номер абонента (8900). Разработана
##программа с использованием двух структур phone, позволяющую раздельно хранить эти три
##части телефонного номера. Инициализацию одной из них производится самостоятельно, а
##значения для другой запрашивается с клавиатуры. Затем выводится содержимое обеих
##переменных на экран. Результат работы программы должен выглядеть так:
##Введите код города, номер станции и номер абонента: 415 555 1212
##Мой номер: (212) 767-8900
##Ваш номер: (415) 555-1212
```cpp
// исходный код
#include <iostream>
using namespace std;
struct phone{
int kod ;
int nom ;
int mom_abon ;
};
struct new_phone{
int kod1;
int nom1;
int mom_abon1;
};
int main() {
setlocale (LC_ALL, "rus" );
phone object;
new_phone new_object;
wcout << L"Введите код города, номер станции и номер абонента: ";
int mas_all[11];
cin >> mas_all[11];
int mas_a[2];
mas_a[0] = mas_all[0];
mas_a[1] = mas_all[1];
mas_a[2] = mas_all[2];
new_object.kod1 = mas_a[2];
int mas_b[2];
mas_b[0] = mas_all[4];mas_b[1] = mas_all[5];
mas_b[2] = mas_all[6];
new_object.nom1 = mas_b[2];
int mas_c[3];
mas_c[0] = mas_all[8];
mas_c[1] = mas_all[9];
mas_c[2] = mas_all[10];
mas_c[3] = mas_all[11];
new_object.mom_abon1= mas_b[2];
object.kod = 123;
object.nom = 456;
object.mom_abon = 7890;
wcout << L"Мой номер телефона : " << object.kod << " " << object.nom << " " << object.mom_abon << endl;
wcout << L"Ваш номер : " << new_object.kod1 << " " << new_object.nom1 << " " << new_object.mom_abon1 << endl;
}
```

```cpp
// исправленный код
#include <iostream>
using namespace std;
struct phone{
    int kod ;
    int nom ;
    int mom_abon ;
};
struct new_phone{
    int kod1;
    int nom1;
    int mom_abon1;
};
int main() {
    setlocale (LC_ALL, "rus" );
    phone object;
    new_phone new_object;
    wcout << L"Введите код города, номер станции и номер абонента: ";
    int mas_all[12];
    cin >> mas_all[0] >> mas_all[1] >> mas_all[2];

    int mas_a[3];
    mas_a[0] = mas_all[0];
    mas_a[1] = mas_all[1];
    mas_a[2] = mas_all[2];
    new_object.kod1 = mas_a[0];

    int mas_b[3];
    mas_b[0] = mas_all[0];
    mas_b[1] = mas_all[1];
    mas_b[2] = mas_all[2];
    new_object.nom1 = mas_b[1];

    int mas_c[4];
    mas_c[0] = mas_all[0];
    mas_c[1] = mas_all[1];
    mas_c[2] = mas_all[2];
    new_object.mom_abon1= mas_b[2];

    object.kod = 123;
    object.nom = 456;
    object.mom_abon = 7890;
    wcout << L"Мой номер телефона : " << object.kod << " " << object.nom << " " << object.mom_abon << endl;
    wcout << L"Ваш номер : " << new_object.kod1 << " " << new_object.nom1 << " " << new_object.mom_abon1 << endl;
}
```


##4) Найдите 2е ошибки и измените код чтобы он был рабочим:
```cpp
// исходный код
#include <iostream>
using namespace std;
int main() {
setlocale (LC_ALL, "rus" );
const int n = 5;
const int m = 10;
int *a;
int *b;
a = new int*[n];
b = new int*[n];
for (int i = 0; i < n; i++) {
a[i] = new int[m];
b[i] = new int[m];
cout << &a[i][0] << endl;
cout << &b[i][0] << endl;
}
}
```

```cpp
// исправленный код
#include <iostream>
using namespace std;
int main() {
    setlocale (LC_ALL, "rus" );
    const int n = 5;
    const int m = 10;
    int *a;
    int *b;
    a = new int[n];
    b = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = *new int[m];
        b[i] = *new int[m];
        cout << &a[i] << endl;
        cout << &b[i] << endl;
    }
    delete[] a;
    a = nullptr;
    delete[] b;
    b = nullptr;
}
```

##5) Найдите ошибки и измените код чтобы он был рабочим и выведите все строки заданные разными способами:
```cpp
// исходный код
#include <iostream>
using namespace std;
int main() {
char s[] = "char s[]: text";
char* ps = "char* ps: text";
std::string str = "std::string str: text";
s = "another text";
str = "std::string str: another text";
char *s_1 = "char *s_1: text";
const char *s_2 = "const char *s_2: text";
wcout << "Вывод строк : "
}
```

```cpp 
// исправленный код
#include <iostream>
#include<cstring>
using namespace std;
int main() {
    char s[] = "char s[]: text";
    const char* ps = "char* ps: text";
    std::string str = "std::string str: text";
    //s = "another text"; // Это ошибка.
    str = "std::string str: another text";
    const char *s_1 = "char *s_1: text";
    const char *s_2 = "const char *s_2: text";

    wcout << L"Вывод строк : " << '\n';
    wcout << L"выводим заданные строки с помощью wcout" << '\n';
    wcout << L"s; " << s << '\n';
    wcout << L"ps : " << ps << '\n';
    cout << "str: " << str << '\n';
    wcout << "s_1: " << s_1 << '\n';
    wcout << "s_2: " << s_2 << '\n' << '\n';

     //выводим с помощью цикла
    wcout << L"вывод в цикле" << '\n';
    for (unsigned i{0}; i < strlen(s); ++i)
        wcout << s[i];
    wcout << '\n';

    for (unsigned i{0}; i < strlen(ps); ++i)
        wcout << ps[i];
    wcout << '\n';

    for (unsigned i{0}; i < str.length(); ++i)
        wcout << str[i];
    wcout << '\n';

    for (unsigned i{0}; i < strlen(s_1); ++i)
        wcout << s_1[i];
    wcout << '\n';

    for (unsigned i{0}; i < strlen(s_2); ++i)
        wcout << s_2[i];
    wcout << '\n';
}
```

##6) Исправьте чтобы был следующий вывод, причем нельзя использовать при выводе строку s
##а использовать s1-s4 (изменить код программы где вопросы примерно так s1 = s.substr(0, 3)):
##Кто вы по профессии? : Я инженер-программист!
```cpp
// исходный код
int main() {
wstring s = "I'am an developer";
wstring
s1 = s.substr(????),
s2 = s.substr(????),
s3 = s.substr(?),
s4 = s.substr(????);
wcout << "Why is you? : " << s1 s2+s3+s4 << '\n';
}
```

```cpp 
// исправленный код
#include<iostream>
#include<cstring>
using namespace std;

int main() {
wstring s = L"I'am an developer";
wstring
s1 = s.substr(0, 4),
s2 = s.substr(4, 4),
s3 = s.substr(8, 4),
s4 = s.substr(13, 4);
wcout << "Why is you? : " << s1 + s2 + s3 + s4 << '\n';
}
```
