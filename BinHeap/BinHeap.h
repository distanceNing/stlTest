#ifndef _BIN_HEAP_H_
#define _BIN_HEAP_H_

#include <vector>
#include <cassert>
template <class T>
class BinHeap
{
public:
	BinHeap(){}
	~BinHeap(){}

	void insert( T data){
		binHeap.push_back(data);
		adjust(binHeap.size() - 1);
	}
	void adjust(size_t index) {
		int data = binHeap[index];
		int parent = index / 2;
		while (data < binHeap[parent])
		{
			std::swap(binHeap[index], binHeap[parent]);
			index = parent;
			parent = parent / 2;
		}
	}
	bool empty()const
	{
		return binHeap.size() - 1 == 0;
	}

	// //ɾ��������е���С���,������СԪ��
	T  deleteMin() {
		assert(!binHeap.empty());
		T ret = binHeap[1];
		binHeap[1] = binHeap.back();
		binHeap.pop_back();
		int child;
		size_t size = binHeap.size();
		for (int i = 1; i * 2  < size;i = child)
		{
			child = i * 2;
			if (child + 1 < size&&binHeap[child] > binHeap[child + 1])
			{
				child++;
			}
			if (binHeap[i] > binHeap[child])
			{
				std::swap(binHeap[i], binHeap[child]);
			}
			else
			{
				break;
			}
		}
		return ret;
	}
	
	void DecreaseKeyValue(int index, T value);   //valueΪ�ؼ���ֵ�ı仯��,Ϊ��ֵ
	void IncreaseKeyValue(int index, T value);   //valueΪ�ؼ���ֵ�ı仯��,Ϊ��ֵ
	bool DeleteBinHeapNodeIndex(int index);      //ɾ��index���Ľ��
	bool BuildHeap(T Elements[],int size);       //����Ϊ����ͷָ�������ĳ���
	void TravelBinHeap();
private:
	std::vector<T> binHeap;
};

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
	while (2 * i<binHeapSize_ + 1)
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
	if (index>binHeapSize_ + 1)
	{
		cout << "Beyond the length" << endl;
		return false;
	}
	T MaxValue = 100;
	DecreaseKeyValue(index, MaxValue);			 //��ͨ�����ٴ˽ڵ��Valueʹ�ô˽ڵ�λ�ڸ��ڵ㣬������DeleteMin��ɾ��
	deleteMin();
	return true;
}
template<class T>
bool BinHeap<T>::BuildHeap(T Elements[], int size)
{
	int i = 0;
	while (i<size)
	{
		insert(Elements[i]);
		i++;
	}
	return true;
}
template <class T>
void BinHeap<T>::TravelBinHeap()
{
	for (size_t i = 1;i < binHeap.size();++i)
	{
		std::cout << binHeap[i] << "\t";
	}
}
#endif //!_BIN_HEAP_H_