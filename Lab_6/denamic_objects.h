#ifndef DENAMIC_OBJECTS_H
#define DENAMIC_OBJECTS_H
#include <string>
#include "constans.h"

// псевдоним типа
using cwstr = const std::wstring;

// обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
auto MemoError(cwstr* f_ptr) -> RetConst;

// очистка динамической памяти
auto deletObject(cwstr* f_dinObj) -> void;
#endif // DENAMIC_OBJECTS_H
