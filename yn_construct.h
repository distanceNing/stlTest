#ifndef _YN_STL_CONSTRUCT_H_
#define _YN_STL_CONSTRUCT_H_
#include <iterator>
namespace ynstl{
	
	template<class T1,class T2>
	inline void _construct(T1 *p,const T2& value)
	{
		//placement new
		new(p) T1(value);
	}
	
	template <class T>
	inline void _destroy(T* ptr)
	{
		ptr->~T();
	}
	
	/*
	template <class ForwardIterator>
	inline void _destroy(ForwardIterator first,ForwardIterator last)
	{
		_destory(first,last,std::value_type(first));
	}
	
	
	template <class ForwardIterator,class T>
	inline void _destroy(ForwardIterator first,ForwardIterator last,T*)
	{
		typedef typename _type_traits<T>::has_trivial_destructor trivial_desstructor;
		_destory_aux(first,last,trivial_desstructor());
	}
	//typedef int _true_type;
	//typedef char _false_type;
	
	template <class ForwardIterator>
	inline void _destroy_aux(ForwardIterator first,ForwardIterator last,_false_type)
	{
		for(;first != last; ++first)
			_destroy(&*first);
	}
	
	template <class ForwardIterator>
	inline void _destroy_aux(ForwardIterator first,ForwardIterator last,_true_type){}
	*/
	inline void _destroy(char* ,char*){}
	
	inline void _destroy(wchar_t*,wchar_t*){}
	
}// namespace ynstl

#endif //! _YN_STL_CONSTRUCT_H_