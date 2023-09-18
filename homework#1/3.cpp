#include <iostream>
using namespace std;

int main()
{
    short salary, total = 0;

    for (short i = 1; i < 4; i++) {
        switch (i) {
        case 1:
            cout << "Input the salary for the " << i << "st month: ";
            break;
        case 2:
            cout << "Input the salary for the " << i << "nd month: ";
            break;
        case 3:
            cout << "Input the salary for the " << i << "rd month: ";
            break;
        }
        cin >> salary;
        total += salary;
    }

    cout << "Total salary for this quarter: " << total << endl;

    return 0;
}
