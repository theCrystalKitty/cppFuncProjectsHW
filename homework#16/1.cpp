#include <iostream>
#define rand(a, b) a + rand() % (b - a + 1)
using namespace std;

template <typename T>
void quickSortRec(T* arr, int left, int right);

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
void quickSort(T* arr) {
    int size = _msize(arr) / sizeof(arr[0]);

    quickSortRec(arr, 0, size - 1);
}

template <typename T>
void quickSortRec(T* arr, int left, int right) {
    if (left >= right)
        return;
    int wall = left - 1;
    for (int i = left; i <= right; i++) {
        if (arr[i] <= arr[right]) {
            wall++;
            if (i > wall) {
                swap(arr[i], arr[wall]);
            }
        }
    }
    quickSortRec(arr, left, wall - 1);
    quickSortRec(arr, wall + 1, right);
}

int main()
{
    srand(time(NULL));

    int* arr = new int[10];

    fillArray(arr);

    showArray(arr);

    quickSort(arr);

    showArray(arr);

    return 0;
}
