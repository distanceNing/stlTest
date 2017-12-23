#ifndef _BINHEAP_
#define  _BINHEAP_
#include <vector>
#include <iostream>
template <class T>
class BinHeap
{
public:
	BinHeap();
	bool InsertNode( T data);             //�������в���Ԫ��
	T DeleteMaxNode();                 //ɾ��������е���С���,������СԪ��
	bool BuildHeap(T Elements[],int size);       //����Ϊ����ͷָ�������ĳ���
	bool IsEmpty() {
		if (BinHeapSize != 0)
			return false;
		return true;
	}
private:
	const int INF = 0x7fffffff;
	std::vector<T> binHeap;
	int BinHeapSize; //�ѵ�ʵ�ʴ�С
};
template <class T>
BinHeap<T>::BinHeap()
{
	BinHeapSize = 0;
	binHeap.push_back(static_cast<T>(INF));
}


template <class T>
bool BinHeap<T>::InsertNode( T data)
{
	if (BinHeapSize == 0)
	{
		if (binHeap.size() > 1)
			binHeap[1] = data;
		else
			binHeap.push_back(data);
		BinHeapSize++;
		return true;
	}
	int i = BinHeapSize+1;
	if(BinHeapSize<=binHeap.size())
		binHeap.push_back(data);
	
	while (data>binHeap[i / 2])
	{
		binHeap[i] = binHeap[i / 2];
		i = i / 2;
	}
	binHeap[i] = data;
	BinHeapSize++;
	return true;
}

template <class T>
T BinHeap<T>::DeleteMaxNode()
{
	if (BinHeapSize == 0)
	{
		std::cerr << "The priotity is empty!\n";
		return false;
	}
	T ret = binHeap[1];
	int  i,child;
	T LastElement;
	LastElement = binHeap[BinHeapSize];
	
	for ( i = 1; i * 2 < BinHeapSize;i=child)
	{
		child = i * 2;
		if (binHeap[child] < binHeap[child + 1])
		{
			child ++;
		}
		if (LastElement < binHeap[child])    //�����һ��Ԫ��С�ڽϴ�ĺ���ʱ���ϴ�ĺ��ӷ��õ���Ѩ
		{
			binHeap[i] = binHeap[child];
		}
		else                                 //�����һ��Ԫ�ش��ڽϴ�ĺ���ʱ��ֱ���˳�ѭ��
		{
			break;
		}
	}

	//�����һ��Ԫ�ط��õ���Ѩ
	binHeap[i] = LastElement;
	binHeap[BinHeapSize] = 0;
	BinHeapSize--;
	return ret;
}

template<class T>
bool BinHeap<T>::BuildHeap(T Elements[], int size)
{
	int i = 0;
	while (i<size)
	{
		InsertNode(Elements[i]);
		i++;
	}
	return true;
}
#endif