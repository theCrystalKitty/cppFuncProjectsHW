#include <iostream>
using namespace std;

int main()
{
    float* usdToEur = new float[12];
    float* percent = new float[12];
    float deposit;

    for (short i = 0, j = 0; i < 12; i++) {
        cout << "Input usd to eur conversion for " << i + 1 << " month: ";
        cin >> j;
        usdToEur[i] = j;
    }

    for (short i = 0, j = 0; i < 12; i++) {
        cout << "Input percents added for " << i + 1 << " month: ";
        cin >> j;
        percent[i] = j;
    }

    cout << "Input you deposit amount: ";
    cin >> deposit;

    short month;

    cout << "Input a month: ";
    cin >> month;

    for (short i = 11, j = deposit; i >= month - 1; i--) {
        if (i == month) {
            if (j / 100 * percent[i] >= 500) {
                cout << "You can withdraw: $" << ((j / 100 * percent[i]) * usdToEur[i]) / 2 << endl;
                break;
            }
            else
                break;
        }
        j -= j / 100 * percent[i];
    }

    return 0;
}
