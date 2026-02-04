#include <iostream>
#include "scarypookie.h"
#include "Windows.h"
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Complex a(3, 4);
    Complex b;

    std::cout << "Введите комплексное число, типо (2 2): ";
    std::cin >> b;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n\n";

    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";
    std::cout << "a / b = " << (a / b) << "\n";
    std::cout << "|a|   = " << a.getModulus() << "\n";

    if (a == Complex(3, 4)) {
        std::cout << "a == 3 + 4i\n";
    }

    return 0;
}