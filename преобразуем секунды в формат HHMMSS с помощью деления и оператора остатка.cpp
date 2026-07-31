#include <iostream>;
#include <cstdlib>;
#include <windows.h>;
using namespace std;

int main()

#include <iostream>

    using namespace std;

    int main() {
        // объявляем переменные
        int time = 0;
        int hour = 0;
        int min = 0;
        int sec = 0;

        // получаем данные от пользователя
        cout << "Enter a time in seconds: ";
        cin >> time;

        // преобразуем секунды в формат HH:MM:SS с помощью деления и оператора остатка
        hour = time / 3600;
        time = time % 3600;
        min = time / 60;
        time = time % 60;
        sec = time;

        // выводим данные на экран
        cout << "\nThe time in HH:MM:SS format is: " << hour << " hours, " << min << " minutes, and " << sec << " seconds!\n";
        return 0;
    }

