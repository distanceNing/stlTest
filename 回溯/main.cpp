#include <iostream>
#include <vector>
#include "MaxLoading.h"
#include "Knapsack.h"

#include "Queue.h"
#include "FlowShop.h"
#pragma   warning(disable:4996)
int main()
{
	/*std::vector<int>test= {10,40,40};
	int w=MaxLoading(test, 50, 50);*/


	//std::vector<int> w = {2,2,4,6,5,};
	//std::vector<int> v = { 6,3,6,5,4 };
	//Knapsack test(w, v, 10);
	//test.backTrack(1);

	

	//Queue test(4);
	//test.backTrack(1);

	std::vector<int>m1 = {0,2,3,2};
	std::vector<int>m2 = {0, 1,1,3 };
	FlowShop test(m1.size()-1, m1, m2);
	test.backTrack(1);

	return 0;
}