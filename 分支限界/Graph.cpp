#include "Graph.h"



Graph::Graph(const char* const filename)
{
	char str[15];
	char *temp;
	int count = 0;
	int  start, end, cost;
	std::ifstream f;
	f.open(filename);
	char *next_token = NULL;
	while (f.getline(str, 15))
	{
		temp = strtok_s(str, ",",&next_token);
		while (temp)
		{
			switch (count)
			{
			case 0:
				start = atoi(temp);
				break;
			case 1:
				end = atoi(temp);
				break;
			case 2:
				cost = atoi(temp);
				break;
			default:
				break;
			}
			count++;
			temp = strtok_s(NULL, ",", &next_token);
		}
		count = 0;
		graphData[start].push_back(cost * 1024 + end);
	}
	optima_cost = 0xffffff;
}
void Graph::find_optimal_path()
{

	int i, j, k, count;
	int cost, value;
	int nextPoint;
	std::set<std::vector<int>> workSpace;      //�������� ���Ա��浱ǰ������·��
	std::vector<int> path;
	path.push_back(0);						   //path[0] �������·����Ȩֵ 
	path.push_back(Start);					   //����㸴�Ƹ�path
	workSpace.insert(path);                    //����ʼ·�����뼯����
	std::vector<int> temp;                     //��ʱ����

	int flag[maxGraphData];   //�������
	memset(flag, 0, sizeof(int)*maxGraphData);
	for (i = 0; i < demand.size(); i++)
		flag[demand[i]] = 1;           //�Աؾ�����б��

	count = 0;
	while (count<10000)
	{
		if (workSpace.empty())
			break;
		count++;
		temp = *workSpace.begin();
		workSpace.erase(workSpace.begin());
		if (temp.back() == End&&temp[0]<optima_cost)					//�ж�·�������Ƿ��յ��Ҫ��
		{
			j = 0;
			for (i = 2; i < temp.size(); i++)							//�ж�·���Ƿ��������еıؾ���
			{
				if (flag[temp[i]] == 1)
					j++;
			}
			if (j == demand.size())									  //�����㣬���˳�ѭ�����س����ս��
			{
				if (!optimalPath.empty())
					optimalPath.clear();
				for (int i = 0; i < temp.size(); i++)
				{
					optimalPath.push_back(temp[i]);
				}
				optima_cost = optimalPath[0];
			}
		}
		else
		{
			//��ȡ������·�������һ������Ϊ��ʱ��㣬Ѱ����һ���㣬
			//����ʱ���Ϊ�±꣬������������Ҳ�����ҵ��Ըõ���Ϊ��㣬���е���һ���յ�
			for (i = 0; i <graphData[temp.back()].size(); i++)
			{
				path = temp;
				value = graphData[temp.back()][i];
				nextPoint = value % 1024;             //������¸����Լ�Ȩֵ
				cost = value / 1024;
				for (k = 1; k< path.size(); k++)      //�ж��¸����Ƿ��������ɵ�·��֮�У���ֹ���ɻػ�
				{
					if (nextPoint == path[k])
						break;
				}
				if (k == path.size())
				{
					path[0] += cost;
					path.push_back(nextPoint);
					workSpace.insert(path);
				}
			}
		}
	}

}

void Graph::input_demand(int start,int end,std::vector<int>& data)
{
	Start = start;
	End = end;
	if (!demand.empty())
		demand.clear();
	for (int i = 0; i < data.size(); i++)
	{
		demand.push_back(data[i]);
	}
}