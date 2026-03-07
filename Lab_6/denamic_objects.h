#ifndef DENAMIC_OBJECTS_H
#define DENAMIC_OBJECTS_H
#include <string>
#include "constans.h"

// псевдоним типа
using wstr = std::wstring;
using ushort = unsigned short;

// обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
auto MemoError(const ushort* f_ptr) -> RetConst;

auto MemoError(const wstr* f_ptr) -> RetConst;

// очистка динамической памяти
auto DelObj(const ushort* f_dinObj) -> void;

// очистка динамической памяти
auto DelObj(const wstr* f_dinObj) -> void;
#endif // DENAMIC_OBJECTS_H
