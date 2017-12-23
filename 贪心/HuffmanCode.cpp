#include "HuffmanCode.h"
void Preorder(HuffTreeNode *pNode)
{
	if (pNode != NULL)
	{
		std::cout << pNode->value << " ";
		Preorder(pNode->lChild);
		Preorder(pNode->rChild);
	}
}

HuffTreeNode *FindNode(HuffTreeNode *node, int data)
{
	HuffTreeNode *temp;

	if (node->value == data)
	{
		return  node;
	}
	if (node->lChild != NULL)
	{
		temp = FindNode(node->lChild, data);
		if (temp != NULL)
		{
			return temp;
		}
	}
	if (node->rChild != NULL)
	{
		return FindNode(node->rChild, data);
	}
	return NULL;
}


void sort(std::vector<int>& value)
{
	int size = value.size();
	int i = 0, j = 0;
	int m = 0;
	int temp;
	while (i<size)
	{
		j = i + 1;
		m = i;
		for (j; j<size; j++)
		{
			if (value[j] < value[m])
				m = j;
		}
		if (m != i)
		{
			temp = value[i];
			value[i] = value[m];
			value[m] = temp;
		}
		i++;
	}
}

void DeleteTree(HuffTreeNode *pNode)
{
	if (pNode != NULL)
	{
		DeleteTree(pNode->lChild);
		DeleteTree(pNode->rChild);
		delete pNode;
		pNode = NULL;
	}
}

HuffTree::HuffTree(std::vector<int>& value)
{
	sort(value);
	pRoot = new HuffTreeNode;
	pRoot->value = value[0];
	pRoot->lChild = NULL;
	pRoot->rChild = NULL;
	for (int i =1; i<value.size(); i++)
	{
		HuffTreeNode* tempRoot = new HuffTreeNode;
		HuffTreeNode* tempNode1 = new HuffTreeNode;

		tempNode1->value = value[i];
		tempNode1->lChild = NULL;
		tempNode1->rChild = NULL;
		tempRoot->value = value[i] + pRoot->value;  //将权值相加合并成一颗新树
		pRoot->parent = tempRoot;
		tempNode1->parent = tempRoot;
		tempRoot->lChild = pRoot;
		tempRoot->rChild = tempNode1;
		pRoot = tempRoot;
	}
	pRoot->parent = NULL;
}

void HuffTree::HuffManCode(int data,std::vector<int>& HuffCode)
{
	std::stack<int> tempStack;
	HuffTreeNode *tempNode1 = FindNode(pRoot, data);
	HuffTreeNode *tempNode2 = NULL;
	tempNode2 = tempNode1->parent;
	while (tempNode2 != NULL)
	{

		if (tempNode2->lChild == tempNode1)
		{
			tempStack.push(0);
		}
		else
		{
			tempStack.push(1);
		}
		tempNode1 = tempNode2;
		tempNode2 = tempNode1->parent;
	}

	while (tempStack.empty() != 1)
	{
		HuffCode.push_back(tempStack.top());
		tempStack.pop();
	}
}


HuffTree::~HuffTree()
{
	DeleteTree(pRoot);
}


