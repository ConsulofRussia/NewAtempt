// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Windows.h>

using namespace std;

int sumInRange(int a, int b) {
    int sum = 0;

    int start = a;
    int end = b;

    if (a > b) {
        start = b;
        end = a;
    }

    for (int i = start; i <= end; i++) {
        sum += i;
    }

    return sum;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int num1, num2;

    cout << "=== Вычисление суммы чисел в диапазоне ===\n\n";

    cout << "Введите первое число: ";
    cin >> num1;

    cout << "Введите второе число: ";
    cin >> num2;

    int result = sumInRange(num1, num2);

    cout << "\nСумма всех чисел от "
        << min(num1, num2) << " до "
        << max(num1, num2) << " = " << result << endl;
    return 0;
}