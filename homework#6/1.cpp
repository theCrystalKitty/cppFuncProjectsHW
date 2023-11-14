#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));
    
    int* nums = new int[10];
    int min = INT32_MAX, max = INT32_MIN;

    for (short i = 0; i < 10; i++) {
        nums[i] = 1 + rand() % 10;
    }

    for (short i = 0; i < 10; i++) {
        if (min >= nums[i])
            min = nums[i];
        if (max <= nums[i])
            max = nums[i];
        cout << nums[i] << ' ';
    }

    cout << endl << "Min: " << min << endl << "Max: " << max;

    return 0;
}
