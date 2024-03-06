#pragma once

#include <iostream>
#define rand(a, b) a + rand() % (b + 1 - a)
using namespace std;

// 1
template <typename T>
void fillArray(T** arr, int a = 10, int b = 99) {
	int size1 = _msize(arr) / sizeof(arr[0]), \
		size2 = _msize(arr[0]) / sizeof(arr[0][0]);

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			arr[i][j] = rand(a, b);
		}
	}
}

// 2
template <typename T>
void removeStrFromArr(T** &arr, int index) {
	int size1 = _msize(arr) / sizeof(arr[0]), \
		size2 = _msize(arr[0]) / sizeof(arr[0][0]);

	if (index >= size1 || index < 0) {
		cout << "Error: index out of range!" << endl;
		return;
	}

	T** buf = new T* [size1 - 1];
	for (int i = 0, k = 0; i < size1; i++) {
		if (i != index) {
			buf[k] = new T[size2];
			buf[k++] = arr[i];
		}
	}

	delete[]arr[index];
	arr = buf;
}

// 3
template <typename T>
void removeColumnFromArr(T** &arr, int index) {
	int size1 = _msize(arr) / sizeof(arr[0]), \
		size2 = _msize(arr[0]) / sizeof(arr[0][0]);

	if (index >= size2 || index < 0) {
		cout << "Error: index out of range!" << endl;
		return;
	}

	T** buf = new T* [size1];
	for (int i = 0; i < size1; i++) {
		buf[i] = new T[size2 - 1];
		for (int j = 0, k = 0; j < size2; j++) {
			if (j != index)
				buf[i][k++] = arr[i][j];
		}
		delete[]arr[i];
	}


	delete[]arr;
	arr = buf;
}

// 4
template <typename T>
int* getIndexOf(T** arr, T el) {
	int ind1 = -1, ind2 = -1;
	int size1 = _msize(arr) / sizeof(arr[0]), \
		size2 = _msize(arr[0]) / sizeof(arr[0][0]);

	for (int i = 0, flag = true; i < size1 && flag; i++) {
		for (int j = 0; j < size2; j++) {
			if (arr[i][j] == el) {
				ind1 = i;
				ind2 = j;
				flag = false;
				break;
			}
		}
	}

	return new int[2] {ind1, ind2};
}

// 5
template <typename T>
void bubbleSort(T** arr) {
	int size1 = _msize(arr) / sizeof(arr[0]), \
		size2 = _msize(arr[0]) / sizeof(arr[0][0]);
	bool flag = true;

	while (flag) {
		flag = false;

		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size2 - 1; j++) {
				if (arr[i][j] > arr[i][j + 1]) {
					swap(arr[i][j], arr[i][j + 1]);
					flag = true;
				}
			}
		}
	}
}

// 6
template <typename T>
void change(T** arr, T a, T b) {
	int size1 = _msize(arr) / sizeof(arr[0]), \
		size2 = _msize(arr[0]) / sizeof(arr[0][0]);

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (arr[i][j] == a)
				arr[i][j] = b;
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
