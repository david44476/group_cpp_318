/*
* ������ୠ� ࠡ�� � 2
*
* ����: ��᫥������� ⨯�� ������, ���ᥬ � IDE (��⥣�஢����� �।� ࠧࠡ�⪨) Qt Creator?
*
* ���ࠡ��稪:���뤮� ����� �������஢��.
*
* OS:WINDOWS
*
* locale (����஢��):IBM866 / CP866 / csIBM866
*/

/* ������砥� ������⥪� ��� �����/�뢮�� */
#include<iostream>

/* ������砥� ��⥬������ ������⥪� �몮� */
#include<cmath>

/* ������砥� ������⥪� ��� ��।������ �ࠪ���⨪ ���� ⨯�� ��६�����. */
#include<limits>

#include <iomanip> // ��� std::setprecision()

#include <bitset>


//main - ������� �㭪�� � ���ன ��稭����� �ᯮ������ �ணࠬ��
int main()
{
#if 0
    // �뢮� ����� �������
    printf("\t\t ������� � 1\n");


    // ����� ���짮��⥫� �� ���� ������
    printf("������ ��� ������ � ������ ����: ");
    int age; // ������� ��६�����: ������ ���짮��⥫�
    scanf("%i", &age); // ���� ������ � ����������


    // ����� ���짮��⥫� �� ���� ���
    printf("������ ��� ��� � ������ ����: ");
    int weight; // ������� ��६�����: ��� ���짮��⥫�
    scanf("%i", &weight); // ���� ��� � ����������


    // ����� ���짮��⥫� �� ���� ���
    printf("������ ��� ��� � ᠭ⨬���� � ������ ����: ");
    int height; // ������� ��६�����: ��� ���짮��⥫�
    scanf("%i", &height); // ���� ��� � ����������


    // ����� ���짮��⥫� �� ���� �����୮� �७���������
    printf("�᫨ �� ��稭� ������ 1, �᫨ ���騭� ������ 0 � ������ ����: ");
    int gender; // ������� ��६�����: ��� ���짮��⥫�
    scanf("%i", &gender); // ���� �����୮� �७��������� � ����������


    // ������ �����쭮�� ��� �� ��㫥 �ப�
    printf("\t ������ �����쭮�� ��� �� ��㫥 �ப�\n");
    float weightCalculation; // ������� ��६�����: ��� ����� ���
    weightCalculation = (gender == 1) ? (height - 100) * 0.9 :(height - 100) * 0.85; // �᫮��� � ��㫠 ��� ����� ���
    printf("��� ������� ��� �� ��㫥 �ப� = %5.2f\n", weightCalculation); // �뢮� � �ନ��� �����쭮�� ��� �� ��㫥 �ப�


    // ������ ������ ����� ⥫�
    printf("\t ������ ������ ����� ⥫�\n");
    float bodyMassIndex; // ������� ��६�����: ��� ������ �����
    bodyMassIndex = static_cast<float>(weight)/pow((static_cast<float>(height)/100),2); // ���㫠 ��� ����� ������ �����


    // �᫮��� � �뢮� � �ନ��� ������ ����� ⥫�
    if (bodyMassIndex <= 16)
    {
        printf("��ࠦ���� ����� �����. ��� ������ ����� ⥫� = %5.2f \n", bodyMassIndex);
    }
    else if(bodyMassIndex >= 16 && bodyMassIndex <= 18.5)
        printf("�������筠� (�����) ���� ⥫�. ��� ������ ����� ⥫� = %5.2f \n", bodyMassIndex);

    // else if((bodyMassIndex >= 18.5) && (bodyMassIndex <= 25))
    //printf("��ଠ. ��� ������ ����� ⥫� = %5.2f \t\n", bodyMassIndex);

    else if (bodyMassIndex >= 25 && bodyMassIndex <= 30)
        printf("�����筠� ���� ⥫� (�।���७��). ��� ������ ����� ⥫� = %5.2f \n", bodyMassIndex);

    else if(bodyMassIndex >= 30 && bodyMassIndex <= 35)
        printf("���७�� ��ࢮ� �⥯���. ��� ������ ����� ⥫� = %5.2f \n", bodyMassIndex);

    else if(bodyMassIndex >= 35 && bodyMassIndex<= 40)
        printf("���७�� ��ன �⥯���. ��� ������ ����� ⥫� = %5.2f \n", bodyMassIndex);

    else if(bodyMassIndex >= 40)
        printf("���७�� ���쥩 �⥯��� (��ࡨ����). ��� ������ ����� ⥫� = %5.2f \t\n", bodyMassIndex);

    // �᫮��� �� ��⠭���� �ணࠬ��. ������ ����� ⥫� � ��ଥ
    if((bodyMassIndex >= 18.5) && (bodyMassIndex <= 25)){
        printf("��ଠ. ��� ������ ����� ⥫� = %5.2f \t\n", bodyMassIndex);
        return 0;
    }


    // �᫮��� � �뢮� � �ନ��� � ���⮬ ������ � �����୮� �७���������
    printf("\t ������ ������ ����� ⥫� � ���⮬ ������ � �����୮� �७���������\n");
    if(gender == 1 && (age >= 19 && age <= 24) && (bodyMassIndex < 21.4))
    {
        printf("� ���⮬ ������ � ��� ����� ����� ⥫�.\n");
    }
    else if(gender == 1 && (age >= 19 && age <= 24) && (bodyMassIndex >= 21.4 + 5))
        printf("� ��⮬ ������ � ��� ������� �஡���� � ��譨� ��ᮬ.\n");

    else if(gender == 1 && (age >= 25 && age <= 34) && (bodyMassIndex < 21.6))
        printf("� ���⮬ ������ � ��� ����� ����� ⥫�.\n");

    else if(gender == 1 && (age >= 25 && age <= 34) && (bodyMassIndex >= 21.6 + 5))
        printf("� ��⮬ ������ � ��� ������� �஡���� � ��譨� ��ᮬ.\n");

    else if(gender == 1 && (age >= 35 && age <= 44) && (bodyMassIndex < 22.9))
        printf("� ���⮬ ������ � ��� ����� ����� ⥫�.\n");

    else if(gender == 1 && (age >= 35 && age <= 44) && (bodyMassIndex >= 22.5 + 5))
        printf("� ��⮬ ������ � ��� ������� �஡���� � ��譨� ��ᮬ.\n");

    else if(gender == 1 && (age >= 45 && age <= 54) && (bodyMassIndex < 25.8))
        printf("� ���⮬ ������ � ��� ����� ����� ⥫�.\n");

    else if(gender == 1 && (age >= 45 && age <= 54) && (bodyMassIndex >= 25.8 + 5))
        printf("� ��⮬ ������ � ��� ������� �஡���� � ��譨� ��ᮬ.\n");

    else if(gender == 1 && (age > 55) && (bodyMassIndex < 26.6))
        printf("� ���⮬ ������ � ��� ����� ����� ⥫�.\n");

    else if(gender == 1 && (age > 55) && (bodyMassIndex >= 26.6 + 5))
        printf("� ��⮬ ������ � ��� ������� �஡���� � ��譨� ��ᮬ.\n");

    else if(gender == 0 && (age == 19 && age <= 24) && (bodyMassIndex < 19.5))
        printf("� ���⮬ ������ � ��� ����� ����� ⥫�.\n");

    else if(gender == 0 && (age >= 19 && age <= 24) && (bodyMassIndex >= 19.5 + 5))
        printf("� ��⮬ ������ � ��� ������� �஡���� � ��譨� ��ᮬ.\n");

    else if(gender == 0 && (age >= 25 && age <= 34) && (bodyMassIndex < 23.2))
        printf("� ���⮬ ������ � ��� ����� ����� ⥫�.\n");

    else if(gender == 0 && (age >= 25 && age <= 34) && (bodyMassIndex >= 23.2 + 5))
        printf("� ��⮬ ������ � ��� ������� �஡���� � ��譨� ��ᮬ.\n");

    else if(gender == 0 && (age >= 35 && age <= 44) && (bodyMassIndex < 23.4))
        printf("� ���⮬ ������ � ��� ����� ����� ⥫�.\n");

    else if(gender == 0 && (age >= 35 && age <= 44) && (bodyMassIndex >= 23.4 + 5))
        printf("� ��⮬ ������ � ��� ������� �஡���� � ��譨� ��ᮬ.\n");

    else if(gender == 0 && (age >= 45 && age <= 54) && (bodyMassIndex < 25.2))
        printf("� ���⮬ ������ � ��� ����� ����� ⥫�.\n");

    else if(gender == 0 && (age >= 45 && age <= 54) && (bodyMassIndex >= 25.2 + 5))
        printf("� ��⮬ ������ � ��� ������� �஡���� � ��譨� ��ᮬ.\n");

    else if(gender == 0 && (age > 55) && (bodyMassIndex < 27.3))
        printf("� ���⮬ ������ � ��� ����� ����� ⥫�.\n");

    else if(gender == 0 && (age >= 55) && (bodyMassIndex >= 27.3 + 5))
        printf("� ��⮬ ������ � ��� ������� �஡���� � ��譨� ��ᮬ.\n");
#endif

#if 0
    // �뢮� ����� �������
    std::cout << "\t\t������� � 2\n";


    // �뢮� ࠧ��஢ �᭮���� ⨯�� ������ C++
    std::cout << "\t �뢮� ࠧ��஢ �᭮���� ⨯�� ������ C++\n";

    std::cout << "����� ⨯� int ࠢ��: " << sizeof(int) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� int

    std::cout << "����� ⨯� bool ࠢ��: " << sizeof(bool) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� bool

    std::cout << "����� ⨯� float ࠢ��: " << sizeof(float) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� float

    std::cout << "����� ⨯� double ࠢ��: " << sizeof(double) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� double

    std::cout << "����� ⨯� long ࠢ��: " << sizeof(long) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� long

    std::cout << "����� ⨯� char ࠢ��: " << sizeof(char) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� char

    std::cout << '\n';


    // �뢮� ࠧ��஢ ⨯�� ������ � �ᯮ�짮������ ����䨪��஢ ����� � ࠧ���
    std::cout << "\t �뢮� ࠧ��஢ ⨯�� ������ � �ᯮ�짮������ ����䨪��஢ ����� � ࠧ���\n";

    std::cout << "����� ⨯� unsigned long long ࠢ��: " << sizeof(unsigned long long) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� unsigned long long

    std::cout << "����� ⨯� unsigned int ࠢ��: " << sizeof(unsigned int) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� unsigned int

    std::cout << "����� ⨯� signed int ࠢ��: " << sizeof(signed int) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� signed int

    std::cout << "����� ⨯� signed char ࠢ��: " << sizeof(signed char) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� signed char

    std::cout << "����� ⨯� unsigned short ࠢ��: " << sizeof(unsigned short) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� unsigned short

    std::cout << "����� ⨯� long double ࠢ��: " << sizeof(long double) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� long double

    std::cout << "����� ⨯� long long ࠢ��: " << sizeof(long long) << " ����" << std::endl; // �뢮� ����� � ����� ⨯� long long

    std::cout << '\n';


    // �뢮� �᫮���� ��������� ⨯�� ������ � �����筮�, ��⭠����筮� � � ����୮� ��⥬�� ��᫥���
    std::cout << "\t �뢮� �᫮���� ��������� ⨯�� ������ � �����筮� ��⥬� ��᫥���\n";

    std::cout << "��᫮��� �������� ⨯� long � �����筮� ��⥬� ��᫥��� �� : " << std::numeric_limits<long>::min() << " �� " << std::numeric_limits<long>::max()
              << ", ࠧ���: " << sizeof(long) << " ����" << '\n';

    std::cout << "��᫮��� �������� ⨯� unsigned short � �����筮� ��⥬� ��᫥��� �� : " << std::numeric_limits<unsigned short>::min() << " �� "<< std::numeric_limits<unsigned short>::max()
              << ", ࠧ���: " << sizeof(unsigned short) << " ����" << '\n';

    std::cout << "��᫮��� �������� ⨯� bool � �����筮� ��⥬� ��᫥��� �� : " << std::numeric_limits<bool>::min() << " �� "<< std::numeric_limits<bool>::max()
              << ", ࠧ���: " << sizeof(bool) << " ����" << '\n';

    std::cout << "��᫮��� �������� ⨯� unsigned int � �����筮� ��⥬� ��᫥��� �� : " << std::numeric_limits<unsigned int>::min() << " �� "
              << std::numeric_limits<unsigned int>::max() << ", ࠧ���: " << sizeof(unsigned int) << " ����" << '\n';

    std::cout << "��᫮��� �������� ⨯� short � �����筮� ��⥬� ��᫥��� �� : " << std::numeric_limits<short>::min() << " �� "<< std::numeric_limits<short>::max()
              << ", ࠧ���: " << sizeof(short) << " ����" << '\n';
    std::cout << '\n';


    std::cout << "\t �뢮� �᫮���� ��������� ⨯�� ������ � ��⭠����筮� ��⥬� ��᫥���\n";

    std::cout << "��᫮��� �������� ⨯� long � ��⭠����筮� ��⥬� ��᫥��� �� : " << std::hex << std::numeric_limits<long>::min() << " �� "
              << std::hex << std::numeric_limits<long>::max() << ", ࠧ���: " << sizeof(long) << " ����" << '\n';

    std::cout << "��᫮��� �������� ⨯� unsigned short � ��⭠����筮� ��⥬� ��᫥��� �� : "  << std::hex << std::numeric_limits<unsigned short>::min() << " �� "
              << std::hex << std::numeric_limits<unsigned short>::max() << ", ࠧ���: " << sizeof(unsigned short) << " ����" << '\n';

    std::cout << "��᫮��� �������� ⨯� bool � ��⭠����筮� ��⥬� ��᫥��� �� : " << std::hex << std::numeric_limits<bool>::min() << " �� "
              << std::hex << std::numeric_limits<bool>::max() << ", ࠧ���: " << sizeof(bool) << " ����" << '\n';

    std::cout << "��᫮��� �������� ⨯� unsigned int � ��⭠����筮� ��⥬� ��᫥��� �� : " << std::hex << std::numeric_limits<unsigned int>::min() << " �� "
              << std::hex << std::numeric_limits<unsigned int>::max() << ", ࠧ���: " << sizeof(unsigned int) << " ����" << '\n';

    std::cout << "\��᫮��� �������� ⨯� short � ��⭠����筮� ��⥬� ��᫥��� �� : " << std::hex << std::numeric_limits<short>::min() << " �� "
              << std::hex << std::numeric_limits<short>::max() << ", ࠧ���: " << sizeof(short) << " ����" << '\n';
    std::cout << '\n';



    std::cout << "\t �뢮� �᫮���� ��������� ⨯�� ������ � ����୮� ��⥬� ��᫥���\n";

    std::cout << "��᫮��� �������� ⨯� char � ����୮� ��⥬� ��᫥��� �� : "  << std::bitset<8>(std::numeric_limits<char>::min()) << " �� "
              << std::bitset<8>(std::numeric_limits<char>::max()) << ", ࠧ���: " << sizeof(char) << " ����" << '\n';

    std::cout << "��᫮��� �������� ⨯� unsigned short � ����୮� ��⥬� ��᫥��� �� : "  << std::bitset<16>(std::numeric_limits<unsigned short>::min()) << " �� "
              << std::bitset<16>(std::numeric_limits<unsigned short>::max()) << ", ࠧ���: " << sizeof(unsigned short) << " ����" << '\n';

    std::cout << "��᫮��� �������� ⨯� bool � ����୮� ��⥬� ��᫥��� �� : "  << std::bitset<8>(std::numeric_limits<bool>::min()) << " �� "
              << std::bitset<8>(std::numeric_limits<bool>::max()) << ", ࠧ���: " << sizeof(bool) << " ����" << '\n';

    std::cout << "��᫮��� �������� ⨯� short � ����୮� ��⥬� ��᫥��� �� : "  << std::bitset<16>(std::numeric_limits<short>::min()) << " �� "
              << std::bitset<16>(std::numeric_limits<short>::max()) << ", ࠧ���: " << sizeof(short) << " ����" << '\n';

    std::cout << "��᫮��� �������� ⨯� int � ����୮� ��⥬� ��᫥��� �� : "  << std::bitset<32>(std::numeric_limits<int>::min()) << " �� "
              << std::bitset<32>(std::numeric_limits<int>::max()) << ", ࠧ���: " << sizeof(int) << " ����" << '\n';
#endif

#if 0
    // �뢮� ����� �������
    std::cout << "\t\t������� � 3\n";

    // ����� ���짮��⥫� �� ���� �ᥫ � �������� �窮�
    std::cout << "������ ������ �ᥫ � ������饩 �窮� � ������ ����:\n";

    // ���塞 ��६����
    double a, b, c, d, e, f, g, h, i, j;

    // ���� ��६����� � ����������
    std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;

    // ���塞 ��६����� � �����뢠�� �।��� ��䬥��᪮� ���祭��
    double arithmeticMean = (a + b + c + d + e + f + g + h + i + j)/10;

    // �뢮� � �ନ���
    std::cout << "�।��� ��䬥��᪮� ���祭�� = " << arithmeticMean;
#endif

#if 0
    // �뢮� ����� �������
    std::cout << "\t\t������� � 4\n";

    // ���塞 ��६����
    double aValue = 34.50;
    double bValue = 0.004000;
    double cValue = 123.005;
    int dValue = 146000;

    // �����⢫塞 �뢮� � �ᯮ���樠�쭮� ����� � �⨫� �몠 C++ (�ᯮ���� �㪢� �, ��� ᨬ��� �ᯮ����).
    std::cout << aValue << " = " << aValue / 10 << "e1 � �ᯮ���樠�쭮� �����, �� ���稬�� ����\n" << bValue << " = " << bValue * pow(10,3) << "e-3 � �ᯮ���樠�쭮� �����, ���� ���稬�� ���\n"
              << cValue << " = " << cValue * pow(10,-2) << "e2 � �ᯮ���樠�쭮� �����, ���� ���稬�� ���\n" << dValue << " = "
              << dValue * pow(10,-5) << "e5 � �ᯮ���樠�쭮� �����, �� ���稬�� ����\n";
#endif

#if 0
    // �뢮� ����� �������
    std::cout << "\t\t������� � 5\n";

    // �뢮� ����������
    std::cout << "1)\n";

    // ��������� �ଠ�஢���� std::boolalpha:
    std::cout << std::boolalpha;

    // ���塞 �㫥��� ��६����� � ��ᢠ�� �� �㫥��� ��ࠦ����
    bool aVal = (true && true) || false;
    std::cout << "(true && true) || false = " << aVal << std::endl; // �뢮��� � �ନ��� १���� �㫥���� ��ࠦ����

    // ���塞 �㫥��� ��६����� � ��ᢠ�� �� �㫥��� ��ࠦ����
    bool bVal = (false && true) || true;
    std::cout << "(false && true) || true = " << bVal << std::endl; // �뢮��� � �ନ��� १���� �㫥���� ��ࠦ����

    // ���塞 �㫥��� ��६����� � ��ᢠ�� �� �㫥��� ��ࠦ����
    bool cVal = (false && true) || false || true;
    std::cout << "(false && true) || false || true = " << cVal << std::endl; // �뢮��� � �ନ��� १���� �㫥���� ��ࠦ����

    // ���塞 �㫥��� ��६����� � ��ᢠ�� �� �㫥��� ��ࠦ����
    bool dVal = (5 > 6 || 4 > 3) && (7 > 8);
    std::cout << "(5 > 6 || 4 > 3) && (7 > 8) = " << dVal << std::endl; // �뢮��� � �ନ��� १���� �㫥���� ��ࠦ����

    // ���塞 �㫥��� ��६����� � ��ᢠ�� �� �㫥��� ��ࠦ����
    bool eVal = !(7 > 6 || 3 > 4);
    std::cout << "!(7 > 6 || 3 > 4) = " << eVal << '\n' << std::endl; // �뢮��� � �ନ��� १���� �㫥���� ��ࠦ����


    // �뢮� ����������
    std::cout << "2)\n";

    // ���塞 �����᪨� ����⠭��
    const bool Value1{true};
    const bool Value2{false};
    const bool Value3{true};
    const bool Value4{false};
    const bool Value5{true};
    const bool Value6{false};

    // ���塞 ��६����� ��� �����᪨� ��஦����
    bool result;

    // �����᪨� ��ࠦ����
    result = ((Value1 && Value3) || (!Value2) && (Value5 || Value4));
    std::cout << "(( Value1 && Value3 ) || ( !Value2) && (Value5 || Value4)) = " << result << std::endl; // �뢮� � �ନ��� �����᪮�� ��ࠦ���� � १���⮬

    result = ((Value2 && Value4) || (Value6 && Value1) || (!Value3));
    std::cout << "((Value2 && Value4) || (Value6 && Value1) || (!Value3)) = " << result << std::endl; // �뢮� � �ନ��� �����᪮�� ��ࠦ���� � १���⮬

    result = ((!Value3 || Value2) && (Value4 || Value6) && (Value1||Value5));
    std::cout << "((!Value3 || Value2) && (Value4 || d1) && (Value1||Value5)) = " << result << std::endl; // �뢮� � �ନ��� �����᪮�� ��ࠦ���� � १���⮬

    // ���塞 ����� ����᫥��� IntVariable
    enum IntVariable{
        // ���� ��室���� ����᫨⥫�
        // ����� ����᫨⥫� ࠧ������� ����⮩, �� �窮� � ����⮩
        ONE, // ��᢮��� 0
        TWO, // ��᢮��� 1
        THREE, // ��᢮��� 2
        FOUR, // ��᢮��� 3
        FIVE, // ��᢮��� 4
        SIX, // ��᢮��� 5
    };

    // �����᪮� ��ࠦ���� � ����᫥��ﬨ
    result = ((FIVE > ONE) && (TWO < THREE) && (SIX != FOUR));
    std::cout << "((FIVE > ONE) && (TWO < THREE) && (SIX != FOUR)) = " << result << '\n' << std::endl; // �뢮� � �ନ��� �����᪮�� ��ࠦ���� � १���⮬



    // �뢮� ����������
    std::cout << "3)\n";

    std::cout << "�஢�ઠ ������ �� ��࣠��\n";

    // ���塞 �����᪨� ��६����
    bool val1{true};
    bool val2{false};

    // �᫮��� �஢�ન ������ �� ��࣠��
    if(!(val1 && val2) == (!val1) || (!val2))
    {
        std::cout << "!(val1 && val2) == (!val1) || (!val2)  �� ��� ��୮!" << '\n'; //�뢮� � �ନ��� १���� �஥ન
    }
    else std::cout << "��� �訡�窠 ��諠!\n"; //�뢮� � �ନ��� १���� �஥ન

    // �᫮��� �஢�ન ������ �� ��࣠��
    if(!(val1 || val2) == (!val1) && (!val2))
    {
        std::cout << "!(val1 || val2) == (!val1) && (!val2)  �� ��� ��୮!" << '\n'; //�뢮� � �ନ��� १���� �஥ન
    }
    else std::cout << "��� �訡�窠 ��諠!"; //�뢮� � �ନ��� १���� �஥ન
    std::cout << '\n';


    // �뢮� ����������
    std::cout << "4)\n";

    // ���塞 ��६����
    int x, y, z, v;
    bool logicValue;

    // ����� ���짮��⥫� �� ���� 楫��᫥���� �ᥫ
    std::cout << "������ 楫��᫥��� ���祭�� ��� x, y, z, v � ������ ���� \n";
    std::cin >> x >> y >> z >> v; // ���� ���祭�� � ����������

    x = 3 + 4 + 5; // ��ᢠ����� ��६����� x ���祭�� ��ࠦ����
    std::cout << "��ࢮ� ��ࠦ���� x = 3 + 4 + 5\n";
    std::cout <<"x = " << x << '\n' << "y = " << y << '\n' << "z = " << z << '\n'; // �뢮��� � �ନ��� ���祭�� ��६����� x, y, z

    x = y = z;  // ��ᢠ�� ��६����� y ���祭�� ��६����� z , ��⮬ ��ᢠ����� ��६����� x ���祭�� ��६����� y
    std::cout << "��஥ ��ࠦ���� x = y = z\n";
    std::cout <<"x = " << x << '\n' << "y = " << y << '\n' << "z = " << z << '\n'; // �뢮��� � �ନ��� ���祭�� ��६����� x, y, z

    z *= ++y + 5; // ((y + 1 ) + 5) * z
    std::cout << "���� ��ࠦ���� z *= ++y + 5\n";
    std::cout <<"x = " << x << '\n' << "y = " << y << '\n' << "z = " << z << '\n'; // �뢮��� � �ନ��� ���祭�� ��६����� x, y, z

    // ���塞 ��६���� ��� �����᪮�� ��ࠦ����
    logicValue = x || y && z || v;
    std::cout <<"logicValue = x || y && z || v = " << logicValue << '\n' << '\n'; // �뢮��� � �ନ��� ���祭�� ��६����� logicValue

    /* ����� �� ��ࠦ���� 4: ����� ���祭�� ������ ����� ��६���� x, y, z, v, �⮡� ��६����� logicValue �ਭ﫠 ���祭�� false?
     * ���祭�� ��६����� ������ ���� �㫥�묨 */


    // �뢮� ����������
    std::cout << "5)\n";

    // ������� � ���᫥���  ��६����� ��� ���ᨬ��쭮�� 稫�
    float powVal = pow(2,4);

    // ����� ���짮��⥫� �� ���� �᫠
    std::cout <<"������ �᫮ �� 0 �� " << powVal << " � ������ ����: ";

    int rangeVal; // ���塞 ��६����� ��� ����� �᫠ � ����������
    std::cin >> rangeVal; // ���� �᫠

    // ����� ���짮��⥫� �� ���� �᫠ ��  ���஥ �㦭� ᤢ�����
    std::cout << "������ �᫮ �� ���஥ ����室��� ᤢ����� �᫮ ����� � ������ ����: ";

    int shiftVal; // // ���塞 ��६����� ��� ����� �᫠ � ����������

    std::cin >> shiftVal; // // ���� �᫠

    std::cout << "������� � �����筮� ���� = " << (rangeVal << shiftVal) << '\n'; // �뢮� १����

    std::cout << "������� � ��⭠����筮� ���� = " << std::hex << (rangeVal << shiftVal) << '\n'; // �뢮� १����

    std::cout << "������� � ��ᬨ�筮� ���� = " << std::oct << (rangeVal << shiftVal) << '\n'; // �뢮� १����

    std::cout << "������� � ����୮� ���� = " << std::bitset<32>(rangeVal << shiftVal) << '\n'; // �뢮� १����


    // �뢮� ����������
    std::cout << "6)\n";

    // ������� ��६�����
    int a{5};
    int b{10};
    int k{3};

    // ���᫥��� ��ࠦ����
    int res1 = a + b * 1 - 128/5;
    int res2 = a | b >> 1;
    int res3 = a / b * k;

    std::cout << "res1 = " << res1 << '\n' << "res2 = " <<res2 << '\n' << "res3 = " <<res3 << '\n' ; // �뢮� १����
    return 0;

#endif
}
