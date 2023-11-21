#include <iostream>
using namespace std;

int main()
{
    int* arr = new int[7];

    for (short i = 0, j = 0; i < 7; i++) {
        cout << "Input your expenses for day " << i + 1;
        cin >> j;

        arr[i] = j;
    }

    int sum = 0;

    for (short i = 0; i < 7; i++) {
        sum += arr[i];
    }

    cout << "Average: $" << float(sum) / 7 << endl \
        << "Total: $" << sum;

    for (short i = 0; i < 7; i++) {
        if (arr[i] > 100) {
            switch (i) {
            case 0:
                cout << i + 1 << " Monday" << endl;
                break;
            case 1:
                cout << i + 1 << " Tuesday" << endl;
                break;
            case 2:
                cout << i + 1 << " Wednesday" << endl;
                break;
            case 3:
                cout << i + 1 << " Thursday" << endl;
                break;
            case 4:
                cout << i + 1 << " Friday" << endl;
                break;
            case 5:
                cout << i + 1 << " Saturday" << endl;
                break;
            case 6:
                cout << i + 1 << " Sunday" << endl;
                break;
            }
        }
    }

    return 0;
}
