// 10. 离散化
// 当题目中数据的范围很大，但是数据的总量不是很大。
// 此时如果需要用数据的值来映射数组的下标时，
// 就可以用离散化的思想先预处理一下所有的数据，
// 使得每一个数据都映射成一个较小的值。
// 之后再用离散化之后的数去处理问题。
// 比如：[99, 9, 9999, 999999] 离散之后就变成 [2, 1, 3, 4]。




// 离散化模板一：排序 + 去重 + 二分
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

int n;
int a[N];

int pos;  // 标记去重之后的元素个数
int disc[N]; // 帮助离散化

// 二分查找 x 的位置
int find(int x)
{
	int l = 1, r = pos;
	while (l < r)
	{
		int mid = l + (r - l) / 2;
		if (disc[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main()
{
	cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		disc[++pos] = a[i];
	}

	// 离散化
	sort(disc + 1, disc + 1 + n);  // 排序
	pos = unique(disc + 1, disc + 1 + n) - (disc + 1);  // 去重

	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " 离散化之后：" << find(a[i]) << endl;
	}

	return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

// 离散化模板二：排序 + 哈希表去重以及记录最终位置
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int pos;  
int disc[N]; // 帮助离散化

unordered_map<int, int> id;  // <原始的值，离散之后的值>

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		disc[++pos] = a[i];
	}

	sort(disc + 1, disc + 1 + pos);

	int cnt = 0;  // 当前这个值是几号元素
	for (int i = 1; i <= pos; i++)
	{
		int x = disc[i];
		if (id.count(x)) continue;
		cnt++;
		id[x] = cnt;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " 离散化之后：" << id[a[i]] << endl;
	}

	return 0;
}