// Условные операторы и ввод данных.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // 1. Полная форма (if...else)
    cout << "=== Пример 1: Полная форма if...else ===" << endl;
    int x;
    cout << "Введите число: ";
    cin >> x;

    if (x > 0) {
        cout << "Число положительное" << endl;
    }
    else {
        cout << "Число не положительное" << endl;
    }

    cout << endl;

    // 2. Неполная форма (if)
    cout << "=== Пример 2: Неполная форма if ===" << endl;
    double temperature;
    cout << "Введите температуру: ";
    cin >> temperature;

    if (temperature < 0) {
        cout << "Лёд" << endl;
    }
    else {
        cout << "Температура выше или равна 0" << endl;
    }

    cout << endl;

    // 3. Каскадная форма (if...else if...else)
    cout << "=== Пример 3: Каскадная форма if...else if...else ===" << endl;
    int score;
    char grade;

    cout << "Введите баллы (0-100): ";
    cin >> score;

    if (score >= 90) {
        grade = 'A';
    }
    else if (score >= 75) {
        grade = 'B';
    }
    else if (score >= 60) {
        grade = 'C';
    }
    else if (score >= 40) {
        grade = 'D';
    }
    else {
        grade = 'F';
    }

    cout << "Оценка: " << grade << endl;

    cout << endl;

    // 4. Оператор выбора (switch) для дискретных значений
    cout << "=== Пример 4: Оператор switch ===" << endl;
    int dayOfWeek;
    cout << "Введите номер дня недели (1-7): ";
    cin >> dayOfWeek;

    switch (dayOfWeek) {
    case 1:
        cout << "Понедельник" << endl;
        break;
    case 2:
        cout << "Вторник" << endl;
        break;
    case 3:
        cout << "Среда" << endl;
        break;
    case 4:
        cout << "Четверг" << endl;
        break;
    case 5:
        cout << "Пятница" << endl;
        break;
    case 6:
        cout << "Суббота" << endl;
        break;
    case 7:
        cout << "Воскресенье" << endl;
        break;
    default:
        cout << "Неверный день" << endl;
        break;
    }

    // Дополнительный пример с enum для switch
    cout << endl << "=== Дополнительный пример switch с enum ===" << endl;
    enum Color { RED = 1, GREEN, BLUE };
    int colorChoice;
    cout << "Выберите цвет (1-Красный, 2-Зеленый, 3-Синий): ";
    cin >> colorChoice;

    switch (colorChoice) {
    case RED:
        cout << "Выбран красный цвет" << endl;
        break;
    case GREEN:
        cout << "Выбран зеленый цвет" << endl;
        break;
    case BLUE:
        cout << "Выбран синий цвет" << endl;
        break;
    default:
        cout << "Неизвестный цвет" << endl;
    }

    return 0;
}