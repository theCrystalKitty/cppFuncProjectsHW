#include <iostream>
using namespace std;

int main()
{
    short num;

    while (true){
        cout << "Input a 4-digit number: ";
        cin >> num;
        if (!(num < 1000 || num>9999))
            break;
        cout << "The number you entered is not a 4-digit number." << endl;
    }

    num = num / 1000 * 100 + num / 100 % 10 * 1000 + num % 10 * 10 + num / 10 % 10;

    cout << num;

    return 0;
}
