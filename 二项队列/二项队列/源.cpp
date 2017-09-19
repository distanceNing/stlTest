#include <iostream>
using namespace std;
#include "BinomialQueue.h"
#include <stdlib.h>
#include <math.h>
int main()
{
	
	//BinomaialQueue test1;
	BinomaialQueue test;
	test.InsertQueue(1);
	test.InsertQueue(2);
	test.InsertQueue(3);
	test.InsertQueue(4);
	test.InsertQueue(5);
	test.InsertQueue(6);
	test.InsertQueue(7);
	test.InsertQueue(8);
	test.InsertQueue(9);
	test.InsertQueue(10);
	test.InsertQueue(11);
	test.InsertQueue(12);
	test.InsertQueue(13);
	test.InsertQueue(14);
	test.InsertQueue(15);
	/*test1.InsertQueue(7);
	test1.InsertQueue(8);
	test1.InsertQueue(9);
	test1.InsertQueue(10);
	test1.InsertQueue(11);
	test1.InsertQueue(12);
	test1.InsertQueue(13);
	;
	
	MergeQueue(test, test1);
	/*int a=0;
	int i = 0;
	int b = 1;
	for (; a < b; i++)
		a += pow(2, i);
	cout << a<<"  " <<i<< endl;*/
	test.DeleteMin();

	system("pause");
	return 0;
}