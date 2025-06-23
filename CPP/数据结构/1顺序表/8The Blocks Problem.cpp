//https://www.luogu.com.cn/problem/UVA101

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> PII;
const int N = 30;
vector<int> arr[N];
int n;

//初始化
void Init()
{
	for (int i = 0; i < n; i++)
	{
		arr[i].push_back(i);
	}
}

//查询坐标
PII Find(int a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] == a)
			{
				return { i, j };
			}
		}
	}
}

//归位
void Clean(int x, int y)
{
	for (int i = y + 1; i < arr[x].size(); i++)
	{
		arr[arr[x][i]].push_back(arr[x][i]);
	}
	arr[x].resize(y + 1);
}

//移动
void Move(int x1, int y1, int x2)
{
	for (int i = y1; i < arr[x1].size(); i++)
	{
		arr[x2].push_back(arr[x1][i]);
	}
	arr[x1].resize(y1);
}

//打印
void Print()
{
	for (int i = 0; i < n; i++)
	{
		cout << i << ":";
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << " " << arr[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int a = 0, b = 0;
	string op1, op2;

	cin >> n;
	//初始化
	Init();

	while (cin >> op1 >> a >> op2 >> b)
	{
		//查询 a 和 b 的坐标
		PII pa = Find(a);
		PII pb = Find(b);
		int x1 = pa.first, y1 = pa.second;
		int x2 = pb.first, y2 = pb.second;

		//判断非法情况
		if (x1 == x2) continue;

		if (op1 == "move")
		{
			//把 a 上方归位
			Clean(x1, y1);
		}
		else if (op2 == "onto")
		{
			//把 b 上方归位
			Clean(x2, y2);
		}

		//移动 a 及 a 以上
		Move(x1, y1, x2);
	}

	//打印
	Print();

	return 0;
}