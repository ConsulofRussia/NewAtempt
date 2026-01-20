// Задание 1 Номер 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

    if (M <= 0 || N <= 0) return 1;

    int* A = new int[M];
    int* B = new int[N];

    std::cout << "Введите элементы массива A:" << std::endl;
    for (int i = 0; i < M; i++) std::cin >> A[i];

    std::cout << "Введите элементы массива B:" << std::endl;
    for (int i = 0; i < N; i++) std::cin >> B[i];

    int sizeC = 0;

    for (int i = 0; i < M; i++) {
        bool inB = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                inB = true;
                break;
            }
        }
        if (!inB) {
            bool dupInA = false;
            for (int k = 0; k < i; k++) {
                if (A[k] == A[i]) {
                    dupInA = true;
                    break;
                }
            }
            if (!dupInA) sizeC++;
        }
    }

    for (int i = 0; i < N; i++) {
        bool inA = false;
        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                inA = true;
                break;
            }
        }
        if (!inA) {
            bool dupInB = false;
            for (int k = 0; k < i; k++) {
                if (B[k] == B[i]) {
                    dupInB = true;
                    break;
                }
            }
            if (!dupInB) sizeC++;
        }
    }

    int* C = new int[sizeC];
    int idx = 0;

    for (int i = 0; i < M; i++) {
        bool inB = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                inB = true;
                break;
            }
        }
        if (!inB) {
            bool dupInC = false;
            for (int k = 0; k < idx; k++) {
                if (C[k] == A[i]) {
                    dupInC = true;
                    break;
                }
            }
            if (!dupInC) C[idx++] = A[i];
        }
    }

    for (int i = 0; i < N; i++) {
        bool inA = false;
        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                inA = true;
                break;
            }
        }
        if (!inA) {
            bool dupInC = false;
            for (int k = 0; k < idx; k++) {
                if (C[k] == B[i]) {
                    dupInC = true;
                    break;
                }
            }
            if (!dupInC) C[idx++] = B[i];
        }
    }

    std::cout << "\nМассив C (не общие элементы без повторений):" << std::endl;
    if (sizeC > 0) {
        for (int i = 0; i < sizeC; i++) std::cout << C[i] << " ";
    }
    else {
        std::cout << "Пуст";
    }

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}