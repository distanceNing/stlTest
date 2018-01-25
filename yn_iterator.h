#ifndef _YN_STL_ITERATOR_H_
#define _YN_STL_ITERATOR_H_
namespace ynstl{
template <class I>
struct iterator_traits{
	typedef typename I::value_type         value_type;
	typedef typename I::iterator_category  iterator_category;   
	// 表示两个迭代器之间的距离。
	typedef typename I::difference_type    difference_type;
	typedef typename I::pointer            pointer;
	typedef typename I::reference          reference;
	
	
};

template <class T>
struct iterator_traits<T*>{
	typedef T          value_type;
	typedef ptrdiff_t  difference_type;
	typedef T&         reference;
	typedef T*         pointer;
};

template <class T>
struct iterator_traits<const T*>{
	typedef T          value_type;
	typedef ptrdiff_t  difference_type;
	typedef const T&   reference;
	typedef const T*   pointer;
};

template <class I>
typename iterator_traits::value_type traits(I ite)
{
	return *ite;
}
}//namespace ynstl


#endif //! _YN_STL_ITERATOR_H_