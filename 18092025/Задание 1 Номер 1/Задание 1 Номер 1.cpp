// Задание 1 Номер 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int M, N;

    std::cout << "Введите размер массива A (M): ";
    std::cin >> M;

    std::cout << "Введите размер массива B (N): ";
    std::cin >> N;

    if (M <= 0 || N <= 0) {
        std::cout << "Размеры массивов должны быть положительными числами!" << std::endl;
        return 1;
    }

    int* A = new int[M];
    int* B = new int[N];

    std::cout << "\nВведите элементы массива A (" << M << " элементов):" << std::endl;
    for (int i = 0; i < M; i++) {
        std::cout << "A[" << i << "] = ";
        std::cin >> A[i];
    }

    std::cout << "\nВведите элементы массива B (" << N << " элементов):" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << "B[" << i << "] = ";
        std::cin >> B[i];
    }

    int* tempResult = new int[M];
    int resultSize = 0;

    for (int i = 0; i < M; i++) {
        bool foundInB = false;

        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                foundInB = true;
                break;
            }
        }

        if (!foundInB) {
            bool alreadyInResult = false;

            for (int k = 0; k < resultSize; k++) {
                if (tempResult[k] == A[i]) {
                    alreadyInResult = true;
                    break;
                }
            }

            if (!alreadyInResult) {
                tempResult[resultSize] = A[i];
                resultSize++;
            }
        }
    }

    int* C = new int[resultSize];

    for (int i = 0; i < resultSize; i++) {
        C[i] = tempResult[i];
    }

    std::cout << "\n=== Результаты ===" << std::endl;

    std::cout << "Массив A: ";
    for (int i = 0; i < M; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив B: ";
    for (int i = 0; i < N; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив C (элементы из A, которых нет в B, без повторений):" << std::endl;
    if (resultSize > 0) {
        std::cout << "Размер массива C: " << resultSize << std::endl;
        std::cout << "Элементы: ";
        for (int i = 0; i < resultSize; i++) {
            std::cout << C[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Массив C пуст! (все элементы из A есть в B)" << std::endl;
    }

    delete[] A;
    delete[] B;
    delete[] tempResult;
    delete[] C;

    return 0;
}