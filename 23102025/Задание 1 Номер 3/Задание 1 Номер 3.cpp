// Задание 1 Номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double profit[12];
    string months[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
                         "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };

    cout << "Введите прибыль фирмы за год (12 месяцев):\n";

    for (int i = 0; i < 12; i++) {
        cout << months[i] << ": ";
        cin >> profit[i];
    }

    int startMonth, endMonth;

    cout << "\nВведите начало диапазона (номер месяца от 1 до 12): ";
    cin >> startMonth;
    cout << "Введите конец диапазона (номер месяца от 1 до 12): ";
    cin >> endMonth;

    if (startMonth < 1 || startMonth > 12 || endMonth < 1 || endMonth > 12 || startMonth > endMonth) {
        cout << "Ошибка! Неверно указан диапазон.\n";
        return 1;
    }

    int startIndex = startMonth - 1;
    int endIndex = endMonth - 1;

    int minMonthIndex = startIndex;
    int maxMonthIndex = startIndex;
    double minProfit = profit[startIndex];
    double maxProfit = profit[startIndex];

    for (int i = startIndex + 1; i <= endIndex; i++) {
        if (profit[i] < minProfit) {
            minProfit = profit[i];
            minMonthIndex = i;
        }
        if (profit[i] > maxProfit) {
            maxProfit = profit[i];
            maxMonthIndex = i;
        }
    }

    cout << "\n=== РЕЗУЛЬТАТЫ В ДИАПАЗОНЕ " << startMonth << "-" << endMonth << " МЕСЯЦ ===" << endl;
    cout << "Минимальная прибыль: " << minProfit << " в " << months[minMonthIndex] << endl;
    cout << "Максимальная прибыль: " << maxProfit << " в " << months[maxMonthIndex] << endl;

    return 0;
}