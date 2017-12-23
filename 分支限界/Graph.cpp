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
	std::set<std::vector<int>> workSpace;      //工作集合 用以保存当前产生的路径
	std::vector<int> path;
	path.push_back(0);						   //path[0] 保存的是路径的权值 
	path.push_back(Start);					   //将起点复制给path
	workSpace.insert(path);                    //将初始路径放入集合中
	std::vector<int> temp;                     //临时变量

	int flag[maxGraphData];   //标记数组
	memset(flag, 0, sizeof(int)*maxGraphData);
	for (i = 0; i < demand.size(); i++)
		flag[demand[i]] = 1;           //对必经点进行标记

	count = 0;
	while (count<10000)
	{
		if (workSpace.empty())
			break;
		count++;
		temp = *workSpace.begin();
		workSpace.erase(workSpace.begin());
		if (temp.back() == End&&temp[0]<optima_cost)					//判断路径满足是否终点的要求
		{
			j = 0;
			for (i = 2; i < temp.size(); i++)							//判断路径是否满足所有的必经点
			{
				if (flag[temp[i]] == 1)
					j++;
			}
			if (j == demand.size())									  //若满足，则退出循环返回出最终结果
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
			//以取出来的路径，最后一个点作为临时起点，寻找下一个点，
			//以临时起点为下标，遍历该向量，也就是找到以该点作为起点，所有的下一个终点
			for (i = 0; i <graphData[temp.back()].size(); i++)
			{
				path = temp;
				value = graphData[temp.back()][i];
				nextPoint = value % 1024;             //反解出下个点以及权值
				cost = value / 1024;
				for (k = 1; k< path.size(); k++)      //判断下个点是否在已生成的路径之中，防止生成回环
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