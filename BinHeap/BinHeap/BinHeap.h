#include <vector>
template <class T>
class BinHeap
{
public:
	BinHeap();
	~BinHeap();
	int Find(T data);
	bool InsertBinHeapNode( T data);             //�������в���Ԫ��
	T DeleteBinHeapMinNode();                 //ɾ��������е���С���,������СԪ��
	void DecreaseKeyValue(int index, T value);   //valueΪ�ؼ���ֵ�ı仯��,Ϊ��ֵ
	void IncreaseKeyValue(int index, T value);   //valueΪ�ؼ���ֵ�ı仯��,Ϊ��ֵ
	bool DeleteBinHeapNodeIndex(int index);      //ɾ��index���Ľ��
	bool BuildHeap(T Elements[],int size);       //����Ϊ����ͷָ�������ĳ���
	void TravelBinHeap();
private:
	std::vector<T> binHeap;
	int BinHeapSize;
};
template <class T>
BinHeap<T>::BinHeap()
{
	BinHeapSize = 0;
	
	binHeap.push_back(static_cast<T>(0));
}
template < class T >
BinHeap<T>::~BinHeap()
{
}
template <class T>
int BinHeap<T>::Find(T data)
{
	int i = 0;
	int temp=0;
	while (i<BinHeapSize)
	{
		if (binHeap[i] == data)
		{
			temp = i;
		}
		i++;
	}
	return temp;
}

template <class T>
bool BinHeap<T>::InsertBinHeapNode( T data)
{
	if (BinHeapSize == 0)
	{
		binHeap.push_back( data);
		BinHeapSize++;
		return true;
	}
	int i = BinHeapSize+1;
	if (data<binHeap[i / 2])
	{
		while (data<binHeap[i / 2])
		{
			binHeap[i] = binHeap[i / 2];
			binHeap[i / 2] = data;
			i = i / 2;
		}
	}
	else
	{
		binHeap.push_back(data);
	}
	
	BinHeapSize++;
	return true;
}
template <class T>
T BinHeap<T>::DeleteBinHeapMinNode()
{
	if (BinHeapSize == 0)
	{
		cout << "The priotity is empty!" << endl;
		return false;
	}
	T ret = binHeap[1];
	int i, child;
	T LastElement;
	LastElement = binHeap[BinHeapSize];
	for (i = 1; i * 2 < BinHeapSize;i=child)
	{
		child = i * 2;
		if (binHeap[child] > binHeap[child + 1])
		{
			child ++;
		}
		if (LastElement > binHeap[child])
		{
			binHeap[i] = binHeap[child];
		}
		else
		{
			break;
		}
	}
	binHeap[i] = LastElement;
	binHeap[BinHeapSize] = 0;
	BinHeapSize--;
	return ret;
}
template <class T>
void BinHeap<T>::DecreaseKeyValue(int index, T value)
{
	if (value == 0)
	{
		return;
	}
	if (value < 0)
	{
		value = value*-1;
	}
	T data;
	int i = index;
	binHeap[index] -= value;
	if (binHeap[index]<binHeap[i / 2])
	{
		while (binHeap[i]<binHeap[i / 2])
		{
			data = binHeap[i];
			binHeap[i] = binHeap[i / 2];
			binHeap[i / 2] = data;
			i = i / 2;
		}
	}
	
}
template <class T>
void BinHeap<T>::IncreaseKeyValue(int index, T value)
{
	if (value == 0)
	{
		return;
	}
	if (value < 0)
	{
		value = value*-1;
	}
	T data;
	int i = index;
	binHeap[index] += value;
	while (2 * i<BinHeapSize + 1)
	{
		if (binHeap[i]>binHeap[i * 2] && binHeap[i] < binHeap[2 * i + 1])//�˽ڵ�����ӵ�ֵС�ڴ˽ڵ��ֵ������λ��
		{
			data = binHeap[i];
			binHeap[i] = binHeap[i * 2];
			binHeap[i * 2] = data;
			i = i * 2;
		}
		if (binHeap[i]<binHeap[i * 2] && binHeap[i] > binHeap[2 * i + 1])//�˽ڵ���Һ��ӵ�ֵС�ڴ˽ڵ��ֵ������λ��
		{
			data = binHeap[i];
			binHeap[i] = binHeap[i * 2 + 1];
			binHeap[i * 2 + 1] = data;
			i = i * 2 + 1;
		}
		if (binHeap[i]>binHeap[i * 2] && binHeap[i] > binHeap[2 * i + 1])//�˽ڵ�����ӵ�ֵ���Һ��ӵ�ֵ��С�ڴ˽ڵ��ֵ����˽ڵ������ӻ���λ��
		{
			data = binHeap[i];
			binHeap[i] = binHeap[i * 2];
			binHeap[i * 2] = data;
			i = i * 2;
		}
		if (binHeap[i]<=binHeap[i * 2] && binHeap[i] <= binHeap[2 * i + 1])//���˽���ֵС�����Һ���ʱ�˳�ѭ��
			break;
	}
	
}
template <class T>
bool BinHeap<T>::DeleteBinHeapNodeIndex(int index)
{
	if (index>BinHeapSize + 1)
	{
		cout << "Beyond the length" << endl;
		return false;
	}
	T MaxValue = 100;
	DecreaseKeyValue(index, MaxValue);			 //��ͨ�����ٴ˽ڵ��Valueʹ�ô˽ڵ�λ�ڸ��ڵ㣬������DeleteMin��ɾ��
	DeleteBinHeapMinNode();
	return true;
}
template<class T>
bool BinHeap<T>::BuildHeap(T Elements[], int size)
{
	int i = 0;
	while (i<size)
	{
		InsertBinHeapNode(Elements[i]);
		i++;
	}
	return true;
}
template <class T>
void BinHeap<T>::TravelBinHeap()
{
	for (int i = 1; i < BinHeapSize+1; i++)
	{	
		cout << binHeap[i] << " ";
	}
}