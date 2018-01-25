#ifndef _YN_VECTOR_H_
#define _YN_VECTOR_H_
#include <cassert>
#include <yn_alloc.h>

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
	typedef simple_alloc<value_type> Alloctor;
	Vector(size_t init_size = kInitSize, value_type init_value = value_type())
	{
		size_ = 0;
		capacity_ = init_size;
		data_ = static_cast<pointer> (alloc::allocate(capacity_ * sizeof(value_type)));
		//placement new
		for (size_t i = 0;i < init_size;++i)
		{
			 new (data_+i) value_type(init_value);
		}
	}

	~Vector(){
		size_ = 0;
		capacity_ = 0;
		alloc::deallocate(data_);
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
	void remalloc(size_t size);
	pointer data_;
	size_t size_; 
	size_t capacity_;
	
};
template <class T>
const float Vector<T>::kGrowFactors = 1.5;
template < class T >
void Vector<T>::remalloc(size_t size)
{
	size_t count= capacity();
	do
	{
		count= static_cast<size_t> (kGrowFactors*count);
	} while (count <= capacity_ + size);
	
	
	pointer p = static_cast<pointer>(alloc::allocate(sizeof(value_type)*count));
	assert(p != NULL);
	memcpy(p, data_, sizeof(value_type)*size_);
	delete []data_;
	data_ = p;
	capacity_ = count;
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
		remalloc(1);
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
	if (size_+count<capacity_)
		memmove(data_ + count + index, data_ + index, sizeof(size_ - index));
	else
	{
		remalloc(count-capacity()+size());
		memmove(data_ + count + index, data_ + index, sizeof(size_ - index));
	}
	size_ += count;
	size_t i = 0;
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