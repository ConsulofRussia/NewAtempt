// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int** createArray(int rows, int cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    return arr;
}
void fillArithmetic(int** arr, int rows, int cols, int start) {
    int value = start;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value;
            value++;
        }
    }
}
void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
void deleteArray(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows, cols, start;

    cout << "Введите размеры массива и начальное значение:\n";
    cout << "Строки: "; cin >> rows;
    cout << "Столбцы: "; cin >> cols;
    cout << "Начальное значение: "; cin >> start;

    int** array = createArray(rows, cols);

    fillArithmetic(array, rows, cols, start);

    cout << "\nРезультат:\n";
    printArray(array, rows, cols);
    
    deleteArray(array, rows);

    return 0;
}