#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Определение PI 
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    setlocale(LC_ALL, "Russian");

    // 1. Объявление переменных
    double a, b;        // Границы интервала
    int n;              // Количество точек
    double x, y;        // Текущая точка и значение функции
    double sum = 0.0;   // Сумма значений
    double h;           // Шаг между точками

    // 2. Ввод данных
    cout << "Программа расчета таблицы значений функции" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Введите левую границу интервала (a): ";
    cin >> a;
    cout << "Введите правую границу интервала (b): ";
    cin >> b;
    cout << "Введите количество точек (n, n > 1): ";
    cin >> n;

    // 3. Проверка на ошибки
    if (n <= 1) {
        cout << "Ошибка: количество точек должно быть больше 1!" << endl;
        return 1;
    }
    if (a > b) {
        cout << "Ошибка: левая граница должна быть меньше правой!" << endl;
        return 1;
    }

    // 4. Вычисление шага
    h = (b - a) / (n - 1);

    // 5. Заголовок таблицы
    cout << "\nТаблица значений функции:" << endl;
    cout << "Функция: y = cos(4πx)/(1+x²)" << endl;
    cout << "Интервал: a = " << a << ", b = " << b << ", n = " << n << ", шаг = " << h << endl;
    cout << string(50, '-') << endl;
    cout << setw(10) << "x" << setw(20) << "f(x)" << setw(20) << "Дробная часть" << endl;
    cout << fixed << setprecision(6);

    // 6. Цикл расчета
    for (int i = 0; i < n; i++) {
        // 6.1. Вычисление текущего x
        x = a + i * h;

        // 6.2. Вычисление значения функции 
        y = cos(4 * M_PI * x) / (1.0 + x * x);

        // 6.3. Выделение дробной части
        double fractional = y - floor(y);
        if (fractional < 0) fractional += 1.0; 

        // 6.4. Вывод текущей строки таблицы
        cout << setw(10) << x << setw(20) << y << setw(20) << fractional;

        // 6.5. Проверка условия и накопление суммы
        if (fractional > 0.5) {
            sum += y;
            cout << " *"; 
        }
        cout << endl;
    }

    // 7. Вывод: Таблица значений и итоговая сумма
    cout << string(50, '=') << endl;
    cout << "Сумма значений с дробной частью > 0.5: "
        << setprecision(10) << sum << endl;

    return 0;
}