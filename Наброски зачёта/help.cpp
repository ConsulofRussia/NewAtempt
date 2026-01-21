#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <string>
#include <windows.h>
#include <cmath>
#include <cstdlib> 
#include <ctime> 

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

    int batteryCharge;
    int stepsCounter;
    vector<char> inventory;

    bool showInventory;
    string message;

    bool inBattle;
    int enemyHP;
    int playerHP;
    int playerAttack;
    int enemyAttack;
    int battleX, battleY;

public:
    Game() : playerX(0), playerY(0), width(0), height(0),
        viewDirection('s'), torchMode(false),
        batteryCharge(100), stepsCounter(0),
        showInventory(false), message(""),
        inBattle(false), enemyHP(0), playerHP(100),
        playerAttack(20), enemyAttack(15),
        battleX(0), battleY(0) {
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
                if (level[y][x] == '.' || level[y][x] == 'B' || level[y][x] == '&') {
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

    bool useBattery() {
        stepsCounter++;
        if (stepsCounter >= 5) {
            stepsCounter = 0;
            if (batteryCharge > 0) {
                batteryCharge--;
                return true;
            }
            else {
                if (torchMode) {
                    torchMode = false;
                    message = "Flashlight discharged!";
                }
                return false;
            }
        }
        return true;
    }

    void rechargeBattery(int amount) {
        int oldCharge = batteryCharge;
        batteryCharge += amount;
        if (batteryCharge > 100) batteryCharge = 100;
        message = "Battery recharged: +" + to_string(batteryCharge - oldCharge) + "%";
    }

    void pickupItem() {
        bool pickedUp = false;

        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dx == 0 && dy == 0) continue;

                int checkX = playerX + dx;
                int checkY = playerY + dy;

                if (checkX >= 0 && checkX < width && checkY >= 0 && checkY < height) {
                    if (level[checkY][checkX] == 'B') {
                        inventory.push_back('B');
                        level[checkY][checkX] = '.';
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

    bool checkEnemyNearby() {
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dx == 0 && dy == 0) continue; 

                int checkX = playerX + dx;
                int checkY = playerY + dy;

                if (checkX >= 0 && checkX < width && checkY >= 0 && checkY < height) {
                    if (level[checkY][checkX] == '&') {
                        battleX = checkX;
                        battleY = checkY;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void startBattleWithNearbyEnemy() {
        if (checkEnemyNearby()) {
            enterBattle(battleX, battleY);
        }
        else {
            message = "No enemy nearby to fight!";
        }
    }

    void useBatteryFromInventory() {
        if (!inventory.empty()) {
            for (auto it = inventory.begin(); it != inventory.end(); ++it) {
                if (*it == 'B') {
                    rechargeBattery(25);
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
                        level[y][x] == 'B' || level[y][x] == ' ' || level[y][x] == '&') {
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
                setColor(14);
            }
            else if (ch == '&') {
                setColor(12); 
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
            else if (ch == '.' || ch == 'B' || ch == '&') {
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

    void displayInventory(int startX) {
        setColor(11);
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

            setColor(14);
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
        setColor(10);
        cout << "Use: U";
        resetColor();
        cout << endl;
    }

    void displayBatteryInfo(int startX) {
        setColor(11);
        cout << "=== FLASHLIGHT ===";
        resetColor();
        cout << endl;

        cout << "Charge: [";
        setColor(batteryCharge > 20 ? 10 : 12);
        for (int i = 0; i < 10; i++) {
            if (batteryCharge >= (i + 1) * 10) {
                cout << char(219);
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
                setColor(10);
                cout << "FLASHLIGHT";
            }
            else {
                setColor(12);
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

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                displayChar(x, y);
            }

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
                cout << "  Fight:   F (when enemy nearby)";
            }
            else if (y == 8) {
                cout << "  Exit:    Q";
            }
            else if (y == 9) {
                cout << "  ";
                setColor(10);
                cout << "=== STATUS ===";
                resetColor();
            }
            else if (y == 10) {
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
            else if (y == 11) {
                if (checkEnemyNearby()) {
                    setColor(12);
                    cout << "  Enemy nearby! Press F to fight";
                    resetColor();
                }
            }
            else if (y == 12) {
                if (!message.empty()) {
                    setColor(14);
                    cout << "  " << message;
                    resetColor();
                    message = "";
                }
            }

            cout << endl;
        }

        cout << "  ";
        if (showInventory) {
            displayInventory(width + 2);
        }
        else {
            displayBatteryInfo(width + 2);
        }
    }

    void displayBattle() {
        system("cls");

        setColor(12);
        cout << "================================" << endl;
        cout << "           BATTLE MODE          " << endl;
        cout << "================================" << endl;
        resetColor();

        cout << endl;

        setColor(12);
        cout << "ENEMY" << endl;
        cout << "HP: [";
        for (int i = 0; i < 20; i++) {
            if (enemyHP > i * 5) {
                cout << char(219);
            }
            else {
                cout << " ";
            }
        }
        cout << "] " << enemyHP << "/100" << endl;
        resetColor();

        cout << endl;

        setColor(10);
        cout << "PLAYER" << endl;
        cout << "HP: [";
        for (int i = 0; i < 20; i++) {
            if (playerHP > i * 5) {
                cout << char(219);
            }
            else {
                cout << " ";
            }
        }
        cout << "] " << playerHP << "/100" << endl;
        resetColor();

        cout << endl;
        cout << "================================" << endl;
        cout << "        CHOOSE ACTION:" << endl;
        cout << "================================" << endl;
        cout << endl;

        setColor(14);
        cout << "  [A] - ATTACK (Deal " << playerAttack << " damage)" << endl;
        cout << "  [F] - FLEE (Try to escape)" << endl;
        cout << "  [U] - USE BATTERY (Restore 30 HP)" << endl;
        resetColor();

        cout << endl;
        if (!message.empty()) {
            setColor(14);
            cout << "> " << message << endl;
            resetColor();
            message = "";
        }
    }

    void enterBattle(int enemyX, int enemyY) {
        inBattle = true;
        battleX = enemyX;
        battleY = enemyY;

        // Инициализация боя
        enemyHP = 100;
        playerHP = 100;

        battleLoop();
    }

    void playerAttackEnemy() {
        int damage = playerAttack + (rand() % 10);
        enemyHP -= damage;
        if (enemyHP < 0) enemyHP = 0;

        message = "You dealt " + to_string(damage) + " damage to enemy!";

        if (enemyHP <= 0) {
            // Победа
            displayBattle();
            Sleep(1000);

            system("cls");
            setColor(10);
            cout << "================================" << endl;
            cout << "        VICTORY!" << endl;
            cout << "================================" << endl;
            resetColor();
            cout << "You defeated the enemy!" << endl;
            cout << "Press any key to continue..." << endl;
            _getch();

            // Убираем врага с карты
            level[battleY][battleX] = '.';
            visited[battleY][battleX] = true;

            inBattle = false;
            return;
        }

        // Враг атакует в ответ
        Sleep(500);
        int enemyDamage = enemyAttack + (rand() % 10);
        playerHP -= enemyDamage;
        if (playerHP < 0) playerHP = 0;

        message += "\nEnemy dealt " + to_string(enemyDamage) + " damage to you!";

        if (playerHP <= 0) {
            // Поражение
            displayBattle();
            Sleep(1000);

            system("cls");
            setColor(12);
            cout << "================================" << endl;
            cout << "         GAME OVER" << endl;
            cout << "================================" << endl;
            resetColor();
            cout << "You were defeated..." << endl;
            cout << "Press any key to exit..." << endl;
            _getch();
            exit(0);
        }
    }

    bool tryFlee() {
        // 70% шанс побега
        if (rand() % 100 < 70) {
            return true;
        }
        return false;
    }

    void playerFlee() {
        if (tryFlee()) {
            message = "You successfully fled from battle!";
            displayBattle();
            Sleep(1000);
            inBattle = false;
        }
        else {
            message = "Failed to flee! Enemy attacks!";

            Sleep(500);
            int enemyDamage = enemyAttack + (rand() % 15);
            playerHP -= enemyDamage;
            if (playerHP < 0) playerHP = 0;

            message += "\nEnemy dealt " + to_string(enemyDamage) + " damage to you!";

            if (playerHP <= 0) {
                displayBattle();
                Sleep(1000);

                system("cls");
                setColor(12);
                cout << "================================" << endl;
                cout << "         GAME OVER" << endl;
                cout << "================================" << endl;
                resetColor();
                cout << "You were defeated..." << endl;
                cout << "Press any key to exit..." << endl;
                _getch();
                exit(0);
            }
        }
    }

    void useBatteryInBattle() {
        if (!inventory.empty()) {
            bool used = false;
            for (auto it = inventory.begin(); it != inventory.end(); ++it) {
                if (*it == 'B') {
                    int heal = 30;
                    playerHP += heal;
                    if (playerHP > 100) playerHP = 100;

                    inventory.erase(it);
                    message = "Used battery! Restored " + to_string(heal) + " HP!";
                    used = true;
                    break;
                }
            }

            if (!used) {
                message = "No batteries in inventory!";
            }
        }
        else {
            message = "Inventory is empty!";
        }
    }

    void battleLoop() {
        while (inBattle) {
            displayBattle();

            if (_kbhit()) {
                int key = _getch();
                char ch = tolower(key);

                switch (ch) {
                case 'a':
                    playerAttackEnemy();
                    break;
                case 'f':
                    playerFlee();
                    break;
                case 'u':
                    useBatteryInBattle();
                    break;
                default:
                    continue;
                }

                if (!inBattle) {
                    break;
                }
            }
        }
    }

    bool canMove(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height) {
            return false;
        }
        char cell = level[y][x];

        return cell == '.' || cell == 'B';
    }

    void movePlayer(int dx, int dy) {
        int newX = playerX + dx;
        int newY = playerY + dy;

        if (canMove(newX, newY)) {
            if (torchMode) {
                if (!useBattery()) {
                    torchMode = false;
                }
            }

            char targetCell = level[newY][newX];

            visited[playerY][playerX] = true;
            level[playerY][playerX] = '.';
            playerX = newX;
            playerY = newY;
            visited[playerY][playerX] = true;

            level[playerY][playerX] = '@';

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
                            torchMode = false;
                            message = "Flashlight discharged!";
                        }
                        break;
                    case 'i':
                        showInventory = !showInventory;
                        break;
                    case 'p':
                        pickupItem();
                        break;
                    case 'u':
                        useBatteryFromInventory();
                        break;
                    case 'f': // Новая клавиша для начала боя
                        startBattleWithNearbyEnemy();
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
    // Для русского текста потом верну
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);

    system("title Maze Game with Flashlight and Battle System");
    system("color 07");

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