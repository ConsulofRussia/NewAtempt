// Задание 1 номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Windows.h>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void showBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "\n";
}

bool checkWin() {
    
    for (int i = 0; i < 3; i++)
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;

    for (int i = 0; i < 3; i++)
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

bool makeMove(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2)
        return false;

    if (board[row][col] != ' ')
        return false;

    board[row][col] = currentPlayer;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int row, col;
    bool gameOver = false;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    initBoard();

    cout << "КРЕСТИКИ-НОЛИКИ\n";
    cout << "Игрок X против игрока O\n";
    cout << "Вводите координаты (строка столбец) от 0 до 2\n";
    cout << "Например: 0 0 - левый верхний угол\n";

    while (!gameOver) {
        showBoard();
        cout << "Ход игрока " << currentPlayer << ": ";
        cin >> row >> col;

        if (!makeMove(row, col)) {
            cout << "Недопустимый ход! Попробуйте снова.\n";
            continue;
        }

        if (checkWin()) {
            showBoard();
            cout << "Игрок " << currentPlayer << " победил!\n";
            gameOver = true;
        }
        else if (checkDraw()) {
            showBoard();
            cout << "Ничья!\n";
            gameOver = true;
        }
        else {
            switchPlayer();
        }
    }

    cout << "Игра окончена. Спасибо за игру!\n";

    return 0;
}