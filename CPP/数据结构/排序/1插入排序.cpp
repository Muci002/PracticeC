// 插入排序(Insert Sort)类似于玩扑克牌的插牌过程，
// 每次将一个待排序的元素按照关键字的大小插入到前面已经有序的序列中
// 按照这种方式将所有元素全部插入完成即可

// 算法思想：
// 把待排序元素插入到已排序的序列中



// #include <iostream>

// using namespace std;

// const int N = 1e5 + 10;
// int arr[N];

// int main()
// {
// 	int n = 0; cin >> n;

// 	for (int i = 1; i <= n; i++)
// 	{
// 		cin >> arr[i];
// 		int c = arr[i];
// 		for (int j = i - 1; j >= 0; j--)
// 		{
			
// 			if (j == 0)
// 			{
// 				arr[1] = c;
// 				break;
// 			}
			
// 			if (arr[j] > c)
// 			{
// 				arr[j + 1] = arr[j];
// 			}

// 			else
// 			{
// 				arr[j + 1] = c;
// 				break;
// 			}
// 		}
// 	}

// 	for (int i = 1; i <= n; i++)
// 	{
// 		cout << arr[i] << " ";
// 	}

// 	return 0;
// }

#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, arr[N];

void insert_sort()
{
	// 依次枚举待排序的元素
	for (int i = 2; i <= n; i++)  // 第一个数默认是有序的
	{
		int key = arr[i];

		// 前面比 key 大的统一右移
		int j = i - 1;
		while (j >= 1 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	cin >> n; 
	for (int i = 1; i <= n; i++) cin >> arr[i];

	insert_sort();

	for (int i = 1; i <= n; i++) cout << arr[i] << " ";

	return 0;
}