#include<iostream>
#include <random>

auto MersWhir (short MyArray[ ], const short size) -> void
{
    short min = 0;  // ��६����� ��� �������쭮�� ���祭��
    short max = 0;  // ��६����� ��� ���ᨬ��쭮�� ���祭��

    // ������㥬 ��砩�� �᫠
    std::random_device rd;
    std::mt19937 mers(rd());

    // 横� ��� ���������� ���ᨢ� ��砩�묨 �᫠��
    for (int i = 0; i < size; ++i)
    {
        MyArray[i] = static_cast<short>(mers());

        std::cout << MyArray[i] << '\t';  // �뢮� ����⮢ ���ᨢ�

        if (MyArray[i] < min) {min = MyArray[i];}  // ��室�� �������쭮� ���祭��
        if (MyArray[i] > max) {max = MyArray[i];}  // ��室�� ���ᨬ��쭮� ���祭��
    }
    std::cout << '\n' << "�������쭮� ���祭�� = " << min << '\n';
    std::cout << "���ᨬ��쭮� ���祭�� = " << max << std::endl;
}

auto MyGen (short MyArray[ ], const short size) -> void
{
    short min = 0;  // ��६����� ��� �������쭮�� ���祭��
    short max = 0;  // ��६����� ��� ���ᨬ��쭮�� ���祭��
    short Gmin = -20;  // ��६����� ��� �������쭮�� ���������
    short Gmax = 20;  // ��६����� ��� ���ᨬ��쭮�� ���������
    double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // �ᯮ����⥫쭠� ��६����� ��� ������� ��砩��� �ᥫ

    // 横� ��� ���������� ���ᨢ� ��砩�묨 �᫠��
    for (int i= 0; i < size; ++i)
    {
        MyArray [i] = static_cast<short>(rand() * fraction * (Gmax - Gmin + 1) + Gmin);

        std::cout << MyArray[i] << '\t';  // �뢮� ����⮢ ���ᨢ�

        if ( MyArray[i] < min) {min = MyArray[i];}  // ��室�� �������쭮� ���祭��
        if ( MyArray[i] > max) {max = MyArray[i];}  // ��室�� ���ᨬ��쭮� ���祭��
    }
    std::cout << '\n' << "�������쭮� ���祭�� = " << min << '\n';
    std::cout << "���ᨬ��쭮� ���祭�� = " << max << std::endl;
}
