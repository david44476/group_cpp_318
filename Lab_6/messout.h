#ifndef MESSOUT_H
#define MESSOUT_H
#include"constans.h" // содержит константы

// пространство имён функций вывода ошибок
namespace MessOut {
void Exeption(const wstr &); // ошибка

void Warning(const wstr &); // внимание

void Info(const wstr &); // информация

void Every(const wstr &); // всё хорошо

void Input(const wstr &); // ввод

void Create(const wstr &); // создаём
}// errmess
#endif // MESSOUT_H
