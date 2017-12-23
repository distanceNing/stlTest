#include <iostream>
using namespace std;
#include <vector>
#include "matrixMultiply.h"
#include"LCSLength.h"
#include "Knapsack.h"
#include "BinSearchTree.h"
int main()
{
	/*std::vector<int>test = { 2,3,5,4 };
	std::vector<int>value = { 3,5,6,5 };
	int size = test.size();
	int **solve = new int*[size];
	int cap = 5;
	for (int i = 0; i < size; i++)
	{
		*(solve + i) = new int[cap + 1];
	}
	Knapsack(test, value, size, cap, solve);
	outputOptPack(test, solve, cap ,size-1);*/
	/*
	vector<int>input1 = {30,35,15,5,10};
	vector<int>input2= { 30,35,15,30,35,15 ,5};
	int size1 = input1.size();
	int size2 = input2.size();
	int **value=new int*[size2+1];
	int **solve = new int*[size2 + 1];
	for (int i = 0; i < size2+1; i++)
	{
		*(value + i) = new int[size1 + 1];
		*(solve + i) = new int[size1 + 1];
	}
	for (int i = 1; i <= input1.size() ; i++)
	{
		for (int j = 1; j <= input1.size() - 1; j++)
			*(*(value + i) + j) = 0;
	}
	LCSLength(input1, input2, solve, value, input1.size(), input2.size());
	outputOptLength( input1, solve,value, input1.size(), input2.size());
*/

	vector<int>input1 = { 30,35,15,5,10,20,25};	
	int size1 = input1.size();
	int **value=new int*[size1];
	int **solve = new int*[size1];
	for (int i = 0; i < size1; i++)
	{
		*(value + i) = new int[size1];
		*(solve + i) = new int[size1];
	}
	for (int i = 0;i < size1;i++)
		memset(*(value + i), 0, size1*sizeof(int));
	matrixMultiply(input1, input1.size()-1, solve, value);
	outputOpt(input1.size() , solve, value);


	/*vector<double>input = { 0.22,0.18,0.2,0.05,0.25,0.02,0.08};
	int size = input.size();
	int **value = new int*[size+1];
	double **solve = new double*[size+1];
	for (int i = 0; i < size + 1; i++)
	{
		*(value + i) = new int[size+1];
		*(solve + i) = new double[size+1];
	}
	
	BinSearchTree(input,solve,value);*/
	return 0;
}