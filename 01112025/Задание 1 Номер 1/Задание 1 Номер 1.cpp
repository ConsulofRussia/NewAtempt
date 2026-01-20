// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

void printFigureA(int size) {
    cout << "\nа) Прямоугольник " << size << "x" << size << ":\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void printFigureB(int size) {
    cout << "\nб) Прямоугольный треугольник:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void printFigureV(int size) {
    cout << "\nв) Перевернутый прямоугольный треугольник:\n";
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void printFigureG(int size) {
    cout << "\nг) Равнобедренный треугольник:\n";
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size - 1; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i * 2; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void printFigureD(int size) {
    cout << "\nд) Ромб:\n";

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size - 1; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i * 2; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = size - 2; i >= 0; i--) {
        for (int j = i; j < size - 1; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i * 2; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void printFigureE(int size) {
    cout << "\nе) Крест:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j || i + j == size - 1) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void printFigureZh(int size) {
    cout << "\nж) Пирамида:\n";
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size - 1; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void printFigureZ(int size) {
    cout << "\nз) Перевернутая пирамида:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        for (int j = i; j < size; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void printFigureI(int size) {
    cout << "\nи) Песочные часы:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        for (int j = i; j < size; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 2; i <= size; i++) {
        for (int j = i; j < size; j++) {
            cout << "  ";
        }
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void printFigureK(int size) {
    cout << "\nк) Контур квадрата:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice, size;

    do {
        cout << "\n=== МЕНЮ ВЫБОРА ФИГУРЫ ===\n";
        cout << "1. Прямоугольник (а)\n";
        cout << "2. Прямоугольный треугольник (б)\n";
        cout << "3. Перевернутый прямоугольный треугольник (в)\n";
        cout << "4. Равнобедренный треугольник (г)\n";
        cout << "5. Ромб (д)\n";
        cout << "6. Крест (е)\n";
        cout << "7. Пирамида (ж)\n";
        cout << "8. Перевернутая пирамида (з)\n";
        cout << "9. Песочные часы (и)\n";
        cout << "10. Контур квадрата (к)\n";
        cout << "0. Выход\n";
        cout << "\nВыберите фигуру (0-10): ";
        cin >> choice;

        if (choice == 0) {
            cout << "Выход из программы.\n";
            break;
        }

        if (choice < 1 || choice > 10) {
            cout << "Неверный выбор! Попробуйте снова.\n";
            continue;
        }

        cout << "Введите размер фигуры (3-20): ";
        cin >> size;

        if (size < 3 || size > 20) {
            cout << "Размер должен быть от 3 до 20. Установлен размер 5.\n";
            size = 5;
        }

        switch (choice) {
        case 1: printFigureA(size); break;
        case 2: printFigureB(size); break;
        case 3: printFigureV(size); break;
        case 4: printFigureG(size); break;
        case 5: printFigureD(size); break;
        case 6: printFigureE(size); break;
        case 7: printFigureZh(size); break;
        case 8: printFigureZ(size); break;
        case 9: printFigureI(size); break;
        case 10: printFigureK(size); break;
        }

        cout << "\nНажмите Enter для продолжения...";
        cin.ignore();
        cin.get();

    } while (choice != 0);

    return 0;
}