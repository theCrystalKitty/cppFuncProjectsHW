#include <iostream>
using namespace std;

int main()
{
    int num;

    while (true){
        cout << "Input a 6-digit number: ";
        cin >> num;
        if (!(num < 100000 || num>999999))
            break;
        cout << "The number you entered is not a 6-digit number." << endl;
    }

    if ((num / 100000 + num / 10000 % 10 + num / 1000 % 10) == (num % 10 + num / 10 % 10 + num / 100 % 10)) {
        cout << "A lucky number!";
    }
    else {
        cout << "Not a lucky number.";
    }

    return 0;
}
