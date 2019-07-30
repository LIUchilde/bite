#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//友元函数
//#include"test.h"
//void Box::setwidth(double wid) {
//	width = wid;
//}
//void printwidth(Box box) {
//	cout << box.width << endl;
//}
//int main() {
//	Box box;
//	box.setwidth(1.0);
//	printwidth(box);
//	system("pause");
//	return 0;
//}
//#include"test.h"
//Date::Date(int year, int month, int day)
//	:_year(year)
//	, _month(month)
//	, _day(day)
//{}
//ostream& operator<<(ostream& _cout, const Date& d) {
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, const Date& d) {
//	_cin >> d._year >> d._month >> d._day;
//	return _cin;
//}
//int main() {
//	Date d(1990, 1, 1);
//	cin >> d;
//	cout << d << endl;
//	system("pause");
//	return 0;
//}

//友元类
//#include"test.h"
//void Box::setwidth(double wid) {
//	width = wid;
//}
//void Bigbox::print(double width, Box& box) {
//	box.setwidth(width);
//	cout << box.width << endl;
//}
//void printwidth(Box box) {
//	cout << box.width << endl;
//}
//int main() {
//	Box box;
//	Bigbox big;
//	box.setwidth(2.0);
//	printwidth(box);
//	big.print(3.0,box);
//	system("pause");
//	return 0;
//}

//#include"test.h"
//Time::Time(int hour, int minute, int second)
//	:_hour(hour)
//	, _minute(minute)
//	, _second(second)
//{}
//Date::Date(int year, int month, int day)
//	: _year(year)
//	, _month(month)
//	, _day(day)
//{}
//void Date::print(Time& t) {
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main() {
//	Time t(15, 11, 30);
//	Date d(2019, 7, 30);
//	d.print(t);
//	system("pause");
//	return 0;
//}

//内部类
//#include"test.h"
//void A::B::print (const A&a) {
//	cout << k << endl;
//		cout <<a.h<< endl;
//}
//int main() {
//	A a;
//	A::B b;
//	b.print(a);
//	system("pause");
//	return 0;
//}

//日期类
#include"test.h"
//重载输出运算符
ostream& operator<<(ostream& _cout, const Date& d) {
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
//构造函数
Date::Date(int year, int month, int day)
	:_year(year)
	,_month(month)
	,_day(day)
{
	//输入日期的合法性判断
	if (!(year > 0) && (month > 0 && month < 13) && (day > 0 && day <= GetMonthdays(_month))) {
		_year = 1990;
		_month = 1;
		_day = 1;
	}
}
//拷贝构造函数
Date::Date(const Date& d)
	:_year(d._year)
	,_month(d._month)
	,_day(d._day)
{}
//判断是否闰年
bool Date::Isleapyear() {
	if (((_year % 4 == 0) && (_year % 100 != 0)) || _year % 400 == 0) {
		return true;
	}
	return false;
}
//获取每月天数
int Date::GetMonthDays(int month) {
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (Isleapyear() && 2 == month)
	{
		days[month] += 1;
	}
	return days[month];
}
//赋值运算符重载
Date& Date::operator=(const Date& d) {
	if (this != &d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
//一个日期加上一个天数
Date Date::operator+(int day) {
	if (day < 0) {//天数若为负数变为减
		return *(this-(0 - day));
	}
	Date temp(*this);
	temp._day += day;
	int daysInMonth = temp.GetMonthDays(temp._month);
	if (temp._day > daysInMonth) {
		temp._day -= daysInMonth;
		temp._month += 1;
		if (temp._month > 12) {
			temp._year += 1;
			temp._month = 1;
		}
	}
	return temp;
}
//一个日期减上一个天数
Date Date::operator-(int day) {
	if (day < 0) {
		return (*this + (0 - day));//天数若为负数变为加
	}
	Date temp(*this);
	temp._day -= day;
	while (temp._day < 0) {
		temp._month--;
		if (temp._month < 0) {
			temp._year -= 1;
			temp._month = 12;
		}
		temp._day += temp.GetMonthDays(temp._month);
	}
	return temp;
}
//两个日期相隔的天数
int Date::operator-(const Date& d) {
	Date maxdate(*this);
	Date mindate(d);
	if (maxdate<mindate) {
		maxdate = mindate;
		mindate = *this;
	}
	int count = 0;
	while (maxdate > mindate) {
		mindate = mindate + 1;
		++count;
	}
	return count;
}
//前置++
Date Date::operator++() {
	*this = *this + 1;
	return *this;
}
//后置++
Date Date ::operator++(int) {
	Date temp(*this);
	*this = *this + 1;
	return temp;
}
//前置--
Date Date::operator--() {
	*this = *this - 1;
	return *this;
}
//后置--
Date Date::operator--(int) {
	Date temp(*this);
	*this = *this - 1;
	return temp;
}
//判断两日期相等
bool Date::operator==(Date& d) {
	if ((_year == d._year) && (_month == d._month) && (_day == d._day)) {
		return true;
	}
	return false;
}
//判断两日期不相等
bool Date::operator!=(Date& d) {
	return!(*this == d);
}
//判断大小
bool Date::operator>(Date& d) {
	if ((_year > d._year) || ((_year == d._year) && (_month > d._month)) || ((_year == d._year) && (_month > d._month) && (_day > d._day))) {
		return true;
	}
	return false;
}
//判断大小
bool Date::operator<(Date& d) {
	return !(*this > d || *this == d);
}
int main() {
	Date d(2019, 7, 30);
	cout << ++d << endl;
	cout << --d << endl;
	cout << d++ << endl;
	cout << d-- << endl;
}









