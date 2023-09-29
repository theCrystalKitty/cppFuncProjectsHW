#include <iostream>
using namespace std;

int main()
{
    char ch;

    cout << "Input any character: ";
    cin >> ch;

    if (isalpha(ch))
        cout << "The character you have inputted is a letter.";
    else if (isdigit(ch))
        cout << "The character you have inputted is a digit.";
    else
        cout << "The character you have inputted is a symbol.";

    return 0;
}
