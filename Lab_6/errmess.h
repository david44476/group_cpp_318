#ifndef ERRMESS_H
#define ERRMESS_H
#include <string>

// пространство имён функций вывода ошибок
namespace errmess {
void Exeption(const std::wstring &str);

void Warning(const std::wstring &str);

void Info(const std::wstring &str);
}// errmess

#endif // ERRMESS_H
