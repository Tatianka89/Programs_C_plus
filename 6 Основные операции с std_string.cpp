// 6 Основные операции с std_string.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string str1 = "Hello";
    string str2 = "World";

    // 1. Конкатенация (соединение строк)
    string result = str1 + " " + str2;  // "Hello World"

    // 2. Доступ к символам
    char first = str1[0];      // 'H'
    char last = str1.at(4);    // 'o' (с проверкой границ)

    // 3. Изменение строк
    str1.append("!!!");        // "Hello!!!"
    str1.insert(5, ", ");      // "Hello, !!!"
    str1.erase(5, 2);          // "Hello!!!"

    // 4. Поиск в строке
    size_t pos = str1.find("lo");  // Позиция = 3
    if (pos != string::npos) {
        cout << "Найдено на позиции: " << pos << endl;
    }

    // 5. Получение подстроки
    string substr = str1.substr(1, 3);  // "ell"

    // 6. Сравнение строк
    if (str1 == str2) {
        cout << "Строки равны" << endl;
    }
    else if (str1 < str2) {
        cout << "str1 меньше str2" << endl;
    }

    // 7. Длина строки
    int length = str1.length();  // или str1.size()

    // 8. Проверка на пустоту
    if (str1.empty()) {
        cout << "Строка пуста" << endl;
    }

    return 0;
}