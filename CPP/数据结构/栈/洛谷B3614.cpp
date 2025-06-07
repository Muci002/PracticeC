#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long LL;
const int N = 1e6 + 10;
LL stk[N];
int id;

void push(int x)
{
	stk[++id] = x;
}

void pop()
{
	id--;
}

LL query()
{
	return stk[id];
}

LL size()
{
	return id;
}

int main()
{
	int T = 0, n = 0;
	LL x = 0;
	string s;
	cin >> T;
	while (T--)
	{
		id = 0;
		cin >> n;
		while (n--)
		{
			cin >> s;
			if (s == "push")
			{
				cin >> x;
				push(x);
			}
			else if (s == "pop")
			{
				if (size())
				{
					pop();
				}
				else cout << "Empty" << endl;
			}
			else if (s == "query")
			{
				if (size())
				{
					cout << query() << endl;
				}
				else cout << "Anguei!" << endl;
			}
			else cout << size() << endl;
		}
	}
	return 0;
}