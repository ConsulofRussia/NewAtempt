// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Windows.h>

using namespace std;

int** transposeMatrix(int** matrix, int rows, int cols) {

    int** transposed = new int* [cols];
    for (int i = 0; i < cols; i++) {
        transposed[i] = new int[rows];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
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

    cout << "Исходная матрица (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int** transposed = transposeMatrix(matrix, rows, cols);

    cout << "\nТранспонированная матрица (" << cols << "x" << rows << "):\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transposed[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < cols; i++) {
        delete[] transposed[i];
    }
    delete[] transposed;

    return 0;
}