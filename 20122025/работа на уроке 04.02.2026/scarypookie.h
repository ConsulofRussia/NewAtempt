#pragma once

#include <iostream>
#include <cmath>
#include "Windows.h"
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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Complex a(2, 1);
    Complex b(4, -5);

    std::cout << "(";
    a.print();
    std::cout << ") + (";
    b.print();
    std::cout << ") = ";

    Complex res = a + b;
    res.print();

    std::cout << "\n";

    return 0;
}