#include "FlowShop.h"
void swap(std::vector<int>& elements, int x, int y)
{
	if (x != y)
	{
		int temp = elements[x];
		elements[x] = elements[y];
		elements[y] = temp;
	}

}

void FlowShop::backTrack(int deepth)
{
	if (deepth > num)
	{
		for (int i = 1;i <= num;i++)
			optSolve[i] = solve[i];
		best_value = value;
		return;
	}
	for (int i = deepth;i <= num;i++)
	{
		time1 += machine1[solve[i]];
		if (time1>time2[deepth - 1])
			time2[deepth] = time1 + machine2[solve[i]];
		else
			time2[deepth] = machine2[solve[i]] + time2[deepth - 1];
		value+= time2[deepth];
		if (value < best_value)
		{
			swap(solve, i, deepth);
			backTrack(deepth + 1);
			swap(solve, i, deepth);
		}
		value -= time2[deepth];
		time1 -= machine1[solve[i]];
	}
}
