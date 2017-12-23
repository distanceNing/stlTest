#include "MaxLoading.h"

int MaxLoading( std::vector<int>& w, int shipCap1, int shipCap2)
{
	Loading temp;
	temp.bestw = 0;
	temp.loadw = 0;
	temp.num = w.size();
	temp.solve = new bool[temp.num];
	temp.optSolve= new bool[temp.num];
	memset(temp.solve, false, sizeof(bool)*temp.num);
	temp.remainw = 0;
	for (int i = 0; i < w.size(); i++)
	{
		temp.remainw += w[i];
	}
	temp.weight = w;
	temp.shipCap1 = shipCap1;
	temp.shipCap2 = shipCap2;
	temp.backTrack(1);
		
	return temp.bestw;
}

void Loading::backTrack(int deepth)
{
	if (deepth > num)
	{
		if (loadw > bestw)
		{
			bestw = loadw;
			for (int i = 0; i < num; i++)
				optSolve[i] = solve[i];
		}
	}
	remainw -= weight[deepth - 1];
	if (loadw + weight[deepth-1] <= shipCap1)
	{
		solve[deepth-1] = true;
		loadw += weight[deepth-1];
		backTrack(deepth + 1);
		loadw-= weight[deepth-1];
	}
	if (loadw+remainw>bestw)
	{
		solve[deepth - 1] = false;
		backTrack(deepth + 1);
	}
	remainw += weight[deepth - 1];
}
