//可变长数组 vector
//vector 的底层就是一个会自动扩容的顺序表
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 10;

struct node
{
	int a;
	string s;
};

//测试 size
void print(vector<int>& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


int main()
{
	// 1,创建 vector
	vector<int> a1;       //创建了一个名字为 a1 的空的可变长数组，里面都是 int 类型的数据
	vector<int> a2(N);    //创建了一个大小为 10 的可变长数组，里面的值默认都是 0
	vector<int> a3(N, 2); //创建了一个大小为 10 的可变长数组，里面的值默认都是 2
	vector<int> a4 = { 1, 2, 3, 4, 5 };  //初始化的创建方式

	// <> 里面可以存放任意的数据类型，这体现了模板的作用，也体现了模板的强大之处
	// 这样，vector 里面就可以存放我们见过的所有的数据类型，甚至是 STL 本身
	vector<string> a5;    //存字符串
	vector<node> a6;      //存结构体
	vector<vector<int>> a7; //创建了一个二维的可变长数组

	vector<int> a8[N];    //创建了一个大小为 N 的 vector 数组

	//size 返回元素个数 / empty 返回是否为空，bool 类型的函数，空返回true， 非空返回false
	print(a2);
	print(a3);

	//测试 empty
	if (a2.empty()) cout << "空" << endl;
	else cout << "不空" << endl;

	// begin ：返回起始位置的迭代器(左闭）
	// end ：返回终点位置的下一个位置的迭代器（右开）
	// 利用迭代器可以访问整个 vector ；存在迭代器的容器就可以使用范围 for 遍历

	// push_back ：尾部添加一个元素
	// pop_back ：尾部删除一个元素
	// O(1)

	// front ：返回首元素
	// back : 返回尾元素
	// O(1)

	// resize ：修改 vector 的大小
	// 大于原始大小，补0
	// 小于原始大小，把后面元素删掉
	// O(N)
	
	// clear ：清空 vector
	// 底层实现的时候，会遍历整个元素，一个一个删除，时间复杂度 O(N) 

	return 0;
}