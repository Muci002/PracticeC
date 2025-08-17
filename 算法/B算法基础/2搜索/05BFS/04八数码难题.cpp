// P1379

// 1.如何剪枝？如何标记 3*3 的矩阵？
// 把矩阵转换成字符串存储

// 2.如何统计最短路
// unordered_map<string, int> dist;

// 二维坐标 ——> 一维坐标 . n*m 矩阵
// (x, y) --> pos = xm + y

// 一维坐标 --> 二维坐标
// x = pos / m
// y = pos % m

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

string s;
unordered_map<string, int> dist;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
string st = "123804765";

void bfs()
{
	if (s == st)
	{
		cout << 0;
		return;
	}
	dist[s] = 0;
	queue<string> q;
	q.push(s);

	while (q.size())
	{
		bool flag = false;
		string tmp = q.front(); q.pop();
		int t = 0;
		for (; t < tmp.size(); t++)
		{
			if (tmp[t] == '0') break;
		}
		int i = t / 3, j = t % 3;
		for (int k = 0; k < 4; k++)
		{
			int x = i + dx[k], y = j + dy[k];
			if (x < 0 || x >= 3 || y < 0 || y >= 3) continue;
			int pos = x * 3 + y;
			string str = tmp;
			swap(str[t], str[pos]);
			if (str == st)
			{
				cout << dist[tmp] + 1; 
				flag = true;
				break;
			}
			if (dist.count(str)) continue;
			dist[str] = dist[tmp] + 1;
			q.push(str);
		}
		if (flag) break;
	}

}

int main()
{
   	cin >> s;
	
	bfs();

	return 0;
}