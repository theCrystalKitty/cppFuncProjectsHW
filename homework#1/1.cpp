#include <iostream>
using namespace std;

int main()
{
    float rad;
    
    cout << "Input radius of the circle: ";
    cin >> rad;
    cout << "Square: " << 3.14 * pow(rad, 2) << endl \
        << "Circumference: " << 3.14 * (rad * 2) << endl \
        << "Diameter: " << rad * 2 << endl;

    return 0;
}
