#include <iostream>
#include "functions.h"
#include <string>

using namespace std;

int main() {

    char board[3][3];
    string play = "y";
    bool win = false;
    char winner;
    string x_pos;
    string o_pos;
    cout << endl << "Welcome to Tic-Tac-Toe!" << endl;
    
    while (play == "yes" || play == "y") {
        PrepBoard(board);
        do {
            PrintBoard(board);
            do {
                x_pos = GetChoice('X');
            } while (!CheckValid(board, x_pos, 'X'));
            if(CheckWin(board)) {
                winner = 'X';
                break;
            }
            if(CheckTie(board)) {
                winner = 'T';
                break;
            }

            PrintBoard(board);
            do {
                o_pos = GetChoice('O');
            } while (!CheckValid(board, o_pos, 'O'));
            if(CheckWin(board)) {
                winner = 'O';
                break;
            }
            if(CheckTie(board)) {
                winner = 'T';
                break;
            }

        } while (!win);

        PrintBoard(board);
        if (winner == 'X' || winner == 'O') {
            cout << endl << "Player " << winner << " wins!" << endl;
        }
        else {
            cout << endl << "Tie game!" << endl;
        }
        cout << "Play again? (y/n): ";
        cin >> play;
        cout << endl;
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}