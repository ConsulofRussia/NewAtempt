// Задание 1 Номер 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double exchangeRate[12]; 
    double depositInterest[12];
    double depositAmount;  
    int month;

    cout << "Введите сумму депозита в евро: ";
    cin >> depositAmount;

    cout << "\nВведите курс доллара к евро за каждый месяц:\n";
    for (int i = 0; i < 12; i++) {
        cout << "Месяц " << i + 1 << ": ";
        cin >> exchangeRate[i];
    }

    cout << "\nВведите начисленные проценты по депозиту (в евро) за каждый месяц:\n";
    for (int i = 0; i < 12; i++) {
        cout << "Месяц " << i + 1 << ": ";
        cin >> depositInterest[i];
    }

    cout << "\nВведите номер месяца (1-12): ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Ошибка! Месяц должен быть от 1 до 12.\n";
        return 1;
    }

    int index = month - 1;

    double interestInDollars = depositInterest[index] * exchangeRate[index];

    cout << "\n=== РАСЧЕТ ===\n";
    cout << "Начисленные проценты в месяц " << month << ":\n";
    cout << "- В евро: " << depositInterest[index] << " EUR\n";
    cout << "- В долларах: " << interestInDollars << " USD\n";

    if (interestInDollars >= 500) {
        double maxWithdraw = interestInDollars * 0.5; 
        cout << "\nМожно обналичить: " << maxWithdraw << " USD\n";
        cout << "(50% от начисленной суммы, так как она >= 500 USD)\n";
    }
    else {
        cout << "\nОбналичивать нельзя!\n";
        cout << "Начисленная сумма (" << interestInDollars << " USD) меньше 500 USD\n";
    }

    return 0;
}