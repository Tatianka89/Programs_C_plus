#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <thread>

// Исправленная функция форматирования времени
void printDuration(std::chrono::milliseconds ms) {
    using namespace std::chrono;

    // Используем явные типы вместо auto
    auto hours_count = duration_cast<hours>(ms).count();
    ms -= std::chrono::milliseconds(std::chrono::hours(hours_count));

    auto minutes_count = duration_cast<minutes>(ms).count();
    ms -= std::chrono::milliseconds(std::chrono::minutes(minutes_count));

    auto seconds_count = duration_cast<seconds>(ms).count();
    ms -= std::chrono::milliseconds(std::chrono::seconds(seconds_count));

    auto milliseconds_count = ms.count();

    std::cout << std::setfill('0')
        << std::setw(2) << hours_count << ":"
        << std::setw(2) << minutes_count << ":"
        << std::setw(2) << seconds_count << "."
        << std::setw(3) << milliseconds_count;
}

// Или альтернативный, более простой вариант:
void printDuration2(std::chrono::milliseconds ms) {
    using namespace std::chrono;

    // Более простой подход через целочисленные вычисления
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

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "=== Простой пример ===\n\n";

    // 1. string
    std::string text = "Hello C++";
    std::cout << "1. Строка: " << text << "\n";
    std::cout << "   Длина: " << text.length() << "\n\n";

    // 2. chrono - измерение времени
    std::cout << "2. Измерение времени:\n";

    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "   Время сна: ";
    printDuration(duration);
    std::cout << " (чч:мм:сс.мсс)\n\n";

    // 3. iomanip - форматирование чисел
    std::cout << "3. Форматирование чисел:\n";

    double numbers[] = { 123.456789, 9876.54321, 3.14159 };

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < 3; i++) {
        std::cout << "   Число " << (i + 1) << ": "
            << std::setw(10) << numbers[i] << "\n";
    }

    std::cout << "\n   В научной нотации:\n";
    std::cout << std::scientific << std::setprecision(3);
    for (int i = 0; i < 3; i++) {
        std::cout << "   Число " << (i + 1) << ": " << numbers[i] << "\n";
    }

    return 0;
}