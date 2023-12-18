#include <iostream>
using namespace std;

int main() {
    srand(time(NULL));
    
    int size1, size2;
    cout << "Input the size of arrays: ";
    cin >> size1 >> size2;

    int** arr = new int* [size1];
    for (short i = 0; i < size1; i++) {
        arr[i] = new int[size2];
        for (short j = 0; j < size2; j++) {
            arr[i][j] = 1 + rand() % 99;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int mv;
    cout << "Input how much to move the array: ";
    cin >> mv;

    for (short i = 0; i < mv; i++) {
        for (short j = 0; j < size1; j++) {
            for (short k = size2 - 1; k > 0; k--) {
                swap(arr[j][k], arr[j][k - 1]);
            }
        }
    }

    cout << endl;

    for (short i = 0; i < size1; i++) {
        for (short j = 0; j < size2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
