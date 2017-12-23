#include "LCSLength.h"
#include <iostream>
#include <stack>
void LCSLength(std::vector<int>& str1, std::vector<int>& str2, int ** solution, int ** value,int size1,int size2)
{
	for (int i = 0; i <= size1; i++)
	{
		value[0][i] = 0;
		solution[0][i] = 0;
	}
	for (int i = 0; i <= size2; i++)
	{
		value[i][0] = 0;
		solution[i][0] = 0;
	}

	for (int i = 1; i <=size2; i++)
	{
		for (int j = 1; j <=size1; j++)
		{
			//当两个字符串的最后一个字符一样时
			if (str2[i-1] == str1[j-1])
			{
				value[i][j] = value[i - 1][j - 1] + 1;
				solution[i][j] = 1;
			}
			else
			{
				//当不一样时，取
				if(value[i - 1][j] >value[i][j - 1])
				{
					value[i][j] = value[i - 1][j];
					solution[i][j] = 2;
				}
				else
				{
					value[i][j] = value[i][j - 1];
					solution[i][j] = 3;
				}
				
			}
		}
	}
}


void outputOptLength(std::vector<int>&str1, int **solution, int ** value, int size1, int size2)
{
	for (int i = 0; i <= size2; i++)
	{
		for (int j = 0; j <= size1; j++)
			std::cout << *(*(value + i) + j) << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i <= size2; i++)
	{
		for (int j = 0; j <= size1; j++)
			std::cout << *(*(solution + i) + j) << "\t";
		std::cout << std::endl;
	}

	std::cout << "Opt: "<< std::endl;

	std::stack<int>optStr;
	int nextx=size2,nexty=size1;
	for (int i = 0; i <= size1; i++)
	{
		
		if (solution[nextx][nexty] == 1)
		{
			optStr.push(str1[i - 1]);
			nextx -= 1;
			nexty -= 1;
		}
		if (solution[nextx][nexty] == 2)
			nextx -= 1;
		if (solution[nextx][nexty] == 3)
			nexty -= 1;

	}
	while (!optStr.empty())
	{
		std::cout << optStr.top() << "\t";
		optStr.pop();
	}
	
	for (int i = 0; i <= size2; i++)
	{
		delete[]*(value + i);
		delete[] *(solution + i);
	}
	delete[] value;
	delete[] solution;

}
