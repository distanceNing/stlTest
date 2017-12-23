#define MaxNodeNum 20
#include "Queue.h"
template < class  T >
struct TreeNode
{
	int NodeIndex;
	T Element;
	TreeNode *LeftChild;
	TreeNode *RightChild;
	TreeNode *Parent;
};

template <class T>
TreeNode<T> *SearchNode(int index, TreeNode<T> *node)
{
	TreeNode<T> *temp;

	if (node->NodeIndex == index)
	{
		return  node;
	}
	if (node->LeftChild != NULL)
	{
		temp = SearchNode(index, node->LeftChild);
		if (temp != NULL)
		{
			return temp;
		}
	}
	if (node->RightChild != NULL)
	{
		return SearchNode(index, node->RightChild);
	}
	return NULL;
}
template <class T>
void DeleteNode(TreeNode<T> *node)
{
	if (node == NULL)
		return;
	TreeNode<T> *templeft = node->LeftChild;
	TreeNode<T> *tempright = node->RightChild;
	if (node)
	{
		delete node;
		node = NULL;
	}
	DeleteNode(templeft);
	DeleteNode(tempright);
}
template < class  T >
class Tree
{
public:

	Tree(T data);
	~Tree();
	TreeNode<T> *SearchTreeNode(int index);
	bool AddTreeNode(int index, int location, T data);
	bool DeleteTreeNode(int index);
	void Transleve();
private:
	TreeNode<T> *RootNode;

};

template < class T>
Tree<T>::Tree(T data)
{
	RootNode = new TreeNode<T>;
	RootNode->NodeIndex = 0;
	RootNode->Parent = NULL;
	RootNode->Element = data;
	RootNode->LeftChild = NULL;
	RootNode->RightChild = NULL;
}

template < class T>
Tree<T>::~Tree()
{
	DeleteTreeNode(0);
}
template <class T>
TreeNode<T> *Tree<T>::SearchTreeNode(int index)    //根据节点索引查找，返回值为节点指针
{
	return SearchNode(index, RootNode);

}
template <class T>
bool Tree<T>::AddTreeNode(int index, int location, T data)  //根据索引添加节点 ，location为0则添加在此索引节点的左子树，1则添加到此节点的右子树，data为待添加节点的信息
{
	TreeNode<T> *temp = NULL;
	temp = SearchTreeNode(index);
	if (temp == NULL)
	{
		return false;
	}
	TreeNode<T> *tempnode = new TreeNode<T>;
	tempnode->Element = data;
	tempnode->Parent = temp;
	tempnode->LeftChild = NULL;
	tempnode->RightChild = NULL;
	if (location == 0)
	{
		tempnode->NodeIndex = index * 2 + 1;
		temp->LeftChild = tempnode;

	}
	if (location == 1)
	{
		tempnode->NodeIndex = index * 2 + 2;
		temp->RightChild = tempnode;

	}
	return true;
}
template <class T>
bool Tree<T>::DeleteTreeNode(int index)
{
	TreeNode<T> *temp = NULL;
	temp = SearchTreeNode(index);
	if (temp == NULL)
	{
		return false;
	}
	if (temp->NodeIndex % 2 == 1 && temp->Parent)
	{
		temp->Parent->LeftChild = NULL;
	}
	if (temp->NodeIndex % 2 == 0 && temp->Parent)
	{
		temp->Parent->RightChild = NULL;
	}
	DeleteNode(temp);
	return true;
}

template <class T>
void Tree<T>::Transleve()
{
	TreeNode<T> *tempNode;
	/*for (int i = 0; i < MaxNodeNum; i++)  //利用索引实现层次遍历
	{
	tempNode = SearchTreeNode(i);
	if (tempNode != NULL)
	{
	cout << "index: "<<tempNode->NodeIndex << "Element: "<<tempNode->Element << endl;
	}
	}*/

	Queue<TreeNode<T>*>tempQueue(MaxNodeNum);  //利用队列实现遍历                     
	tempQueue.In_Queue(RootNode);
	if (RootNode)
		cout << "index: " << RootNode->NodeIndex << "Element: " << RootNode->Element << endl;
	while (tempQueue.IsEmpty()!=1)
	{
		tempNode=tempQueue.Out_Queue();
		if (tempNode->LeftChild != NULL)
		{
			cout << "index: " << tempNode->LeftChild->NodeIndex << "Element: " << tempNode->LeftChild->Element << endl;
			tempQueue.In_Queue(tempNode->LeftChild);
		}
		if (tempNode->RightChild != NULL)
		{
			cout << "index: " << tempNode->RightChild->NodeIndex << "Element: " << tempNode->RightChild->Element << endl;
			tempQueue.In_Queue(tempNode->RightChild);
		}
	}
}