#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Queue.h"
int main()
{
	Queue<int> q(5);
	int i = 0;
	q.In_Queue(1);
	q.In_Queue(2);
	q.In_Queue(3);
	q.In_Queue(4);
	q.In_Queue(5);
	q.Out_Queue();
	q.Out_Queue();
	q.In_Queue(6);
	q.In_Queue(7);
	q.In_Queue(8);
	q.VisitQueue();

	/*while (!q.IsEmpty())
	{
		cout << q.Out_Queue() << endl;
		i++;

	}*/



	system("pause");
	return 0;
}