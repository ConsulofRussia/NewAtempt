// Задание 1 Номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int sum = 0;

    for (int i = 1; i <= 1000; i++) {
        sum += i;
    }

    double average = sum / 1000.0;

    cout << "Среднее арифметическое чисел от 1 до 1000: " << average << endl;

    return 0;
}