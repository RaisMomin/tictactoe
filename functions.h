#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

void PrintBoard(char board[3][3]);

void PrepBoard(char board[3][3]);

std::string GetChoice(char player);

bool CheckValid(char board[3][3], std::string pos, char player);

bool CheckWin(char board[3][3]);

bool CheckTie(char board[3][3]);

#endif