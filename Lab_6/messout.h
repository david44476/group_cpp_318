#ifndef MESSOUT_H
#define MESSOUT_H

#include <string>

// пространство имён функций вывода сообщений
namespace MessOut {
void Exeption(const std::wstring &); // ошибка

void Warning(const std::wstring &); // внимание

void Info(const std::wstring &); // информация

void Every(const std::wstring &); // всё хорошо

void Input(const std::wstring &); // ввод

void Create(const std::wstring &); // создаём
}; // MessOut пространство имён функций вывода сообщений
#endif // MESSOUT_H
