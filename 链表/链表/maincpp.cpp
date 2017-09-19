#include <iostream>
using namespace std;
#include "list_practice.h"
#include <stdlib.h>
int main()
{
	
	linkList<int> s2;
	for(int i=0;i<5;i++)
		s2.instert_list(i);
	
	s2.ChangeReverse();
	s2.Printf_LinkList();
	system("pause");
	return 0;
}