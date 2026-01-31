#include <iostream>
#include <iomanip>
#include <limits>  // для numeric_limits

using namespace std;

// Максимальный размер матрицы для статического массива
const int MAX_SIZE = 20;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;

    cout << "ЗАДАНИЕ 2.2: Сумма элементов под главной диагональю" << endl;
    cout << "*****************************************************" << endl;

    // 1. Ввод размера матрицы с проверкой
    while (true) {
        cout << "Введите размер квадратной матрицы (n, от 1 до " << MAX_SIZE << "): ";
        cin >> n;

        if (cin.fail()) {
            cout << "Ошибка: введите целое число!" << endl;
            cin.clear(); // сброс флагов ошибок
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера
            continue;
        }

        if (n <= 0 || n > MAX_SIZE) {
            cout << "Ошибка: размер должен быть от 1 до " << MAX_SIZE << "!" << endl;
        }
        else {
            break;
        }
    }

    // 2. Объявление статического массива
    int a[MAX_SIZE][MAX_SIZE];

    // 3. Ввод элементов матрицы с проверкой
    cout << "\nВведите элементы матрицы " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Строка " << (i + 1) << " (через пробел " << n << " чисел): ";

        for (int j = 0; j < n; j++) {
            while (true) {
                cin >> a[i][j];

                if (cin.fail()) {
                    cout << "Ошибка: введите целое число для a[" << i << "][" << j << "]: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                break;
            }
        }
    }

    // 4. Вывод исходной матрицы
    cout << "\nИсходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << a[i][j] << " ";
        }
        cout << endl;
    }

    // 5. Подсчет суммы элементов под главной диагональю
    int sum = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            sum += a[i][j];
        }
    }

    // 6. Вывод результата
    cout << "\nЭлементы под главной диагональю:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                cout << setw(5) << a[i][j] << " ";
            }
            else {
                cout << "      ";
            }
        }
        cout << endl;
    }

    cout << "\nСумма элементов под главной диагональю: " << sum << endl;

    return 0;
}