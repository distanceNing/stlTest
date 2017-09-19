#include <iostream>
#include <stdlib.h>
using namespace std;
#include "hash.h"    //分离链接散列表
#include <vector>

void FindReal(char *data);
int main()

{  
	char data[] = "twoonethree";  //1238
	FindReal(data);
	system("pause");
	return 0;
}
void FindReal(char *data)
{
	linkList<char> tempList;
	char *temp = data;
	while (*temp != '\0')
	{
		tempList.instert_list(*temp);
		temp++;
	}
	vector<int> saveNum;
	temp = data;
	while (*temp!='\0')
	{
		switch (*temp)
		{
		case'z':
			{
				   saveNum.push_back(0);
				   tempList.DeleteListData('z');
				   tempList.DeleteListData('e');
				   tempList.DeleteListData('r');
				   tempList.DeleteListData('o');
				   break;
			}
	
		case 'u':
			{
				saveNum.push_back(4);
				tempList.DeleteListData('f');
				tempList.DeleteListData('u');
				tempList.DeleteListData('r');
				tempList.DeleteListData('o');
				break;
			}
		case'w':
			{
				saveNum.push_back(2);
				tempList.DeleteListData('t');
				tempList.DeleteListData('w');
				tempList.DeleteListData('o');
				break;
			}
		case 'x':
			{
				saveNum.push_back(6);
				tempList.DeleteListData('s');
				tempList.DeleteListData('i');
				tempList.DeleteListData('x');
				break;
			}
		case'g':
			{
				   saveNum.push_back(8);;
				   tempList.DeleteListData('e');
				   tempList.DeleteListData('i');
				   tempList.DeleteListData('g');
				   tempList.DeleteListData('h');
				   tempList.DeleteListData('t');
				   break;
			}
		default:
			break;
		}
		temp++;
	}
	if (tempList.Get_listSize()<1)
	{
		cout << "the real num: ";
		for (int i = 0; i < saveNum.size(); i++)
		{
			cout << saveNum[i] << " ";
		}
		return;
	}
	temp = NULL;
	temp=new char[tempList.Get_listSize()+1];
	int i=1;
	while (tempList.get_listData(i))
	{
		*(temp + i - 1) = tempList.get_listData(i)->data;
		i++;
	}
	temp[tempList.Get_listSize() + 1] = '\0';
	while (*temp!='\0')
	{
		switch (*temp)
		{
		case'r':
		{
				   saveNum.push_back(3);
				   tempList.DeleteListData('t');
				   tempList.DeleteListData('h');
				   tempList.DeleteListData('r');
				   tempList.DeleteListData('e');
				   tempList.DeleteListData('e');
				   break;
		}

		case 'o':
		{
					saveNum.push_back(1);
					tempList.DeleteListData('n');
					tempList.DeleteListData('e');;
					tempList.DeleteListData('o');
					break;
		}
		case 'f':
		{
					saveNum.push_back(5);
					tempList.DeleteListData('f');
					tempList.DeleteListData('i');;
					tempList.DeleteListData('v');
					tempList.DeleteListData('e');
					break;
		}
		case 's':
		{
					saveNum.push_back(7);
					tempList.DeleteListData('s');
					tempList.DeleteListData('e');;
					tempList.DeleteListData('v');
					tempList.DeleteListData('e');
					tempList.DeleteListData('n');
					break;
		}
		default:
			break;
		}
		temp++;
	}
	
	while (tempList.Get_listSize() >0)
	{
		saveNum.push_back(9);

		tempList.DeleteListData('n');
		tempList.DeleteListData('i');
		tempList.DeleteListData('e');
		tempList.DeleteListData('n');

	}
	cout << "the real num: ";
	for (int i = 0; i < saveNum.size(); i++)
	{
		cout << saveNum[i] << " ";
	}
	/*char key0[] = "zero";
	char key1[] = "one";
	char key2[] = "two";
	char key3[] = "three";
	char key4[] = "four";
	char key5[] = "five";
	char key6[] = "six";
	char key7[] = "seven";
	char key8[] = "eight";
	char key9[] = "nine";
	Hash<char> testHash(10);
	testHash.InsertTheKey(0, key0);
	testHash.InsertTheKey(1, key1);
	testHash.InsertTheKey(2, key2);
	testHash.InsertTheKey(3, key3);
	testHash.InsertTheKey(4, key4);
	testHash.InsertTheKey(5, key5);
	testHash.InsertTheKey(6, key6);
	testHash.InsertTheKey(7, key7);
	testHash.InsertTheKey(8, key8);
	testHash.InsertTheKey(9, key9);

	while (*data!='\0')
	{
		testHash.FlagNode(*data);
		data++;
	}
	*/
}