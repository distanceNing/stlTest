#pragma once
#include <fstream>
#include <vector>
#include <set>
#define maxGraphData 50
class Graph
{
public:
	Graph(const char* const);
	void  find_optimal_path();
	void input_demand(int start, int end, std::vector<int> &data);

private:
	int Start, End;
	std::vector<int>demand;						 //保存必经点的信息
	std::vector<int> optimalPath;				 //保存最优路径
	std::vector<int> graphData[maxGraphData];	 //用以保存图的信息，下标表示起点，高22bit用以保存权值，低10bit用以保存终点
	int optima_cost;

};
