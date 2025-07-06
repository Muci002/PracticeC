//P5250

#include <iostream>
#include <set>
#include <cmath>
using namespace std;

set<int> mp;

int main()
{
	int m = 0;
	cin >> m;
	mp.insert(1e10+10);
	mp.insert(-1e10+10);
	for(int i = 0; i < m ; i++)
	{
		int op = 0, len = 0; 
		cin >> op >> len;
		if(op == 1)
		{
			if(mp.count(len)) cout << "Already Exist" << endl;
			else mp.insert(len);
		}
		else
		{
			if(mp.size() == 2) 
			{
				cout << "Empty" << endl; 
				continue;
			}
			auto it = mp.lower_bound(len);
			auto tmp = it;
			tmp--;
			int p = abs(*it - len) < abs(*tmp - len) ? *it : *tmp;
			if(abs(*it - len) == abs(*tmp - len)) p = *it < *tmp ? *it : *tmp;
			cout << p << endl;
			mp.erase(p);
		}
	}
	return 0;
}