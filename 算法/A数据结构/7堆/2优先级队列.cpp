#include <iostream>
#include <queue>

using namespace std;
	j    
struct node
{
	int a, b, c;

	// 重载 < 运算符
	// 按照 b 为基准，创建大根堆
	bool operator < (const node& x) const
	{
		return b < x.b;    // 大根小于，小根大于
	}
};

// 结构体类型
void test2()
{
	priority_queue<node> heap;

	for (int i = 1; i <= 5; i++)
	{
		heap.push({ i + 5, i + 1, i + 2 });
	}
	while (heap.size())
	{
		node t = heap.top(); heap.pop();
		cout << t.a << " " << t.b << " " << t.c << endl;
	}
}

// 内置类型
void test1()
{
	// 大根堆
	priority_queue<int> heap1; // 默认就是大根堆

	// priority_queue<数据类型，存储结构，比较方式>
	// less 小于的比较方式
	// greater 大于的比较方式
	priority_queue<int, vector<int>, less<int>> heap2; // 大根堆
	priority_queue<int, vector<int>, greater<int>> heap3; // 小根堆

	// 记忆方式
	// 大根用小于
	// 小根用大于

}


int main()
{
	int a[10] = { 1, 41, 23, 10, 11, 2, -1, 99, 14, 0 };
	priority_queue<int> q;  // 默认是一个大根堆

	for (int i = 0; i < 10; i++)
	{
		q.push(a[i]);
	}

	while (q.size())
	{
		cout << q.top() << " ";
		q.pop();
	}

	return 0;
}