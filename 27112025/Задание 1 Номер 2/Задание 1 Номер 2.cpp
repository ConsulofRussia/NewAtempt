// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

bool isVowel(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    char lower_c = tolower(uc);

    // Для русских букв (кодировка 1251)
    return (lower_c == 224 ||  // 'а' в CP1251
        lower_c == 229 ||  // 'е'
        lower_c == 184 ||  // 'ё'
        lower_c == 232 ||  // 'и'
        lower_c == 238 ||  // 'о'
        lower_c == 243 ||  // 'у'
        lower_c == 251 ||  // 'ы'
        lower_c == 253 ||  // 'э'
        lower_c == 254 ||  // 'ю'
        lower_c == 255 ||  // 'я'
        lower_c == 'a' ||
        lower_c == 'e' ||
        lower_c == 'i' ||
        lower_c == 'o' ||
        lower_c == 'u' ||
        lower_c == 'y');
}

bool isConsonant(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    // Сначала проверяем, является ли символ буквой
    if (!isalpha(static_cast<unsigned char>(c))) return false;
    // Если не гласная, значит согласная
    return !isVowel(c);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream input("input.txt");
    if (!input.is_open()) {
        cout << "Ошибка открытия input.txt\n";
        return 1;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    char c;
    while (input.get(c)) {
        charCount++;

        if (c == '\n') {
            lineCount++;
        }
        else {
            unsigned char uc = static_cast<unsigned char>(c);
            if (isVowel(c)) vowelCount++;
            else if (isConsonant(c)) consonantCount++;
            else if (isdigit(uc)) digitCount++;  // Приводим к unsigned char
        }
    }

    // Учитываем последнюю строку, если она не заканчивается \n
    if (charCount > 0 && c != '\n') {
        lineCount++;
    }

    input.close();

    ofstream output("statistics.txt");
    output << "Статистика файла input.txt:\n";
    output << "Количество символов: " << charCount << endl;
    output << "Количество строк: " << lineCount << endl;
    output << "Количество гласных букв: " << vowelCount << endl;
    output << "Количество согласных букв: " << consonantCount << endl;
    output << "Количество цифр: " << digitCount << endl;

    output.close();

    cout << "Статистика записана в файл statistics.txt\n";

    return 0;
}