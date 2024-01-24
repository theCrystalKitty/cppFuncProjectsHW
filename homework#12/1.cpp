#include <iostream>
using namespace std;


// #1
template <typename T>
bool isEven(T n) {
    return n % 2 == 0;
}

// #2
bool isPalindrome(string str) {
    int size = 0, counter = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        size++;
    }
    for (int i = 0; i != size / 2; i++) {
        if (str[i] != str[size - 1 - counter++])
            return false;
    }
    return true;
}

// #3
template <typename T>
T factorial(T n) {
    T result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main()
{
    

    return 0;
}
