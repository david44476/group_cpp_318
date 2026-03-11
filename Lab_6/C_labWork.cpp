#include<iostream>
#include<clocale>
#include<string>
#include<limits>
#include<iomanip>
#include"errmess.h" // функции для вывода ошибок
#include"C_labWork.h" // обьявляем класс
#include"denamic_objects.h" // функции для динамической памяти

// конструктор без параметров
 C_labWork::C_labWork() {
    std::wcout << L"Конструктор без параметров вызвался!!!\n";
    this->WrlabWork();
}

// конструктор с параметрами о разработчике по умочанию
C_labWork::C_labWork(const wstr& f_devLop, const wstr& f_group) {
    std::wcout << L"Конструктор с параметрами о разработчике по умолчанию вызвался!!!\n";
    if ((f_devLop.empty()) || (f_group.empty())) {
        errmess::Warning(L"Вы не ввели данные разработчика!!!\n");
        this->WrDevLop();
        this->WrGroup();
    } else {
        m_devLop.s_devLop = f_devLop;
        m_devLop.s_group = f_group;
    }

    // устанавливаем переменную номер лабораторной работы
    if ((!m_devLop.s_devLop.empty()) && (!m_devLop.s_group.empty())) {
        this->WrLabWorkNum();
    } else {
        this->WrDevLop();
        this->WrGroup();
    }

    // устанавливаем тему лабораторной работы
    if (m_titlePage.s_labWorkNum) {
        this->WrTopLabWork();
    } else this->WrLabWorkNum();

    // устанавливаем цели лабораторной работы
    if (m_titlePage.s_topLabWork) {
        this->WrObjLabWork();
    } else this->WrTopLabWork();

    // устанавливаем операционную систему лабораторной работы
    if (m_titlePage.s_objLabWork) {
        this->WrOperSystem();
    } else this->WrObjLabWork();

    // устанавливаем локаль(кодировка) лабораторной работы
    if (m_titlePage.s_operSystem) {
        this->WrLoc();
    } else this->WrOperSystem();
}

// конструктор с параметрами о лабораторной работе и разработчике по умочанию
C_labWork::C_labWork(const ushort& f_labWorkNum, const wstr& f_topLabWork, const wstr& f_objLabWork,
                     const wstr& f_devLop, const wstr& f_group) {
    std::wcout << L"Конструктор с параметрами о лабораторной работе и разработчике по умочанию вызвался!!!\n";

    // если f_labWorkNum больше 0
    if (f_labWorkNum > 0) {

        // выделяем динамическую память для переменной m_titlePage.s_labWorkNum
        m_titlePage.s_labWorkNum = new (std::nothrow)ushort;

        // проверяем выделилась память
        if (MemoError(m_titlePage.s_labWorkNum)) {

            // присваеваем m_titlePage.s_labWorkNum значение f_labWorkNum
            *m_titlePage.s_labWorkNum = f_labWorkNum;
        }
    } else this->WrLabWorkNum(); // устанавливаем номер лабораторной работы

    // если строка f_topLabWork не пустая
    if (!f_topLabWork.empty()) {

        // выделяем динамическую память для переменной m_titlePage.s_topLabWork
        m_titlePage.s_topLabWork = new (std::nothrow)wstr;

        // проверяем выделилась память
        if (MemoError(m_titlePage.s_topLabWork)) {

            // присваеваем m_titlePage.s_topLabWork значение f_topLabWork
            *m_titlePage.s_topLabWork = f_topLabWork;
        }
    } else this->WrTopLabWork(); // устанавливаем тему лабораторной работы

    // если строка f_objLabWork не пустая
    if (!f_objLabWork.empty()) {

        // выделяем динамическую память для переменной m_titlePage.s_objLabWork
        m_titlePage.s_objLabWork = new (std::nothrow)wstr;

        // проверяем выделилась память
        if (MemoError(m_titlePage.s_objLabWork)) {

            // присваеваем m_titlePage.s_objLabWork значение f_objLabWork
            *m_titlePage.s_objLabWork = f_objLabWork;

            // Заменяем ';' на '\n'
            this->ReplaceAll(*m_titlePage.s_objLabWork, L";", L"\n");
        }
    } else this->WrObjLabWork(); // устанавливаем цели лабораторной работы

    // если строка f_devLop не пустая
    if (!f_devLop.empty()) {

        // присваеваем m_devLop.s_devLop значение f_devLop
        m_devLop.s_devLop = {f_devLop};
    } else this->WrDevLop(); // устанавливаем разработчика лабораторной работы

    // если строка f_group не пустая
    if (!f_group.empty()) {

        // присваеваем m_devLop.s_groupзначение f_group
        m_devLop.s_group = {f_group};
    } else this->WrGroup(); // устанавливаем группу разработчика лабораторной работы

    // устанавливаем операционную систему лабораторной работы
    if (m_titlePage.s_objLabWork) {
        this->WrOperSystem();
    } else this->WrObjLabWork();

    // устанавливаем локаль(кодировка) лабораторной работы
    if (m_titlePage.s_operSystem) {
        this->WrLoc();
    } else this->WrOperSystem();
}

// деструктор
C_labWork::~C_labWork() {
    std::wcout << L"Деструктор отработал!!!\n";
    DelObj(m_titlePage.s_labWorkNum);
    DelObj(m_titlePage.s_topLabWork);
    DelObj(m_titlePage.s_objLabWork);
    DelObj(m_titlePage.s_operSystem);
    DelObj(m_titlePage.s_loc);
}

// устанавливаем поля класса
void C_labWork::WrlabWork() {

    // устанавливаем номер лабораторной работы
    this->WrLabWorkNum();

    // устанавливаем тему лабораторной работы
    if (m_titlePage.s_labWorkNum) {
        this->WrTopLabWork();
    } else this->WrLabWorkNum();


    // устанавливаем цели лабораторной работы
    if (m_titlePage.s_topLabWork) {
        this->WrObjLabWork();
    } else this->WrTopLabWork();

    // устанавливаем операционную систему лабораторной работы
    if (m_titlePage.s_objLabWork) {
        this->WrOperSystem();
    } else this->WrObjLabWork();

    // устанавливаем локаль(кодировка)
    if (m_titlePage.s_operSystem) {
        this->WrLoc();
    } else this->WrOperSystem();

    // устанавливаем разработчика лабораторной работы
    if (m_titlePage.s_loc) {
        this->WrDevLop();
    } else this->WrLoc();

    // устанавливаем группу разработчика лабораторной работы
    if (!m_devLop.s_devLop.empty()) {
        this->WrGroup();
    } else this->WrDevLop();
}

// устанавливаем переменную номер лабораторной работы
void C_labWork::WrLabWorkNum() {
    wstr str{};
    do {
        std::wcout << L"Введите номер лабораторной работы и нажмите ввод: ";

        // вводим номер лабораторной работы
        if (std::getline(std::wcin, str)) {

            // если строка пустая выводим сооющения
            if (str.empty()) {
                errmess::Warning(L"Вы не ввели номер лабораторной работы!\n");
            } else {

                // в цикле прверяем является ли символ строки числом
                for (size_t i{0}; i < str.length(); ++i) {
                    if (!(isdigit(str[i]))) {
                        errmess::Warning(L"Некорректный формат ввода! Введите число!!!\n");
                        str.clear();
                    }
                }
            }
        }
    } while (str.empty());

    // выделяем динамическую память для переменной m_titlePage.s_labWorkNum
    m_titlePage.s_labWorkNum = new (std::nothrow)ushort;

    // проверяем выделилась память
    if (MemoError(m_titlePage.s_labWorkNum)) {

        /* если память выделилась присваеваем  m_titlePage.s_labWorkNum значение
         * str с преобразованием в число*/
        *m_titlePage.s_labWorkNum = std::stoi(str);
    } else DelObj(m_titlePage.s_labWorkNum); // иначе удаляем объект
}

// устанавливаем тему лабораторной работы
void C_labWork::WrTopLabWork() {
    wstr str{};
    do {
        std::wcout << L"Введите тему лабораторной работы "
                      "(например, \"Исследование С++ классов в IDE Qt Creator\") и нажмите ввод: ";

        // Вводим тему лабораторной работы
        if (std::getline(std::wcin, str)) {

            // если строка пустая выводим сооющения
            if (str.empty()) {
                errmess::Warning(L"Вы не ввели тему лабораторной работы!\n");
            }
        } else {
            errmess::Exeption(L"ввода темы лабораторной работы!\n");
            return; // Завершаем функцию при ошибке ввода
        }
    } while (str.empty());

    // Выделяем память только один раз после успешного ввода
    m_titlePage.s_topLabWork = new (std::nothrow) wstr;

    // если память выделина
    if (MemoError(m_titlePage.s_topLabWork)) {

        // присваеваем  m_titlePage.s_topLabWork значение str
        *m_titlePage.s_topLabWork = str;
    } else DelObj(m_titlePage.s_topLabWork); // иначе удаляем объект
}

// устанавливаем цели лабораторной работы
void C_labWork::WrObjLabWork() {
    wstr str{};
    do {
        std::wcout << L"Введите цели лабораторной работы строго через ';' например: "
                      "1.Закрепить на практике представление о классах;\n"
                      "2.Научиться инкапсулировать данные в классах языка С++. "
                      "и нажмите ввод: ";

        // Вводим цели лабораторной работы
        if (std::getline(std::wcin, str)) {

            // если строка пустая выводим сооющения
            if (str.empty()) {
                errmess::Warning(L"Вы не ввели цели лабораторной работы!\n");
            }
        } else {
            errmess::Exeption(L"ввода целей лабораторной работы!\n");
            return; // Завершаем функцию при ошибке ввода
        }
    } while (str.empty());

    // Выделяем память только один раз после успешного ввода
    m_titlePage.s_objLabWork = new (std::nothrow) wstr;

    // если память выделина
    if (MemoError(m_titlePage.s_objLabWork)) {

        // Заменяем ';' на '\n'
        this->ReplaceAll(str, L";", L"\n");

        // присваеваем  m_titlePage.s_objLabWork значение str
        *m_titlePage.s_objLabWork = str;
    } else DelObj(m_titlePage.s_objLabWork); // иначе удаляем объект
}

// устанавливаем операционную систему лабораторной работы
void C_labWork::WrOperSystem() {

    // выделяем динамическую память для переменной m_titlePage.s_operSystem
    m_titlePage.s_operSystem = new (std::nothrow)wstr;

    // проверяем выделилась память или нет
    if (MemoError(m_titlePage.s_objLabWork)) {

        // присваеваем значение переменной m_titlePage.s_operSystem
        *m_titlePage.s_operSystem = {this->GetOsName()};
    } else DelObj(m_titlePage.s_operSystem); // иначе удаляем объект
}

// устанавливаем локаль(кодировка) лабораторной работы
void C_labWork::WrLoc() {
    wstr loc{this->LocToWstr(std::setlocale(LC_ALL, nullptr))};

    // если строка не пустая
    if (!loc.empty()) {

        // выделяем динамическую память для переменной m_titlePage.s_loc
        m_titlePage.s_loc = new (std::nothrow)wstr;

        // проверяем выделилась память
        if (MemoError(m_titlePage.s_loc)) {

            // присваеваем значение переменной m_titlePage.s_loc
            *m_titlePage.s_loc = loc;
        } else DelObj(m_titlePage.s_loc); // иначе удаляем объект
    } else return;
}

// устанавливаем разработчика лабораторной работы
void C_labWork::WrDevLop() {
    do {
        std::wcout << L"Введите фамилию имя отчество разработчика лабораторной работы например: "
                      "Давыдов Денис Владимирович и нажмите ввод: ";

        // если ошибка ввода или строка пустая выводим сообщение
        if (!(std::getline(std::wcin, m_devLop.s_devLop)) || (m_devLop.s_devLop.empty())) {
            errmess::Warning(L"Вы не ввели данные разработчика лабораторной работы!!!\n");
        }
    } while (m_devLop.s_devLop.empty());
}

// устанавливаем группу разработчика лабораторной работы
void C_labWork::WrGroup() {
    do {
        std::wcout << L"Введите группу разработчика лабораторной работы например: "
                      "\"cpp_318\" и нажмите ввод: ";

        // если ошибка ввода или строка пустая выводим сообщение
        if (!(std::getline(std::wcin, m_devLop.s_group)) || m_devLop.s_group.empty()) {
            errmess::Warning(L"Вы не ввели группу разработчика лабораторной работы!!!\n");
        }
    } while (m_devLop.s_group.empty());
}

// устанавливаем переменную номер задания
void C_labWork::WrTask() {
        std::wcout << L"Ведите номер задания от " << static_cast<ushort>(ProgrEnum::Task_2) << L" до "
                   <<  static_cast<ushort>(ProgrEnum::Task_Max) << L" и нажмите ввод: ";
        m_task.s_taskNum = this->TypeThecking(m_task.s_taskNum, static_cast<ushort>(ProgrEnum::Task_2),
                                              static_cast<ushort>(ProgrEnum::Task_Max));
}

// читаем переменную номер задания
const ushort& C_labWork::RdTask() const {return m_task.s_taskNum;}

// устанавливаем текс задания
void C_labWork::WrTaskText(const wstr& f_taskText)  {
    if (!f_taskText.empty()) {
        m_task.s_taskText = f_taskText;
    } else errmess::Warning(L"Текст задания лабораторной работы отсутствует!!!\n");
}

// функция замены символов
void C_labWork::ReplaceAll(wstr& f_str, const wstr f_from, const wstr f_to) {
    if (f_from.empty()) {
        return;
    }
    wstr result;
    size_t pos{0};
    size_t from_len{f_from.length()};

    while (pos < f_str.length()) {
        size_t found_pos{f_str.find(f_from, pos)};
        if (found_pos == wstr::npos) {
            // Больше вхождений нет — копируем остаток
            result.append(f_str, pos);
            break;
        }

        // Копируем часть до вхождения
        result.append(f_str, pos, found_pos - pos);
        // Добавляем строку замены
        result += f_to;
        // Перемещаем позицию после найденного вхождения
        pos = found_pos + from_len;

    }
    f_str = std::move(result);
}

// функция преобразования локали в std::wstring
wstr C_labWork::LocToWstr(const char* f_input) {
    if (!f_input) {
        return L"";
    }
    wstr result{};
    for (const char* p = f_input; *p; ++p) {
        if (static_cast<unsigned char>(*p) < 128) { // ASCII
            result += static_cast<wchar_t>(*p);
        } else {
            // Для не‑ASCII заменяем на вопросительный знак
            result += L'?';
        }
    }
    return result;
}

// функция выбора задания
const ProgrEnum C_labWork::TaskSelec(const ushort& f_choice) const {

    // выбор задания
    switch (f_choice) {
    case 1: {
        errmess::Info(L"Вы выбрали задание № 1\n");
        return ProgrEnum::Task_1;
        break;
    }
    case 2: {
        errmess::Info(L"Вы выбрали задание № 2\n");
        return ProgrEnum::Task_2;
        break;
    }
    case 3: {
        errmess::Info(L"Вы выбрали задание № 3\n");
        return ProgrEnum::Task_3;
        break;
    }
    case 4: {
        errmess::Info(L"Вы выбрали задание № 4\n");
        return ProgrEnum::Task_4;
        break;
    }
    case 5: {
        errmess::Info(L"Вы выбрали задание № 5\n");
        return ProgrEnum::Task_5;
        break;
    }
    }
    return ProgrEnum::Task_Max;
}

// функция проверки корректности ввода номера задания
const ushort& C_labWork::TypeThecking(ushort& f_a, const ushort& f_min, const ushort& f_max) const {
    while (true) {

        // Пытаемся считать число
        if (std::wcin >> f_a) {

            // Ввод успешен, проверяем диапазон
            if (f_a >= f_min && f_a <= f_max) {

                // Корректный ввод — выходим из цикла
                break;
            } else {
                errmess::Exeption(L"Номер задания вне допустимого диапазона [" +
                                  std::to_wstring(f_min) + L"–" +
                                  std::to_wstring(f_max) + L"]. Попробуйте ещё раз: ");
            }
        } else {

            // Ошибка ввода (некорректный формат)
            errmess::Exeption(L"Некорректный формат ввода! Введите число от " +
                              std::to_wstring(f_min) + L" до " +
                              std::to_wstring(f_max) + L": ");
        }

        // Очищаем флаги ошибок и буфер ввода
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
    }
    return f_a;
}

// функция проверки корректности ввода выхода из программы
const wchar_t& C_labWork::TypeThecking(wchar_t& f_c) const {
    while (true) {

        // Пытаемся считать символ
        if (std::wcin >> f_c) {

            // если введеный символ число
            if (isdigit(f_c)) {

                // Ошибка ввода (некорректный формат)
                errmess::Exeption(L"Некорректный формат ввода! Введите символ \"Д\" или \"Н\": ");
                std::wcin.clear();
                std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
                continue;
            }

            // Нормализуем ввод к нижнему регистру для упрощения проверки
            f_c = std::towlower(f_c);

            // Проверяем, входит ли введёный символ в допустимый набор
            if (f_c == L'д' || f_c == L'н') {

                // Успешный ввод корректного символа — выходим из цикла
                break;
            } else {
                errmess::Exeption(L"Вы ввели неверный символ! Попробуйте ещё: ");
                std::wcin.clear();
                std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            }
        }
    }
    return f_c;
}

// функция определения операционной системы
const wstr C_labWork::GetOsName() const {
#ifdef _WIN32
    return L"Windows (32-bit)";
#elif defined(_WIN64)
    return L"Windows (64-bit)";
#elif defined(__linux__)
    return L"Linux";
#elif defined(__APPLE__) || defined(__MACH__)
    return L"macOS";
#else
    return L"Unknown OS";
#endif
}

// функция вывода данных о лабораторной работе 'Титульный лист'
void C_labWork::PrintLab(ushort f_fieldWidth, wchar_t f_separator) {

    // проверяем указатели на nullptr
    if (!m_titlePage.s_labWorkNum || !m_titlePage.s_topLabWork ||
        !m_titlePage.s_objLabWork || !m_titlePage.s_operSystem ||
        !m_titlePage.s_loc)
    {
        errmess::Exeption(L"Не все данные титульного листа инициализированы!\n");
        return;
    }

    //std::wcout.imbue(std::locale(""));
    auto separatorLine{wstr(f_fieldWidth * 2, f_separator)};

    // Заголовок с разделителем
    std::wcout << separatorLine << '\n';
    std::wcout << std::setw(f_fieldWidth) << std::right << L"Лабораторная работа № "
               << *m_titlePage.s_labWorkNum << '\n';
    std::wcout << separatorLine << '\n'; // разделитель

    // поля с выравниванием
    std::wcout << std::setw(f_fieldWidth) << std::left << L"Тема:"
               << *m_titlePage.s_topLabWork << '\n';
    std::wcout << std::setw(f_fieldWidth) << std::left << L"Цели:"
               << '\n' << *m_titlePage.s_objLabWork << '\n';
    std::wcout << std::setw(f_fieldWidth) << std::left << L"Разработчик:"
               << m_devLop.s_devLop << '\n';
    std::wcout << std::setw(f_fieldWidth) << std::left << L"Группа:"
               << m_devLop.s_group << '\n';
    std::wcout << std::setw(f_fieldWidth) << std::left << L"Операционная система:"
               << *m_titlePage.s_operSystem << '\n';
    std::wcout << std::setw(f_fieldWidth) << std::left << L"Локаль(кодировка):"
               << *m_titlePage.s_loc << '\n';

    // завершающий разделитель
    std::wcout << separatorLine << '\n';
}

// функция вывода данных по заданию
void C_labWork::PrintTask(ushort f_fieldWidth, wchar_t f_separator) {
    if (!m_task.s_taskNum || m_task.s_taskText.empty()) {
        errmess::Exeption(L"Не все данные задания инициализированы!");
        return;
    }

    //std::wcout.imbue(std::locale(""));
    auto separatorLine{wstr(f_fieldWidth * 2, f_separator)};

    // заголовок с разделителем
    std::wcout << separatorLine << '\n';
    std::wcout << std::setw(f_fieldWidth) << std::right << L"Задание № "
               << m_task.s_taskNum << ')' << '\n';
    std::wcout << separatorLine << '\n'; // разделитель

    // текст задания с выравниванием
    std::wcout << std::setw(f_fieldWidth) << std::left << L"Текст задания:"
               << '\n' << m_task.s_taskText << '\n';

    // завершающий разделитель
    std::wcout << separatorLine << '\n';
}

// функция для останоки или продолжения выполнения программы по выбору пользователя
const bool C_labWork::StopLab() const  {
    bool  stop{false};

    // запрос пользователю на выбор действия
    errmess::Info(L"Хотите продолжить введите 'Д', а если хотите прекратить 'Н' и нажмите ввод: ");
    wchar_t choice{this->TypeThecking(choice)}; // проверка на корректность ввода;

    // условие для действия по выбору пользователя
    if (choice == L'Д' || choice == L'д') stop = false;

    else if (choice == L'Н' || choice == L'н') stop = true;
    return stop;
}
