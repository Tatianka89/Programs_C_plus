// 6.Ввод и вывод строк.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Для C-строк
    char cstr[100];
    cout << "Введите C-строку: ";
    cin.getline(cstr, 100);  // Безопасный ввод с ограничением длины

    // Для std::string
    string str;
    cout << "Введите string: ";
    getline(cin, str);  // Безопасный ввод без ограничения длины

    cout << "C-строка: " << cstr << endl;
    cout << "string: " << str << endl;

    return 0;
}