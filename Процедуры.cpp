#include <iostream>
using namespace std;

int main() {
    // Арифметические операторы
    int a = 10, b = 3;
    int sum = a + b;      // 13
    int diff = a - b;     // 7
    int prod = a * b;     // 30
    int quot = a / b;     // 3 (целочисленное деление)
    int rem = a % b;      // 1 (остаток от деления)

    // Операторы инкремента и декремента
    int x = 5;
    int y = ++x;  // x=6, y=6 (префиксный)
    int z = x++;  // z=6, x=7 (постфиксный)

    // Операторы отношения и логические
    bool isEqual = (a == 10);           // true
    bool isGreater = (b > 5);           // false
    bool inRange = (a >= 1 && a <= 10); // true

    // Операторы присваивания
    int total = 0;
    total += a;  // total = total + a
    total *= 2;  // total = total * 2

    // Тернарный условный оператор
    int max = (a > b) ? a : b;  // max = 10

    return 0;
}