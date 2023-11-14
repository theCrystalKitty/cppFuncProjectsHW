#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));

    int* profit = new int[12];
    int rangeStart, rangeEnd, minProfit = INT32_MAX, maxProfit = INT32_MIN;

    for (short i = 0, j; i < 12; i++) {
        cout << "Input profit for the " << i + 1 << " month: ";
        cin >> j;
        profit[i] = j;
    }

    cout << "Input a range: ";
    cin >> rangeStart >> rangeEnd;
    while (rangeStart < 1 || rangeStart>12 || rangeEnd < 1 || rangeEnd>12) {
        cout << "Input a range: ";
        cin >> rangeStart >> rangeEnd;
    }

    if (rangeStart > rangeEnd)
        swap(rangeStart, rangeEnd);

    for (short i = rangeStart; i < rangeEnd; i++) {
        if (minProfit > profit[i])
            minProfit = profit[i];
        if (maxProfit < profit[i])
            maxProfit = profit[i];
    }

    cout << endl << "Min profit: " << minProfit << endl << "Max profit: " << maxProfit;

    return 0;
}
