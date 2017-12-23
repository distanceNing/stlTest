#include <iostream>
#include "Widget.h"
namespace std{
	template<>
	void swap<Widget>(Widget&lhs, Widget&rhs)
	{
		lhs.swap(rhs);
	}
}

int main()
{
	Widget test1(1);
	Widget test2(2);
	test1.swap(test2);
	return 0;
}