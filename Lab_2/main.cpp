/*
* Лабораторная работа № 2
*
* Тема: Исследование типов данных, лексем в IDE (интегрированной среде разработки) Qt Creator?
*
* Разработчик:Давыдов Денис Владимирович.
*
* OS:WINDOWS
*
* locale (кодировка):IBM866 / CP866 / csIBM866
*/

/* подключаем библиотеку для ввода/вывода */
#include<iostream>

/* подключаем математическую библиотеку языков */
#include<cmath>

/* подключаем библиотеку для определения характеристик общих типов переменных. */
#include<limits>

#include <iomanip> // для std::setprecision()

#include <bitset>


//main - главная функция с которой начинается исполнение программы
int main()
{
#if 0
    // Вывод номера задания
    printf("\t\t Задание № 1\n");


    // Запрос пользователю на ввод возраста
    printf("Введите ваш возраст и нажмите ввод: ");
    int age; // Обьявление переменной: возраст пользователя
    scanf("%i", &age); // Ввод возраста с клавивтуры


    // Запрос пользователю на ввод веса
    printf("Введите ваш вес и нажмите ввод: ");
    int weight; // Обьявление переменной: вес пользователя
    scanf("%i", &weight); // Ввод веса с клавиатуры


    // Запрос пользователю на ввод роста
    printf("Введите ваш рост в сантиметрах и нажмите ввод: ");
    int height; // Обьявление переменной: рост пользователя
    scanf("%i", &height); // Ввод роста с клавиатуры


    // Запрос пользователю на ввод гендерной пренадлежности
    printf("Если вы мужчина введите 1, если женщина введите 0 и нажмите ввод: ");
    int gender; // Обьявление переменной: пол пользователя
    scanf("%i", &gender); // Ввод гендерной пренадлежности с клавиатуры


    // Расчёт идеального веса по формуле Брока
    printf("\t Расчёт идеального веса по формуле Брока\n");
    float weightCalculation; // Обьявление переменной: для расчёта веса
    weightCalculation = (gender == 1) ? (height - 100) * 0.9 :(height - 100) * 0.85; // Условие и формула для расчёта веса
    printf("Ваш идеальный вес по формуле Брока = %5.2f\n", weightCalculation); // Вывод в терминал идеального веса по формуле Брока


    // Расчёт индекса массы тела
    printf("\t Расчёт индекса массы тела\n");
    float bodyMassIndex; // Обьявление переменной: для индекса массы
    bodyMassIndex = static_cast<float>(weight)/pow((static_cast<float>(height)/100),2); // Формула для расчёта индекса массы


    // Условие и вывод в терминал индекса массы тела
    if (bodyMassIndex <= 16)
    {
        printf("Выраженный дефицит массы. Ваш индекс массы тела = %5.2f \n", bodyMassIndex);
    }
    else if(bodyMassIndex >= 16 && bodyMassIndex <= 18.5)
        printf("Недостаточная (дефицит) масса тела. Ваш индекс массы тела = %5.2f \n", bodyMassIndex);

    // else if((bodyMassIndex >= 18.5) && (bodyMassIndex <= 25))
    //printf("Норма. Ваш индекс массы тела = %5.2f \t\n", bodyMassIndex);

    else if (bodyMassIndex >= 25 && bodyMassIndex <= 30)
        printf("Избыточная масса тела (предожирение). Ваш индекс массы тела = %5.2f \n", bodyMassIndex);

    else if(bodyMassIndex >= 30 && bodyMassIndex <= 35)
        printf("Ожирение первой степени. Ваш индекс массы тела = %5.2f \n", bodyMassIndex);

    else if(bodyMassIndex >= 35 && bodyMassIndex<= 40)
        printf("Ожирение второй степени. Ваш индекс массы тела = %5.2f \n", bodyMassIndex);

    else if(bodyMassIndex >= 40)
        printf("Ожирение третьей степени (морбидное). Ваш индекс массы тела = %5.2f \t\n", bodyMassIndex);

    // Условие на остановку программы. Индекс массы тела в норме
    if((bodyMassIndex >= 18.5) && (bodyMassIndex <= 25)){
        printf("Норма. Ваш индекс массы тела = %5.2f \t\n", bodyMassIndex);
        return 0;
    }


    // Условие и вывод в терминал с учётом возраста и гендерной пренадлежности
    printf("\t Расчёт индекса массы тела с учётом возраста и гендерной пренадлежности\n");
    if(gender == 1 && (age >= 19 && age <= 24) && (bodyMassIndex < 21.4))
    {
        printf("С учётом возраста у вас дефицит массы тела.\n");
    }
    else if(gender == 1 && (age >= 19 && age <= 24) && (bodyMassIndex >= 21.4 + 5))
        printf("С учетом возраста у вас имеются проблемы с лишним весом.\n");

    else if(gender == 1 && (age >= 25 && age <= 34) && (bodyMassIndex < 21.6))
        printf("С учётом возраста у вас дефицит массы тела.\n");

    else if(gender == 1 && (age >= 25 && age <= 34) && (bodyMassIndex >= 21.6 + 5))
        printf("С учетом возраста у вас имеются проблемы с лишним весом.\n");

    else if(gender == 1 && (age >= 35 && age <= 44) && (bodyMassIndex < 22.9))
        printf("С учётом возраста у вас дефицит массы тела.\n");

    else if(gender == 1 && (age >= 35 && age <= 44) && (bodyMassIndex >= 22.5 + 5))
        printf("С учетом возраста у вас имеются проблемы с лишним весом.\n");

    else if(gender == 1 && (age >= 45 && age <= 54) && (bodyMassIndex < 25.8))
        printf("С учётом возраста у вас дефицит массы тела.\n");

    else if(gender == 1 && (age >= 45 && age <= 54) && (bodyMassIndex >= 25.8 + 5))
        printf("С учетом возраста у вас имеются проблемы с лишним весом.\n");

    else if(gender == 1 && (age > 55) && (bodyMassIndex < 26.6))
        printf("С учётом возраста у вас дефицит массы тела.\n");

    else if(gender == 1 && (age > 55) && (bodyMassIndex >= 26.6 + 5))
        printf("С учетом возраста у вас имеются проблемы с лишним весом.\n");

    else if(gender == 0 && (age == 19 && age <= 24) && (bodyMassIndex < 19.5))
        printf("С учётом возраста у вас дефицит массы тела.\n");

    else if(gender == 0 && (age >= 19 && age <= 24) && (bodyMassIndex >= 19.5 + 5))
        printf("С учетом возраста у вас имеются проблемы с лишним весом.\n");

    else if(gender == 0 && (age >= 25 && age <= 34) && (bodyMassIndex < 23.2))
        printf("С учётом возраста у вас дефицит массы тела.\n");

    else if(gender == 0 && (age >= 25 && age <= 34) && (bodyMassIndex >= 23.2 + 5))
        printf("С учетом возраста у вас имеются проблемы с лишним весом.\n");

    else if(gender == 0 && (age >= 35 && age <= 44) && (bodyMassIndex < 23.4))
        printf("С учётом возраста у вас дефицит массы тела.\n");

    else if(gender == 0 && (age >= 35 && age <= 44) && (bodyMassIndex >= 23.4 + 5))
        printf("С учетом возраста у вас имеются проблемы с лишним весом.\n");

    else if(gender == 0 && (age >= 45 && age <= 54) && (bodyMassIndex < 25.2))
        printf("С учётом возраста у вас дефицит массы тела.\n");

    else if(gender == 0 && (age >= 45 && age <= 54) && (bodyMassIndex >= 25.2 + 5))
        printf("С учетом возраста у вас имеются проблемы с лишним весом.\n");

    else if(gender == 0 && (age > 55) && (bodyMassIndex < 27.3))
        printf("С учётом возраста у вас дефицит массы тела.\n");

    else if(gender == 0 && (age >= 55) && (bodyMassIndex >= 27.3 + 5))
        printf("С учетом возраста у вас имеются проблемы с лишним весом.\n");
#endif

#if 0
    // вывод номера задания
    std::cout << "\t\tЗадание № 2\n";


    // вывод размеров основных типов данных C++
    std::cout << "\t Вывод размеров основных типов данных C++\n";

    std::cout << "Длина типа int равна: " << sizeof(int) << " байт" << std::endl; // вывод длины в байтах типа int

    std::cout << "Длина типа bool равна: " << sizeof(bool) << " байт" << std::endl; // вывод длины в байтах типа bool

    std::cout << "Длина типа float равна: " << sizeof(float) << " байт" << std::endl; // вывод длины в байтах типа float

    std::cout << "Длина типа double равна: " << sizeof(double) << " байт" << std::endl; // вывод длины в байтах типа double

    std::cout << "Длина типа long равна: " << sizeof(long) << " байт" << std::endl; // вывод длины в байтах типа long

    std::cout << "Длина типа char равна: " << sizeof(char) << " байт" << std::endl; // вывод длины в байтах типа char

    std::cout << '\n';


    // вывод размеров типов данных с использованием модификаторов длины и размера
    std::cout << "\t Вывод размеров типов данных с использованием модификаторов длины и размера\n";

    std::cout << "Длина типа unsigned long long равна: " << sizeof(unsigned long long) << " байт" << std::endl; // вывод длины в байтах типа unsigned long long

    std::cout << "Длина типа unsigned int равна: " << sizeof(unsigned int) << " байт" << std::endl; // вывод длины в байтах типа unsigned int

    std::cout << "Длина типа signed int равна: " << sizeof(signed int) << " байт" << std::endl; // вывод длины в байтах типа signed int

    std::cout << "Длина типа signed char равна: " << sizeof(signed char) << " байт" << std::endl; // вывод длины в байтах типа signed char

    std::cout << "Длина типа unsigned short равна: " << sizeof(unsigned short) << " байт" << std::endl; // вывод длины в байтах типа unsigned short

    std::cout << "Длина типа long double равна: " << sizeof(long double) << " байт" << std::endl; // вывод длины в байтах типа long double

    std::cout << "Длина типа long long равна: " << sizeof(long long) << " байт" << std::endl; // вывод длины в байтах типа long long

    std::cout << '\n';


    // вывод числового диапазона типов данных в десятичной, шестнадцатеричной и в бинарной системах счисления
    std::cout << "\t Вывод числового диапазона типов данных в десятичной системе счисления\n";

    std::cout << "Числовой диапозон типа long в десятичной системе счисления от : " << std::numeric_limits<long>::min() << " до " << std::numeric_limits<long>::max()
              << ", размер: " << sizeof(long) << " байт" << '\n';

    std::cout << "Числовой диапозон типа unsigned short в десятичной системе счисления от : " << std::numeric_limits<unsigned short>::min() << " до "<< std::numeric_limits<unsigned short>::max()
              << ", размер: " << sizeof(unsigned short) << " байт" << '\n';

    std::cout << "Числовой диапозон типа bool в десятичной системе счисления от : " << std::numeric_limits<bool>::min() << " до "<< std::numeric_limits<bool>::max()
              << ", размер: " << sizeof(bool) << " байт" << '\n';

    std::cout << "Числовой диапозон типа unsigned int в десятичной системе счисления от : " << std::numeric_limits<unsigned int>::min() << " до "
              << std::numeric_limits<unsigned int>::max() << ", размер: " << sizeof(unsigned int) << " байт" << '\n';

    std::cout << "Числовой диапозон типа short в десятичной системе счисления от : " << std::numeric_limits<short>::min() << " до "<< std::numeric_limits<short>::max()
              << ", размер: " << sizeof(short) << " байт" << '\n';
    std::cout << '\n';


    std::cout << "\t Вывод числового диапазона типов данных в шестнадцатеричной системе счисления\n";

    std::cout << "Числовой диапозон типа long в шестнадцатеричной системе счисления от : " << std::hex << std::numeric_limits<long>::min() << " до "
              << std::hex << std::numeric_limits<long>::max() << ", размер: " << sizeof(long) << " байт" << '\n';

    std::cout << "Числовой диапозон типа unsigned short в шестнадцатеричной системе счисления от : "  << std::hex << std::numeric_limits<unsigned short>::min() << " до "
              << std::hex << std::numeric_limits<unsigned short>::max() << ", размер: " << sizeof(unsigned short) << " байт" << '\n';

    std::cout << "Числовой диапозон типа bool в шестнадцатеричной системе счисления от : " << std::hex << std::numeric_limits<bool>::min() << " до "
              << std::hex << std::numeric_limits<bool>::max() << ", размер: " << sizeof(bool) << " байт" << '\n';

    std::cout << "Числовой диапозон типа unsigned int в шестнадцатеричной системе счисления от : " << std::hex << std::numeric_limits<unsigned int>::min() << " до "
              << std::hex << std::numeric_limits<unsigned int>::max() << ", размер: " << sizeof(unsigned int) << " байт" << '\n';

    std::cout << "\Числовой диапозон типа short в шестнадцатеричной системе счисления от : " << std::hex << std::numeric_limits<short>::min() << " до "
              << std::hex << std::numeric_limits<short>::max() << ", размер: " << sizeof(short) << " байт" << '\n';
    std::cout << '\n';



    std::cout << "\t Вывод числового диапазона типов данных в бинарной системе счисления\n";

    std::cout << "Числовой диапозон типа char в бинарной системе счисления от : "  << std::bitset<8>(std::numeric_limits<char>::min()) << " до "
              << std::bitset<8>(std::numeric_limits<char>::max()) << ", размер: " << sizeof(char) << " байт" << '\n';

    std::cout << "Числовой диапозон типа unsigned short в бинарной системе счисления от : "  << std::bitset<16>(std::numeric_limits<unsigned short>::min()) << " до "
              << std::bitset<16>(std::numeric_limits<unsigned short>::max()) << ", размер: " << sizeof(unsigned short) << " байт" << '\n';

    std::cout << "Числовой диапозон типа bool в бинарной системе счисления от : "  << std::bitset<8>(std::numeric_limits<bool>::min()) << " до "
              << std::bitset<8>(std::numeric_limits<bool>::max()) << ", размер: " << sizeof(bool) << " байт" << '\n';

    std::cout << "Числовой диапозон типа short в бинарной системе счисления от : "  << std::bitset<16>(std::numeric_limits<short>::min()) << " до "
              << std::bitset<16>(std::numeric_limits<short>::max()) << ", размер: " << sizeof(short) << " байт" << '\n';

    std::cout << "Числовой диапозон типа int в бинарной системе счисления от : "  << std::bitset<32>(std::numeric_limits<int>::min()) << " до "
              << std::bitset<32>(std::numeric_limits<int>::max()) << ", размер: " << sizeof(int) << " байт" << '\n';
#endif

#if 0
    // вывод номера задания
    std::cout << "\t\tЗадание № 3\n";

    // запрос пользователю на ввод чисел с плавающёй точкой
    std::cout << "Введите десять чисел с плавающей точкой и нажмите ввод:\n";

    // обьявляем переменные
    double a, b, c, d, e, f, g, h, i, j;

    // ввод переменных с клавивтуры
    std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;

    // обьявляем переменную и высчитываем среднее арифметическое значение
    double arithmeticMean = (a + b + c + d + e + f + g + h + i + j)/10;

    // вывод в терминал
    std::cout << "Среднее арифметическое значение = " << arithmeticMean;
#endif

#if 0
    // вывод номера задания
    std::cout << "\t\tЗадание № 4\n";

    // обьявляем переменные
    double aValue = 34.50;
    double bValue = 0.004000;
    double cValue = 123.005;
    int dValue = 146000;

    // осуществляем вывод в экспоненциальной записи в стиле языка C++ (используя букву е, как символ экспонента).
    std::cout << aValue << " = " << aValue / 10 << "e1 в экспоненциальной записи, три значимых цифры\n" << bValue << " = " << bValue * pow(10,3) << "e-3 в экспоненциальной записи, пять значимых цифр\n"
              << cValue << " = " << cValue * pow(10,-2) << "e2 в экспоненциальной записи, шесть значимых цифр\n" << dValue << " = "
              << dValue * pow(10,-5) << "e5 в экспоненциальной записи, три значимых цифры\n";
#endif

#if 0
    // вывод номера задания
    std::cout << "\t\tЗадание № 5\n";

    // вывод подзадания
    std::cout << "1)\n";

    // манипулятор форматирования std::boolalpha:
    std::cout << std::boolalpha;

    // обьявляем булевую переменную и присваем ей булевое выражение
    bool aVal = (true && true) || false;
    std::cout << "(true && true) || false = " << aVal << std::endl; // выводим в терминал резльтат булевого выражения

    // обьявляем булевую переменную и присваем ей булевое выражение
    bool bVal = (false && true) || true;
    std::cout << "(false && true) || true = " << bVal << std::endl; // выводим в терминал резльтат булевого выражения

    // обьявляем булевую переменную и присваем ей булевое выражение
    bool cVal = (false && true) || false || true;
    std::cout << "(false && true) || false || true = " << cVal << std::endl; // выводим в терминал резльтат булевого выражения

    // обьявляем булевую переменную и присваем ей булевое выражение
    bool dVal = (5 > 6 || 4 > 3) && (7 > 8);
    std::cout << "(5 > 6 || 4 > 3) && (7 > 8) = " << dVal << std::endl; // выводим в терминал резльтат булевого выражения

    // обьявляем булевую переменную и присваем ей булевое выражение
    bool eVal = !(7 > 6 || 3 > 4);
    std::cout << "!(7 > 6 || 3 > 4) = " << eVal << '\n' << std::endl; // выводим в терминал резльтат булевого выражения


    // вывод подзадания
    std::cout << "2)\n";

    // обьявляем логические константы
    const bool Value1{true};
    const bool Value2{false};
    const bool Value3{true};
    const bool Value4{false};
    const bool Value5{true};
    const bool Value6{false};

    // обьявляем переменную для логических вырожений
    bool result;

    // логические выражения
    result = ((Value1 && Value3) || (!Value2) && (Value5 || Value4));
    std::cout << "(( Value1 && Value3 ) || ( !Value2) && (Value5 || Value4)) = " << result << std::endl; // вывод в терминал логического выражения с резльтатом

    result = ((Value2 && Value4) || (Value6 && Value1) || (!Value3));
    std::cout << "((Value2 && Value4) || (Value6 && Value1) || (!Value3)) = " << result << std::endl; // вывод в терминал логического выражения с резльтатом

    result = ((!Value3 || Value2) && (Value4 || Value6) && (Value1||Value5));
    std::cout << "((!Value3 || Value2) && (Value4 || d1) && (Value1||Value5)) = " << result << std::endl; // вывод в терминал логического выражения с резльтатом

    // Объявляем новое перечисление IntVariable
    enum IntVariable{
        // Ниже находятся перечислители
        // Каждый перечислитель разделяется запятой, НЕ точкой с запятой
        ONE, // присвоено 0
        TWO, // присвоено 1
        THREE, // присвоено 2
        FOUR, // присвоено 3
        FIVE, // присвоено 4
        SIX, // присвоено 5
    };

    // логическое выражение с перечмслениями
    result = ((FIVE > ONE) && (TWO < THREE) && (SIX != FOUR));
    std::cout << "((FIVE > ONE) && (TWO < THREE) && (SIX != FOUR)) = " << result << '\n' << std::endl; // вывод в терминал логического выражения с резльтатом



    // вывод подзадания
    std::cout << "3)\n";

    std::cout << "Проверка законв де Моргана\n";

    // обьявляем логические переменные
    bool val1{true};
    bool val2{false};

    // условие проверки закона де Моргана
    if(!(val1 && val2) == (!val1) || (!val2))
    {
        std::cout << "!(val1 && val2) == (!val1) || (!val2)  Да всё верно!" << '\n'; //вывод в терминал результата проерки
    }
    else std::cout << "Упс ошибочка вышла!\n"; //вывод в терминал результата проерки

    // условие проверки закона де Моргана
    if(!(val1 || val2) == (!val1) && (!val2))
    {
        std::cout << "!(val1 || val2) == (!val1) && (!val2)  Да всё верно!" << '\n'; //вывод в терминал результата проерки
    }
    else std::cout << "Упс ошибочка вышла!"; //вывод в терминал результата проерки
    std::cout << '\n';


    // вывод подзадания
    std::cout << "4)\n";

    // обьявляем переменные
    int x, y, z, v;
    bool logicValue;

    // запрос пользователю на ввод целочисленных чисел
    std::cout << "Введите целочисленные значения для x, y, z, v и нажмите ввод \n";
    std::cin >> x >> y >> z >> v; // ввод значений с клавиатуры

    x = 3 + 4 + 5; // присваеваем переменной x значение выражения
    std::cout << "Первое выражение x = 3 + 4 + 5\n";
    std::cout <<"x = " << x << '\n' << "y = " << y << '\n' << "z = " << z << '\n'; // выводим в терминал значения переменных x, y, z

    x = y = z;  // присваем переменной y значение переменной z , потом присваеваем переменной x значение переменной y
    std::cout << "Второе выражение x = y = z\n";
    std::cout <<"x = " << x << '\n' << "y = " << y << '\n' << "z = " << z << '\n'; // выводим в терминал значения переменных x, y, z

    z *= ++y + 5; // ((y + 1 ) + 5) * z
    std::cout << "Третье выражение z *= ++y + 5\n";
    std::cout <<"x = " << x << '\n' << "y = " << y << '\n' << "z = " << z << '\n'; // выводим в терминал значения переменных x, y, z

    // обьявляем переменню для логического выражения
    logicValue = x || y && z || v;
    std::cout <<"logicValue = x || y && z || v = " << logicValue << '\n' << '\n'; // выводим в терминал значения переменной logicValue

    /* Вопрос по выражению 4: какие значения должны иметь переменные x, y, z, v, чтобы переменная logicValue приняла значение false?
     * значение переменных должны быть нулевыми */


    // вывод подзадания
    std::cout << "5)\n";

    // обьявление и вычисление  переменной для максимального чила
    float powVal = pow(2,4);

    // запрос пользователю на ввод числа
    std::cout <<"Введите число от 0 до " << powVal << " и нажмите ввод: ";

    int rangeVal; // обьявляем переменную для ввода числа с клавиатуры
    std::cin >> rangeVal; // ввод числа

    // запрос пользователю на ввод числа на  которое нужно сдвинуть
    std::cout << "Введите число на которое необходимо сдвинуть число влево и нажмите ввод: ";

    int shiftVal; // // обьявляем переменную для ввода числа с клавиатуры

    std::cin >> shiftVal; // // ввод числа

    std::cout << "Результат в десятичном виде = " << (rangeVal << shiftVal) << '\n'; // вывод результата

    std::cout << "Результат в шестнадцатеричном виде = " << std::hex << (rangeVal << shiftVal) << '\n'; // вывод результата

    std::cout << "Результат в восмиричном виде = " << std::oct << (rangeVal << shiftVal) << '\n'; // вывод результата

    std::cout << "Результат в бинарном виде = " << std::bitset<32>(rangeVal << shiftVal) << '\n'; // вывод результата


    // вывод подзадания
    std::cout << "6)\n";

    // обьявление переменных
    int a{5};
    int b{10};
    int k{3};

    // вычисление выражений
    int res1 = a + b * 1 - 128/5;
    int res2 = a | b >> 1;
    int res3 = a / b * k;

    std::cout << "res1 = " << res1 << '\n' << "res2 = " <<res2 << '\n' << "res3 = " <<res3 << '\n' ; // вывод результата
    return 0;

#endif
}
