#include <iostream>
using namespace std;

int main()
{
    short from, to, time;
    short price12=19, price21=12, price13=6, price31=5, price23=10, price32=11;

    cout << "Choose operator to call from (operator1 - 1, operator2 - 2, operator3 - 3): ";
    cin >> from;
    cout << "Choose operator to call to (operator1 - 1, operator2 - 2, operator3 - 3): ";
    cin >> to;
    cout << "Input the time of a call: ";
    cin >> time;

    if(from == 1 && from == 2) {
        cout << "Price: " << time * price12;
    }
    else if (from == 2 && to == 1) {
        cout << "Price: " << time * price21;
    }
    else if (from == 1 && to == 3) {
        cout << "Price: " << time * price13;
    }
    else if (from == 3 && to == 1) {
        cout << "Price: " << time * price31;
    }
    else if (from == 2 && to == 3) {
        cout << "Price: " << time * price23;
    }
    else if (from == 3 && to == 2) {
        cout << "Price: " << time * price32;
    }

    return 0;
}
