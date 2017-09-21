#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <ctime>
#include <deque>
#include <set>
#include <unordered_map>



using namespace std;

namespace Test
{
	long getTargetLong()
	{
		long value;
		cin >> value;
		return value;
	}

	string getTargetString()
	{
		string str;
		cin >> str;
		return str;
	}
	

	void testVector(long &value)
	{
		cout << "test Vector ----" << endl;

		vector<string> test;
		char buffer[32];
		for (long i = 0;i < value;++i)
		{
			try {
				snprintf(buffer, 32, "%d", rand());
				test.push_back(string(buffer));
			}
			catch (exception &e)
			{
				cout << e.what() << endl;
				cout << "i is " << i << "!!!\n";
			}
		}
		clock_t start =clock();
		auto ite = std::find(test.begin(), test.end(), string("23456"));
		if (ite != test.end())
		{
			cout << "Found ! !" << *ite << endl;
		}
		else
		{
			cout << "Not Found ! !" << endl;
		}
		cout <<"test.data() :" <<test.data() << endl;
		cout <<"test.size() : "<<test.size() << endl;
		cout <<"test.capacity() :"<< test.capacity() << endl;
		cout << "time cost : " << clock() - start << endl;
	}

	void testDeque(long &value)
	{
		cout << "test deque ----" << endl;
		clock_t start = clock();
		deque<string> test;
		char buffer[32];
		for (long i = 0;i < value;++i)
		{
			try {
				snprintf(buffer, 32, "%d", rand());
				test.push_back(string(buffer));
			}
			catch (exception &e)
			{
				cout << e.what() << endl;
				cout << "i is " << i << "!!!\n";
			}
		}
		cout << "init time cost : " << clock() - start << endl;
		start = clock();
		auto ite = std::find(test.begin(), test.end(), string("23456"));
		if (ite != test.end())
		{
			cout << "Found ! !" << *ite << endl;
		}
		else
		{
			cout << "Not Found ! !" << endl;
		}
		cout << "test.size() : " << test.size() << endl;
		cout << "test.max_size() :" << test.max_size() << endl;
		cout << "time cost : " << clock() - start << endl;
	}

	void testSet(long &value)
	{
		cout << "test set ----" << endl;
		clock_t start = clock();
		set<string> test;
		char buffer[32];
		for (long i = 0;i < value;++i)
		{
			try {
				snprintf(buffer, 32, "%d", rand());
				test.insert(string(buffer));
			}
			catch (exception &e)
			{
				cout << e.what() << endl;
				cout << "i is " << i << "!!!\n";
			}
		}
		//²åÈëÐ§ÂÊÌ«µÍ
		cout << "init time cost : " << clock() - start << endl;
		start = clock();
		auto ite = ::find(test.begin(), test.end(), "23456");
		if (ite != test.end())
		{
			cout << "Found ! !" << *ite << endl;
		}
		else
		{
			cout << "Not Found ! !" << endl;
		}
		cout << "time cost : " << clock() - start << endl;
		start = clock();
		ite = test.find("23456");
		if (ite != test.end())
		{
			cout << "Found ! !" << *ite << endl;
		}
		else
		{
			cout << "Not Found ! !" << endl;
		}
		cout << "test.size() : " << test.size() << endl;
		cout << "test.max_size() :" << test.max_size() << endl;
		cout << "time cost : " << clock() - start << endl;
	}
}
int main()
{
	
	int ia[5] = { 1,2,3,1,4 };
	std::vector<int, allocator<int>> vi{ ia,ia + 5 };

	//for (vector<int, allocator<int>>::iterator i = vi.begin();i!=vi.end();++i)
	//{
	//
	//}

	//for (auto i : vi)
	//{
	//	cout << i;
	//}

	//auto ite = ::find(vi.begin(), vi.end(), 1);

	//cout << *ite << endl;
	//cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 3)));


	long value = Test::getTargetLong();
	Test::testVector(value);
	
	return 0;
}