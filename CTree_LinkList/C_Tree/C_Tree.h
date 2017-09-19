
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
typedef int Index;
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
	int FindTreeNodeInData(T data);
	void Insert_Tree(T data);
	TreeNode<T> *SearchTreeNode(int index);
	bool AddTreeNode(int index, int location,T data);
	bool DeleteTreeNode(int index);
	bool DeleteTreeNodeInData(T data);
	void PreorderTraverTheTree();
	void InordetTraverTheTree();
	void PostordetTraverTheTree();
    bool DeleteThisNode(int index);
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
	cout << "aaa" << endl;
}

template < class T>
Tree<T>::~Tree()
{
	DeleteTreeNode(0);
}

template <class T>
TreeNode<T> *Tree<T>::SearchTreeNode(int index)    //���ݽڵ��������ң�����ֵΪ�ڵ�ָ��
{
	return SearchNode(index, RootNode);
	
}

template <class T>
Index Tree<T>::FindTreeNodeInData(T data)   //���ݽڵ�Ԫ�ص���Ϣ���ң�����ֵΪ�ڵ������
{
	return FindNode(RootNode, data);
}

template <class T>
bool Tree<T>::AddTreeNode(int index, int location, T data)  //����������ӽڵ� ��locationΪ0������ڴ������ڵ����������1����ӵ��˽ڵ����������dataΪ����ӽڵ����Ϣ
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

template <class T>
bool Tree<T>::DeleteThisNode(int index)
{

	TreeNode<T> *temp = NULL;
	temp = SearchTreeNode(index);
	if (temp == NULL)
	{
		return false;
	}
	if (temp->LeftChild == NULL&&temp->RightChild==NULL)//����˽ڵ�û�к��ӣ���ֱ��ɾ��
	{
		DeleteTreeNode(index);
		
	}
	if (temp->LeftChild == NULL&&temp->RightChild )  //�����������������Һ���
	{
		if (temp->NodeIndex % 2 == 1 && temp->Parent)
		{
			temp->Parent->LeftChild = temp->RightChild;
			temp->RightChild->NodeIndex = temp->NodeIndex;
			temp->RightChild->Parent = temp->Parent;
		}
		if (temp->NodeIndex % 2 == 0 && temp->Parent)
		{
			temp->Parent->RightChild = temp->RightChild;
			temp->RightChild->NodeIndex = temp->NodeIndex;
			temp->RightChild->Parent = temp->Parent;
		}
		delete temp;
		temp = NULL;
	}
	if (temp->LeftChild &&temp->RightChild == NULL)  //�����������Һ���������
	{
		if (temp->NodeIndex % 2 == 1 && temp->Parent)
		{
			temp->Parent->LeftChild = temp->LeftChild;
			temp->LeftChild->NodeIndex = temp->NodeIndex;
			temp->LeftChild->Parent= temp->Parent;
		}
		if (temp->NodeIndex % 2 == 0 && temp->Parent)
		{
			temp->Parent->RightChild = temp->LeftChild;
			temp->LeftChild->NodeIndex = temp->NodeIndex;
			temp->LeftChild->Parent = temp->Parent;
		}
		delete temp;
		temp = NULL;
	}
	if (temp->LeftChild &&temp->RightChild)
	{
		  //��ɾ�����������ӵĽ��ʱ�����ж�������ĸ��ڵ��м���������ֻ����һ����㣬��ֱ�Ӱ�����������Һ�����ӵ�����ڵ�ĸ��ڵ���
		if (temp->Parent->LeftChild == NULL&&temp->Parent->RightChild)
		{
			temp->Parent->LeftChild = temp->LeftChild;
			temp->LeftChild->NodeIndex = temp->NodeIndex-1;
			temp->LeftChild->Parent = temp->Parent;

			temp->Parent->RightChild = temp->RightChild;
			temp->RightChild->NodeIndex = temp->NodeIndex;
			temp->RightChild->Parent = temp->Parent;
			
			delete temp;
			temp = NULL;
		}
		if (temp->Parent->LeftChild &&temp->Parent->RightChild == NULL)
		{
			temp->Parent->LeftChild = temp->LeftChild;
			temp->LeftChild->NodeIndex = temp->NodeIndex;
			temp->LeftChild->Parent = temp->Parent;

			temp->Parent->RightChild = temp->RightChild;
			temp->RightChild->NodeIndex = temp->NodeIndex+1;
			temp->RightChild->Parent = temp->Parent;
			delete temp;
			temp = NULL;
		}

	}
	//��ɾ���� �����������ĸ��ڵ� 
	return true;
}