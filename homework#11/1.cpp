#include <iostream>
#include <Windows.h>
using namespace std;

void show(char** arr, int size1, int size2) {
    system("cls");
    cout << "  a b c d" << endl;
    for (short i = 0; i < size1; i++) {
        cout << i + 1 << ' ';
        for (short j = 0; j < size2; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));

    const int SIZE = 4;
    
    char** field = new char* [SIZE];
    for (short i = 0; i < SIZE; i++) {
        field[i] = new char [SIZE];
    }

    char** showField = new char* [SIZE];
    for (short i = 0; i < SIZE; i++) {
        showField[i] = new char [SIZE];
        for (short j = 0; j < SIZE; j++) {
            showField[i][j] = '#';
        }
    }

    for (short i = 0, c = 0; i < SIZE; i++) {
        for (short j = 0; j < SIZE; j++) {
            switch (c) {
            case 0:
                field[i][j] = '1';
                break;
            case 1:
                field[i][j] = '1';
                break;
            case 2:
                field[i][j] = '2';
                break;
            case 3:
                field[i][j] = '2';
                break;
            case 4:
                field[i][j] = '3';
                break;
            case 5:
                field[i][j] = '3';
                break;
            case 6:
                field[i][j] = '4';
                break;
            case 7:
                field[i][j] = '4';
                break;
            case 8:
                field[i][j] = '5';
                break;
            case 9:
                field[i][j] = '5';
                break;
            case 10:
                field[i][j] = '6';
                break;
            case 11:
                field[i][j] = '6';
                break;
            case 12:
                field[i][j] = '*';
                break;
            case 13:
                field[i][j] = '*';
                break;
            case 14:
                field[i][j] = '*';
                break;
            case 15:
                field[i][j] = '*';
                break;
            }
            c++;
        }
    }

    for (short i = 0; i < SIZE*SIZE; i++) {
        swap(field[rand() % SIZE][rand() % SIZE], field[rand() % SIZE][rand() % SIZE]);
    }

    cout << "  a b c d" << endl;
    for (short i = 0; i < SIZE; i++) {
        cout << i + 1 << ' ';
        for (short j = 0; j < SIZE; j++) {
            cout << showField[i][j] << ' ';
        }
        cout << endl;
    }

    int choose1, choose2;
    char choose2char;
    short hp = 3;

    bool flag = true;
    while (flag && hp > 0) {
        for (int i = 0, ch1s = -1, ch2s = -1; i < 2; i++) { 
            while (true) {
                cout << "Input coordinates: ";
                cin >> choose1 >> choose2char;

                choose1 -= 1;
                choose2 = int(choose2char) - 97;

                while (showField[choose1][choose2] != '#') {
                    cout << endl << "This coordinate was already opened!" << endl;
                    cout << "Input coordinates: ";
                    cin >> choose1 >> choose2char;

                    choose1 -= 1;
                    choose2 = int(choose2char) - 97;
                }

                showField[choose1][choose2] = field[choose1][choose2];
                show(showField, SIZE, SIZE);
                if (field[choose1][choose2] == '*') {
                    if (ch1s != -1 && ch2s != -1) {
                        showField[ch1s][ch2s] = '#';
                    }
                    cout << endl << "You found the mine! Lives left: " << --hp;
                    Sleep(3000);
                    i = 2;
                    break;
                }

                if (ch1s != -1 && ch2s != -1 && field[choose1][choose2] != field[ch1s][ch2s]) {
                    Sleep(2000);
                    showField[choose1][choose2] = '#';
                    showField[ch1s][ch2s] = '#';
                    break;
                }

                ch1s = choose1;
                ch2s = choose2;

                if (choose1 >= 0 && choose1 <= 3 && choose2 >= 0 && choose2 <= 3) {
                    break;
                }
            }
        }

        show(showField, SIZE, SIZE);

        for (short i = 0; i < SIZE; i++) {
            for (short j = 0; j < SIZE; j++) {
                if (showField[i][j] != field[i][j] && field[i][j] != '*') {
                    break;
                }
                if (i == SIZE - 1 && j == SIZE - 1) {
                    flag = false;
                }
            }
        }
    }

    if (hp == 0) {
        cout << endl << "You lost!";
    }
    else {
        cout << endl << "You won!";
    }

    return 0;
}
