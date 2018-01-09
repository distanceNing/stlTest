#ifndef _MYSTL_STACK_
#define _MYSTL_STACK_
#include"../yn_vector/yn_vector.h"
#include <iostream>
namespace ynstl{
template <class T>
class Stack
{
private:
	static const size_t kInitSize = 4;
public:
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
	Stack(size_t size = kInitSize) :vec_(size), top_(0) {}

	void push(const value_type& data);

	//void push(value_type&& data)

	const reference top() {
		if (empty())
		{
			std::cout << "empty\n";
			throw std::exception();
		}
		return vec_[top_ - 1];
	}
	void pop();
	bool empty() {
		return top_ == 0;
	}
private:
	bool full()
	{
		return top_ == vec_.size();
	}
	Vector<T> vec_;
	size_t top_;
};

template <class T>
void Stack<T>::push(const value_type& data)
{
	if (full())
	{
		vec_.push_back(data);
	}
	else
	{
		vec_[top_] = data;
	}
	++top_;
}
template <class T>
void Stack<T>::pop()
{
	if (empty())
	{
		std::cout << "empty\n";
		return;
	}
	top_--;
}
}//namespace ynstl
#endif // !_MYSTL_STACK_ 