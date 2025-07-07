//P4305 [JLOI2011] 不重复数字
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
	int T = 0; cin >> T;
	while (T--)
	{
		int n = 0; cin >> n;
		unordered_set<int> mp;
		vector<int> arr;
		while (n--)
		{
			int x; cin >> x;
			if (mp.count(x) == 0)
			{
				mp.insert(x);
				arr.push_back(x);
			}
		}
		for (auto e : arr)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	return 0;
}