#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#include"test.h"
////构造函数初始化列表
//Date::Date(int year, int month, int day)
//	:_year(year)
//	,_month(month)
//	,_day(day)
//{}
////构造函数赋值
//Date::Date(int year, int month, int day) {
//	_year = year;
//	_month = month;
//	_day = day;
//}
//void Date::print() {
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main() {
//	Date d(1990, 1, 1);
//	d.print();
//	system("pause");
//	return 0;
//}

//class Date {
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	explicit Date(int year)
//		:_year(year)
//	{}
//};
//int main() {
//	Date d(1990);
//	system("pause");
//	return 0;
//}

//class Text {
//public:
//	static int count;
//};
//int Text::count = 0;
//int main() {
//	Text t1,t2;
//	t1.count = 100;
//	cout << t2.count << endl;
//	system("pause");
//	return 0;
//}

//class Text {
//public:
//	static int count;
//	int num;
//	static int fun() {
//		return num;
//	}
//};
//int Text::count = 0;
//int main() {
//	Text t;
//	t.count = 100;
//	t.fun();//发生错误，fun函数return的是非static类成员，如果return count就正确
//	system("pause");
//	return 0;
//}

//#include"test.h"
//Date::Date(int year,int month,int day)
//	:_year(year)
//	,_month(month)
//	,_day(day)
//{}
//ostream& operator<<(ostream& _cout, const Date& d) {
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, const Date& d) {
//	_cin >> d._year >> "-" >> d._month >> "-" >> d._day;
//	return _cin;
//}
//int main() {
//	Date d(1990, 1, 1);
//	cin >> d;
//	cout << d << endl;
//	system("pause");
//	return 0;
//}

//#include"test.h"
//Time::Time(int hour,int minute,int second)
//	:_hour(hour)
//	,_minute(minute)
//	,_second(second)
//{}
//Date::Date(int year,int month,int day)
//	:_year(year)
//	,_month(month)
//	,_day(day)
//{}
//void Date::setTimeofDate(int hour, int minute, int second) {
//	_t._hour = hour;
//	_t._minute = minute;
//	_t._second = second;
//}
//int main() {
//	Time t(16,16,16);
//	Date d(1990, 1, 1);
//	d.setTimeofDate(16, 2, 2);
//}
//
//#include"test.h"
//void A::B::print(const A& a) {
//	cout << a.k << endl;
//	cout << h << endl;
//}
//int main() {
//	A a;
//	A::B b;
//	b.print(a);
//	system("pause");
//	return 0;
//}
