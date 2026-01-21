// Задание 1 Номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

void shiftRowsDown(int** arr, int rows, int cols, int shifts) {
    shifts %= rows;
    if (shifts == 0) return;

    int* temp = new int[cols];

    for (int s = 0; s < shifts; s++) {

        for (int j = 0; j < cols; j++) {
            temp[j] = arr[rows - 1][j];
        }

        for (int i = rows - 1; i > 0; i--) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = arr[i - 1][j];
            }
        }

        for (int j = 0; j < cols; j++) {
            arr[0][j] = temp[j];
        }
    }

    delete[] temp;
}

void shiftColumnsRight(int** arr, int rows, int cols, int shifts) {
    shifts %= cols;
    if (shifts == 0) return;

    int* temp = new int[rows];

    for (int s = 0; s < shifts; s++) {
        for (int i = 0; i < rows; i++) {
            temp[i] = arr[i][cols - 1];
        }
        for (int j = cols - 1; j > 0; j--) {
            for (int i = 0; i < rows; i++) {
                arr[i][j] = arr[i][j - 1];
            }
        }

        for (int i = 0; i < rows; i++) {
            arr[i][0] = temp[i];
        }
    }

    delete[] temp;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows, cols;

    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * 10 + j;
        }
    }

    cout << "\nИсходная матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int choice, shifts;
    cout << "\n1. Сдвиг строк вниз\n2. Сдвиг столбцов вправо\nВыберите операцию: ";
    cin >> choice;
    cout << "Сколько раз сдвинуть: ";
    cin >> shifts;

    if (choice == 1) {
        shiftRowsDown(matrix, rows, cols, shifts);
    }
    else if (choice == 2) {
        shiftColumnsRight(matrix, rows, cols, shifts);
    }

    cout << "\nМатрица после сдвига:\n";
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