// Задание 1 Номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class CaesarCipher {
private:
    const string russianLower = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    const string russianUpper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    const string englishLower = "abcdefghijklmnopqrstuvwxyz";
    const string englishUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

public:
    // Шифрование символа
    char encrypt(char ch, int key) {
        return shiftChar(ch, key);
    }

    // Дешифрование символа
    char decrypt(char ch, int key) {
        return shiftChar(ch, -key);
    }

private:
    char shiftChar(char ch, int shift) {
        size_t pos;

        // Русские строчные буквы
        pos = russianLower.find(ch);
        if (pos != string::npos) {
            return circularShift(russianLower, pos, shift);
        }

        // Русские прописные буквы
        pos = russianUpper.find(ch);
        if (pos != string::npos) {
            return circularShift(russianUpper, pos, shift);
        }

        // Английские строчные буквы
        pos = englishLower.find(ch);
        if (pos != string::npos) {
            return circularShift(englishLower, pos, shift);
        }

        // Английские прописные буквы
        pos = englishUpper.find(ch);
        if (pos != string::npos) {
            return circularShift(englishUpper, pos, shift);
        }

        // Если не буква, возвращаем без изменений
        return ch;
    }

    char circularShift(const string& alphabet, size_t pos, int shift) {
        int alphabetSize = alphabet.size();
        int newPos = (pos + shift) % alphabetSize;

        // Обработка отрицательных значений
        if (newPos < 0) {
            newPos += alphabetSize;
        }

        return alphabet[newPos];
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CaesarCipher cipher;

    string inputFileName, outputFileName;
    int key;
    char choice;

    cout << "=== Шифр Цезаря ===" << endl;
    cout << "1. Зашифровать файл" << endl;
    cout << "2. Расшифровать файл" << endl;
    cout << "Выберите действие (1 или 2): ";
    cin >> choice;
    cin.ignore();

    cout << "Введите имя входного файла: ";
    getline(cin, inputFileName);

    cout << "Введите имя выходного файла: ";
    getline(cin, outputFileName);

    cout << "Введите ключ (целое число): ";
    cin >> key;

    ifstream inputFile(inputFileName, ios::binary);
    if (!inputFile.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << inputFileName << endl;
        return 1;
    }

    ofstream outputFile(outputFileName, ios::binary);
    if (!outputFile.is_open()) {
        cout << "Ошибка: не удалось создать файл " << outputFileName << endl;
        inputFile.close();
        return 1;
    }

    char ch;
    int charCount = 0;

    while (inputFile.get(ch)) {
        char processedChar;

        if (choice == '1') {
            processedChar = cipher.encrypt(ch, key);
        }
        else if (choice == '2') {
            processedChar = cipher.decrypt(ch, key);
        }
        else {
            cout << "Неверный выбор!" << endl;
            inputFile.close();
            outputFile.close();
            return 1;
        }

        outputFile.put(processedChar);
        charCount++;
    }

    inputFile.close();
    outputFile.close();

    cout << "\nОперация завершена успешно!" << endl;
    cout << "Обработано символов: " << charCount << endl;
    cout << "Результат сохранен в файле: " << outputFileName << endl;

    if (choice == '1') {
        cout << "\nПример шифрования (ключ = " << key << "):" << endl;
        cout << "А -> " << cipher.encrypt('А', key) << endl;
        cout << "а -> " << cipher.encrypt('а', key) << endl;
        cout << "A -> " << cipher.encrypt('A', key) << endl;
        cout << "a -> " << cipher.encrypt('a', key) << endl;
    }

    return 0;
}