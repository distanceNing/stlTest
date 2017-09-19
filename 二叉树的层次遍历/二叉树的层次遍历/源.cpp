#include <iostream>
#include "Transleve.h"
using namespace std;
#include "stdlib.h"
int main()
{
	Tree<int>test(3);
	test.AddTreeNode(0, 0, 1);
	test.AddTreeNode(0, 1, 4);

	test.AddTreeNode(1, 0, 6);
	test.AddTreeNode(1, 1, 9);

	test.AddTreeNode(2, 0, 2);
	test.AddTreeNode(2, 1, 5);

	test.AddTreeNode(3, 0, 7);

	test.Transleve();
	


	system("pause");
	return 0;
}