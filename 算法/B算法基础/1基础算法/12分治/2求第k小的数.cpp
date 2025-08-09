// P1923

// 快速选择算法 - -> 基于快排实现

#include <iostream>
#include <ctime>
#include <utility>

using namespace std;
const int N = 5e6 + 10;
int n, k;
int a[N];

// 随机选择基准
int get_random(int left, int right)
{
	return a[rand() % (right - left + 1) + left];
}

int  quick_seleck(int left, int right, int k)
{
	if (left >= right) return a[left];
	// 1.选择基准元素
	int p = get_random(left, right);
	// 2.数组分三块
	int cur1 = left - 1, cur2 = right + 1, i = left;
	while (i < cur2)
	{
		if (a[i] < p) swap(a[++cur1], a[i++]);
		else if (a[i] == p) i++;
		else swap(a[--cur2], a[i]);
	}

	// 3.选择存在结果的区间
	// [left, cur1] [cur1+1, cur2-1] [cur2, right]
	int a = cur1 - left + 1, b = cur2 - 1 - cur1, c = right - cur2 + 1;
	if (k <= a) return quick_seleck(left, cur1, k);
	else if (k <=(a + b)) return p;
	else return quick_seleck(cur2, right, k - a - b);
}

int main()
{
	srand(time(0));
	//cin >> n >> k;
	scanf("%d%d", &n, &k);
	k++;  // 使最小的元素是第 0 小，变成最小的元素是第 1 小
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	printf("%d", quick_seleck(1, n, k));
	return 0;
}


///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// nth_element 是 C++ 标准库 <algorithm> 头文件中的一个算法，
// 用于将指定范围内的元素重新排列，使得第 n 小（或大）的元素处于它在有序序列中的位置上，
// 同时保证左边的元素都小于等于它，右边的元素都大于等于它。
// 虽然它不会完全对整个范围进行排序，但能让前 n 个最小的元素位于最前面（顺序不一定是完全有序的）。
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 示例数组，包含重复元素
    vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    int k = 4;  // 求第4小的数
    // 注意这里k - 1，因为vector下标从0开始
    nth_element(arr.begin(), arr.begin() + k - 1, arr.end()); 
    // 输出第4小的数
    cout << arr[k - 1] << endl; 
    return 0;
}