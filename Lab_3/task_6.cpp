#include<iostream>

// функция преобразования типов даных
void Initialization (int x, float y, double z, unsigned short k)
{
    // преобразование типов с помощью static_cast
    std::cout << "преобразование типов с помощью static_cast\n";
    
    int i = x + static_cast<int> (y)  * static_cast<int> (z + k);
    std::cout<< "i = " << i << '\t' <<  '\n';
    
    k = x - static_cast<int> (y / z);
    std::cout << "k = " << k <<  '\n';
    
    z = x * static_cast<int> (y + z / x);
    std::cout << "z = " << z << '\n';
    
    unsigned int ui = x / static_cast<int> (y + k);
    std::cout << "ui = " << ui << '\n';
    
    short s = x % (x /static_cast<int> (y));
    std::cout << "s = " << (s) << '\n';
    
    
    // преобразование типов с помощью С-style cast
    std::cout << "преобразование типов с помощью С-style cast\n";
    
    i = x + (int) (y)  * (int) (z + k);
    std::cout<< "i = " << i << '\t' <<  '\n';
    
    k = x - (int) (y / z);
    std::cout << "k = " << k <<  '\n';
    
    z = x * (int) (y + z / x);
    std::cout << "z = " << z << '\n';
    
    ui = x / (int) (y + k);
    std::cout << "ui = " << ui << '\n';
    
    s = x % (int) (x / y);
    std::cout << "s = " << s << '\n';
    
    // преобразование типов с помощью не явной инициализацией
    std::cout << "преобразование типов с помощью не явной инициализацией\n";

    int i1 = (x + y) * z + k;
    std::cout<< "i1 = " << i1 << '\t' <<  '\n';
    
    int  k1 = x - y / z;
    std::cout << "k1 = " << k1 <<  '\n';
    
    int z1 = x * y + z / x;
    std::cout << "z1 = " << z1 << '\n';
    
    int ui1 = x / y + k;
    std::cout << "ui1 = " << ui1 << '\n';
    
    int s1 = x % (int) (x / y);
    std::cout << "s1 = " << s1 << '\n';

}
