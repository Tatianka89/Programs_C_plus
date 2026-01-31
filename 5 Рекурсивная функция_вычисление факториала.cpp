// 5 Рекурсивная функция_вычисление факториала.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}

unsigned long long factorialIterative(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Вычисление факториала:" << endl;
    cout << "***********************" << endl;

    for (int i = 0; i <= 10; i++) {
        cout << i << "! = " << factorial(i) << " (рекурсивно)" << endl;
        cout << "  = " << factorialIterative(i) << " (итеративно)" << endl;
    }

    
    cout << "\nПроверка 10!:" << endl;
    cout << "Рекурсивно: " << factorial(10) << endl;
    cout << "Итеративно: " << factorialIterative(10) << endl;

    return 0;
}