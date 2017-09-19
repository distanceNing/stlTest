template < class T>
struct Node
{
	T data;
	Node *next;
};
template <class T>
class linkList
{
public:
	linkList() {
		head = NULL;
		flag = head;
	}
	~linkList(){ Delete_LinkList(); }
	int isEmpty(){
		if (flag = head)
			return 1;
		else
			return 0;
	}
	void instert_list(T data);                      //β�ӷ�������
	int delete_listData(int Index);                 //ɾ��Index���Ľ��
	Node<T>* get_listData(int Index);               //������index���Ľ�㣬����ֵΪ���ָ��
	void Printf_LinkList();                         //��������������Ϣ
	void Add_list(int Index, int count, T data);    //��Index�����count������Ϊdata��Ԫ��
	int Get_listSize();                             //���������ʵ�ʳ���
	void Delete_LinkList();                         //������������
	linkList<T> operator=(const linkList<T> &temp); //����=,ʹ�ÿ����ڶ���丳ֵ
	int GetListData(T data);                        //���ݽ����Ϣ���ҽ�㣬����ֵΪ��������
	void DeleteListData(T data);                    //���ݽ����Ϣɾ�����
	void ChangeReverse();
private:
	Node<T> *head;
	Node<T> *flag;   //pΪ���

};
template <class T>
void linkList<T>::instert_list(T data)
{
	Node<T> *temp = new  Node<T>;
	temp->data = data;
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
int linkList<T>::delete_listData(int Index)//iΪ��ɾ��Ԫ�ص�λ��
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
			cout << "λ�ô���" << endl;
			return 0;
		}
		else if (temp->next == NULL)
		{
			cout << "λ�ò�����" << endl;
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
Node<T>* linkList<T>::get_listData(int Index)//i ΪԪ���������е�λ��
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
		cout << "�����λ�ú���Ŀ����" << endl;
		return;
	}
	if (Index>Get_listSize())
	{
		cout << "�����λ�ó�������Χ" << endl << "Ĭ����β������" << endl;
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
	int size = Get_listSize();
	for (int i = 1; i <= size; i++)
	{
		delete_listData(i);
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
int linkList<T>::GetListData(T data)  //dataΪ�����Ϣ,����ֵΪ����������е�λ��
{
	Node<T> *q = head;
	int j = 1;
	
	while (q!=NULL)
	{
		if (q->data == data)
			return j;
		q = q->next;
		j++;
	}
	
		return NULL;
}
template <class T>
void linkList<T>::DeleteListData(T data)//iΪ��ɾ��������Ϣ
{
	delete_listData(GetListData(data));

}

template<class T>
void linkList<T>::ChangeReverse()
{
	/*Node<T>* tempHead,*temp1,*temp2;
	tempHead = new Node<T>;
	tempHead->data=head->data;
	tempHead->next = NULL;
	temp1 = head->next;
	delete head;
	head = NULL;
	while (temp1)
	{
		temp2 = new Node<T>;
		temp2->data = temp1->data;
		temp2->next = tempHead;
		tempHead = temp2;
		temp2 = temp1;
		temp1 = temp1->next;
		delete temp2;
		temp2 = NULL;
	}*/
	Node<T>* tempHead, *temp1, *temp2;
	tempHead = head;
	temp1 = head->next;  //����ͷ��� 
	while (temp1)
	{
		temp2 = temp1->next;   
		temp1->next = tempHead;
		tempHead = temp1;
		temp1 = temp2;
	}

	head->next = NULL;
	head = tempHead;
}
