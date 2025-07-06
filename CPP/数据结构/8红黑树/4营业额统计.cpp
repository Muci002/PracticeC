//P2234 [HNOI2002] 营业额统计
#include <iostream>
#include <set>
#include <cmath>
using namespace std;
const int INF = 1e7+10;
int main()
{
	set<int> mp;
	int n = 0, ret = 0;
	cin >> n;
	cin >> ret;
	mp.insert(ret);
	
	// 添加左右护法
	mp.insert(-INF);
	mp.insert(INF);
	
	for(int i = 1; i < n; i++)
	{
		int x = 0; cin >> x;
		
		auto it = mp.lower_bound(x);
		auto tmp = it;
		tmp--;
		
		if(*it == x) continue;
		
		ret += min(abs(*it - x), abs(*tmp - x));
		mp.insert(x);
	 } 
	
	cout << ret;
	
	return 0;
}