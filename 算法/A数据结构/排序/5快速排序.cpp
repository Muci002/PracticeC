// 核心算法原理可以分为两步：
// 1. 从待排序区间中选择一个基准元素，
// 按照基准元素的大小将区间分成左右两部分；
// 2. 然后递归处理左区间和右区间，直到区间长度为1。

// 朴素快排的缺陷：
// 1. 基准元素选择不当，递归层数会增加，时间复杂度变高；
// 2. 当有大量重复元素时，递归层数也会增加。

// 先解决第一个问题：基准元素选择不当，递归层数会增加，时间复杂度变高。
// 解决方案：在待排序区间中，随机选择一个基准元素。
// 利用C++提供的随机函数，在一个区间内随机选择一个元素作为基准。
// 随机函数：
// - srand(time(0))：种下一个随机数种子；
// - rand()：获得一个随机数；
// - rand() % (right - left + 1) + left：在[left, right]区间内，随机选择一个数。 


// 解决第二个问题：当有大量重复元素时，递归层数也会增加。
// 回忆一下之前在顺序表做过的一道题：
//《颜色分类》。这道题的核心就是数组分成三块：
// 左边全是0；中间全是1；右边全是2。
// 如果在此基础上稍作修改，变成：
// 左边全部小于基准元素；中间全部等于基准元素；右边全部大于基准元素。
// 那么，接下来仅需递归处理左右区间，中间区间就可以无需考虑。


#include <iostream>
#include <utility>
#include <ctime>
using namespace std;
const int N = 5e6 + 10;
int n, a[N];

// 优化一：随机选择基准元素
int get_random(int left, int right)
{
	return a[rand() % (right - left + 1) + left];
}

void quick_sort(int left, int right)
{
	if (left >= right) return;

	// 1.选择一个基准元素
	int p = get_random(left, right);

	//数组分三块 — 荷兰国旗问题
	int cur1 = left - 1,cur2 = right + 1;
	int i = left;
	while(i < cur2)
	{
		if (a[i] < p) swap(a[++cur1], a[i++]);
		else if (a[i] == p) i++;
		else swap(a[--cur2], a[i]);
	}
	// [left, cur1] [cur1 + 1, cur2 - 1] [cur2, right] 
	quick_sort(left, cur1);
	quick_sort(cur2, right);
}

int main()
{
	srand(time(0));

	cin >> n;
	for (int i = 1; i <= n;i++) cin >> a[i];

	quick_sort(1, n);

	for (int i = 1; i <= n;i++) cout << a[i] << " ";

	return 0;
}