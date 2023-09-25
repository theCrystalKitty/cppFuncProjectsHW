#include <iostream>
using namespace std;

int main()
{
    int num, max = 0, min = INT32_MAX;

    for (short i = 0; i < 7; i++) {
        cout << "Input a number: ";
        cin >> num;
        if (min > num)
            min = num;
        if (max < num)
            max = num;
    }

    cout << "Max number: " << max << endl << "Min number: " << min;

    return 0;
}
