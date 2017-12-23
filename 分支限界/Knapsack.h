#pragma once
#include <vector>
#include <queue>
class Knapsack
{
public:
	Knapsack(std::vector<int> &w, std::vector<int>& v, int r) :weight(w), value(v), capacity(r), num(w.size()),solve(num+1,false) {}
	void SearchforBest();
private:
	float bound(int deepth,node_info* node);
	struct node_info {
		float load_value;
		float load_weight;
		node_info(float v, float w) :load_value(v), load_weight(w) {}
	};
	node_info* next_level_flag =NULL;
	std::vector<int>weight;
	std::vector<int>value;
	int num;
	float capacity;
	float best_value;
	std::vector<bool> solve;
};

