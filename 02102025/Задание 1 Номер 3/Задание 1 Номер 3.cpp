// Задание 1 Номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

bool isPerfectNumber(int number) {

    if (number <= 0) {
        return false;
    }

    int sumOfDivisors = 0;

    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sumOfDivisors += i;
        }
    }

    return sumOfDivisors == number;
}

void findPerfectNumbers(int start, int end) {
    cout << "Совершенные числа в интервале [" << start << ", " << end << "]:" << endl;

    bool foundAny = false;

    for (int num = start; num <= end; num++) {
        if (isPerfectNumber(num)) {
            cout << "  " << num << " - совершенное число!" << endl;

            cout << "    Делители: ";
            for (int i = 1; i <= num / 2; i++) {
                if (num % i == 0) {
                    cout << i << " ";
                }
            }
            cout << endl;
            cout << "    Сумма делителей: " << num << endl;

            foundAny = true;
        }
    }

    if (!foundAny) {
        cout << "  Совершенных чисел не найдено" << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== ПОИСК СОВЕРШЕННЫХ ЧИСЕЛ ===\n\n";

    int start, end;

    cout << "Введите начало интервала: ";
    cin >> start;

    cout << "Введите конец интервала: ";
    cin >> end;

    if (start > end) {
        cout << "Ошибка: начало интервала больше конца!" << endl;
        cout << "Меняю местами..." << endl;
        int temp = start;
        start = end;
        end = temp;
    }
    findPerfectNumbers(start, end);
    return 0;
}