// Задание 2 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

int* createArray(int size) {
    return new int[size];
}
void inputArray(int* arr, int size) {
    std::cout << "Введите " << size << " чисел: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void printArray(int* arr, int size) {
    std::cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool isSimple(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int* removeSimpleNumbers(int* arr, int& size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!isSimple(arr[i])) {
            count++;
        }
    }

    if (count == 0) {
        delete[] arr;
        size = 0;
        return nullptr;
    }

    int* newArr = new int[count];

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (!isSimple(arr[i])) {
            newArr[j] = arr[i];
            j++;
        }
    }

    delete[] arr;

    size = count;

    return newArr;
}

int main() {
    int n;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    int* arr = createArray(n);

    inputArray(arr, n);

    std::cout << "\nИсходный ";
    printArray(arr, n);

    arr = removeSimpleNumbers(arr, n);

    std::cout << "После удаления простых чисел ";
    if (arr != nullptr) {
        printArray(arr, n);
    }
    else {
        std::cout << "массив пуст\n";
    }

    if (arr != nullptr) {
        delete[] arr;
    }

    return 0;
}