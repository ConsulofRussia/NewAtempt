// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) return isLeapYear(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

int dateToDays(int day, int month, int year) {
    int days = 0;

    for (int y = 1; y < year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < month; m++) {
        days += daysInMonth(m, year);
    }

    days += day - 1;

    return days;
}

int dateDifference(int d1, int m1, int y1, int d2, int m2, int y2) {
    int days1 = dateToDays(d1, m1, y1);
    int days2 = dateToDays(d2, m2, y2);
    return abs(days2 - days1);
}

int dateDifferenceArray(int date1[3], int date2[3]) {
    return dateDifference(date1[0], date1[1], date1[2],
        date2[0], date2[1], date2[2]);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int d1, m1, y1, d2, m2, y2;

    cout << "Первая дата (день месяц год): ";
    cin >> d1 >> m1 >> y1;

    cout << "Вторая дата (день месяц год): ";
    cin >> d2 >> m2 >> y2;

    cout << "\nРазница: " << dateDifference(d1, m1, y1, d2, m2, y2) << " дней\n";

    int date1[3] = { d1, m1, y1 };
    int date2[3] = { d2, m2, y2 };
    cout << "Разница (через массивы): " << dateDifferenceArray(date1, date2) << " дней\n";

    return 0;
}