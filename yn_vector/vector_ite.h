#ifndef _YN_STL_VECTOR_ITE_H_
#define _YN_STL_VECTOR_ITE_H_
#include <iterator>
#include "yn_vector.h"

namespace ynstl{
template <class VectorItem>
class VectorIte :public std::iterator < std::random_access_iterator_tag, VectorItem> {
public:
	VectorIte(VectorItem* ptr):ptr_(ptr){}
	
	VectorItem& operator* ()const 
	{
		return *ptr_;
	}
	
	VectorItem* operator->()const
	{
		return ptr_;
	}
	
	VectorIte& operator++()
	{
		ptr_++;
		return *this; 
	}
	
	VectorIte operator++(int)
	{
		VectorIte temp = *this;
		++*this;
		return temp;
	}
	bool operator<(const VectorIte& i)const {
		return i.ptr_ < ptr_;
	}

	bool operator==(const VectorIte& i)const {
		return i.ptr_ == ptr_;
	}
	
	bool operator!=(const VectorIte& i)const {
		return i.ptr_ != ptr_;
	}
private:
	VectorItem* ptr_;
};

	
}// namespace ynstl


#endif // !_YN_STL_VECTOR_ITE_H_