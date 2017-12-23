#pragma once
#include <vector>
struct Loading
{
	int bestw;
	std::vector<int>weight;
	bool* solve;
	int shipCap1;
	int shipCap2;
	int loadw;
	int num;
	bool* optSolve;
	int remainw;
	friend int MaxLoading(std::vector<int>&w, int c1, int c2);
	void backTrack(int deepth);
	~Loading()
	{
		delete[]optSolve;
		delete[]solve;
	}
};

	
