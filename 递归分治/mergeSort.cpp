#include "mergeSort.h"

void merge(std::vector<int>& elements, std::vector<int>& temp,int mid, int x, int y)
{
	int j = mid+1;
	int i = x;
	while (i <= mid&&j <= y)
	{
		if (elements[i] <= elements[j])
		{
			temp.push_back(elements[i]);
			i++;
		}
		else
		{
			temp.push_back(elements[j]);
			j++;
		}
	
		
	}
	if (i <= mid)
	{
		for (; i <= mid; i++)
			temp.push_back(elements[i]);
	}

	if(j<=y)
	{
		for (; j <= y; j++)
			temp.push_back(elements[j]);
	}
}

void copy(std::vector<int>& elements, std::vector<int>& temp, int left, int right)
{
	int k = 0;
	for (int i = left; i <=right; i++)
	{
		elements[i] = temp[k++];
	}
}

void mergeSort(std::vector<int>& element, int left, int right)
{
	int mid;
	std::vector<int>temp;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSort(element, left, mid);
		mergeSort(element, mid + 1, right);
		merge(element, temp, mid,left,right);
		copy(element,temp,left,right);
	}
}
