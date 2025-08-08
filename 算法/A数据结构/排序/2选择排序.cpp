// 选择排序(Selection Sort)是一种特别直观的算法
// 算法思想：
// 每次找出未排序序列中最小的元素，然后放进有序序列的后面

// #include <iostream>
// #include <utility>
// #include <algorithm>

// using namespace std;

// const int N = 1e5 + 10;
// int n,arr[N];

// void selection_sort()
// {
// 	for (int i = 1; i <= n; i++)
// 	{
// 		int minvalue = 0x3f3f3f3f;
// 		int p = 0;
// 		for (int j = i; j <= n; j++)
// 		{
// 			if (arr[j] < minvalue)
// 			{
// 				p = j;
// 				minvalue = arr[j];
// 			}
// 		}
// 		swap(arr[i], arr[p]);
// 	}
// }

// int main()
// {
// 	cin >> n;
// 	for (int i = 1; i <= n; i++) cin >> arr[i];

// 	selection_sort();

// 	for (int i = 1; i <= n; i++) cout << arr[i] << " ";

// 	return 0;
// }




#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n,arr[N];

void selection_sort()
{
	for (int i = 1; i < n; i++)
	{
		// [i, n] 就是待排序的区间
		int pos = i;
		for (int j = i; j <= n; j++)  // 查找待排区间最小元素的下标
		{
			if (arr[j] < arr[pos])
			{
				pos = j;
			}
		}
		swap(arr[i], arr[pos]);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	selection_sort();

	for (int i = 1; i <= n; i++) cout << arr[i] << " ";

	return 0;
}