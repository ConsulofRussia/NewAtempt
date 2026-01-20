// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

    int arr1[10];
    int arr2[5];
    int arr3[5];

    cout << "Основной массив:\n";
    for (int i = 0; i < 10; i++) {
        arr1[i] = rand() % 100;
        cout << arr1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++) {
        arr2[i] = arr1[i];
    }

    for (int i = 0; i < 5; i++) {
        arr3[i] = arr1[i + 5];
    }
    cout << "\nПервый массив (первые 5 элементов):\n";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }

    cout << "\n\nВторой массив (следующие 5 элементов):\n";
    for (int i = 0; i < 5; i++) {
        cout << arr3[i] << " ";
    }

    cout << endl;

    return 0;
}