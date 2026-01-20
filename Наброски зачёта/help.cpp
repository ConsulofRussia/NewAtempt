#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <string>
#include <windows.h>
#include <cmath>
#include <cstdlib>  // Для rand() и srand()
#include <ctime>    // Для time()

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

    // Система фонарика
    int batteryCharge;     // 0-100
    int stepsCounter;      // счетчик шагов
    vector<char> inventory; // инвентарь (B - батарейки)

    // Интерфейс
    bool showInventory;
    string message;        // Сообщение для отображения

public:
    Game() : playerX(0), playerY(0), width(0), height(0),
        viewDirection('s'), torchMode(false),
        batteryCharge(100), stepsCounter(0),
        showInventory(false), message("") {
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
                if (level[y][x] == '.' || level[y][x] == 'B') {
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

    // Использовать батарею
    bool useBattery() {
        stepsCounter++;
        if (stepsCounter >= 5) {
            stepsCounter = 0;
            if (batteryCharge > 0) {
                batteryCharge--;
                return true;
            }
            else {
                // Батарея разряжена - выключаем фонарик
                if (torchMode) {
                    torchMode = false;
                    message = "Flashlight discharged!";
                }
                return false;
            }
        }
        return true;
    }

    // Зарядить фонарик
    void rechargeBattery(int amount) {
        int oldCharge = batteryCharge;
        batteryCharge += amount;
        if (batteryCharge > 100) batteryCharge = 100;
        message = "Battery recharged: +" + to_string(batteryCharge - oldCharge) + "%";
    }

    // Подобрать предмет
    void pickupItem() {
        // Проверяем клетку под игроком (она уже '@', проверяем что было ДО)
        // Вместо этого проверяем все соседние клетки
        bool pickedUp = false;

        // Проверяем все 8 направлений вокруг игрока
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dx == 0 && dy == 0) continue; // Пропускаем клетку игрока

                int checkX = playerX + dx;
                int checkY = playerY + dy;

                if (checkX >= 0 && checkX < width && checkY >= 0 && checkY < height) {
                    if (level[checkY][checkX] == 'B') {
                        inventory.push_back('B');
                        level[checkY][checkX] = '.'; // Убираем батарейку с уровня
                        pickedUp = true;
                        message = "Battery picked up!";
                    }
                }
            }
        }

        if (!pickedUp) {
            message = "No battery nearby";
        }
    }

    // Использовать батарейку из инвентаря
    void useBatteryFromInventory() {
        if (!inventory.empty()) {
            // Ищем первую батарейку
            for (auto it = inventory.begin(); it != inventory.end(); ++it) {
                if (*it == 'B') {
                    rechargeBattery(25); // +25% заряда
                    inventory.erase(it);
                    break;
                }
            }
        }
        else {
            message = "Inventory is empty";
        }
    }

    bool isVisibleRadius(int x, int y) {
        int distance = abs(x - playerX) + abs(y - playerY);
        return distance <= 1;
    }

    bool isVisibleTorch(int x, int y) {
        // Если батарея разряжена - ничего не видно
        if (batteryCharge <= 0) return false;

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
        if (torchMode && batteryCharge > 0) {
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
                    else if (level[y][x] == '.' || level[y][x] == '@' ||
                        level[y][x] == 'B' || level[y][x] == ' ') {
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
                setColor(8);
            }
            else if (ch == 'B') {
                setColor(14); // Желтый для батареек
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
            else if (ch == '.' || ch == 'B') {
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

    // Отрисовка инвентаря
    void displayInventory(int startX) {
        setColor(11); // Голубой
        cout << "=== INVENTORY ===";
        resetColor();
        cout << endl;

        if (inventory.empty()) {
            cout << "   Empty" << endl;
        }
        else {
            int batteryCount = 0;
            for (char item : inventory) {
                if (item == 'B') batteryCount++;
            }

            setColor(14); // Желтый
            cout << "   Batteries: " << batteryCount;
            resetColor();
            cout << endl;

            for (int i = 0; i < min(5, (int)inventory.size()); i++) {
                if (inventory[i] == 'B') {
                    cout << "   [" << i + 1 << "] Battery" << endl;
                }
            }

            if (inventory.size() > 5) {
                cout << "   ... and " << inventory.size() - 5 << " more" << endl;
            }
        }

        cout << endl;
        setColor(10); // Зеленый
        cout << "Use: U";
        resetColor();
        cout << endl;
    }

    // Отрисовка информации о фонарике
    void displayBatteryInfo(int startX) {
        setColor(11); // Голубой
        cout << "=== FLASHLIGHT ===";
        resetColor();
        cout << endl;

        cout << "Charge: [";
        setColor(batteryCharge > 20 ? 10 : 12); // Зеленый или красный
        for (int i = 0; i < 10; i++) {
            if (batteryCharge >= (i + 1) * 10) {
                cout << char(219); // Полный блок
            }
            else {
                cout << " ";
            }
        }
        resetColor();
        cout << "] " << batteryCharge << "%" << endl;

        cout << "Mode: ";
        if (torchMode) {
            if (batteryCharge > 0) {
                setColor(10); // Зеленый
                cout << "TORCH";
            }
            else {
                setColor(12); // Красный
                cout << "DISCHARGED";
            }
        }
        else {
            cout << "RADIUS";
        }
        resetColor();
        cout << endl;
    }

    void display() {
        system("cls");

        markVisibleCells();

        // Отрисовка уровня и интерфейса в одной строке
        for (int y = 0; y < height; y++) {
            // Уровень
            for (int x = 0; x < width; x++) {
                displayChar(x, y);
            }

            // Интерфейс справа (только первые несколько строк)
            if (y == 0) {
                cout << "  ";
                setColor(11);
                cout << "=== CONTROLS ===";
                resetColor();
            }
            else if (y == 1) {
                cout << "  Move:    W A S D";
            }
            else if (y == 2) {
                cout << "  Flashlight: 1";
            }
            else if (y == 3) {
                cout << "  Look:    ARROWS";
            }
            else if (y == 4) {
                cout << "  Inventory: I";
            }
            else if (y == 5) {
                cout << "  Pickup:  P";
            }
            else if (y == 6) {
                cout << "  Use item: U";
            }
            else if (y == 7) {
                cout << "  Exit:    Q";
            }
            else if (y == 8) {
                cout << "  ";
                setColor(10);
                cout << "=== STATUS ===";
                resetColor();
            }
            else if (y == 9) {
                cout << "  Direction: ";
                char displayDir = viewDirection;
                if (displayDir == 72) cout << "UP";
                else if (displayDir == 80) cout << "DOWN";
                else if (displayDir == 75) cout << "LEFT";
                else if (displayDir == 77) cout << "RIGHT";
                else if (displayDir == 'w') cout << "UP (W)";
                else if (displayDir == 's') cout << "DOWN (S)";
                else if (displayDir == 'a') cout << "LEFT (A)";
                else if (displayDir == 'd') cout << "RIGHT (D)";
            }
            else if (y == 10) {
                // Сообщение
                if (!message.empty()) {
                    setColor(14);
                    cout << "  " << message;
                    resetColor();
                    message = ""; // Сбрасываем сообщение после показа
                }
            }

            cout << endl;
        }

        // Отображение инвентаря или информации о фонарике
        cout << "  ";
        if (showInventory) {
            displayInventory(width + 2);
        }
        else {
            displayBatteryInfo(width + 2);
        }
    }

    bool canMove(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height) {
            return false;
        }
        char cell = level[y][x];
        return cell == '.' || cell == 'B'; // Можно ходить по полу и через батарейки
    }

    void movePlayer(int dx, int dy) {
        int newX = playerX + dx;
        int newY = playerY + dy;

        if (canMove(newX, newY)) {
            // Используем заряд фонарика
            if (torchMode) {
                if (!useBattery()) {
                    // Если батарея разрядилась во время движения
                    torchMode = false;
                }
            }

            // Запоминаем, что было на клетке куда идем
            char targetCell = level[newY][newX];

            visited[playerY][playerX] = true;
            level[playerY][playerX] = '.';
            playerX = newX;
            playerY = newY;
            visited[playerY][playerX] = true;

            // Ставим игрока
            level[playerY][playerX] = '@';

            // Если встали на батарейку - автоматически подбираем
            if (targetCell == 'B') {
                inventory.push_back('B');
                message = "Battery picked up automatically!";
            }

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
                    if (torchMode && batteryCharge > 0) {
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
                        if (batteryCharge > 0) {
                            torchMode = !torchMode;
                            if (torchMode) {
                                message = "Torch ON";
                            }
                            else {
                                message = "Torch OFF";
                            }
                        }
                        else {
                            torchMode = false; // Нельзя включить разряженный
                            message = "Flashlight discharged!";
                        }
                        break;
                    case 'i':
                        showInventory = !showInventory;
                        break;
                    case 'p': // Подобрать предмет (ручной сбор с соседних клеток)
                        pickupItem();
                        break;
                    case 'u': // Использовать предмет из инвентаря
                        useBatteryFromInventory();
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
    // Для русского текста (если нужно будет вернуть)
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);

    system("title Maze Game with Flashlight");
    system("color 07");

    // Инициализация рандома
    srand(static_cast<unsigned int>(time(nullptr)));

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