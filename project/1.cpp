#include <iostream>
#define rand(a, b) a + rand() % (b - a + 1)
using namespace std;

void showField(string** field, const int size1, const int size2) {
    system("cls");
    cout << '\t';
    for (int i = 0, k = 0; i < size2; i++) {
        if (i == 6) {
            cout << ' ' << '\t';
        }
        cout << char(65 + k++) << '\t';
    }
    cout << endl;
    for (int i = 0; i < size1; i++) {
        if (i == 0)
            cout << "1\t";
        else if (i == size1 - 1)
            cout << "2\t";
        else
            cout << " \t";
        for (int j = 0; j < size2; j++) {
            if (j == 6) {
                cout << "|\t";
            }
            cout << field[i][j] << '\t';
        }
        cout << endl;
    }
}

//defines who will go first
bool firstMove() {
    short g1 = rand(1, 6), g2 = rand(1, 6), \
        r1 = rand(1, 6), r2 = rand(1, 6);
    cout << "Green threw dice: " << g1 << ' ' << g2 << endl;
    cout << "Red threw dice: " << r1 << ' ' << r2 << endl;
    if (g1 + g2 > r1 + r2) {
        cout << "Green goes first!" << endl;
        system("pause");
        return true;
    }
    else if (r1 + r2 > g1 + g2) {
        cout << "Red goes first!" << endl;
        system("pause");
        return false;
    }
    else {
        cout << "Tie! Throwing again..." << endl;
        system("pause");
        return firstMove();
    }
}

//checks if someone won
bool checkWin(string** withdrawnField, const int withdrawnSize2, bool showWinMessage = true) {
    if (withdrawnField[0][withdrawnSize2 - 1] == "\x1B[32m*\033[0m") {
        cout << "Green won!" << endl;
        return true;
    }
    else if (withdrawnField[1][withdrawnSize2 - 1] == "\x1B[31m*\033[0m") {
        cout << "Red won!" << endl;
        return true;
    }
    return false;
}

//checks if a user can make moves that they have
bool checkMoves(string** field, const int size1, const int size2, int* moves, bool greenMove, bool* tookFromStart) {
    short movesAmt = _msize(moves) / sizeof(moves[0]);
    bool ismoves = false;
    for (short j = 0; j < movesAmt; j++) {
        for (int i = 11; i >= 0; i--) {
            if (i == 11 && field[0][11] == "\x1B[31m*\033[0m" && tookFromStart[0] && tookFromStart[1]) {
                continue;
            }
            if (field[0][i] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                if (moves[j] > i) {
                    int move0 = moves[j] - i;
                    if (field[29][move0] == " " || field[29][move0] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                        ismoves = true;
                    }
                }
                else {
                    if (field[0][i - moves[j]] == " " || field[0][i - moves[j]] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                        ismoves = true;
                    }
                }
            }
        }
        for (int i = 0; i < 12; i++) {
            if (i == 0 && field[29][0] == "\x1B[31m*\033[0m" && tookFromStart[0] && tookFromStart[1]) {
                continue;
            }
            if (field[29][i] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                if (moves[j] > 12 - i) {
                    int move0 = moves[j] - (12 - i);
                    if (field[0][12 - move0] == " " || field[0][12 - move0] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                        ismoves = true;
                    }
                }
                else {
                    if (field[29][i + moves[j]] == " " || field[29][i + moves[j]] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                        ismoves = true;
                    }
                }
            }
        }
    }
    return ismoves;
}

//checks if a user can make moves that they have with the selected piece
bool checkPieceMoves(string** field, const int size1, const int size2, int* coords, int* moves, bool greenMove, bool* tookFromStart) {
    short movesAmt = _msize(moves) / sizeof(moves[0]);
    bool ismoves = false;
    if (((coords[0] == 29 && coords[1] == 0) || (coords[0] == 0 && coords[1] == 11)) && (tookFromStart[0] && tookFromStart[1])) {
        return false;
    }
    for (short j = 0; j < movesAmt; j++) {
        if (coords[0] == 0 && field[0][coords[1]] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
            if (moves[j] > coords[1]) {
                int move0 = moves[j] - coords[1];
                if (field[29][move0] == " " || field[29][move0] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                    ismoves = true;
                }
            }
            else {
                if (field[0][coords[1] - moves[j]] == " " || field[0][coords[1] - moves[j]] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                    ismoves = true;
                }
            }
        }
        if (coords[0] == 29 && field[29][coords[1]] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
            if (moves[j] <= coords[1]) {
                int move0 = moves[j] - (12 - coords[1]);
                if (field[0][12 - move0] == " " || field[0][12 - move0] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                    ismoves = true;
                }
            }
            else {
                if (field[29][coords[1] + moves[j]] == " " || field[29][coords[1] + moves[j]] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                    ismoves = true;
                }
            }
        }
    }
    return ismoves;
}

int letterToIndex(char letter) {
    switch (letter) {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    case 'E':
        return 4;
    case 'F':
        return 5;
    case 'G':
        return 6;
    case 'H':
        return 7;
    case 'I':
        return 8;
    case 'J':
        return 9;
    case 'K':
        return 10;
    case 'L':
        return 11;
    default:
        return -1;
    }
}

int lengthBetweenCoords(int coords[]) {
    if (coords[0] > coords[2]) {
        return 12 - coords[1] + 12 - coords[3] - 1;
    }
    else if (coords[0] == coords[2]) {
        return (coords[3] > coords[1]) ? coords[3] - coords[1] : coords[1] - coords[3];
    }
    else {
        return coords[3] + coords[1] + 1;
    }
}

//checks if a user can go to the specified coordinates
bool canGo(string** field, bool greenMove, int coords[], int moves[], int movesLeft) {
    int len = lengthBetweenCoords(coords);
    for (int i = 0; i < movesLeft; i++) {
        if (len == moves[i] && (field[coords[2]][coords[3]] == " " || field[coords[2]][coords[3]] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m"))) {
            return true;
        }
    }
    return false;
}

//Checks for pieces outside withdraw area
bool piecesOutsideWithdrawArea(string** field, const int size1, const int size2, bool greenMove) {
    for (int i = 11; i >= ((greenMove) ? 0 : 6); i--) {
        if (field[0][i] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
            return true;
        }
    }
    for (int i = 0; i < ((greenMove) ? 6 : 12); i++) {
        if (field[29][i] == ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
            return true;
        }
    }
    return false;
}

//checks if a user can withdraw a piece
bool canWithdraw(string** field, const int size1, const int size2, int coords[], int moves[], int movesLeft, bool greenMove) {
    if (piecesOutsideWithdrawArea(field, size1, size2, greenMove))
        return false;
    int* lenCoords;
    if (greenMove) {
        lenCoords = new int[4] { coords[0], coords[1], 29, 14 };
    }
    else {
        lenCoords = new int[4] { coords[0], coords[1], 0, 0 };
    }
    for (int i = 0; i < movesLeft; i++) {
        if (lengthBetweenCoords(lenCoords) == moves[i]) {
            return true;
        }
    }
    return false;
}

//initiates a move
void move(string** field, const int size1, const int size2, bool &greenMove, bool* isFirstMove, string** withdrawnField, int withdrawnSize2) {
    int* moves = nullptr;
    int movesLeft, a;
    bool flag = false;
    char b;
    int coords[4] = {};
    bool* tookFromStart = nullptr;

    //dice throw
    cout << ((greenMove) ? "Greens" : "Reds") << " turn. Throwing dice..." << endl;
    system("pause");
    int d1 = rand(1, 6), d2 = rand(1, 6);
    cout << "Dice thrown: " << d1 << ' ' << d2 << endl;
    if (d1 == d2) {
        cout << "Doubles!" << endl;
        if (isFirstMove[((greenMove) ? 0 : 1)]) {
            switch (d1) {
            case 3:
                moves = new int[4] { d1, d1, d1, d1 };
                tookFromStart = new bool[2] { false, false };
                movesLeft = 4;
                break;
            case 4:
                moves = new int[4] { d1, d1, d1, d1 };
                tookFromStart = new bool[2] { false, false };
                movesLeft = 4;
                break;
            case 6:
                moves = new int[4] { d1, d1 };
                tookFromStart = new bool[2] { false, false };
                movesLeft = 2;
                break;
            default:
                tookFromStart = new bool[2] { false, true };
                movesLeft = 4;
                moves = new int[4] { d1, d1, d1, d1 };
                break;
            }
        }
        else {
            tookFromStart = new bool[2] { false, true };
            movesLeft = 4;
            moves = new int[4] { d1, d1, d1, d1 };
        }
    }
    else {
        tookFromStart = new bool[2] { false, true };
        movesLeft = 2;
        moves = new int[2] { d1, d2 };
    }

    isFirstMove[((greenMove) ? 0 : 1)] = false;

    //moves
    for (short i = 0; i < movesLeft; i++) {
        if (!checkMoves(field, size1, size2, moves, greenMove, tookFromStart)) {
            cout << "No moves left!" << endl;
            system("pause");
            break;
        }

        //selecting a piece
        while (!flag) {
            flag = true;
            cout << "Input coordinates of what piece to move(number letter): ";
            cin >> a >> b;
            if (a == 1) {
                coords[0] = 0;
            }
            else {
                coords[0] = 29;
            }
            coords[1] = letterToIndex(b);
            cout << coords[0] << ' ' << coords[1];
            if ((coords[0] != 0 && coords[0] != 29) || coords[1] == -1) {
                cout << "Incorrect coordinates!" << endl;
                flag = false;
                continue;
            }
            if (field[coords[0]][coords[1]] != ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                cout << "You cannot select this!" << endl;
                flag = false;
                continue;
            }
            if (!checkPieceMoves(field, size1, size2, new int[2] {coords[0], coords[1]}, moves, greenMove, tookFromStart)) {
                cout << "This piece cannot make the moves you have!" << endl;
                flag = false;
                continue;
            }
        }

        //highlighting the selected piece and saving coordinates
        int* selectedPieceCoords = new int[2];
        for (short i = 0; i < 16; i++) {
            if (field[(coords[0] == 0) ? coords[0] + i : coords[0] - i][coords[1]] != ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                field[(coords[0] == 0) ? coords[0] + i - 1 : coords[0] - i + 1][coords[1]] = ((greenMove) ? "\033[32;43m*\033[0;0m" : "\033[31;43m*\033[0;0m");
                selectedPieceCoords[0] = ((coords[0] == 0) ? coords[0] + i - 1 : coords[0] - i + 1);
                selectedPieceCoords[1] = coords[1];
                break;
            }
        }

        showField(field, size1, size2);
        flag = false;

        //selecting where to place the selected piece
        while (!flag) {
            flag = true;
            cout << "Input coordinates of where to move the selected piece(number letter or W W to withdraw): ";
            cin >> a >> b;
            if (b == 'W') { 
                if (!canWithdraw(field, size1, size2, coords, moves, movesLeft, greenMove)) {
                    cout << "You cannot withdraw this piece!" << endl;
                    flag = false;
                    continue;
                }
                coords[3] = 'W';
                continue;
            }
            if (a == 1) {
                coords[2] = 0;
            }
            else {
                coords[2] = 29;
            }
            coords[3] = letterToIndex(b);
            cout << coords[0] << ' ' << coords[1] << ' ' << coords[2] << ' ' << coords[3] << ' ' << lengthBetweenCoords(coords);
            if ((coords[2] != 0 && coords[2] != 29) || coords[3] == -1) {
                cout << "Incorrect coordinates!" << endl;
                flag = false;
                continue;
            }
            if (!canGo(field, greenMove, coords, moves, movesLeft)) {
                cout << "You cannot go here!" << endl;
                flag = false;
                continue;
            }
        }

        if (coords[3] == 'W') {
            //withdrawing the piece
            field[selectedPieceCoords[0]][selectedPieceCoords[1]] = (" ");
            for (short i = 0; i < 15; i++) {
                if (withdrawnField[((greenMove) ? 0 : 1)][i] == " ") {
                    withdrawnField[((greenMove) ? 0 : 1)][i] = ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m");
                    break;
                }
            }
        }
        else {
            //moving the piece
            field[selectedPieceCoords[0]][selectedPieceCoords[1]] = (" ");
            for (short i = 0; i < 16; i++) {
                if (field[(coords[2] == 0) ? coords[2] + i : coords[2] - i][coords[3]] != ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m")) {
                    field[(coords[2] == 0) ? coords[2] + i : coords[2] - i][coords[3]] = ((greenMove) ? "\x1B[32m*\033[0m" : "\x1B[31m*\033[0m");
                    break;
                }
            }
        }

        if ((coords[0] == 0 && coords[1] == 11) || (coords[0] == 29 && coords[1] == 0)) {
            tookFromStart[((tookFromStart[1]) ? 0 : 1)] = true;
        }

        showField(field, size1, size2);

        //checking if the user won after the move
        if (checkWin(withdrawnField, withdrawnSize2, false))
            break;

        flag = false;
    }
    
    greenMove = !greenMove;
}

int main()
{
    srand(time(NULL));

    //creating the field
    const int size1 = 30, size2 = 12;
    bool* isFirstMove = new bool[2] { true, true };
    string** field = new string * [size1];
    for (int i = 0; i < size1; i++) {
        field[i] = new string[12]{};
        for (int j = 0; j < size2; j++) {
            field[i][j] = " ";
        }
        if (i <= 14) {
            field[i][11] = "\x1B[32m*\033[0m";
        }
        else {
            field[i][0] = "\x1B[31m*\033[0m";
        }
    }

    //creating the withdrawn pieces array
    const int withdrawnSize1 = 2, withdrawnSize2 = 15;
    string** withdrawnField = new string * [withdrawnSize1];
    for (int i = 0; i < 2; i++) {
        withdrawnField[i] = new string[withdrawnSize2];
        for (int j = 0; j < withdrawnSize2; j++) {
            withdrawnField[i][j] = " ";
        }
    }

    showField(field, size1, size2);
    bool greenMove = firstMove();
    while (!checkWin(withdrawnField, withdrawnSize2)) {
        showField(field, size1, size2);
        move(field, size1, size2, greenMove, isFirstMove, withdrawnField, withdrawnSize2);
    }
    return 0;
}
