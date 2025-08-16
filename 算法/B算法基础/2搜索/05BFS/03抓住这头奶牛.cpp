// P1588

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int dist[N];
int x, y;

void bfs()
{
	queue<int> q;
	q.push(x);
	dist[x] = 0;

	while (q.size())
	{
		int t = q.front(); q.pop();
		int a = t + 1, b = t - 1, c = t * 2;

		if (a <= N && dist[a] == -1)
		{
			q.push(a);
			dist[a] = dist[t] + 1;
		}

		if (b > 0 && dist[b] == -1)
		{
			q.push(b);
			dist[b] = dist[t] + 1;
		}

		if (c <= N && dist[c] == -1)
		{
			q.push(c);
			dist[c] = dist[t] + 1;
		}
		if (a == y || b == y || c == y)
		{
			cout << dist[t] + 1 << endl;
			break;
		}
	}
}

int main()
{
	int T = 0; cin >> T;
	while (T--)
	{
		cin >> x >> y;
		memset(dist, -1, sizeof dist);
		bfs();
	}
	return 0;
}