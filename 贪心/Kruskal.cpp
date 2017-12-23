#include "Kruskal.h"


void sortEdge()
{
	int i = 0, j = 0;
	int m = 0;
	edgeInfo* temp;
	int size = edge.size();
	while (i <size)
	{
		j = i + 1;
		m = i;
		for (j; j < size; j++)
		{
			if (edge[j]->cost < edge[m]->cost)
				m = j;
		}
		if (m != i)
		{
			temp = edge[i];
			edge[i] = edge[m];
			edge[m] = temp;
		}
		i++;
	}
}

void Kruskal(std::vector<edgeInfo*>edges, int graphSize)  //graph为图中点的个数
{
	sortEdge();
	std::vector<int>result;
	int count = 1;

	int* setFlag = new int[graphSize];
	for (int i = 0; i < graphSize; i++)
		setFlag[i] = i;
	
	
	for (int i = 0; i<edge.size() ;i++)
	{
		if ((setFlag[edge[i]->end] != setFlag[edge[i]->start]))  //判断起点和终点是否连通
		{
			for (int j = 0; j < graphSize; j++)
			{	
				if (setFlag[j] == setFlag[edge[i]->end])
					setFlag[j] = setFlag[edge[i]->start];
			}
			setFlag[edge[i]->end] = setFlag[edge[i]->start];
			result.push_back(i);
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << "Edge: " <<edge[result[i]]->start << "--" << edge[result[i]]->end << "  cost: " << edge[result[i]]->cost<< std::endl;
	}
}
