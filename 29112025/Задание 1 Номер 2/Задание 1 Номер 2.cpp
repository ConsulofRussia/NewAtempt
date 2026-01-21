// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string fileName;

    cout << "Введите имя файла, который вы создали в папке проекта, не забудьте .txt: ";
    getline(cin, fileName);

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << fileName << endl;
        return 1;
    }

    int maxLength = 0;
    int lineNumber = 0;
    int longestLineNumber = 0;
    string longestLine;
    string line;

    while (getline(file, line)) {
        lineNumber++;
        int currentLength = line.length();

        if (currentLength > maxLength) {
            maxLength = currentLength;
            longestLineNumber = lineNumber;
            longestLine = line;
        }
    }

    file.close();

    cout << "\n=== Результаты анализа файла ===" << endl;
    cout << "Имя файла: " << fileName << endl;
    cout << "Прочитано строк: " << lineNumber << endl;

    if (lineNumber == 0) {
        cout << "Файл пуст!" << endl;
    }
    else {
        cout << "Длина самой длинной строки: " << maxLength << " символов" << endl;
        cout << "Номер самой длинной строки: " << longestLineNumber << endl;
        cout << "\nСамая длинная строка:" << endl;
        cout << "----------------------------------------" << endl;
        cout << longestLine << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}