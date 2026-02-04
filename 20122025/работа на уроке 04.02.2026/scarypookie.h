#pragma once

#include <iostream>
#include <cmath>

class Complex
{
public:
    double real;
    double imag;

    Complex();
    Complex(double r);
    Complex(double r, double im);

    double getModulus() const;
    bool equals(const Complex& other) const;
    bool lessThan(const Complex& other) const;

    void add(const Complex& other);
    void subtract(const Complex& other);
    void multiply(const Complex& other);
    void divide(const Complex& other);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    Complex operator-() const;

    void print() const;
};

int main()
{
    Complex a(3, 4);
    Complex b(1, 2);

    std::cout << "a: ";
    a.print();
    std::cout << "\n";

    Complex sum = a + b;
    std::cout << "sum: ";
    sum.print();
    std::cout << "\n";

    return 0;
}