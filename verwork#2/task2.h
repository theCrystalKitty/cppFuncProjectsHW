#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 1
void showTxtDoc(string path) {
	string str;

	ifstream in(path);

	if (in.is_open()) {
		while (getline(in, str)) {
			cout << str << endl;
		}
	}

	in.close();
}

// 2
string* getStringsFromFile(string path) {
	string* data = nullptr;
	string str;
	int size = 0, i = 0;

	ifstream in(path);

	if (in.is_open()) {
		while (getline(in, str)) {
			size++;
		}
	}

	in.close();

	ifstream in2(path);

	if (in2.is_open()) {
		data = new string[size];

		while (getline(in2, str)) {
			data[i++] = str;
		}
	}

	in2.close();

	return data;
}

// 3
void writeStringsInFile(string path, string* data, int size) {
	ofstream out(path, ios::app);

	if (out.is_open()) {
		for (int i = 0; i < size; i++) {
			out << endl << data[i];
		}
	}

	out.close();
}

// 4
void rmStringFromFile(string path, int index) {
	string* data = nullptr;
	string str;
	int size = 0, i = 0;

	ifstream in(path);

	if (in.is_open()) {
		while (getline(in, str)) {
			size++;
		}
	}

	if (index >= size || index < 0) {
		cout << "Error: Index out of range!" << endl;
		return;
	}

	in.close();

	ifstream in2(path);

	if (in2.is_open()) {
		data = new string[size];

		while (getline(in2, str)) {
			data[i++] = str;
		}
	}

	in2.close();

	ofstream out(path);

	if (out.is_open()) {
		for (int j = 0; j < size; j++) {
			if (j != index)
				out << data[j] << endl;
		}
	}

	out.close();
}

// 5
int countRepeatingStrInFile(string path, string target) {
	int counter = 0;
	string str;
	ifstream in(path);

	if (in.is_open()) {
		while (getline(in, str)) {
			if (str == target) {
				counter++;
			}
		}
	}

	return counter;
}
