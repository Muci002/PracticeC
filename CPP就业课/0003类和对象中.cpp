// 面向对象三大特性：


// 构造函数的特点
// 1.函数名与类名相同
// 2.没有返回值
// 3.对象实例化时系统会自动调用对应的构造函数
// 4.构造函数可以重载
// 5.

 
// 后定义的先析构 
// 有资源申请一定要写析构，否则会造成内存泄露



#include <iostream>

using namespace std;

class date
{
public:
	/*date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/

	void print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	bool operator==(date d2)
	{
		return _year == d2._year;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	date A;
	A.print();
	
	/*date B(2025, 7, 22);
	B.print();*/

	date B;
	A.operator==(B);
	A == B;

	return 0;
}