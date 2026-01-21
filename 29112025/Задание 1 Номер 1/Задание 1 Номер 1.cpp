// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string inputFileName, outputFileName;

    cout << "Введите имя входного файла созданного вами(обязательно добавьте .txt): ";
    getline(cin, inputFileName);

    cout << "Введите имя выходного файла(обязательно добавьте .txt): ";
    getline(cin, outputFileName);

    ifstream countFile(inputFileName);
    if (!countFile.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << inputFileName << endl;
        return 1;
    }

    int lineCount = 0;
    string tempLine;

    while (getline(countFile, tempLine)) {
        lineCount++;
    }

    countFile.close();

    if (lineCount == 0) {
        cout << "Файл пуст. Создан пустой выходной файл." << endl;

        ofstream outputFile(outputFileName);
        outputFile.close();

        cout << "Создан пустой файл: " << outputFileName << endl;
        return 0;
    }

    cout << "Количество строк в исходном файле: " << lineCount << endl;

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Ошибка при открытии файлов." << endl;
        return 1;
    }

    int currentLine = 0;

    while (getline(inputFile, tempLine)) {
        currentLine++;

        if (currentLine < lineCount) {
            outputFile << tempLine;

            if (currentLine < lineCount - 1) {
                outputFile << endl;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Операция завершена успешно!" << endl;
    cout << "Количество строк в новом файле: " << lineCount - 1 << endl;
    cout << "Результат записан в файл: " << outputFileName << endl;

    return 0;
}