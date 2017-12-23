#define size 20
template <class T>
class Stack
{
private:
	T a[size];
	int top;
public:
	Stack();
	void push_Stack(T data);
	T pop_Stack();
	bool is_Empty();
	bool is_Full();
};
template <class T>
Stack<T> ::Stack()
{
	top = -1;
}
template <class T>
bool Stack<T>::is_Full()
{
	if (top == size-1)
		return true;
	else
		return false;
}
template <class T>
bool Stack<T>::is_Empty()
{
	if (top = =-1)
		return true;
	else
		return false;
}
template <class T>
void Stack<T>::push_Stack(T data)
{
	if (is_Full() == 1)
		cout << "is full" << endl;
	else
	{
		a[++top] = data;
	}
	

}
template <class T>
T Stack<T>::pop_Stack()
{
	T data;
	if (top != -1)
	{
		data = a[top];
		top--;
	}
	return data;
}