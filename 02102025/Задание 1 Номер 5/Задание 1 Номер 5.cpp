// Задание 1 Номер 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

bool isHappyTicket(int number) {
    if (number < 100000 || number > 999999) {
        return false;
    }

    int d1 = number / 100000;          
    int d2 = (number / 10000) % 10;   
    int d3 = (number / 1000) % 10;     
    int d4 = (number / 100) % 10;      
    int d5 = (number / 10) % 10;      
    int d6 = number % 10;            

    int sum1 = d1 + d2 + d3;
    int sum2 = d4 + d5 + d6;

    return sum1 == sum2;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int ticket;
    cout << "Введите номер билета (6 цифр): ";
    cin >> ticket;

    if (isHappyTicket(ticket)) {
        cout << "Билет №" << ticket << " - СЧАСТЛИВЫЙ!\n";
    }
    else {
        cout << "Билет №" << ticket << " - обычный\n";
    }

    cout << "\nПримеры:\n";
    cout << "123321 - " << (isHappyTicket(123321) ? "счастливый" : "обычный") << endl;
    cout << "123456 - " << (isHappyTicket(123456) ? "счастливый" : "обычный") << endl;

    return 0;
}