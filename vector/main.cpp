#include <iostream>
#include <algorithm>
using namespace std;
//#include <string>
//#include "Array.h"
//#include <stdlib.h>
bool cmp(char a, char b)
{
	
		return a>b;
}
int main()
{
	int a[5] = { 6,3,41,2,4 };
	sort(a, a + 4, cmp);

	//int i = 0;
	//char a[5] = "inpu";
	//

	//Carray<int> ar;
	//ar.Add_Carray(1);
	//ar.Add_Carray(3);
	//ar.Add_Carray(3);
	//ar.Add_Carray(6);
	//ar.Add_Carray(5);

	//ar.Inster_Carray(0,10);
	//ar.Delete_Carray(0, 2);

	//while (i<ar.Get_CarraySize())
	//{
	//	cout << ar[i] << " ";
	//	i++;
	//}
	//
	
	
	return 0;
}