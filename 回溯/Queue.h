#pragma once
#include <vector>

class Queue
{

public:
	Queue(int num) :method_num(0), queue_num(num), solve(num+1, 0) {}

	void backTrack(int deepth);
private:
    int method_num;
    int queue_num;
    std::vector<int>solve;
    bool judge(int place, int deepth);
};

