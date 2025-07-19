#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
// Input Output Stream 的缩写，
// 是标准的输入、输出流库，定义了标准的输入、输出对象




// 解决名字冲突
// 使用 namespace 关键字定义名字空间，后面跟名字空的名字
// {}中为命名空间的成员
// namespace 只能定义在全局，可以嵌套定义
// C++ 标准库都放在一个叫 std(standard) 的命名空间中

using std::endl;  // 将某个成员展开
using namespace std;  // 展开命名空间中全部成员

namespace tyx
{
	int a = 10;
}

// 却省参数
void Func(int a = 0)
{
	cout << a << endl;
}

// 半缺省
// 不能间隔，只能从右往左连续缺省
// 传参时只能从左往右传，不能跳跃传
void Func2(int a, int b = 10, int c = 20)
{

}


int main()
{
	std::cout << "hehe" << endl;
	int a = 1;
	std::cout << tyx::a << endl;  // 指定命名空间访问

	Func();    // 没有传参时，使用参数的默认值
	Func(10);  // 传参时，使用指定的实参

	return 0;
}




// 引用不是新定义一个变量，而是给已经存在的变量取了一个别名，
// 编译器不会为引用变量开辟内存空间
// 它和它引用的变量共用同一块内存空间

// 引用的特性
// 引用在定义时必须初始化
// 一个变量可以有多个引用
// 引用一旦引用一个实体，再不能引用其他实体 

// 引用一般用在函数的传参和返回值中
// 权限可以缩小，不能放大

void Swap(int& rx, int& ry)
{
	int z = rx;
	rx = ry;
	ry = z;
}

int main()
{
	int a = 0;
	// 引用：b 和 c 是 a 的别名
	int& b = a;
	int& c = a;

	// 也可以给别名 b 取别名， d 相当于 还是 a 的别名
	int& d = b;
	++d;

	// 这里取地址我们看到的是一样的
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &c << endl;

	int x = 2, y = 3;
	Swap(x, y);
	cout << x << "  " << y << endl;

	return 0;
}



// 内联函数

inline int Add(int x, int y)
{
	int ret = x + y;
	return ret;
}

//C++11 中引入 nullptr，nullptr 是一个特殊的关键字，
// nullptr 是一种特殊类型的字面量，它可以转换成任意其他类型的指针类型。
// 使用 nullptr 定义空指针可以避免类型转换的问题，
// 因为 nullptr 只能被隐式地转换为指针类型，而不能被转换为整数类型。