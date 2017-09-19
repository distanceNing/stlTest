#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int main()
{

	int ia[5] = { 1,2,3,1,4 };
	std::vector<int, allocator<int>> vi{ ia,ia + 5 };

	//for (vector<int, allocator<int>>::iterator i = vi.begin();i!=vi.end();++i)
	//{
	//
	//}

	for (auto i : vi)
	{
		cout << i;
	}

	auto ite = ::find(vi.begin(), vi.end(), 1);

	cout << *ite << endl;
	cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 3)));

	return 0;
}