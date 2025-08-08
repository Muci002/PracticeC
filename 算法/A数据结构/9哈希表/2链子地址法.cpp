#include <iostream>

using namespace std;

const int N = 23;

int h[N]; // 哈希表
int e[N], ne[N], id;

// 计算下标，除留余数法
int f(int x)
{
	return (x % N + N) % N;
}

// 插入元素 - 处理哈希冲突
void insert(int x)
{
	int idx = f(x);

	// 把 x 头插到 idx 所在的链表中
	e[++id] = x;

	// 连地址法
	ne[id] = h[idx];
	h[idx] = id;
}

// 查找元素
bool find(int x)
{
	int idx = f(x);

	for (int i = h[idx]; i; i = ne[i])
	{
		if (e[i] == x) return true;
	}
	return false;
}

int main()
{

	return 0;
}