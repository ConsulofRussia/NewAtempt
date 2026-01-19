// 120920252.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;


const int BOARD_SIZE = 4;
int board[BOARD_SIZE][BOARD_SIZE];
int emptyRow, emptyCol;

void initBoard() {
    int num = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = (num == 16) ? 0 : num;
            if (board[i][j] == 0) {
                emptyRow = i;
                emptyCol = j;
            }
            num++;
        }
    }
}

void shuffleBoard() {
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < 1000; i++) {
        int direction = rand() % 4;
        int newRow = emptyRow, newCol = emptyCol;

        switch (direction) {
        case 0: newRow--; break;
        case 1: newRow++; break;
        case 2: newCol--; break;
        case 3: newCol++; break;
        }

        if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE) {
            swap(board[emptyRow][emptyCol], board[newRow][newCol]);
            emptyRow = newRow;
            emptyCol = newCol;
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                cout << "    ";
            }
            else {
                if (board[i][j] < 10) cout << " ";
                cout << board[i][j] << "  ";
            }
        }
        cout << "\n\n";
    }
    cout << "Управление: w(вверх), s(вниз), a(влево), d(вправо), q(выход)\n";
}

bool checkWin() {
    int num = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == BOARD_SIZE - 1 && j == BOARD_SIZE - 1) {
                if (board[i][j] != 0) return false;
            }
            else {
                if (board[i][j] != num) return false;
                num++;
            }
        }
    }
    return true;
}

bool makeMove(char move) {
    int newRow = emptyRow, newCol = emptyCol;

    switch (move) {
    case 'w': case 'W': newRow++; break;
    case 's': case 'S': newRow--; break;
    case 'a': case 'A': newCol++; break;
    case 'd': case 'D': newCol--; break;
    default: return false;
    }

    if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE) {
        swap(board[emptyRow][emptyCol], board[newRow][newCol]);
        emptyRow = newRow;
        emptyCol = newCol;
        return true;
    }
    return false;
}

int main() {
    char move;

    initBoard();
    shuffleBoard();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "=== ИГРА 'ПЯТНАШКИ' (4x4) ===\n";
    cout << "Соберите числа по порядку от 1 до 15\n";

    while (true) {
        displayBoard();

        if (checkWin()) {
            cout << "\nПОЗДРАВЛЯЮ! ВЫ ВЫИГРАЛИ!\n";
            break;
        }

        cout << "Ваш ход: ";
        cin >> move;

        if (move == 'q' || move == 'Q') {
            cout << "Выход из игры.\n";
            break;
        }

        if (!makeMove(move)) {
            cout << "Недопустимый ход! Используйте w,a,s,d или q для выхода.\n";
        }
    }

    return 0;
}