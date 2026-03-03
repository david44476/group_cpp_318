#include<string>
#include"constans.h"
#include"errmess.h"

// псевдоним типа
using wstr = std::wstring;

// обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
auto MemoError(const wstr* f_ptr) -> RetConst {
    if (!f_ptr) {

        // Обработка этого случая
        errmess::Exeption(L"Память не выделенна!!!");
    }
    return ErrMemory;
}

// очистка динамической памяти
auto deletObject(const wstr* f_dinObj) -> void {
    if (f_dinObj) {
        delete f_dinObj;
        f_dinObj = nullptr;
    }
}
