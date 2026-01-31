#include <iostream>
#include <cstdlib>  // Для rand(), srand()
#include <ctime>    // Для time()
#include <iomanip>  // Для setw()

using namespace std;


// Прототипы функций


// Инициализация массива случайными числами
void initArray(int arr[], int size, int minVal, int maxVal);

// Вывод массива на экран
void printArray(const int arr[], int size, const string& title);

// Нахождение максимального элемента
int findMax(const int arr[], int size);

// Нахождение минимального элемента
int findMin(const int arr[], int size);

// Вычисление среднего арифметического
double calculateAverage(const int arr[], int size);

// Сортировка массива (метод пузырька)
void bubbleSort(int arr[], int size);

// Поиск элемента в массиве (возвращает индекс или -1)
int searchElement(const int arr[], int size, int target);


// Главная функция


int main() {
    setlocale(LC_ALL, "Russian");

    const int SIZE = 10;
    int numbers[SIZE];

    // 1. Инициализация генератора случайных чисел
    srand(time(0));

    // 2. Инициализация массива
    initArray(numbers, SIZE, 1, 100);

    // 3. Вывод исходного массива
    printArray(numbers, SIZE, "Исходный массив:");

    // 4. Вычисление характеристик массива
    cout << "\nХарактеристики массива:" << endl;
    cout << "Максимальный элемент: " << findMax(numbers, SIZE) << endl;
    cout << "Минимальный элемент: " << findMin(numbers, SIZE) << endl;
    cout << "Среднее арифметическое: " << fixed << setprecision(2)
        << calculateAverage(numbers, SIZE) << endl;

    // 5. Поиск элемента
    int target;
    cout << "\nВведите элемент для поиска: ";
    cin >> target;

    int index = searchElement(numbers, SIZE, target);
    if (index != -1) {
        cout << "Элемент найден на позиции " << index << endl;
    }
    else {
        cout << "Элемент не найден" << endl;
    }

    // 6. Сортировка массива
    bubbleSort(numbers, SIZE);
    printArray(numbers, SIZE, "Отсортированный массив:");

    return 0;
}


// Определения функций


void initArray(int arr[], int size, int minVal, int maxVal) {
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

void printArray(const int arr[], int size, const string& title) {
    cout << "\n" << title << endl;
    cout << string(50, '-') << endl;

    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl; // По 10 элементов в строке
    }

    if (size % 10 != 0) cout << endl;
    cout << string(50, '-') << endl;
}

int findMax(const int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findMin(const int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

double calculateAverage(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмен элементов
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int searchElement(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Элемент найден
        }
    }
    return -1; // Элемент не найден
}