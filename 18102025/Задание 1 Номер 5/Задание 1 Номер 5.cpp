// Задание 1 Номер 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int k;

    cout << "Введите номер варианта k: ";
    cin >> k;

    cout << "\nТаблица умножения на " << k << ":\n";

    for (int i = 1; i <= 10; i++) {
        cout << k << " x " << i << " = " << k * i << endl;
    }

    return 0;
}