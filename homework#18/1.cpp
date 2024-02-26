#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#define rand(a, b) a + rand() % (b - a + 1)
using namespace std;

void addStr(string*& arr, int size1, string addArr) {
    string* buf = new string [size1 + 1];

    for (int i = 0; i < size1; i++) {
        buf[i] = arr[i];
    }

    buf[size1] = addArr;

    delete[]arr;
    arr = buf;
}

void readFile(string path, string*& arr, int &size) {
    ifstream in(path);
    if (in.is_open()) {
        string str;
        while (getline(in, str)) {
            addStr(arr, size++, str);
        }
    }
    else {
        cout << "File not found" << endl;
    }
    in.close();
}

void copyFile(string path) {
    string* arr = new string[0];
    int size = 0;

    readFile(path, arr, size);

    int indexPeriod = -1;
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == '.')
            indexPeriod = i;
    }

    string fileNamePath = "", ef = "";
    for (int i = 0; path[i] != '\0'; i++) {
        if (i < indexPeriod) {
            fileNamePath += path[i];
        }
        if (i >= indexPeriod) {
            ef += path[i];
        }
    }

    ofstream out(fileNamePath + "(Copy)" + ef);
    if (out.is_open()) {
        for (int i = 0; i < size; i++) {
            out << arr[i] << '\n';
        }
    }
    out.close();
}

int main()
{
    srand(time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    copyFile("./file.txt");

    return 0;
}
