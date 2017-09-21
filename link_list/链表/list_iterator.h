#ifndef _LIST_ITERATOR_H_
#define _LIST_ITERATOR_H_
#include "list_node.h"
template <class T>
class ListIterator
{
protected:
	typedef T valueType;
	typedef T& reference;
	typedef T* pointer;
	typedef ListIterator<T> self;
	typedef ListNode<T>* nodeType;
public:
	ListIterator();

	ListIterator(const nodeType & node) :node_(node) {}

	ListIterator(const self& arg) :node_(arg.node_) {}

	~ListIterator();
	
	pointer operator->()
	{
		return &(operator*());
		//return &(node_->data);
	}

	reference operator*()
	{
		return node_->data;
	}

	self operator++(int)
	{
		self tmp=*this;
		++(*this);
		return tmp;
	}

	self& operator++()
	{
		node_ = node_->next;
		return *this;
	}
private:
	nodeType node_;
};
template <class T>
ListIterator<T>::ListIterator()
{
}

template <class T>
ListIterator<T>::~ListIterator()
{
}
#endif // !_LIST_ITERATOR_H_

