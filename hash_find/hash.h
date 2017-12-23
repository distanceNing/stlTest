#ifndef _HASH_H_ 
#define _HASH_H_

#include "list_practice.h"
typedef  int Index;
typedef int value;
value TheHashFunction(char key)
{
	int val;
	val = key;

	return val;
}


template <class T>
class Hash
{
public:
	Hash(int hashSize);
	~Hash();
	Index HashFun( T key);
	Node<T> *Find(T key);
	void Insert(T key);
	void InsertTheKey(int keyIndex,T *key);
	void FlagNode(T key);
private:
	int HashTableSize;
	linkList<T> *theLists;
};
template <class T>
Hash<T>::Hash(int hashSize)
{
	
	HashTableSize = hashSize;
	theLists = new linkList<T>[hashSize];
	if (theLists == NULL)
	{
		cout << "Out of space" << endl;
	}
}
template <class T>
Hash<T>::~Hash()
{
	delete []theLists;
}
template <class T>
Index Hash<T>::HashFun(T key)
{
	int val=TheHashFunction(key);
	return val%HashTableSize;
}
template <class T>
Node<T> *Hash<T>::Find(T key)
{
	int tempIndex = HashFun(key);
	linkList<T> *temp = theLists + tempIndex;
	return temp->GetListData(key);
}
template <class T>
void Hash<T>::Insert(T key)
{
	Node<T> *tempNode;
	tempNode = Find(key);
	if (tempNode == NULL)
	{
		
		int tempIndex = HashFun(key);
		linkList<T> *temp = theLists + tempIndex;
		temp->Add_list(0, 1, key);
	}
	else
	{
		cout << "此关键字已存在" << endl;
	}
}
template <class T>
void Hash<T>::InsertTheKey(int keyIndex, T *key)
{
	linkList<T> *temp = theLists+keyIndex;
	while (*key!='\0')
	{
		temp->instert_list(*key);
		key++;
	}

}
template <class T>
void Hash<T>::FlagNode(T key)
{
	linkList<T> *temp;
	for (int i = 0; i < HashTableSize; i++)
	{
		temp = theLists + i;
		temp->FlagTheNode(key);
	}
}

#endif // !_HASH_H_ 