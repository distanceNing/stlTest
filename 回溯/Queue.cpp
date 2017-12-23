#include "Queue.h"

bool Queue::judge(int place,int deepth)
{
	for (int i = 1;i < deepth;i++)
	{
		if (place == solve[i] || (abs(deepth - i) == abs(place - solve[i])))
			return false;
	}
	return true;
}

void Queue::backTrack(int deepth)
{
	if (deepth > queue_num)
	{
		method_num++;
		return;
	}
	for (int i = 1;i <= queue_num;i++)
	{
		if (judge(i, deepth))
		{
			solve[deepth] = i;
			backTrack(deepth+1);
		}
	}
	
}
