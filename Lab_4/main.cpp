/*
* ������ୠ� ࠡ�� � 4
*
* ����: ?��᫥������� ���ᨢ��, 㪠��⥫��, ��뫮�.?
*
* ���ࠡ��稪: ���뤮� ����� �������஢��.
*
* OS: WINDOWS
*
* locale (����஢��): IBM 866
*/

#include<iostream>
#include"functions.h"

// ᮧ��� ����᫥��� �������
enum class ProgrEnum {Task_1, Task_2, Task_3, Tak_4, Task_5, Task_6, Task_7, Task_8, Task_9};

// �롮� �����
const ProgrEnum progrEnum = ProgrEnum::Task_1;


int main() {
    // �᫮��� ��� �롮� ������� � 1
    if (progrEnum == ProgrEnum::Task_1)
    {
        constexpr short Size {10};  // ᮧ��� ��६����� ��� ����� ���ᨢ�
        short MyArray [Size];  // ᮧ��� ���ᨢ

        std::cout << "������塞 ���ᨢ � ������� ����� ���ᥭ�" << '\n';
        MersWhir (MyArray, Size);  // �맮� �㭪㨨 ��� ���������� ���ᨢ� ���६ ���ᥭ�

        std::cout << '\n' << "���������� ���ᨢ� ᢮�� ������஬ ��砩��� �ᥫ" << '\n';
        MyGen (MyArray, Size);
    }

    // �᫮��� ��� �롮� ������� � 2
    if (progrEnum == ProgrEnum::Task_2)
    {
        std::cout << "\t ������� 2.a)" << '\n' << "�뢮� �����筮� �����" << '\n';
        Task_2a ();

        std::cout << "\t ������� 2.b)" << '\n' << "��室�� �㬬� ����⮢ ������, "
                                                  "������ ��� ������� ���������:\n\t �����⭠� ����� 8*8\n";
        Task_2b ();
    }
}
