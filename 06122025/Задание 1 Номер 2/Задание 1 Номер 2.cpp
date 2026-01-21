// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct Car {
    string brand;     
    string model;       
    double length;    
    double clearance;     
    double engineVolume; 
    int enginePower;      
    double wheelDiameter; 
    string color;         
    string transmission;  
};

void showCar(Car car) {
    cout << "\nМарка: " << car.brand;
    cout << "\nМодель: " << car.model;
    cout << "\nДлина: " << car.length << " м";
    cout << "\nКлиренс: " << car.clearance << " мм";
    cout << "\nОбъем двигателя: " << car.engineVolume << " л";
    cout << "\nМощность: " << car.enginePower << " л.с.";
    cout << "\nДиаметр колес: " << car.wheelDiameter << " дюймов";
    cout << "\nЦвет: " << car.color;
    cout << "\nКоробка передач: " << car.transmission;
    cout << endl;
}

void findCarByBrand(Car cars[], int count, string brand) {
    cout << "\nПоиск автомобилей марки '" << brand << "':" << endl;
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (cars[i].brand == brand) {
            showCar(cars[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Не найдено!" << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== УПРАВЛЕНИЕ АВТОМОБИЛЯМИ ===" << endl;

    Car garage[3];

    garage[0] = { "Toyota", "Camry", 4.88, 155, 2.5, 181, 17, "Черный", "Автоматическая" };
    garage[1] = { "Lada", "Vesta", 4.41, 178, 1.6, 106, 16, "Белый", "Механическая" };
    garage[2] = { "BMW", "X5", 4.92, 210, 3.0, 249, 20, "Синий", "Автоматическая" };

    cout << "\n=== ВСЕ АВТОМОБИЛИ В ГАРАЖЕ ===" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nАвтомобиль #" << i + 1 << ":";
        showCar(garage[i]);
    }

    findCarByBrand(garage, 3, "Toyota");
    findCarByBrand(garage, 3, "Lada");

    return 0;
}