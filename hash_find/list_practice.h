template < class T>
struct Node
{
	T data;
	Node *next;
	int Flag;
};
template <class T>
class linkList
{
public:
	linkList() {
		head = NULL;
		flag = head;
	}
	int isEmpty(){
		if (flag = head)
			return 1;
		else
			return 0;
	}
	void instert_list(T data);
	int delete_listData(int Index);
	Node<T>* get_listData(int Index);
	void Printf_LinkList();
	void Add_list(int Index, int count, T data);//在Index处添加count个元素
	int Get_listSize();
	void Delete_LinkList();
	linkList<T> operator=(const linkList<T> &temp);
	int GetListData(T data);
	void FlagTheNode(T data);
	void DeleteListData(T data);  //data为待删除结点的信息
private:
	Node<T> *head;
	Node<T> *flag;   //p为标记

};
template <class T>
void linkList<T>::instert_list(T data)
{
	Node<T> *temp = new  Node<T>;
	temp->data = data;
	temp->Flag = 0;
	if (temp)
	{
		if (head)
		{
			flag->next = temp;
			flag = temp;
		}
		else
		{
			head = temp; 
			flag = temp;
		}
	}
	if (flag)
		flag->next = NULL;
	
}
template<class T>
int linkList<T>::delete_listData(int Index)//i为待删除元素的位置
{
	Node<T>	*temp,*temp2;
	if (Index == 1)
	{
		temp = head;
		head = head->next;
		delete temp;
		return 1;
	}
	else
	{
		temp = get_listData(Index - 1);
		if (temp== NULL)
		{
			cout << "位置错误" << endl;
			return 0;
		}
		else if (temp->next == NULL)
		{
			cout << "位置不存在" << endl;
		}
		else
		{
			temp2 = temp->next;
			temp->next = temp2->next;
			delete temp2;
		}
	}
}
template<class T>
Node<T>* linkList<T>::get_listData(int Index)//i 为元素在链表中的位置
{
	Node<T> *q = head;
	int j = 1;
	if (Index == 1)
		return q;
	while (q != NULL&&j<Index)
	{
		q = q->next;
		j++;
	}
	if (j == Index)
	{
		
		return q;
	}
	else
		return NULL;
}
template<class T>
void linkList<T>::Printf_LinkList()
{
	Node<T> *temp;
	temp = head;
	while (temp)
	{
		cout << temp->data << " ";
		temp= temp->next;
	}
	cout << endl;
}
template <class T>
void linkList<T>::Add_list(int Index, int count,T data)
{
	Node<T> *temp,* temp2;
	int i = 0;
	if (Index < 0 || count <= 0)
	{
		cout << "输入的位置和数目错误" << endl;
		return;
	}
	if (Index>Get_listSize())
	{
		cout << "插入的位置超出链表范围" << endl << "默认在尾部插入" << endl;
		Index = Get_listSize();
	}

	if (Index == 0)
	{
		temp = new  Node<T>;
		temp->data = data;
		temp->next = head;
		head=temp;
		temp2 = head;
		temp = NULL;
		count -= 1;
	}
	else
	{
		temp2 = get_listData(Index );
	}
	
	while (i < count)
	{
		temp = new  Node<T>;
		temp->data = data;
		if (temp)
		{
				temp->next = temp2->next;
				temp2->next = temp;
				temp2 = temp2->next;
			
		}
		temp = NULL;
		i++;
	}
	
}
template <class T>
int linkList<T>::Get_listSize()
{
	Node<T> *temp = head;
	int size = 0;
	
		while (temp)
		{
			temp = temp->next;
			size++;
		}
		return size;
}
template <class T>
void linkList<T>::Delete_LinkList()
{
	Node<T> *temp, *temp2;
	temp= head->next;
	head = NULL;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		delete temp2;
		temp2 = NULL;
	}

}
template <class T>
linkList<T> linkList<T>::operator=(const linkList<T> &temp)
{
	head = temp.head;
	flag = temp.flag;
	return *this;
}
template <class T>
int linkList<T>::GetListData(T data)//i 为元素在链表中的位置
{
	Node<T> *q = head;
	int j = 1;

	while (q != NULL)
	{
		if (q->data == data)
			return j;
		q = q->next;
		j++;
	}

	return 0;
}
template <class T>
void linkList<T>::FlagTheNode(T data)
{
	Node<T> *q = head;
	while (q != NULL)
	{
		if (q->data == data)
			q->Flag = 1;
		q = q->next;
		
	}
	
}
template<class T>
void linkList<T>::DeleteListData(T data)//i为待删除结点的信息
{
	delete_listData(GetListData(data));
	
}