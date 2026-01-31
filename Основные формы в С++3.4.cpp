// 1. Полная форма (if...else)
if (x > 0) {
    cout << "Число положительное" << endl;
}
else {
    cout << "Число не положительное" << endl;
}

// 2. Неполная форма (if)
if (temperature < 0) {
    cout << "Лёд" << endl;
}

// 3. Каскадная форма (if...else if...else)
if (score >= 90) {
    grade = 'A';
}
else if (score >= 75) {
    grade = 'B';
}
else if (score >= 60) {
    grade = 'C';
}
else {
    grade = 'F';
}

// 4. Оператор выбора (switch) для дискретных значений
switch (dayOfWeek) {
case 1: cout << "Понедельник"; break;
case 2: cout << "Вторник"; break;
    // ... другие case
default: cout << "Неверный день"; break;
}