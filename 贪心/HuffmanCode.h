#pragma once
#include <iostream>
#include <vector>
#include <stack>
struct HuffTreeNode
{
	int value;
	HuffTreeNode *parent;
	HuffTreeNode *lChild;
	HuffTreeNode *rChild;
};
void DeleteTree(HuffTreeNode *pNode);

void Preorder(HuffTreeNode *pNode);

void sort(std::vector<int>& value);

HuffTreeNode *FindNode(HuffTreeNode *node, int data);

class HuffTree
{
public:
	HuffTree(std::vector<int>& value);
	~HuffTree();
	void PreorderTree()
	{
		Preorder(pRoot);
	}

	void HuffManCode(int data, std::vector<int>& HuffCode);

private:
	HuffTreeNode *pRoot;
};


