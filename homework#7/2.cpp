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

    cout << endl;

    int* arr2 = new int[10];
    for (short i = 0; i < 10; i++) {
        arr[i] = rand() % 9;
        cout << arr2[i] << " ";
    }

    cout << endl;

    int* arr3 = new int[10];
    for (short i = 0; i < 10; i++) {
        arr3[i] = arr[i] + arr2[i];
        cout << arr3[i] << " ";
    }

    return 0;
}
