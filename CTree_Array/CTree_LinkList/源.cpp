#include <iostream>
using namespace std;
#include "CTree.h"
#include "stdlib.h"
int main()
{
	Tree<int> T(12,3);
	T.AddTreeNode(0, 1, 1);
	T.AddTreeNode(0, 2, 4);
	T.AddTreeNode(1, 2, 9);
	T.AddTreeNode(1, 1, 6);
	T.AddTreeNode(2 * 0 + 2, 2, 5);	
	T.AddTreeNode(2 * 0 + 2, 1, 2);
	T.AddTreeNode(2 * 1 + 1, 1, 7);
	T.AddTreeNode(7, 1, 5);

	cout << "index:"<<T.Find(3) << endl;
	cout << "node4: " << T.SearchNode(4) << endl;
	T.DeleteTreeNode(5);
	T.TravelTree();
	system("pause");
	return 0;
}
