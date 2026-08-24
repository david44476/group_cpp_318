#ifndef CHECKINPUT_H
#define CHECKINPUT_H

#include"errmess.h"

// деклорация функций***************************************************************************
short StrNum(const wstr &xstr); // функция преобразования строки в число
using PtrStrNum = short (*const)(const wstr &xstr);
PtrStrNum PtrNumStr = StrNum; // указатель на функцию преобразования строки в число

// перегруженная функция обработки ввода для unsigned short
short CheckInput(ushort &xvalue, const ushort &xmin, const ushort &xmax,
                 const wstr &xstr, PtrStrNum fPtrStr = StrNum);

// псевдоним типа на функцию
using PtrChec = short (*const)(ushort &, const ushort &, const ushort &, const wstr &, PtrStrNum);
PtrChec PtrCheInput = CheckInput;
ProgrEnum TaskSel(PtrChec xPtrChec = CheckInput); // функция выбора задания
ProgrEnum (*const PtrTaskSel)(const PtrChec) = TaskSel; // указатель на функцию выбора задания
void ClearConsole(); // функция очистки окна терминала
void (*const PtrClearConsole)() = ClearConsole; // указатель на функцию очистки окна терминала
bool Exit(); // функция выхода
bool (*const PtrExit)() = Exit; // указатель на функцию выхода

// функция обработки ввода для std::wstring
bool CheckInput(wstr &, const ushort &, const ushort &, const wstr &);

// указатель на функцию обработки ввода для std::wstring
bool (*const PtrWstr)(wstr &, const ushort &, const ushort &, const wstr &) = CheckInput;

// перегруженная функция обработки ввода для std::wstring
auto CheckInput(wstr &xvalue) -> short;

// указатель на перегружкнную функцию обработки ввода
short (*const PtrInStr)(wstr &xvalue) = CheckInput;
// *********************************************************************************************

// шаблонная функция выделенния памяти
template<typename T>
auto MemAlloc(T* &xobject, const wstr &xstr) -> short {
    xobject = new(std::nothrow) T;

        // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
        if (!xobject) {
        Errmess::Exeption(L"Для объекта: " + xstr + L" память не выделена!!!");
            return Ret::ErrMemory;
    }
        return Ret::Ok;
} // шаблонная функция выделенния памяти MemAlloc

// шаблонная функция удаления памяти
template<typename T>
auto DelMem(T &xobject) -> void {
    if (xobject) {
        delete xobject; // удаляем выделенную память
        xobject = nullptr; // обнуляем указатель
    }
} // шаблонная функция удаления памяти delMem
#endif // CHECKINPUT_H
