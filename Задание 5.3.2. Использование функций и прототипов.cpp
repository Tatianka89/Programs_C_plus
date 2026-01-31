// Задание 5.3.2. Использование функций и прототипов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;


// Прототип функций (по заданию 3.2)


// Ввод матрицы с клавиатуры
void inputMatrix(int** matrix, int rows, int cols);

// Поиск и обнуление максимального элемента
int findAndZeroMaxElement(int** matrix, int rows, int cols);

// Вывод матрицы на экран
void printMatrix(int** matrix, int rows, int cols, const string& title);

// Освобождение памяти матрицы
void freeMatrix(int** matrix, int rows);


// ГЛАВНАЯ ФУНКЦИЯ

int main() {
    setlocale(LC_ALL, "Russian");

    int n, m;

    cout << "Задание 3.2: Поиск и обнуление максимального элемента матрицы" << endl;
    cout << "**************************************************************" << endl;
    cout << "Введите количество строк (n): ";
    cin >> n;
    cout << "Введите количество столбцов (m): ";
    cin >> m;

    if (n <= 0 || m <= 0) {
        cout << "Ошибка: размеры матрицы должны быть положительными!" << endl;
        return 1;
    }

    // Динамическое создание матрицы
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    // Вызов функций для обработки матрицы
    inputMatrix(a, n, m);
    printMatrix(a, n, m, "Исходная матрица:");

    int maxValue = findAndZeroMaxElement(a, n, m);
    cout << "\nМаксимальный элемент матрицы: " << maxValue << endl;

    printMatrix(a, n, m, "Преобразованная матрица (максимальный элемент обнулен):");

    // Освобождение памяти
    freeMatrix(a, n);

    return 0;
}


// Определения функций


// Функция ввода матрицы
void inputMatrix(int** matrix, int rows, int cols) {
    cout << "\nВведите элементы матрицы " << rows << "x" << cols << ":" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Строка " << (i + 1) << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Функция поиска и обнуления максимального элемента
int findAndZeroMaxElement(int** matrix, int rows, int cols) {
    int maxVal = matrix[0][0];
    int maxRow = 0, maxCol = 0;

    // Поиск максимального элемента
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // Обнуление максимального элемента
    matrix[maxRow][maxCol] = 0;

    return maxVal;
}

// Функция вывода матрицы
void printMatrix(int** matrix, int rows, int cols, const string& title) {
    cout << "\n" << title << endl;
    cout << string(cols * 8 + 1, '-') << endl;

    for (int i = 0; i < rows; i++) {
        cout << "|";
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j] << " |";
        }
        cout << endl;
        cout << string(cols * 8 + 1, '-') << endl;
    }
}

// Функция освобождения памяти матрицы
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}