// help.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <string>
#include <windows.h>
#include <cmath>

using namespace std;

class Game {
private:
    vector<string> level;
    vector<vector<bool>> visited;
    vector<vector<bool>> wallsRevealed;
    int playerX, playerY;
    int width, height;
    HANDLE hConsole;
    char viewDirection;
    bool torchMode;

public:
    Game() : playerX(0), playerY(0), width(0), height(0), viewDirection('s'), torchMode(false) {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    void setColor(int color) {
        SetConsoleTextAttribute(hConsole, color);
    }

    void resetColor() {
        SetConsoleTextAttribute(hConsole, 7);
    }

    bool loadLevel(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: cannot open file " << filename << endl;
            return false;
        }

        string line;
        while (getline(file, line)) {
            level.push_back(line);
        }

        file.close();

        if (level.empty()) {
            cerr << "Error: file is empty" << endl;
            return false;
        }

        height = (int)level.size();
        width = (int)level[0].size();

        visited.resize(height, vector<bool>(width, false));
        wallsRevealed.resize(height, vector<bool>(width, false));

        bool found = false;
        for (int y = 0; y < height && !found; y++) {
            for (int x = 0; x < width && !found; x++) {
                if (level[y][x] == '.') {
                    playerX = x;
                    playerY = y;
                    level[y][x] = '@';
                    visited[y][x] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            cerr << "Error: no free cell for player" << endl;
            return false;
        }

        return true;
    }

    bool isVisibleRadius(int x, int y) {
        int distance = abs(x - playerX) + abs(y - playerY);
        return distance <= 1;
    }

    bool isVisibleTorch(int x, int y) {
        int relX = x - playerX;
        int relY = y - playerY;

        char dir = viewDirection;

        if (dir == 72) dir = 'w';
        else if (dir == 80) dir = 's';
        else if (dir == 75) dir = 'a';
        else if (dir == 77) dir = 'd';

        switch (dir) {
        case 'w':
            if (relY == -1 && abs(relX) <= 0) return true;
            if (relY == -2 && abs(relX) <= 0) return true;
            if (relY == -1 && abs(relX) == 1) return true;
            break;

        case 's':
            if (relY == 1 && abs(relX) <= 0) return true;
            if (relY == 2 && abs(relX) <= 0) return true;
            if (relY == 1 && abs(relX) == 1) return true;
            break;

        case 'a':
            if (relX == -1 && abs(relY) <= 0) return true;
            if (relX == -2 && abs(relY) <= 0) return true;
            if (relX == -1 && abs(relY) == 1) return true;
            break;

        case 'd':
            if (relX == 1 && abs(relY) <= 0) return true;
            if (relX == 2 && abs(relY) <= 0) return true;
            if (relX == 1 && abs(relY) == 1) return true;
            break;
        }

        return false;
    }

    bool isVisible(int x, int y) {
        if (torchMode) {
            return isVisibleTorch(x, y);
        }
        else {
            return isVisibleRadius(x, y);
        }
    }

    void markVisibleCells() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (isVisible(x, y)) {
                    if (level[y][x] == '#') {
                        wallsRevealed[y][x] = true;
                    }
                    else if (level[y][x] == '.' || level[y][x] == '@') {
                        visited[y][x] = true;
                    }
                }
            }
        }
    }

    void displayChar(int x, int y) {
        char ch = level[y][x];

        if (isVisible(x, y)) {
            if (ch == '@') {
                setColor(15);
            }
            else if (ch == '#') {
                setColor(15);
            }
            else if (ch == '.') {
                setColor(15);
            }
        }
        else {
            if (ch == '#') {
                if (wallsRevealed[y][x]) {
                    setColor(8);
                }
                else {
                    setColor(0);
                }
            }
            else if (ch == '.') {
                if (visited[y][x]) {
                    setColor(8);
                }
                else {
                    setColor(0);
                }
            }
            else if (ch == '@') {
                setColor(15);
            }
        }

        cout << ch;
        resetColor();
    }

    void display() {
        system("cls");

        markVisibleCells();

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                displayChar(x, y);
            }
            cout << endl;
        }

        cout << "\n=== CONTROLS ===" << endl;
        cout << "Move:    W A S D" << endl;
        cout << "Exit:    Q" << endl;
        cout << "Light:   1" << endl;

        if (torchMode) {
            cout << "Look:    ARROWS" << endl;
            cout << "\n=== TORCH MODE ===" << endl;
        }
        else {
            cout << "\n=== RADIUS MODE ===" << endl;
        }

        cout << "Direction: ";
        char displayDir = viewDirection;

        if (displayDir == 72) {
            cout << "UP";
        }
        else if (displayDir == 80) {
            cout << "DOWN";
        }
        else if (displayDir == 75) {
            cout << "LEFT";
        }
        else if (displayDir == 77) {
            cout << "RIGHT";
        }
        else if (displayDir == 'w') {
            cout << "UP (W)";
        }
        else if (displayDir == 's') {
            cout << "DOWN (S)";
        }
        else if (displayDir == 'a') {
            cout << "LEFT (A)";
        }
        else if (displayDir == 'd') {
            cout << "RIGHT (D)";
        }
        cout << endl;
    }

    bool canMove(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height) {
            return false;
        }
        return level[y][x] == '.';
    }

    void movePlayer(int dx, int dy) {
        int newX = playerX + dx;
        int newY = playerY + dy;

        if (canMove(newX, newY)) {
            visited[playerY][playerX] = true;
            level[playerY][playerX] = '.';
            playerX = newX;
            playerY = newY;
            visited[playerY][playerX] = true;
            level[playerY][playerX] = '@';

            if (dx == 0 && dy == -1) viewDirection = 'w';
            if (dx == 0 && dy == 1) viewDirection = 's';
            if (dx == -1 && dy == 0) viewDirection = 'a';
            if (dx == 1 && dy == 0) viewDirection = 'd';
        }
    }

    void changeViewDirection(int arrowKey) {
        viewDirection = arrowKey;
    }

    void run() {
        bool running = true;

        display();

        while (running) {
            if (_kbhit()) {
                int key = _getch();

                if (key == 0 || key == 224) {
                    int arrow = _getch();
                    if (torchMode) {
                        changeViewDirection(arrow);
                        display();
                    }
                }
                else {
                    char ch = tolower(key);

                    switch (ch) {
                    case 'w':
                        movePlayer(0, -1);
                        break;
                    case 's':
                        movePlayer(0, 1);
                        break;
                    case 'a':
                        movePlayer(-1, 0);
                        break;
                    case 'd':
                        movePlayer(1, 0);
                        break;
                    case '1':
                        torchMode = !torchMode;
                        display();
                        break;
                    case 'q':
                        running = false;
                        cout << "\nExit..." << endl;
                        continue;
                    default:
                        continue;
                    }

                    display();
                }
            }
        }
    }
};

int main() {
    system("chcp 65001 > nul");
    system("title Maze Game");
    system("color 07");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    Game game;

    if (game.loadLevel("level1.txt")) {
        game.run();
    }
    else {
        cout << "Press any key to exit..." << endl;
        _getch();
    }

    return 0;
}