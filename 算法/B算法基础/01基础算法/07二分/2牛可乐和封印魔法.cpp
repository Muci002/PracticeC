// NC235558

// 用二分模板
#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N], n, q;

int Left(int x)
{
	int l = 1, r = n;
	while (l < r)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] >= x) r = mid;
		else l = mid + 1;
	}
	if (a[l] < x) return 0;
	return l;
}

int Right(int y)
{
	int l = 1, r = n;
	while (l < r)
	{
		int mid = l + (r - l + 1) / 2;
		if (a[mid] <= y) l = mid;
		else r = mid - 1;
	}
    if(a[l] > y) return 0;
	return l;
}

int main()
{
	cin >> n; 
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	cin >> q; 
	while (q--)
	{
		int x = 0, y = 0; cin >> x >> y;
		if (Left(x) == 0 || Right(y) == 0) cout << 0 << endl;
		else
		cout <<  Right(y) - Left(x) + 1  << endl;
	}

	return 0;
}


// ````````````````````````````````````````````````````````````````````````````
// ````````````````````````````````````````````````````````````````````````````

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> a;
	int n = 0; cin >> n;
	while (n--)
	{
		int x; cin >> x;
		a.push_back(x);
	}

	int t = 0; cin >> t;
	while (t--)
	{
		int x = 0, y = 0; cin >> x >> y;
		auto it = lower_bound(a.begin(), a.end(), x);
		auto is = upper_bound(a.begin(), a.end(), y);
		if (it == a.end() ||is == a.begin()) 
		{
			cout << 0 << endl;
			continue;
		}
		int l = it - a.begin();
		int r = is - a.begin();
		cout << r - l << endl;
	}

	return 0;
}



