// 7.2 二分答案
// 准确来说，应该叫做「二分答案 + 判断」。
// 二分答案可以处理大部分「最大值最小」以及「最小值最大」的问题。
// 如果「解空间」在从小到大的「变化」过程中，「判断」答案的结果出现「二段性」，
// 此时我们就可以「二分」这个「解空间」，通过「判断」，找出最优解。
// 刚接触的时候，可能觉得这个「算法原理」很抽象。
// 没关系，3 道题的练习过后，你会发现这个「二分答案」的原理其实很容易理解，
// 重点是如何去「判断」答案的可行性。


// P2440

#include <iostream>
#include <cmath>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL a[N], n, k;

int calu(int x)
{
	LL ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ret += a[i] / x;
	}
	return ret;
}

int main()
{
	cin >> n >> k;
	LL maxlen = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxlen = max(maxlen, a[i]);
	}

	LL l = 0, r = maxlen;
	while (l < r)
	{
		LL mid = l + (r - l + 1) / 2;
		if (calu(mid) >= k) l = mid;
		else r = mid - 1;
	}
	
	cout << l;

	return 0;
}