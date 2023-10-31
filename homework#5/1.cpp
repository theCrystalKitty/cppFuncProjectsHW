#include <iostream>
using namespace std;

int main()
{
    int rangeStart, rangeEnd, total = 0;
    bool flag;
    
    cout << "Input start and end of a range: ";
    cin >> rangeStart >> rangeEnd;

    if (rangeStart > rangeEnd)
        swap(rangeStart, rangeEnd);

    for (int i = rangeStart; i <= rangeEnd; i++) {
        flag = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = false;
            }
        }
        if (flag)
            total++;
    }

    cout << "Amount of prime numbers in the range from " << rangeStart << " to " << rangeEnd << " is " << total;

    return 0;
}
