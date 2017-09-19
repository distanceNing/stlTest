#include <iostream>
using namespace std;
#include <stdlib.h>
#include "templete_Stack.h"
int main()
{
	Stack<int> a;
	cout << a.is_Full() << endl;
	a.push_Stack(2);
	cout << a.is_Full() << endl;
	cout << a.pop_Stack() << endl;

	system("pause");
	return 0;
}