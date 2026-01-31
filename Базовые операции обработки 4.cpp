#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 7; // Размер массива
    double data[N];  // Объявление массива

    // 1. Ввод данных в массив
    cout << "Введите " << N << " значений: ";
    for (int i = 0; i < N; ++i) {
        cin >> data[i];
    }

    // 2. Вывод (перебор) массива
    cout << "\nМассив data: ";
    for (int i = 0; i < N; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    // 3. вычисление суммы и среднего арифметического
    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        sum += data[i]; // Накопление суммы
    }
    double average = sum / N;
    cout << "Сумма: " << sum << ", Среднее: " << average << endl;

    // 4. поиск максимального элемента [citation:4]
    double maxElement = data[0]; // Предположим, максимальный
    int maxIndex = 0;
    for (int i = 1; i < N; ++i) { // Начинаем сравнение со второго элемента
        if (data[i] > maxElement) {
            maxElement = data[i];
            maxIndex = i;
        }
    }
    cout << "Максимум: data[" << maxIndex << "] = " << maxElement << endl;

    // 5. создание нового массива на основе существующего [citation:4]
    double squaredData[N]; // Новый массив для квадратов
    for (int i = 0; i < N; ++i) {
        squaredData[i] = pow(data[i], 2); // Возведение в квадрат
    }

    // 6. обрпаботка двумерного массива (матрицы 3*3)
    int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int mainDiagSum = 0;

    cout << "\nМатрица 3x3:\n";
    for (int i = 0; i < 3; ++i) {        // Цикл по строкам
        for (int j = 0; j < 3; ++j) {    // Цикл по столбцам
            cout << matrix[i][j] << "\t";
            if (i == j) { // Элемент на главной диагонали
                mainDiagSum += matrix[i][j];
            }
        }
        cout << endl;
    }
    cout << "Сумма главной диагонали: " << mainDiagSum << endl;

    return 0;
}