#ifndef _YN_STL_QUEUE_
#define _YN_STL_QUEUE_
namespace ynstl{
template < class T>
class Queue
{
public:
	Queue(int nSize) {
		Size = nSize;
		ClearQueue();
		Element = new T[nSize];
	}

	~Queue()
	{
		if (Element != NULL)
		{
			delete[] Element;
			Element = NULL;
		}
	}
	int empty();
	void push(T data);
	T pop();
	int size(){ return QueueLen; }
private:
	int Size;   //队列的有效资源长度
	int QueueLen;
	int Front;
	int Rear;
	T*  Element;
};
template < class T >
int Queue<T>::empty()
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
void Queue<T>::push(T data)
{
	if (Rear == Size - 1)
	{
		Rear = Rear%Size;
	}
	Element[Rear] = data;
	Rear++;
	QueueLen++;
	
}
template < class T >
T Queue<T>::pop()
{
	if (empty())
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

}// namespace ynstl

#endif // !_QUEUE
