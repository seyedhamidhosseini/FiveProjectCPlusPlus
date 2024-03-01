#include <iostream>
using namespace std;

int main() {
    int player1_choice, player2_choice;

    cout << "Player 1, choose (1 for scissors, 2 for rock, 3 for paper): ";
    cin >> player1_choice;

    cout << "Player 2, choose (1 for scissors, 2 for rock, 3 for paper): ";
    cin >> player2_choice;

    int result;

    if (player1_choice == player2_choice)
        result = 0; // Tie

    else if ((player1_choice == 1 && player2_choice == 3)
        || (player1_choice == 2 && player2_choice == 1)
        || (player1_choice == 2 && player2_choice == 3))

        result = 1; // Player 1 wins

    else if((player1_choice == 3 && player2_choice == 1)
            || (player1_choice == 1 && player2_choice == 2)
            || (player1_choice == 3 && player2_choice == 2))
        result = 2; // Player 2 wins

    switch(result) {
        case 0:
            cout << "It's a tie!" << endl;
            break;
        case 1:
            cout << "Player 1 is the winner." << endl;
            break;
        case 2:
            cout << "Player 2 is the winner." << endl;
            break;
        default:
            cout << "Error! Invalid result." << endl;
            break;
    }
    return 0;
}
