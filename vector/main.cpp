#include <iostream>
#include <algorithm>
using namespace std;
#include "yn_vector.h"
#include <vector>

int main()
{
	ynstl::Vector<int> ar;
	ar.push_back(1);
	ar.push_back(3);
	ar.push_back(3);
	ar.push_back(6);
	ar.push_back(5);

	ar.insert(0,10);
	ar.erase(0, 2);

	for (size_t i = 0;i < ar.size();++i)
	{
		cout << ar[i] << "\n";
	}
	
	
	return 0;
}