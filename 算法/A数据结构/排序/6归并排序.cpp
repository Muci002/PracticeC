// 归并排序(Merge Sort)是无论数据有什么特性，
// 时间复杂度就能稳定 \( N * logN \) 的排序算法。

// 归并排序用的是分治思想，不知道分治是什么也没关系，后续算法课会讲到。它的主要过程分两步：
// 1. 只要能分，就将整个区间从中间一分为二，先将左区间和右区间排序；
// 2. 然后将左右两个已经排好序的区间合并在一起。

// 其中，如何让左右两边有序，就继续交给归并排序。
// - 因此归并排序是用递归来实现的；
// - 合并两个有序区间的操作，在顺序表中讲过类似的算法题。


#include <iostream>
#include <utility>
using namespace std;

const int N = 1e5 + 10;
int n, arr[N];
int tmp[N];  // 辅助归并排序，合并两个有序数组

void merge_sort(int left, int right)
{
	if (left >= right) return;
	
	// 1.先一分为二
	int mid = (left + right) >> 1;
	// [left, mid]  [mid + 1, right]
	// 2.先让左右区间有序
	merge_sort(left, mid);
	merge_sort(mid + 1, right);

	// 合并两个有序数组
	int cur1 = left, cur2 = mid + 1, i = left;
	// [left, mid]  [mid + 1, right]
	while (cur1 <= mid && cur2 <= right)
	{
		if (arr[cur1] <= arr[cur2]) tmp[i++] = arr[cur1++];
		else tmp[i++] = arr[cur2++];
	}

	while(cur1 <= mid) tmp[i++] = arr[cur1++];
	while(cur2 <= mid) tmp[i++] = arr[cur2++];

	for (int j = left; j <= right; j++)
	{
		arr[j] = tmp[j];
	}

}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	merge_sort(1, n);

	for (int i = 1; i <= n; i++) cout << arr[i] << " ";

	return 0;
}