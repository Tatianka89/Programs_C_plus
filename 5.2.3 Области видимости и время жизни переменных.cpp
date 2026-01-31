#include <iostream>
using namespace std;

// Глобальные переменные (видимы во всех функциях).
int globalVar = 100;

// Прототипы функций.
int process(int param);
void printInfo();

int main() {
    // Локальные переменные main.
    int localMain = 50;

    // Вызов функции с параметром.
    int result = process(localMain);

    printInfo();

    return 0;
}

// Определение функции process.
int process(int param) { // param - параметр функции.
    // Локальные переменные функции process.
    int localProcess = param * 2;

    // Статическая переменная (сохраняет значение между вызовами).
    static int staticVar = 0;
    staticVar++;

    // Доступ к глобальной переменной.
    return localProcess + globalVar + staticVar;
}

void printInfo() {
    // Доступ к глобальной переменной.
    cout << "Global variable: " << globalVar << endl;

    // Ошибка: нет доступа к локальным переменным других функций.
    // cout << localMain; // Ошибка компиляции!
}