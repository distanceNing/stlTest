#include<iostream>
//#include "perm.h"
#include "divideInteger.h"
#include "BinSearsh.h"
#include "chessBoard.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "roundRobin.h"
#include <vector>
#include "IntegerMulti.h"

int main()
{
	//std::vector<int>test = {1,2, 3,4,54};
	////quickSort(test, 0, test.size() - 1);
	////mergeSort(test, 0, test.size() - 1);
	////int index=recurBinSearsh(test, 0, test.size() - 1, 3);
	////perm(test, test.size() - 1,0);
	int num=divideInteger(6, 6);
	std::vector<int>result;
	outputDivideInteger(7, 6, result);
	/*coverChessBoard(0, 0, 0, 1, boardSize);
	outputChessBoard();*/

	//int sport[8][8];
	//roundRobin(athleteNum, sport);
	//int result = IntegerMulti(1320, 1030);
	return 0;
} 

