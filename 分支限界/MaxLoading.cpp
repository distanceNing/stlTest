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
		//������
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

		//������   �ж��Ͻ�ֵ  �����ҽڵ�  
		if (bound(deepth)+load_weight>best_weight)
		{
			methods[++method_count] = solve;
			methods[method_count][deepth] = 0;
			methods[method_count][0] = deepth+1;
			node_info = load_weight << 10;
			work_queue.InsertNode(node_info + method_count);
		}
		//���ȡ���Ľڵ��Ѿ�������Ҷ�ڵ㣬������� 
		//ȡ����ǰ������������û��������Ҷ�ڵ�Ľڵ��������
		do
		{
			max_node = work_queue.DeleteMaxNode();   //ȡ����ǰ�����е����������Ľڵ�
			method_num = max_node % 1024;		     //ȡ����չ�ڵ�Ľ������
			deepth = methods[method_num][0];		 //ȡ����չ�ڵ����Ӽ����е����	 
		} while (deepth > num&&!work_queue.IsEmpty());

		if (work_queue.IsEmpty())
			return;
		load_weight = max_node / 1024;			 //ȡ����չ�ڵ��װ������			
		solve = methods[method_num];			 //ȡ���������
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
