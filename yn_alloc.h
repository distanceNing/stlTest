#ifndef _YN_STL_ALLOC_H_
#define _YN_STL_ALLOC_H_
#include <new>
#include <cstdlib>
#include <cstddef>
#include <climits>
#include <iostream>

#include "yn_construct.h"

namespace ynstl
{
class alloc{
public:
	static inline void* allocate(size_t size)
	{   
		void* temp = ::malloc(size);
		if (temp == NULL)
		{
			std::cerr << "out of memory" << std::endl;
			exit(1);
		}
		return temp;
	}

	static inline void deallocate(void* buffer)
	{
		::free(buffer);
	}	
};
template<class T,class Alloc = alloc>
class simple_alloc
{
public:
	typedef T         value_type;
	typedef T*        pointer;
	typedef const T*  const_pointer;
	typedef T&        reference;
	typedef const T&  const_reference;
	typedef size_t    size_type;
	typedef ptrdiff_t difference_type;

	template<class U>
	struct rebind
	{
		typedef allocator<U> other;
	};
	
	pointer allocate(size_type n, const void* hint = 0)
	{
		return 0 == n ? 0 : static_cast<pointer>(Alloc::allocate(n * sizeof(value_type)));
	}
	
	//pointer allocate()
	//{
	//	return static_cast<pointer>(Alloc::allocate(sizeof(value_type)));
	//}
	
	void deallocate(pointer p, size_type n)
	{
		Alloc::deallocate(p);
	}

	void construct(pointer p, const T& value)
	{
		_construct(p, value);
	}

	void destroy(pointer p)
	{
		_destroy(p);
	}

	pointer address(reference x)
	{
		return static_cast<pointer>(&x);
	}

	const_pointer const_address(const_reference x)
	{
		return static_cast<const_pointer>(&x);
	}

	size_type max_size()const
	{
		return static_cast<size_type>(UINT_MAX / sizeof(T));
	}
};
	
}// namespace ynstl

#endif // !_YN_STL_ALLOC_H_

