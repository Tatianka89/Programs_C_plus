//Написать программу, которая преобразует введенное с клавиатуры дробное число в денежный формат.
//Например, число 12,5 должно быть преобразовано к виду 12 долларов 50 центов.

#include <iostream>
using namespace std;
int main()
{
	double number, dollar, cent;

	setlocale(LC_ALL, "Russian");

	cout << "Введите денежную единицу" << endl;
	cin >> number;

	dollar = int(number);
	cent = (number - dollar) * 100;

	cout << dollar << " долларов " <<cent << " центов \n";
	return 0;
}
