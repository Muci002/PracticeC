// set 不能存相同的元素
// multiset 可以存相同的元素
// 使用方式完全一样，可以用 set 去重

// size : 返回 set 实际元素的个数
// empty : 判断 set 是否为空
// O(1)

// begin / end 
// 迭代器，可以使用范围 for 遍历整个红黑树
// 遍历是中序遍历的顺序，因此是一个有序的序列

// insert : 向红黑树中插入一个元素
// erase : 删除一个元素
// O(log N)

// find : 查找一个元素，返回的是迭代器
// count : 查询元素出现的次数，一般用来判断元素是否在红黑树中
// O(log N)

// lower_bound : 大于等于 x 的最小元素，返回的迭代器
// upper_bound : 大于 x 的最小元素，返回的是迭代器
// O(log N)

#include <iostream>
#include <set>

using namespace std;

int arr[] = { 90, 20, 50,30, 80, 70, 60, 10, 40 };

int main()
{
	set<int> mp;

	// 插入
	for (auto e : arr)
	{
		mp.insert(e);
	}

	for (auto e : mp)
	{
		cout << e << " ";
	}
	cout << endl;

	if (mp.count(10)) cout << "10" << endl;
	if (mp.count(50)) cout << "50" << endl;
	if (!mp.count(100)) cout << "not fond" << endl;

	/*mp.erase(10);
	mp.erase(30);
	if (mp.count(10)) cout << "10" << endl;
	else cout << "no:10" << endl;
	if (mp.count(30)) cout << "30" << endl;
	else cout << "no:30" << endl;*/
	
	auto x = mp.lower_bound(20);
	auto y = mp.upper_bound(20);
	cout << *x << " " << *y << endl;


	return 0;
}