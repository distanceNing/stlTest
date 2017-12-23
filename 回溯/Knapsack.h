#pragma once
#include <vector>
class Knapsack
{
	std::vector<int>weight;
	std::vector<int>value;
	int num;
	float capacity;
	float best_value;
	float loadw;
	float remainw;     //Ê£Óà±³°üÈÝÁ¿
	float load_value;
	std::vector<bool>optSolve;
	std::vector<bool>solve;
public:
	Knapsack(std::vector<int> &w, std::vector<int>& v, int r) :weight(w), value(v), capacity(r), num(w.size()),loadw(0),solve(num,false),optSolve(num,false),remainw(r), load_value(0){}
	void backTrack(int deepth);
	float bound(int deepth);

};

