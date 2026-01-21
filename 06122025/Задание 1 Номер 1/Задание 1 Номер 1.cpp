// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

struct Complex {
    double re, im;

    Complex(double r = 0, double i = 0) : re(r), im(i) {}

    void show() {
        cout << re;
        if (im >= 0) cout << " + " << im << "i";
        else cout << " - " << -im << "i";
    }
};

Complex add(Complex a, Complex b) {
    return Complex(a.re + b.re, a.im + b.im);
}

Complex sub(Complex a, Complex b) {
    return Complex(a.re - b.re, a.im - b.im);
}

Complex mul(Complex a, Complex b) {
    return Complex(
        a.re * b.re - a.im * b.im,
        a.re * b.im + a.im * b.re
    );
}

Complex div(Complex a, Complex b) {
    double d = b.re * b.re + b.im * b.im;
    if (d == 0) {
        cerr << "Ошибка: деление на ноль!" << endl;
        return Complex(0, 0);
    }
    return Complex(
        (a.re * b.re + a.im * b.im) / d,
        (a.im * b.re - a.re * b.im) / d
    );
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Complex z1(3, 4);
    Complex z2(1, -2);

    cout << "z1 = "; z1.show(); cout << endl;
    cout << "z2 = "; z2.show(); cout << endl;

    Complex sum = add(z1, z2);
    cout << "Сумма: "; sum.show(); cout << endl;

    Complex dif = sub(z1, z2);
    cout << "Разность: "; dif.show(); cout << endl;

    Complex prod = mul(z1, z2);
    cout << "Произведение: "; prod.show(); cout << endl;

    Complex quot = div(z1, z2);
    cout << "Частное: "; quot.show(); cout << endl;

    return 0;
}