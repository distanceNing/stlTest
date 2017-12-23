#include "Knapsack.h"



void Knapsack(std::vector<int> weight, std::vector<int> value, int num, int capacity, int ** solution)
{
	for (int i = 0; i < num; i++)
		solution[i][0] = 0;
	for (int i = 0; i <= capacity; i++)
	{
		if (weight[0] <= i)
			solution[0][i] = value[0];
		else
			solution[0][i] = 0;
	}

	for (int i = 1;i < num;i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			//��ǰ��Ʒ�������ڱ�������������ǰһ����Ʒ����Ϊjʱ�ļ�ֵ
			if (weight[i] > j)  
			{
				solution[i][j] = solution[i - 1][j];
			}
			else
			{
			//��װ��ʱװ�뵱ǰ��Ʒ������ֵ����ǰһ����Ʒ������ֵȡ�ϴ��ߡ�
				solution[i][j] = fmax(solution[i - 1][j], solution[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
}

void outputOptPack(std::vector<int>&str1, int **solution,  int size1, int size2)
{
	std::cout << "Opt: " << std::endl;

	for (int i = 0; i <= size2; i++)
	{
		for (int j = 0; j <= size1; j++)
			std::cout << *(*(solution + i) + j) << "\t";
		std::cout << std::endl;
	}
	for (int i = 0; i <= size2; i++)
	{
		delete[] * (solution + i);
	}	
	delete[] solution;

}