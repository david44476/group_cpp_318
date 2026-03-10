// #include<string>
// #include"constans.h"
// #include"errmess.h"

// // псевдонимы типов
// using wstr = std::wstring;
// using ushort = unsigned short;

// // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)
// auto MemoError(const ushort* f_ptr) -> RetConst {
//     if (!f_ptr) {

//         // Обработка этого случая
//         errmess::Exeption(L"Память не выделенна!!!");
//         return ErrMemory;
//     }
//     else return Ok;
// }

// // обрабатываем случай, когда new возвращает null (т.е. память не выделяется)z
// auto MemoError(const wstr* f_ptr) -> RetConst {
//     if (!f_ptr) {

//         // Обработка этого случая
//         errmess::Exeption(L"Память не выделенна!!!");
//         return ErrMemory;
//     }
//     else return Ok;
// }

// // очистка динамической памяти
// auto DelObj(const wstr* f_dinObj) -> void {
//     if (f_dinObj) {
//         delete f_dinObj;
//         f_dinObj = nullptr;
//     }
// }

// // очистка динамической памяти
// auto DelObj(const ushort* f_dinObj) -> void {
//     if (f_dinObj) {
//         delete f_dinObj;
//         f_dinObj = nullptr;
//     }
// }
