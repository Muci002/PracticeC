//双端队列
//将队列的两端分别称为前端和后端，两端都可以进行数据入队和出队

//创建
//deque<T> q;
//T可以是任意类型的数据

//size : 返回队列里实际元素的个数
//empty ：返回队列是否为空
// O(1)

//push_front : 头插
//push_back : 尾插
// O(1)

//pop_front : 头插
//pop_back : 尾插
// O(1)

//front : 返回队头元素，不会删除
//back ：返回队尾元素，不会删除
// O(1)

//clear ：清空队列
// O(N)

#include <iostream>
#include <deque>

using namespace std;

//存一个结构体
struct node
{
	int x, y, z;
};

deque<node> q;

int main()
{

	//头插
	for (int i = 1; i <= 5; i++)
	{
		q.push_front({ i, i * 2, i * 3 });
	}

	//头删
	while (q.size())
	{
		auto t = q.front();
		cout << t.x << " " << t.y << " " << t.z << endl;
		q.pop_front();
	}

	//尾插
	for (int i = 1; i <= 5; i++)
	{
		q.push_back({ i, i * 2, i * 3 });
	}

	//尾删
	while (!q.empty())
	{
		auto t = q.back();
		cout << t.x << " " << t.y << " " << t.z << endl;
		q.pop_back();
	}

	return 0;
}