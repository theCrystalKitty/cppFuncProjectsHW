#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));
    
    int* nums = new int[10];
    int rangeStart, rangeEnd, num, sum = 0;

    cout << "Input a range: ";
    cin >> rangeStart >> rangeEnd;
    cout << "Input a number: ";
    cin >> num;

    for (short i = 0; i < 10; i++) {
        nums[i] = rangeStart + rand() % (rangeEnd + 1 - rangeStart);
    }

    for (short i = 0; i < 10; i++) {
        if (nums[i] < num)
            sum += nums[i];
        cout << nums[i] << ' ';
    }

    cout << endl << "Sum: " << sum;

    return 0;
}
