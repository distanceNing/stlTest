#include <iostream>
using namespace std;
#include "C_Tree.h"
#include "linkStack.h"
#include <vector>
#include <stdlib.h>

template <class T>
vector<T> PreOrder(TreeNode<T> *pNode);
template <class T>
vector<T> InOrder(TreeNode<T> *pNode);
template <class T>
vector<T> PostOrder(TreeNode<T> *pNode);

template<class T>
void Pre_In_Order(vector<T> Pre, vector<T> In, int PreH, int PreL, int InH, int InL, TreeNode<T> **tempNode);


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
	test.AddTreeNode(3, 1, 9);

	test.AddTreeNode(8, 0, 19);
	test.AddTreeNode(8, 1, 20);

	
	vector<int >tempPre=PreOrder(test.GetTheTree());

	vector<int >tempIn = InOrder(test.GetTheTree());
	int PreH = tempPre.size()-1;  
	int PreL = 0;
	int InH = tempIn.size()-1;
	int InL = 0;
	TreeNode<int> *temp = NULL; 
	Pre_In_Order(tempPre, tempIn, PreH, PreL, InH, InL,&temp);

	vector<int> testTree=PostOrder(temp);
	int i = 0;
	while (i<testTree.size())
	{
		cout << testTree[i] << " ";
		i++;
	}
	system("pause");
	return 0;
}
template <class T>
vector<T> PreOrder(TreeNode<T> *pNode)
{
	vector<T>Result;
	stack<TreeNode<T>*> tempStack;
	while (pNode!=NULL||tempStack.empty_Stack()!=1)
	{
		if (pNode != NULL)
		{
			Result.push_back(pNode->Element);
			tempStack.push_Stack(pNode);
			pNode = pNode->LeftChild;
		}
		else
		{			
			pNode = tempStack.pop_Stack();
			pNode = pNode->RightChild;
		}

	}
	return Result;
}
template <class T>
vector<T> InOrder(TreeNode<T> *pNode)
{
	vector<T>Result;
	stack<TreeNode<T>*> tempStack;
	while (pNode != NULL ||	 tempStack.empty_Stack() != 1)
	{
		if (pNode != NULL)
		{
			tempStack.push_Stack(pNode);
			pNode = pNode->LeftChild;
		}
		else
		{
			pNode = tempStack.pop_Stack();
			Result.push_back(pNode->Element);
			pNode = pNode->RightChild;
		}	

	}
	return Result;
}
template <class T>
vector<T>PostOrder(TreeNode<T> *pNode)
{
	vector<T>Result;
	stack<TreeNode<T>*> tempStack;
	int flag[100];
	int i = 0;
	int j = 0;
	do
	{
		if (pNode != NULL)
		{
			tempStack.push_Stack(pNode);
			pNode = pNode->LeftChild;	
			flag[i] = 0;
			i++;
		}	
		else
		{
			pNode = tempStack.pop_Stack();
			i--;		
			if (flag[i] == 0)
			{
				tempStack.push_Stack(pNode);
				pNode = pNode->RightChild;
				flag[i] = 1;
				i++;
			}
			else
			{
				Result.push_back( pNode->Element);
				pNode = NULL;		
			}
		}

	} while (pNode!=NULL||tempStack.empty_Stack() != 1);
	return Result;
}
template<class T>
void Pre_In_Order(vector<T> Pre, vector<T> In,int PreH,int PreL,int InH,int InL,TreeNode<T> **tempNode)
{
	int count = PreL;
	*tempNode = new TreeNode<T>;
	(*tempNode)->Element = Pre[PreL];
    
	
	while (In[count] != Pre[PreL]&&count<PreH-PreL+1)
		{
			count++;
		}
	if (In[count] == Pre[PreL])
	{
		
		if (count == PreL)
		{
			(*tempNode)->LeftChild = NULL;
		}
		else
		{
			Pre_In_Order(Pre, In, count, PreL + 1, count - 1, InL,& (*tempNode)->LeftChild);
		}
		if (count == PreH)
		{
			(*tempNode)->RightChild = NULL;
		}
		else
		{
			Pre_In_Order(Pre, In, PreH, count + 1, InL, count + 1, &(*tempNode)->RightChild);
		}
	}aaaaaaaaaaaa
	
}
