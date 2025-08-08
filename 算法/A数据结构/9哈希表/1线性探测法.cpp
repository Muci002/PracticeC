#include <iostream>

using namespace std;

const int N = 23, INF = 0x3f3f3f3f;

int h[N]; // 哈希表
 
// 初始化
void init()
{
	memset(h, 0x3f, sizeof h);
}

// 哈希函数 - 计算出 x 的存储位置
int f(int x)
{
	// 防止出现负数下标 — 模加模
	int id = (x % N + N) % N;

	// 处理哈希冲突
	while (h[id] != INF && h[id] != x)
	{
		id++;
		if (id == N) id = 0; // 如果走到尾部，从头开始
	}

	return id;
}

// 添加元素
void insert(int x)
{
	int idx = f(x);
	h[idx] = x;
}

// 查找元素
bool find(int x)
{
	int id = f(x);
	return h[id] == x;
}

int main()
{
	init();

	return 0;
}