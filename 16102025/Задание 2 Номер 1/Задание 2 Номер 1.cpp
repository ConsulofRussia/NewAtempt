// Задание 2 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

void initMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = rand() % 100;
}

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void findMinMaxDiagonal(int** matrix, int size, int& min, int& max) {
    min = matrix[0][0];
    max = matrix[0][0];
    for (int i = 1; i < size; i++) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
}

void sortRows(int** matrix, int size) {
    for (int i = 0; i < size; i++)
        sort(matrix[i], matrix[i] + size);
}

void initMatrix(double** matrix, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = (rand() % 1000) / 10.0;
}

void printMatrix(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void findMinMaxDiagonal(double** matrix, int size, double& min, double& max) {
    min = matrix[0][0];
    max = matrix[0][0];
    for (int i = 1; i < size; i++) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
}

void sortRows(double** matrix, int size) {
    for (int i = 0; i < size; i++)
        sort(matrix[i], matrix[i] + size);
}

void initMatrix(char** matrix, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = 'A' + rand() % 26;
}

void printMatrix(char** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void findMinMaxDiagonal(char** matrix, int size, char& min, char& max) {
    min = matrix[0][0];
    max = matrix[0][0];
    for (int i = 1; i < size; i++) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
}

void sortRows(char** matrix, int size) {
    for (int i = 0; i < size; i++)
        sort(matrix[i], matrix[i] + size);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size;
    cout << "Введите размер квадратной матрицы: ";
    cin >> size;

    int** intMatrix = new int* [size];
    for (int i = 0; i < size; i++) intMatrix[i] = new int[size];

    cout << "\nint матрица:\n";
    initMatrix(intMatrix, size);
    printMatrix(intMatrix, size);

    int intMin, intMax;
    findMinMaxDiagonal(intMatrix, size, intMin, intMax);
    cout << "Min на диагонали: " << intMin << endl;
    cout << "Max на диагонали: " << intMax << endl;

    sortRows(intMatrix, size);
    cout << "После сортировки строк:\n";
    printMatrix(intMatrix, size);

    double** doubleMatrix = new double* [size];
    for (int i = 0; i < size; i++) doubleMatrix[i] = new double[size];

    cout << "\ndouble матрица:\n";
    initMatrix(doubleMatrix, size);
    printMatrix(doubleMatrix, size);

    double doubleMin, doubleMax;
    findMinMaxDiagonal(doubleMatrix, size, doubleMin, doubleMax);
    cout << "Min на диагонали: " << doubleMin << endl;
    cout << "Max на диагонали: " << doubleMax << endl;

    sortRows(doubleMatrix, size);
    cout << "После сортировки строк:\n";
    printMatrix(doubleMatrix, size);

    char** charMatrix = new char* [size];
    for (int i = 0; i < size; i++) charMatrix[i] = new char[size];

    cout << "\nchar матрица:\n";
    initMatrix(charMatrix, size);
    printMatrix(charMatrix, size);

    char charMin, charMax;
    findMinMaxDiagonal(charMatrix, size, charMin, charMax);
    cout << "Min на диагонали: " << charMin << endl;
    cout << "Max на диагонали: " << charMax << endl;

    sortRows(charMatrix, size);
    cout << "После сортировки строк:\n";
    printMatrix(charMatrix, size);

    for (int i = 0; i < size; i++) delete[] intMatrix[i];
    delete[] intMatrix;

    for (int i = 0; i < size; i++) delete[] doubleMatrix[i];
    delete[] doubleMatrix;

    for (int i = 0; i < size; i++) delete[] charMatrix[i];
    delete[] charMatrix;

    return 0;
}