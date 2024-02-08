#include <iostream>
#define rand(a, b) a + rand() % (b - a + 1)
using namespace std;

template <typename T>
void fillArray(T* arr) {
    int size = _msize(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        arr[i] = rand(0, 9);
    }
}

template <typename T>
void showArray(T* arr) {
    int size = _msize(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }

    cout << endl;
}

template <typename T>
void bubbleSort(T* arr) {
    int size = _msize(arr) / sizeof(arr[0]);

    bool flag = true;

    while (flag) {
        flag = false;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                flag = true;
            }
        }
    }
}

int main()
{
    srand(time(NULL));

    int* arr = new int [5];

    fillArray(arr);

    showArray(arr);

    bubbleSort(arr);

    showArray(arr);

    return 0;
}
