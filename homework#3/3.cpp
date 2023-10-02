#include <iostream>
using namespace std;

int main()
{
    short choose, late, a;
    int income, lines;

    cout << "Task 1 - 1, Task 2 - 2, Task3 - 3: ";
    cin >> choose;

    switch (choose) {
    case 1:
        cout << "Input the income you want: ";
        cin >> income;
        cout << "Input how many times you are late to work: ";
        cin >> late;
        cout << "You will need to write " << float((income + late * 20)) / 50 * 100 << " lines of code";
        break;
    case 2:
        cout << "Input how many lines of code did you write: ";
        cin >> lines;
        cout << "Input the income you want: ";
        cin >> income;
        a = (income - float(lines) / 100 * 50) / 20;
        if (a < 0) 
            a = 0;
        cout << "You can be late to work " << a << " time(s)";
        break;
    case 3:
        cout << "Input how many lines of code did you write: ";
        cin >> lines;
        cout << "Input how many times you are late to work: ";
        cin >> late;
        a = float(lines) / 100 * 50 - late * 20;
        if (a < 0)
            a = 0;
        cout << "You will be paid " << a;
    }

    return 0;
}
