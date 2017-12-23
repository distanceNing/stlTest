#include "BinSearchTree.h"
void BinSearchTree(std::vector<double> elements, double ** solution, int ** optTree)
{
	int size = elements.size();
	for (int i = 0; i <= size; i++)  //���������Ϊ0ʱ������Ϊ0.
		solution[0][i] = 0;
	for (int i = 1;i<=size; i++)  //���������Ϊ1ʱ������Ϊ��ǰ����Ȩ�ء�
	{
		solution[1][i] = elements[i-1];
		optTree[1][i] = i;
	}
	double minCost=0;
	for (int num = 2; num <=size; num++)
	{
		for (int left = 1; left <=size- num+1; left++)
		{
			minCost = 0;
			for (int i = left-1; i < num + left-1; i++)      //����ȫ������Ȩ��
				minCost += elements[i];
			solution[num][left] = solution[num - 1][left + 1]+minCost;
			for (int root = left+1; root <= left + num-1; root++)
			{
				double cost = minCost;
				cost += solution[root-left][left] + solution[left+num-root-1][root+1];   
				if (solution[num][left] > cost)
				{
					solution[num][left] = cost;
					optTree[num][left] = root;
				}
			}
		}
	}
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size-i+1; j++)
			std::cout << *(*(solution + i) + j) << "\t";
		std::cout << std::endl;
	}


}
