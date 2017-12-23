#include "perm.h"
#include <vector>
#include <iostream>

//template<typename T>
void swap(std::vector<int>& elements, int x, int y)
{
	if(x!=y)
	{
		int temp = elements[x];
		elements[x] = elements[y];
		elements[y] = temp;
	}
	
}

//template<class T>
void perm(std::vector<int>& elements, int high, int low)
{
	if (high == low)
	{
		for (int i = 0; i <=high; i++)
			std::cout << elements[i]<<"  ";
		std::cout << std::endl;
	}
	else
	{
		for (int i = low; i <=high; i++)
		{
			swap(elements, i, low);
			perm(elements,  high, low + 1);
			swap(elements, i, low);
		}
	}
}
