// Задание 2 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//1 Условие
//int* allocateMemory(int size) {
//int* arr = new int[size];
//return arr;
//}

//2 Условие
//void initializeArray(int* arr, int size, int defaultValue = 0) {

    //for (int i = 0; i < size; i++) {
        //arr[i] = defaultValue;
    //}
//}

//void inputArray(int* arr, int size) {
    //std::cout << "Введите " << size << " элементов массива:\n";
    //for (int i = 0; i < size; i++) {
        //std::cout << "arr[" << i << "] = ";
        //std::cin >> arr[i];
    //}
//}

//3 Условие
// void printArray(int* arr, int size) {
//if (arr == nullptr) {
    //std::cout << "Массив не существует!\n";
    //return;
//}

//std::cout << "Массив [" << size << "]: ";
//for (int i = 0; i < size; i++) {
    //std::cout << arr[i] << " ";
//}
//std::cout << std::endl;
//}

//4 Условие
// void deleteArray(int*& arr) {

//delete[] arr;

//arr = nullptr;
//}

//5 Условие
//int* addToEnd(int* arr, int& size, int value) {
//int* newArr = new int[size + 1];

//for (int i = 0; i < size; i++) {
    //newArr[i] = arr[i];
//}

//newArr[size] = value;
//size++;
//delete[] arr;
//return newArr;
//}

//6 Условие
//int* insertAtIndex(int* arr, int& size, int index, int value) {
//if (index < 0 || index > size) {
    //std::cout << "Неверный индекс!\n";
    //return arr;
//}

//int* newArr = new int[size + 1];

//for (int i = 0; i < index; i++) {
    //newArr[i] = arr[i];
//}

//newArr[index] = value;

//for (int i = index; i < size; i++) {
    //newArr[i + 1] = arr[i];
//}

//size++;

//delete[] arr;

//return newArr;
//}

//7
//int* removeAtIndex(int* arr, int& size, int index) {
    //if (index < 0 || index >= size) {
        //std::cout << "Неверный индекс!\n";
        //return arr;
    //}

    //if (size == 1) {
        //delete[] arr;
        //size = 0;
        //return nullptr;
    //}

    //int* newArr = new int[size - 1];

    //for (int i = 0; i < index; i++) {
        //newArr[i] = arr[i];
    //}

    //for (int i = index + 1; i < size; i++) {
        //newArr[i - 1] = arr[i];
    //}

    //size--;

    //delete[] arr;

    //return newArr;
//}

#include <iostream>
#include <Windows.h>
int* allocateMemory(int size) {
    return new int[size];
}

void initializeArray(int* arr, int size, int defaultValue = 0) {
    for (int i = 0; i < size; i++) {
        arr[i] = defaultValue;
    }
}

void printArray(int* arr, int size) {
    if (arr == nullptr) {
        std::cout << "Массив не существует!\n";
        return;
    }

    std::cout << "Массив [" << size << "]: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void deleteArray(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

int* addToEnd(int* arr, int& size, int value) {
    int* newArr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    newArr[size] = value;
    size++;

    delete[] arr;
    return newArr;
}

int* insertAtIndex(int* arr, int& size, int index, int value) {
    if (index < 0 || index > size) {
        std::cout << "Неверный индекс!\n";
        return arr;
    }

    int* newArr = new int[size + 1];

    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }

    newArr[index] = value;

    for (int i = index; i < size; i++) {
        newArr[i + 1] = arr[i];
    }

    size++;
    delete[] arr;
    return newArr;
}

int* removeAtIndex(int* arr, int& size, int index) {

    if (arr == nullptr) {
        std::cout << "Массив не существует!\n";
        return nullptr;
    }

    if (index < 0 || index >= size) {
        std::cout << "Неверный индекс!\n";
        return arr;
    }
    if (size == 1) {
        delete[] arr;
        size = 0;
        return nullptr;
    }

    int* newArr = new int[size - 1];

    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }
    size--;
    delete[] arr;

    return newArr;
}

int main() {
    int size = 5;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "=== 1. Выделение памяти ===\n";
    int* myArray = allocateMemory(size);

    std::cout << "=== 2. Инициализация массива ===\n";
    initializeArray(myArray, size, 10);
    printArray(myArray, size);

    std::cout << "=== 3. Добавление элемента в конец ===\n";
    myArray = addToEnd(myArray, size, 99);
    printArray(myArray, size);

    std::cout << "=== 4. Вставка элемента по индексу 2 ===\n";
    myArray = insertAtIndex(myArray, size, 2, 777);
    printArray(myArray, size);

    std::cout << "=== 5. Удаление элемента по индексу 3 ===\n";
    myArray = removeAtIndex(myArray, size, 3);
    printArray(myArray, size);

    std::cout << "=== 6. Попытка удаления с неверным индексом ===\n";
    myArray = removeAtIndex(myArray, size, 100);
    printArray(myArray, size);

    std::cout << "=== 7. Освобождение памяти ===\n";
    deleteArray(myArray);

    std::cout << "=== 8. Попытка печати после удаления ===\n";
    printArray(myArray, size);

    return 0;
}