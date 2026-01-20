// Задание Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int x, y;

    cout << "Введите число x: ";
    cin >> x;

    cout << "Введите степень y: ";
    cin >> y;

    double result = pow(x, y);

    cout << x << " в степени " << y << " = " << result << endl;

    return 0;
}