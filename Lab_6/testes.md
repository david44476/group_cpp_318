# Тестовые задания
## 1)Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
```cpp
//исходный код
#include <iostream>
class Integer {
Integer(int value) {
value=value;
std::cout << "Object created." <;
}
int getValue() return value;
void setValue(int number) { value = number; }
void print( {
cout << "Value: " << value
}
private
int value;
}
int main()
Integer integer;
.setValue(3);
std::cout << Value: " << getValue() <<
}
```

```cpp
// исправленный код
#include <iostream>
class Integer {
public:
    Integer(int xvalue) {
        m_value = xvalue;
        std::cout << "Object created." << '\n';
    }
    int getValue() {return m_value;}
    void setValue(int xnumber) { m_value = xnumber; }
    void print() {
        std::cout << "Value: " << m_value << '\n';
    }
private:
    int m_value;
};


int main(){
    Integer integer(7);
    integer.print();
    integer.setValue(3);
    std::cout << "Value: " << integer.getValue() << '\n';
}
/* вывод программы
Object created.
Value: 7
Value: 3
*/
```


## 2)Найдите ошибки в программе, которая будет заниматься учетом успеваемости студентов в группе, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
```cpp
//исходный код
#include <string>
#include <iostream>
class Students {
// Установка имени студента
void set_name(string xstudent_name) {
name = student_name;
}
// Получение имени студента
std::string get_name() {
return name;// Установка фамилии студента
void set_last_name(std::string student_last_name) {
last_name = student_last_name;
}
// Получение фамилии студента
std::string get_last_name() {
return last_name;
}
// Установка промежуточных оценок
void set_scores(int student_scores[]) {
for (int i = 0; i < 5; +i) {
scores[i] = student_scores[i];
}
}
// Установка среднего балла
void set_average_ball(float ball) {
average_ball = ball
}
// Получение среднего балла
float get_average_ball() {
return average_ball;
}
Students();
private
// Промежуточные оценки
int scores[5];
// Средний балл
float average_ball;
// Имя
std::string name;
// Фамилия
std::string last_name;
}
main() -> int {
// Создание объекта класса Student
Students ;
std::string name;
string last_name;
// Ввод имени с клавиатуры
cout << "Name: «";
getline(std::cin, name);
// Ввод фамилии
std::cout << "Last name: ";
getline(cin, last_name);
// Сохранение имени и фамилии в объект класса Students
student.set_name(name);
student.set_last_name(last_name);
// Оценки
int scores[];
// Сумма всех оценок
int sum = 0;
// Ввод промежуточных оценок
for (i = 0; i < 5; ++i) {
std::cout << "Score " << i+1 << ": ";
std::cin >> scores[i];
// суммирование
sum += scores[i];
}// Сохраняем промежуточные оценки в объект класса Student
student.set_scores(scores);
// Считаем средний балл
float average_ball = sum / 5,0;
// Сохраняем средний балл в объект класса Students
set_average_ball(average_ball);
// Выводим данные по студенту
std::cout << "Average ball for " << student.get_name() << " "
<< student.get_last_name() << " is "
<< student.get_average_ball() << std::endl;
}
```

```cpp
// исправленный код
#include <string>
#include <iostream>
class Students {
public:

    // Установка имени студента
    void set_name(std::string xstudent_name) {
        name = xstudent_name;
    }

    // Получение имени студента
    std::string get_name() {
        return name;
    }

    // Установка фамилии студента
    void set_last_name(std::string xstudent_last_name) {
        last_name = xstudent_last_name;
    }

    // Получение фамилии студента
    std::string get_last_name() {
        return last_name;
    }

    // Установка промежуточных оценок
    void set_scores(int xstudent_scores[]) {
        for (int i = 0; i < 5; ++i) {
            scores[i] = xstudent_scores[i];
        }
    }

    // Установка среднего балла
    void set_average_ball(float xball) {
        average_ball = xball;
    }

    // Получение среднего балла
    float get_average_ball() {
        return average_ball;
    }

    // деструктор
    ~Students(){
        std::cout << "Destructor ~Students(): " << '\n';
    };

private:

    // Промежуточные оценки
    int scores[5];

    // Средний балл
    float average_ball;

    // Имя
    std::string name;

    // Фамилия
    std::string last_name;
};

auto main() -> int {

    // Создание объекта класса Student
    Students student ;
    std::string name;
    std::string last_name;

    // Ввод имени с клавиатуры
    std::cout << "Name: «";
    getline(std::cin, name);

    // Ввод фамилии
    std::cout << "Last name: ";
    getline(std::cin, last_name);

    // Сохранение имени и фамилии в объект класса Students
    student.set_name(name);
    student.set_last_name(last_name);

    // Оценки
    int scores[5];

    // Сумма всех оценок
    int sum = 0;

    // Ввод промежуточных оценок
    for (int i = 0; i < 5; ++i) {
        std::cout << "Score " << i+1 << ": ";
        std::cin >> scores[i];

        // суммирование
        sum += scores[i];
    }

    // Сохраняем промежуточные оценки в объект класса Student
    student.set_scores(scores);

    // Считаем средний балл
    float average_ball = sum / 5.0;

    // Сохраняем средний балл в объект класса Students
    student.set_average_ball(average_ball);

    // Выводим данные по студенту
    std::cout << "Average ball for " << student.get_name() << " "
              << student.get_last_name() << " is "
              << student.get_average_ball() << std::endl;
}
/* вывод программы
Name: «Denis
Last name: Davydov
Score 1: 5
Score 2: 4
Score 3: 3
Score 4: 2
Score 5: 5
Average ball for Denis Davydov is 3.8
Destructor ~Students():
*/
```

## 3) Исправьте ошибки в программе, можно только добавлять что-то, но убирать нельзя:
```cpp
//исходный код
struct Vec2f {
float x ;
float y ;
float x_1;
float y_1;
Vec2f (float x, float y) x_1(x)
, y_1(y) {
x = x;
y = y;
}
float getLength() const {
const float lengthSquare = x * x + y * y;
return std::sqrt(lengthSquare);
}
}
int main() {
cout << vect2f.getLength() << '\n';
}
```

```cpp
// исправленный код
#include <cmath>
#include <iostream>
struct Vec2f {
    float x ;
    float y ;
    float x_1;
    float y_1;
    Vec2f (float xx, float xy): x_1(xx)
        , y_1(xy) {
        x = xx;
        y = xy;
    }
    float getLength() const {
        const float lengthSquare = x * x + y * y;
        return std::sqrt(lengthSquare);
    }
};

int main() {
    Vec2f value{5.2, 6.8};
    std::cout << value.getLength() << '\n';
}
```

## 4) Исправьте ошибки в программе.
```cpp
//исходный код
class BufferedIO {
public
enum IOError { None, Access, General, Erro = -1}
class Date {
unsigned short nWeekDay : 3, // 0..7 (3 bits)
unsigned short nMonthDay : 6, // 0..31 (6 bits)
unsigned short nMonth : 5, // 0..12 (5 bits)
unsigned short nYear : 8, // 0..100 (8 bits)
}
// Declare nested class BufferedInput.
class BufferedInput {
BufferedInput();
public
int read() {}
int Ngood() {
return _inputerror == Erro;
}
private:
int _inputerror;
}
// Declare nested class BufferedOutput.
class BufferedOutput {
BufferedOutput();
public:
int Ngood() {
return _inputerror == Erro;
}
private:
int _inputerror;
}
}
int main() {
BufferedIO _inputerror;
BufferedInput buffIn;BufferedOutput buffOut;
std::cout << _inputerror.nWeekDay << '\n';
}
```

```cpp
// исправленный код
#include<iostream>
class BufferedIO {
public:
    enum IOError { None, Access, General, Erro = -1};
    class Date {
    public:
        unsigned short nWeekDay : 3; // 0..7 (3 bits)
        unsigned short nMonthDay : 6; // 0..31 (6 bits)
        unsigned short nMonth : 5; // 0..12 (5 bits)
        unsigned short nYear : 8; // 0..100 (8 bits)
    };

    // Declare nested class BufferedInput.
    class BufferedInput {
    public:
        BufferedInput() {};
        void read() {}
        int Ngood() {
            return _inputerror == Erro;
        }
    private:
        int _inputerror;
    };

    // Declare nested class BufferedOutput.
    class BufferedOutput {
    public:
        BufferedOutput() {};
        int Ngood() {
            return _inputerror == Erro;
        }
    private:
        int _inputerror;
    };
};

int main() {
    BufferedIO::Date _inputerror;
    BufferedIO::BufferedInput buffIn;
    BufferedIO::BufferedOutput buffOut;
    std::cout << _inputerror.nWeekDay << '\n';
}
```

## 5) Исправьте ошибки в программе и выведите статическую переменную.
```cpp
//исходный код
class BufferedOutput {
short BytesWritten() {
return bytecount;
}
static void ResetCount() {
bytecount = 0;
}
static long bytecount;
};
int main() {
BufferedOutput bufOut = new BufferedOutput;
std::cout << bufOut.bytecount << '\n';
}
```

```cpp
// исправленный код
#include<iostream>

/* Перечисление констант, используемых в качетве
   возвращаемых значений из функций */
using typyRetConst = int; //псевдоним для типа констант enum
enum RetConst: typyRetConst
{
    Ok = 0, // Выполнео
    ErrData = -1, // Ошибка
    ErrMemory = -5, // Ошибка выделения памяти
    Overflow = -6, // Переполнено
    OutRange = -7, // Вне диапазона
    EndHi = -64, // Начиная с этого кода можно раширять коды возврата
    End = EndHi
};

// пространство имён для функций вывода ошибок
namespace errmess {
auto Exeption (const std::wstring &str) {
    std::wcout << L"Ошибка: " << str << '\n';
}

auto Warning (const std::wstring &str) {
    std::wcout << L"Предупреждение: " << str << '\n';
}

auto Info (const std::wstring &str) {
    std::wcout << L"Информация: " << str << '\n';
}
}// errmess

class BufferedOutput {
private:
    static long bytecount;
public:
    short BytesWrite(short byte) {
        return  bytecount = byte;
    }
    short BytesRead() const {
        return bytecount;
    }
    static void ResetCount() {
        bytecount = 0;
    }
};
long BufferedOutput::bytecount{4}; // инициализация статической переменной
int main() {
    setlocale (LC_ALL, "ru_RU.UTF-8");

    BufferedOutput *bufOut = new BufferedOutput;

    // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
    if (!bufOut) {

        // Обработка этого случая
        errmess::Exeption(L"Память не выделенна!!!");
        return ErrMemory;
    }
    bufOut->BytesWrite(5); // присваеваем значение статической переменной через метод класса
    std::wcout << L"Вывод значения статической переменной: " << bufOut->BytesRead() << '\n';
    delete bufOut;
    bufOut = nullptr;
}
/* вывод программы
Вывод значения статической переменной: 5
*/
```


## 6) Исправьте ошибки в программе причем нельзя убирать const у функции getFlag().
## Программа должна вывести 4.
```cpp
//исходный код
class X {
X(int flag) : m_flag(flag) {}
bool getFlag() const {
m_accessCount++;
return m_flag + m_accessCount;
}
private:
int m_flag;
int m_accessCount{0};
};
int main() {
X x(new X);
std::cout << x.getFlag << '\n';
}
```

```cpp
// исправленный код
#include<iostream>
class X {
public:
    X(int flag) : m_flag(flag) {}
    int getFlag() const {
        m_accessCount++;
        return m_flag + m_accessCount;
    }
private:
    int m_flag;
    mutable int m_accessCount{0};
};
int main() {
    setlocale (LC_ALL, "ru_RU.UTF-8");
    X x(3);
    std::wcout << L"Вывод переменной: " << x.getFlag() << '\n';
}
/* вывод программы
Вывод переменной: 4
*/
```

## 7) Исправьте ошибки в программе.
```cpp
//исходный код
#include <iostream>
using namespace std;
namespace box {
class Box {
double length; // Length of a box
double breadth; // Breadth of a box
double height; // Height of a box
}
};
int main() {
Box Box1;
// Declare Box1 of type Box
Box Box2;
// Declare Box2 of type Box
box::Box Box3(new Box);
// Declare Box2 of type Box
double volume = 0.0; // Store the volume of a box here
// box 1 specification
box::Box1.height = 5.0;
box::Box1.length = 6.0;
box::Box1.breadth = 7.0;
// box 2 specification
box::Box2.height = 10.0;
box::Box2.length = 12.0;
box::Box2.breadth = 13.0;
// volume of box 1
volume = box::Box1.height * box::Box1.length * box::Box1.breadth;
cout << "Volume of Box1 : " << volume <<endl;
// volume of box 2
volume = box::Box2.height * box::Box2.length * box::Box2.breadth;
cout << "Volume of Box2 : " << volume <<endl;
delete box::Box3[];
}
```

```cpp
// исправленный код
#include <iostream>
namespace box {
class Box {
public:
    double length; // Length of a box
    double breadth; // Breadth of a box
    double height; // Height of a box
};
} // box
int main() {

    // Declare Box1 of type Box
    box::Box Box1;

    // Declare Box2 of type Box
    box::Box Box2;

    // Declare Box3 of type Box
    box::Box *Box3 = new box::Box;

    // Declare volume of type double
    double volume = 0.0; // Store the volume of a box here

    // box 1 specification
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    // box 2 specification
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;

    // box 3 specification
    Box3->height = 10.5;
    Box3->length = 2.7;
    Box3->breadth = 15.8;

    // volume of box 1
    volume = Box1.height * Box1.length * Box1.breadth;
    std::cout << "Volume of Box1 : " << volume << std::endl;

    // volume of box 2
    volume = Box2.height * Box2.length * Box2.breadth;
    std::cout << "Volume of Box2 : " << volume << std::endl;

    // volume of box 3
    volume = Box3->height * Box3->length * Box3->breadth;
    std::cout << "Volume of Box3 : " << volume << std::endl;
    delete Box3;
    Box3 = nullptr;
}
/* вывод программы
Volume of Box1 : 210
Volume of Box2 : 1560
Volume of Box3 : 447.93
*/
```

## 8) Исправьте ошибки. Добавьте операторы * & в объявлении указателя на член класса.
```cpp
//исходный код
class Window {
public:
Window();
// Default constructor.
Window( int x1, int y1, int x2, int y2 ) {} // Constructor specifying Window size.
bool SetCaption( const char *szTitle ) { return 0; } // Set window caption.
const char *GetCaption() {}
// Get window caption.
char *szWinCaption;
// Window caption.
};
// Declare a pointer
char Window::*pwCaption = &Window::szWinCaption;
const char * (Window::* pfnwGC)() = Window::GetCaption;
bool (Window:: pfnwSC)( const char * ) = &Window::SetCaption;
Window wMainWindow;
Window pwChildWindow = new Window;
char *szUntitled = "Untitled - ";
int cUntitledLen = strlen(szUntitled);
int main() {
}
```

```cpp
// исправленный код
#include<iostream>
#include<cstring>

/* Перечисление констант, используемых в качетве
   возвращаемых значений из функций */
using typyRetConst = int; //псевдоним для типа констант enum
enum RetConst: typyRetConst
{
    Ok = 0, // Выполнео
    ErrData = -1, // Ошибка
    ErrMemory = -5, // Ошибка выделения памяти
    Overflow = -6, // Переполнено
    OutRange = -7, // Вне диапазона
    EndHi = -64, // Начиная с этого кода можно раширять коды возврата
    End = EndHi
};

// пространство имён для функций вывода ошибок
namespace errmess {
auto Exeption (const std::wstring &str) {
    std::wcout << L"Ошибка: " << str << '\n';
}

auto Warning (const std::wstring &str) {
    std::wcout << L"Предупреждение: " << str << '\n';
}

auto Info (const std::wstring &str) {
    std::wcout << L"Информация: " << str << '\n';
}
}// errmess
class Window {
public:
    Window(): m_x1(0), m_y1(0), m_x2(0), m_y2(0), szWinCaption(nullptr), caption(nullptr) {};

    // Default constructor.
    Window( int x1, int y1, int x2, int y2 ) {SetWindow(x1, y1, x2, y2);} // Constructor specifying Window size.
    void SetWindow(int x1, int y1, int x2, int y2) {
        m_x1 = x1;
        m_y1 = y1;
        m_x2 = x2;
        m_y2 = y2;
    }

    // Set window caption.
    RetConst SetCaption(const char* szTitle) {
       // if (caption) delete[] caption;
        if (szTitle) {
            size_t len = strlen(szTitle) + 1;
            caption = new char[len];

            // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
            if (!caption) {

                // Обработка этого случая
                errmess::Exeption(L"Память не выделенна!!!");
                return ErrMemory;
            }
            strcpy(caption, szTitle);
        } else {
            caption = nullptr;
        }
        return Ok;
    }

    // Set window szWinCaption.
    RetConst SetszWinCaption(const char* szTitle) {
        //if (szWinCaption) delete[] szWinCaption;
        if (szTitle) {
            size_t len = strlen(szTitle) + 1;
            szWinCaption = new char[len];

            // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
            if (!szWinCaption) {

                // Обработка этого случая
                errmess::Exeption(L"Память не выделенна!!!");
                return ErrMemory;
            }
            strcpy(szWinCaption, szTitle);
        } else {
            szWinCaption = nullptr;
        }
        return Ok;
    }
    const char* GetszWinCaption() const {return szWinCaption ? szWinCaption : "No szWinCaption";}
    const char* GetCaption() const {return caption ? caption : "No caption";}
    const int& Get_x1() const {return m_x1;}
    const int& Get_y1() const {return m_y1;}
    const int& Get_x2() const {return m_x2;}
    const int& Get_y2() const {return m_y2;}

    ~Window() {
        delete[] szWinCaption;
        delete[] caption;
    }

private:
    int m_x1, m_y1, m_x2, m_y2;

    // Get window caption.
    char *szWinCaption;

    // Window caption.
    char *caption;
};

void PrintWindow(const Window& x) {
    std::cout << "x1: " << x.Get_x1() << ", x2: " << x.Get_x2()
    << ", y1: " << x.Get_y1() << ", y2: " << x.Get_y2() << '\n'
    << "szWinCaption: " << x.GetszWinCaption() << '\n'
    << "caption: " << x.GetCaption() << '\n';
}


int main() {
    // Declare a pointer
    const int& (Window::*ptrGetX1)() const = &Window::Get_x1;
    const char* (Window::*ptrGetCaption)() const = &Window::GetCaption;
    RetConst (Window::*ptrSetCaption)(const char*) = &Window::SetCaption;
    RetConst (Window::*ptrSetszWinCaption)(const char*) = &Window::SetszWinCaption;

    // создаём объекты
    Window wMainWindow(10, 20, 300, 400);
    Window* pwChildWindow = new Window(50, 60, 250, 350);
    char szUntitled[] = "Untitled - ";
    int cUntitledLen = strlen(szUntitled);
    std::cout << "Строка: " << szUntitled << "длиной: " << cUntitledLen << " символов." << '\n';

    // Использование указателей на методы
    wMainWindow.SetCaption("Main Window");
    (wMainWindow.*ptrSetCaption)("Modified Main Window");
    pwChildWindow->SetszWinCaption("Child Window");
    (pwChildWindow->*ptrSetszWinCaption)("Modified Child Window");

    // Вывод информации
    PrintWindow(wMainWindow);
    PrintWindow(*pwChildWindow);

    // Демонстрация работы с указателем на метод
    std::cout << "Main window x1 via pointer: " << (wMainWindow.*ptrGetX1)() << '\n';
    std::cout << "Main window caption via pointer: " << (wMainWindow.*ptrGetCaption)() << '\n';

    delete pwChildWindow;
    return 0;
}
/* вывод программы
Строка: Untitled - длиной: 11 символов.
x1: 10, x2: 300, y1: 20, y2: 400
szWinCaption: No szWinCaption
caption: Modified Main Window
x1: 50, x2: 250, y1: 60, y2: 350
szWinCaption: Modified Child Window
caption: No caption
Main window x1 via pointer: 10
Main window caption via pointer: Modified Main Window
*/
```

