#include <iostream>
using namespace std;
#include <stdlib.h>
#include "linkStack.h"
int main()
{

	stack<int> test;
	test.push_Stack(1);
	test.push_Stack(2);
	test.push_Stack(3);
	test.push_Stack(4);

	cout << "The top is :" << test.get_Top() << endl;
	while (test.empty_Stack()!=1)
	{
		cout << "The stack element : " << test.pop_Stack() << endl;
	}

	system("pause");
	return 0;
}