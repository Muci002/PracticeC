#include <iostream>

using namespace std;

const int N = 1e5;
int e[N], pre[N], ne[N], h, id, mp[N];

//遍历链表
void print()
{
	for (int i = ne[h]; i; i = ne[i])
	{
		cout << e[i] << " ";
	}
	cout << endl;
}

//头插
void push_front(int x)
{
	e[++id] = x;
	mp[x] = id;
	pre[id] = h;
	ne[id] = ne[h];
	pre[ne[h]] = id;
	ne[h] = id;
	
}

//按值查找
int find(int x)
{
	return mp[x];
}

//任意位置插入
void insert(int p, int x)
{
	e[++id] = x;
	mp[x] = id;
	pre[id] = p;
	ne[id] = ne[p];
	pre[ne[p]] = id;
	ne[p] = id;
}

int main()
{

	return 0;
}