// Задание 1 Номер 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

using namespace std;

void printPlayingCard(int value, char suit) {
    string cards[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

    if (value < 1 || value > 13) {
        cout << "Ошибка: значение должно быть от 1 до 13" << endl;
        return;
    }

    char suitChar;
    if (suit == 'S') suitChar = 6;
    else if (suit == 'H') suitChar = 3;
    else if (suit == 'D') suitChar = 4;
    else if (suit == 'C') suitChar = 5;
    else {
        cout << "Ошибка: неверная масть" << endl;
        return;
    }

    string cardValue = cards[value - 1];

    cout << " ---------" << endl;
    if (value == 10) {
        cout << "|" << cardValue << suitChar << "       |" << endl;
    }
    else {
        cout << "|" << cardValue << suitChar << "        |" << endl;
    }
    cout << "|         |" << endl;
    cout << "|         |" << endl;
    cout << "|    " << suitChar << "    |" << endl;
    cout << "|         |" << endl;
    cout << "|         |" << endl;
    if (value == 10) {
        cout << "|       " << suitChar << cardValue << "|" << endl;
    }
    else {
        cout << "|        " << suitChar << cardValue << "|" << endl;
    }
    cout << " ---------" << endl;
}

int main() {
    printPlayingCard(4, 'H');
    return 0;
}