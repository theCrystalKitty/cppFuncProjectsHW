#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));

    float* nums = new float[10];
    int min = INT32_MAX, max = INT32_MIN, pr, prCh = 0, sumNeg = 0, sumFL = 0, sumMinMax;
    short firstNegIndex = -1, lastNegIndex;

    cout << "Input min and max: ";
    cin >> min >> max;

    for (short i = 0; i < 10; i++) {
        nums[i] = (- 10) + rand() % (10 + 1 - (-10));
    }

    for (short i = 0; i < 10; i++) {
        cout << nums[i] << " ";
        if (nums[i] < 0)
            if (firstNegIndex == -1)
                firstNegIndex = i;
            lastNegIndex = i;
            sumNeg += nums[i];
        if (i % 2 == 0 && prCh == 0)
            prCh = nums[i];
        if (i % 2 == 0)
            prCh *= nums[i];
    }

    for (short i = firstNegIndex; i <= lastNegIndex; i++) {
        sumFL += nums[i];
    }

    for (short i = min; i <= max; i++) {
        sumMinMax += nums[i];
    }

    cout << endl \
        << "Sum of negative numbers: " << sumNeg << endl \
        << "* of numbers between min and max: " << sumMinMax << endl \
        << "* of numbers with even index: " << prCh << endl \
        << "Sum of numbers between first and last negative numbers : " << sumFL;

    return 0;
}
