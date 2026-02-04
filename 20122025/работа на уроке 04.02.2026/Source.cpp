#include "scarypookie.h"

Complex::Complex() : real(0.0), imag(0.0) {}

Complex::Complex(double r) : real(r), imag(0.0) {}

Complex::Complex(double r, double im) : real(r), imag(im) {}

double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

double Complex::getModulus() const {
    return std::sqrt(real * real + imag * imag);
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(
        real * other.real - imag * other.imag,
        real * other.imag + imag * other.real
    );
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    return Complex(
        (real * other.real + imag * other.imag) / denom,
        (imag * other.real - real * other.imag) / denom
    );
}

Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    real -= other.real;
    imag -= other.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    real = r;
    imag = i;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    *this = *this / other;
    return *this;
}

Complex Complex::operator-() const {
    return Complex(-real, -imag);
}

bool Complex::operator==(const Complex& other) const {
    const double EPS = 1e-9;
    return std::abs(real - other.real) < EPS &&
        std::abs(imag - other.imag) < EPS;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

void Complex::print() const {
    std::cout << real;
    if (imag >= 0) {
        std::cout << " + " << imag << "i";
    }
    else {
        std::cout << " - " << -imag << "i";
    }
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) {
        os << " + " << c.imag << "i";
    }
    else {
        os << " - " << -c.imag << "i";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}