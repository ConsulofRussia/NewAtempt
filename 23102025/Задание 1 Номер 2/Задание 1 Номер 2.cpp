// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    int size, minRange, maxRange, userValue;

    cout << "Введите размер массива: ";
    cin >> size;

    cout << "Введите минимальное значение диапазона: ";
    cin >> minRange;

    cout << "Введите максимальное значение диапазона: ";
    cin >> maxRange;

    cout << "Введите значение для сравнения: ";
    cin >> userValue;

    int* arr = new int[size];
    int sum = 0;

    cout << "\nМассив: ";
    for (int i = 0; i < size; i++) {
        arr[i] = minRange + rand() % (maxRange - minRange + 1);
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Элементы меньше " << userValue << ": ";
    for (int i = 0; i < size; i++) {
        if (arr[i] < userValue) {
            sum += arr[i];
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    cout << "Сумма элементов меньше " << userValue << ": " << sum << endl;

    delete[] arr;

    return 0;
}