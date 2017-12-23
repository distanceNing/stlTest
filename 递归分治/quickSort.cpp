#include "quickSort.h"

int Partition(std::vector<int>& elements, int left, int right)
{
	int index = rand()%(right-left)+left;
	int pivot = elements[index];
	swap(elements, index, right);

	int j = right-1;
	int i = left;
	while (true)
	{
		while (elements[i] < pivot) {
			i++;
		}
		while (j>0&&elements[j] > pivot) { 
			j--;
		}
		if (i < j)
			swap(elements, i, j);
		else
			break;
	}
	swap(elements, i, right);
	return i;
}

void quickSort(std::vector<int>& elements, int left, int right)
{
	int index;
	if (left < right)
	{
		index = Partition(elements, left, right);
		quickSort(elements, left, index-1);
		quickSort(elements, index + 1, right);
	}
}
