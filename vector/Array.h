template < class T >
class Carray
{
public:
	Carray();
	~Carray(){ delete[]ar_Data; }
	int Get_CarraySize()
	{ 
		return ar_Size;
	}
	T const Get_Carray(int nIndex)   //只读对象专用Const、&
	{
		return ar_Data[nIndex];
	}
	T operator [](int nIndex)
	{
		return ar_Data[nIndex];
	}
	void RemoveAll()
	{
		ar_Size = 0;
	}
	void Add_Carray(T data);
	void Delete_Carray(int nIndex, int count = 1);
	void Inster_Carray(int nIndex, T data, int count = 1);
	void Remalloc(int count);
	void Sort_Carray();
private:
	T *ar_Data;
	int ar_Size; //shiji changdu
	int ar_Count;//youxiao chnagdu 
};
template < class T >
Carray<T>::Carray()
{
	int i = 0;
	ar_Size = 0;
	ar_Count = 4;
	ar_Data = new T[ar_Count];	
}
template < class T >
void Carray<T>::Remalloc(int count)
{
	T *p = new T[ar_Count +count];
	memcpy(p, ar_Data, sizeof(T)*ar_Size);
	delete[]ar_Data;
	ar_Data = p;
}
template < class T >
void Carray<T>::Add_Carray(T data)
{
	if (ar_Count >ar_Size)
	{
		ar_Data[ar_Size++] = data;
	}
	else
	{
		Remalloc(1);
		ar_Data[ar_Size++] = data;
	}
		
	
}
template < class T >
void Carray<T>::Delete_Carray(int nIndex, int count = 0)//在nIndex位置后删除count个元素
{
	
		if ( nIndex >= ar_Size)
		{
			cout << "超出数组范围" << endl;
			return;
		}
		if (nIndex < 0)//若输入的位置为负数，则把位置置于0
		{
			nIndex = 0;
		}
		if (ar_Size - nIndex < count)//若删除的元素个数大于nIndex后的元素个数，这时删除nIndex后的所有元素
		{
			count = ar_Size - nIndex;
		}
		memmove(nIndex + ar_Data, nIndex + ar_Data + count,sizeof(ar_Size-nIndex-count));
		ar_Size -= count;
	
}
template < class T >
void Carray<T>::Inster_Carray(int nIndex, T data, int count )
{
	int i = 0;
	ar_Size += count;
	if (nIndex < 0 || count <= 0)
	{
		cout << "插入的位置、数目错误" << endl;
		return;
	}
	if (ar_Size+count<ar_Count)
		memmove(ar_Data + count + nIndex, ar_Data + nIndex, sizeof(ar_Size - nIndex));
	else
	{
		Remalloc(ar_Size + count - ar_Count);
		memmove(ar_Data + count + nIndex, ar_Data + nIndex, sizeof(ar_Size - nIndex));
	}
	while (count--)
	{
		*(ar_Data + nIndex + i) = data;
		i++;
	}
	
}
template < class T >
void Carray<T>::Sort_Carray()
{
	int i = 0, j = 0;
	int m = 0;
	T temp;
	for (i; i < ar_Size; i++)
	{
		j = i + 1;
		m = i;
		for (j; j < ar_Size; j++)
		{
			if (ar_Data[j] < ar_Data[m])
				m = j;
		}
		if (m != i)
		{
			temp = ar_Data[i];
			ar_Data[i] = ar_Data[m];
			ar_Data[m] = temp;
		}
	}
}