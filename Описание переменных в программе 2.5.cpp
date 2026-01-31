// Примеры объявления переменных
int counter = 0;                // Целочисленная с инициализацией
double temperature;             // Вещественная без инициализации
char grade = 'A';               // Символьная
bool isActive = true;           // Логическая
unsigned int distance = 1500u;  // Беззнаковая целочисленная
float prices[5] = { 10.5, 20.0, 15.75 }; // Массив

// Константные переменные
const double PI = 3.141592653589793;
const int MAX_USERS = 100;

// Указатели
int value = 42;
int* pointer = &value;  // Указатель хранит адрес переменной value

// Ссылки (альтернативное имя переменной)
int original = 100;
int& reference = original;  // reference - псевдоним для original