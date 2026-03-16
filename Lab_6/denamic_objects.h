#ifndef DENAMIC_OBJECTS_H
#define DENAMIC_OBJECTS_H
#include <string>
#include"errmess.h" // функции для вывода ошибок

// обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
template <typename T>
auto MemoError(const T* f_ptr) -> bool {
    if (!f_ptr) {

        // Обработка этого случая
        errmess::Exeption(L"Память не выделенна!!!\n");
        return false;
    }
    else return true;
}

// очистка динамической памяти
template <typename T>
auto DelObj(const T* f_dinObj) -> void {
    if (f_dinObj) {
        delete f_dinObj;
        f_dinObj = nullptr;
    }
}
#endif // DENAMIC_OBJECTS_H
