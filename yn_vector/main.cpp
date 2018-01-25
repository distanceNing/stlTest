
#include "yn_vector.h"
#include "../test/test_common.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
int main()
{
	ynstl::Vector<int> ar;
	ar.push_back(1);
	ar.push_back(3);
	ar.push_back(3);
	ar.push_back(6);
	ar.push_back(5);
	
	ar.insert(0,10,10);
	EXPECT_EQ_INT(15, ar.size());
	EXPECT_EQ_INT(19, ar.capacity());
	ar.erase(0, 2);
	EXPECT_EQ_INT(13, ar.size());
	for (size_t i = 0;i < ar.size();++i)
	{
		std::cout << ar[i] << "\t";
	}
	printTestResult();
	getchar();
	return 0;
}