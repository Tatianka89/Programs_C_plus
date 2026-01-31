// 2.1Процедуры в C++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// Синтаксис:
// void ИмяПроцедуры( [Параметры] ) {
//     // Тело процедуры (операторы)
// }

// Пример процедуры для вывода заголовка отчета
static void printReportHeader() {
    std::cout << "============================\n";
    std::cout << "      ОТЧЕТ ПО РАСЧЕТАМ\n";
    std::cout << "============================\n";
    std::cout << "Дата: " << getCurrentDate() << std::endl;
}

// Пример процедуры с параметрами
void drawRectangle(int width, int height, char symbol) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << symbol;
        }
        std::cout << std::endl;
    }
}