#include <vector>
#include "BinHeap.h"
class MaxLoading
{
private:
	int best_weight;
	std::vector<int>weight;	
	int shipCap1;
	int shipCap2;
	int num;
	int optSolve;				//记录最有的解决方法在methods中的下标
	std::vector < std::vector < int >>methods;
public:
	MaxLoading(int n, int cap1, int cap2, const std::vector<int>&w) :weight(w), num(n), shipCap1(cap1), shipCap2(cap2),methods(pow(2,num),std::vector<int>(num+1,0)){	}
	void SearchforBest();
	int bound(int deepth);

};

