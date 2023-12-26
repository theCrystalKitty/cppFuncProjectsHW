#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    srand(time(NULL));

    // 1
    /*int max = INT32_MIN;
    for (int i = 0, j; i < 4; i++) {
        cout << "Input a number: ";
        cin >> j;
        if (max < j)
            max = j;
    }

    cout << max;*/

    // 2
    /*int n, a, b;
    cout << "Input n, a, b: ";
    cin >> n >> a >> b;

    if (a > b)
        swap(a, b);

    for (int i = a; i < n + a; i++) {
        cout << ((i >= b) ? b : i) << ' ';
    }*/

    // 3
    /*float max;
    cout << "Input max: ";
    cin >> max;

    for (float i = 0; i < max; i += 0.25) {
        cout << i << ' ';
    }*/

    // 4
    /*int count = 0, sum = 0;

    for (int num = 1; num == 0; count++) {
        cout << "Input a number: ";
        cin >> num;
        sum += num;
    }

    cout << sum / count;*/

    // 5
    /*char ch;
    cout << "Input a symbol: ";
    cin >> ch;

    cout << "The symbol is " << ((ch >= 'a' && ch <= 'z') ? "an english letter" : "not an english letter");*/

    // 6
    /*int arr[10];
    
    for (short i = 0; i < 10; i++) {
        arr[i] = 7 + rand() % 12;
        cout << arr[i] << ' ';
    }

    cout << endl;

    // 7
    short size = 0;
    for (short i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0)
            size++;
    }

    int* arr2 = new int[size];
    for (short i = 0, count = 0; i < 10; i++) {
        if (arr[i] % 2 == 0)
            arr2[count++] = arr[i];
    }

    for (short i = 0; i < size; i++) {
        cout << arr2[i] << ' ';
    }*/

    // 8
    /*int size;
    cout << "Input size of the square: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << ((i == 0 || i == size - 1 || j == 0 || j == size - 1 || j == size / 2 || i == size / 2) ? "0 " : "  ");
        }
        cout << endl;
    }*/

    // 9
    /*int arr[10];

    for (short i = 0; i < 10; i++) {
        arr[i] = 7 + rand() % 12;
        cout << arr[i] << ' ';
    }

    cout << endl;

    for (short i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0)
            cout << arr[i];
    }*/

    // 10
    /*const short SIZE1 = 5, SIZE2 = 4;

    int arr[SIZE1][SIZE2];

    for (short i = 0; i < SIZE1; i++) {
        for (short j = 0; j < SIZE2; j++) {
            arr[i][j] = 10 + rand() % 90;
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    short max = INT16_MIN, min = INT16_MAX, sum = 0, maxNumCol;

    for (short i = 0; i < SIZE1; i++) {
        for (short j = 0; j < SIZE2; j++) {
            if (arr[i][j] < min)
                min = arr[i][j];
            if (arr[i][j] > max) {
                max = arr[i][j];
                maxNumCol = j + 1;
            }
            sum += arr[i][j];
        }
    }

    cout << "Min: " << min << endl\
        << "Max: " << max << endl\
        << "Column with max number: " << maxNumCol << endl\
        << "Sum: " << sum << endl;*/

    return 0;
}
