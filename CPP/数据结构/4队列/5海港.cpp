// 洛谷P2058

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII; // 第一个int存时间，第二个int存国家
const int N = 1e5 + 10;  
int cont[N]; //记录每个国家出现的次数
int kinds; //记录有多少个国家
queue<PII> q;

int main()
{
	int T = 0; cin >> T;
	while (T--)
	{
		int t = 0, k = 0, x = 0;
		cin >> t >> k;
		while (k--)
		{
			cin >> x;
			q.push({t, x});
			cont[x]++;
			if (cont[x] == 1) kinds++;
		}
		while (q.front().first <= t - 86400)  //超出一天，出队
		{
			int p = q.front().second;
			cont[p]--;
			if (cont[p] == 0) kinds--; // 1 —— > 0 国家种类减少
			q.pop(); //出队；
		}
		cout << kinds << endl;
	}
	return 0;
}