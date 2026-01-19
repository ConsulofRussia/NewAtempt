// 2 Задание Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 10;
    int source[SIZE] = { 1, 9, 7, 5, 3 };
    int destination[SIZE];

    int* srcPtr = source;
    int* dstPtr = destination;

    std::cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << source[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++) {
        *(dstPtr + i) = *(srcPtr + i);
    }

    std::cout << "Скопированный массив: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << destination[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\nАльтернативный способ (с перемещением указателей):\n";

    srcPtr = source;
    dstPtr = destination;

    int* endPtr = source + SIZE;

    while (srcPtr < endPtr) {
        *dstPtr = *srcPtr;
        srcPtr++;
        dstPtr++;
    }

    std::cout << "Результат после альтернативного копирования: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << destination[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}