#include <iostream>
#include "functions.h"
#include <string>
#include <limits>

using namespace std;

void PrintBoard(char board[3][3]) {
    cout << endl;
    cout << "    1   2   3 " << endl;
    cout << "A   " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
    cout << "   ———|———|———" << endl;
    cout << "B   " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
    cout << "   ———|———|———" << endl;
    cout << "C   " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;
}

void PrepBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

std::string GetChoice(char player) {
    std::string choice;
    cout << endl << "Player " << player << ", choose an empty position (ex: A1): ";
    cin >> choice;
    while (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input, choose an empty position (ex: A1): ";
        cin >> choice;
    }
    return choice;
}

bool CheckValid(char board[3][3], std::string pos, char player) {
    int row;
    int col;
    if (pos.size() != 2) {
        cout << "Position should consist of one letter and one number (ex: A1)." << endl;
        return false;
    }
    switch (pos.at(0)) {
        case 'A':
        case 'a':
        row = 0;
        break;

        case 'B':
        case 'b':
        row = 1;
        break;

        case 'C':
        case 'c':
        row = 2;
        break;

        default:
        cout << "Invalid letter for row." << endl;
        return false;

    }
    switch (pos.at(1)) {
        case '1':
        col = 0;
        break;

        case '2':
        col = 1;
        break;

        case '3':
        col = 2;
        break;

        default:
        cout << "Invalid number for column." << endl;
        return false;

    }
    if (board[row][col] != ' ') {
        cout << "Chosen position is not empty." << endl;
        return false;
    }

    board[row][col] = player;
    return true;
}

bool CheckWin(char board[3][3]) {
    if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != ' ') {
        return true;
    }
    if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != ' ') {
        return true;
    }
    if (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != ' ') {
        return true;
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') {
        return true;
    }
    return false;
}

bool CheckTie(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}