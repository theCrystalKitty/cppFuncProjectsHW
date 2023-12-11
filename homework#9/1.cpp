#include <iostream>
using namespace std;

int main() {
    srand(time(NULL));
    
    const int SIZE1 = 5, SIZE2 = 5;

    int** arr = new int* [SIZE1];
    for (short i = 0; i < SIZE1; i++) {
        arr[i] = new int[SIZE2];
    }

    for (short i = 0; i < SIZE1; i++) {
        for (short j = 0; j < SIZE2; j++) {
            arr[i][j] = 1 + rand() % 99;
        }
    }

    int sum = 0;
    for (int i = 0, total; i < SIZE1; i++) {
        total = 0;
        for (short j = 0; j < SIZE2; j++) {
            cout << arr[i][j] << '\t';
            total += arr[i][j];
            sum += arr[i][j];
        }
        cout << "|\t" << total << endl;
    }

    cout << "_\t_\t_\t_\t_\t_\t_" << endl;

    for (int i = 0, total; i < SIZE2; i++) {
        total = 0;
        for (short j = 0; j < SIZE1; j++) {
            total += arr[j][i];
        }
        cout << total << "\t";
    }

    cout << "|\t" << sum << endl << endl;


    for (int i = 0, max = INT32_MIN, maxX, maxY, min = INT32_MAX, minX, minY, maxSumStr = INT32_MIN, maxSumStrNum, minSumStr = INT32_MAX, minSumStrNum, sumStr; i < SIZE1; i++) {
        sumStr = 0;
        for (short j = 0; j < SIZE2; j++) {
            sumStr += arr[i][j];
            if (arr[i][j] > max) {
                max = arr[i][j];
                maxX = j;
                maxY = i;
            }
            if (arr[i][j] < min) {
                min = arr[i][j];
                minX = j;
                minY = i;
            }
        }
        if (sumStr > maxSumStr) {
            maxSumStr = sumStr;
            maxSumStrNum = i;
        }
        if (sumStr < minSumStr) {
            minSumStr = sumStr;
            minSumStrNum = i;
        }
        if (i == SIZE2 - 1) {
            cout << "Max val: " << max << " (" << maxX + 1 << ":" << maxY + 1 << ")" << endl \
                << "Min val: " << min << " (" << minX + 1 << ":" << minY + 1 << ")" << endl \
                << "Max sum in str: " << maxSumStr << " (" << maxSumStrNum + 1 << ")" << endl \
                << "Min sum in str: " << minSumStr << " (" << minSumStrNum + 1 << ")" << endl;
        }
    }

    for (int i = 0, total, maxSumCol = INT32_MIN, maxSumColNum, minSumCol = INT32_MAX, minSumColNum; i < SIZE2; i++) {
        total = 0;
        for (short j = 0; j < SIZE1; j++) {
            total += arr[j][i];
        }
        if (total > maxSumCol) {
            maxSumCol = total;
            maxSumColNum = i;
        }
        if (total < minSumCol) {
            minSumCol = total;
            minSumColNum = i;
        }
        if (i == SIZE2 - 1) {
            cout << "Max sum in column: " << maxSumCol << " (" << maxSumColNum + 1 << ")" << endl \
                << "Min sum in column: " << minSumCol << " (" << minSumColNum + 1 << ")" << endl;
        }
    }

    return 0;
}
