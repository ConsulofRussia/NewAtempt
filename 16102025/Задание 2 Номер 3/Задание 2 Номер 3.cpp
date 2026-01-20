// Задание 2 Номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateNumber() {
    srand(time(NULL));
    int digits[10] = { 0,1,2,3,4,5,6,7,8,9 };

    for (int i = 0; i < 10; i++) {
        int j = rand() % 10;
        swap(digits[i], digits[j]);
    }

    return digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
}

void checkBullsCows(int secret, int guess, int& bulls, int& cows) {
    bulls = cows = 0;
    int secretDigits[4], guessDigits[4];

    int tempSecret = secret;
    int tempGuess = guess;
    for (int i = 3; i >= 0; i--) {
        secretDigits[i] = tempSecret % 10;
        guessDigits[i] = tempGuess % 10;
        tempSecret /= 10;
        tempGuess /= 10;
    }

    for (int i = 0; i < 4; i++) {
        if (secretDigits[i] == guessDigits[i]) {
            bulls++;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j && secretDigits[i] == guessDigits[j]) {
                cows++;
                break;
            }
        }
    }
}

void playGame(int secret, int attempts) {
    if (attempts == 0) {
        cout << "Загаданное число: " << secret << endl;
        return;
    }

    cout << "\nПопытка #" << attempts << endl;
    cout << "Введите ваше предположение (4 цифры): ";

    int guess;
    cin >> guess;

    if (guess < 1000 || guess > 9999) {
        cout << "Ошибка! Введите 4-значное число.\n";
        playGame(secret, attempts);
        return;
    }

    int bulls, cows;
    checkBullsCows(secret, guess, bulls, cows);

    if (bulls == 4) {
        cout << "Поздравляем! Вы угадали число " << secret << "!\n";
        cout << "Количество попыток: " << attempts << endl;
        return;
    }

    cout << "Быки: " << bulls << ", Коровы: " << cows << endl;

    playGame(secret, attempts + 1);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== ИГРА 'БЫКИ И КОРОВЫ' ===\n\n";
    cout << "Правила:\n";
    cout << "- Компьютер загадывает 4-значное число без повторяющихся цифр\n";
    cout << "- Вы должны угадать это число\n";
    cout << "- Быки: цифра и позиция совпадают\n";
    cout << "- Коровы: цифра есть, но позиция не совпадает\n\n";

    int secretNumber = generateNumber();

    cout << "Игра началась! Компьютер загадал число.\n";

    playGame(secretNumber, 1);

    return 0;
}