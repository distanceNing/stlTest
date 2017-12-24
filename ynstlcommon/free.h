#ifndef _YN_STL_FREE_H_
#define _YN_STL_FREE_H_
#include <cstdlib>
namespace ynstl {

namespace common {

inline void free(void* p)
{
	::free(p);
}

}//namespace common

}//namespace ynstl




#endif // !_YN_STL_FREE_H_
