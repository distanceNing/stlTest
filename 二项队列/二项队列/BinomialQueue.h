
/*�������֧��ɾ����С��㡢�ϲ�������
  ��ÿ�β��������������ʱ�䶼ΪO��logN�� ���������ƽ������Ϊ����ʱ��
*/
typedef int Elementtype;
typedef  struct BinTree *BinTrees;
#define maxTrees 4
struct BinTree
{
	Elementtype Element;
	BinTree *FirstChild;
	BinTree *RightBrother;
};
BinTree * MergetheSameQueue(BinTree *T1,BinTree *T2) //�ϲ�������ͬ�߶ȵĶ����� 
{
	if (T1->Element > T2->Element)
		return MergetheSameQueue(T2, T1);
	T2->RightBrother = T1->FirstChild;
	T1->FirstChild = T2;
	return T1;
}
class BinomaialQueue   //�������
{
public:
	BinomaialQueue();
	bool InsertQueue(Elementtype data);
	BinomaialQueue friend  MergeQueue(BinomaialQueue tempQueue1, BinomaialQueue tempQueue2);//�ϲ������������
	Elementtype DeleteMin();                                       /*��Ϊ�����LogN�ö������������СԪ��ʱ��ҲΪO��logN�����ҵ���СԪ�Ķ����� ������tempTree��ʱ��ΪO(minTree) �ٺϲ����ö���������ʱ��ΪO��logN��*/
	BinomaialQueue operator=(const BinomaialQueue &temp);//����=������ʵ�ֶ���丳ֵ

	BinTrees BinQueue[maxTrees];
	int Capacity;   //������е�ʵ����Ч����
	int CurrentSize;//��ͨ����  Ϊ������еĵĽ�����
	int ArraySize;
};

BinomaialQueue::BinomaialQueue()
{
	int count = 0;
	int a = 0;
	for (count; count < maxTrees; count++)
	a += pow(2, count);
	ArraySize = count;
	Capacity =a;
	CurrentSize = 0;
	for (int i = 0; i < ArraySize; i++)
	{
		BinQueue[i] = NULL;
	}
}
bool BinomaialQueue::InsertQueue(Elementtype data)
{
	if (CurrentSize >= Capacity)
	{
		cout << "out of space" << endl;
		return false;
	}
	BinTree *T,*Carry,*temp=new BinTree;
	temp->FirstChild = NULL;
	temp->RightBrother = NULL;
	CurrentSize++;
	Carry = NULL;
	temp->Element = data;
	int i,flag;
	for (i = 0; i < ArraySize; i++)
	{
		T =BinQueue[i];
		flag = !!T + 2 * !!Carry + 4 * !!temp;
		switch (flag)
		{
		case 0:
			/*NO trees*/
		case 1:/*only T*/
		{
				   break;
		}
		case 2:/*Only carry*/
		{
				   BinQueue[i] = Carry;
				   Carry= NULL;
				   break;
		}
		case 3:/*T and Carry*/
		{
				   Carry = MergetheSameQueue(T,Carry);
				   BinQueue[i] = NULL;
				   break;
		}
		case 4:
		{
				  BinQueue[i] = temp;
				  temp = NULL;
				  break;
		}
		case 5:
		{
				  Carry = MergetheSameQueue(T,temp);
				  temp = NULL;
				  BinQueue[i] = NULL;
				  break;
		}
		default:
			break;
		}
	}
	
	return true;
}
BinomaialQueue MergeQueue(BinomaialQueue tempQueue1, BinomaialQueue tempQueue2)
{
	BinTree *T1, *T2, *T3, *Carry = NULL;
	int i,flag;
	int size = tempQueue1.CurrentSize + tempQueue2.CurrentSize;
	if (size > tempQueue1.Capacity)
	{
		cout << "out of sapce" << endl;
	}
	for (i = 0; i < tempQueue1.ArraySize; i++)
	{
		T1 = tempQueue1.BinQueue [i];
		T2 = tempQueue2.BinQueue [i];
		flag = !!T1 + 2 * !!T2 + 4 * !!Carry;
		switch (flag)
		{
		case 0:
			/*NO trees*/
		case 1:/*Only tempQueue1*/
		{
				   break;
		}
		case 2:/*Only tempQueue2*/
		{
				   tempQueue1.BinQueue[i] = T2;
				   tempQueue2.BinQueue[i] = NULL;
				   break;
		}
		case 4:/*Only Carry*/
		{
				   tempQueue1.BinQueue[i] = Carry;
				   Carry = NULL;
				   break;
		}
		case 3:/*tempQueue1 and tempQueue2*/
		{
				   Carry = MergetheSameQueue(T1, T2);
				   tempQueue1.BinQueue[i] = tempQueue2.BinQueue[i] = NULL;
				   break;
		}
		case 5:/*tempQueue1  and carry*/
		{
				   Carry = MergetheSameQueue(T2, Carry);
				   tempQueue1.BinQueue[i] = NULL;
				   break;
		}
		case 6:/*tempqueue2 and carry*/
		{
				   Carry = MergetheSameQueue(T2, Carry);
				   tempQueue2.BinQueue[i] = NULL;
				   break;

		}
		case 7:/*all three*/
		{
				   tempQueue1.BinQueue[i] = Carry;
				   Carry = MergetheSameQueue(T1, T2);
				   tempQueue2.BinQueue[i] = NULL;
				   break;
		}
		default:
			break;
		}
	}
	return tempQueue1;
}
Elementtype BinomaialQueue::DeleteMin()
{
	int minItem = BinQueue[0]->Element;
	int minTree=0;
	for (int i = 1; i < ArraySize; i++)//������СԪ
	{
		if (BinQueue[i] != NULL&&BinQueue[i]->Element < BinQueue[minTree]->Element)
		{
			minItem = BinQueue[i]->Element;
			minTree = i;
		}
		
	}
	
	BinomaialQueue tempTree;
	tempTree.CurrentSize = (1 << minTree) - 1;
	BinTree *T = BinQueue[minTree]->FirstChild;
	for (int i = minTree - 1;i>=0; i--)
	{
		tempTree.BinQueue[i] = T;
		T = T->RightBrother;
		tempTree.BinQueue[i]->RightBrother = NULL;
	}
	BinQueue[minTree] = NULL;
	CurrentSize = CurrentSize - tempTree.CurrentSize + 1;
	*this=MergeQueue(*this, tempTree);
	return minItem;
}
BinomaialQueue BinomaialQueue::operator = (const BinomaialQueue &temp)
{
	ArraySize = temp.ArraySize;
	CurrentSize = temp.CurrentSize;
	Capacity = temp.Capacity;
	for (int i = 0; i < ArraySize; i++)
	{
		BinQueue[i] = temp.BinQueue[i];
	}
	return *this;
}
