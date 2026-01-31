#include <iostream>
#include <cmath>  // Для математических функций
using namespace std;

// Процедура для расчета площади круга
void calculateCircleArea(double radius) {
    const double PI = 3.141592653589793;
    double area = PI * pow(radius, 2);
    cout << "Площадь круга с радиусом " << radius
        << " = " << area << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Объявление и инициализация переменных
    int choice = 0;
    double value = 0.0;

    cout << "Калькулятор геометрических фигур" << endl;
    cout << "================================" << endl;
    cout << "Введите радиус круга: ";
    cin >> value;

    // Проверка корректности ввода
    if (value <= 0) {
        cout << "Ошибка: радиус должен быть положительным!" << endl;
        return 1;  // Завершение с ошибкой
    }

    // Вызов процедуры
    calculateCircleArea(value);

    // Использование различных операторов
    double diameter = 2 * value;       // Оператор умножения
    bool isLarge = (value > 10);       // Оператор сравнения

    if (isLarge) {
        cout << "Это большой круг!" << endl;
    }
    else {
        cout << "Это маленький или средний круг." << endl;
    }

    return 0;
}