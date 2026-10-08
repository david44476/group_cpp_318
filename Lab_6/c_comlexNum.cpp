#include "c_complexNum.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <stdexcept>

// --- Приватный метод ---
double Complex::normalizeAngle(double angle) {
    const double PI = std::acos(-1.0);
    const double TWO_PI = 2.0 * PI;
    angle = std::fmod(angle, TWO_PI);
    if (angle > PI)  angle -= TWO_PI;
    if (angle <= -PI) angle += TWO_PI;
    return angle;
}

// --- Конструкторы ---
Complex::Complex() : re(0.0), im(0.0) {}
Complex::Complex(double real, double imag) : re(real), im(imag) {}

// --- Геттеры / сеттеры ---
double Complex::real() const { return re; }
double Complex::imag() const { return im; }
void Complex::setReal(double value) { re = value; }
void Complex::setImag(double value) { im = value; }

// --- Модуль и аргумент ---
double Complex::modulus() const {
    return std::sqrt(re * re + im * im);
}

double Complex::argument() const {
    return std::atan2(im, re);
}

// --- Сопряжение ---
Complex Complex::conjugate() const {
    return Complex(re, -im);
}

// --- Арифметика ---
Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(re * other.re - im * other.im,
                   re * other.im + im * other.re);
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.re * other.re + other.im * other.im;
    if (denom == 0.0)
        throw std::runtime_error("Деление на ноль (комплексный ноль в знаменателе)");
    return Complex((re * other.re + im * other.im) / denom,
                   (im * other.re - re * other.im) / denom);
}

Complex Complex::operator-() const {
    return Complex(-re, -im);
}

// --- Составные присваивания ---
Complex& Complex::operator+=(const Complex& other) { re += other.re; im += other.im; return *this; }
Complex& Complex::operator-=(const Complex& other) { re -= other.re; im -= other.im; return *this; }
Complex& Complex::operator*=(const Complex& other) { *this = *this * other; return *this; }
Complex& Complex::operator/=(const Complex& other) { *this = *this / other; return *this; }

// --- Сравнение ---
bool Complex::operator==(const Complex& other) const {
    const double EPS = 1e-10;
    return std::abs(re - other.re) < EPS && std::abs(im - other.im) < EPS;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// --- Возведение в целую степень ---
Complex Complex::power(int n) const {
    if (n == 0) return Complex(1.0, 0.0);
    Complex result(1.0, 0.0);
    Complex base = (n < 0) ? Complex(1.0, 0.0) / *this : *this;
    unsigned exp = static_cast<unsigned>(std::abs(n));
    while (exp > 0) {
        if (exp & 1) result = result * base;
        base = base * base;
        exp >>= 1;
    }
    return result;
}

// --- Возведение в действительную степень ---
Complex Complex::powerDouble(double n) const {
    double r = modulus();
    double phi = argument();
    if (r == 0.0) {
        if (n > 0.0) return Complex(0.0, 0.0);
        throw std::runtime_error("Ноль нельзя возвести в неположительную степень");
    }
    double newR = std::pow(r, n);
    double newPhi = phi * n;
    return Complex(newR * std::cos(newPhi), newR * std::sin(newPhi));
}

// --- Извлечение корня n-й степени ---
std::vector<Complex> Complex::root(int n) const {
    if (n <= 0)
        throw std::runtime_error("Степень корня должна быть положительным целым числом");
    const double PI = std::acos(-1.0);
    std::vector<Complex> roots;
    double r = modulus();
    double phi = argument();
    if (r == 0.0) {
        roots.push_back(Complex(0.0, 0.0));
        return roots;
    }
    double rootR = std::pow(r, 1.0 / n);
    for (int k = 0; k < n; ++k) {
        double angle = (phi + 2.0 * PI * k) / n;
        roots.push_back(Complex(rootR * std::cos(angle),
                                rootR * std::sin(angle)));
    }
    return roots;
}

// --- Широкие формы записи ---
std::wstring Complex::toAlgebraic() const {
    std::wostringstream oss;
    oss << std::fixed << std::setprecision(4);
    oss << re;
    if (im >= 0) oss << L" + " << im << L"i";
    else         oss << L" - " << std::abs(im) << L"i";
    return oss.str();
}

std::wstring Complex::toTrigonometric() const {
    double r = modulus();
    double phi = argument();
    std::wostringstream oss;
    oss << std::fixed << std::setprecision(4);
    oss << r << L"*(cos(" << phi << L") + i*sin(" << phi << L"))";
    return oss.str();
}

std::wstring Complex::toExponential() const {
    double r = modulus();
    double phi = argument();
    std::wostringstream oss;
    oss << std::fixed << std::setprecision(4);
    oss << r << L"*e^(i*" << phi << L")";
    return oss.str();
}

// --- Потоковый ввод-вывод (широкий) ---
std::wostream& operator<<(std::wostream& os, const Complex& c) {
    os << c.toAlgebraic();
    return os;
}

std::wistream& operator>>(std::wistream& is, Complex& c) {
    is >> c.re >> c.im;
    return is;
}
