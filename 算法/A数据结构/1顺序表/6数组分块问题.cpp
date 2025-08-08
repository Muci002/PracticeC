//力扣283

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> a = { 0,1,0,3,12 };

int main()
{
	//数组分块问题，利用双指针
	//定义两个指针
	// cur 标记非 0 元素的最后一个位置
	// i 扫描数组
	// [0, cur] 非0; [cur + 1, i - 1] 0; [i, n - 1] 待扫描;
	// 
	//分类讨论
	// 1.遇到 0 : 直接 i++
	// 2.遇到 1 ：swap(a[cur + 1], a[i]); cur++, i++

	
	for (int i = 0, cur = -1; i < a.size(); i++)
	{
		if (a[i]) //非 0 元素
		{
			swap(a[cur + 1], a[i]);
			cur++;
		}
	}


	return 0;
}