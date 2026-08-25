#ifndef ERRMESS_H
#define ERRMESS_H
#include"constans.h" // содержит константы

// пространство имён функций вывода ошибок
namespace Errmess {
void Exeption(const wstr &); // ошибка

void Warning(const wstr &); // внимание

void Info(const wstr &); // информация

void Every(const wstr &); // всё хорошо

void Input(const wstr &); // ввод

void Create(const wstr &); // создаём
}// errmess
#endif // ERRMESS_H
