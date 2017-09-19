#include <iostream>
#include "C_Tree.h"
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
	test.AddTreeNode(7, 0, 15);
	test.AddTreeNode(7, 1, 16);
	test.DeleteThisNode(7);
	//cout << "3 --index: "<<test.FindTreeNodeInData(3)<< endl;
	//test.DeleteTreeNodeInData(4);
	cout << "Preorder: " << endl;
	test.PreorderTraverTheTree();


	/*cout << "Inorder: " << endl;
	test.InordetTraverTheTree();
	cout << "Postorder: " << endl;
	test.PostordetTraverTheTree();*/

	system("pause");
	return 0;
}