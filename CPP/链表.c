#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//创建
const int N = 1e5;
int e[N], ne[N], h, id;
int mp[N];

//头插
void push_front(int x)
{
	e[++id] = x;
	mp[x] = id;
	ne[id] = ne[h];
	ne[h] = id;
}

//在任意位置之后插入
void insert(int p, int x)
{
	e[++id] = x;
	mp[x] = id;
	ne[id] = ne[p];
	ne[p] = id;
}

//遍历链表
void print()
{
	for (int i = ne[h]; i; i = ne[i])
	{
		cout << e[i] << " ";
	}
	cout << endl;
}


int main()
{
	for (int i = 1; i <= 5; i++)
	{
		push_front(i);
	}
	print();

	insert(2, 9);
	return 0;
}