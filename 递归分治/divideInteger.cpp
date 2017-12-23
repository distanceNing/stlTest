#include "divideInteger.h"
#include <iostream>
int divideInteger(int num, int plusNum)
{
	if(num<1||plusNum<1)
		return 0;
	if (plusNum == 1||num==1)
		return 1;
	if (plusNum > num)
		return divideInteger(num, num);
	if(plusNum==num)
		return 1+divideInteger(num, num-1);
	return divideInteger(num, plusNum - 1) + divideInteger(num - plusNum, plusNum);
}

void outputDivideInteger(int num, int plusNum, std::vector<int>&result)
{
	if (num < 1 || plusNum < 1)
		return;
	if (plusNum == 1 && num != 1)
	{
		for (; num != 1; num--)
			result.push_back(plusNum);
	}
	if (plusNum == num)
	{
		result.push_back(num);
		
		for (int i = 0; i < result.size() - 1; i++)
			std::cout << result[i] << " + ";
		std::cout << result[result.size() - 1] << std::endl;
		if (plusNum == 1)				//当最大加数为1时，当前不能继续划分下去
			while (result.size() > 0 && result[result.size() - 1] == 1)
				result.pop_back();
			else
				while ( result[result.size() - 1] <plusNum)
					result.pop_back();
		if (!result.empty())
			result.pop_back();
		return outputDivideInteger(num, num - 1, result);
	}
	if (plusNum > num)
		return outputDivideInteger(num, num,result);
	result.push_back(plusNum);
	outputDivideInteger(num-plusNum, plusNum, result);
	return outputDivideInteger(num, plusNum-1, result);
	
}