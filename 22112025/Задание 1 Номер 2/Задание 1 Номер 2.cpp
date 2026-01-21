// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstring>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size = 100;
    int count = 0;

    char** phonebook = new char* [2];
    phonebook[0] = new char[size * 50];
    phonebook[1] = new char[size * 20];

    int choice;

    do {
        cout << "\n=== ТЕЛЕФОННАЯ КНИГА ===\n";
        cout << "1. Добавить запись\n";
        cout << "2. Поиск по имени\n";
        cout << "3. Поиск по телефону\n";
        cout << "4. Изменить данные\n";
        cout << "5. Показать все\n";
        cout << "0. Выход\n";
        cout << "Выберите: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            if (count >= size) {
                cout << "Телефонная книга заполнена!\n";
                break;
            }

            char name[50], phone[20];
            cout << "Введите имя: ";
            cin.getline(name, 50);
            cout << "Введите телефон: ";
            cin.getline(phone, 20);

            strcpy(&phonebook[0][count * 50], name);
            strcpy(&phonebook[1][count * 20], phone);
            count++;

            cout << "Запись добавлена.\n";
            break;
        }

        case 2: {
            char searchName[50];
            cout << "Введите имя для поиска: ";
            cin.getline(searchName, 50);

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (strcmp(&phonebook[0][i * 50], searchName) == 0) {
                    cout << "Найдено: " << &phonebook[0][i * 50] << " - "
                        << &phonebook[1][i * 20] << endl;
                    found = true;
                }
            }
            if (!found) cout << "Не найдено.\n";
            break;
        }

        case 3: {
            char searchPhone[20];
            cout << "Введите телефон для поиска: ";
            cin.getline(searchPhone, 20);

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (strcmp(&phonebook[1][i * 20], searchPhone) == 0) {
                    cout << "Найдено: " << &phonebook[0][i * 50] << " - "
                        << &phonebook[1][i * 20] << endl;
                    found = true;
                }
            }
            if (!found) cout << "Не найдено.\n";
            break;
        }

        case 4: {
            char searchName[50];
            cout << "Введите имя для изменения: ";
            cin.getline(searchName, 50);

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (strcmp(&phonebook[0][i * 50], searchName) == 0) {
                    char newName[50], newPhone[20];
                    cout << "Текущие данные: " << &phonebook[0][i * 50]
                        << " - " << &phonebook[1][i * 20] << endl;
                    cout << "Введите новое имя: ";
                    cin.getline(newName, 50);
                    cout << "Введите новый телефон: ";
                    cin.getline(newPhone, 20);

                    strcpy(&phonebook[0][i * 50], newName);
                    strcpy(&phonebook[1][i * 20], newPhone);

                    cout << "Данные обновлены.\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Не найдено.\n";
            break;
        }

        case 5: {
            if (count == 0) {
                cout << "Телефонная книга пуста.\n";
            }
            else {
                cout << "\nВсе записи:\n";
                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". " << &phonebook[0][i * 50]
                        << " - " << &phonebook[1][i * 20] << endl;
                }
            }
            break;
        }

        case 0:
            cout << "Выход.\n";
            break;

        default:
            cout << "Неверный выбор.\n";
        }

    } while (choice != 0);

    delete[] phonebook[0];
    delete[] phonebook[1];
    delete[] phonebook;

    return 0;
}