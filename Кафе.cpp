#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Структура для хранения информации о заказе
struct Order {
    string name; // Название напитка или кондитерского изделия
    int quantity; // Количество
    double price; // Цена за единицу
};

// Меню с товарами и их ценами
vector<Order> menu = {
    {"Чай", 1, 50.0},
    {"Кофе", 1, 70.0},
    {"Пирожное", 1, 80.0}
};

// Функция для вывода меню с цифрами
void printMenu() {
    cout << "Меню:" << endl;
    for (int i = 0; i < menu.size(); ++i) {
        cout << i + 1 << ". " << menu[i].name << " - " << menu[i].price << " рублей" << endl;
    }
}

// Функция для обработки заказа
void processOrder(int num_people) {
    printMenu();
    // Спрашиваем у пользователя, на сколько человек заказ
    cout << "Введите количество человек: ";
    cin >> num_people;

    vector<Order> allOrders; // Храним все заказы

    for (int i = 0; i < num_people; ++i) {
        cout << "\nЗаказ " << i + 1 << endl;

        while (true) {
            cout << "Выберите напиток или кондитерское изделие (введите цифру, 'n' для завершения заказа): ";
            string choice;
            cin >> choice;

            if (choice == "n") {
                // Если клиент хочет завершить заказ, переходим к следующему
                break;
            }
            else {
                int itemIndex = stoi(choice) - 1; // Преобразуем строку в число и корректируем индекс (начинается с 0)
                if (itemIndex >= 0 && itemIndex < menu.size()) {
                    double quantity = 0.0;
                    cout << "Сколько желаете заказать? " << menu[itemIndex].name << ": ";
                    cin >> quantity;

                    // Добавляем заказ в список всех заказов
                    allOrders.push_back({ menu[itemIndex].name, static_cast<int>(quantity), menu[itemIndex].price });
                }
                else {
                    cout << "Некорректный выбор. Попробуйте снова." << endl;
                }
            }
        }
    }

    // Рассчитываем итоговую сумму заказа
    double total_sum = 0.0;
    for (const auto& order : allOrders) {
        total_sum += order.quantity * order.price;
    }

    // Выводим итоговую сумму
    cout << "\nИтоговая сумма заказа: " << total_sum << " рублей." << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    processOrder(0);
    return 0;
}