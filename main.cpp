#include <iostream>
#include <vector>
using namespace std;
#include "yn_alloc.h"

class MyClass{
	int x_;
	int y_;
public:
	MyClass(int x=2,int y=2):x_(x),y_(y){}
	void printMsg()
	{
		std::cout<<x_<<" "<<y_<<std::endl;
	}
};


int main()
{
	int ia[5] = { 0,1,2,3,4 };
	unsigned int i;
	vector<int, ynstl::simple_alloc<int> > i_vec(ia, ia + 5);
	vector<MyClass, ynstl::simple_alloc<MyClass> > vec(5);
	for (int i = 0; i < i_vec.size(); i++)
	{
		vec[i].printMsg();
	}
	cout << endl;
	getchar();
	return 0;
}
