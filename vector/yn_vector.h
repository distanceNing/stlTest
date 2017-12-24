#ifndef _YN_VECTOR_H_
#define _YN_VECTOR_H_
#include <cassert>

#include "ynstlcommon/alloc.h"
#include "ynstlcommon/free.h"

namespace ynstl{

template < class T >
class Vector
{
private:
	static const size_t kInitSize = 4;
	// 设置为1.5可以利用到缓存
	static const float kGrowFactors;
public:
	
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;

	
	Vector()
	{
		size_ = 0;
		capacity_ = kInitSize;
		data_ =static_cast<pointer> (common::alloc(capacity_* sizeof(value_type)));
	}

	~Vector(){
		size_ = 0;
		capacity_ = 0;
		common::free(data_);
	}

	size_t size() const
	{ 
		return size_;
	}

	size_t capacity() const
	{
		return capacity_;
	}

	pointer data() const
	{
		return data_;
	}

	reference operator[](size_t index)  
	{
		assert(index < size_);
		return data_[index];
	}

	void clear()
	{
		size_ = 0;
		memset(data_, 0, capacity_);
	}

	void push_back(const value_type value)
	{
		insert(size_, value);
	}

	void push_back(const reference value);

	void erase(size_t index, int count = 1);
	void insert(size_t index, value_type data, size_t count = 1);
	
	void sort();
private:
	void remalloc();
	pointer data_;
	size_t size_; 
	size_t capacity_;
	
};
template <class T>
const float Vector<T>::kGrowFactors = 1.5;
template < class T >
void Vector<T>::remalloc()
{
	size_t count = static_cast<size_t> (kGrowFactors*capacity());
	pointer p = static_cast<pointer>(common::alloc(sizeof(value_type)*count));
	assert(p != NULL);
	memcpy(p, data_, sizeof(value_type)*size_);
	delete []data_;
	data_ = p;
}
template < class T >
void Vector<T>::push_back(const reference  value)
{
	if (capacity_ >size_)
	{
		data_[size_++] = value;
	}
	else
	{
		remalloc();
		data_[size_++] = value;
	}
}
template < class T >
void Vector<T>::erase(size_t index, int count = 0)//在index位置后删除count个元素
{
	assert(index + count < size_);
	memmove(index + data_, index + data_ + count,sizeof(size_- index -count));
	size_ -= count;
}
template < class T >
void Vector<T>::insert(size_t index, value_type data, size_t count)
{
	assert(index >= 0 && index <= size_);
	size_ += count;
	size_t i = 0;
	if (size_+count<capacity_)
		memmove(data_ + count + index, data_ + index, sizeof(size_ - index));
	else
	{
		remalloc();
		memmove(data_ + count + index, data_ + index, sizeof(size_ - index));
	}
	while (count--)
	{
		*(data_ + index + i) = data;
		i++;
	}
	
}
template < class T >
void Vector<T>::sort()
{
	int i = 0, j = 0;
	int m = 0;
	T temp;
	for (i; i < size_; i++)
	{
		j = i + 1;
		m = i;
		for (j; j < size_; j++)
		{
			if (data_[j] < data_[m])
				m = j;
		}
		if (m != i)
		{
			temp = data_[i];
			data_[i] = data_[m];
			data_[m] = temp;
		}
	}
}
}//namespace ynstl
#endif // !_YN_VECTOR_H_