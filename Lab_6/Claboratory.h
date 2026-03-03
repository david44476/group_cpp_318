#ifndef CLABORATORY_H
#define CLABORATORY_H
#include"denamic_objects.h"
#include"constans.h"

// класс лабораторная
class Claboratory {
private:
    wstr* m_labWorkNum; // номер лабораторной работы
    wstr* m_topicLabWork; // тема лабораторной работы
    wstr* m_objecLabWork; // цели лабораторной работы
    const wstr m_devLabWork{L"Разработчик: Давыдов Денис Владимирович.\n"}; // разработчик
    const wstr m_os{L"OS: UNIX\n"}; // операционная система
    const wstr m_locale{L"locale (кодировка): UTF 8\n"}; // локаль
    const unsigned short m_min{static_cast<short>(ProgrEnum::Task_1)};
    const unsigned short m_max{static_cast<short>(ProgrEnum::Task_Max)};
public:

    // конструктор
    Claboratory(const wstr& f_labWorkNum, const wstr& f_topicLabWork, const wstr& f_objecLabWork) {
        WrClaboratory(f_labWorkNum, f_topicLabWork, f_objecLabWork);
    }

    // деструктор
    ~Claboratory() {

        // освобождаем память переменной m_labWorkNum
        deletObject(m_labWorkNum);

        // освобождаем память переменной m_topicLabWork
        deletObject(m_topicLabWork);

        // освобождаем память переменной m_objecLabWork
        deletObject(m_objecLabWork);
    }

    // чтение полей min, max класса
    const unsigned short& Rdm_min() const {return m_min;}
    const unsigned short& Rdm_max() const {return m_max;}

    // установка полей класса
    auto WrClaboratory(const wstr &f_labWorkNum, const wstr &f_topicLabWork,
                       const wstr &f_objecLabWork) -> void;

    // вывод информации по лабараторной работе
    auto PrintLab() -> void;

    // функция выбора задания
    auto TaskSelection(const short& f_choice) -> const short;

    // функция для останоки или продолжения выполнения программы по выбору пользователя
    static auto StopLab() -> bool;

    // вложенный класс задание
    class Ctask {
    private:
        const wstr m_task; // номер задания
        const wstr m_taskText; // текст задания
    public:

        // конструктор с параметрами
        Ctask(const wstr& f_task, const wstr& f_taskText): m_task{f_task}, m_taskText{f_taskText} {}

        // деструктор
        ~Ctask() {}

        // функция вывода номера и текста задания
        auto printTask() -> void;
    };
};
#endif // CLABORATORY_H
