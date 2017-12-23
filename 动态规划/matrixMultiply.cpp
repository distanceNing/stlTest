#include "matrixMultiply.h"




const int INF = 0x7fffffff;
void matrixMultiply(std::vector<int> &input,int num, int ** solution, int ** value)
{
	int left, right,temp;
	for (left =1; left <= num; left++)
	{
		value[left][left] = 0;
	}
	for (int i = 2; i <=num ; i++)
	{
		for (left = 1; left <= num - i+1; left++)
		{
			right = left + i-1;
			value[left][right] =INF;
			for (int k = left; k < right; k++)
			{
			    temp = value[left][k] + value[k + 1][right] + input[left - 1] * input[k]*input[right];
				if (temp < value[left][right])
				{
					value[left][right] = temp;
					solution[left][right] = k;
				}
			}
		}

	}
}

void outputOpt(int num, int ** solution, int ** value)
{
	for (int i = 1; i <num; i++)
	{
		for (int j = 1; j < num; j++)
			std::cout << *(*(value + i) + j) << "\t";
		std::cout << std::endl;
	}
}
