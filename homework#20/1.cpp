#include <iostream>
#include <string>
#include <fstream>
#define rand(a, b) a + rand() % (b - a + 1)
using namespace std;

class str : public string {
public:
    using string::string;

    str* split(char target) {
        str pon = "";
        int counter = 0;

        for (int i = 0; this[0][i] != '\0'; i++) {
            if (this[0][i] == target && i != 0 && this[0][i + 1] != '\0' && this[0][i - 1] != target)
                counter++;
        }

        if (counter == 0) {
            str* buf = new str[1];
            for (int i = 0; this[0][i] != '\0'; i++) {
                buf[0] += this[0][i];
            }
            return buf;
        }
        
        str* buf = new str[counter + 2];

        for (int i = 0, k = 0; this[0][i] != '\0'; i++) {
            if (this[0][i] == target && i != 0 && this[0][i + 1] != '\0' && this[0][i - 1] != target) {
                buf[k++] = pon;
                pon = "";
                continue;
            }
            else if ((i == 0 || this[0][i + 1] == '\0') && this[0][i] == target) {
                continue;
            }
            pon += this[0][i];
        }
        buf[counter] = pon;

        return buf;
    }
};

// 1
template <typename T>
T findLeast(T a, T b, T c) {
    return ((a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c));
}

// 2
template <typename T>
void sum(T a, T b) {
    T sum = 0;
    int count = 0;
    if (a > b) {
        swap(a, b);
    }
    for (T i = a; i < b + 1; i++, count++) {
        sum += i;
    }
    cout << "Sum: " << sum << endl \
        << "Amount: " << count << endl \
        << "Avg: " << (float)sum / count << endl;
}

// 3
bool isLeapYear(short year) {
    return ((year % 4 == 0) ? ((year % 100 == 0) ? ((year % 400 == 0) ? true : false) : true) : false);
}

// 4
template <typename T>
void fillArray(T* arr) {
    int size = _msize(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        arr[i] = rand(1, 9);
    }
}

// 5
template <typename T>
T biggestNumber(T* arr) {
    int size = _msize(arr) / sizeof(arr[0]);

    T num = arr[0];

    for (int i = 1; i < size; i++) {
        if (num < arr[i])
            num = arr[i];
    }

    return num;
}

// 6
template <typename T>
void addElement(T* &arr, T element) {
    int size = _msize(arr) / sizeof(arr[0]);

    T* buf = new T[size + 1];

    for (int i = 0; i < size; i++) {
        buf[i] = arr[i];
    }

    buf[size] = element;

    delete[]arr;
    arr = buf;
}

template <typename T>
void showArray(T* arr) {
    int size = _msize(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
}

// 8
bool check(str* pons, str pon, int i) {
    int ponStart = pon.find_last_of(' ');
    if (ponStart == -1) {
        ponStart = 0;
    }
    int ponEnd = pon.length();

    int ponsStart = 0;
    int ponsEnd = pons[i].length();

    for (int j = ponStart, k = ponsStart; j < ponEnd, k < ponsEnd; j++, k++) {
        if (pons[i][k] != pon[j]) {
            return true;
        }
    }

    return false;
}

void showStringsWithKeyWord(string path, string keyword) {
    str pon;
    str* pons = nullptr;
    int size;
    int i = 0;
    ifstream in(path);

    if (in.is_open()) {
        while (getline(in, pon)) {
            pons = pon.split(' ');
            i = -1;
            do {
                i++;
                if (pons[i] == keyword) {
                    cout << pon << endl;
                    break;
                }
            } while (check(pons, pon, i));
        }
    }

    in.close();
}

int main()
{
    srand(time(NULL));

    // 1
    /*int a, b, c;

    cin >> a >> b >> c;

    cout << findLeast(a, b, c) << endl << endl;*/


    // 2
    /*int a, b;

    cin >> a >> b;

    sum(a, b);*/


    // 3
    /*short year;

    cin >> year;
    
    cout << ((isLeapYear(year)) ? "YES" : "NO") << endl << endl;*/


    // 4 && 5 && 6
    /*int* arr = new int[5];

    fillArray(arr);

    for (short i = 0; i < 5; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl << endl;

    cout << biggestNumber(arr) << endl << endl;

    addElement(arr, 5);

    showArray(arr);
    cout << endl << endl;*/


    // 7
    /*string pon;

    cin >> pon;

    for (int i = pon.length() - 1; i > -1; i--) {
        cout << pon[i];
    }
    cout << endl << endl;*/


    // 8
    showStringsWithKeyWord("file.txt", "la");

    return 0;
}
