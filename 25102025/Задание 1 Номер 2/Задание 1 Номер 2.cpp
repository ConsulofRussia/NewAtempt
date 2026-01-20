// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    const int SIZE = 5;
    int arr1[SIZE];
    int arr2[SIZE];
    int result[SIZE];

    cout << "Первый массив:\n";
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = rand() % 100;
        cout << arr1[i] << " ";
    }

    cout << "\n\nВторой массив:\n";
    for (int i = 0; i < SIZE; i++) {
        arr2[i] = rand() % 100;
        cout << arr2[i] << " ";
    }

    cout << "\n\nРезультат (сумма):\n";
    for (int i = 0; i < SIZE; i++) {
        result[i] = arr1[i] + arr2[i];
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}