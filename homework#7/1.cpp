#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));

    int* arr = new int[10];
    for (short i = 0; i < 10; i++) {
        arr[i] = rand() % 9;
        cout << arr[i] << " ";
    }

    int* arr2 = new int[5];
    int* arr3 = new int[5];

    cout << endl;

    for (short i = 0; i < 5; i++) {
        arr2[i] = arr[i];
        cout << arr2[i] << " ";
    }

    cout << endl;

    for (short i = 5; i < 10; i++) {
        arr3[i - 5] = arr[i];
        cout << arr3[i] << " ";
    }

    return 0;
}
