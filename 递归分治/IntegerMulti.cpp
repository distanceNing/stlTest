#include "IntegerMulti.h"
#include <math.h>

int IntegerMulti(int M, int N)
{
	if (M == 0 || N == 0)
		return 0;
	if (M < 10 || N <10 )
		return M*N;
	int  count, A, B, C, D, temp;
	temp = M;
	count = 0;
	while (temp!=0)
	{
		temp /= 10;
		count++;
	}
	int num = pow(10, (count / 2));
	A = M /num;
	B = M%num;
	C = N /num;
	D = N % num;
	return IntegerMulti(A, C)*num*num +(IntegerMulti(A - B, D - C) + IntegerMulti(A, C) + IntegerMulti(B, D)) *num+ IntegerMulti(B, D);
}

