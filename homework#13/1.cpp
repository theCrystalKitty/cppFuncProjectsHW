#include <iostream>
using namespace std;

// # 1
template <typename T>
bool findLinear(T arr[], const int SIZE, T key) {
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}

// # 2
template <typename T>
bool findBinary(T arr[], const int SIZE, T key) {
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < SIZE - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                flag = true;
            }
        }
    }
    int middle = int(round(float(SIZE) / 2));
    while (true) {
        if (key == arr[middle])
            return true;
        if (middle == SIZE || middle == 0) {
            return false;
        }
        if (key > arr[middle]) {
            middle = middle + int(round(float(SIZE - middle) / 2));
        }
        else {
            middle = middle - int(round(float(SIZE - middle) / 2)) - 1;
            if (middle == 1)
                middle--;
        }
        
    }
}

// # 3
int binToInt(int num) {
    int conv = 0;

    for (int i = 0; num != 0; i++) {
        conv += num % 10 * (pow(2, i));
        num /= 10;
    }

    return conv;
}

// # 4
template <typename T>
void matrixInit(T** matrix, T symbol, const int SIZE1, const int SIZE2) {
    for (int i = 0; i < SIZE1; i++) {
        for (int j = 0; j < SIZE2; j++) {
            matrix[i][j] = symbol;
        }
    }
}

template <typename T>
void showMatrix(T** matrix, const int SIZE1, const int SIZE2) {
    for (int i = 0; i < SIZE1; i++) {
        for (int j = 0; j < SIZE2; j++) {
            cout << matrix[i][j] << ' ';
        }
    }
}

template <typename T>
T maxElDiag(T** matrix, const int SIZE1, const int SIZE2) {
    T max = matrix[0][0];
    for (int i = 1, j = 1; i < SIZE1 || j < SIZE2; i++, j++) {
        if (max < matrix[i][j])
            max = matrix[i][j];
    }
    return max;
}
template <typename T>
T minElDiag(T** matrix, const int SIZE1, const int SIZE2) {
    T min = matrix[0][0];
    for (int i = 1, j = 1; i < SIZE1 || j < SIZE2; i++, j++) {
        if (min > matrix[i][j])
            min = matrix[i][j];
    }
    return min;
}

template <typename T>
bool sortLinesMatrix(T** matrix, const int SIZE1, const int SIZE2) {
    for (int i = 0; i < SIZE2; i++) {
        bool flag = true;
        while (flag) {
            flag = false;
            for (int j = 0; j < SIZE2 - 1; j++) {
                if (matrix[i][j] > matrix[i][j + 1]) {
                    swap(matrix[i][j], matrix[i][j + 1]);
                    flag = true;
                }
            }
        }
    }
}

int main()
{
    

    return 0;
}
