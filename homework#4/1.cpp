#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");

    short cpuChoice, userChoice, userScore = 0, cpuScore = 0;

    while ((userScore < 5 && cpuScore < 5)) {
        cpuChoice = 1 + rand() % 3;
        cout << "Choose 1-Rock, 2-Scissors, 3-Paper: ";
        cin >> userChoice;
        while ((userChoice < 1 && userChoice > 3)) {
            cout << "Unknown argument!" << endl << "Choose 1-Rock, 2-Scissors, 3-Paper: ";
            cin >> userChoice;
        }
        if (userChoice == 1 && cpuChoice == 2) {
            userScore++;
            cout << "You Won!" << endl << "CPU - " << cpuScore << endl << "You - " << userScore << endl << endl;
        }
        else if (userChoice == 1 && cpuChoice == 3) {
            cpuScore++;
            cout << "CPU Won!" << endl << "CPU - " << cpuScore << endl << "You - " << userScore << endl << endl;
        }
        else if (userChoice == 2 && cpuChoice == 1) {
            cpuScore++;
            cout << "CPU Won!" << endl << "CPU - " << cpuScore << endl << "You - " << userScore << endl << endl;
        }
        else if (userChoice == 2 && cpuChoice == 3) {
            userScore++;
            cout << "You Won!" << endl << "CPU - " << cpuScore << endl << "You - " << userScore << endl << endl;
        }
        else if (userChoice == 3 && cpuChoice == 1) {
            userScore++;
            cout << "You Won!" << endl << "CPU - " << cpuScore << endl << "You - " << userScore << endl << endl;
        }
        else if (userChoice == 3 && cpuChoice == 2) {
            cpuScore++;
            cout << "CPU Won!" << endl << "CPU - " << cpuScore << endl << "You - " << userScore << endl << endl;
        }
        else {
            cout << "Draw!" << endl << endl;
        }
    }

    cout << ((userScore > cpuScore) ? "You" : "CPU") << " won the game!";

    return 0;
}
