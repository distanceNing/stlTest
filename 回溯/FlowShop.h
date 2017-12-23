#pragma once
#include <vector>
const unsigned int INF = 0xFFFF;
class FlowShop
{
	int best_value;
	int value;
	int num;
	std::vector<int>optSolve;
	std::vector<int>solve;
	std::vector<int>machine1;
	std::vector<int>machine2;
	std::vector<int>time2;
	int time1;
public:
	FlowShop(int n,std::vector<int>&m1, std::vector<int>&m2):best_value(INF),value(0),num(n),machine1(m1),machine2(m2),optSolve(n+1,0),time2(n+1,0),time1(0) {
		for (int i = 0;i <= n;i++)
			solve.push_back(i);
	}
	void backTrack(int deepth);
};

