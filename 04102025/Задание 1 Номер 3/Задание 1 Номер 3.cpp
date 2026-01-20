// Задание 1 Номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int** createArray(int r, int c) {
    int** arr = new int* [r];
    for (int i = 0; i < r; i++) arr[i] = new int[c];
    return arr;
}

void fillRandom(int** arr, int r, int c) {
    srand(time(NULL));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            arr[i][j] = rand() % 10;
}

void printArray(int** arr, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void shiftLeft(int** arr, int r, int c, int k) {
    k %= c;
    if (k == 0) return;

    int* temp = new int[c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) temp[j] = arr[i][j];
        for (int j = 0; j < c; j++) arr[i][j] = temp[(j + k) % c];
    }

    delete[] temp;
}

void shiftRight(int** arr, int r, int c, int k) {
    k %= c;
    if (k == 0) return;

    int* temp = new int[c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) temp[j] = arr[i][j];
        for (int j = 0; j < c; j++) arr[i][j] = temp[(j - k + c) % c];
    }

    delete[] temp;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows = 3, cols = 4, shift, dir;

    int** arr = createArray(rows, cols);
    fillRandom(arr, rows, cols);

    cout << "Исходный массив:\n";
    printArray(arr, rows, cols);

    cout << "Сдвиг (1-влево, 2-вправо): ";
    cin >> dir;
    cout << "На сколько: ";
    cin >> shift;

    if (dir == 1) shiftLeft(arr, rows, cols, shift);
    else if (dir == 2) shiftRight(arr, rows, cols, shift);

    cout << "\nПосле сдвига:\n";
    printArray(arr, rows, cols);

    for (int i = 0; i < rows; i++) delete[] arr[i];
    delete[] arr;

    return 0;
}