#ifndef _LIST_H_
#define _LIST_H_
#include "list_iterator.h"
#include "list_node.h"

template <class T>
class linkList
{
protected:
	typedef T valueType;
	typedef ListNode<T> listNode;
public:
	typedef ListIterator<T> iterator;
	linkList() {
		head = NULL;
		
	}
	~linkList(){ clear(); }
	int isEmpty(){
		if (flag = head)
			return 1;
		else
			return 0;
	}
	iterator begin() {
		return iterator(head);
	}

	void push_back(valueType data);						    //β�ӷ�������
	
	
	void PrintLinkList();                           //��������������Ϣ
	void addToList(int Index, int count, T data);    //��Index�����count������Ϊdata��Ԫ��
	unsigned int getListSize();                      //���������ʵ�ʳ���
	void clear();                                  //������������
	linkList<T> operator=(const linkList<T> &temp); //����=,ʹ�ÿ����ڶ���丳ֵ

	int getListData(valueType data);                        //���ݽ����Ϣ���ҽ�㣬����ֵΪ��������
	listNode* getListData(unsigned int Index);				//������index���Ľ�㣬����ֵΪ���ָ��

	unsigned int eraseListNode(unsigned int Index);                 //ɾ��Index���Ľ��
	void deleteListNode(valueType data);                    //���ݽ����Ϣɾ�����
	void ChangeReverse();
private:
	listNode *head;
	listNode *flag;   //pΪ���

};

template <class T>
void linkList<T>::push_back(valueType data)
{
	listNode *temp = new  listNode;
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
unsigned int linkList<T>::eraseListNode(unsigned int Index)//iΪ��ɾ��Ԫ�ص�λ��
{
	ListNode<T>	*temp, *temp2;
	if (Index == 1)
	{
		temp = head;
		head = head->next;
		delete temp;
		return 1;
	}
	else
	{
		temp = getListData(Index - 1);
		if (temp == NULL)
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
ListNode<T>* linkList<T>::getListData(unsigned int Index)//i ΪԪ���������е�λ��
{
	ListNode<T> *ptr = head;
	int j = 1;
	if (Index == 1)
		return ptr;
	while (ptr != NULL&&j<Index)
	{
		ptr = ptr->next;
		j++;
	}
	if (j == Index)
	{

		return ptr;
	}
	else
		return NULL;
}
template<class T>
void linkList<T>::PrintLinkList()
{
	ListNode<T> *temp;
	temp = head;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
template <class T>
void linkList<T>::addToList(int Index, int count, T data)
{
	ListNode<T> *temp, *temp2;
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
		temp = new  ListNode<T>;
		temp->data = data;
		temp->next = head;
		head = temp;
		temp2 = head;
		temp = NULL;
		count -= 1;
	}
	else
	{
		temp2 = get_listData(Index);
	}

	while (i < count)
	{
		temp = new  ListNode<T>;
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
unsigned int linkList<T>::getListSize()
{
	ListNode<T> *temp = head;
	unsigned int size = 0;

	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return size;
}
template <class T>
void linkList<T>::clear()
{
	unsigned int size = getListSize();
	for (int i = 1; i <= size; i++)
	{
		eraseListNode(i);
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
int linkList<T>::getListData(valueType data)  //dataΪ�����Ϣ,����ֵΪ����������е�λ��
{
	ListNode<T> *q = head;
	int j = 1;

	while (q != NULL)
	{
		if (q->data == data)
			return j;
		q = q->next;
		j++;
	}

	return NULL;
}
template <class T>
void linkList<T>::deleteListNode(valueType data)//iΪ��ɾ��������Ϣ
{
	eraseListNode(getListData(data));
}
template<class T>
void linkList<T>::ChangeReverse()
{
	/*ListNode<T>* tempHead,*temp1,*temp2;
	tempHead = new ListNode<T>;
	tempHead->data=head->data;
	tempHead->next = NULL;
	temp1 = head->next;
	delete head;
	head = NULL;
	while (temp1)
	{
	temp2 = new ListNode<T>;
	temp2->data = temp1->data;
	temp2->next = tempHead;
	tempHead = temp2;
	temp2 = temp1;
	temp1 = temp1->next;
	delete temp2;
	temp2 = NULL;
	}*/
	ListNode<T>* tempHead, *temp1, *temp2;
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
#endif // !_LIST_H_