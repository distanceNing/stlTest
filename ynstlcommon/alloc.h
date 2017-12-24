#ifndef _YN_STL_ALLOC_H_
#define _YN_STL_ALLOC_H_
#include <cstdlib>
namespace ynstl {

namespace common {
	
inline void* alloc(size_t size)
{
	return ::malloc(size);
}

}//namespace common

}//namespace ynstl




#endif // !_YN_STL_ALLOC_H_
