// 冒泡排序(Bubble Sort)也是一种简单的排序算法。
// 它的工作原理是每次检查相邻两个元素，如果前面的元素与后面的元素满足给定的排序条件，就将相邻两个元素交换。
// 当没有相邻的元素需要交换时，排序就完成了

// 算法思想：
// 执行 n - 1 趟操作
// 每趟从前往后比较待排序区间的相邻元素，如果逆序，就交换。
// 每趟结束之后，就会有一个较大元素在最终的位置上


// #include <iostream>
// #include <utility>
// using namespace std;

// const int N = 1e5 + 10;
// int n, arr[N];

// void bubble_sort()
// {
// 	for (int i = 1; i <= n; i++)
// 	{
// 		for (int j = 2; j <= n - i + 1; j++)
// 		{
// 			if (arr[j] < arr[j - 1]) swap(arr[j], arr[j - 1]);
// 		}
// 	}
// }

// int main()
// {
// 	cin >> n;
// 	for (int i = 1; i <= n; i++) cin >> arr[i];

// 	bubble_sort();

// 	for (int i = 1; i <= n; i++) cout << arr[i] << " ";

// 	return 0;
// }




// 当某一趟冒泡操作中，没有执行元素的交换操作时，整个序列就是有序的了
// 就没有必要再执行冒泡排序算法了
#include <iostream>
#include <utility>
using namespace std;

const int N = 1e5 + 10;
int n, arr[N];

void bubble_sort()
{
	// 依次枚举待排序区间的最后一个元素
	for (int i = n; i > 1; i--)
	{
		bool flag = true;
		// [1, i] 就是待排序区间
		for (int j = 1; j < i; j++)
		{
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
			flag = false;
		}
		if (flag) return;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	bubble_sort();

	for (int i = 1; i <= n; i++) cout << arr[i] << " ";

	return 0;
}