// Задание 1 Номер 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введите количество элементов N: ";
    cin >> N;

    double* arr = new double[N];

    cout << "Введите " << N << " вещественных чисел:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    double sumNegative = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            sumNegative += arr[i];
        }
    }

    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    double productBetween = 1;
    int start = (minIndex < maxIndex) ? minIndex : maxIndex;
    int end = (minIndex > maxIndex) ? minIndex : maxIndex;

    bool hasElements = false;
    for (int i = start + 1; i < end; i++) {
        productBetween *= arr[i];
        hasElements = true;
    }

    if (!hasElements || end - start <= 1) {
        productBetween = 0;
    }

    double productEvenIndex = 1;
    for (int i = 1; i < N; i += 2) {
        productEvenIndex *= arr[i];
    }

    double sumBetweenNegatives = 0;
    int firstNegative = -1, lastNegative = -1;

    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            firstNegative = i;
            break;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] < 0) {
            lastNegative = i;
            break;
        }
    }

    if (firstNegative != -1 && lastNegative != -1 && lastNegative - firstNegative > 1) {
        for (int i = firstNegative + 1; i < lastNegative; i++) {
            sumBetweenNegatives += arr[i];
        }
    }

    cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;
    cout << "1. Сумма отрицательных элементов: " << sumNegative << endl;
    cout << "2. Произведение элементов между min и max: " << productBetween << endl;
    cout << "3. Произведение элементов с четными номерами: " << productEvenIndex << endl;
    cout << "4. Сумма между первым и последним отрицательными: " << sumBetweenNegatives << endl;

    delete[] arr;

    return 0;
}