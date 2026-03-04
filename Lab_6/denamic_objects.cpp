#include<string>
#include"constans.h"
#include"errmess.h"

// псевдоним типа
using cwstr = const std::wstring;

// обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
auto MemoError(const cwstr* f_ptr) -> RetConst {
    if (!f_ptr) {

        // Обработка этого случая
        errmess::Exeption(L"Память не выделенна!!!");
    }
    return ErrMemory;
}

// очистка динамической памяти
auto deletObject(const cwstr* f_dinObj) -> void {
    if (f_dinObj) {
        delete f_dinObj;
        f_dinObj = nullptr;
    }
}
