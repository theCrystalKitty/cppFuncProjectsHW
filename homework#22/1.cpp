#include <iostream>
#include <string>
using namespace std;

const char LETTERS[11] = { 'A', 'B', 'E', 'K', 'M', 'H', 'O', 'P', 'C', 'T', 'X' };

class Car {
private:
	static string lastNumberPlate;
	string numberPlate;
	string model;
	string color;

	void incrementLastNumberPlate() {
		if (lastNumberPlate == "X999XX" || lastNumberPlate == "MAXED") {
			lastNumberPlate = "MAXED";
			return;
		}
		string tempNumberPlate = "";
		int number1 = 0;
		for (short i = 0; i < 3; i++) {
			tempNumberPlate += this->lastNumberPlate[i + 1];
		}
		number1 = stoi(tempNumberPlate);
		if (number1 < 999) {
			number1++;
			if (number1 / 10 == 0) {
				tempNumberPlate = "";
				tempNumberPlate = tempNumberPlate + this->lastNumberPlate[0] + "00" + to_string(number1) + this->lastNumberPlate[4] + this->lastNumberPlate[5];
				this->lastNumberPlate = tempNumberPlate;
			}
			else if (number1 / 100 == 0) {
				tempNumberPlate = "";
				tempNumberPlate = tempNumberPlate + this->lastNumberPlate[0] + "0" + to_string(number1) + this->lastNumberPlate[4] + this->lastNumberPlate[5];
				this->lastNumberPlate = tempNumberPlate;
			}
			else {
				tempNumberPlate = "";
				tempNumberPlate = tempNumberPlate + this->lastNumberPlate[0] + to_string(number1) + this->lastNumberPlate[4] + this->lastNumberPlate[5];
				this->lastNumberPlate = tempNumberPlate;
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
							tempNumberPlate = "";
							tempNumberPlate = tempNumberPlate + LETTERS[i + 1] + "000" + this->lastNumberPlate[4] + this->lastNumberPlate[5];
							this->lastNumberPlate = tempNumberPlate;
						}
					}
				}
				for (short i = 0; i < 10; i++) {
					if (this->lastNumberPlate[4] == LETTERS[i]) {
						tempNumberPlate = "";
						tempNumberPlate = tempNumberPlate + this->lastNumberPlate[0] + "000" + LETTERS[i + 1] + this->lastNumberPlate[5];
						this->lastNumberPlate = tempNumberPlate;
						return;
					}
				}
			}
			for (short i = 0; i < 10; i++) {
				if (this->lastNumberPlate[5] == LETTERS[i]) {
					tempNumberPlate = "";
					tempNumberPlate = tempNumberPlate + this->lastNumberPlate[0] + "000" + this->lastNumberPlate[4] + LETTERS[i + 1];
					this->lastNumberPlate = tempNumberPlate;
					return;
				}
			}
		}
	}

public:
	Car() {};
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

	void setColor(string color) {
		this->color = color;
	}

	void carInfo() {
		cout << "Number plate: " << this->numberPlate << endl \
			<< "Model: " << this->model << endl \
			<< "Color: " << this->color << endl;
	}
};

string Car::lastNumberPlate = "A000AA";

class Parking {
private:
	string name;
	int capacity;
	int occupied = 0;
	float price;
	Car* cars = new Car[0];
public:
	Parking(string name, int capacity, float price) {
		this->name = name;
		this->capacity = capacity;
		this->price = price;
	}

	string getName() {
		return this->name;
	}
	int getCapacity() {
		return this->capacity;
	}
	float getPrice() {
		return this->price;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPrice(float price) {
		this->price = price;
	}
	~Parking() {
		delete[]this->cars;
	}

	void addCar(Car car) {
		if (this->occupied == this->capacity) {
			cout << "Parking is full!" << endl;
			return;
		}

		Car* buf = new Car[this->occupied + 1];

		for (int i = 0; i < this->occupied; i++) {
			buf[i] = this->cars[i];
		}

		buf[this->occupied++] = car;

		delete[]this->cars;
		this->cars = buf;
	}

	void removeCar(string numberPlate) {
		if (this->occupied == 0) {
			cout << "Parking is empty!" << endl;
			return;
		}

		bool flag = false;

		for (int i = 0; i < this->occupied; i++) {
			if (this->cars[i].getNumberPlate() == numberPlate) {
				flag = true;
				break;
			}
		}

		if (!flag) {
			cout << "No car with provided number plate!" << endl;
			return;
		}

		Car* buf = new Car[this->occupied - 1];

		for (int i = 0, k = 0; i < this->occupied; i++) {
			if (this->cars[i].getNumberPlate() == numberPlate) {
				continue;
			}
			buf[k++] = this->cars[i];
		}

		this->occupied--;

		delete[]this->cars;
		this->cars = buf;
	}

	void parkInfo() {
		cout << "Name: " << this->name << endl \
			<< "Capacity: " << this->capacity << endl \
			<< "Occupied: " << this->occupied << endl \
			<< "Price: " << this->price << endl \
			<< "Cars: " << endl;

		for (int i = 0; i < this->occupied; i++) {
			this->cars[i].carInfo();
			cout << endl;
		}
	}
};
int main()
{


	return 0;
}
