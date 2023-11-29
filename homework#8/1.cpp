#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));

    int* arr = new int[10];
    int* arrCount = new int[10] {};
    for (short i = 0; i < 10; i++) {
        arr[i] = rand() % 9;
        cout << arr[i] << ' ';
    }

    for (short i = 0; i < 10; i++) {
        arrCount[arr[i]]++;
    }

    for (short i = 0, k = 0; i < 10; i++) {
        for (short j = 0; j < arrCount[i]; j++) {
            arr[k++] = i;
        }
    }

    cout << endl;

    for (short i = 0; i < 10; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
