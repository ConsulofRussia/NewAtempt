// Задание 2 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 8;
    int arr[SIZE] = { 10, 20, 30, 40, 50, 60, 70, 80 };

    int* ptr = arr;

    std::cout << "Исходный массив:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << "\n\n";

    std::cout << "Метод 1: Использование двух указателей (начало и конец)\n";

    int arr1[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = arr[i];
    }

    int* start = arr1;
    int* end = arr1 + SIZE - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp; 

        start++;
        end--;
    }

    std::cout << "Массив после реверса: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << *(arr1 + i) << " ";
    }
    std::cout << "\n\n";

    std::cout << "Метод 2: Использование одного указателя с индексацией\n";

    int arr2[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr2[i] = arr[i];
    }

    int* p = arr2; 

    for (int i = 0; i < SIZE / 2; i++) {
        int* left = p + i;
        int* right = p + (SIZE - 1 - i);

        int temp = *left;
        *left = *right;
        *right = temp;
    }

    std::cout << "Массив после реверса: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << *(p + i) << " ";
    }
    std::cout << "\n\n";

    std::cout << "Метод 3: Реверс исходного массива на месте (in-place)\n";

    std::cout << "До реверса: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    int* front = arr;
    int* back = arr + SIZE - 1;
    int* middle = arr + (SIZE / 2);

    std::cout << "Адреса указателей:\n";
    std::cout << "front: " << front << " (значение: " << *front << ")\n";
    std::cout << "back:  " << back << " (значение: " << *back << ")\n";
    std::cout << "middle: " << middle << " (середина массива)\n\n";

    int count = 0;
    for (int* left = arr, *right = arr + SIZE - 1; left < right; left++, right--) {
        int temp = *left;
        *left = *right;
        *right = temp;
        count++;
    }

    std::cout << "После реверса: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Выполнено " << count << " обменов\n\n";

    std::cout << "Дополнительный пример: реверс массива символов\n";

    char str[] = "Hello, World!";
    int strLength = 0;

    char* strPtr = str;
    while (*strPtr != '\0') {
        strLength++;
        strPtr++;
    }

    std::cout << "Исходная строка: " << str << "\n";
    std::cout << "Длина строки: " << strLength << "\n";

    char* strStart = str;
    char* strEnd = str + strLength - 1;

    while (strStart < strEnd) {
        char temp = *strStart;
        *strStart = *strEnd;
        *strEnd = temp;

        strStart++;
        strEnd--;
    }

    std::cout << "Строка после реверса: " << str << "\n";

    return 0;
}