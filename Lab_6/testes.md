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

    // конструктор по умолчанию без параметров
    Integer() {};

    // конструктор с параметрами
    Integer(int value) {
        m_value = value;
        std::cout << "Object created." << '\n';
    }

    // методы класса
    int getValue() {return m_value;} // читаем переменную - член класса m_value
    void setValue(int number) {m_value = number;} // записываем значение в переменную - член класса m_value

    // выводим значение переменной - члена класса
    void print() {
        std::cout << "Value: " << m_value << '\n';
    }
private:
    int m_value; // пременная - член класса
};

int main() {
    Integer integer; // создаём объект класса с помощью конструктора по умолчанию
    integer.setValue(3); // записываем значение в переменную - член класса m_value объекта integer
    std::cout << "integer Value: " << integer.getValue()
              << '\n'; // читаем переменную - член класса m_value объекта integer
    Integer inter(4); // создаём объект класса с помощью конструктора с параметрами
    inter.print(); // выводим значение переменной - члена класса объекта inter

    return 0;
}
/* вывод программы
integer Value: 3
Object created.
Value: 4
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

static constexpr unsigned size{5}; // константа для размера массива

class Students {

public:

    // Установка имени студента
    void set_name(std::string xstudent_name) {
        m_name = xstudent_name;
    }

    // Получение имени студента
    std::string get_name() {

        return m_name;
    }

    // Установка фамилии студента
    void set_last_name(std::string student_last_name) {
        m_last_name = student_last_name;
    }

    // Получение фамилии студента
    std::string get_last_name() {
        return m_last_name;
    }

    // Установка промежуточных оценок
    void set_scores(int student_scores[]) {
        for (int i = 0; i < 5; ++i) {
            m_scores[i] = student_scores[i];
        }
    }

    // Установка среднего балла
    void set_average_ball(float ball) {
        m_average_ball = ball;
    }

    // Получение среднего балла
    float get_average_ball() {
        return m_average_ball;
    }

    Students() : m_scores{0}, m_average_ball{0.0}, m_name{"\0"},  m_last_name{"\0"} {}

private:

    // Промежуточные оценки
    unsigned m_scores[size];

    // Средний балл
    float m_average_ball;

    // Имя
    std::string m_name;

    // Фамилия
    std::string m_last_name;
};

auto main() -> int {

    // Создание объекта класса Student
    Students student;
    std::string name; // переменная для ввода имени
    std::string last_name; // переменная для ввода фамилии

    // Ввод имени с клавиатуры
    std::cout << "Имя: ";
    std::getline(std::cin, name);

    // Ввод фамилии
    std::cout << "Фамилия: ";
    std::getline(std::cin, last_name);

    // Сохранение имени и фамилии в объект класса Students
    student.set_name(name);
    student.set_last_name(last_name);

    // Оценки
    int scores[size]; // массив с оценками

    // Сумма всех оценок
    int sum = 0;

    // Ввод промежуточных оценок
    for (auto i = 0; i < size; ++i) {
        std::cout << "Оценка " << i + 1 << ": ";
        std::cin >> scores[i];

        // суммирование
        sum += scores[i];
    }

    // Сохраняем промежуточные оценки в объект класса Student
    student.set_scores(scores);

    // Считаем средний балл
    float average_ball = static_cast<float>(sum) / size;

    // Сохраняем средний балл в объект класса Students
    student.set_average_ball(average_ball);

    // Выводим данные по студенту
    std::cout << "Средний балл студента " << student.get_name() << " "
              << student.get_last_name() << " состовляет "
              << student.get_average_ball() << std::endl;
}
/* вывод программы
Имя: Денис
Фамилия: Давыдов
Оценка № 1: 5
Оценка № 2: 4
Оценка № 3: 3
Оценка № 4: 2
Оценка № 5: 4
Средний балл студента Денис Давыдов состовляет: 3.6
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
#include<iostream>
#include<cmath>
struct Vec2f {
    float m_x ;
    float m_y ;
    float m_x_1;
    float m_y_1;
    Vec2f (float x, float y) : m_x_1(x)
        , m_y_1(y) {
        m_x = x;
        m_y = y;
    }
    float getLength() const {
        const float lengthSquare = m_x * m_x_1 + m_y * m_y_1;
        return std::sqrt(lengthSquare);
    }
};
int main() {
    Vec2f vect2f(2.5, 5.2);
    std::cout << vect2f.getLength() << '\n';
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
    private:
        unsigned short nWeekDay : 3; // 0..7 (3 bits)
        unsigned short nMonthDay : 6; // 0..31 (6 bits)
        unsigned short nMonth : 5; // 0..12 (5 bits)
        unsigned short nYear : 8; // 0..100 (8 bits)
    public:
        Date() : nWeekDay{4}, nMonthDay{27}, nMonth{6}, nYear{55} {}
        unsigned short GetWeekDay() {return nWeekDay;}
        unsigned short GetMnthDay() {return nMonthDay;}
        unsigned short GetMonth() {return nMonth;}
        unsigned short GetYear() {return nYear;}
    };

    // Declare nested class BufferedInput.
    class BufferedInput {
    public:
        BufferedInput() : _inputError{None} {}
        int Read() {return _inputError;}
        int Ngood() {
            return _inputError = Erro;
        }
    private:
        int _inputError;
    };

    // Declare nested class BufferedOutput.
    class BufferedOutput {
    public:
        BufferedOutput() : _outputError{None} {}
        int Read() {return _outputError;}
        int Ngood() {
            return _outputError = Erro;
        }
    private:
        int _outputError;
    };
};
int main() {
    BufferedIO::Date _inputerror;
    BufferedIO::BufferedInput buffIn;
    BufferedIO::BufferedOutput buffOut;
    std::cout << _inputerror.GetWeekDay() << '\n';
    std::cout << buffIn.Read() << '\n';
    std::cout << buffIn.Ngood() << '\n';
    std::cout << buffOut.Read() << '\n';
    std::cout << buffOut.Ngood() << '\n';
    return 0;
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
class BufferedOutput {
public:

    // Метод для получения количества байт (const, потому что не меняет состояние)
    long BytesWritten() const {
        return bytecount;
    }

    // Статический метод сброса
    static void ResetCount() {
        bytecount = 0;
    }

    // Статическая переменная: объявление в классе
    static long bytecount;
};

// Определение статической переменной (обязательно вне класса)
long BufferedOutput::bytecount{10};

int main() {
    BufferedOutput *bufOut = new BufferedOutput;

    // Демонстрация работы
    std::cout << "Текущее значение: " << BufferedOutput::bytecount << '\n';
    std::cout << "Выводим значение через метод объекта: " << bufOut->BytesWritten() << '\n';
    BufferedOutput::ResetCount(); // сбрасываем статическую переменную
    std::cout << "Текущее значение: " << BufferedOutput::bytecount << '\n';
    std::cout << "Выводим значение через метод объекта: " << bufOut->BytesWritten() << '\n';
    bufOut->bytecount = 20; // устанавливаем новое значение статической переменной через объект

    // выводим значение статической переменной через объект
    std::cout << "Текущее значение: "<< bufOut->bytecount << '\n';
    std::cout << "Выводим значение через метод объекта: " << bufOut->BytesWritten() << '\n';
    delete bufOut;
    bufOut = nullptr;
    return 0;
}
/* вывод программы
Текущее значение: 10
Выводим значение через метод объекта: 10
Текущее значение: 0
Выводим значение через метод объекта: 0
Текущее значение: 20
Выводим значение через метод объекта: 20
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
    explicit X(int flag) : m_flag(flag) {}
    int getFlag() const {
        m_accessCount++;
        return m_flag + m_accessCount;
    }
private:
    int m_flag;
    mutable int m_accessCount{0};
};
int main() {
    X x(10);
    std::cout << x.getFlag() << '\n';
    std::cout << x.getFlag() << '\n';
}
/* вывод программы
Ввывод значения переменной: 11
Ввывод значения переменной: 12
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
using namespace std;
namespace box {
class Box {
public:
    double length; // Length of a box
    double breadth; // Breadth of a box
    double height; // Height of a box
    Box() : length{0}, breadth{0}, height{0} {} // default constructor
};
}


int main() {

    // Declare Box1 of type Box
    box::Box Box1;

    // Declare Box2 of type Box
    box::Box Box2;

    // Declare Box2 of type Box
    box::Box *Box3 = new box::Box;

    // Store the volume of a box here
    double volume = 0.0;

    // box 1 specification
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    // box 2 specification
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;

    // box 3 specification
    Box3->height = 15.0;
    Box3->length = 19.0;
    Box3->breadth = 12.0;

    // volume of box 1
    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Volume of Box1 : " << volume << endl;

    // volume of box 2
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "Volume of Box2 : " << volume << endl;

    // volume of box 3
    volume = Box3->height * Box3->length * Box3->breadth;
    cout << "Volume of Box3 : " << volume << endl;
    delete Box3;
    Box3 = nullptr;
    return 0;
}
/* вывод программы
Volume of Box1 : 210
Volume of Box2 : 1560
Volume of Box3 : 3420
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
#include <cstring>
#include <iostream>
class Window {
public:

    // Default constructor.
    Window() :
        m_x1{0},
        m_x2{0},
        m_y1{0},
        m_y2{0}
    {
        szWinCaption = new char[captionMax];
        szWinCaption[0] = '\0';
    }

    // Destructor
    ~Window() {delete[] szWinCaption;}

    // Constructor specifying Window size.
    Window(int x1, int y1, int x2, int y2) : m_x1{x1}, m_x2{x2}, m_y1{y1}, m_y2{y2}
    {
        szWinCaption = new char[captionMax];
        szWinCaption[0] = '\0';
    }

    // Set window caption.
    void SetCaption(const char *szTitle) {
        if(!szTitle) return;
        size_t strLen{std::strlen(szTitle)};
        if (strLen >= captionMax) strLen = captionMax - 1;
        std::strncpy(szWinCaption, szTitle, strLen);
        szWinCaption[strLen] = '\0';
    }

    // Get window caption.
    const char *GetCaption() const {return szWinCaption;}

    static constexpr size_t captionMax{64};

    // Window caption.
    char *szWinCaption;
private:
    int m_x1, m_x2, m_y1, m_y2;
};

// Declare a pointer
char* Window::*pwCaption = &Window::szWinCaption;
const char* (Window::*pfnwGC)() const = &Window::GetCaption;
void (Window::*pfnwSC)(const char*) = &Window::SetCaption;

int main() {

    Window wMainWindow; // creating an object
    Window *pwChildWindow = new Window; // creating an object in dynamic memory
    const char *szUntitled = "Untitled - ";

    // writing the value szWinCaption of a variable through a class method
    wMainWindow.SetCaption(szUntitled);

    // displaying the value szWinCaption of a variable through a class method
    std::cout << wMainWindow.GetCaption() << '\n';
    szUntitled = "Hello world!!!";

    // writing the variable value szWinCaption through a class method pointer
    (pwChildWindow->*pfnwSC)(szUntitled);

    // displaying the variable value szWinCaption through a class method pointer
    std::cout << (pwChildWindow->*pfnwGC)() << '\n';
    //int cUntitledLen = strlen(szUntitled);
    delete pwChildWindow;
    pwChildWindow = nullptr;
    return 0;
}
/* вывод программы
Untitled -
Hello world!!!
*/
```
