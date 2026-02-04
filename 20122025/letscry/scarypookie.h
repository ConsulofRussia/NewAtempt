#pragma once

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double r);
    Complex(double r, double im);

    double getReal() const;
    double getImag() const;
    double getModulus() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    Complex operator-() const;

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    void print() const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};