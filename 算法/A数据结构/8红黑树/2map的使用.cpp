// map / multimap
// 双关键字，里面存的是一个 pair<key, value>, (k-v) 模型不仅有一个关键字，还有一个与关键字绑定的值，比较方式是按照 key 的值来比较
// 可以理解为，红黑树里面一个一个的节点都是一个结构体，里面有两个元素分别是 key 和 value 。插入，删除和查找的过程中，比较的是 key 的值

// 比如，我们可以在 map 中
// 存 <int, int>, 来统计数字出现的个数
// 存 <string, int>, 来统计字符串出现的个数
// 存 <string, string>, 可以表示一个字符串变成另一个字符串
// 存 <int, vector<int>>, 来表示一个树后面跟了若干个数......, 用来存树

// size : 返回红黑树的大小
// empty : 返回红黑树是否为空
// O(1)

// begin / end
// 迭代器，可以使用范围 for 遍历整个红黑树
// 遍历是按照中序遍历的顺序，因此是一个有序的序列

// insert : 向红黑树中插入一个元素，这里需要插入一个 pair, 可以用 {} 的形式。比如：mp.insert({1,2})
// erase : 删除一个元素
// O(log N)

// operator[] : 重载 [], 使 map 可以像数组一样使用

// find : 查找一个元素，返回的是迭代器
// count ：查询元素出现的次数，一般用来判断当前元素是否在红黑树中
// O(log N)

// lower_bound : 大于等于 x 的最小元素，返回的是迭代器
// upper_bound : 大于 x 的最小元素，返回的是迭代器
// O(log N)

#include <iostream>
#include <map>
#include <string>

using namespace std;

void print(map<string, int>& mp)
{
	for (auto p : mp)
	{
		cout << p.first << " " << p.second << endl;
	}
}

int main()
{
	map<string, int> mp;

	mp.insert({ "张三", 18 });
	mp.insert({ "李四", 20 });
	mp.insert({ "王五", 22 });

	print(mp);

	// operator[] 可以让 map 像数组一样使用
	cout << mp["张三"] << endl;

	// 注意事项：operator[] 有可能会向 map 中插入本不想插入的元素
	// [] 里面的内容如果不存在 map 中，会先插入，然后再拿值
	// 插入的时候：第一个关键字就是 [] 里面的内容，第二个关键字就是一个默认值
	// 使用前可以先判断
	if (mp.count("赵六") && mp["赵六"] == 4) cout << "yes" << endl;
	else cout << "no" << endl;

	mp.erase("张三");
	print(mp);

	return 0;
}