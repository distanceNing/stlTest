#include "Knapsack.h"






void Knapsack::backTrack(int deepth)
{
	if (deepth > num)
	{
		if (load_value > best_value)
		{
			best_value = load_value;
			for (int i = 0; i < num; i++)
				optSolve[i] = solve[i];
		}
		return;

	}

	if (loadw + weight[deepth - 1] <= capacity)  //进入左子树
	{
		solve[deepth - 1] = true;
		loadw += weight[deepth - 1];
		load_value += value[deepth - 1];
		backTrack(deepth + 1);
		loadw -= weight[deepth - 1];
		load_value -= value[deepth - 1];
	}
	//进入右子树
	if(bound(deepth)>best_value)
	{
		solve[deepth - 1] = false;
		backTrack(deepth + 1);
	}
	
	
	
}

float Knapsack::bound(int deepth)
{
	if (deepth >= num)
		return load_value;
	float ret=0;
	int maxw=capacity-loadw;
	while (deepth < num && maxw>= weight[deepth])
	{
		ret += value[deepth];
		maxw -= weight[deepth];
		deepth++;
	}

	if (maxw > 0)
	{
		ret += ((float)value[deepth] / weight[deepth])*maxw;
	}

	return ret+load_value;
}

