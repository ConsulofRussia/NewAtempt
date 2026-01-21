// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int** deleteColumn(int** arr, int rows, int& cols, int colToDelete) {

    if (colToDelete < 0 || colToDelete >= cols) {
        return arr;
    }

    int** newArr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        newArr[i] = new int[cols - 1];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0, k = 0; j < cols; j++) {
            if (j != colToDelete) {
                newArr[i][k] = arr[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    cols--;
    return newArr;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows = 3, cols = 4;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * 10 + j;
        }
    }

    cout << "Исходная матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int colToDelete = 2;
    matrix = deleteColumn(matrix, rows, cols, colToDelete);

    cout << "\nПосле удаления столбца " << colToDelete << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}