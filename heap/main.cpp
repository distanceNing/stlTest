#include <iostream>
using namespace std;
#include <stdlib.h>
#include "yn_heap.h"
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 66, 888, 99, 44, 44 };
	ynstl::BinHeap<int> test;
	
	test.makeHeap(a, 10);
	
	while (!test.empty()){
		std::cout << test.min() << "\t";
	}
	

	system("pause");
	return 0;
}