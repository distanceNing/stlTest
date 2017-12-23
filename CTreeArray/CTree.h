template <class T>
class Tree
{
public:
	Tree(int treeLength,T data);
	~Tree();
	int Find(T data);
	T SearchNode(int index);
	bool AddTreeNode(int index, int location, T data);
	bool DeleteTreeNode(int index);
	void TravelTree();
private:
	T *tree;
	int TreeSize;
};
template <class T>
Tree<T>::Tree(int treeLength,T data)
{
	tree = new T[treeLength];
	tree[0] = data;
	TreeSize = treeLength;
	for (int i = 1; i < TreeSize; i++)
	{
		tree[i] = 0;
	}
}
template < class T >
Tree<T>::~Tree()
{
	delete[]tree;
}
template <class T>
int Tree<T>::Find(T data)
{
	int i = 0;
	int temp=0;
	while (i<TreeSize)
	{
		if (tree[i] == data)
		{
			temp = i;
		}
		i++;
	}
	return temp;
}
template <class T>
T Tree<T>::SearchNode(int index)
{
	if (index<0 || index>TreeSize)
	{
		return NULL;
	}
	if (tree[index] == 0)
	{
		return NULL;
	}
	return tree[index];
	
}
template <class T>
bool Tree<T>::AddTreeNode(int index, int location, T data)
{
	if (index<0 || index>TreeSize)
	{
		return false;
	}
	if (location == 1)
	{
		if (index * 2 + 1>=TreeSize)
		{
			return false;
		}
		if (tree[index * 2 + 1]!=0)
		{
			cout << "此处已有节点" << endl;
			return false;
		}
		tree[index * 2 + 1] = data;
	}
	else
	{
		if (index * 2 + 2 >= TreeSize)
		{
			return false;
		}
		if (tree[index * 2 + 2] != 0)
		{
			cout << "此处已有节点" << endl;
			return false;
		}
		tree[index * 2 + 2] = data;
	}
	return true;
}
template <class T>
bool Tree<T>::DeleteTreeNode(int index)
{
	if (SearchNode(index) == NULL)
	{
		cout << "无此节点" << endl;
		return false;
	}
	tree[index] = 0;
	return true;
}
template <class T>
void Tree<T>::TravelTree()
{
	for (int i = 0; i < TreeSize; i++)
	{
		cout << tree[i] << " ";
	}
}