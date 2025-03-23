#include<iostream>

int iVal{77}; // глобальная переменная

void Initialization() //фнкция для инициализации разными способами
{
  int iVal{66}; // локальная переменная

  int iValue = 5; // копирующая инициализация

  bool bValue (true); // прямая инициализация

  char cValue {'7'}; // списки инициализации

  auto lValue = 9223372036854775807; // auto инициализация

  std::cout << iValue << '\n' << bValue << '\n' << cValue << '\n' << lValue << '\n';
  std::cout << "Глобальная переменная: " << ::iVal << '\n' << "Локальная переменная: " << iVal << '\n';
}
