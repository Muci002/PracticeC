// 链式前向星的本质是用链表存储所有的孩子
// 1.创建一个足够大的数组 h ，作为所有节点的哨兵位
// 2.创建两个足够大的数组 e 和 ne，一个作为数据域，一个作为指针域
// 3.一个变量 id，标记新来节点的存储位置
// 当 x 有一个孩子 y 的的时候，就把 y 头插到 x 的链表中
// id++; e[id] = y; ne[id] = h[x]; h[x] = id;

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

//链式前向星
int h[N], e[N * 2], ne[N * 2], id;

// 把 b 头插到 a 所在的链表后面
void add(int a, int b)
{
	e[++id] = b;
	ne[id] = h[a];
	h[a] = id;
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b; cin >> a >> b;
		// a 和 b 之间有一条边
		add(a, b); add(b, a);
	}

	return 0;
}