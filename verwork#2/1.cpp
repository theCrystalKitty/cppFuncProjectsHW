#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "task1.h"
#include "task2.h"
#define rand(a, b) a + rand() % (b + 1 - a)
using namespace std;

void showTask(short num1, short num2) {
	cout << endl << "Task " << num1 << '.' << num2 << ':' << endl << endl;
}

int main()
{
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Task 1
	/*int** arr = new int* [5];
	for (short i = 0; i < 5; i++) {
		arr[i] = new int[5];
	}

	showTask(1, 1);

	fillArray(arr);

	showArray(arr);


	showTask(1, 2);

	removeStrFromArr(arr, 1);

	showArray(arr);


	showTask(1, 3);

	removeColumnFromArr(arr, 1);

	showArray(arr);


	showTask(1, 4);

	int* coords = getIndexOf(arr, 10);

	cout << coords[0] << ' ' << coords[1] << endl;


	showTask(1, 5);

	bubbleSort(arr);

	showArray(arr);


	showTask(1, 6);

	change(arr, 10, 52);

	showArray(arr);*/


	// Task 2
	/*string path = "text.txt";


	showTask(2, 1);

	showTxtDoc(path);


	showTask(2, 2);

	string* data = getStringsFromFile(path);

	cout << data[0] << endl;


	showTask(2, 3);

	writeStringsInFile(path, new string[3]{ "rgjegk[erpg]", "uhgeir erjoopr ergiw wijq p jwww", "абв"}, 3);

	showTxtDoc(path);


	showTask(2, 4);

	rmStringFromFile(path, 2);

	showTxtDoc(path);


	showTask(2, 5);

	cout << countRepeatingStrInFile(path, "a a") << endl;*/

	return 0;
}
