#include<iostream>
#include<limits>

// �஢�ઠ �� ��४⭮��� �����
auto Type_Thecking (short a, short min, short max) -> short
{
    while (true)
    {
        if (! (std::cin >> a) || a < min || a > max || a == ' ')
        {
            std::cout << "�� ����� �� ���� ����!" << '\n' << "���஡�� ���: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<short>::max(), '\n');
        }
        else break;
    }
    return (a);
}


// �஢�ઠ �� ��४⭮��� �����
auto Type_Thecking (char c) -> char
{
    while (true)
    {
        std::cin >> c;
        if ( ! (c == 'Y' || c == 'y' || c == 'N' || c == 'n') || c == ' ')
        {
            std::cout << "�� ����� �� ���� ᨬ���!" << '\n' << "���஡�� ���: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<char>::max(), '\n');
        }
        else break;
    }
    return (c);
}


// �஢�ઠ �� ��४⭮��� �����
auto Type_Thecking (short a) -> short
{
    while (true)
    {
        if (! (std::cin >> a))
        {
            std::cout << "�� ����� �� ���� ����!" << '\n' << "���஡�� ���: ";
            std::cin.clear ();
            std::cin.ignore (std::numeric_limits<short>::max(), '\n');
        }
        else break;
    }
    return (a);
}
