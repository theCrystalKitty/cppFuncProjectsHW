#include <iostream>
#include <string>
#define rand(a, b) a + rand() % (b + 1 - a)
using namespace std;

const char LETTERS[11] = { 'A', 'B', 'E', 'K', 'M', 'H', 'O', 'P', 'C', 'T', 'X' };

class Car {
private:
	static string lastNumberPlate;
	string numberPlate;
	string model;
	string color;

	void incrementLastNumberPlate() {
		string pon = "";
		int pon1 = 0;
		for (short i = 0; i < 3; i++) {
			pon += this->lastNumberPlate[i + 1];
		}
		pon1 = stoi(pon);
		if (pon1 < 999) {
			pon1++;
			if (pon1 / 10 == 0) {
				pon = "";
				pon = pon + this->lastNumberPlate[0] + "00" + to_string(pon1) + this->lastNumberPlate[4] + this->lastNumberPlate[5];
				this->lastNumberPlate = pon;
			}
			else if (pon1 / 100 == 0) {
				pon = "";
				pon = pon + this->lastNumberPlate[0] + "0" + to_string(pon1) + this->lastNumberPlate[4] + this->lastNumberPlate[5];
				this->lastNumberPlate = pon;
			}
			else {
				pon = "";
				pon = pon + this->lastNumberPlate[0] + to_string(pon1) + this->lastNumberPlate[4] + this->lastNumberPlate[5];
				this->lastNumberPlate = pon;
			}
		}
		else {
			if (this->lastNumberPlate[5] == LETTERS[10]) {
				if (this->lastNumberPlate[4] == LETTERS[10]) {
					if (this->lastNumberPlate[0] == LETTERS[10]) {
						cout << "Max cars reached!" << endl;
						return;
					}
					for (short i = 0; i < 10; i++) {
						if (this->lastNumberPlate[0] == LETTERS[i]) {
							pon = "";
							pon = pon + LETTERS[i + 1] + "000" + this->lastNumberPlate[4] + this->lastNumberPlate[5];
							this->lastNumberPlate = pon;
						}
					}
				}
				for (short i = 0; i < 10; i++) {
					if (this->lastNumberPlate[4] == LETTERS[i]) {
						pon = "";
						pon = pon + this->lastNumberPlate[0] + "000" + LETTERS[i + 1] + this->lastNumberPlate[5];
						this->lastNumberPlate = pon;
						return;
					}
				}
			}
			for (short i = 0; i < 10; i++) {
				if (this->lastNumberPlate[5] == LETTERS[i]) {
					pon = "";
					pon = pon + this->lastNumberPlate[0] + "000" + this->lastNumberPlate[4] + LETTERS[i + 1];
					this->lastNumberPlate = pon;
					return;
				}
			}
		}
	}

public:
	Car(string model, string color) {
		this->numberPlate = this->lastNumberPlate;
		this->model = model;
		this->color = color;
		this->incrementLastNumberPlate();
	}

	string getNumberPlate() {
		return this->numberPlate;
	}
	string getModel() {
		return this->model;
	}
	string getColor() {
		return this->color;
	}
	static string getL() {
		return lastNumberPlate;
	}
};

string Car::lastNumberPlate = "A001AA";

int main()
{
	srand(time(NULL));

	Car haha("pon", "pon");
	cout << haha.getNumberPlate() << " " << haha.getL() << endl;
	for (short i = 0; i < 1000; i++) {
		haha = Car("pon", "pon");
		cout << haha.getNumberPlate() << " " << haha.getL() << endl;
	}

	return 0;
}
