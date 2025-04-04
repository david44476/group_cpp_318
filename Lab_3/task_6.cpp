#include<iostream>

// функция преобразования типов даных
void Initialization (int x, float y, double z, unsigned short k)
{
    // преобразование типов с помощью static_cast
    std::cout << "преобразование типов с помощью static_cast\n";
    
    int i = x + static_cast<int> (y)  * static_cast<int> (z + k);
    std::cout<< "i = " << i << '\t' <<  '\n';
    
    k = static_cast<unsigned short>(x) - static_cast<unsigned short> (y) / static_cast<unsigned short>(z);
    std::cout << "k = " << k <<  '\n';
    
    z = static_cast<double>(x) * static_cast<double> (y) + z / static_cast<double>(x);
    std::cout << "z = " << z << '\n';
    
    unsigned int ui = static_cast<unsigned int>(x) / static_cast<unsigned int>(y) + static_cast<unsigned int>(k);
    std::cout << "ui = " << ui << '\n';
    
    short s = static_cast<short>(x) % static_cast<short>(x) /static_cast<short> (y);
    std::cout << "s = " << (s) << '\n';


    // преобразование типов с помощью С-style cast
    std::cout << "преобразование типов с помощью С-style cast\n";
    
    i = x + (int) y * (int) z + (int) k;
    std::cout<< "i = " << i << '\t' <<  '\n';
    
    k = (unsigned short) (x) - (unsigned short) (y) / (unsigned short) (z);
    std::cout << "k = " << k <<  '\n';
    
    z = (double) (x) * (double) (y) + (double) (z) / (double) (x);
    std::cout << "z = " << z << '\n';
    
    ui = (unsigned int) (x) / (unsigned int) (y) + (unsigned int) (k);
    std::cout << "ui = " << ui << '\n';
    
    s = (short) (x) % (short) (x) / (short) (y);
    std::cout << "s = " << s << '\n';

    
    // преобразование типов с помощью не явной инициализацией
    std::cout << "преобразование типов с помощью не явной инициализацией\n";

    i = (x + y) * z + k;
    std::cout<< "i = " << i << '\t' <<  '\n';
    
    k = x - y / z;
    std::cout << "k = " << k <<  '\n';
    
    z = x * y + z / x;
    std::cout << "z = " << z << '\n';
    
    ui = x / y + k;
    std::cout << "ui = " << ui << '\n';
    
    s = x % (int) (x / y);
    std::cout << "s = " << s << '\n';

}
