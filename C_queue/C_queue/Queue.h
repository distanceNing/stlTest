#pragma once
#ifndef _QUEUE
#define _QUEUE
template < class T>
class Queue
{
public:
	Queue(int nSize);
	~Queue()
	{
		if (Element != NULL)
		{
			delete[] Element;
			Element = NULL;
		}
	}
	int IsEmpty();
	int IsFull();
	void In_Queue(T data);
	T Out_Queue();
	int Get_QueueLength(){ return QueueLen; }
	void MakeEmpty();
	void VisitQueue();
	void ClearQueue();
private:
	int Size;   //队列的有效资源长度
	int QueueLen;
	int Front;
	int Rear;
	T *Element;
};
template < class T >
Queue<T>::Queue(int nSize)
{
	Size = nSize;
	ClearQueue();
	Element = new T[nSize];
}
template < class T >
int Queue<T>::IsEmpty()
{
	if (QueueLen == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
template < class T >
int Queue<T>::IsFull()
{
	if (QueueLen == Size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
template < class T >
void Queue<T>::In_Queue(T data)
{
	if (IsFull())
	{
		cout << "The queue is full" << endl;
	}
	else
	{
		if (Rear == Size - 1)
		{
			Rear = Rear%Size;
		}
		Element[Rear] = data;
		Rear++;
		QueueLen++;
	}
}
template < class T >
T Queue<T>::Out_Queue()
{
	if (IsEmpty())
	{
		cout << "The queue is empty" << endl;
	}
	else
	{
		if (Front == Size - 1)
		{
			Front = Rear%Size;
		}
		T temp = Element[Front];
		QueueLen--;
		Front++;
		return temp;
	}
}
template <class T>
void Queue<T>::MakeEmpty()
{
	Size = 0;
	Front = 0;
	Rear = 0;

}
template <class T>
void Queue<T>::VisitQueue()
{

	int i = Front;
	for (int j = 0; j < QueueLen; j++)
	{
		if (Front == Size - 1)
		{
			Front = Rear%Size;
		}
		cout << Element[i] << " ";
		i++;
	}
}
template <class T>
void Queue<T>::ClearQueue()
{
	Front = 0;
	Rear = 0;
	QueueLen = 0;
}
#endif // !_QUEUE
