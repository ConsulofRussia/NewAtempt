// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

double power(double base, int exponent) {
    double result = 1.0;

    if (exponent > 0) {
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
    }
    else if (exponent < 0) {
        for (int i = 0; i < -exponent; i++) {
            result *= base;
        }
        result = 1.0 / result;
    }

    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double base;
    int exponent;

    cout << "Введите основание степени: ";
    cin >> base;

    cout << "Введите показатель степени (целое число): ";
    cin >> exponent;

    double result = power(base, exponent);

    cout << base << " в степени " << exponent << " = " << result << endl;

    return 0;
}