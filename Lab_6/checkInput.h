#ifndef CHECKINPUT_H
#define CHECKINPUT_H

#include"C_Bruteforce.h"

// деклорация функций***************************************************************************

// указатель на медот класса перебора комбинаций пароля
RetFunc (Bruteforce::*const PtrCharSearch)(const wstr &, const ushort &) = &Bruteforce::CharSearch;

// указатель на метод класса выводящий информацию о переборе
void (Bruteforce::*const PtrPrintAlpBet)(const wstr &) = &Bruteforce::PrintAlpBet;

// указатель на метод класса выводящий строку символов для перебора пароля
const wstr& (Bruteforce::*const PtrGetAlphaBet)() const = &Bruteforce::GetAlphaBet;
const ushort CharSel(); // функция выбора набора символов
const ushort (*const PtrCharSel)() = CharSel; // указатель на функцию выбора набора символов
const wstr CharInput(const ushort (*)()); // функция ввода набора символов

// указатель на функцию ввода набора символов
const wstr (*const PtrCharInput)(const ushort (*)()) = CharInput;
const wstr EnterPass(const ushort&, Bruteforce&); // функция ввода пароля

// указатель на функцию ввода пароля
const wstr (*const PtrEnterPass)(const ushort&, Bruteforce&) = EnterPass;
const ProgrEnum TaskSel(); // функция выбора задания
const ProgrEnum (*const PtrTaskSel)() = TaskSel; // указатель на функцию выбора задания
void ClearConsole(); // функция очистки окна терминала
void (*const PtrClearConsole)() = ClearConsole; // указатель на функцию очистки окна терминала
bool Exit(); // функция выхода
bool (*const PtrExit)() = Exit; // указатель на функцию выхода

// функция обработки ввода для std::wstring
bool CheckInput(wstr &, const ushort &, const ushort &, const wstr &);

// указатель на функцию обработки ввода для std::wstring
bool (*const PtrWstr)(wstr &, const ushort &, const ushort &, const wstr &) = CheckInput;

// перегруженная функция обработки ввода для unsigned short
bool CheckInput(ushort &xvalue, const ushort &xmin, const ushort &xmax, const wstr &xstr);

// указатель на перегружкнную функцию обработки ввода для unsigned short
bool (*const PtrUshor)(ushort &, const ushort &, const ushort &, const wstr &) = CheckInput;
bool CheckInput(wchar_t xchoice); // перегружкнная функция обработки ввода для wchar_t

// указатель на перегружкнную функцию обработки ввода для wchar_t
bool (*const PtrWchar)(wchar_t xchoice) = CheckInput;
// *********************************************************************************************
#endif // CHECKINPUT_H
