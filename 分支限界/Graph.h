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
	std::vector<int>demand;						 //����ؾ������Ϣ
	std::vector<int> optimalPath;				 //��������·��
	std::vector<int> graphData[maxGraphData];	 //���Ա���ͼ����Ϣ���±��ʾ��㣬��22bit���Ա���Ȩֵ����10bit���Ա����յ�
	int optima_cost;

};
