#include "MaxLoading.h"

void MaxLoading::SearchforBest()
{
	BinHeap<int>work_queue;
	work_queue.InsertNode(0);
	int deepth = 1;
	int load_weight = 0;
	int method_count=0;
	int method_num=1 ;
	int node_info=0;
	int max_node=0;
	std::vector<int>solve=methods[0];
	while (true)
	{	
		//左子树
		if (weight[deepth] + load_weight<= shipCap1)
		{			
			methods[++method_count] = solve;
			methods[method_count][deepth] = 1;
			methods[method_count][0] = deepth+1;
			node_info = (load_weight + weight[deepth]) << 10;
			work_queue.InsertNode(node_info + method_count);
			if (weight[deepth] + load_weight >best_weight)
			{
				optSolve = method_count;
				best_weight = weight[deepth] + load_weight;
			}
		}

		//右子树   判断上界值  加入右节点  
		if (bound(deepth)+load_weight>best_weight)
		{
			methods[++method_count] = solve;
			methods[method_count][deepth] = 0;
			methods[method_count][0] = deepth+1;
			node_info = load_weight << 10;
			work_queue.InsertNode(node_info + method_count);
		}
		//如果取出的节点已经搜索到叶节点，则放弃。 
		//取出当前队列中最优且没有搜索到叶节点的节点继续搜索
		do
		{
			max_node = work_queue.DeleteMaxNode();   //取出当前队列中的载重量最大的节点
			method_num = max_node % 1024;		     //取出扩展节点的解决方法
			deepth = methods[method_num][0];		 //取出扩展节点在子集树中的深度	 
		} while (deepth > num&&!work_queue.IsEmpty());

		if (work_queue.IsEmpty())
			return;
		load_weight = max_node / 1024;			 //取出扩展节点的装载质量			
		solve = methods[method_num];			 //取出解决方法
	}
}

int MaxLoading::bound(int deepth)
{
	int ret = 0;
	while (++deepth <= num)
	{
		ret += weight[deepth];
	}
	return ret;
}
