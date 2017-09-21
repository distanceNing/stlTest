#include <iostream>
using namespace std;
#include "list.h"
#include <stdlib.h>
int main()
{
	
	linkList<int> s2;
	for(int i=0;i<5;i++)
		s2.push_back(i);
	linkList<int>::iterator ite = s2.begin();
	
	cout << *ite << endl;
	++ite;
	cout << *ite << endl;
	s2.ChangeReverse();
	s2.PrintLinkList();
	
	return 0;
}