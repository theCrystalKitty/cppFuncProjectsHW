#include <iostream>
using namespace std;

template <typename T1, typename T2>
double calc(T1 a, char op, T2 b) {
    switch (op) {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    case '^':
        return pow(a, b);
        break;
    default:
        return 0;
    }
}

int main()
{
  

    return 0;
}
