// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <Windows.h>

using namespace std;

void replaceWord(string& text, const string& oldWord, const string& newWord) {
    size_t pos = 0;
    while ((pos = text.find(oldWord, pos)) != string::npos) {
        text.replace(pos, oldWord.length(), newWord);
        pos += newWord.length();
    }
}
void capitalizeSentences(string& text) {
    if (text.empty()) return;

    text[0] = toupper(text[0]);

    for (size_t i = 1; i < text.length(); i++) {
        if ((text[i - 1] == '.' || text[i - 1] == '!' || text[i - 1] == '?') &&
            i + 1 < text.length() && isalpha(text[i + 1])) {
            text[i + 1] = toupper(text[i + 1]);
        }
    }
}
void countAndPrintLetters(const string& text) {
    map<char, int> letters;

    for (char c : text) {
        if (isalpha(c)) {
            letters[tolower(c)]++;
        }
    }

    cout << "\nСтатистика букв:" << endl;
    for (const auto& pair : letters) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int countDigits(const string& text) {
    int count = 0;
    for (char c : text) {
        if (isdigit(c)) count++;
    }
    return count;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;
    cout << "Введите текст на английском: ";
    getline(cin, text);

    string oldWord, newWord;
    cout << "\nЗамена слова. Введите слово для поиска: ";
    getline(cin, oldWord);
    cout << "Введите слово для замены: ";
    getline(cin, newWord);

    replaceWord(text, oldWord, newWord);
    cout << "\nТекст после замены:\n" << text << endl;

    capitalizeSentences(text);
    cout << "\nТекст после исправления предложений:\n" << text << endl;

    countAndPrintLetters(text);

    int digits = countDigits(text);
    cout << "\nКоличество цифр в тексте: " << digits << endl;

    return 0;
}