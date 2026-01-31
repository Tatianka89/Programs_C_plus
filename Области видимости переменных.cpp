#include <iostream>
using namespace std;

// Глобальная переменная (видна во всем файле)
int globalVar = 100;

void exampleFunction() {
    // Локальная переменная функции
    int localVar = 50;

    // Статическая переменная (сохраняет значение между вызовами)
    static int staticVar = 0;
    staticVar++;

    cout << "localVar: " << localVar << endl;
    cout << "staticVar: " << staticVar << endl;
    cout << "globalVar: " << globalVar << endl;

    // Блочная область видимости
    if (true) {
        int blockVar = 999;  // Видна только внутри этого блока
        cout << "blockVar: " << blockVar << endl;
    }
    // cout << blockVar << endl;  // ОШИБКА: blockVar не видна здесь
}

int main() {
    exampleFunction();  // staticVar = 1
    exampleFunction();  // staticVar = 2
    exampleFunction();  // staticVar = 3

    return 0;
}