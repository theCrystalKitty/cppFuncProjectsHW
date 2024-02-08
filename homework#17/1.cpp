#include <iostream>
#define rand(a, b) a + rand() % (b - a + 1)
using namespace std;

template <typename T>
void fillArray(T** arr) {
    int size1 = _msize(arr) / sizeof(arr[0]), \
        size2 = _msize(arr[0]) / sizeof(arr[0][0]);

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size1; j++) {
            arr[i][j] = rand(0, 9);
        }
    }
}

template <typename T>
void showArray(T** arr) {
    int size1 = _msize(arr) / sizeof(arr[0]), \
        size2 = _msize(arr[0]) / sizeof(arr[0][0]);

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

template <typename T>
void removeArray(T**& arr, int index) {
    int size1 = _msize(arr) / sizeof(arr[0]);

    if (index < 0 || index > size1) {
        cout << "index out of range";
        return;
    }

    T** newArr = new T * [size1 - 1];
    for (int i = 0, j = 0; i < size1; i++) {
        if (i != index)
            newArr[j++] = arr[i];
    }

    delete[]arr[index];
    delete[]arr;
    arr = newArr;
}

int main()
{
    srand(time(NULL));

    int** arr = new int* [5];
    for (short i = 0; i < 5; i++) {
        arr[i] = new int[5];
    }

    fillArray(arr);

    showArray(arr);

    cout << endl;

    removeArray(arr, 3);

    showArray(arr);

    return 0;
}
