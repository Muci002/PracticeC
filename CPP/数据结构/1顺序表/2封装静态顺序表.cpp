#include <iostream>

using namespace std;

const int N = 50;

//使用类或者结构体封装一个静态顺序表
class SqList
{
	int a[N];
	int n;
public:
	//构造函数
	SqList()
	{
		n = 0;
	}

	//打印顺序表
	void print()
	{
		for (int i = 1; i <= n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}

	//尾插  时复 O(1)
	void push_back(int x)
	{
		a[++n] = x;
	}

};

int main()
{

	class SqList s1, s2;
	for (int i = 1; i <= 5; i++)
	{
		s1.push_back(i);
	}
	s1.print();
	return 0;
}