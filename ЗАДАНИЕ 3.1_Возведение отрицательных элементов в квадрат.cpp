// ЗАДАНИЕ 3.1_Возведение отрицательных элементов в квадрат.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <iomanip>

using namespace std;


// Прототипы функций


// Ввод массива с клавиатуры
void inputArray(int arr[], int size);

// Возведение отрицательных элементов в квадрат
void processNegativeElements(int arr[], int size);

// Вывод массива на экран
void printArray(const int arr[], int size, const string& title);


// Главная функция


int main() {
    setlocale(LC_ALL, "Russian");

    int n;

    cout << "ЗАДАНИЕ 3.1: Возведение отрицательных элементов в квадрат" << endl;
    cout << "************************************************" << endl;
    cout << "Введите размер массива (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Ошибка: размер массива должен быть положительным!" << endl;
        return 1;
    }

    // Объявление массива
    int* a = new int[n];

    // Вызов функций для обработки массива
    inputArray(a, n);
    printArray(a, n, "Исходный массив:");
    processNegativeElements(a, n);
    printArray(a, n, "Преобразованный массив (отрицательные возведены в квадрат):");

    // Освобождение памяти
    delete[] a;

    return 0;
}

// Определения функций


// Функция ввода массива с клавиатуры
void inputArray(int arr[], int size) {
    cout << "\nВведите " << size << " элементов массива:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }
}

// Функция возведения отрицательных элементов в квадрат
void processNegativeElements(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            arr[i] = arr[i] * arr[i]; // Возведение в квадрат
        }
    }
}

// Функция вывода массива
void printArray(const int arr[], int size, const string& title) {
    cout << "\n" << title << endl;
    cout << string(50, '-') << endl;

    for (int i = 0; i < size; i++) {
        cout << setw(6) << "a[" << i << "] = " << setw(6) << arr[i];
        if ((i + 1) % 3 == 0 || i == size - 1) {
            cout << endl;
        }
    }

    cout << string(50, '-') << endl;
}