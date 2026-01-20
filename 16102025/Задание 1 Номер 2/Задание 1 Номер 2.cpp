// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;
double average(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return (double)sum / size;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;

    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double avg = average(arr, n);

    cout << "Среднее арифметическое: " << avg << endl;

    delete[] arr;

    return 0;
}