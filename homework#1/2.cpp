#include <iostream>
using namespace std;

int main()
{
    short rating;
    float total = 0;

    for (short i = 1; i < 5; i++) {
        switch (i) {
        case 1:
            cout << "Input the rating for the " << i << "st quarter: ";
            break;
        case 2:
            cout << "Input the rating for the " << i << "nd quarter: ";
            break;
        case 3:
            cout << "Input the rating for the " << i << "rd quarter: ";
            break;
        default:
            cout << "Input the rating for the " << i << "th quarter: ";
            break;
        }
        cin >> rating;
        total += rating;
    }

    cout << "Rating for this year: " << total / 4 << endl;

    return 0;
}
