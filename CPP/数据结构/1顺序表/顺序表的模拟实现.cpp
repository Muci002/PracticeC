#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int N = 1e5 + 10; //根据实际情况定大小

//创建静态顺序表
int a[N];  //用足够大的数组来模拟顺序表
int n;     //标记顺序表里有多少个元素

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

//头插 O(n)
void push_front(int x)
{
	// 1.把[1, n]的元素统一向后移动一位
	for (int i = n; i >= 1; i--)
	{
		a[i + 1] = a[i];
	}
	// 2.把x放在表头
	a[1] = x;
	n++;  // 元素个数加一
}

//在任意位置插入 O(n)
void insert(int p, int x)
{
	for (int i = n; i >= p; i--)
	{
		a[i + 1] = a[i];
	}
	a[p] = x;
	n++;
}

//尾删 O(1)
void pop_back()
{
	n--;
}

//头删 O(n)
void pop_front()
{
	//把[2, n]区间内所有的元素，统一左移一位
	for (int i = 2; i <= n; i++)
	{
		a[i-1] = a[i];
	}
	n--;
}

//任意位置删 O(n)
void erase(int p)
{
	// 把[p+1, n]区间内的元素统一左移一位
	for (int i = p+1; i <= n; i++)
	{
		a[i-1] = a[i];
	}
	n--;
}

//按值查找 O(n)
int find(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == x) return i;
	}
	return 0;
}

//按位查找 O(1) 体现了顺序表随机存储的特性
int at(int p)
{
	return a[p];
}

//按位修改 O(1)
void change(int p, int x)
{
	a[p] = x;
}

//清空顺序表
void clear()
{
	n = 0;
}

int main()
{
	push_back(1);
	push_back(2);
	push_back(3);
	push_back(4);
	push_back(5);
	print();
	push_front(1);
	push_front(2);
	push_front(3);
	push_front(4);
	push_front(5);
	print();
	insert(2, 9);
	print();

	pop_back();
	print();
	pop_front();
	print();
	erase(3);
	print();
	return 0;
}