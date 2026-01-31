#include <iostream>
using namespace std;

int main() {
    // Арифметические операторы
    int a = 10, b = 3;
    int sum = a + b;      
    int diff = a - b;     
    int prod = a * b;     
    int quot = a / b;     // целочисленное деление
    int rem = a % b;      // остаток от деления

    // Операторы инкремента и декремента
    int x = 5;
    int y = ++x;  // префиксный
    int z = x++;  // постфиксный

    // Операторы отношения и логические
    bool isEqual = (a == 10);           
    bool isGreater = (b > 5);           
    bool inRange = (a >= 1 && a <= 10); 

    // Операторы присваивания
    int total = 0;
    total += a;  
    total *= 2;  

    // Тернарный условный оператор
    int max = (a > b) ? a : b;  

    return 0;
}