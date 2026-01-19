// 120920251.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 8;

const int moves[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

bool isSafe(int x, int y, int board[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

int countMoves(int x, int y, int board[N][N]) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if (isSafe(nx, ny, board)) {
            count++;
        }
    }
    return count;
}

bool solveKnightTour(int x, int y, int moveCount, int board[N][N]) {
    board[x][y] = moveCount;

    if (moveCount == N * N - 1) {
        return true;
    }

    vector<pair<int, int>> nextMoves;

    for (int i = 0; i < 8; i++) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];

        if (isSafe(nx, ny, board)) {
            int movesFromNext = countMoves(nx, ny, board);
            nextMoves.push_back({ movesFromNext, i });
        }
    }

    sort(nextMoves.begin(), nextMoves.end());

    for (auto& move : nextMoves) {
        int i = move.second;
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];

        if (solveKnightTour(nx, ny, moveCount + 1, board)) {
            return true;
        }
    }

    board[x][y] = -1;
    return false;
}

void printBoard(int board[N][N]) {
    cout << "\nРешение для доски " << N << "x" << N << ":\n";
    cout << "   ";
    for (int j = 0; j < N; j++) {
        cout << " " << j << "  ";
    }
    cout << "\n   ";
    for (int j = 0; j < N; j++) {
        cout << "----";
    }
    cout << "-\n";

    for (int i = 0; i < N; i++) {
        cout << i << " |";
        for (int j = 0; j < N; j++) {
            if (board[i][j] + 1 < 10) cout << " ";
            cout << board[i][j] + 1 << " |";
        }
        cout << "\n   ";
        for (int j = 0; j < N; j++) {
            cout << "----";
        }
        cout << "-\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int board[N][N];
    int startX, startY;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }

    cout << "ШАХМАТНАЯ ДОСКА " << N << "x" << N << "\n";
    cout << "========================\n";

    cout << "Введите начальную позицию (0 0 или 7 7): ";
    cin >> startX >> startY;

    if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
        cout << "Неверные координаты. Установлена позиция (0,0).\n";
        startX = startY = 0;
    }

    cout << "\nПоиск решения...\n";

    if (solveKnightTour(startX, startY, 0, board)) {
        cout << "Решение найдено!\n";
        printBoard(board);
    }
    else {
        cout << "Решение не найдено для позиции (" << startX << "," << startY << ")\n";
        cout << "Попробуйте другую стартовую позицию, например (0,0) или (3,3)\n";
    }

    return 0;
}