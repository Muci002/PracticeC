#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
queue<PII> q;

//size()返回队列实际元素的个数 
//empty()返回队列是否为空  
//O(1)
//push()入队
//pop()出队
//O(1)
//front()返回队头元素，不会删除
//back()返回队尾元素，不会删除

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		q.push({ i, i * 10 });
	}

	while (q.size())
	{
		cout << q.front().first << " " << q.front().second << endl;
		q.pop();
	}

	return 0;
}