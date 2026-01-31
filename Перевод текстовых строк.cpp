#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <thread>
#include <limits>

void printDuration(std::chrono::milliseconds ms) {
    using namespace std::chrono;

    auto total_ms = ms.count();
    auto hours = total_ms / (1000 * 60 * 60);
    total_ms %= (1000 * 60 * 60);
    auto minutes = total_ms / (1000 * 60);
    total_ms %= (1000 * 60);
    auto seconds = total_ms / 1000;
    auto milliseconds = total_ms % 1000;

    std::cout << std::setfill('0')
        << std::setw(2) << hours << ":"
        << std::setw(2) << minutes << ":"
        << std::setw(2) << seconds << "."
        << std::setw(3) << milliseconds;
}

// Функция для очистки буфера ввода
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    // Устанавливаем локаль для поддержки русского языка
    setlocale(LC_ALL, "Russian");

    std::cout << "=== Программа для демонстрации возможностей C++ ===\n\n";

    // 1. Ввод и вывод строки
    std::cout << "1. Работа со строками\n";
    std::cout << "   Введите любую строку: ";

    std::string userText;
    std::getline(std::cin, userText);

    std::cout << "   Вы ввели: " << userText << "\n";
    std::cout << "   Длина строки: " << userText.length() << " символов\n\n";

    // 2. Ввод времени сна и его измерение
    std::cout << "2. Измерение времени\n";
    std::cout << "   Введите время сна в миллисекундах (например, 500): ";

    int sleepTimeMs;
    std::cin >> sleepTimeMs;
    clearInputBuffer(); // Очищаем буфер после ввода числа

    std::cout << "   Засыпаем на " << sleepTimeMs << " мс...\n";

    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeMs));
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "   Фактическое время сна: ";
    printDuration(duration);
    std::cout << " (чч:мм:сс.мсс)\n\n";

    // 3. Ввод чисел для форматирования
    std::cout << "3. Форматирование чисел\n";
    std::cout << "   Введите 3 числа через пробел (например, 123.456789 9876.54321 3.14159): ";

    double numbers[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> numbers[i];
    }
    clearInputBuffer(); // Очищаем буфер после ввода чисел

    std::cout << "\n   Ваши числа в десятичном формате:\n";
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < 3; i++) {
        std::cout << "   Число " << (i + 1) << ": "
            << std::setw(10) << numbers[i] << "\n";
    }

    std::cout << "\n   Ваши числа в научной нотации:\n";
    std::cout << std::scientific << std::setprecision(3);
    for (int i = 0; i < 3; i++) {
        std::cout << "   Число " << (i + 1) << ": " << numbers[i] << "\n";
    }

    // 4. Дополнительно: ввод собственного времени для форматирования
    std::cout << "\n4. Форматирование произвольного времени\n";
    std::cout << "   Введите время в миллисекундах для форматирования (например, 3661123): ";

    long long userTimeMs;
    std::cin >> userTimeMs;
    clearInputBuffer();

    std::chrono::milliseconds userDuration(userTimeMs);
    std::cout << "   Форматированное время: ";
    printDuration(userDuration);
    std::cout << " (чч:мм:сс.мсс)\n";

    // 5. Дополнительно: создание собственной строки с конкатенацией
    std::cout << "\n5. Создание новой строки\n";
    std::cout << "   Введите первую часть строки: ";
    std::string part1;
    std::getline(std::cin, part1);

    std::cout << "   Введите вторую часть строки: ";
    std::string part2;
    std::getline(std::cin, part2);

    std::string combined = part1 + " " + part2;
    std::cout << "   Результат конкатенации: " << combined << "\n";
    std::cout << "   Итоговая длина: " << combined.length() << " символов\n";

    std::cout << "\n=== Программа завершена ===\n";
    return 0;
}