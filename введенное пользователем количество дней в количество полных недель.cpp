// Написать программу, которая преобразует введенное пользователем количество дней в количество полных недель и оставшихся дней.Например, пользователь ввел 17 дней, программа должна вывести на экран 2 недели и 3 дня.
//
#include <iostream>
using namespace std;
int main ()
{
    const int week = 7; 
    int days, weeks;

    cout << "days : ";
    cin >> days; 
    weeks = days / 7;
    days = days % 7;

    cout << "weeks : " << weeks << "\n";
    cout << "days : " << days << "\n";
    cout << " weeks : " << weeks << " days : " << days * 1 << "\n";

    return 0;
}
