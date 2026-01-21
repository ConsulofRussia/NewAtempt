// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string inputFile, outputFile;

    cout << "Введите имя исходного файла: ";
    getline(cin, inputFile);

    cout << "Введите имя файла для результата: ";
    getline(cin, outputFile);

    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << inputFile << endl;
        return 1;
    }

    vector<string> lines;
    string line;

    while (getline(inFile, line)) {
        lines.push_back(line);
    }
    inFile.close();

    if (lines.empty()) {
        cout << "Файл пуст. Создан пустой файл результата." << endl;

        ofstream outFile(outputFile);
        outFile.close();

        cout << "Создан пустой файл: " << outputFile << endl;
        return 0;
    }

    cout << "Исходный файл содержит " << lines.size() << " строк." << endl;
    cout << "Удаляется последняя строка..." << endl;

    lines.pop_back();

    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        cout << "Ошибка: не удалось создать файл " << outputFile << endl;
        return 1;
    }

    for (size_t i = 0; i < lines.size(); i++) {
        outFile << lines[i];
        if (i != lines.size() - 1) {
            outFile << endl;
        }
    }
    outFile.close();

    cout << "Файл успешно обработан!" << endl;
    cout << "Новый файл содержит " << lines.size() << " строк." << endl;
    cout << "Результат сохранен в файле: " << outputFile << endl;

    return 0;
}