//P2786
#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef long long LL;
int main()
{
	map<string, int> mp;
	int n, p; cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		string s; 
		int x;
		cin >> s >> x;
		mp[s] = x;
	}

	char ch;
	string ret;
	LL num = 0;
	while ((ch = getchar()) != EOF)
	{
		if (isalnum(ch))
		{
			ret += ch;
		}
		else
		{
			if (mp.count(ret))
			{
				num += mp[ret];
			}
			ret = "";
		}
	}

	cout << num % p;
	return 0;
}