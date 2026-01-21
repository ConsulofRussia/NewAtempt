// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file1("file1.txt");
    ifstream file2("file2.txt");

    if (!file1.is_open()) {
        cout << "Ошибка открытия file1.txt\n";
        return 1;
    }
    if (!file2.is_open()) {
        cout << "Ошибка открытия file2.txt\n";
        return 1;
    }

    string line1, line2;
    int lineNum = 1;
    bool allMatch = true;

    while (getline(file1, line1) || getline(file2, line2)) {
        if (line1 != line2) {
            cout << "Несовпадение в строке " << lineNum << ":\n";
            cout << "file1.txt: " << line1 << endl;
            cout << "file2.txt: " << line2 << endl;
            cout << endl;
            allMatch = false;
        }
        lineNum++;
        line1 = "";
        line2 = "";
    }

    if (allMatch) {
        cout << "Все строки совпадают.\n";
    }

    file1.close();
    file2.close();

    return 0;
}