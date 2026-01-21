// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

struct Employee {
    string lastName;
    string firstName;
    int age;
    string position;
};

vector<Employee> employees;

void loadFromFile() {
    ifstream file("employees.txt");
    if (!file.is_open()) {
        cout << "Файл не найден. Создан новый." << endl;
        return;
    }

    employees.clear();
    Employee emp;
    while (getline(file, emp.lastName)) {
        getline(file, emp.firstName);
        file >> emp.age;
        file.ignore();
        getline(file, emp.position);
        employees.push_back(emp);
    }
    file.close();
    cout << "Загружено сотрудников: " << employees.size() << endl;
}

void saveToFile() {
    ofstream file("employees.txt");
    for (const auto& emp : employees) {
        file << emp.lastName << endl;
        file << emp.firstName << endl;
        file << emp.age << endl;
        file << emp.position << endl;
    }
    file.close();
    cout << "Сохранено сотрудников: " << employees.size() << endl;
}

void addEmployee() {
    Employee emp;
    cout << "\nВведите фамилию: ";
    getline(cin, emp.lastName);
    cout << "Введите имя: ";
    getline(cin, emp.firstName);
    cout << "Введите возраст: ";
    cin >> emp.age;
    cin.ignore();
    cout << "Введите должность: ";
    getline(cin, emp.position);

    employees.push_back(emp);
    cout << "Сотрудник добавлен!" << endl;
}

void printAll() {
    if (employees.empty()) {
        cout << "Список пуст!" << endl;
        return;
    }

    cout << "\n=== ВСЕ СОТРУДНИКИ ===" << endl;
    for (int i = 0; i < employees.size(); i++) {
        cout << i + 1 << ". " << employees[i].lastName << " "
            << employees[i].firstName << ", " << employees[i].age
            << " лет, " << employees[i].position << endl;
    }
}

void searchByLastName() {
    string lastName;
    cout << "Введите фамилию: ";
    getline(cin, lastName);

    bool found = false;
    for (const auto& emp : employees) {
        if (emp.lastName == lastName) {
            cout << "Найден: " << emp.lastName << " " << emp.firstName
                << ", " << emp.age << " лет, " << emp.position << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Не найдено!" << endl;
    }
}

void searchByAge() {
    int age;
    cout << "Введите возраст: ";
    cin >> age;
    cin.ignore();

    bool found = false;
    for (const auto& emp : employees) {
        if (emp.age == age) {
            cout << "Найден: " << emp.lastName << " " << emp.firstName
                << ", " << emp.position << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Не найдено!" << endl;
    }
}

void searchByFirstLetter() {
    char letter;
    cout << "Введите первую букву фамилии: ";
    cin >> letter;
    cin.ignore();

    bool found = false;
    for (const auto& emp : employees) {
        if (!emp.lastName.empty() && toupper(emp.lastName[0]) == toupper(letter)) {
            cout << "Найден: " << emp.lastName << " " << emp.firstName
                << ", " << emp.age << " лет, " << emp.position << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Не найдено!" << endl;
    }
}

void showMenu() {
    cout << "\n=== СИСТЕМА 'СОТРУДНИКИ' ===" << endl;
    cout << "1. Добавить сотрудника" << endl;
    cout << "2. Показать всех" << endl;
    cout << "3. Поиск по фамилии" << endl;
    cout << "4. Поиск по возрасту" << endl;
    cout << "5. Поиск по первой букве фамилии" << endl;
    cout << "6. Сохранить данные" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите: ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== ИНФОРМАЦИОННАЯ СИСТЕМА 'СОТРУДНИКИ' ===" << endl;

    loadFromFile();

    bool running = true;
    while (running) {
        showMenu();

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: addEmployee(); break;
        case 2: printAll(); break;
        case 3: searchByLastName(); break;
        case 4: searchByAge(); break;
        case 5: searchByFirstLetter(); break;
        case 6: saveToFile(); break;
        case 0:
            saveToFile();
            cout << "До свидания!" << endl;
            running = false;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    }

    return 0;
}