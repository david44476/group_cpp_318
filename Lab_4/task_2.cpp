#include<iostream>
#include<time.h>


auto Task_2a () -> void
{
    constexpr short sArray {5};  // ��६����� ��� ����� ���ᨢ�
    short MyArray [sArray] [sArray];  // ᮧ��� ���ᨢ

    for (short i = 0; i < sArray; ++i)
    {
        for (short j = 0; j < sArray; ++j)
        {
            if (i == j) {MyArray [i] [j] = 1;}

            else {MyArray [i] [j] = 0;}

            std::cout << MyArray [i] [j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "������ �����: = " << sizeof (MyArray ) << " ���� \n";
}

auto Task_2b () -> void
{
    constexpr short sMatrix {8};  // ��६����� ��� ����� ���ᨢ�
    short MyMatrix [sMatrix] [sMatrix];  // ᮧ��� ���ᨢ
    short S;  // ��६����� ��� �㬬� ����⮢ ������, ������ ��� ������� ���������
    const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    short min = -15;  // ��६����� ��� �������쭮�� ���������
    short max = 15;   // ��६����� ��� ���ᨬ��쭮�� ���������
    srand (static_cast<unsigned short>(time (nullptr)));

    for (short i = S = 0; i < sMatrix; ++i)
    {
        for (short j = 0; j < sMatrix; ++j)
        {
            short result = static_cast<short>(rand() * fraction * (max - min + 1) + min) ;
            MyMatrix [i] [j] = result;
            std::cout << MyMatrix [i] [j] <<  '\t';
            if (i < j) {S += MyMatrix [i] [j];}
        }
        std::cout << '\n';
    }
    std::cout << "�㬬� ����⮢ ������, ������ ��� ������� ��������� = " << S << '\n';
}
