// Задание 1 Номер 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a;
    long long product = 1;

    cout << "Введите число a (от 1 до 20): ";
    cin >> a;

    if (a < 1 || a > 20) {
        cout << "Ошибка! Число должно быть от 1 до 20." << endl;
        return 1;
    }

    for (int i = a; i <= 20; i++) {
        product *= i;
    }

    cout << "Произведение чисел от " << a << " до 20: " << product << endl;

    return 0;
}