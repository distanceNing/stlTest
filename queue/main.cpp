#include <iostream>
using namespace std;
#include <stdlib.h>
#include "yn_queue.h"
int main()
{
	ynstl::Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	q.pop();
	q.push(6);
	q.push(7);
	q.push(8);
	while (!q.empty()){
		cout << q.front() << endl;
		q.pop();
	}
	system("pause");
	return 0;
}