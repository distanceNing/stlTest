
#pragma once
template <class T>
struct	stackNode
{
	T data;
	struct stackNode *next;
};
template <class T>
class stack
{
public:
	stack();
	~stack();
	bool empty_Stack();
	void push_Stack(T x);
	T pop_Stack();
	T get_Top()
	{ 
		if (empty_Stack())
			return 0;
		else
		return top->data;
	}

private:
	stackNode<T> *s;
	stackNode<T> *top;

};
template <class T>
stack<T>::stack()
{
	s = NULL;
	top = s;
}
template <class T>
stack<T>::~stack()
{
	while (empty_Stack() != 1)
	{
		 pop_Stack();
	}

}
template <class T>
bool stack<T>::empty_Stack()
{
	if (top == NULL)
		return true;
	else
		return false;
}

template <class T>
void stack<T>::push_Stack(T x)
{
	stackNode<T> *p;
	p = new stackNode<T>;
	p->data = x;
	p->next = top;
	top = p;
}

template <class T>
T stack<T>::pop_Stack()
{
	stackNode<T> *p = NULL;
	T x;
	if (empty_Stack() != 1)
	{
		x = top->data;
		p = top;
		top = top->next;
		delete p;
		p = NULL;
	}
	else
	{
		return 0;
	}
	return x;
}
