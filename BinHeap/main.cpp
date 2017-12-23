#include <iostream>
using namespace std;
#include <stdlib.h>
#include "BinHeap.h"
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 66, 888, 99, 44, 44 };
	BinHeap<int> test;
	
	test.BuildHeap(a, 10);
	
   
	test.TravelBinHeap();
	cout << "the min element :"<<test.DeleteBinHeapMinNode() << endl;
	
	system("pause");
	return 0;
}