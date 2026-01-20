// Задание 1 Номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;
void countElements(int arr[], int size, int& positive, int& negative, int& zero) {
    positive = negative = zero = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positive++;
        }
        else if (arr[i] < 0) {
            negative++;
        }
        else {
            zero++;
        }
    }
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

    int positive, negative, zero;
    countElements(arr, n, positive, negative, zero);

    cout << "Положительных: " << positive << endl;
    cout << "Отрицательных: " << negative << endl;
    cout << "Нулевых: " << zero << endl;

    delete[] arr;

    return 0;
}