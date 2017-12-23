#pragma once
#include <iostream>
const int boardSize = 8;
extern int chess[boardSize][boardSize];
void coverChessBoard(int lrow,int lcolumn,int coverRow,int couverColunmn,int size);

void outputChessBoard();