// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    long long number;
    int choice;

    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Ввести число" << endl;
        cout << "2. Подсчитать количество цифр" << endl;
        cout << "3. Найти сумму цифр" << endl;
        cout << "4. Найти среднее арифметическое цифр" << endl;
        cout << "5. Подсчитать количество нулей" << endl;
        cout << "6. Показать все результаты" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Выход из программы." << endl;
            break;
        }

        if (choice == 1) {
            cout << "Введите число: ";
            cin >> number;
            cout << "Число сохранено." << endl;
            continue;
        }

        if (number == 0 && choice != 1) {
            cout << "Ошибка! Сначала введите число (выберите пункт 1)." << endl;
            continue;
        }

        long long temp = abs(number); 
        int digitCount = 0;
        int digitSum = 0;
        int zeroCount = 0;

        if (temp == 0) {
            digitCount = 1;
            zeroCount = 1;
        }
        else {
            while (temp > 0) {
                int digit = temp % 10;
                digitCount++;
                digitSum += digit;
                if (digit == 0) zeroCount++;
                temp /= 10;
            }
        }

        double average = (digitCount > 0) ? (double)digitSum / digitCount : 0;

        switch (choice) {
        case 2:
            cout << "Количество цифр в числе " << number << ": " << digitCount << endl;
            break;
        case 3:
            cout << "Сумма цифр числа " << number << ": " << digitSum << endl;
            break;
        case 4:
            cout << "Среднее арифметическое цифр числа " << number << ": " << average << endl;
            break;
        case 5:
            cout << "Количество нулей в числе " << number << ": " << zeroCount << endl;
            break;
        case 6:
            cout << "\n=== РЕЗУЛЬТАТЫ ДЛЯ ЧИСЛА " << number << " ===" << endl;
            cout << "Количество цифр: " << digitCount << endl;
            cout << "Сумма цифр: " << digitSum << endl;
            cout << "Среднее арифметическое цифр: " << average << endl;
            cout << "Количество нулей: " << zeroCount << endl;
            break;
        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
        }

    } while (choice != 0);

    return 0;
}