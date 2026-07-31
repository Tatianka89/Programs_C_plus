// Домашняя работа 1.4.1.cpp : Этот файл содержит функцию "main". 
//
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	double speed, distance, time;
	int minutes, seconds;
	cout << "Вычисление скорости бега.";
	cout << " Введите длину дистанции (метров) = ";
	cin >> distance;
	cout << " Введите время(мин.сек) = ";
	cin >> time;
	minutes = time;
	seconds = (time - minutes) * 100;
	time = (minutes * 60) + seconds;
	speed = distance / time * 3.6;
	cout << "Дистанция: " << distance << "м\n";
	cout << "Время: " << minutes << " мин " <<
		seconds << " сек = " << time << " секунд\n";
	cout << "Вы бежали со скоростью " << speed << "км/ч\n";

	return 0;
}
