// Задание 1 Номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string days[7] = { "Понедельник", "Вторник", "Среда", "Четверг",
                      "Пятница", "Суббота", "Воскресенье" };

    double expenses[7];
    double total = 0;
    int countOver100 = 0;

    cout << "Введите расходы за неделю (в долларах):\n";

    for (int i = 0; i < 7; i++) {
        cout << days[i] << ": $";
        cin >> expenses[i];
        total += expenses[i];
    }

    double average = total / 7;

    cout << "\n=== РЕЗУЛЬТАТЫ ===\n";
    cout << "Общая сумма за неделю: $" << total << endl;
    cout << "Средняя сумма в день: $" << average << endl;

    cout << "\nДни, когда расходы превысили $100:\n";
    for (int i = 0; i < 7; i++) {
        if (expenses[i] > 100) {
            countOver100++;
            cout << days[i] << " ($" << expenses[i] << ")" << endl;
        }
    }

    cout << "\nВсего дней с расходами > $100: " << countOver100 << endl;

    return 0;
}