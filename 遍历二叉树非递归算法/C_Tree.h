
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
TreeNode<T> *SearchNode(int index,TreeNode<T> *node)
{
	TreeNode<T> *temp;

	if (node->NodeIndex==index)
	{
		return  node;
	}
	if (node->LeftChild!=NULL)
	{
		temp = SearchNode(index,node->LeftChild);
		if (temp != NULL) 
		{
			return temp;
		}	
	}
	if (node->RightChild != NULL)
	{
		return SearchNode(index,node->RightChild);	
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
void PreorderTraver(TreeNode<T> *node)
{
	if (node!=NULL)
	{
		cout << "index: " << node->NodeIndex<<"  " << "Element: " << node->Element << endl;
		PreorderTraver(node->LeftChild);
		PreorderTraver(node->RightChild);
	}
}

template <class T>
void InorderTraver(TreeNode<T> *node)
{
	if (node != NULL)
	{
		InorderTraver(node->LeftChild);
		cout << "index: " << node->NodeIndex << "  " << "Element: " << node->Element << endl;
		InorderTraver(node->RightChild);
	}
}

template <class T>
void PostorderTraver(TreeNode<T> *node)
{
	if (node != NULL)
	{
		PostorderTraver(node->LeftChild);
		PostorderTraver(node->RightChild);
		cout << "index: " << node->NodeIndex << "  " << "Element: " << node->Element << endl;		
	}
}

template <class T>
int FindNode(TreeNode<T> *node,T data)
{
	int temp = -1;
	if (node->Element == data)
	{
		return  node->NodeIndex;
	}
	if (node->LeftChild != NULL)
	{
		temp = FindNode( node->LeftChild,data);
		if (temp != -1)
		{
			return temp;
		}
	}
	if (node->RightChild != NULL)
	{
		temp= FindNode( node->RightChild,data);
		if (temp != -1)
		{
			return temp;
		}
	}
	return -1;
}



template < class  T >
class Tree
{
public:
	
	Tree(T data);
	~Tree();
	void MakeEmpty();
	int FindTreeNodeInData(T data);
	void Insert_Tree(T data);
	TreeNode<T> *SearchTreeNode(int index);
	bool AddTreeNode(int index, int location,T data);
	bool DeleteTreeNode(int index);
	bool DeleteTreeNodeInData(T data);
	void PreorderTraverTheTree();
	void InordetTraverTheTree();
	void PostordetTraverTheTree();
	TreeNode<T> *GetTheTree(){ return RootNode; }
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

template < class T>
void Tree<T>::MakeEmpty()
{
	if (tempTree != NULL)
	{
		MakeEmpty(tempTree->LeftChild);
		MakeEmpty(tempTree->RightChild);
		free(tempTree);
	}
	
}

template <class T>
TreeNode<T> *Tree<T>::SearchTreeNode(int index)    //根据节点索引查找，返回值为节点指针
{
	return SearchNode(index, RootNode);
	
}

template <class T>
int Tree<T>::FindTreeNodeInData(T data)   //根据节点元素的信息查找，返回值为节点的索引
{
	return FindNode(RootNode, data);
}

template <class T>
bool Tree<T>::AddTreeNode(int index, int location, T data)  //根据索引添加节点 ，location为0则添加在此索引节点的左子树，1则添加到此节点的右子树，data为待添加节点的信息
{
	TreeNode<T> *temp = NULL;
	temp=SearchTreeNode(index);
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
	if (temp->NodeIndex % 2 == 1&&temp->Parent)
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
bool Tree<T>::DeleteTreeNodeInData(T data)
{
	int index=FindTreeNodeInData(data);
	if (index < 0)
	{
		return false;
	}
	else
	{
		DeleteTreeNode(index);
	}
	return true;
}

template <class T>
void Tree<T>::PreorderTraverTheTree()
{
	PreorderTraver(RootNode);
}

template <class T>
void Tree<T>::InordetTraverTheTree()
{
	InorderTraver(RootNode);
}

template <class T>
void Tree<T>::PostordetTraverTheTree()
{
	PostorderTraver(RootNode);
}