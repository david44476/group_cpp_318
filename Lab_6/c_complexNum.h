#ifndef C_COMPLEXNUM_H
#define C_COMPLEXNUM_H

#include <string>
#include <vector>
#include <iostream>

class Complex {
private:
    double re, im;

    static double normalizeAngle(double angle);

public:
    Complex();
    Complex(double real, double imag = 0.0);

    double real() const;
    double imag() const;
    void setReal(double value);
    void setImag(double value);

    double modulus() const;
    double argument() const;
    Complex conjugate() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    Complex operator-() const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    Complex power(int n) const;
    Complex powerDouble(double n) const;
    std::vector<Complex> root(int n) const;

    // Широкие версии форм записи
    std::wstring toAlgebraic() const;
    std::wstring toTrigonometric() const;
    std::wstring toExponential() const;

    friend std::wostream& operator<<(std::wostream& os, const Complex& c);
    friend std::wistream& operator>>(std::wistream& is, Complex& c);
};

#endif // C_COMPLEXNUM_H
