#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
public:

	Date(int year = 1900, int month = 1, int day = 1);
	void Print();

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);

		int monthDayArray[13] = { -1 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
		
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 29;
		}
		return monthDayArray[month];
	}

	bool CheckDate()
	{
		if (_month < 1 || _month > 12) return false;
		if (_day < 1 || _day > GetMonthDay(_year, _month)) return false;
		return true;
	}

	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	// d1 += 天数
	Date& operator+= (int day);
	Date operator+ (int day);

	// d1 -= 天数
	Date& operator-= (int day);
	Date operator- (int day);
	// d1 - d2
	int operator-(const Date& d);

	// ++d1 -> d1.operator++()
	Date& operator++();
	// d1++ -> d1.operator++(0)
	// 为了区分，构成重载，给后置++，强行增加了一个int形参
	// 这里不需要写形参名，因为接收值是多少不重要，也不需要用
	// 这个参数仅仅是为了跟前置++构成重载区分
	Date operator++(int);

	// 前置
	Date& operator--();
	// 后置
	Date operator--(int);

private:
	int _year;
	int _month;
	int _day;
	
};