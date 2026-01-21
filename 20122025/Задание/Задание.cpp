// Задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename, word;

    cout << "Введите имя файла: ";
    getline(cin, filename);

    cout << "Введите слово для поиска: ";
    getline(cin, word);

    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!\n";
        return 1;
    }

    int count = 0;
    string line;
    vector<string> foundLines;

    while (getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != string::npos) {
            count++;
            foundLines.push_back(line);
            pos += word.length();
        }
    }
    file.close();

    cout << "\nНайдено совпадений: " << count << "\n";

    if (count > 0) {
        cout << "\nСтроки с совпадениями:\n";
        for (size_t i = 0; i < foundLines.size(); i++) {
            cout << i + 1 << ": " << foundLines[i] << "\n";
        }

        cout << "\nХотите заменить слово? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();

        if (choice == 'y' || choice == 'Y') {
            string newWord;
            cout << "Введите новое слово: ";
            getline(cin, newWord);

            file.open(filename.c_str());
            string content;
            while (getline(file, line)) {
                size_t pos = 0;
                while ((pos = line.find(word, pos)) != string::npos) {
                    line.replace(pos, word.length(), newWord);
                    pos += newWord.length();
                }
                content += line + "\n";
            }
            file.close();

            ofstream out(filename.c_str());
            out << content;
            out.close();

            cout << "Слово заменено!\n";
        }
    }

    return 0;
}