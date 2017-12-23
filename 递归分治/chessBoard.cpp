#include "chessBoard.h"



int chess[boardSize][boardSize];
int title = 1;

void coverChessBoard(int lrow, int lcolumn, int coverRow, int couverColunmn, int size)
{
	if (size == 1)
		return;
	int t = title++;
	int isize = size / 2;
	if (coverRow < lrow + isize&&couverColunmn < lcolumn + isize)  //вСио╫г
		coverChessBoard(lrow, lcolumn, coverRow, couverColunmn, isize);
	else
	{
		chess[lrow + isize - 1][lcolumn + isize - 1] = t;
		coverChessBoard(lrow, lcolumn, lrow + isize - 1, lcolumn + isize - 1, isize);
	}

	if (coverRow < lrow + isize&&couverColunmn >= lcolumn + isize)  //срио╫г
		coverChessBoard(lrow, lcolumn+isize, coverRow, couverColunmn, isize);
	else
	{
		chess[lrow + isize - 1][lcolumn + isize] = t;
		coverChessBoard(lrow, lcolumn + isize, lrow + isize - 1, lcolumn + isize , isize);
	}

	if (coverRow >= lrow + isize&&couverColunmn < lcolumn + isize)  //вСоб╫г
		coverChessBoard(lrow+isize, lcolumn, coverRow, couverColunmn, isize);
	else
	{
		chess[lrow + isize][lcolumn + isize - 1] = t;
		coverChessBoard(lrow + isize, lcolumn, lrow + isize, lcolumn + isize - 1, isize);
	}

	if (coverRow >=lrow + isize&&couverColunmn >= lcolumn + isize)  //сроб╫г
		coverChessBoard(lrow+isize, lcolumn + isize, coverRow, couverColunmn, isize);
	else
	{
		chess[lrow + isize ][lcolumn + isize] = t;
		coverChessBoard(lrow+isize, lcolumn + isize, lrow + isize , lcolumn + isize, isize);
	}
}

void outputChessBoard()
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			std::cout << chess[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
