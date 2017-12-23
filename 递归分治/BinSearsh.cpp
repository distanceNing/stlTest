#include "BinSearsh.h"



int BinSearsh(std::vector<int> &elements, int low, int high,int value)
{
	int mid;
	while (low<=high)
	{
		mid = (low + high) / 2;
		if (elements[mid] > value)
			high = mid - 1;
		else
		{
			if (elements[mid] < value)
				low = mid + 1;
			else
			{
				return mid;
			}
		}
	}
	return -1;
}

int recurBinSearsh(std::vector<int> &elements, int low, int high, int value)
{
	if (low > high)
		return -1;
	int mid = (low + high) / 2;

	if (elements[mid] > value)
		return recurBinSearsh(elements, low, mid - 1, value);
	else
	{
		if (elements[mid] < value)
			return recurBinSearsh(elements, mid+1,high, value);
		else
		{
			return mid;
		}
	}
}
