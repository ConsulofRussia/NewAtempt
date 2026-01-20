// Задание 2 Номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

void separateArray(int* staticArr, int size,
    int*& posArr, int& posSize,
    int*& negArr, int& negSize,
    int*& zeroArr, int& zeroSize) {

    posSize = 0;
    negSize = 0;
    zeroSize = 0;

    for (int i = 0; i < size; i++) {
        if (staticArr[i] > 0) {
            posSize++;
        }
        else if (staticArr[i] < 0) {
            negSize++;
        }
        else {
            zeroSize++;
        }
    }

    if (posSize > 0) {
        posArr = new int[posSize];
    }
    if (negSize > 0) {
        negArr = new int[negSize];
    }
    if (zeroSize > 0) {
        zeroArr = new int[zeroSize];
    }

    int posIndex = 0, negIndex = 0, zeroIndex = 0;

    for (int i = 0; i < size; i++) {
        if (staticArr[i] > 0) {
            posArr[posIndex] = staticArr[i];
            posIndex++;
        }
        else if (staticArr[i] < 0) {
            negArr[negIndex] = staticArr[i];
            negIndex++;
        }
        else {
            zeroArr[zeroIndex] = staticArr[i];
            zeroIndex++;
        }
    }
}

void printArray(int* arr, int size, const char* name) {
    std::cout << name << " [" << size << "]: ";
    if (arr == nullptr) {
        std::cout << "пусто";
    }
    else {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int SIZE = 10;
    int staticArr[SIZE] = { 5, -3, 0, 8, -1, 4, -7, 2, 9, -4 };

    int* posArr = nullptr;
    int* negArr = nullptr;
    int* zeroArr = nullptr;

    int posSize = 0, negSize = 0, zeroSize = 0;

    std::cout << "Исходный статический массив: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << staticArr[i] << " ";
    }
    std::cout << std::endl;

    separateArray(staticArr, SIZE, posArr, posSize,
        negArr, negSize, zeroArr, zeroSize);

    std::cout << "\nРезультаты распределения:\n";
    printArray(posArr, posSize, "Положительные");
    printArray(negArr, negSize, "Отрицательные");
    printArray(zeroArr, zeroSize, "Нулевые");

    if (posArr != nullptr) delete[] posArr;
    if (negArr != nullptr) delete[] negArr;
    if (zeroArr != nullptr) delete[] zeroArr;

    return 0;
}