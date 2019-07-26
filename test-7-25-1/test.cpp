#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class A {
//public:
//	void fun1(){}
//private:
//	int _a;
//};
//class B {
//public:
//	void fun2(){}
//};
//class C {
//};
//int main() {
//	A a;
//	B b;
//	C c;
//	cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c) << endl;
//	system("pause");
//	return 0;
//}
//#include"test.h"
//void Date::getDate(int year, int month, int day) {
//	_year = year;
//	_month = month;
//	_day = day;
//}
//void Date::Display() {
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main() {
//	Date d1,d2;
//	d1.getDate(1990, 1, 1);
//	d2.getDate(2000, 1, 1);
//	d1.Display();
//	d2.Display();
//	system("pause");
//	return 0;
//}
//#include"test.h"
//void Date::getDate( int year, int month, int day) {
//	this->_year = year;
//	this->_month = month;
//	this->_day = day;
//}
//void Date::Display() {
//	cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//}
//int main() {
//	Date d1, d2;
//	d1.getDate(1992, 1, 1);
//	d2.getDate(1992, 2, 2);
//	d1.Display();
//	d2.Display();
//	system("pause");
//	return 0;
//}
//class A {
//public:
//	void print() {
//		cout << _a << endl;
//	}
//	void show() {
//		cout << "show()" << endl;
//	}
//private:
//	int _a;
//};
//int main() {
//	A* p = NULL;
//	p->print();
//	p->show();
//	system("pause");
//	return 0;
//}
//#include"test.h"
//Date::Date() {
//};
//Date::Date(int year, int month, int day) {
//	_year = year;
//	_month = month;
//	_day = day;
//};
//int main() {
//	Date d1;
//	Date d2(1992, 1, 1);
//	system("pause");
//	return 0;
//}
//无参的构造函数和全缺省构造函数都可以称为默认构造函数，默认构造函数只能有一个
//class Date {
//public:
//	Date(){
//		_year = 1000;
//		_month = 2;
//		_day = 2;
//	}
//	Date(int year=2000, int month=1, int day=1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestDate() {
//	Date d;
//}
class Time {
public:
	Time() {
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date {
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main() {
	Date d;
	system("pause");
	return 0;
}