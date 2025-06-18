#include <iostream>

using namespace std;

const int N = 1e6+10;
int e[N], ne[N], h, id, mp[N];

void insert(int x, int y)
{
	int p = mp[x];
	e[++id] = y;
	mp[y] = id;
	ne[id] = ne[p];
	ne[p] = id;
}

void erase(int x)
{
	int p = mp[x];
	mp[e[ne[p]]] = 0;
	ne[p] = ne[ne[p]];
}

int find(int x)
{
	if(!mp[x]) return 0;
	return e[ne[mp[x]]];
}
int main()
{
	//放入第一个元素 1
	e[++id] = 1;
	mp[1] = id;
	ne[h] = id;
	
	int n = 0, op = 0, x = 0, y = 0;
	cin >> n;
	
	while(n--)
	{
		cin >> op >> x;
		if(op == 1)
		{
			cin >> y;
			insert(x,y);
		}
		else if(op == 2)
		{
			cout << find(x) << endl;
		}
		else
		{
			erase(x);
		}
	}
	return 0;
}