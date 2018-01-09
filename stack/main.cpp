#include "yn_stack.h"
#include "../test/test_common.h"

#include <string>

int main()
{
	ynstl::Stack<int> a;
	
	a.push(2);
	EXPECT_EQ_INT(2, a.top());
	a.push(3);
	EXPECT_EQ_INT(3, a.top());
	a.push(12);
	EXPECT_EQ_INT(12, a.top());

	a.pop();
	EXPECT_EQ_INT(3, a.top());

	a.push(13);
	EXPECT_EQ_INT(13, a.top());
	a.push(14);
	EXPECT_EQ_INT(14, a.top());

	a.pop();
	EXPECT_EQ_INT(13, a.top());
	a.pop();
	EXPECT_EQ_INT(3, a.top());
	a.pop();
	EXPECT_EQ_INT(2, a.top());
	while (!a.empty())
	{
		a.pop();
	}

	EXPECT_EQ_INT(1, a.empty());

	
	printTestResult();
	return 0;
}