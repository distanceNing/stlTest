#include "Knapsack.h"

void Knapsack::SearchforBest()
{
	std::queue<node_info*> work_queue;
	int deepth=0;
	work_queue.push(next_level_flag);
	node_info *work_node=new node_info(0,0);
	while (true)
	{
		//���������� 	
		if (weight[deepth] + work_node->load_weight <= capacity)
		{
			//solve[deepth - 1] = true;
			if (work_node->load_value + value[deepth] > best_value)
			{
				best_value = work_node->load_value + value[deepth];
			}
			work_queue.push(new node_info(work_node->load_value + value[deepth], work_node->load_weight + weight[deepth]));
		}
		if(bound(deepth+1,work_node)>best_value)
			work_queue.push(new node_info(work_node->load_value,work_node->load_weight));
		delete work_node;
		work_node= work_queue.front();
		work_queue.pop();
		if (work_node == next_level_flag)
		{
			//������Ϊ�յ�ʱ���˳�ѭ��
			if (work_queue.empty())
				return;
			//������һ��
			deepth++;
			work_queue.push(next_level_flag);
			work_node = work_queue.front();
			work_queue.pop();
		}
	}

}


float Knapsack::bound(int deepth, node_info* node)
{
	if (deepth >= num)
		return node->load_value;
	float ret = 0;
	int maxw = capacity - node->load_weight;
	while (deepth < num && maxw >= weight[deepth])
	{
		ret += value[deepth];
		maxw -= weight[deepth];
		deepth++;
	}

	if (maxw > 0)
	{
		ret += ((float)value[deepth] / weight[deepth])*maxw;
	}

	return ret + node->load_value;
}