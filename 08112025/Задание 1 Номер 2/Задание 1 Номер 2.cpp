// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int cellSize;

    cout << "Введите размер клеточки шахматной доски: ";
    cin >> cellSize;

    for (int row = 0; row < 8; row++) {
        for (int cellRow = 0; cellRow < cellSize; cellRow++) {
            for (int col = 0; col < 8; col++) {
                if ((row + col) % 2 == 0) {
                    for (int i = 0; i < cellSize; i++) {
                        cout << "*";
                    }
                }
                else {
                    for (int i = 0; i < cellSize; i++) {
                        cout << "_";
                    }
                }
            }
            cout << endl;
        }
    }

    return 0;
}