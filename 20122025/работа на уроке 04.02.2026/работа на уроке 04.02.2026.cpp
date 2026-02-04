#include "scarypookie.h"
#include "Windows.h"

Complex::Complex() : real(0.0), imag(0.0) {}

Complex::Complex(double r) : real(r), imag(0.0) {}

Complex::Complex(double r, double im) : real(r), imag(im) {}


double Complex::getModulus() const
{
    return std::sqrt(real * real + imag * imag);
}


bool Complex::equals(const Complex& other) const
{
    return std::abs(getModulus() - other.getModulus()) < 1e-9;
}


bool Complex::lessThan(const Complex& other) const
{
    return getModulus() < other.getModulus() - 1e-9;
}


void Complex::add(const Complex& other)
{
    real += other.real;
    imag += other.imag;
}


void Complex::subtract(const Complex& other)
{
    real -= other.real;
    imag -= other.imag;
}


void Complex::multiply(const Complex& other)
{
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    real = r;
    imag = i;
}


void Complex::divide(const Complex& other)
{
    double denom = other.real * other.real + other.imag * other.imag;
    if (denom == 0) {
        std::cout << "division by zero\n";
        return;
    }
    double r = (real * other.real + imag * other.imag) / denom;
    double i = (imag * other.real - real * other.imag) / denom;
    real = r;
    imag = i;
}


Complex Complex::operator+(const Complex& other) const
{
    Complex res = *this;
    res.add(other);
    return res;
}


Complex Complex::operator-(const Complex& other) const
{
    Complex res = *this;
    res.subtract(other);
    return res;
}


Complex Complex::operator*(const Complex& other) const
{
    Complex res = *this;
    res.multiply(other);
    return res;
}


Complex Complex::operator/(const Complex& other) const
{
    Complex res = *this;
    res.divide(other);
    return res;
}


Complex& Complex::operator+=(const Complex& other)
{
    add(other);
    return *this;
}


Complex& Complex::operator-=(const Complex& other)
{
    subtract(other);
    return *this;
}


Complex& Complex::operator*=(const Complex& other)
{
    multiply(other);
    return *this;
}


Complex& Complex::operator/=(const Complex& other)
{
    divide(other);
    return *this;
}


Complex Complex::operator-() const
{
    return Complex(-real, -imag);
}


void Complex::print() const
{
    std::cout << real;
    if (imag >= 0) {
        std::cout << " + " << imag << "i";
    }
    else {
        std::cout << " - " << -imag << "i";
    }
}