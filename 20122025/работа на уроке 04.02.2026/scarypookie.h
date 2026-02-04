#pragma once
#include <iostream>
#include <cmath>

class Complex
{
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double r);
    Complex(double r, double im);

    double getModulus() const;
    bool equals(const Complex& other) const;
    bool lessThan(const Complex& other) const;
    void print() const;

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
};