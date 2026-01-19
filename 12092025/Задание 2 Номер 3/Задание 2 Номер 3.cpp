// Задание 2 Номер 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 7;
    int source[SIZE] = { 10, 20, 30, 40, 50, 60, 70 };
    int destination[SIZE];

    int* srcStart = source;
    int* srcEnd = source + SIZE - 1;
    int* dstStart = destination;

    std::cout << "Исходный массив: ";
    int* ptr = source;
    while (ptr < source + SIZE) {
        std::cout << *ptr << " ";
        ptr++;
    }
    std::cout << std::endl;

    int* srcCurrent = srcEnd;
    int* dstCurrent = dstStart;

    while (srcCurrent >= srcStart) {
        *dstCurrent = *srcCurrent; 
        srcCurrent--; 
        dstCurrent++; 
    }

    std::cout << "Скопированный в обратном порядке: ";
    ptr = destination;
    while (ptr < destination + SIZE) {
        std::cout << *ptr << " ";
        ptr++;
    }
    std::cout << std::endl;

    return 0;
}